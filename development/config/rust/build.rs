use std::env;
use std::error::Error;
use std::fs;
use std::path::{Path, PathBuf};

fn main() -> Result<(), Box<dyn Error>> {
    let manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR")?);
    let development = manifest_dir.join("../..");

    let registry = development.join("algorithms.tsv");

    println!("cargo:rerun-if-changed={}", registry.display());

    let entries = fs::read_to_string(&registry)?;

    let mut generated = String::new();
    let mut registered = 0usize;
    let mut tested = 0usize;

    for entry in entries.lines() {
        let entry = entry.trim();

        if entry.is_empty() || entry.starts_with('#') {
            continue;
        }

        let parts: Vec<&str> = entry.split('|').collect();

        assert_eq!(parts.len(), 3, "Invalid algorithms.tsv entry: {entry}");

        let exercise_dir = development
            .join(parts[0])
            .join(parts[1])
            .join(parts[2])
            .join("rust");

        let source = exercise_dir.join("main.rs");
        let tests = exercise_dir.join("main_test.rs");

        println!("cargo:rerun-if-changed={}", source.display());
        println!("cargo:rerun-if-changed={}", tests.display());

        if !is_implemented(&source)? {
            continue;
        }

        let module_name = parts[2].replace('.', "_").replace('-', "_");

        let source_path = absolute_path(&source)?;

        generated.push_str(&format!(
            "#[allow(non_snake_case)]\n\
             pub mod {module_name} {{\n\
             include!({source_path:?});\n"
        ));

        registered += 1;

        if has_real_tests(&tests)? {
            let test_path = absolute_path(&tests)?;

            generated.push_str(&format!(
                "#[cfg(test)]\n\
                 mod tests {{\n\
                 use super::*;\n\
                 include!({test_path:?});\n\
                 }}\n"
            ));

            tested += 1;
        }

        generated.push_str("}\n\n");
    }

    let output = PathBuf::from(env::var("OUT_DIR")?).join("algorithms.rs");

    fs::write(output, generated)?;

    println!("cargo:warning=Registered {registered} Rust algorithms, {tested} test modules");

    Ok(())
}

fn is_implemented(path: &Path) -> Result<bool, Box<dyn Error>> {
    if !path.is_file() {
        return Ok(false);
    }

    let content = fs::read_to_string(path)?;
    let content = content.trim();

    Ok(!content.is_empty() && content != "// Implement the mathematical algorithm here.")
}

fn has_real_tests(path: &Path) -> Result<bool, Box<dyn Error>> {
    if !path.is_file() {
        return Ok(false);
    }

    let content = fs::read_to_string(path)?;

    Ok(!content.trim().is_empty() && !content.contains("TDD test not written yet"))
}

fn absolute_path(path: &Path) -> Result<String, Box<dyn Error>> {
    Ok(path.canonicalize()?.to_string_lossy().into_owned())
}
