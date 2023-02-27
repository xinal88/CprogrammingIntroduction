#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

typedef struct {
	char name[30];
	char ID[12];
	char home_town[30];
	double GPA;
} student;

char* lowerCase(char* str) {
    char* p = str;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
    return str;
}

char* capitalize(char* str) {
    // Check if string is empty
    if (strlen(str) == 0) {
        return str;
    }

    // Capitalize first character
    str[0] = toupper(str[0]);

    // Iterate through string and capitalize after spaces
    for (int i = 1; i < strlen(str); i++) {
        if (isspace(str[i]) && i+1 < strlen(str)) {
            str[i+1] = toupper(str[i+1]);
        }
    }

    return str;
}

void search_GPA_HT(student stu[], int n, char st[], double average) {
	int index = 0;
	printf("%-6s%-20s%-15s%-20s%-5s\n", "STT", "Ten", "MSSV", "Que Quan", "GPA");
	for (int i = 0; i < n; i++) {
		int result = strcmp(lowerCase(stu[i].home_town), lowerCase(st));
		if (stu[i].GPA > average && result == 0) {
			index++;
			printf("%-6d%-20s%-15s%-20s%-5.1lf\n", index, stu[i].name, stu[i].ID, stu[i].home_town, stu[i].GPA);
		}
	}
}

void sort(student stu[], int n) {
	student temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (stu[i].GPA < stu[j].GPA) {
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}	
}

void printStudent(student stu[], int n) {
	double sum = 0;
	printf("%-6s%-20s%-15s%-20s%-5s\n", "STT", "Ten", "MSSV", "Que Quan", "GPA");
	for (int i = 0; i < n; i++) {
		sum = sum + stu[i].GPA;
		printf("%-6d%-20s%-15s%-20s%-5.1lf\n", i+1, stu[i].name, stu[i].ID, capitalize(stu[i].home_town), stu[i].GPA);
	}
	printf("Diem GPA trung binh tat ca sinh vien: %0.1lf\n", sum/n);
}


void search(student stu[], int n, char s[]) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if(strcmp(s, stu[i].ID) == 0) {
			index = i;
		}
	}
	if (index != -1) {
		printf("%-6s%-20s%-15s%-20s%-5s\n", "STT", "Ten", "MSSV", "Que Quan", "GPA");
			printf("%-6d%-20s%-15s%-20s%-5.1lf\n", index+1, stu[index].name, stu[index].ID, stu[index].home_town, stu[index].GPA);	
	} else {
		printf("Searching FAILED\n");
	}
}


int main() {
    int choice, n = 0;
    double average;
    student s[MAX];
    do {
        printf("MENU\n");
        printf("1. Read.\n");
        printf("2. Print\n");
        printf("3. Search by Student ID\n");
        printf("4. Search by Home town and GPA\n");
        printf("5. Sort by GPA\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
            	int more;
            	double sum = 0;
                do {
                    printf("Enter the number of student: ");
                    scanf("%d", &more);         
                    if (more <= 0)  printf("Must be > 0\n");
                } while (more <= 0 );

                for (int i = n; i < n + more; i++) {
                    printf("Enter the student ID: ");
                    scanf(" %[^\n]%*c", s[i].ID);
                    printf("Enter the student name: ");
                    scanf(" %[^\n]%*c", s[i].name);
                    printf("Enter the student home town: ");
                    scanf(" %[^\n]%*c", s[i].home_town);
                    printf("GPA: ");
                    scanf("%lf", &s[i].GPA);
                    sum = sum + s[i].GPA;
                }
				
				n = n + more;
				average = sum/n;
                break;
            }
            case 2: {
                printStudent(s, n);
                break;
            }
            case 3: {
            	char st[9];
				printf("Enter the ID: ");
				scanf(" %[^\n]%*c", st);
				search(s, n, st);
				
                break;
            }

            case 4: {
            	char st[15];
            	printf("Enter the home town: ");
            	scanf(" %[^\n]%*c", st);
				search_GPA_HT(s, n, st, average);				
				break;
            }
            case 5: {
            	sort(s, n);
            	printStudent(s, n);
				break;				
            }
            case 6: {
                printf("Thank you for using our service!!!");
                exit(0);
            }
            default: {
                printf("Please enter another number from 1 to 6 once again!!!\n");
                break;
            }
        }
    } while(1);

    return 0;
}

