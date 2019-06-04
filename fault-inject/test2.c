#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

#define ROWT 4416
#define COLT 1
#define sep ";"
#define MAX 100000;

double flipmask = (double)0;

void ue(double array[][COLT], int row, int col, const char *colstr)
{
  double throw;
  int bit;
  long long flipmask = 0;
  long long data;

  array[row][col] = atof(colstr);
  //char buf[MAX];
  //printf("%s%lf%s", col?"":"\n", array[row][col], sep);
  printf("%lf%s\n",  array[row][col], sep); // original data

  throw = drand48();
  bit = rand() % 64; // bit to flip
  bit = 62; // 63-0, 63 = sign bit
  printf("bit to flip = %d\n", bit);
  flipmask = flipmask | ((long long)1 << bit);
  data = *(long long *)&array[row][col];
  data = data ^ flipmask;
  array[row][col] = *(double *)&data;
  printf("%lf%s\n", array[row][col], sep);
}

int main()
{
  
  FILE *f = fopen("sedov_dens0001.csv", "r");
  if (f)
    {
      double array[ROWT][COLT] = { 0 };
      int n, row, col;
      char rowstr[100], colstr[100], *p;

      for (row = 0; row < ROWT && fgets(rowstr, 100, f); ++row)
	for (col = 0, n=*colstr=0, p=rowstr; col < COLT && sscanf(p, "%12[^"sep"]%n",colstr, &n)!=EOF; ++col,p+=n, *p?++p:0)
	  ue(array, row, col, colstr);

      fclose(f); 
      puts("\n");
    }
  else
    return 1;
  return 0;
}
