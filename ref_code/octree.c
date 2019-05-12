#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define e 2.78
#define G_CONSTANT 6.673*pow(e,-11)
#define solarmass 1.9889320*pow(e,30)



struct point {

	int x, y; // cartesian coordinates
	int mass; // theoretical value... these points occupy no space...
	int vx,vy; // velocity components
	int fx, fy; // force components
};

struct point * update_movement_of_point(int dt, struct point * p1) {

	p1->vx += (dt*p1->fx)/(p1->mass);
	p1->vy += (dt*p1->fy)/(p1->mass);

}

struct point * reset_force(struct point * p1) {

	p1->fx = 0;
	p1->fy = 0;
}

void point_to_point_force(struct point * p1) {
	
	struct point *pointPtr, p2;
	pointPtr = &p2;
	pointPtr->x = 10;
	pointPtr->y = 10;
	pointPtr->mass = 100;
	double EPS = 3*(e, 4);

	int d_x = abs((p2->x)-(p2->x));
	int d_y = abs((p2->y)-(p2->y));
	int dist = sqrt(pow(d_x, 2) + pow(d_y, 2));


	double F = G_CONSTANT*p1->mass*p2->mass/(dist*dist + EPS*EPS);

	p1->fx += (F*d_x)/dist;
	p1->fy += (F*d_y)/dist;
}

void print_values(struct point * p1) {

	point_to_point_force(p1);

	printf("%d", p1->fx);
	printf("%d", p1->fy);


}

//void create_universe(int N, struct point * p1) {

	//for (int i = 0; i <= N; i++) {
		//point_creation(p1);
		//i++;
	//}


//}

int main() {

	struct point *pointPtr, p1;

	pointPtr = &p1;
	pointPtr->x = 0;
	pointPtr->y = 0;
	pointPtr->mass = 100;

	point_to_point_force(&p1);

	print_values(&p1);

}








