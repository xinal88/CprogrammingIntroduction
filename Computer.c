#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 8

typedef struct times {
	int hour;
	int minute;
} time_t;

typedef struct com_type {
	int number;
	int free;
	time_t beginTime;
	time_t endTime;
	long fee;
	int time_used;
} computer;


int main() {
    int choice, n = 0;
    double average;
    student s[MAX];
    do {
        printf("MENU\n");
        printf("1. Initialize\n");
        printf("2. Use computer\n");
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
