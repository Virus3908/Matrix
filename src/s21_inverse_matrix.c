#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  double det = 0;
  if (s21_valid_matrix(A)) {
    error_code = s21_valid_matrix(A);
  } else if (A->columns != A->rows) {
    error_code = ERROR_CALCULATION;
  } else {
    // printf("1ok\n");
    error_code = s21_determinant(A, &det);
    // printf("1ok\n");
    if (!det) {
      error_code = ERROR_CALCULATION;
    }
    // printf("1ok\n");
  }
  if (!error_code) {
    matrix_t B, C;
    if (A->columns == 1) {
      error_code = s21_mult_number(A, 1.0 / (det * det), result);
    } else {
      error_code = s21_calc_complements(A, &B);
      if (!error_code && !(error_code = s21_transpose(&B, &C))) {
        s21_mult_number(&C, 1.0 / det, result);
        s21_remove_matrix(&C);
      }
      s21_remove_matrix(&B);
    }
  }
  return error_code;
}