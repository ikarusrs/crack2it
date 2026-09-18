#include<stdio.h>

void bubble_sort(int arr[], int n) {
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] >= arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		
		while (j>=0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}

int main() {
	int n = 8;

	int arr[8] = {1, 4, 2, 7, 3, 2, 9, 6};
	int arr2[8];
	//bubble_sort(arr, n);
	//insertion_sort(arr, n);
	selection_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf(" %d, ", arr[i]);
	}
}
