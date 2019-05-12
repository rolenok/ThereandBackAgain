#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* C program to find the transpose of a Matrix */

int idx(int row, int column, int rows, int columns) {
	return row * columns + column;
}

int trans_idx(int row, int column, int rows, int columns) {
	return rows*column + row;
}

int * matrix_creation(int NROWS, int NCOLS) {
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
			a[idx(i, j,NCOLS, NROWS)]; // = a[idx(j,i,NCOLS,NROWS)];
		}
	}
}

void print_matrix(int NROWS, int NCOLS, int * a) {
	for (int i = 0; i < NROWS; i++) {
		for (int j = 0; j < NCOLS; j++) {
			printf("%d  ", a[idx(i, j, NROWS, NCOLS)]);
		}
		printf("\n");
	}
}

void set_rows_and_columns(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);

}
int main() {
	int NROWS, NCOLS;
	set_rows_and_columns(&NROWS, &NCOLS);

	int * a = matrix_creation(NROWS, NCOLS);
	transpose_matrix(NROWS, NCOLS, a);

	print_matrix(NROWS, NCOLS, a);
}