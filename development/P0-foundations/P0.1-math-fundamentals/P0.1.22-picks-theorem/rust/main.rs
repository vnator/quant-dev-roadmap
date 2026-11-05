// Implement the mathematical algorithm here
pub fn picks_area(int_points: u64, border_points: u64) -> f64 {
    (int_points as f64) + (border_points as f64 / 2.0) - 1.0
}

#[cfg(test)]
mod main_test;
