#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// index functions
/*
*
*
*
*
*
*/

int idx(int row, int column, int rows, int columns) {
	return row * columns + column;
}

int idx_transpose(int row, int column, int rows, int columns) {
	return column * rows + row;
}

double idx_double(double row, double column, int rows, int columns) {
	return row * columns + column;	
}

double idx_double_transpose(double row, double column, int rows, int columns) {
	return column * rows + row;
}

// matrix functions
/*
*
*
*
*
*
*/

void transpose_matrix(int NROWS, int NCOLS, int * a) { // dont know if i need this 
	int i, j;
	for (j=0; j<=NROWS; j++) {
		for (i=0; i<=NCOLS; i++) {
			a[trans_idx(i, j,NCOLS, NROWS)]; // = a[idx(j,i,NCOLS,NROWS)];
		}
	}
}

void print_matrix(int NROWS, int NCOLS, double * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%d  ", a[idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}

double * manual_matrix_creation_floating_elements(NROWS, NCOLS) {
	double *a_dbl = malloc(sizeof(double) * NROWS * NCOLS);
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%lf", &a[double_idx(i, j, NROWS, NCOLS)]); // manual user input
		}
	}
	return a;
}


void set_rows_and_columns(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);
}


void conjugate_gradient(int NROWS, int NCOLS, double * a_dbl) {
	double *r, *b, *p, *rsold, *rsnew, *Ap, *alpha, *x = malloc(sizeof(double) * NROWS * NCOLS); //may have to redefine x as actual size --> [1, N]
	

	for (int i = 0; i <NROWS; i++) {
		for (int j = 0; j <NCOLS; j++) {
			p[idx_double(i,j,NROWS,NCOLS)] = r[idx_double(i,j,NROWS,NCOLS)];

			r[idx_double(i,j,NROWS,NCOLS)] = b[idx_double(i,j,NROWS,NCOLS)] - (a_dbl[idx_double(i,j,NROWS,NCOLS)]*x[idx_double(i,j,1,NCOLS)]); // --> this probably wont work

			rsold[idx_double(i,j,NROWS,NCOLS)] = r[idx_double_transpose(i,j,NROWS,NCOLS)] * r[idx_double(i,j,NROWS,NCOLS)]; // probably can't do matrix multiplication this way -- pipe dream!

			size_t n = sizeof(b[idx_double(i,j,NROWS,NCOLS)]); //returns size of b? --> maybe?

			for(int k = 1; k < n; k++) {
				Ap[idx_double(i,j,NROWS,NCOLS)] = a_dbl[idx_double(i,j,NROWS,NCOLS)] * p[idx_double(i,j,NROWS,NCOLS)];
				alpha[idx_double(i,j,NROWS,NCOLS)] = rsold{idx_double(i,j,NROWS,NCOLS)] / (p[idx_double_transpose(i,j,NROWS,NCOLS)] * Ap[idx_double(i,j,NROWS,NCOLS)]);
			}//still workin'
		}
	}
}


//main
/*
*
*
*
*
*
*/

int main() {

	int NROWS, NCOLS;
	set_rows_and_columns(NROWS, NCOLS);




}