/*

<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Node Structure (Distance , Petrol)
Assume - 1. Always move from left to right.
		 2. 1 unit petrol leads to 1 unit distance.

  0     1     2     3
(4,6) (6,5) (7,3) (4,5)
Starting from index=0 dist bw 0city to 1city is 4 and petrol is 6 so we remain with +2 unit
now from 1 to 2 city dist is 6 and petrol is 5+2 so we left with +1 unit. Now from 2 to 3
dist is 7 and petrol is 3+1 so to reach 3 we require 4more unit of petrol .Hence Index 0
cannot perform Circular Tour.
Now start from index 1 and repeat same process and so on. Ans is index=3 which wiil comp
the circular tour. TC:O(n^2)

Goal : return the minm possible index to complete the circular tour else return -1.

2. Better method in O(n)
Queue

*/
#include<bits/stdc++.h>
using namespace std;

// A petrol pump has petrol and distance to next petrol pump
class petrolPump
{
public:
	int distance;
	int petrol;

};

// The function returns starting point if there is a possible solution,
// otherwise returns -1
int printTour(petrolPump arr[], int n)
{
	// Consider first petrol pump as a starting point
	int start = 0;
	int end = 1;

	int curr_petrol = arr[start].petrol - arr[start].distance;

	/* Run a loop while all petrol pumps are not visited.
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0) // run till end==start and curr >0
	{
		// If curremt amount of petrol in truck becomes less than 0, then
		// remove the starting petrol pump from tour
		while (end != start and curr_petrol < 0)
		{
			// Remove starting petrol pump. Change start
			curr_petrol -= arr[start].petrol - arr[start].distance;
			start = (start + 1) % n;

			// If 0 is being considered as start again, then there is no
			// possible solution
			if (start == 0)
				return -1;
		}
		// Add a petrol pump to current tour
		curr_petrol += arr[end].petrol - arr[end].distance;

		end = (end + 1) % n;
	}

	// Return starting point
	return start;
}

int main()
{
	petrolPump arr[] = {{5, 6}, {6, 7}, {7, 4}, {8, 10}, {6, 6}, {4, 5}};

	int n = sizeof(arr) / sizeof(arr[0]);
	int start = printTour(arr, n);

	(start == -1) ? cout << "No solution" : cout << "Start = " << start;

	return 0;
}