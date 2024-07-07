#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 10e-7

typedef enum {
  OK = 0,
  ERROR_MATRIX = 1,
  ERROR_CALCULATION = 2
} s21_matrix_errors;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#include "s21_extra_func.h"

/// @brief Создание матрицы
/// @param rows Кол-во строк
/// @param columns Кол-во столбоцов
/// @param result Указатель на matrix_t
/// @return Возвращает код ошибки
int s21_create_matrix(int rows, int columns, matrix_t *result);

/// @brief Очистка матрицы
/// @param A Матрица, которую нужно очистить
void s21_remove_matrix(matrix_t *A);

/// @brief Сравнение матриц
/// @param A Матрица А
/// @param B Матрица Б
/// @return 1 - Матрицы равны, 0 - Матрицы не равны
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/// @brief Сумма матриц
/// @param A Указатель на слагаемое
/// @param B Указатель на слагаемое
/// @param result Указатель на сумму
/// @return Возвращает код ошибки
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/// @brief Разность матриц
/// @param A Указатель на уменьшаемое
/// @param B Указатель на вычитаемое
/// @param result Указатель на разность
/// @return Возвращает код ошибки
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/// @brief Умножает матрицу на число
/// @param A Указатель на матрицу множитель
/// @param number Число множитель
/// @param result Указатель на матрицу результата
/// @return Возвращает код ошибки
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/// @brief Перемножение матриц
/// @param A Указатель на первый множитель
/// @param B Указатель на второй множитель
/// @param result Указатель на матрицу результата
/// @return Возвращает код ошибки
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/// @brief Транспонирование матрицы
/// @param A Указатель на матрицу для транспонирования
/// @param result Указатель на матрицу результата
/// @return Возвращает код ошибки
int s21_transpose(matrix_t *A, matrix_t *result);

/// @brief Нахождение матрицы алгебраических дополнений
/// @param A Указатель на матрицу
/// @param result Указатель на матрицу результат
/// @return Возвращает код ошибки
int s21_calc_complements(matrix_t *A, matrix_t *result);

/// @brief Находит определитель квадратной матрицы
/// @param A Указатель на матрицу
/// @param result Указатель на переменную куда записать результат
/// @return Возвращает код ошибки
int s21_determinant(matrix_t *A, double *result);

/// @brief Нахождение обратной матрицы
/// @param A Указатель на матрицу
/// @param result Указатель на матрицу результат
/// @return Возвращает код ошибки
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif