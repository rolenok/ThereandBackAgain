#include <iostream>
#include <math.h>
#include <complex>
#include <vector>
#include <valarray>
const int MAX = 100;

using namespace std;

vector< vector<int> > vec(n, vector<int>(n));

void popAndPush(int n) {
	for (i = 0; i < n; i++) {
		vec.push_back(rand(), vec);
		i++
	}
}

int main() {
	int n;
	cout<<("enter a value for n, please.");
	cin>>n;

	fillMatrix(n);
	for (int i = 0;i<n;i++) {
		for (int j=0; j<n;j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return 0;
}