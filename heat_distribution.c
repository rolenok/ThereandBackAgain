#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#include <time.h>
//#include <mpi.h>

#include <time.h>
#include <mpi.h>



int idx(int row, int column, int rows, int columns)
{
	return row * columns + column;
}

double* plate_creation(int NROWS, int NCOLS) {
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

				plate[idx(i,NCOLS-1, NROWS, NCOLS)] = temp;

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
	double dtmax = 0.0;



	// simulate
	double dtmax = 0.0;
	double global_dtmax = 0.0;

	do {
		dtmax = 0.0;

		// simulation step

		for(int i = 1; i < NROWS-1; i++) {
			for(int j = 1; j < NCOLS-1;j++)
			{
				// physics step
				new[idx(i,j, NROWS, NCOLS)] = (old[idx(i-1,j, NROWS, NCOLS)] + old[idx(i,j-1, NROWS, NCOLS)] + old[idx(i+1,j, NROWS, NCOLS)] + old[idx(i,j+1, NROWS, NCOLS)]) / 4.0;


		for(int i = 1; i < NROWS-2; i++) {
			for(int j = 1; j < NCOLS-1;j++)
			{
				// physics step
				new[idx(i, j, NROWS, NCOLS)] = (old[idx(i-1,j, NROWS, NCOLS)] + old[idx(i,j-1, NROWS, NCOLS)] + old[idx(i+1,j, NROWS, NCOLS)] + old[idx(i,j+1, NROWS, NCOLS)]) / 4.0;

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

					dtmax = global_dtmax;
				}
			//	if (j % 10 == 0) {
			//	MPI_Send(&new[idx(i,j, NROWS-2, NCOLS)], NCOLS, MPI_DOUBLE, my_top_cart_rank, 0, MPI_COMM_WORLD);
			//	MPI_Recv(&new[idx(i,j, NROWS-2, NCOLS)], NCOLS, MPI_DOUBLE, my_top_cart_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			//	MPI_Send(&new[idx(i,j, NROWS, NCOLS -2)], NROWS, MPI_DOUBLE, my_bottom_cart_rank, 0, MPI_COMM_WORLD);
			//	MPI_Recv(&new[idx(i,j, NROWS, NCOLS -2)], NROWS, MPI_DOUBLE, my_bottom_cart_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);


			//	}


			}
		}

		// memory pointer swap
		double *tmp = old;
		old = new;
		new = tmp;

		//printf("%lf\n", dtmax);
		//plate_print(NROWS, NCOLS, new);

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

// *NROWS
int main(int argc, char **argv) {
	int size;
	int ndims = 1;
	int my_rank;
	MPI_Comm comm = MPI_COMM_WORLD;
	MPI_Comm Comm1D;
	int dims[ndims], coord[ndims];
	int periodic[ndims];
	int reorder;
	int ierr;
	int nrows;
	int ncols;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_size(comm, &size);
	MPI_Comm_rank(comm, &my_rank);

	printf("rank %i is alive\n", my_rank);

	//if (argc == 3) {
		//nrows = atoi (argv[1]);
		//ncols = atoi (argv[2]);
		/* number of rows */
		/* number of columns */
		//if( (nrows*NCOLS) != size) {
			//if( my_rank ==0) printf("ERROR: nrows*NCOLS)=%d * %d = %d != size\n", NROWS, NCOLS, NROWS*NCOLS,size);
			//MPI_Finalize(); exit(0);
		//}
	//} else {
	//}
	// intialize Dimensions
	//MPI_Dims_create(size, ndims, dims);
	//if(my_rank==0)
		//printf("PW[%d], CommSz[%d%]: PEdims = [%d x %d] \n",my_rank,size,dims[0],dims[1]);

	// create cartesian mapping 
	periodic[0] = 1; // periodic shift is false 
	reorder = 0;

	dims[0] = size;

	ierr = MPI_Cart_create(MPI_COMM_WORLD, ndims, dims,
	periodic, reorder, &Comm1D);
	if(ierr != MPI_SUCCESS) printf("ERROR[%d] creating CART\n",ierr);

	//find my coordinates in the cartesian communicator group 
	MPI_Cart_coords(Comm1D, my_rank, ndims, coord);
	//use my cartesian coordinates to find my rank in cartesian group

	printf("rank %i coord %i\n", my_rank, coord[0]);

	int my_top_cart_rank;
	int my_bottom_cart_rank;

	int coord_top[1];
	int coord_bottom[1];

	//coord_top[0] = ((coord[0] + 1) + size) ;
	//coord_bottom[0] = ((coord[0] - 1) + size) % size;

	coord_top[0] = coord[0] + 1;
	coord_bottom[0] = coord[0] - 1;

	printf("rank %i top %i bottom %i\n", my_rank, coord_top[0], coord_bottom[0]);

	MPI_Cart_rank(Comm1D, coord_bottom, &my_bottom_cart_rank);
	MPI_Cart_rank(Comm1D, coord_top, &my_top_cart_rank);

	MPI_Comm_free(&Comm1D);

	int NROWS, NCOLS;
	set_rows_and_cols(&NROWS, &NCOLS);

	double tol;
	set_tolerance(&tol);

	set_boundary();

	double *plate = plate_creation(NROWS, NCOLS);

	plate_set_temp(NROWS, NCOLS, plate);
	plate_set_boundary(NROWS, NCOLS, plate);

	plate_simulation(NROWS, NCOLS, plate, tol);

	plate_print(NROWS, NCOLS, plate);


	//MPI_Finalize();

	return 0;
}


	MPI_Finalize();

	return 0;
}

