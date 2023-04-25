#include <iostream>
using namespace std;

int dimRoute; // dimension of route vector

int CalculateDistance(int distances[], int route[]) { 

	int distance = 0;
	int i = 0, j = 0;

	while (j < route[i]) { // calculates the distances from the starting point to the first port in the route
		distance += distances[j];
		j++;
	}

	i++;

	while (i < dimRoute) { // checks if the next port in the route is behind or in the front of the current port

		if (route[i] > route[i - 1]) { 
			for (j = route[i - 1]; j < route[i]; j++) {
				distance += distances[j];
			}
		}

		else if (route[i] < route[i - 1]) { 
			for (j = route[i]; j < route[i - 1]; j++)
				distance += distances[j];
		}

		i++;
	}

	for (i = 0; i < route[dimRoute - 1]; i++) // calculates the distance from the last port in the route to the starting point
		distance += distances[i];

	return distance;
}

int main()
{
	int distances[] = { 75, 89, 90, 21, 30, 49 };

	int route[] = { 2, 4, 3, 5, 2};

	dimRoute = sizeof(route) / sizeof(int); // calculates the dimension of route vector

	cout << "The distance traveled: " << CalculateDistance(distances, route);

	return 0;
}