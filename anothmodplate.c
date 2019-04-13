#include <stdlib.h>
#include <stdio.h>
#include <math.h>



void JacobJacobi(double tol, int NROWS, int NCOLS) {
	int i, j;
	double dtmax;
	double (*plate1)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));
	double (*plate2)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));
	double temp;
	printf("enter the temp: ");
	scanf("%lf", &temp);
	plate1[5][5] = plate2[5][5] = temp;

do {
	dtmax = 0;
	for(i = 1; i < NROWS-1; i++) {
		for(j = 1; j < NCOLS-1;j++)
		{
			plate2[i][j] = (plate1[i-1][j] + plate1[i][j-1] + plate1[i+1][j] + plate1[i][j+1])/4; //physics
			if (fabs(plate2[i][j] - plate1[i][j]) > dtmax) {
			dtmax =fabs(plate2[i][j] - plate1[i][j]);
			}
		}
	}


	printf("dtmax:%.2f\n",dtmax);
	for(i = 1;i<NROWS-1;i++) {
		for(j=1;j<NCOLS-1;j++) {
			plate1[i][j] = plate2[i][j];
		}
	}
	} while(dtmax > tol);
	for(i=0;i<NROWS;i++) {
		for(j=0;j<NCOLS;j++) 
		printf("%5.0f", plate1[i][j]);
		printf("\n");
		
	}
}





int main() {
	int NROWS, NCOLS;
	int temp;
	double tol = 1.5;
	printf("please enter values for rows, cols: ");
	scanf("%d %d", &NROWS, &NCOLS);
	JacobJacobi(tol, NROWS, NCOLS);
	

	return 0;
}
