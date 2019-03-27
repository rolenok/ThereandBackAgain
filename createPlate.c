
#include <stdlib.h>
#include <stdio.h>


double createPlate(int rows, int cols) {
	double **plate;
	plate = malloc(rows*sizeof(double*));

	for (int i=0; i<rows; i++) {
		plate[i] = malloc(cols*sizeof(double));
	}

	return plate[rows][cols];


}

int main() {
	int rows, cols;
	printf("please enter values for rows, cols: ");
	scanf("%d %d", &rows, &cols);
	createPlate(rows, cols);
}