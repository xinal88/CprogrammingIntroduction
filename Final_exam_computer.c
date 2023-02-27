#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10

typedef struct times {
	int hour; /* gia tri tu 0 - 23*/
	int minute;
} time_t;

typedef struct com_type {
	int number; /*so hieu*/
	int free;
	time_t beginTime;
	time_t endTime;
	long fee;
	int time_used;
} computer;

void print(computer c[], int n) {
	printf("%-5s%-10s%-10s%-10s%-10s%-10s\n", "STT", "Status", "Begin", "End", "Fee", "Time-used");
	for (int i = 0; i < n; i++) {
		printf("%-5d%-10s%-2s%-2s%")
	}
}

int invalidTime(computer c) {
	int x = (c.beginTime.hour * 60 + c.beginTime.minute) - (c.endTime.hour * 60 + c.endTime.minute);
	if (x < 0) return 1;
		else return 0;
}

int timeCompare(time_t a, time_t b) {
		
}

int main() {
	int choice, n;
	computer c[MAX];
	
	switch (choice) {
		case 1: {
					
			break;
		}
	}
}
