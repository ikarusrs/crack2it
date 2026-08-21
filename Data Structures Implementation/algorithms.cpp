#include<iostream>
using namespace std;

// Globals
int isPresent = 0;

// Linear Search
// Consider an integer type array A of size n
// Key variable is declared
// If key is found, display the location of element (index + 1)
// Time Complexity = O(n)

void linear_search(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (key == arr[i]) {
			cout << "Value found at position " << i+1 << endl;
			isPresent = 1;
			break;
		}
	}
	if (!isPresent) {
		cout << "Value not found!" << endl;
	}
}


// Binary Search
// Only works on sorted data
// Middle element is average of lower and higher bound rounded down
// Mid = (higher + lower) / 2
// If current element is less than key, increment lower
// If current element is greater than key, decrement higher
// Worst Case time complexity is O(logn); Binary search is tree traversal and the tree has logn levels
void binary_search(int arr[], int size, int key) {
	int higher, lower, mid;
	lower = 0;
	higher = size - 1;

	while (higher >= lower) {
		mid = (higher + lower) / 2; // C++ integer division truncation is basically rounding down for positive numbers
		
		if (arr[mid] == key) {
			cout << "Value found at position " << mid+1 << endl;
			isPresent = 1;
			break;
		} else if (arr[mid] < key) {
			lower = mid + 1;
		} else {
			higher = mid - 1;
		}
	}

	if (!isPresent) {
		cout << "Value not found!";
	}
}

// Fibonacci Search
// only works on sorted data
// Uses divide and conquer
// First find the smallest fibo number greater than or equal to length of array (Fm)
void fibonacci_search(int arr[], int size, int key) {
	int a=0, b = 0, Fm = 1;
	int offset = -1;
	while (Fm < size) {
		a = b;
		int next = b + Fm;
		b = Fm;
		Fm = next;
	}
	while (Fm > 1) {
		int i;
		if (offset + a < size - 1) {
			i = offset + a;
		} else {
			i = size - 1;
		}

		if (arr[i] < key) {
			Fm = b;
			b = a;
			a = Fm - b;
			offset = i;
		} else 
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	linear_search(arr, 5, 5);
	binary_search(arr, 5, 5);
	fibonacci_search(arr, 5, 5);
}


