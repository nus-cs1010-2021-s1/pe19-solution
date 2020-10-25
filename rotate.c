/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 2: Rotate
 *
 * TODO(by student): Brief description of the purpose
 * of this program.
 *
 * @file: rotate.c
 * @author: XXX (Group XXX)
 */

#include "cs1010.h"
#include <stdbool.h>

/**
 * Look for q in list[i]..list[j].
 *
 * @pre list is sorted.
 * @return -1 if not found, the position of q in list otherwise.
 */
long binary_search(const long list[], long i, long j, long q) {
  if (i > j) {
    return -1;
  }
  long mid = (i+j)/2;
  if (list[mid] == q) {
    return mid;
  } 
  if (list[mid] > q) {
    return binary_search(list, i, mid-1, q);
  }
  return binary_search(list, mid+1, j, q);
}

/**
 * Look for q in list[i]..list[j].
 *
 * @pre list is sorted.
 * @return -1 if not found, the position of q in list otherwise.
 */
long search(const long list[], long i, long j, long q) {
  if (j < i) {
    return -1;
  }

  // { list[i]..list[j] has 3 or more elements }

  long mid = (i+j)/2;
  if (list[mid] == q) {
    return mid;
  } 

  /*
   * - list[i]..list[mid] is strictly increasing.  So we do binary search
   *   if q falls within this range.  Otherwise, we recursively search 
   *   the other half (which is a rotated list).
   */
  if (list[i] < list[mid]) {
    if (list[i] <= q && q <= list[mid]) {
      return binary_search(list, i, mid-1, q);
    }
    return search(list, mid+1, j, q);
  }

  /*
   * - list[i]..list[mid] is rotated.  So we do a binary search on the 
   *   other half.
   */
  if (list[mid+1] <= q && q <= list[j]) {
    return binary_search(list, mid+1, j, q);
  }
  return search(list, i, mid-1, q);
}

int main() {
  long n = cs1010_read_long();
  long *list = cs1010_read_long_array(n);
  long query = cs1010_read_long();
  if (list == NULL) {
    cs1010_println_string("memory allocation error");
    return 1;
  }

  long pos = search(list, 0, n - 1, query);
  if (pos == -1) {
    cs1010_println_string("not found");
  } else {
    cs1010_println_long(pos);
  }

  free(list);
}
