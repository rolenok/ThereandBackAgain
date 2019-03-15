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


<<<<<<< HEAD
double fft(std::complex<double> A[], int w, int n) {
	A[n] = {(1,2), (3,4)};
	std::complex<double> V[n];
	std::complex<double> Aeven[n/2];
	std::complex<double> Aodd[n - n/2];
	std::complex<double> Veven[n];
	std::complex<double> Vodd[n];
=======
int fft(int A[int n], int w) {
	A[n] = {(1,2), (3,4)}
	std::complex<int> V[n];
	std::complex<int> Aeven[n/2]
	std::complex<int> Aodd[n - n/2]
	std::complex<int> Veven[n]
	std::complex<int> Vodd[n]
>>>>>>> ddf7920e246c8792db47c2ba2a9062e4d57c796a

	n = pow(n, 2);

	std::cout<< ("enter values for n and w, respectively");
	std::cin>> n >> w;
	for (double k = 0.0; k <= n; k++) {
		 if ((int)k % 2 == 0) {
		 	Aeven.push_back(k);
		 }
		 else { 
		 	Aodd.push_back(k);
		 }
	}
	Veven = {fft(Aeven, n/2, w^2)}; // recursion and Divide/conquer
	Vodd = {fft(Aodd, n/2, w^2)}; // recursion and Divide/conquer

	for(int i = 1; i <= n/2; i++) {
		V[i] = Veven[i] + pow(w, (i-1))*Vodd[i];
		V[n/2 +1] = Veven[i] - pow(w, (i-1))*Vodd[i];

		return V[i];
	}
	
}
