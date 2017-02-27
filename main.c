#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <conio.h>
#include <time.h>

void clear() {
    system("cls");
}

void copy(int copy_from[], int copy_to[], int size) {
    for(int i = 0; i < size; i++) {
        copy_to[i] = copy_from[i];
    }
}

int files_in_dir(char dir_name[]) {
    DIR *d;
    struct dirent *dir;
    int num_files = 0;
    char command[50];

    sprintf(command, "./%s", dir_name);

    d = opendir(command);
    while((dir = readdir(d)) != NULL) {
        if(dir->d_type == DT_REG) {
            num_files++;
        }
    }
    closedir(d);

    return num_files;
}

void modified_bubble_sort(int array[], int size) {
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
}

void bubble_sort(int array[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(array[j + 1] < array[j]) {
                int c = array[j + 1];
                array[j + 1] = array[j];
                array[j] = c;
            }
        }
    }

}

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

void insertion_sort(int array[], int size) {
    for(int i = 1; i < size; i++) {
        int item = array[i];
        int position = i;
        while(array[position - 1] > item && position > 0) {
            int c = array[position - 1];
            array[position - 1] = item;
            array[position] = c;
            position--;
        }

    }
}

void print_decorated_contents(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("[%d]  ", array[i]);    
    }
    printf("\n");
}

