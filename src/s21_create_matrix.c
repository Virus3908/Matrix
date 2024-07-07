#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = OK;
  if (result) {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
  }
  if (rows > 0 && columns > 0 && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows + rows * columns, sizeof(double));
    if (!result->matrix) {
      error_code = ERROR_MATRIX;
    }

    double *ptr = (double *)(result->matrix + rows);
    for (int i = 0; i < rows && !error_code; i++) {
      result->matrix[i] = ptr + i * columns;
    }
  } else {
    error_code = ERROR_MATRIX;
  }
  return error_code;
}