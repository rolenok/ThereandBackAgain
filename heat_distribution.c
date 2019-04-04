#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include <time.h>
//#include <mpi.h>


int idx(int row, int column, int rows, int columns)
{
	return row * columns + column;
}

double *plate_creation(int NROWS, int NCOLS) {
	double *plate = malloc(sizeof(double) * NROWS * NCOLS);

	return plate;
}

void plate_print(int NROWS, int NCOLS, double * plate) {
	for(int i=0;i<NROWS;i++) {
		for(int j=0;j<NCOLS;j++)
			printf("%5.0f", plate[idx(i,j, NROWS, NCOLS)]);
		printf("\n");
	}
}

double plate_max(int NROWS, int NCOLS, double *plate)
{
	double max = plate[0];

	for(int i = 0; i < NCOLS; ++i)
	{
		for(int j = 0; j < NROWS; ++j)
		{
			max = max > plate[idx(i, j, NROWS, NCOLS)] ?  max : plate[idx(i, j, NROWS, NCOLS)];
		}
	}

	return max;
}

void plate_output_ppm(int id, double min, double max, int NROWS, int NCOLS, double *plate)
{
	FILE *fp;

	// generate name
	char name[128];
	sprintf(name, "testname%05i.pgm", id);
	
	// open and write header
	fp = fopen(name, "w");
	fprintf(fp, "P2\n");
	fprintf(fp, "%i %i\n255\n", NROWS, NCOLS);
	
	// output pixels
	for(int i = 0; i < NCOLS; ++i)
	{
		for(int j = 0; j < NROWS; ++j)
		{
			// scale [min, max] -> [0, 255]
			int value = (int)(((plate[idx(i, j, NROWS, NCOLS)]  - min) / max) * 255);

			fprintf(fp, "%i ", value);
		}

		fprintf(fp, "\n");
	}	

	// close file
	fclose(fp);
}

int source;
double temp;
void set_boundary()
{
	printf("enter the location of the heat source (type 1, 2, 3 or 4 for north, south, east or west, respectively: ");
	scanf("%d", &source);

	printf("enter the boundary temp: ");
	scanf("%lf", &temp);
}

void plate_set_boundary(int NROWS, int NCOLS, double* plate) {
	if (source == 1 || source == 2) {
		for (int j = 0; j<NCOLS;j++) {
			if (source == 1) {
				plate[idx(0,j, NROWS, NCOLS)] = temp;
			}
			else if (source == 2) {
				plate[idx((NROWS-1), j, NROWS, NCOLS)] = temp;
			}

		}
	}
	else if (source == 3 || source == 4) {
		for (int i = 0; i<NROWS;i++) {
			if (source == 4) {
				plate[idx(i,0, NROWS, NCOLS)] = temp;
			}
			else if (source == 3) {
				plate[(i,NCOLS-1, NROWS, NCOLS)] = temp;
			}

		}
	}
}

void plate_simulation(int NROWS, int NCOLS, double *plate, double tol) {
	// create temporary plate
	double *plate_tmp = plate_creation(NROWS, NCOLS);
	plate_set_boundary(NROWS, NCOLS, plate_tmp);
	double *old = plate;
	double *new = plate_tmp;

	// simulate
	int count = 0;
	double dtmax = 0.0;
	do {
		dtmax = 0.0;

		// simulation step
		for(int i = 1; i < NROWS-1; i++) {
			for(int j = 1; j < NCOLS-1;j++)
			{
				// physics step
				new[idx(i,j, NROWS, NCOLS)] = (old[idx(i-1,j, NROWS, NCOLS)] + old[idx(i,j-1, NROWS, NCOLS)] + old[idx(i+1,j, NROWS, NCOLS)] + old[idx(i,j+1, NROWS, NCOLS)]) / 4.0;

				// change calculation
				double change = fabs(new[idx(i,j, NROWS, NCOLS)] - old[idx(i,j, NROWS, NCOLS)]);
				if(change > dtmax) {
					dtmax = change;
				}
				/*if ((j % 50) == 0) {
					MPI_Send(plate_tmp, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
				}
				else if ((j% 50 != 0)) {
					MPI_Recv(plate_tmp, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				}*/
				
			}
		}

		// memory pointer swap
		double *tmp = old;
		old = new;
		new = tmp;

		//printf("%lf\n", dtmax);
		//plate_print(NROWS, NCOLS, new);

		plate_output_ppm(count, 0.0, 100.0, NROWS, NCOLS, plate);
		count++;

	} while(dtmax > tol);
	//MPI_Allreduce(old, new, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

	// 
	free(plate_tmp);
}

//double create_random_plate(int NROWS, int NCOLS, int MAX_RANDOM, int MIN_RANDOM) {
//	for (int i =0; i<NROWS;i++) {
//		for(int j=0; j<NCOLS; j++) {
//			rand_plate[idx(i,j, NROWS, NCOLS)] = rand();
//		}
//	}
//}

void plate_set_temp(int NROWS, int NCOLS, double *plate) {
	double plate_temp;
	printf("enter the plate temp: ");
	scanf("%lf", &plate_temp);
	
	for(int row = 0; row < NROWS; row++)

		for(int column = 0; column < NCOLS; column++)
			plate[idx(row, column, NROWS, NCOLS)] = plate_temp;
}

void set_rows_and_cols(int * NROWS, int * NCOLS) {
	printf("please enter values for rows, cols: ");
	scanf("%d %d", NROWS, NCOLS);
}

void set_tolerance(double *tol) {
	printf("enter the tolerance...");
	scanf("%lf", tol);
}

int main() {
	//int rank, size;
	//MPI_Init(NULL, NULL);
	//MPI_Comm_size(MPI_COMM_WORLD, &size);
	//MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int NROWS, NCOLS;
	set_rows_and_cols(&NROWS, &NCOLS);

	double tol;
	set_tolerance(&tol);

	set_boundary();

	double *plate = plate_creation(NROWS, NCOLS);

	plate_set_temp(NROWS, NCOLS, plate);
	plate_set_boundary(NROWS, NCOLS, plate);

	plate_simulation(NROWS, NCOLS, plate, tol);

	//plate_print(NROWS, NCOLS, plate);

	//plate_output_ppm(0, 0.0, 100.0, NROWS, NCOLS, plate);

	//MPI_Finalize();

	return 0;
}

