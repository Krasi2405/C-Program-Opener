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

// ALGORITHM OVERVIEW
// There are 2 sub-arrays.
// One is the ordered the other is unordered
// i is number of elements on the ordered list.
// You get the first item in the unordered list.
// And find a place for it in the ordered list.

int main(void) {
	int an_array[] = {-5, 10, -20, 50, -30};
	int size = sizeof(an_array) / sizeof(int);

	// i is the number of elements on the sorted list.

	for(int i = 1; i < size; i++) {
		int item = an_array[i];
		int position = i;

		print_decorated_contents(an_array, size, position);
		getch();

		while(an_array[position - 1] > item && position > 0) {

			int c = an_array[position - 1];
			an_array[position - 1] = item;
			an_array[position] = c;
			position--;


			print_decorated_contents(an_array, size, position);
			getch();
		}

	}

	return 0;
}