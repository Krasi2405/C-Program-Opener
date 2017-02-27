#include <stdio.h>
void straight_sort(int array[], int size) {
	for(int i = 0; i < size; i++) {
		int position = i;
		int min = array[i];
		for(int j = i + 1; j < size; j++) {
			if(min > array[j]) {
				min = array[j];
				position = j;
			}
		}

		int swap = array[i];
		array[i] = min;
		array[position] = swap;
	}
}


int main() {
	int unsorted[] = {5, 4, 10, 3, 20, 1};
	for(int i = 0; i < 6; i++) {
		printf("%d\n", unsorted[i]);
	}

	straight_sort(unsorted, 6);

	for(int i = 0; i < 6; i++) {
		printf("%d\n", unsorted[i]);
	}

	return 0;
}