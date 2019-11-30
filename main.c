# include <stdio.h>
# include "myBank.h"

int main() {
	int flag = 1;	
	do {
		char i;
		printf("Please insert a char that repesent an action: ");
		scanf(" %c", &i);
		if( i == 'O' ){
			double x = 0;
			printf("Please insert a deposit number: ");
			scanf(" %lf", &x);
			newOpen(x);
		} else if ( i == 'B'){
			char x, y, z;
			printf("Please insert your account number: ");
			scanf(" %c %c %c", &x, &y, &z);
			Inquiry(x,y,z);
		} else if ( i == 'D'){
			char x, y, z;
			printf("Please insert your account number: ");
			scanf(" %c %c %c", &x, &y, &z);
			Deposit(x,y,z);
		} else if ( i == 'W'){
			char x, y, z;
			printf("Please insert your account number: ");
			scanf(" %c %c %c", &x, &y, &z);
			attraction(x,y,z);
		} else if ( i == 'C'){
			char x, y, z;
			printf("Please insert your account number: ");
			scanf(" %c %c %c", &x, &y, &z);
			closeAccount(x,y,z);
		} else if ( i == 'I'){
			double x = 0;
			printf("Please insert an interest number: ");
			scanf(" %lf", &x);
			interest(x);
		} else if ( i == 'P'){
			stringBank();
		} else if ( i == 'E'){
			closebank();
			flag = 0;
		} else {
			printf("Please select appropriate action:\n");
			printf("Open an account : O \n");
			printf("Balance inquiry : B \n");
			printf("Deposit		: D \n");
			printf("attraction      : W \n");
			printf("Account Closing : C \n");
			printf("add interest    : I \n");
			printf("Print           : P \n");
			printf("Close & Exit    : E \n");
		}
	} while (flag == 1);
}