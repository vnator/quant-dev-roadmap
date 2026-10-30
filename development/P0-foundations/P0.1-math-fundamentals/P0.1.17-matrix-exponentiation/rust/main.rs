use std::ops::Mul;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Matrix<const N: usize> {
    pub data: [[i32; N]; N],
}

impl<const N: usize> Matrix<N> {
    pub fn new(data: [[i32; N]; N]) -> Self {
        assert!(N > 0, "Matrix dimension bust be positive");

        Self { data }
    }

    pub fn data(&self) -> &[[i32; N]; N] {
        &self.data
    }

    pub fn identity() -> Self {
        let mut data = [[0; N]; N];

        for i in 0..N {
            data[i][i] = 1;
        }

        Self::new(data)
    }

    pub fn pow(&self, mut expo: u64) -> Self {
        let mut result = Self::identity();
        let mut base = self.clone();

        while exp > 0 {
            if !exp.is_multiple_of(2) {
                result = result.multiply(&base);
            }

            exp /= 2;

            if exp > 0 {
                base = base.multiply(&base);
            }
        }

        result
    }
}

impl<const N: usize> Mul<&Matrix<N>> for &Matrix<N> {
    type Output = Matrix<N>;

    fn mul(self, rhs: &Matrix<N>) -> Self::Output {
        let mut result = [[0i32; N]; N];

        for i in 0..N {
            for j in 0..N {
                for k in 0..N {
                    let prod = self.data[i][k]
                        .checked_mul(rhs.data[k][j])
                        .expect("Matrix overflow multy");

                    result[i][j] = result[i][j].checked_add(prod).expect("Matrix overflow add");
                }
            }
        }

        Matrix::new(result)
    }
}
