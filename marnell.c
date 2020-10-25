#include "cs1010.h"
#include <math.h>

#define PRIME 1
#define SEMIPRIME 2
#define NEITHER 3

long is_prime_or_semiprime(long n) {
  if (n <= 1) {
    return NEITHER;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (is_prime_or_semiprime(i) == PRIME && is_prime_or_semiprime(n/i) == PRIME) {
        return SEMIPRIME;
      }
      return NEITHER;
    }
  }
  return PRIME;
}

int main()
{
  long n = cs1010_read_long();
  long counter = 0;

  for (long i = 2; i <= n/2; i++) {
    long j = n - i;
    long p1 = is_prime_or_semiprime(i);
    if (p1 == PRIME || p1 == SEMIPRIME) {
      long p2 = is_prime_or_semiprime(j);
      if ((p1 == PRIME && p2 == SEMIPRIME) || (p1 == SEMIPRIME && p2 == PRIME)) {
        counter += 1;
      }
    }
  }
  cs1010_println_long(counter);
}
