#include<stdio.h>

void average_marks(int array[], int array_length) {
	float sum = 0.0f;
	float result;

	for (int i = 0; i < array_length; i++) {
		if (array[i] != -1) {
			sum += array[i];
		}
	}

	result = sum / array_length;

	printf("\nAverage score of the class is: %.2f \n", result);
}

void minmax(int array[], int array_length) {
	int min, max;
	min = 101;
	max = -1;
	
	for (int i = 0; i < array_length; i++){
		if (array[i] > max) {max = array[i];}
		if (array[i] < min) {min = array[i];}
	}
	
	printf("\nHighest Score of the class is: %d \n", max);
	printf("Lowest Score of the class is: %d \n", min);
}

void absentcount(int array[], int array_length) {
	int count = 0;

	for (int i = 0; i < array_length; i++){
		if (array[i] == -1) {count++;}
	}

	printf("\nNumber of Absent Students: %d \n", count);
}

void maxfreq(int array[], int array_length) {
	int frequency[101] = {0};
	int maxf = 0;
	int position = 0;

	for (int i = 0; i < array_length; i++) {
		if (array[i] != -1) {
			frequency[array[i]]++;
		}
	}
	
	for (int i = 0; i < 101; i++) {
		if (frequency[i] > maxf) {
			maxf = frequency[i];
			position = i;
		};
		
	}
	
	printf("\nScore with maximum frequency is %d. (%d times!) \n", position, maxf);

}

int main() {
	int N;
	int choice;

	printf("Enter the Number of Students: ");
	scanf("%d", &N);

	int marks[N];

	printf("\nEnter the Marks of Students (-1 for absent students): ");
	for (int i = 0; i < N; i++){
		printf("\nStudent %d: ", i+1);
		scanf("%d", &marks[i]);
	}
	
	do {
		printf("Enter a choice: \nAverage - 1\nMinimum and Maximum - 2\nAbsent Count - 3\nMaximum Frequency - 4\nExit - 5\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				average_marks(marks, N);
				break;
			case 2:
				minmax(marks, N);
				break;
			case 3:
				absentcount(marks, N);
				break;
			case 4:
				maxfreq(marks, N);
				break;
			default: 
				break;
		}
	} while (choice < 5);
}

