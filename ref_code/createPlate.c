<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

void solve_Tridiagonal_Reuseable(double * x, const size_t X, double * a, double * b, double * c) {
	float * cprime = malloc(sizeof(float) * X);
=======
void solve_Tridiagonal_Reuseable(float * restrict const x, const size_t X, const float * restrict const a, const float * restrict const b, float * restrict const c) {
	float * restrict const cprime = malloc(sizeof(float) * X);
>>>>>>> 7efab54f61d1feaa739ed423c6eba263d8c5aca6

	if (!cprime) {

	}
	c[0] = c[0] / b[0];
    x[0] = x[0] / b[0];
    
    for (size_t ix = 1; ix < X; ix++) {
        const float m = 1.0f / (b[ix] - a[ix] * c[ix - 1]);
        c[ix] = c[ix] * m;
        x[ix] = (x[ix] - a[ix] * x[ix - 1]) * m;
    }
    
    for (size_t ix = X - 2; ; ix--)
        x[ix] -= c[ix] * x[ix + 1];

    free(cprime);
}

int main() {
/* variable declaration */
<<<<<<< HEAD
	double x =  1.0;
	const size_t X = 5;
	double a = 6.0;
	double b = 3.0;
	double c = 4.0;
	solve_Tridiagonal_Reuseable(x, X, a, b, c);
	return 0;
}
=======

	solve_Tridiagonal_Reusable();

}
>>>>>>> 7efab54f61d1feaa739ed423c6eba263d8c5aca6
