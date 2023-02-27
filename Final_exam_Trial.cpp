#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 30

typedef struct {
	double noitru;
	double phauthuat;
	double thuoc;
	double giatri;
} Vienphi;

typedef struct {
	char hoten[30];
	char loaithe;
	Vienphi vp;
} Benhnhan;

char *trimSpace(char *str) {
        //Left trim 
    char *frontp = str;
    while (isspace(*frontp)) {
        ++frontp;
    }
    memmove(str, frontp, strlen(frontp) + 1);
        //Right trim
    char *endp = str + strlen(str) - 1;
    while (endp > str && isspace(*endp)) {
        --endp;
    }
    *(endp + 1) = '\0';
        //Whitespaces trim
    char *insidep = str;
    while (isspace(*insidep) && isspace(*insidep++)) {
        *insidep++;
    }

    return str; 
}

//Capitalize the first character
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

void printPatient(Benhnhan bn[], int n) {
	printf("%-5s%-20s%-15s\n", "STT", "Ho ten", "Loai the");
	for (int i = 0; i < n; i++) {
		if (bn[i].loaithe == 'G')
			printf("%-5d%-20s%-15s\n", i+1, bn[i].hoten, "Gold");
		else if (bn[i].loaithe == 'S')
			printf("%-5d%-20s%-15s\n", i+1, bn[i].hoten, "Silver");
		else if (bn[i].loaithe == 'C')
			printf("%-5d%-20s%-15s\n", i+1, bn[i].hoten, "Citizen");
	}
}

void printPatient2(Benhnhan bn[], int n, int giamtru[], int fee[]) {
	printf("%-20s%-15s%-15s%-15s%-15s\n", "Ho ten", "Loai the", "Chi phi the", "Giam tru","Phai tra");
	for (int i = 0; i < n; i++) {
		printf("%-20s%-15s%-15.0lf%-15.0lf%-15.0lf\n", bn[i].hoten, bn[i].loaithe, bn[i].vp.giatri, giamtru[i], fee[i]);
	}	
}

int maxProfit(int giamtru[], int n) {
	int max = 0;
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (max < giamtru[i]) {
			max = giamtru[i];
			index = i;
		}
	}
	return index;
}

int maxStay(Benhnhan bn[], int n) {
	int max = 0;
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (max < bn[i].vp.noitru) {
			max = bn[i].vp.noitru;
			index = i;
		}
	}
	return index;
}

int main() {
	int choice, n;
	int x;
	int giamtru[MAX], fee[MAX];
	Benhnhan bn[MAX];
	   do {
        printf("MENU\n");
        printf("1. Add patient\n");
        printf("2. Pay the patient fee\n");
        printf("3. Report\n");
        printf("4. Special report\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                int n;
                do {
                    printf("Enter the number of patient: ");
                    scanf("%d", &n);
                    if (n <= 0 || n > 30)  printf("Must be > 0 and < 30\n");
                } while (n <= 0 || n > 30);

                for (int i = 1; i < n; i++) {
                	printf("Patient Name: ");
                    scanf(" %[^\n]%*c", bn[i].hoten);
					printf("Name after normalization %s\n", capitalize(trimSpace(bn[i].hoten)));
					do {
					
						printf("Hospital Card type: "); 
                    	scanf("%c", bn[i].loaithe);
                    	getchar();
                    	if (bn[i].loaithe != 'G' && bn[i].loaithe != 'S' && bn[i].loaithe != 'C') 
                    		printf("Must be a single character G for Gold, S for Silver \and C for Citizen\n!!!");
                	} while (bn[i].loaithe != 'G' && bn[i].loaithe != 'S' && bn[i].loaithe != 'C');
				}

                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                	printf("Patient %s\n", bn[i].hoten);
                	do {
                		printf("How many day you stay at hospital: ");
                		scanf("%f", &bn[i].vp.noitru);
                		if (bn[i].vp.noitru > 10  || bn[i].vp.noitru < 0) 
                			printf("Must be a number from 0 to 10\n");
					} while (bn[i].vp.noitru > 10  || bn[i].vp.noitru < 0);
					do {
						printf("Did you do the surgery (1 for Yes, 0 for No): ");
						scanf("%d", &x);
						if (x != 1 || x != 0) printf("Must be 1 or 0\n");
						if (x == 1) {
							do {
								printf("Enter the surgery fee: ");
								scanf("%lf", &bn[i].vp.phauthuat);
								if (bn[i].vp.phauthuat < 0 || bn[i].vp.phauthuat > 2000000)
									printf("The surgery fee must be from 0 to 2 million VND\n");
							} while (bn[i].vp.phauthuat < 0 || bn[i].vp.phauthuat > 2000000);
						} else if (x == 0) 
								bn[i].vp.phauthuat = 0;
					} while (x != 1 || x != 0);
					
						do {
							printf("Enter the medicine fee: ");
							scanf("%lf", &bn[i].vp.thuoc);
							if (bn[i].vp.thuoc < 0 || bn[i].vp.thuoc > 5000000) 
								printf("The medicine fee must be from 0 to 5 million VND\n");
						} while (bn[i].vp.thuoc < 0 || bn[i].vp.thuoc > 5000000);

						bn[i].vp.giatri = bn[i].vp.noitru*15000 + bn[i].vp.phauthuat + bn[i].vp.thuoc;
											
						if (bn[i].loaithe == 'G') {
							giamtru[i] = (bn[i].vp.giatri * 70) / 100;
							printf("Patient %s has been reduced %d by Gold membership\n", bn[i].hoten, giamtru[i]);
						} else if (bn[i].loaithe == 'S') {
							giamtru[i] = (bn[i].vp.giatri * 50) / 100;
							printf("Patient %s has been reduced %d by Silver membership\n", bn[i].hoten, giamtru[i]);
						} else {
							giamtru[i] = (bn[i].vp.giatri * 30) / 100;
							printf("Patient %s has been reduced %d by Citizen membership\n", bn[i].hoten, giamtru[i]);
						}
						
						fee[i] = bn[i].vp.giatri - giamtru[i];
						printf("Patient fee: %d - %d = %d\n", bn[i].vp.giatri, giamtru[i], fee[i]);
                break;
            	}
            }
            case 3: {
                printPatient2(bn, n, giamtru, fee);
                break;
            }
            case 4: {
            	int a = maxProfit(giamtru, n);
                printf("The most profitable patient is %s\n", bn[a].hoten);
				int b = maxStay(bn, n);
				printf("Patient who stays longest in hospital is %s\n", bn[b].hoten);                
                break;
            }
            case 5: {
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
