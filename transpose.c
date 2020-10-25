/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 2: Transpose
 *
 * TODO(by student): Brief description of the purpose
 * of this program.
 *
 * @file: transpose.c
 * @author: XXX (Group XXX)
 */

#include "cs1010.h"
#include <assert.h>

/**
 * Allocated and read a matrix from the standard input.  
 * The caller is responsible to free the matrix.  
 *
 * @param[in] row The number of rows to read.
 * @param[in] col The number of columns to read.
 * @return    A 2D array containing the matrix.
 */
double** read_matrix(long row, long col) 
{
  double **m = calloc((size_t)row, sizeof(double *));
  if (m == NULL) {
    return NULL;
  }
  for (long i = 0; i < row; i += 1) {
    m[i] = cs1010_read_double_array(col);
    if (m[i] == NULL) {
      for (long j = 0; j < i; j += 1) {
        free(m[j]);
      }
      free(m);
      return NULL;
    }
  }
  return m;
}

/**
 * Allocated a 2D matrix of 0s.
 * The caller is responsible to free the matrix.  
 *
 * @param[in] row The number of rows to allocate.
 * @param[in] col The number of columns to allocate.
 * @return    A 2D array containing the matrix.
 */
double** alloc_matrix(long row, long col) 
{
  double **m = calloc((size_t)row, sizeof(double *));
  if (m == NULL) {
    return NULL;
  }
  for (long i = 0; i < row; i += 1) {
    m[i] = calloc((size_t)col, sizeof(double));
    if (m[i] == NULL) {
      for (long j = 0; j < i; j += 1) {
        free(m[j]);
      }
      free(m);
      return NULL;
    }
  }
  return m;
}

/**
 * Print a given 2D matrix.
 *
 * @param[in] m   The matrix to print.
 * @param[in] row The number of rows to print.
 * @param[in] col The number of columns to print.
 */
void print_matrix(double **m, long row, long col) 
{
  for (long i = 0; i < row; i += 1) {
    for (long j = 0; j < col; j += 1) {
      cs1010_print_double(m[i][j]);
      if (j == col - 1) {
        cs1010_println_string("");
      } else {
        cs1010_print_string(" ");
      }
    }
  }
}

/**
 * Free the memory allocated for a 2D matrix.
 *
 * @param[in] m   The matrix to free.
 * @param[in] row The number of rows in the matrix m.
 */
void free_matrix(double **m, long row)
{
  for (long i = 0; i < row; i += 1) {
    free(m[i]);
  }
  free(m);
}

/**
 * Transpose a given matrix m1 and store the output in m2.
 *
 * @param[in]  m1  The given matrix to transpose.
 * @param[out] m2  The transposed matrix.
 * @param[in]  num_of_rows The number of rows in m1.
 * @param[in]  num_of_cols The number of rows in m2.
 */
void transpose(double **m1, double **m2, long num_of_rows, long num_of_cols) {
  for (long i = 0; i < num_of_rows; i += 1) {
    for (long j = 0; j < num_of_cols; j += 1) {
      m2[j][i] = m1[i][j];
    }
  }
}

int main() {
  long row = cs1010_read_long();
  long col = cs1010_read_long();

  double **m1 = read_matrix(row, col);
  if (m1 == NULL) {
    cs1010_print_string("memory allocation error");
    return 1;
  }
  double **m2 = alloc_matrix(col, row);
  if (m2 == NULL) {
    free(m1);
    cs1010_print_string("memory allocation error");
    return 1;
  }

  transpose(m1, m2, row, col);

  print_matrix(m2, col, row);
  free_matrix(m1, row);
  free_matrix(m2, col);
}
