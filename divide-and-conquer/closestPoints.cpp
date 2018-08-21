// A divide and conquer program to find the smallest \
// distance from given set of points in 2D.

#include <stdio.h>
#include <cmath.h>
#include <stdlib.h>

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
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
				);
}

//BruteForcing algorithm with Order(n*n)
float bruteForce(Point P[], int n){
	float min = FLT_MAX;
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (eucldieanDistance(P[i], P[j]) < min) min = dist(P[i], P[j]);
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
	float dleft = _closestPair(Pleft, mid);
	float dright = _closestPair(Pright, mid)

	
}

// sort initial array by X coord, and then D&C
float closestPair(Point P[], int n){
	qsort(P, n, sizeof(Point), compareX);
	return _closestPair(P, n);
}

int main(){
	Point P[] = {{2,3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P)/sizeof(P[0]);
	cout << closestPair(P, n) << endl;	
}