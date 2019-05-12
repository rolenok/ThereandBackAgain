#include <stdio.h>
#include <math.h>


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



