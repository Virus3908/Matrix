#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (s21_valid_matrix(A)) {
    error_code = s21_valid_matrix(A);
  } else if (s21_valid_matrix(B)) {
    error_code = s21_valid_matrix(B);
  } else if (A->columns != B->rows) {
    error_code = ERROR_CALCULATION;
  } else {
    error_code = s21_create_matrix(A->rows, B->columns, result);
  }
  if (!error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  if (!error_code) {
    error_code = s21_valid_matrix(result);
  }
  return error_code;
}