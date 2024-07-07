#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (s21_valid_matrix(A)) {
    error_code = s21_valid_matrix(A);
  } else if (A->columns != A->rows) {
    error_code = ERROR_CALCULATION;
  } else {
    error_code = s21_create_matrix(A->rows, A->columns, result);
  }
  matrix_t B;
  for (int i = 0; !error_code && i < A->rows; i++) {
    for (int j = 0; !error_code && j < A->rows; j++) {
      error_code = s21_minor_matrix(A, i, j, &B);
      if (!error_code) {
        error_code = s21_determinant(&B, &result->matrix[i][j]);
        result->matrix[i][j] *= pow(-1, i + j);
        s21_remove_matrix(&B);
      }
    }
  }
  return error_code;
}