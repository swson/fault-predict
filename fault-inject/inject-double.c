#include <stdio.h>

const double  MD_WORD_ERROR_RATE = 1e-7;
#define N 10000
double A[N];

main()
{
  double elapsed, throw, error_prob;
  double curr_t = 0.0, last_t = 0.0;
  int fault_injected = 0;
  long log byte_pos, bit_pos;
  long log flipmask = 0;
  int i;

  for (i=0; i < 1000; i++) {
    curr_t = 1.0*i;
    elapsed = curr_t - last_t;
    elapsed *= 10000000;
    error_prob = MD_WORD_ERROR_RATE * elapsed;
    printf ("error_prob = %f\n", error_prob); 
    throw = drand48();
    printf ("throw = %f\n", throw); 

    if (throw <= error_prob) {
      byte_pos = rand() % N;
      bit_pos = rand() % 64;
      printf ("fault injected: i=%d: byte_pos = %d, bit_pos = %d\n", i, byte_pos, bit_pos);
      flipmask = flipmask | (double)1 << bit_pos;
      last_t = curr_t;
      fault_injected++;
    }

    A[byte_pos] = A[byte_pos] ^ flipmask;

  }

  printf("fault injected = %d\n", fault_injected); 
  return 0;
}
