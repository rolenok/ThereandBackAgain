# ThereandBackAgain
Implementation of 13 dwarves in C++
# COMPILE AND RUN: (assuming you are using a unix-based machine)
1. Download or clone
2. Open terminal
3. cd to proper repo
4. type 'module load openmpi' and press enter (no output if all goes well)
5. type 'mpicxx heatDistribution.cpp -o *filename*' and press enter. 
6. ./*filename*

[                                                      GOOD LUCK                                                            ]

 +++++++++LEGEND++++++++++
* (ideal) --> code is composed, commented, follows language/MPI standards and executes properly with no known bugs 
* (excellent) --> code is composed, follows language/MPI standards and excecutes properly with no known bugs
* (good) --> code is not quite composed but follows language standards and executes properly with no known bugs
* (fair) --> code is not composed and has a few bugs , but follows language and MPI standards
* (sloppy) --> code does not follow language/MPI standards and/or has major bugs and/or gives incorrect output.
* (needs work) --> code follows no standards and has runtime errors and/or compile-time errors.
* (incomplete) --> no more than a pseudo mock-up.
* (*) --> Currently no known benchmark

# The Thirteen Dwarves: 
1. Dense Linear Algebra --> heatDistribution.cpp (needs work)
2. Sparse Linear Algebra --> Communication.cpp (incomplete -- lowest importance level)
3. Spectral Methods/FFT --> ?
4. N-body Methods, Fast Multipole Methods --> needs renaming --> ?
5. Structured Grids --> ?
6. Unstructured Grids --> ?
7. Monte Carlo --> mc-pi.c (not going to worry about this one)...
8. Combinational Logic --> ?
9. Graph Traversal --> ? (Some kind of search)
10. Graphical Models --> Bayesian Networks, Hidden Markov Models (*)
11. Finite-State Machines --> ? (*)
12. Dynamic Programming --> ? (*)
13. Backtrack and Branch-and-Bound -->  (*)

The originial paper: The Landscape of Parallel Computing Research: A View from Berkeley
--> (Authors) Krste Asanovic, Ras Bodik, Bryan Christopher Catanzaro, Joseph James Gebis, Parry Husbands, Kurt Keutzer, David ---  A. Patterson, William Lester Plishker, John Shalf, Samuel Webb Williams, Katherine A. Yelick
--> https://www2.eecs.berkeley.edu/Pubs/TechRpts/2006/EECS-2006-183.pdf <--

