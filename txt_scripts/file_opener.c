#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <conio.h>

void clear() {
    system("cls");
}

int main()
{
    int counter = 0;
    int current = 0;
	int max = 0;
    char file_name[30];
    char command[50];
    int controls;
    DIR *d;
    struct dirent *dir;
	FILE *fptr;
	
	clear();

    // Choose whether to run the program or open its contents.
    print("Press '1' in order to open program runner.\nPress '2' in order to open program reader.\n");
    controls = getch();

    // PROGRAM OPENER MODE
    if(controls == '1') 
    {
        clear();

        // Get number of files.
        d = opendir("./scripts");
        while((dir = readdir(d)) != NULL) {
            if(dir->d_type == DT_REG) {
                max++;
            }
        }
        closedir(d);

        while(1) {
            current = 0;
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
                    current++;
                }
            }
            
            closedir(d);
            controls = getch();
            system("cls");
            
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

        sprintf(command, "scripts\\%s", file_name);
        system(command);

        return 0;
    }
    // PROGRAM READER MODE
    else if(controls == '2') 
    {
        clear();

        // Get number of files.
        d = opendir("./txt_scripts");
        while((dir = readdir(d)) != NULL) {
            if(dir->d_type == DT_REG) {
                max++;
            }
        }
        closedir(d);

        while(1) {
            current = 0;
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
                    current++;
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

        return 0;
    }
    
}