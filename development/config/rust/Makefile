RUST_MANIFEST := config/rust/Cargo.toml
RUST_FORMAT_CONFIG := config/rust/rustfmt.toml

RUST_BUILD := .build/rust
RUST_COVERAGE := coverage/rust

RUST_FILES := $(shell find P* -type f \
	-path '*/rust/*.rs' 2>/dev/null | sort)

export CARGO_TARGET_DIR := $(RUST_BUILD)

.PHONY: rust-build rust-test rust-coverage rust-lint
.PHONY: rust-format rust-format-check rust-clean

rust-build:
	cargo build --manifest-path $(RUST_MANIFEST)

rust-test:
	cargo test --manifest-path $(RUST_MANIFEST)

rust-coverage:
	cargo llvm-cov \
		--manifest-path $(RUST_MANIFEST) \
		--html \
		--output-dir $(RUST_COVERAGE)

rust-lint:
	cargo clippy \
		--manifest-path $(RUST_MANIFEST) \
		--all-targets

rust-format:
	rustfmt --edition 2024 \
		--config-path $(RUST_FORMAT_CONFIG) \
		$(RUST_FILES)
	cargo fmt --manifest-path $(RUST_MANIFEST)

rust-format-check:
	rustfmt --check --edition 2024 \
		--config-path $(RUST_FORMAT_CONFIG) \
		$(RUST_FILES)
	cargo fmt --manifest-path $(RUST_MANIFEST) -- --check

rust-clean:
	cargo clean --manifest-path $(RUST_MANIFEST)
	rm -rf $(RUST_COVERAGE)
