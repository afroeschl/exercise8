/// @file
/// @brief Task1: "single-file" executable C program

/// @todo Include C standard library headers as needed
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/// @todo Implement a function 'isprime' according to the description below:
/// - the function receives an 'unsigned int' value and
/// - returns 'true' (or 1) if the value is a prime number
/// - returns 'false' (or 0) if the value is a not a prime number
/// @note you need to include '#include <stdbool.h>' to be able to use a boolean
/// type 'bool'
///       and constants 'true' and 'false'

/// @todo Implement a function 'count_primes' according to the description
/// below:
/// - the function receives an array of 'unsigned int' values, e.g. 'unsigned
/// int values[]', and also its size as a separate parameter
/// - the function returns the number of prime numbers in the array
/// @note use your function 'isprime' to check for primes in the array

/// @todo Implement a 'main' function conducting the following tasks in this
/// order:
/// - construct two local arrays of type 'unsigned int[]' containing the
/// following sequences of values:
///   {1, 20, 21, 43, 32, 42, 2344, 42433, 6, 2, 0, 22, 45, 47, 1033, 1247}
///   {21, 22, 44, 33, 7, 3, 1, 23, 46, 48, 1034, 1248}
/// - use your function 'count_primes' to count the number of primes in each of
/// the sequences
/// - print the overall number of primes (summing both results) to the console

bool isprime(unsigned int value) {
  if (value < 2)
    return false;
  for (unsigned int i = 2; i * i <= value; ++i) {
    if (value % i == 0)
      return false;
  }
  return true;
}

int count_primes(const unsigned int *values, size_t size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (isprime(values[i])) {
      ++count;
    }
  }
  return count;
}

int main() {
  unsigned int seq1[] = {1, 20, 21, 43, 32, 42, 2344, 42433,
                         6, 2,  0,  22, 45, 47, 1033, 1247};
  unsigned int seq2[] = {21, 22, 44, 33, 7, 3, 1, 23, 46, 48, 1034, 1248};

  printf("Number of primes in seq1: %d\n",
         count_primes(seq1, sizeof(seq1) / sizeof(seq1[0])));
  printf("Number of primes in seq2: %d\n",
         count_primes(seq2, sizeof(seq2) / sizeof(seq2[0])));

  return 0;
}
