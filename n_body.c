#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define G_CONSTANT 6.673*exp(-11)
#define SOLARMASS 1.9889320*exp(30)
#define PI 3.14159265358979323846264338327950288420
#define EPS 3*exp(4)

#define RANDOM_MIN_NATURAL 15
#define RANDOM_MAX_NATURAL 1000000

#define RANDOM_MIN -1000
#define RANDOM_MAX 1000



struct body {

	int x, y; // cartesian coordinates
	int mass; // theoretical value..._these bodies occupy no space_...
	int vx,vy; // velocity components
	int fx, fy; // force components
};

struct body create_body(int x, int y, int mass, int vx, int vy, int fx, int fy) {

	struct body i;
	struct body *ptr; // storage size of i isn't known -- compile time error
		ptr = &i;
		ptr->x=x;
		ptr->y=y;
		ptr->mass=mass;
		ptr->vx=vx;
		ptr->vy=vy;
		ptr->fx=fx;
	return i;
}

int rand_bounded_natural_numbers() {

	int n = rand();

	if (n < RANDOM_MIN_NATURAL) {

		n = RANDOM_MIN_NATURAL;
	}

	else if (n > RANDOM_MAX_NATURAL) {
		
		n = RANDOM_MAX_NATURAL;
	}

	return n; 
}

int rand_bounded_integers() {

	int n = rand();

	if (n < RANDOM_MIN) {

		n = RANDOM_MIN;
	}

	else if (n > RANDOM_MAX) {

		n = RANDOM_MAX;
	}

	return n;
}

double circlev(double x, double y) {

	double r = exp(18);
	double r2 = sqrt((x*x)+(y*y));
	double num = (6.67*exp(-11)*exp(6)*SOLARMASS);

	return sqrt(num/r2);
}

signed signum(double x) {

	return -x;
}


void body_to_body_force(struct body * body1, struct body * body2) { // all wrong

	int d_x = abs((body1->x)-(body2->x));
	int d_y = abs((body1->y)-(body2->y));
	int dist = sqrt(pow(d_x, 2) + pow(d_y, 2));


	double F = G_CONSTANT*body1->mass*body2->mass/(dist*dist + EPS*EPS);

	body1->fx += (F*d_x)/dist;
	body1->fy += (F*d_y)/dist;
}

struct body * update(int dt, struct body ** bodies, int i) {

	bodies[i]->vx += (dt*bodies[i]->fx)/(bodies[i]->mass);
	bodies[i]->vy += (dt*bodies[i]->fy)/(bodies[i]->mass);
}

struct body * reset_force(int i, struct body ** bodies) {

	bodies[i]->fx = 0;
	bodies[i]->fy = 0;
}

void addforces(int N, struct body ** bodies) {

	for (int i = 0; i < N; i++) {

		reset_force(i,bodies[i]);

		for (int j = 0; j < N; j++) {

			if (i!=j) bodies[i]->body_to_body_force(bodies[j]);	
		}
	}

	for (int k = 0; k < N; k++) {

		bodies[k]->update(exp(11));
	}
}


void create_universe(int N, struct body ** bodies) {

	double r  = exp(18);


	for (int i = 1; i <= N; i++) {
		double x = r*exp(-1.8)*(0.5-rand_bounded_integers(NULL));
		double y = r*exp(-1.8)*(0.5-rand_bounded_integers(NULL));

		double magv = circlev(x, y);
		double angle = tan(abs(y/x));
		double thetav = PI/(2-angle);
		double phiv = rand_bounded_natural_numbers()*PI;

		double vx = signum(y)*cos(thetav)*magv;
		double vy = signum(x)*sin(thetav)*magv;

		if (rand() <= 0.5) {

			vx = -vx;
			vy = -vy;
		}

		double mass = rand()*SOLARMASS*exp(20);
		bodies[i] = create_body(rand_bounded_integers(NULL), rand_bounded_integers(NULL), rand_bounded_natural_numbers(NULL),0,0,0,0);
	}

	bodies[0] = create_body(0,0,exp(6)*SOLARMASS, 0,0,0,0);
}


void print_values(struct body ** bodies) {

	printf("%d", bodies->fx);
	printf("%d", bodies->fy);
}

int main() {

	int N = rand_bounded_integers(NULL);
	struct body * bodies = malloc(sizeof(struct body*)*N);
	create_universe(N);




	/*
	struct body*bodyPtr, p1;

	bodyPtr = &p1;
	bodyPtr->x = 0;
	bodyPtr->y = 0;
	bodyPtr->mass = 100;

	struct body*bodyPtr1, p2;

		bodyPtr1 = &p2;
		bodyPtr1->x = 5;
		bodyPtr1->y = 3;
		bodyPtr1->mass = 1000;

	*/

	//print_values(&p2);
}








