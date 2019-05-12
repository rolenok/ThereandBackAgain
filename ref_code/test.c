#include <dwarf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int NROWS, NCOLS;
	set_rows_and_columns(&NROWS, &NCOLS);

	int * a = manual_matrix_creation(NROWS, NCOLS);
	//transpose_matrix(NROWS, NCOLS, a);

	print_matrix_transpose(NROWS, NCOLS, a);
}