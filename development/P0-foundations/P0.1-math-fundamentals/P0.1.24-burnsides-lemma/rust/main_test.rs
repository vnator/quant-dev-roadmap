use super::*;
use rstest::rstest;

#[rstest]
#[case(
    vec![
        vec![0, 1, 2, 3],
        vec![1, 2, 3, 0],
        vec![2, 3, 0, 1],
        vec![3, 0, 1, 2],
    ],
    1
)]
// Grupo C2: troca os elementos 0 e 1, mantendo o 2 fixo.
#[case(
    vec![
        vec![0, 1, 2],
        vec![1, 0, 2],
    ],
    2
)]
// Grupo trivial: somente a identidade.
#[case(
    vec![vec![0, 1, 2]],
    3
)]
// Ação não fiel: dois elementos do grupo agem como identidade.
#[case(
    vec![
        vec![0, 1, 2],
        vec![0, 1, 2],
    ],
    3
)]
// Conjunto vazio: nenhuma órbita.
#[case(
    vec![vec![]],
    0
)]
fn test_burnside_orbits(#[case] group_actions: Vec<Vec<usize>>, #[case] expected: usize) {
    assert_eq!(burnside_orbits(&group_actions), Ok(expected));
}

#[test]
fn test_empty_group() {
    let actions: Vec<Vec<usize>> = vec![];

    assert_eq!(burnside_orbits(&actions), Err(BurnsideError::EmptyGroup));
}

#[test]
fn test_inconsistent_permutation_size() {
    let actions = vec![vec![0, 1], vec![0]];

    assert_eq!(
        burnside_orbits(&actions),
        Err(BurnsideError::InconsistentPermutationSize)
    );
}

#[test]
fn test_invalid_permutation() {
    // Índice 2 não existe em um conjunto de tamanho 2.
    let out_of_range = vec![vec![0, 2]];

    assert_eq!(
        burnside_orbits(&out_of_range),
        Err(BurnsideError::InvalidPermutation)
    );

    // O índice 0 aparece duas vezes.
    let duplicated = vec![vec![0, 0]];

    assert_eq!(
        burnside_orbits(&duplicated),
        Err(BurnsideError::InvalidPermutation)
    );
}

#[test]
fn test_non_integral_average() {
    // Identidade e ciclo de três elementos não formam,
    // sozinhos, um grupo completo.
    //
    // A média seria (3 + 0) / 2 = 1.5.
    let actions = vec![vec![0, 1, 2], vec![1, 2, 0]];

    assert_eq!(
        burnside_orbits(&actions),
        Err(BurnsideError::NonIntegralAverage)
    );
}
