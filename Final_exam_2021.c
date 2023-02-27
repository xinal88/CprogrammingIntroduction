#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

typedef struct {
    int ID;
    int chapter;
    char content[50];
} Question;

Question input_question(Question qs, int n) {

}

void printQuestion(Question qs[], int n) {
    printf("%-5s%-8s%-9s\n", "ID", "Chap", "Content");
    for (int i = 0; i < n; i++) {
        printf("%-4d%-8d\"%-9s\"\n", qs[i].ID, qs[i].chapter, qs[i].content);
    }
}

int search(Question qs[], int number, int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (qs[i].ID == number) 
            index = number;
    }
    return index;
}

void sort(Question qs[], int n) {
	Question temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (qs[i].chapter > qs[j].chapter) {
				temp = qs[i];
				qs[i] = qs[j];
				qs[j] = temp;
			}
		}
	}
	
	printf("%-5s%-8s%-9s\n", "ID", "Chap", "Content");
    for (int i = 0; i < n; i++) {
        printf("%-4d%-8d\"%-9s\"\n", qs[i].ID, qs[i].chapter, qs[i].content);
    }
}

int verifyContent(char *s) {
	if (s[0] < 'A' || s[0] > 'Z') return 0;
	
	for (int i = 1; i < strlen(s); i++) {
		if (s[i] == '*' || s[i] == '$' || s[i] == '\\') return 0;
	}
	
	return 1;
}

void qualified(Question qs[], int n) {
	printf("%-5s%-8s%-9s\n", "ID", "Chap", "Content");
    for (int i = 0; i < n; i++) {
        if (verifyContent(qs[i].content) == 1)
			printf("%-4d%-8d\"%-9s\"\n", qs[i].ID, qs[i].chapter, qs[i].content);
    }
}

int main() {
    int choice, n;
    Question qs[n];
    do {
        printf("MENU\n");
        printf("1. Read.\n");
        printf("2. Search\n");
        printf("3. Add\n");
        printf("4. Sort\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                do {
                    printf("Enter the number of question: ");
                    scanf("%d", &n);
                    if (n <= 0 || n > 100)  printf("Must be > 0 and <= 100\n");
                } while (n <= 0 || n > 100);

                for (int i = 0; i < n; i++) {
                    printf("Enter the chapter and content: ");
                    scanf("%d %[^\n]%*c", &qs[i].chapter, qs[i].content);
                    qs[i].ID = i+1;
                }

                printQuestion(qs, n);
                break;
            }
            case 2: {
                int number;
                printf("Enter the ID: ");
                scanf("%d", &number);
                int tmp = search(qs, number, n); 
                if (tmp != -1) {
                     printf("%-4d%-8d%-9s\n", qs[tmp].ID, qs[tmp].chapter, qs[tmp].content);
                } else {
                    printf("Invalid ID\n");
                }
                break;
            }
            case 3: {
                printf("New question\n");
                n = n + 1;
                printf("Enter the chapter and content: ");
                scanf("%d %[^\n]%*c", &qs[n-1].chapter, qs[n-1].content);
                qs[n-1].ID = n;

                //Print some questions
                printQuestion(qs, n);
                break;
            }

            case 4: {
				sort(qs, n);				
				break;
            }
            case 5: {
            	qualified(qs, n);
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

    
