#include <stdlib.h>
#include <stdio.h>
#include <math.h>



void periodic_jacobi_matrix(int NROWS, int NCOLS, double tol, int temp, int tx, int ty) {
	int i, j;
	double dtmax;

	double (*plate1)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));
	double (*plate2)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));

	plate1[tx][ty] = plate2[tx][ty] = temp;
	

do {
	dtmax = 0.0;
	for(i = 1; i < NROWS-1; i++) {
		for(j = 1; j < NCOLS-1;j++)
		{
			plate2[i][j] = (plate1[i-1][j] + plate1[i][j-1] + plate1[i+1][j] + plate1[i][j+1])/4; //Jacobi algorithm 
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

void set_tolerance(double * tol) {
	printf("please enter the tolerance: ");
	scanf("%lf", tol);
}

void set_rows_and_columns(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);
}

void set_temperature(int * temp) {
	printf("enter the temp: ");
	scanf("%d", temp);
}

void set_heatsource_location(int * tx, int * ty) {
		printf("Enter the location of the temp on the plate...");
		scanf("%d %d",tx,ty);
}

int main() {

	int NROWS, NCOLS;
	set_rows_and_columns(&NROWS, &NCOLS);

	int temp;
	set_temperature(&temp);

	double tol;
	set_tolerance(&tol);

	int tx, ty;
	set_heatsource_location(&tx, &ty);

	periodic_jacobi_matrix(NROWS, NCOLS, tol, temp, tx, ty);
	

	return 0;
}
