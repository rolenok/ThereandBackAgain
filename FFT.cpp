/*************************************************************************************************************************
* FFT
* 
* +++++++++LEGEND++++++++++
* (ideal) --> is commented, follows language standards and executes properly with no bugs (having been repeatedly tested)
* (excellent) --> follows language standards and excecutes properly with no known bugs
* (good) --> follows language standards and executes properly with few known bugs
* (fair) -->  compiles, runs and gives the expected output.
* (sloppy) --> has major bugs or gives unexpected output.
* (needs work) --> has runtime errors and/or compile-time errors.
* (incomplete) --> unfinished.
*++++++++++++++++++++++++++
**********************************************************************************************************************/

#include <complex>
#include <iostream>
#include <math.h>
#include <vector>


int fft(int A[int n], int w) {
	A[n] = {(1,2), (3,4)}
	std::complex<int> V[n];
	std::complex<int> Aeven[n/2]
	std::complex<int> Aodd[n - n/2]
	std::complex<int> Veven[n]
	std::complex<int> Vodd[n]

	n = pow(n, 2);
	int Aeven[n] = {0};
	int Aodd[n] = {0};
	int Veven[n] = {0};
	int Vodd[n] = {0};

	cout << ("enter values for n and w, respectively");
	cin >> n >> w;
	for (int k = 0; k <= n; k++) {
		 if (k % 2 == 0) {
		 	Aeven.push_back(k);
		 }
		 else { 
		 	Aodd.push_back(k);
		 }
	}
	Veven[] = {fft(Aeven, n/2, w^2)};
	Vodd[] = {fft(Aodd, n/2, w^2)};

	for(int i = 1; i <= n/2; i++) {
		V[i] = Veven[i] + pow(w, (i-1))*Vodd[i];
		V[n/2 +1] = Veven[i] - pow(w, (i-1))*Vodd[i];
	}
	return V[n];
}
