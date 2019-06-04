#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWT 35
#define COLT 1
#define sep ";"
#define comma ","
#define MAX 100000;

double flipmask = (double)0;

void ue(double array[][COLT], double arrayori[][COLT], int row, int col, const char *colstr)
{
  double throw;
  int bit;
  long long flipmask = 0;
  long long data;

  array[row][col] = atof(colstr);
  arrayori[row][col] = atof(colstr);

  throw = drand48();
  bit = rand() % 64; // bit to flip
  bit = 47; // 63-0, 63 = sign bit
 // printf("bit to flip = %d\n", bit);
  flipmask = flipmask | ((long long)1 << bit);
  data = *(long long *)&array[row][col];
  data = data ^ flipmask;
  array[row][col] = *(double *)&data;
  //printf("%lf%s\n", array[row][col], sep);
}

void create_csv(char *filename, double a[][COLT], double a1[][COLT], int n, int m)
{
  printf("\n Creating %s.csv file", filename);
  FILE *fp;
  filename = strcat(filename, ".csv");
  fp = fopen(filename, "w+");
  for (n = 0; n < ROWT; n++){
	  fprintf(fp, "%lf,%lf\n", a1[n][0], a[n][0]);
  }
  fclose(fp);
  printf("\n %sfile created", filename);
}


int main()
{
  
  FILE *f = fopen("sedov_dens0002.csv", "r");
  if (f)
    {
      double array[ROWT][COLT] = { 0 };
	  double arrayori[ROWT][COLT] = { 0 };
      int n, row, col;
      char rowstr[100000], colstr[100000], *p;
	
	  for (row = 0; row < ROWT && fgets(rowstr, 100, f); ++row) 
	  {
		  for (col = 0, n = *colstr = 0, p = rowstr; col < COLT && sscanf(p, "%12[^"sep"]%n", colstr, &n) != EOF; ++col, p += n, *p ? ++p : 0)
		  {
           ue(array, arrayori, row, col, colstr);
		  }	
	  }
	  puts("\n");

	  char str[100];
	  printf("\n Enter the filename :");
	  gets(str);
	  create_csv(str, array, arrayori, row, col);

      fclose(f);    
    }
  else
    return 1;
  return 0;
}
