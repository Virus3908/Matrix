#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (s21_valid_matrix(A)) {
    error_code = s21_valid_matrix(A);
  }
  if (!error_code &&
      !(error_code = s21_create_matrix(A->columns, A->rows, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  if (!error_code) {
    error_code = s21_valid_matrix(result);
  }
  return error_code;
}