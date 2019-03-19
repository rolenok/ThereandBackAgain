#include <stdio.h>
#include <math.h>

#define NROWS 10
#define NCOLS 10

int main() {
	int i, j;
	int mat[NROWS][NCOLS] = {{0}};

	for (i =0; i<NROWS;i++) {
		for(j=0; j<NCOLS; j++) {
			mat[i][j] = rand();
		}
	}
	printf(mat[i][j]);
}



