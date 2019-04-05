#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <time.h>
//#include <mpi.h>

// configuration data
int width, height;
int print;
int ppm_frequency;
int random_temp = 0;
double rand_min, rand_max;
double tolerance, temperature;
double north, south, east, west;
char base[128];

int idx(int column, int row, int width, int height)
{
	return row * width + column;
}

double *plate_creation(int width, int height) {
	double *plate = malloc(sizeof(double) * width * height);

	return plate;
}

void plate_print(int width, int height, double *plate) {
	for(int j = 0; j < height; j++) {
		for(int i = 0; i < width; i++)
		{
			printf("%10.0f", plate[idx(i, j, width, height)]);
		}

		printf("\n");
	}
}

void read_config(char *path)
{
	FILE *fp;

	// open config file
	fp = fopen(path, "r");

	ssize_t read;
	char *line = NULL;
	size_t len = 0;
	// parse line by line
	while((read = getline(&line, &len, fp)) != -1)
	{
		char *token = strtok(line, " ");
		
		// skip empty
		if(token == NULL)
			continue;

		// skip comments
		else if(token[0] == '#')
			continue;

		// skip new lines
		else if(token[0] == '\n')
			continue;

		else if(strcmp(token, "width") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%d", &width);
		}
		
		else if(strcmp(token, "height") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%d", &height);
		}

		else if(strcmp(token, "print") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%d", &print);
		}

		else if(strcmp(token, "ppm") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%d", &ppm_frequency);
		}

		else if(strcmp(token, "basename") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%s", base);
		}

		else if(strcmp(token, "threshold") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &tolerance);
		}

		else if(strcmp(token, "temperature") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &temperature);
		}

		else if(strcmp(token, "randomtemp") == 0)
		{
			random_temp = 1;

			token = strtok(NULL, " ");
			sscanf(token, "%lf", &rand_min);

			token = strtok(NULL, " ");
			sscanf(token, "%lf", &rand_max);
		}

		else if(strcmp(token, "north") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &north);
		}

		else if(strcmp(token, "south") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &south);
		}
			
		else if(strcmp(token, "east") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &east);
		}
			
		else if(strcmp(token, "west") == 0)
		{
			token = strtok(NULL, " ");
			sscanf(token, "%lf", &west);
		}
			
		else
		{
			printf("unable to parse line: '%s'\n", line);
		}
	}

	printf("width %i height %i\ntolerance %lf temperature %lf\nnorth %lf south %lf east %lf west %lf\n",
		width, height, tolerance, temperature, north, south, east, west);

	fclose(fp);
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

void plate_output_ppm(int id, char *base, double min, double max, int height, int width, double *plate)
{
	FILE *fp;

	// generate name
	char name[128];
	int offset = sprintf(name, "%s", base);
	sprintf(&name[offset], "%05i.pgm", id);
	
	// open and write header
	fp = fopen(name, "w");
	fprintf(fp, "P2\n");
	fprintf(fp, "%i %i\n255\n", width, height);
	
	// output pixels
	for(int j = 0; j < height; ++j)
	{
		for(int i = 0; i < width; ++i)
		{
			// scale [min, max] -> [0, 255]
			int value = (int)(((plate[idx(i, j, width, height)]  - min) / max) * 255);

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
	//printf("enter the location of the heat source (type 1, 2, 3 or 4 for north, south, east or west, respectively: ");
	//scanf("%d", &source);

	//printf("enter the boundary temp: ");
	//scanf("%lf", &temp);
}

void plate_set_boundary(int width, int height, double* plate) {
	// set west and east boundary
	for(int j = 0; j < height; ++j)
	{
		plate[idx(0, j, width, height)] = west;
		plate[idx((width-1), j, width, height)] = east;
	}

	// set north and east boundary
	for(int j = 0; j < width; ++j)
	{
		plate[idx(j, 0, width, height)] = north;
		plate[idx(j, height-1, width, height)] = south;
	}
		
	//if (source == 1 || source == 2) {
	//	for (int j = 0; j<NCOLS;j++) {
	//		if (source == 1) {
	//			plate[idx(0,j, NROWS, NCOLS)] = temp;
	//		}
	//		else if (source == 2) {
	//			plate[idx((NROWS-1), j, NROWS, NCOLS)] = temp;
	//		}

	//	}
	//}
	//else if (source == 3 || source == 4) {
	//	for (int i = 0; i<NROWS;i++) {
	//		if (source == 4) {
	//			plate[idx(i,0, NROWS, NCOLS)] = temp;
	//		}
	//		else if (source == 3) {
	//			plate[(i,NCOLS-1, NROWS, NCOLS)] = temp;
	//		}

	//	}
	//}
}

int plate_simulation(int NROWS, int NCOLS, double *plate, double tol) {
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

		if(count % ppm_frequency == 0)
		{
			printf("count %i dtmax %lf\n", count, dtmax);
			plate_output_ppm(count, base, 0.0, 100.0, NROWS, NCOLS, plate);
		}

		count++;

	} while(dtmax > tol);
	//MPI_Allreduce(old, new, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

	printf("iterations %i\n", count);

	// 
	free(plate_tmp);

	return count;
}

void plate_set_temp_random(int width, int height, double *plate, double min, double max) {
	for(int j = 0; j < height; ++j)
	{
		for(int i = 0; i < width; ++i)
		{
			plate[idx(i, j, width, height)] = max * ((double)rand() / (double)RAND_MAX) + min;
		}
	}
}

void plate_set_temp(int NROWS, int NCOLS, double *plate) {
	//double plate_temp;
	//printf("enter the plate temp: ");
	//scanf("%lf", &plate_temp);
	
	for(int row = 0; row < NROWS; row++)
		for(int column = 0; column < NCOLS; column++)
			//plate[idx(row, column, NROWS, NCOLS)] = plate_temp;
			plate[idx(row, column, NROWS, NCOLS)] = temperature;
}

void set_rows_and_cols(int * NROWS, int * NCOLS) {
	//printf("please enter values for rows, cols: ");
	//scanf("%d %d", NROWS, NCOLS);

	*NROWS = height;
	*NCOLS = width;
}

void set_tolerance(double *tol) {
	//printf("enter the tolerance...");
	//scanf("%lf", tol);

	*tol = tolerance;
}

int main(int argc, char **argv) {
	//int rank, size;
	//MPI_Init(NULL, NULL);
	//MPI_Comm_size(MPI_COMM_WORLD, &size);
	//MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(argc == 2)
		read_config(argv[1]);
	else
		return 1;

	double *plate = plate_creation(width, height);

	if(random_temp == 1)
		plate_set_temp_random(width, height, plate, rand_min, rand_max);

	else
		plate_set_temp(width, height, plate);

	plate_set_boundary(width, height, plate);

	int count = plate_simulation(width, height, plate, tolerance);
	plate_output_ppm(count, base, 0.0, 100.0, width, height, plate);

	if(print)
		plate_print(width, height, plate);

	//MPI_Finalize();

	return 0;
}

