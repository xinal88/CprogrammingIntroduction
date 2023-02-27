#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 30

typedef struct vip {
  int noitru;
  double phauthuat;
  double thuoc;
  double giatri;
} Vienphi;

typedef struct benh {
  char hoten[30];
  char loaithe[6];
  Vienphi vp;
} Benhnhan;

void removeWhitespace(char str[]){
    //xóa kho?ng tr?ng
    int i = 0, j = 0;
    while (str[i])
    {
        while (isspace(str[i]) && isspace(str[i + 1]))
        {
            i++;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
}
//lower all the characters
char *lower(char str[]){
    for(int i = 0; i < strlen(str);i++){
        str[i] = tolower(str[i]);
    }
    return str;
}
char *upper_first_character(char str[]){
    str[0] = toupper(str[0]);
    for(int i = 1; i <strlen(str); i++){
        if(isspace(str[i]) && str[i+1] != ' '){
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}
/*void printPatient(Benhnhan bn[], int n) {
  printf("STT\tHo ten\tLoai the\n");
  for (int i = 0; i < n; i++) {
    if (strcmp(bn[i].loaithe,"G") == 0) 
      printf("%d\t%s\t%s\n", i+1, bn[i].hoten, "Gold");
    if (strcmp(bn[i].loaithe,'S') == 0)
      printf("%d\t%s\t%s\n", i+1, bn[i].hoten, "Silver");
    if (strcmp(bn[i].loaithe,'C') == 0)
      printf("%d\t%s\t%s\n", i+1, bn[i].hoten, "Concatenate");
  }
} */

/*void report(Benhnhan bn[], int n) {
  printf("Ho ten\tLoai the\tChi phi tho\tGiam tru\tPhai tra\n");
  for (int i = 0; i < n; i++) {
    if (bn[i].loaithe == 'G') { 
      double tmp = (bn[i].vp.giatri * 70) / 100; 
       printf("%s\t%s\t%lf\t%lf\t%lf\n", bn[i].hoten, bn[i].loaithe, bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
     }
     if (bn[i].loaithe == 'S') { 
       double tmp = (bn[i].vp.giatri * 50) / 100; 
       printf("%s\t%s\t%lf\t%lf\t%lf\n", bn[i].hoten, bn[i].loaithe, bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
     }
      if (bn[i].loaithe == 'C') { 
       double tmp = (bn[i].vp.giatri * 30) / 100; 
       printf("%s\t%s\t%lf\t%lf\t%lf\n", bn[i].hoten, bn[i].loaithe, bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
      }
  }
}*/

int checkMostProfit(Benhnhan bn[], int n) {
  int index = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
     if (strcmp(bn[i].loaithe,"G") == 0) { 
       double tmp = (bn[i].vp.giatri * 70) / 100;
       if (max < tmp) {
	max = tmp;
	index = i;
      }
     }
     if (strcmp(bn[i].loaithe,"S") == 0) { 
       double tmp = (bn[i].vp.giatri * 50) / 100; 
       if (max < tmp) {
	max = tmp;
	index = i;
      }
     }
     if (strcmp(bn[i].loaithe, "C") == 0) { 
       double tmp = (bn[i].vp.giatri * 30) / 100; 
       if (max < tmp) {
	max = tmp;
	index = i;
      }
     }
  }

  return index;
}

int checkMostStay(Benhnhan bn[], int n) {
  int max = 0;
  int index = 0;
  for (int i = 1; i < n; i++) {
    if (bn[i].vp.noitru > max) {
      max = bn[i].vp.noitru;
      index = i;
    }
  }
  return index;
}

int main() {
  Benhnhan bn[MAX];
  int choice, n;
  do {
    printf("\nMENU\n");
    printf("1. Nhap ten benh nhan\n");
    printf("2. Thanh toan vien phi\n");                            
    printf("3. Bao cao chung\n");
    printf("4. THong ke dac biet\n");
    printf("5. Thoat\n");
    printf("-----------------------------------\n");
    printf("Chon 1 con so tu 1 den 5: ");
    scanf("%d", &choice);

    switch(choice) {
    case 1: {

      printf("Nhap so luong benh nhan: ");
      scanf("%d", &n);

      for (int i = 0; i < n; i++) {
		printf("Benh nhan %d\n", i+1);
		printf("Ten benh nhan: ");
		//fgets(bn[i].hoten, sizeof(bn[i].hoten), stdin);
		scanf(" %[^\n]%*c", bn[i].hoten);
		printf("Loai the: ");
		scanf(" %[^\n]%*c", bn[i].loaithe);
		//fgets(bn[i].loaithe, sizeof(bn[i].loaithe), stdin);
	   
      }
      
      break;
    }

      case 2: {
	for (int i = 0; i < n; i++) {
	  printf("Xin chao benh nhan %s\n", bn[i].hoten);
	  printf("Vien phi\n");
	  printf("-------------------------------------\n");
	  
	  do {
	    printf("Noi tru: ");
	    scanf("%d", &bn[i].vp.noitru);
	  } while (bn[i].vp.noitru >= 10 || bn[i].vp.noitru < 0);
	    
		printf("Ban co phau thuat hay khong (co: 1, khong: 0)? ");
	    int x;
	    scanf("%d", &x);
	    if (x == 1) {
	      do {
			printf("Phau thuat: ");
			scanf("%lf", &bn[i].vp.phauthuat);
	      } while (bn[i].vp.phauthuat > 2000000 || bn[i].vp.phauthuat < 0);
	    }
	    else bn[i].vp.phauthuat = 0;
	    
	    printf("Thuoc: ");
	    scanf("%lf", &bn[i].vp.thuoc);
	    
	    bn[i].vp.giatri = bn[i].vp.phauthuat + bn[i].vp.noitru*150000 + bn[i].vp.thuoc;
	    
	}
		
		printf("\n%-4s%-20s%-8s", "STT", "Ho ten", "Loai the");
	  	for (int i = 0; i < n; i++) {
	    	if (strcmp(bn[i].loaithe,"G") == 0) 
	      		printf("\n%-4d%-20s%-8s", i+1, bn[i].hoten, "Gold");
	    	if (strcmp(bn[i].loaithe, "S") == 0)
	      		printf("\n%-4d%-20s%-8s", i+1, bn[i].hoten, "Silver");
	    	if (strcmp(bn[i].loaithe, "C") == 0)
	      		printf("\n%-4d%-20s%-8s", i+1, bn[i].hoten, "Citizen");
	  	}
	
		printf("\n");
		break;
    }

    case 3: {
      printf("%-20s%-13s%-20s%-20s%-20s\n", "Ho ten", "Loai the", "Chi phi tra", "Giam tru", "Phai tra");
  	for (int i = 0; i < n; i++) {
    	if (strcmp(bn[i].loaithe,"G") == 0) { 
      	double tmp = (bn[i].vp.giatri * 70) / 100; 
       	printf("%-20s%-13s%-20.0lf%-20.0lf%-20.0lf\n", bn[i].hoten, "Gold", bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
     }
     	if (strcmp(bn[i].loaithe,"S") == 0) { 
       	double tmp = (bn[i].vp.giatri * 50) / 100; 
       	printf("%-20s%-13s%-20.0lf%-20.0lf%-20.0lf\n", bn[i].hoten, "Silver", bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
     }
      	if (strcmp(bn[i].loaithe,"C") == 0) { 
       	double tmp = (bn[i].vp.giatri * 30) / 100; 
     	printf("%-20s%-13s%-20.0lf%-20.0lf%-20.0lf\n", bn[i].hoten, "Citizen", bn[i].vp.giatri, tmp, bn[i].vp.giatri - tmp); 
    	}
  	}
      break;

    }

    case 4: {
      int temp = checkMostProfit(bn, n);
      printf("Benh nhan huong loi nhieu nhat: %s\n", bn[temp].hoten);
      int temp_2 = checkMostStay(bn, n);
      printf("Benh nhan nam vien nhieu nhat: %s\n", bn[temp_2].hoten);
      break;
    }

    case 5: {
      printf("Thank you for using our service !!!\n");
      exit(0);
    }
      
    default: {
      printf("Please enter another number from 1 to 5!!!");
      break;
    }
    }
  } while(1);

  return 0;
}
