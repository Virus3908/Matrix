#include "s21_matrix.h"

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if (A && B && A->matrix && B->matrix && A->rows == B->rows &&
      A->columns == B->columns) {
    result = s21_compare_matrix(A->matrix, B->matrix, A->rows, A->columns);
  } else {
    result = FAILURE;
  }
  return result;
}
