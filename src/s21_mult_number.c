#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = s21_valid_matrix(A);
  if (!error_code && (isinf(number) || isnan(number))) {
    error_code = ERROR_CALCULATION;
  }
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  if (!error_code) {
    error_code = s21_valid_matrix(result);
  }
  return error_code;
}