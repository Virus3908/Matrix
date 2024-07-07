#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_code = s21_valid_matrix(A);
  if (!result) {
    error_code = ERROR_CALCULATION;
  }
  if (!error_code && A->columns != A->rows) {
    error_code = ERROR_CALCULATION;
  }
  if (!error_code) {
    int sign = 1;
    *result = 0;
    if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->columns && !error_code; i++) {
        matrix_t B;
        error_code = s21_minor_matrix(A, 0, i, &B);
        if (!error_code) {
          double minor_det_res = 0;
          error_code = s21_determinant(&B, &minor_det_res);
          *result += (sign * A->matrix[0][i] * minor_det_res);
          sign *= -1;
        }
        s21_remove_matrix(&B);
      }
    }
  }
  return error_code;
}