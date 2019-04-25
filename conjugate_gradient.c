#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------- index functions-------------------------------------------------------//
/*
* test to see if these work properly with all the function calls and matrix manipulations
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

//------------------------------------------------ matrix functions-------------------------------------------------------//
/*
* Things to do:
*
*  *!* Function for matrix multiplications
*
*  *!* redefine the index of x, alpha, and/or any other variables that arent matrices of size [NROWS NCOLS]
*
*  *!* make sure sizeof works with index functions
*
*/

void transpose_matrix(int NROWS, int NCOLS, int * a) { // dont know if i need this 
	int i, j;
	for (j=0; j<=NROWS; j++) {
		for (i=0; i<=NCOLS; i++) {
			a[idx_transpose(i, j,NCOLS, NROWS)]; // = a[idx(j,i,NCOLS,NROWS)];
		}
	}
}

void matrix_inverse(int NROWS, NCOLS, int * a)

void print_matrix(int NROWS, int NCOLS, int * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%d  ", a[idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}


double * manual_matrix_creation_floating_elements(NROWS, NCOLS) {
	double *a_dbl = malloc(sizeof(double)*NROWS*NCOLS);
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("Enter element a%d%d: ",i+1, j+1);
           // scanf("%lf", &a[double_idx(i, j, NROWS, NCOLS)]); // manual user input
		}
	}
	return a_dbl;
}

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

void set_rows_and_columns(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);
}

int * multiply_matrices_integer_elements(int * a, int * b, int NROWS, int NCOLS) {
	int mult_rslt;
	for (int i = 0; i < NROWS; i++) {
    	for (int j = 0; j < NCOLS; j++) {
    		mult_rslt[idx(i,j,NROWS,NCOLS)] = 0;
        	for (int k = 0; k < NROWS; k++) {
          		mult_rslt[idx(i,j,NROWS,NCOLS)] += a[idx(i,k,NROWS,NCOLS)]*b[idx(k,j,NROWS,NCOLS)];
        	}
 
      	}
    }
    return mult_rslt;
}

//absolutely not complete

void conjugate_gradient_integer_elements(int NROWS, int NCOLS, int * a, int * b, int * x) {
	int * r = malloc(sizeof(int) * NROWS * NCOLS);
	int * p = malloc(sizeof(int) * NROWS * NCOLS);
	int * rsold = malloc(sizeof(int) * NROWS * NCOLS); 
	int * rsnew = malloc(sizeof(int) * NROWS * NCOLS); 
	int * Ap = malloc(sizeof(int) * NROWS * NCOLS); 
	int * alpha = malloc(sizeof(int) * 1 * NCOLS); //this seems miserably inefficient -- and I may have to redefine x and alpha as actual size --> [1, N]
	
	//result of multiplied variables ?

	// int r_squared = malloc(sizeof(int) * NROWS * NCOLS);
	int 
	for (int i = 0; i <NROWS; i++) {
		for (int j = 0; j <NCOLS; j++) {

			p[idx(i,j,NROWS,NCOLS)] = r[idx(i,j,NROWS,NCOLS)];

			r[idx(i,j,NROWS,NCOLS)] = b[idx(i,j,NROWS,NCOLS)] - (a[idx(i,j,NROWS,NCOLS)]*x[idx(i,j,1,NCOLS)]); // --> this probably wont work

			rsold[idx(i,j,NROWS,NCOLS)] = multiply_matrices_integer_elements(r, r, NROWS, NCOLS); //r[idx_transpose(i,j,NROWS,NCOLS)] * r[idx(i,j,NROWS,NCOLS)];

			size_t n = sizeof(b[idx(i,j,NROWS,NCOLS)]); //returns size of b? --> maybe?

			for(int k = 1; k < n; k++) {
				Ap[idx(i,j,NROWS,NCOLS)] = multiply_matrices_integer_elements(a, p, NROWS, NCOLS)//a[idx(i,j,NROWS,NCOLS)] * p[idx(i,j,NROWS,NCOLS)]; 

				alpha[idx(i,j,NROWS,NCOLS)] = rsold{idx(i,j,NROWS,NCOLS)] multiply_matrix_integer_elements(rsold, 
				inverse_matrix(multiply_matrices_integer_elements(p, Ap, NROWS, NCOLS), NROWS, NCOLS)); //rsold[idx(i,j,NROWS,NCOLS)] / (p[idx_transpose(i,j,NROWS,NCOLS)] * Ap[idx(i,j,NROWS,NCOLS)]);
				
				x[idx(i,j,1,NCOLS)] = x[idx(i,j,1,NCOLS)] + multiply_matrices_integer_elements(alpha, p, NROWS, NCOLS); //alpha[idx(i,j,NROWS,NCOLS)] * p[idx(i,j,NROWS,NCOLS)]; 
				
				r[idx(i,j,NROWS,NCOLS)] = r[idx(i,j,NROWS,NCOLS)] - (multiply_matrices_integer_elements(alpha, p, NROWS, NCOLS));//(alpha[idx(i,j,NROWS,NCOLS)]*p[idx(i,j,NROWS,NCOLS)]);
				
				rsnew[idx(i,j,NROWS,NCOLS)] = multiply_matrices_integer_elements(r, r, NROWS, NCOLS); //r[idx_transpose(i,j,NROWS,NCOLS)] * r[idx_double(i,j,NROWS,NCOLS)]; 

				
				if (sqrt(rsnew[idx(i,j,NROWS,NCOLS)]) < exp(1,-10)) {
					break;
				}
			}//still a brewin'
		}
	}
}


//main


int main() {

	int NROWS, NCOLS;
	set_rows_and_columns(&NROWS, &NCOLS);
	// int * mult_rslt = malloc(sizeof(int)*NROWS*NCOLS);
	int * a = manual_matrix_creation(NROWS, NCOLS);
	int * b = manual_matrix_creation(NROWS, NCOLS);
	int * x = manual_matrix_creation(NROWS, 1);

	conjugate_gradient_integer_elements(NROWS, NCOLS, a);

	multiply_matrices_integer_elements(a, b, mult_rslt, NROWS, NCOLS);

	print_matrix(NROWS, NCOLS, mult_rslt);
}
