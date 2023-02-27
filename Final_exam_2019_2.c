#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 40

typedef struct {
    char tenSV[20];
    float DiemQT, DiemCK, DiemTK;
    char DiemXL[2];
} DiemSV;

void printTable(DiemSV cls[], int n) {
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep loai");
    for (int i = 0; i < n; i++) {
        printf("%-20s%-15.0f%-15.0f%-15.1f%-15s\n", cls[i].tenSV, cls[i].DiemQT, cls[i].DiemCK, cls[i].DiemTK, cls[i].DiemXL); 
    }
}

void check(DiemSV cls[], int n, int l) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (abs(cls[i].DiemQT - cls[i].DiemCK) >= l) 
            res++;
    }
    if (res == 0) printf("There is no student has bigger differeent %d score in Diem QT and Diem Ck \n", l);
    else {
    	printf("Number of student: %d\n", res);
		printf("%-20s%-15s%-15s%-15s%-15s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep loai");
        for (int i = 0; i < n; i++) {
        	if (abs(cls[i].DiemQT - cls[i].DiemCK) >= l)
        		printf("%-20s%-15.0f%-15.0f%-15.1f%-15s\n", cls[i].tenSV, cls[i].DiemQT, cls[i].DiemCK, cls[i].DiemTK, cls[i].DiemXL); 
    	}
    }
}

void sortTable(DiemSV cls[], int n) {
    DiemSV temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (cls[i].DiemTK < cls[j].DiemTK) {
                temp = cls[i];
                cls[i] = cls[j];
                cls[j] = temp;
            }
            else {
            	if (cls[i].DiemTK == cls[j].DiemTK) {
            		if (strcmp(cls[i].tenSV, cls[j].tenSV) == 1) {
            			temp = cls[i];
                		cls[i] = cls[j];
                		cls[j] = temp;
					}
				}
			}
        }
    }
}

int main() {
    int choice, n;
    int x = 0;
    DiemSV c[MAX];
    do {
        printf("MENU\n");
        printf("1. Input score\n");
        printf("2. Print the class score\n");
        printf("3. Different in score\n");
        printf("4. Sort\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                int more;
                do {
                    printf("Enter the number of student: ");
                    scanf("%d", &n);
                    if (n <= 0 || n > 40)  printf("Must be > 0 and < 40\n");
                } while (n <= 0 || n > 40);

                for (int i = 0; i < n; i++) {
					printf("Ten Sinh vien: ");
                    scanf(" %[^\n]%*c", c[i].tenSV);
					do {
                    	printf("Diem qua trinh: ");
                    	scanf("%f", &c[i].DiemQT);
                    	if (c[i].DiemQT < 0 || c[i].DiemQT > 10) printf("Must be >= 0 and <= 10");
                	} while (c[i].DiemQT < 0 || c[i].DiemQT > 10); 
                    do {
                    	printf("Diem cuoi ky: ");
                    	scanf("%f", &c[i].DiemCK);
                    	if (c[i].DiemCK < 0 || c[i].DiemCK > 10) printf("Must be >= 0 and <= 10");
                	} while (c[i].DiemCK < 0 || c[i].DiemCK > 10); 
                	
                    c[i].DiemTK = (c[i].DiemQT*4) / 10 + (c[i].DiemCK*6)/10;
                    
                    printf("Diem tong ket la: %0.1f\n", c[i].DiemTK);
                    
                    if (c[i].DiemQT <= 3 || c[i].DiemCK <=3) strcpy(c[i].DiemXL,"F");
                    else {
					
	                    if (c[i].DiemTK >= 8.5) strcpy(c[i].DiemXL,"A");
	                    else if (c[i].DiemTK >=7) strcpy(c[i].DiemXL,"B");
	                    else if (c[i].DiemTK >= 5.5) strcpy(c[i].DiemXL,"C");
	                    else if (c[i].DiemTK >= 4) strcpy(c[i].DiemXL, "D");
	                    else strcpy(c[i].DiemXL,"F"); 
	                }
	                printf("Xep loai: %s\n", c[i].DiemXL);
				}

                break;
            }
            case 2: {
                printTable(c, n);
                break;
            }
            case 3: {
                int l;
                printf("Nhap so diem chenh lech: ");
                scanf("%d", &l);
                check(c, n, l);
                break;
            }
            case 4: {
                sortTable(c, n);
                printTable(c, n);
                break;
            }
            case 5: {
				printf("Thank you for using our service!!!");
                exit(0);
                break;
            }
            default: {
                printf("Please enter another number from 1 to 5 once again!!!\n");
                break;
            }
        }
    } while(1);

    return 0;
}
