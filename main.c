#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <conio.h>

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
	
	system("cls");
	
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
		if(controls == 119) {
			counter--;
		}
		if(controls == 115) {
			counter++;
		}
		if(counter < 0) {
			counter = 0;
		}
		if(counter >= max) {
			counter = max - 1;
		}
		
    }
	
    sprintf(command, "scripts\\%s", file_name);
    system(command);

    return 0;
}