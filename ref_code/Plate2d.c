#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// a structure of the plate sort
typedef struct {
	int n
}p;

//Memory Allocation and initialisation of structure
struct Plate2d *createPlate(struct Plate2d **p, int NROWS, int NCOLS) {
	p = malloc(NROWS*sizeof(double));
	p->NROWS = NROWS;
	p->NCOLS = NCOLS;
	p->plateSize = (sizeof(plate1) + sizeof(**p) *p->platesize);
	p->plate[0][0] = plate[NROWS][NCOLS];
	return **p;
}

//
void printPlate(struct Plate2d *p)
	{
		printf("NROWS : %d\n",
			   "NCOLS : %d\n",
			   "plateSize : %d\n",
			   &p->NROWS, &p->NCOLS, &p->plateSize);

	}
/*double JacobJacobi(struct Output *plate1[NROWS][NCOLS], double * plate2[NROWS][NCOLS], double dtmax) {
	dtmax = 0;
	for(int i = 0; i < NROWS; i++)
	for(int j = 0; j < NCOLS;j++)
	{
		plate2[i][j] = (plate1[i-1][j] + plate1[i][j-1] + plate1[i+1][j] + plate1[i][j+1])/4; //physics
		if (fabs(plate2[i][j] - plate1[i][j]) > dtmax)
		dtmax =fabs(plate2[i][j] - plate1[i][j]);
	}
	return plate1[i][j]
}
*/
int main() {
	int NROWS, NCOLS;
	struct Plate2d *p1, *p2;
	printf("enter values for NROWS, NCOLS: ");
	scanf("%d %d", &NROWS, &NCOLS);
	p1 = createPlate(p1, NROWS, NCOLS);
	p2 = createPlate(p2, NROWS, NCOLS);
}