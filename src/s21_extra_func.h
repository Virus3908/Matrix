#ifndef S21_EXTRA_FUNC_H
#define S21_EXTRA_FUNC_H

#include <stdio.h>

#include "s21_matrix.h"

/// @brief Сравнивает матрицы
/// @param a double** матрица
/// @param b double** матрица
/// @param row Кол-во строк
/// @param column Кол-во столбцов
/// @return 1 равны, 0 не равны
int s21_compare_matrix(double **a, double **b, int rows, int columns);

/// @brief Заполняет матрицу значениями
/// @param A Указатель на матрицу
/// @param start Начало
/// @param step Шаг
void s21_fill_matrix(matrix_t *A, double start, double step);

/// @brief Выводит на экран матрицу
/// @param A Матрица для отображения
void s21_print_matrix(matrix_t *A);

/// @brief Проверяет матрицу на валидность
/// @param A Матрица
/// @return Возвращает код ошибки
int s21_valid_matrix(matrix_t *A);

/// @brief Нахождение минора матрицы
/// @param A Указатель на матрицу
/// @param col Номер столбца, который откинуть
/// @param row Номер строки, который откинуть
/// @param result Указатель на матрицу результат
/// @return Возвращает код ошибки
int s21_minor_matrix(matrix_t *A, int row, int col, matrix_t *result);

#endif