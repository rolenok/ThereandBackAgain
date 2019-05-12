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

//-----------------------------------------------LU_Decomposition functions----------------------------------------------------//

int LU_Decomposition(double * A, int * P, int N, double tol) {
	// P is permutation matrix
	// A is matrix of NxN
	// N is either NROWS or NCOLS... doesn't matter as they are symmetric
	int i,j,k,ptr,absA,imax,maxA;

	for (i = 0; i <= N; i++) {
		P[i] = i;
	}

	for (i = 0; i < N; i++) {
		maxA = 0;
		imax = i;

		for (k = i; k < N; k++) {
			if ((absA = fabs(A[idx(i,k,N,N)]) > maxA)) {
				maxA = absA;
				imax = k;
			}
		}
		if (maxA < tol) return 0; //failure

		if (imax != i) {
			j = P[i];
			P[i] = P[imax];
			P[imax] = j;

			ptr = A[i];
			A[i] = A[imax];
			A[imax] = ptr;
			P[N]++;

		}

		for(j = i+1; j<N;j++) {
			A[idx(j,i,N,N)] /= A[idx(i,i,N,N)];

			for(k = i+1;k<N;k++) {
				A[idx(j,k,N,N)] -= A[idx(j,i,N,N)] * A[idx(i,k,N,N)];

			}
		}

	}
}


double * manual_matrix_creation(int NROWS, int NCOLS) {
	double *a = malloc(sizeof(double) * NROWS * NCOLS);
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%lf", &a[idx(i, j, NROWS, NCOLS)]); // Right now just manual user input -- get over it.
		}
	}
	return a;
}

void LU_invert(double * A, int * P,  double * IA, int N) {

	// Let A be an NxN matrix and let A = (a(i,j)*1<=(i,j)<=N)
	// A(0) := A.
	// -l(i,n) := -((a(i,n))^(n-1)/(a(n,n))^(n-1))

	// A^(n) := L(n)*A^(n-1).
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (P[i] == j) {
				IA[idx(i,j,N,N)] = 1;

			}
			else {
				IA[idx(i,j,N,N)] = 0;
			}

			for(int k = 0;k<i;k++) {
				IA[idx(i,j,N,N)] -= A[idx(i,k,N,N)] * IA[idx(k,j,N,N)];
			}

			IA[idx(i,j,N,N)] = IA[idx(i,j,N,N)] / A[idx(i,i,N,N)];
		}

	}
}

void print_matrix(int NROWS, int NCOLS, double * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%lf  ", a[idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}

int main() {

	int N = 3;
	double tol = 1.0;
	int * P = malloc(sizeof(int)*N);
	double * IA = malloc(sizeof(double)*N*N);
	double * A = manual_matrix_creation(N,N);



	LU_Decomposition(A,P,N,tol);
	LU_invert(A,P,IA,N);

	print_matrix(N,N,IA);
}