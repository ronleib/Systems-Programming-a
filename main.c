# include <stdio.h>
# include "myBank.h"
# define size 256

double checkf(char chk[size],int flag){
	int i=0,temp=0;
	int sumflag=flag;
	double sum=0;
	while (i<size&&chk[i] != ('\0'))
	{
		if(chk[i]>=48&&chk[i]<=57){
				if((sumflag>=1&&sumflag<3)){
					temp=((int)chk[i])-48;
					sum+=(temp/10.0);
					sumflag++;
					printf("1------%f------",sum);}
				else {
					temp=((int)chk[i])-48;
					sum=(sum*10)+temp;}
				}
		else if (chk[i]==46&&sumflag<5){ sumflag++;printf("2------%f------",sum);}

		else return -10;
		i++;
	}
	printf("3------%f------",sum);
	return sum;
}
int main() {
	int flag = 1;	
	do {
		char i[size];
		printf("\nOpen an account : O \n");
		printf("Balance inquiry : B \n");
		printf("Deposit		: D \n");
		printf("attraction      : W \n");
		printf("Account Closing : C \n");
		printf("add interest    : I \n");
		printf("Print           : P \n");
		printf("Close & Exit    : E \n");
		printf("Please select appropriate action:  ");
		scanf(" %s", i);
		if(i[1] == ('\0')){
			if( i[0] == 'O' ){
				char check[size];
				double x = 0;
				printf("Please insert a deposit number: ");
				scanf("%s", check);
				x=checkf(check,0);
				if(x!=-10)
					newOpen(x);
				else printf("Invalid request");
			} else if ( i[0] == 'B'){
					char check[size];
					int x = 0;
					printf("Please insert an account number: ");
					scanf("%s", check);
					x=((int)checkf(check,5));
					if(x!=-10)
						Inquiry(x);
					else printf("Invalid request");
			} else if ( i[0] == 'D'){
					char check_X[size],check_Y[size];
					int x = 0;
					double y = 0;
					printf("Please insert an account number: ");
					scanf("%s", check_X);
					x=((int)checkf(check_X,5));
					if(x!=-10){
						printf("Please insert a deposit number: ");
						scanf("%s", check_Y);
						y=checkf(check_Y,0);
						if(y!=-10){
							Deposit( x, y);}
						else printf("Invalid request");
					}
					else printf("Invalid request");
			} else if ( i[0] == 'W'){
						char check_X[size],check_Y[size];
						int x = 0;
						double y = 0;
						printf("Please insert an account number: ");
						scanf("%s", check_X);
						x=((int)checkf(check_X,5));
						if(x!=-10){
							printf("Please insert an attraction number: ");
							scanf("%s", check_Y);
							y=checkf(check_Y,0);
							if(y!=-10){
								attraction( x, y);}
							else printf("Invalid request");
						}
						else printf("Invalid request");
			} else if ( i[0] == 'C'){
					char check[size];
					int x = 0;
					printf("Please insert an account number: ");
					scanf("%s", check);
					x=((int)checkf(check,5));
					if(x!=-10)
						closeAccount(x);
					else printf("Invalid request");
			} else if ( i[0] == 'I'){
					char check[size];
					double x = 0;
					printf("Please insert an interest number: ");
					scanf("%s", check);
					x=checkf(check,0);
					if(x!=-10){
						interest(x);}
					else {printf("Invalid request");}
			} else if ( i[0] == 'P'){
				stringBank();
			} else if ( i[0] == 'E'){
				closebank();
				flag = 0;
			}
			//else if  printf("Your income is invalid /n Please select appropriate action:/n ");
		}
	
	else  printf("Your income is invalid /n Please select appropriate action:/n ");
	}
	 while (flag);
}
