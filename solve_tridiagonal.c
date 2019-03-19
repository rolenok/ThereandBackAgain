void solve_Tridiagonal_Reuseable(float * restrict const x, const size_t X, const float * restrict const a, const float * restrict const b, float * restrict const c) {
	float * restrict const cprime = malloc(sizeof(float) * X);

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

	solve_Tridiagonal_Reusable();

}
