#include <iostream>
#include <math.h>
#include <complex>
#include <vector>
#include <bits/stdc++.h>
const int MAX = 100;
int mat[MAX][MAX];
using namespace std;

void fillRemaining(int i, int j, int n) 
{ 

    int x = 2; 

    for (int k = i + 1; k < n; k++) 
        mat[k][j] = x++; 

    for (int k = 0; k < i; k++) 
        mat[k][j] = x++; 
} 
void fillMatrix(int n) {
	int right = n-1;
	int left = 0;
	for (int i = 0; i < n ; i++) {
		if (i % 2 ==0) {
			mat[i][right] = 1;
			fillRemaining(i, right, n);
			right--;
		}

		else {
			mat[i][left] = 1;
			fillRemaining(i, left, n);
			i++;
		}

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