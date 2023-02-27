#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 20

typedef struct {
	double r1;
	double r2;
	double r3;
} result;

typedef struct {
	int ID;
	char nation[3];
	char name[30];
	result r;	
} athelete;

void printResult(athelete ath[], int n) {
	printf("%-7s%-11s%-20s%-8s%-8s%-8s%-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
	for (int i = 0; i < n; i++) {
		double sum = ath[i].r.r1 + ath[i].r.r2 + ath[i].r.r3;
		printf("%-7d%-11s%-30s%-8.2f%-8.2f%-8.2f%-8.2f\n", ath[i].ID, ath[i].nation, ath[i].name, ath[i].r.r1, ath[i].r.r2, ath[i].r.r3, sum);
	}
}

void searchByNation(athelete ath[], int n, char nat[]) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(ath[i].nation, nat) == 0) {
			res++;
		}
	}
	if (res == 0) printf("There is no athelete from %s\n", nat);
	else {
		printf("%-7s%-11s%-20s%-8s%-8s%-8s%-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			if (strcmp(ath[i].nation, nat) == 0) {		
				double sum = ath[i].r.r1 + ath[i].r.r2 + ath[i].r.r3;
				printf("%-7d%-11s%-30s%-8.2f%-8.2f%-8.2f%-8.2f\n", ath[i].ID, ath[i].nation, ath[i].name, ath[i].r.r1, ath[i].r.r2, ath[i].r.r3, sum);
			}
		}
	}
}

void searchByName(athelte ath[], int n, char nam[]) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(ath[i].name, nam) == 0) {
			res++;
		}
	}
	if (res == 0) printf("There is no athelete from %s\n", nat);
	else {
		printf("%-7s%-11s%-20s%-8s%-8s%-8s%-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			if (strcmp(ath[i].name, nam) == 0) {		
				double sum = ath[i].r.r1 + ath[i].r.r2 + ath[i].r.r3;
				printf("%-7d%-11s%-30s%-8.2f%-8.2f%-8.2f%-8.2f\n", ath[i].ID, ath[i].nation, ath[i].name, ath[i].r.r1, ath[i].r.r2, ath[i].r.r3, sum);
			}
		}
	}
}

int main() {
    int choice, n;
    athelete ath[MAX];
    do {
        printf("MENU\n");
        printf("1. Read\n");
        printf("2. Print\n");
        printf("3. Play\n");
        printf("4. Search\n");
        printf("5. Result\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                do {
                    printf("Enter the number of atheletes: ");
                    scanf("%d", &n);
                    if (n <= 0 || n > 20)  printf("Must be > 0 and <= 20\n");
                } while (n <= 0 || n > 20);

                for (int i = 0; i < n; i++) {
                	printf("-------------------------------\n");
                    printf("ID: ");
                    scanf("%d", &ath[i].ID);
                    printf("Nation: ");
                    scanf(" %[^\n]%*c", ath[i].nation);
                    printf("Athelete Name: ");
                    scanf(" %[^\n]%*c", ath[i].name);
                }

                break;
            }
            case 2: {
				printResult(ath, n);            	
                
                break;
            }
            case 3: {
            	int count = 1;
            	do {
            		printf("Turn %d\n", count);
            	for (int i = 0; i < n; i++) {
                	
                	printf("--------------------------------\n");
                	printf("Player ID %d\n", ath[i].ID);
                	printf("Score: ");
                	scanf("%lf", &ath[i].r.r1);
                }
                
				} while (count > 3);
			
			    break;
            }

            case 4: {
			//	sort(qs, n);				
				break;
            }
            case 5: {
            //	qualified(qs, n);
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

