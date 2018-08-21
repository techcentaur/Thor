// A divide and conquer program to find the smallest \
// distance from given set of points in 2D.

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Point{
	int x, y;
};

// Functions for comparsion in quick sort
// ...For X co-ordinate
int compareX(const void* a, const void* b){
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

// ...For Y co-ordinate
int compareY(const void* a, const void* b){
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x- p2->x);
}

// utility function for finding the euclidean distance between 2 points
float eucldieanDistance(Point p1, Point p2){
	float a = sqrt((p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
				);
	return a;
}

//BruteForcing algorithm with Order(n*n)
float bruteForce(Point P[], int n){
	float min = INT8_MAX;
	for (int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if (eucldieanDistance(P[i], P[j]) < min){
				min = eucldieanDistance(P[i], P[j]);
			}
		}
	}
	return min;
}

// closest distance in strip can be found in O(6n) as inner loop /
// runs a max of 6 iterations : Geometric proof with atoms
float closestInStrip(Point strip[], int size, float d){
	float min = d; //initialise the min distance as d
	qsort(strip, size, sizeof(size), compareY);

	for (int i=0; i<size; i++){
		for(int j=i+1; j<size && (strip[j].y - strip[i].y) < min; ++j){
			if (eucldieanDistance(strip[i], strip[j]) < min){
				min = eucldieanDistance(strip[i], strip[j]);
			}
		}
	}
	return min;
}

float _closestPair(Point P[], int n){
	if (n<=3)
		return bruteForce(P, n);

	// get mid point
	int mid = n/2;
	Point midPoint = P[mid];

	// get smallest distance from both partitions
	float dleft = _closestPair(P, mid);
	float dright = _closestPair(P + mid, mid);

	// get smallest of above two distances
	float d = min(dleft, dright);

	// Array for points in strip (closer to mid line)
	Point strip[n];
	int j=0;
	for (int i=0; i<n; i++){
		if(abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;
	}

	// find closest points in strip, return min of (d, closest distance in strip)
	return min(d, closestInStrip(strip, j, d));
}

// sort initial array by X coord, and then D&C
float closestPair(Point P[], int n){
	qsort(P, n, sizeof(Point), compareX);
	return _closestPair(P, n);
}

int main(){
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P)/sizeof(P[0]);
	cout << closestPair(P, n) << endl;	
}