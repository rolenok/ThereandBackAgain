#include <stdio.h>

double idx_double(double row, double column, int rows, int columns) {
  return row * columns + column;

double * multiply_matrices_floating_elements(int m,int n, int c, int d, int p, int q, double * a, double * b) {
	double sum = 0.0;

	double *multiply = malloc(sizeof(double)*m*n)
	for (int c = 0; c < m; c++) {
    	for (int d = 0; d < q; d++) {
        	for (int k = 0; k < p; k++) {
          		sum = sum + a[(int)idx_double(c,k,m,n)]*b[(int)idx_double(k,d,n,m)];
        	}
 
        	multiply[(int)idx_double(c,d,m,n)] = sum;
        	sum = 0;
      	}
    }
    return multiply;
}

int main() {
  int m = 5;
  int n = 5;
  int c = 5;
  ind d = 5;
  int p = 5;
  int q = 5;

  

  double * mim = multiply_matrices_floating_elements();

  return 0;
}