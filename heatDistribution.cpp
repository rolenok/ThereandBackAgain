/*************************************************************************************************************************
* Temperature distribution in metal plates. A classic engineering problem for C/C++ and the 1st of the Thirteen Dwarves.
* Serial Implementation works, parallel implementation does not (This is almost embarrassingly parallel, so shouldn't be too long --> 
* More an issue of dealing with technicalities of composability over having trouble implementing parallel.)
* 
* +++++++++LEGEND++++++++++
* (ideal) --> is composed, commented, follows language standards and executes properly with no bugs (having been repeatedly tested)
* (excellent) --> is composed, follows language standards and excecutes properly with no known bugs
* (good) --> follows language standards and executes properly with no known bugs
* (fair) -->  compiles, runs and gives the expected output.
* (sloppy) --> has major bugs or gives unexpected output.
* (needs work) --> has runtime errors and/or compile-time errors.
* (incomplete) --> unfinished.
*++++++++++++++++++++++++++
**********************************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <mpi.h>
#include <math.h>
#define NROWS 6
#define NCOLS 8

using namespace std;

int heatDistro(double top_t, double bot_t, double right_t, double left_t, double tol) // heat distribution function (fair)
{
double plate2[NROWS][NCOLS] = {{0}}, plate1[NROWS][NCOLS] = {{0}}; // return value
double dtmax =0.0; // return value
int i, j;

	for (j = 0; j<NCOLS;j++) {
	plate1[0][j] = plate2[0][j] = top_t;
	plate1[NROWS-1][j] = plate2[NROWS-1][j] = bot_t;
	}
	for (i =0;i < NROWS-1; i++) {
	plate1[i][0] =plate2[i][0] = left_t;
	plate1[i][NCOLS-1] = plate2[i][NCOLS-1] = right_t;
	}
do 
{
	dtmax = 0;
	for(i = 1; i < NROWS-1; i++)
	for(j = 1; j < NCOLS-1;j++)
	{
		plate2[i][j] = (plate1[i-1][j] + plate1[i][j-1] + plate1[i+1][j] + plate1[i][j+1])/4;
		if (fabs(plate2[i][j] - plate1[i][j]) > dtmax)
		dtmax =fabs(plate2[i][j] - plate1[i][j]);
	}
	printf("dtmax:%.2f\n",dtmax);
	for(i = 1;i<NROWS-1;i++)
	for(j=1;j<NCOLS-1;j++)
	plate1[i][j] = plate2[i][j];
	}while(dtmax > tol);
	for(i=0;i<NROWS;i++){
		for(j=0;j<NCOLS;j++)
		printf("%5.0f", plate1[i][j]);
		printf("\n");
	}
	return plate1, dtmax;
	}

int main(int argc, char **argv) { // (needs work)
	int rank, size;
	double top_t, bot_t, right_t, left_t, tol;  // partition of plate
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Bcast()

	cout << "Enter the temperatures of the left, right, top and bottom sides of the plate: " << endl;
	cin >> left_t >> right_t >> top_t >> bot_t;
	cout << "Enter the tolerance value: " << endl;
	cin >> tol;
	double plate = heatDistro(top_t, bot_t, right_t, left_t, tol); // 

	MPI_Reduce(&plate, 1, 0, MPI_SUM, MPI_DOUBLE, MPI_INT, MPI_COMM_WORLD); // don't think this is quite right

	MPI_Finalize();
	return 0;


}
