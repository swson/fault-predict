#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP 10
#define N 64 // 64 bits

double flipmask = (double)0;

int main()
{
  double throw, data_org=1.0;
  int bit, i;
  long long flipmask = 0;
  long long data;

  printf("orignal data = %.15e\n", data_org); // %.10e format for scientific format

  for (i=1; i<N; i++) {
    //throw = drand48(); // not used at the moment
    //bit = rand() % 64; // bit to flip
    bit = i; 
    printf("bit to flip = %d: ", bit);
    flipmask = flipmask | ((long long)1 << bit);
    data = *(long long *)&data_org; // cast double to int-compatible format
    data = data ^ flipmask;
    data_org = *(double *)&data;
    //if (bit%STEP == 0) 
    printf("%.20e\n", data_org);
    data_org = 1.0; // reset to original 1.0
    flipmask = 0;
  }

  return 0;
}
