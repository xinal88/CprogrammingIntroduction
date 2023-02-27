#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 200

typedef struct {
    int ClassID;
    char courseName[30];
    char room[10];
    int day;
    char slots[10];
} classe;

void printClass(classe cls[], int n) {
    printf("%-10s%-20s%-10s%-8s%-10s\n", "Ma lop", "Ten mon hoc", "Ten phong", "Thu", "Tiet hoc");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-20s%-10s%-8d%-10s\n", cls[i].ClassID, cls[i].courseName, cls[i].room, cls[i].day, cls[i].slots); 
    }
}

void searchClass(classe cls[], int n, char room[]) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(cls[i].room, room) == 0) 
            res++;
    }
    if (res == 0) printf("The room %s doesn't exist in the list\n", room);
    else {
    	printf("Number of class: %d\n", res);
		printf("%-10s%-20s%-10s%-8s%-10s\n", "Ma lop", "Ten mon hoc", "Ten phong", "Thu", "Tiet hoc");
    	for (int i = 0; i < n; i++) {
        	if (strcmp(cls[i].room, room) == 0) {
            	printf("%-10d%-20s%-10s%-8d%-10s\n", cls[i].ClassID, cls[i].courseName, cls[i].room, cls[i].day, cls[i].slots); 
        	}
    	}
    }
}

void sortClass(classe cls[], int n) {
    classe temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (cls[i].ClassID > cls[j].ClassID) {
                temp = cls[i];
                cls[i] = cls[j];
                cls[j] = temp;
            }
        }
    }
}

int check(char str1[], char str2[]) {
	 // Extract last number from first string
    char *token = strtok(str1, "-");
    int num1 = atoi(token);
    while (token != NULL) {
        num1 = atoi(token);
        token = strtok(NULL, "-");
    }
    
    // Extract first number from second string
    token = strtok(str2, "-");
    int num2 = atoi(token);
    
    // Compare numbers
    if (num1 >= num2 || num1 < 1 || num1 > 12 || num2 < 1 || num2 > 12) {
        return 1;
    } else {
        return 0;
    }    
}

int checkVerifyClass(char str1[]) {
	char *token = strtok(str1,"-");
	int num1 = atoi(token);
	int num2;
	while (token != NULL) {
		num2 = atoi(token);
		token = strtok(NULL, "-");
	}
	if (num1 >= num2) return 1;
	else return 0;
}


/*void check(char les_1[], char les_2[]) {
	int num[4];
	int index = 0;
	char number[4][2] = {"","","",""};
	
	index = 0;
	for (int i = 0; i < strlen(les_1); i++) {
		if (les_1[i] != '-') {
			number[index] = number[index] + les_1[i]; 
		} else {
			index++;
			
		}
	}
	for (int i = 0; i < strlen(les_2); i++) {
		if (les_2[i] != '-') {
			number[index] = number[index] + les_2[i]; 
		} else {
			index++;
			number[index] = ' ';
		}
	}
	
	for (int i = 0; i < 4; i++) {
		printf("%s ", number[i]);
	}	
}
*/
void checkClass(classe cls[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (strcmp(cls[i].room,cls[j].room) == 0) {
				if (cls[i].day == cls[j].day) {
					if (check(cls[i].slots, cls[j].slots) == 1)
						printf("%d %d\n", cls[i].ClassID, cls[j].ClassID);					
				}
			}
		}
	}
}

int main() {
    int choice, n = 0;
    int x = 0;
    classe c[MAX];
    do {
        printf("MENU\n");
        printf("1. Add class\n");
        printf("2. Print the class\n");
        printf("3. Search by room\n");
        printf("4. Sort by class ID\n");
        printf("5. Check identical class\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                int more;
                do {
                    printf("Enter the number of class: ");
                    scanf("%d", &more);
                    if (more <= 0 || more > 200)  printf("Must be > 0 and <= 200\n");
                } while (more <= 0 || more > 200);

                for (int i = n; i < n + more; i++) {
					printf("Class ID: ");
                    scanf("%d", &c[i].ClassID);
                    printf("Course Name: ");
                    scanf(" %[^\n]%*c", c[i].courseName);
                    printf("Room number: ");
                    scanf(" %[^\n]%*c", c[i].room);
                    do {
						printf("Day: ");
                    	scanf("%d", &c[i].day);
                    	if (c[i].day < 2 || c[i].day > 7) printf("Enter another date from 2 to 7!!!\n");
                	} while (c[i].day < 2 || c[i].day > 7);
					do {
                    	printf("Lesson: ");
                    	scanf(" %[^\n]%*c", c[i].slots);
                    	x = checkVerifyClass(c[i].slots); 
                    	if (x == 1) printf("Enter another slots!!!\n");
                	} while (x == 1);
				}

                n = n + more;
                break;
            }
            case 2: {
                printClass(c, n);
                break;
            }
            case 3: {
                char s[10];
                printf("Enter the room: ");
                scanf(" %[^\n]%*c", s);
                
                searchClass(c, n, s);
                break;
            }
            case 4: {
                sortClass(c, n);
                printClass(c, n);
                break;
            }
            case 5: {
				checkClass(c, n);
            }
            case 6: {
                printf("Thank you for using our service!!!");
                exit(0);
                break;
            }
            default: {
                printf("Please enter another number from 1 to 6 once again!!!\n");
                break;
            }
        }
    } while(1);

    return 0;
}
