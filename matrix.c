/* Functions necessary for various dwarf calculations (really just a file of matrix and index functions) */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// index functions

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

/****************** matrix creation ***************************/

int * manual_matrix_creation(int NROWS, int NCOLS) {
	int *a = malloc(sizeof(int) * NROWS * NCOLS);
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%d", &a[idx(i, j, NROWS, NCOLS)]); // Right now just manual user input -- get over it.
		}
	}
	return a;
}

void transpose_matrix(int NROWS, int NCOLS, int * a) {
	int i, j;
	for (j=0; j<=NROWS; j++) {
		for (i=0; i<=NCOLS; i++) {
			a[trans_idx(i, j,NCOLS, NROWS)]; // = a[idx(j,i,NCOLS,NROWS)];
		}
	}
}


int * automatic_matrix_creation_random_elements(int NROWS, int NCOLS) {

	int *a_rand = malloc(sizeof(int)*NROWS*NCOLS)
	for (i =0; i<NROWS;i++) {
		for(j=0; j<NCOLS; j++) {
			a_rand[idx(i,j,NROWS,NCOLS)] = rand();
		}
	}
	return a_rand;
}


void print_matrix(int NROWS, int NCOLS, int * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%d  ", a[idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}

void print_matrix_transpose(int NROWS, int NCOLS, int * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%d  ", a[trans_idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}

void set_rows_and_columns(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);

}

double * manual_matrix_creation_floating_elements() {
	double *a = malloc(sizeof(double) * NROWS * NCOLS);
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%lf", &a[double_idx(i, j, NROWS, NCOLS)]); // Right now just manual user input -- get over it.
		}
	}
	return a;
}

void conjugate_gradient(int NROWS, int NCOLS, double * a_dbl) {
	double *r, *b, *p, *rsold, *rsnew, *Ap, *alpha, *x = malloc(sizeof(double) * NROWS * NCOLS); //may have to redefine x as actual size --> [1, N]
	

	for (int i = 0; i <NROWS; i++) {
		for (int j = 0; j <NCOLS; j++) {
			p[idx_double(i,j,NROWS,NCOLS)] = r[idx_double(i,j,NROWS,NCOLS)];

			r[idx_double(i,j,NROWS,NCOLS)] = b[idx_double(i,j,NROWS,NCOLS)] - (a_dbl[idx_double(i,j,NROWS,NCOLS)]*x[idx_double(i,j,1,NCOLS)]); // --> this probably wont work

			rsold[idx_double(i,j,NROWS,NCOLS)] = r[idx_double_transpose(i,j,NROWS,NCOLS)] * r[idx_double(i,j,NROWS,NCOLS)]; // probably can't do matrix multiplication this way -- pipe dream!

			size_t n = sizeof(b[idx_double(i,j,NROWS,NCOLS)]); //returns size of b? --> should work

			for(int k = 1; k < n; k++) {
				Ap[idx_double(i,j,NROWS,NCOLS)] = a_dbl[idx_double(i,j,NROWS,NCOLS)] * p[idx_double(i,j,NROWS,NCOLS)];
				alpha[idx_double(i,j,NROWS,NCOLS)] = rsold{idx_double(i,j,NROWS,NCOLS)] / (p[idx_double_transpose(i,j,NROWS,NCOLS)] * Ap[idx_double(i,j,NROWS,NCOLS)]);
			}
		}
	}
}

void matrix_multiply(double r, double k)


}
int main() {
	int NROWS, NCOLS;
	set_rows_and_columns(&NROWS, &NCOLS);

	int * a = manual_matrix_creation(NROWS, NCOLS);
	
	//transpose_matrix(NROWS, NCOLS, a);

	print_matrix_transpose(NROWS, NCOLS, a);
}
