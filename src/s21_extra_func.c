#include "s21_extra_func.h"

int s21_compare_matrix(double** a, double** b, int rows, int columns) {
  int result = SUCCESS;
  for (int i = 0; i < rows && result; i++) {
    for (int j = 0; j < columns && result; j++) {
      if (fabs(a[i][j] - b[i][j]) > EPS) {
        result = FAILURE;
      }
    }
  }
  return result;
}

void s21_fill_matrix(matrix_t* A, double start, double step) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = start;
        start += step;
      }
    }
  }
}

int s21_valid_matrix(matrix_t* A) {
  int error_code = OK;
  if (A && A->matrix && A->columns > 0 && A->rows > 0) {
    for (int i = 0; !error_code && i < A->rows; i++) {
      for (int j = 0; !error_code && j < A->columns; j++) {
        error_code = (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j]))
                         ? ERROR_CALCULATION
                         : OK;
      }
    }
  } else {
    error_code = ERROR_MATRIX;
  }
  return error_code;
}

// void s21_print_matrix(matrix_t* A) {
//   if (A->matrix) {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         printf("%10g\t", A->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   }
// }

int s21_minor_matrix(matrix_t* A, int row, int col, matrix_t* result) {
  int error_code = s21_valid_matrix(A);
  int row_offset = 0;
  int col_offset = 0;
  if (!error_code) {
    error_code = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  }
  if (!error_code) {
    for (int i = 0; i < result->rows; i++) {
      if (i == row) {
        row_offset = 1;
      }
      for (int j = 0; j < result->columns; j++) {
        if (j == col) {
          col_offset = 1;
        }
        result->matrix[i][j] = A->matrix[i + row_offset][j + col_offset];
      }
      col_offset = 0;
    }
  }
  return error_code;
}