void print_decorated_contents_cursor(int array[], int size, int cursor_step) {
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

double test_time(void (*f)(int[], int), int array[], int size) {
    clock_t start, end;
    start = clock();
    (*f)(array, size);
    end = clock();

    return ((double) (end - start)) / CLOCKS_PER_SEC;
}


int main()
{
    while(1) {
        DIR *d;
        struct dirent *dir;

        int counter;
        int current = 0;
        int max = 0;

        char file_name[30];
        char command[50];
        int controls;
        clock_t start, end;
        double cpu_time_used;


        clear();
        printf("Press '1' to open program runner.\nPress '2' to open program reader.\n");
        printf("Press '3' to open algorithm time recorder.\nPress '4' to open algorithm step by step viewer\n");
        controls = getch();

        // PROGRAM OPENER MODE
        if(controls == '1') 
        {
            while(1) {
                clear();
                max = files_in_dir("scripts");
                while(1) {
                    counter = 0;
                    
                    
                    d = opendir("./scripts");
                    printf("Available programs: \n");
                            
                    while((dir = readdir(d)) != NULL) {
                                
                        if (dir->d_type == DT_REG) {
                            printf("%s", dir->d_name);
                            if(counter == current) {
                                printf(" - Current.");
                                sprintf(file_name, "%s", dir->d_name);
                            }
                            printf("\n");
                            counter++;
                            
                        }
                    }
                    closedir(d);
                    controls = getch();
                    clear();
                    
                    if(controls == 13) {
                        break;
                    }
                    if(controls == 'w' || controls == 'W') {
                        current--;
                    }
                    else if(controls == 's' || controls == 'S') {
                        current++;
                    }

                    if(current < 0) {
                        current = 0;
                    }
                    else if(current >= max) {
                        current = max - 1;
                    }
                }

                sprintf(command, "scripts\\%s", file_name);
                system(command);

                printf("\nPress anything to run the algorithm time recorder again.\n");
                printf("Press Escape to exit the program.\nPress Enter to go back to main menu.\n");
                controls = getch();
                if(controls == 27) {
                    return 0;
                }
                else if(controls == 13) {
                    break;
                }
            }
        }
        // PROGRAM READER MODE
        else if(controls == '2') 
        {
            while(1) {
                clear();
                max = files_in_dir("txt_scripts");

                while(1) {
                    d = opendir("./txt_scripts");
                    printf("Available programs: \n");
                            
                    while((dir = readdir(d)) != NULL) {
                                
                        if (dir->d_type == DT_REG) {
                            printf("%s", dir->d_name);
                            if(counter == current) {
                                printf(" - Current.");
                                sprintf(file_name, "%s", dir->d_name);
                            }
                            printf("\n");
                            counter++;
                        }
                    }
                    closedir(d);

                    controls = getch();
                    clear();
                    
                    if(controls == 13) {
                        break;
                    }
                    if(controls == 'w' || controls == 'W') {
                        counter--;
                    }
                    else if(controls == 's' || controls == 'S') {
                        counter++;
                    }

                    if(counter < 0) {
                        counter = 0;
                    }
                    else if(counter >= max) {
                        counter = max - 1;
                    }
                }

                sprintf(command, "type txt_scripts\\%s", file_name);
                system(command);

                printf("\nPress anything to run the algorithm time recorder again.\n");
                printf("Press Escape to exit the program.\nPress Enter to go back to main menu.\n");
                controls = getch();
                if(controls == 27) {
                    return 0;
                }
                else if(controls == 13) {
                    break;
                }
            }
        }
        // Algorithm Time Recorder
        else if(controls == '3') {
            while(1) {
                double time_taken;
                double overall_time = 0;
                // Initialize arrays.
                int size = 10000;
                int sorted_array[size];
                int random_array1[size];
                int unsorted_array[size];


                // Initialize sorted array.
                for(int i = 0; i < sizeof(sorted_array) / sizeof(int); i++) {
                    sorted_array[i] = i;
                }
                // Initialize random arrays.
                for(int i = 0; i < sizeof(random_array1) / sizeof(int); i++) {
                    random_array1[i] = rand() % 10000;
                }
                // Initialize unsorted array.
                for(int i = (sizeof(unsorted_array) / sizeof(int)) - 1; i >= 0; i--) {
                    unsorted_array[i] = size - 1 - i;
                }

                clear();

                // #################################################
                //               STRAIGHT SELECT
                // #################################################
                printf("Currently testing straight select sort.\n");
                void (*straight_sort_ptr)(int[], int);
                straight_sort_ptr = &straight_sort;

                int test_straight_select[size];
                copy(sorted_array, test_straight_select, size);
                time_taken = test_time(straight_sort_ptr, test_straight_select, size);
                overall_time += time_taken;
                printf("Seconds taken for already sorted array: %lf\n", time_taken);

                int test_straight_random1[size];
                copy(random_array1, test_straight_random1, size);
                time_taken = test_time(straight_sort_ptr, test_straight_random1, size);
                overall_time += time_taken;
                printf("Seconds taken for random array: %lf\n", time_taken);

                int test_unsorted_straight_select[size];
                copy(unsorted_array, test_unsorted_straight_select, size);
                time_taken = test_time(straight_sort_ptr, test_unsorted_straight_select, size);
                overall_time += time_taken;
                printf("Seconds taken for worst case unsorted array: %lf\n", time_taken);
                printf("Overall time taken: %lf\n", overall_time);

                

                // #################################################
                //               BUBBLE SORT
                // #################################################
                overall_time = 0;
                printf("\nCurrently testing bubble sort.\n");

                void (*bubble_ptr)(int[], int);
                bubble_ptr = &bubble_sort;

                int test_sorted_bubble[size];
                copy(sorted_array, test_sorted_bubble, size);
                time_taken = test_time(bubble_ptr, test_sorted_bubble, size);
                overall_time += time_taken;
                printf("Seconds taken for already sorted array: %lf\n", time_taken);

                int test_bubble_random1[size];
                copy(sorted_array, test_bubble_random1, size);
                time_taken = test_time(bubble_ptr, test_bubble_random1, size);
                overall_time += time_taken;
                printf("Seconds taken for random array: %lf\n", time_taken);

                int test_unsorted_bubble[size];
                copy(sorted_array, test_unsorted_bubble, size);
                time_taken = test_time(bubble_ptr, test_unsorted_bubble, size);
                overall_time += time_taken;
                printf("Seconds taken for worst case unsorted array: %lf\n", time_taken);

                printf("Overall time taken: %lf\n", overall_time);



                // #################################################
                //               MODIFIED BUBBLE SORT
                // #################################################
                overall_time = 0;
                printf("\nCurrently testing modified bubble sort.\n");

                void (*mod_bubble_ptr)(int[], int);
                mod_bubble_ptr = &modified_bubble_sort;

                int test_sorted_mod_bubble[size];
                copy(sorted_array, test_sorted_mod_bubble, size);
                time_taken = test_time(mod_bubble_ptr, test_sorted_mod_bubble, size);
                overall_time += time_taken;
                printf("Seconds taken for already sorted array: %lf\n", time_taken);

                int test_mod_bubble_random1[size];
                copy(random_array1, test_mod_bubble_random1, size);
                time_taken = test_time(mod_bubble_ptr, test_mod_bubble_random1, size);
                overall_time += time_taken;
                printf("Seconds taken for random array: %lf\n", time_taken);

                int test_unsorted_mod_bubble[size];
                copy(unsorted_array, test_unsorted_mod_bubble, size);
                time_taken = test_time(mod_bubble_ptr, test_unsorted_mod_bubble, size);
                overall_time += time_taken;
                printf("Seconds taken for worst case unsorted array: %lf\n", time_taken);

                printf("Overall time taken: %lf\n", overall_time);
                

                // #################################################
                //                INSERTION SORT
                // #################################################
                
                overall_time = 0;
                printf("\nCurrently testing insertion sort.\n");

                void (*insertion_sort_ptr)(int[], int);
                insertion_sort_ptr = &insertion_sort;

                int test_sorted_insertion[size];
                copy(sorted_array, test_sorted_insertion, size);
                time_taken = test_time(insertion_sort_ptr, test_sorted_insertion, size);
                overall_time += time_taken;
                printf("Seconds taken for already sorted array: %lf\n", time_taken);

                int test_insertion_random1[size];
                copy(random_array1, test_insertion_random1, size);
                time_taken = test_time(insertion_sort_ptr, test_insertion_random1, size);
                overall_time += time_taken;
                printf("Seconds taken for first random array: %lf\n", time_taken);

                int test_unsorted_insertion[size];
                copy(unsorted_array, test_unsorted_insertion, size);
                time_taken = test_time(insertion_sort_ptr, test_unsorted_insertion, size);
                overall_time += time_taken;
                printf("Seconds taken for worst case unsorted array: %lf\n", time_taken);

                printf("Overall time taken: %lf\n", overall_time);

                printf("\nPress anything to run the algorithm time recorder again.\n");
                printf("Press Escape to exit the program.\nPress Enter to go back to main menu.\n");
                controls = getch();
                if(controls == 27) {
                    return 0;
                }
                else if(controls == 13) {
                    break;
                }
            }
        }
    }
}