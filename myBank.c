#include <stdio.h>

double nums[2][50]={0};

double changeToPoint2(double x){
	return ((int) (x*100))/100.0;
}

void newOpen(double x){   // פותח חשבון חדש
	int i=0;
	if(x>0){
		while (i<50&&nums[0][i]!=0){ // לולה שבודקת עם יש מקום לפתוח חשבון 
			i++;
		}
		if(i==50)
			printf("is full");
		else {
			nums[0][i] = 1;
			nums[1][i] = changeToPoint2(x);
		}
		printf("new account %d\n",(901+i));
	}
}

int ifOpen(int x){   // מקבל מספר חשבון ובודק עם הוא קיים 
	int index = x-901;
	if(index > -1 && index < 50){
	   return (1);
	} else {
	   return(0);
	}
}

int cak(char x, char y, char z){
	int accountNum = 0;
	accountNum = 100*((int) (x-'0'))+10*((int) (y-'0'))+((int) (z-'0')); 
	return accountNum;
}

void Inquiry(char x, char y, char z){   // מקבל חשבון בנ ומתפיס את האיתרה 
    int a = cak(x, y, z);
	if(ifOpen(a)==1){  // בודק עם החשבון קיים
		a = ((a%100)-1);
		if(nums[0][a]== 1){ // בודק עם החשבון פעיל 
			printf ("The account balance: %.2lf \n",nums[1][a]);
		}else printf ("Account inactive\n");
	}else printf ("The account does not exist\n");					
}

void Deposit(char x, char y, char z){
	int a = cak(x, y, z);
	if(ifOpen(a)==1){
		double y = 0;
		printf("Please insert a Deposit number: ");
		scanf(" %lf", &y);
		if(y >= 0){
			a = ((a%10)-1);
			if(nums[0][a]==1){
			   nums[1][a]+=changeToPoint2(y);
			   printf ("balance is : %.2lf \n",nums[1][a]);
			} else printf ("The account is inactive. \n");
		} else printf ("Deposit can't be negative. \n");
	} else printf ("The account does not exist. \n");
}

void attraction(char x, char y, char z){
	int a = cak(x, y, z);
	if(ifOpen(a)== 1){
		double y = 0;
		printf("Please insert an attraction number: ");
		scanf(" %lf", &y);
		a=((a%100)-1);
	    if(nums[0][a]==1){
	       	if((nums[1][a]-y)>0){
				nums[1][a] -= changeToPoint2(y);
				printf ("balance is : %.2lf\n",nums[1][a]);
			} else { 
				printf ("you do not have enough money. \n");
			}
 	    } else	 printf ("Account inactive. \n");
	} else printf ("The account does not exist. \n");
}
	
void closeAccount(char x, char y, char z){
	int a = cak(x, y, z);
	if(ifOpen(a)==1){
		a = ((a%100)-1);
		if(nums[0][a]== 1){
			nums[0][a]= 0;
			nums[1][a]= 0;
		}else  printf ("Account inactive. \n");
	}else printf ("The account does not exist. \n");
}

void interest (double y){
	int i=0;
	while (i<50){
		if(nums[0][i]== 1){
			nums[1][i] = (((nums[1][i]*y)/100.0)+(nums[1][i]*1.0));
			nums[1][i] = changeToPoint2(nums[1][i]);
		}
		i++;
	}
}

void stringBank(){
	int i=0;
	while (i<50){
		if(nums[0][i]==1){
		printf ("Account: %d \n The account balance: %.2lf\n",(i+901),nums[1][i]);
		}
		i++;
	}
}

void closebank(){
	int i=0;
	while (i<50){
		if(ifOpen(i+901)==1){
			if(nums[0][i]==1){
				nums[0][i]=0;
				nums[1][i]=0;
			}
		}
		i++;
	}
	printf ("The bank is close! good day.\n");
}

