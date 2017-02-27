#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void print_decorated_contents(int array[], int size, int cursor_step) {
    for(int i = 0; i < size; i++) {
        if(cursor_step == i) {
            printf("  V   ");
        }
        else {
            printf("      ");
        }
    }
    printf("\n");

    for(int i = 0; i < size; i++) {
        printf("[%d]  ", array[i]);    
    }
    printf("\n");
}

int main() {
	int unsorted[] = {5, 4, 10, 3, 20};
	int cursor_step = 0;
	int is_sorted;
	for(int i = 0; i < size; i++) {
		is_sorted = 1;
		for(int j = 0; j < size - 1; j++) {
			if(array[j + 1] < array[j]) {
				int c = array[j + 1];
				array[j + 1] = array[j];
				array[j] = c;
				is_sorted = 0;
			}
		}

		if(is_sorted) {
			break;
		}
	}

	return 0;
}