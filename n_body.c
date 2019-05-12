#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define e 2.718
#define G_CONSTANT 6.673*pow(e,-11)
#define SOLARMASS 1.9889320*pow(e,30)
#define PI 3.14159265358979323846264338327950288420
#define EPS 3*exp(4)



struct body {

	int x, y; // cartesian coordinates
	int mass; // theoretical value..._these bodies occupy no space_...
	int vx,vy; // velocity components
	int fx, fy; // force components
};


void create_body(int x, int y, int mass, int vx, int vy, int fx, int fy) {

	struct body *ptr, i;
		ptr = &i;
		ptr->x=x;
		ptr->y=y;
		ptr->mass=mass;
		ptr-vx=vx;
		ptr->vy=vy;
		ptr->fx=fx;

		return i;

}

void create_universe(int N) {
	double r  = pow(e, 18);
	struct body * p1 = malloc(sizeof(struct body)*N);

	for (int i = 0; i <= N; i++) {
		p1->x = r*exp(-1.8)*(0.5-rand());
		p1->y = r*exp(-1.8)*(0.5-rand());

		double magv = circle(px, py);
		double angle = tan(abs(py/px));
		double thetav = PI/(2-angle);
		double phiv - rand()*PI;

		p1->vx = signum(py)*cos(thetav)*magv;
		p1->vy = signum(px)*sin(thetav)*magv;



		if (rand() <= 0.5) {

		vx = -vx;
		vy = -vy;
		}

		double mass = rand()*SOLARMASS*exp(20);
		p1[i] = /*"new"*/ struct body p1;
	}
}

void body_to_body_force(struct body * p1, struct body * p2) {

	int d_x = abs((p1->x)-(p2->x));
	int d_y = abs((p1->y)-(p2->y));
	int dist = sqrt(pow(d_x, 2) + pow(d_y, 2));


	double F = G_CONSTANT*p1->mass*p2->mass/(dist*dist + EPS*EPS);

	p1->fx += (F*d_x)/dist;
	p1->fy += (F*d_y)/dist;
}

void print_values(struct body * p1) {

	printf("%d", p1->fx);
	printf("%d", p1->fy);

}

struct body * update_movement_of_body(int dt, struct body * p1) {

	p1->vx += (dt*p1->fx)/(p1->mass);
	p1->vy += (dt*p1->fy)/(p1->mass);

}

struct body * reset_force(struct body * p1) {

	p1->fx = 0;
	p1->fy = 0;
}

signed double signum(double x) {

	return -x;
}
double circle(double x, double y) {
	double r = pow(e,18);
	double r2 = sqrt((x*x)+(y*y));
	double num = (6.67*exp(-11)*exp(6)*SOLARMASS);

	return sqrt(num/r2);

}


void addforces(int N) {

	for (int i = 0; i < N, i++) {

		reset_force(p1[i]);

		for (int j = 0; j < N; j++) {

			if (i!=j) p1[i]->body_to_body_force(p1);	

		}

	}

	for (int k = 0; k < N; k++) {

		p1[i]->update_movement_of_body(exp(11));

	}

}


int main() {
	int N = rand();
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

	body_to_body_force(&p1, &p2);

	print_values(&p1, &p2);




}








