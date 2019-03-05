#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int NUMBER_ROWS = 10;
const int NUMBER_COLUMNS = 10;

int main(int argc, char*argv[]) {
    int r, c;
    bool done = false;
    double grid[NUMBER_ROWS][NUMBER_COLUMNS]; 
    
    double temp_north;
    double temp_south;
    double temp_east;
    double temp_west;
    double tolerance;
    double check_value;
    double update_temp;
    double maxUpdate = 0;
    
    cout << "enter the four sides' intital temperature (North, South, East, West)\n";
    cin >> temp_north >> temp_south >> temp_east >> temp_west;
    
    cout << "enter the tolerance\n";
    cin >> tolerance;
    
    tolerance = fabs(tolerance);
    
    for(r = 1; r < NUMBER_ROWS-1;r++) {
        for(c = 1; c < NUMBER_COLUMNS; c++) {
            grid[r][c] = 0.0;
        }
        grid[r][0] = temp_west;
        grid[r][NUMBER_COLUMNS] = temp_east;
    }

    for(c=0; c<NUMBER_COLUMNS-1; c++) {
    	grid[0][c] = temp_north;
    	grid[NUMBER_ROWS-1][c] = temp_south;
    }
    
    while(!done) {
    	for(r = 1; r<NUMBER_ROWS-1;r++) {
    		for(c = 0; c<NUMBER_COLUMNS;c++) {
    			update_temp = (grid[r+1][c] + grid[r-1][c] + grid[r][c-1] + grid[r][c+1])/4;
    			check_value = update_temp - grid[r][c];
    			if(check_value > maxUpdate) {
    				maxUpdate = check_value;
    				grid[r][c] = update_temp;
    			}
    		}
    		
    	}
    	done = (maxUpdate < tolerance);
    }
    printf("Equilibrium values across the grid: ");
    for (r=1;r<NUMBER_ROWS-1;r++) {
    	for(c=1;c<NUMBER_COLUMNS;c++) {
    		cout << fixed << setprecision(5) << setw(10) << grid[r][c];
    		cout << endl;
    	}
    }

    return 0;
}

