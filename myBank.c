#include <stdio.h>

double nums[2][50]={0};

void newOpen(double x){      // פותח חשבון חדש
	int i=0;
	while (i<50&&nums[0][i]!=0){ // לולה שבודקת עם יש מקום לפתוח חשבון 
		i++;
	}
	if(i==50){
		printf("is full");
	} else {
		nums[0][i]=1;
		nums[1][i]=x;
		i+=901;
		printf("new account: %d\n",i);
	}
}

int ifOpen(int x){   // מקבל מספר חשבון ובודק עם הוא קיים 
	int index=x-901;
	if(index>-1&&index<50){
		return (1);
	}else return(0);
}
	
void Inquiry(int a){   // מקבל חשבון בנק ומתפיס את האיתרה 
    if(ifOpen(a)==1){  // בודק עם החשבון קיים
		a=(a%100)-1;
		if(nums[0][a]==1){ // בודק עם החשבון פעיל 
			printf ("The account balance,%.2f",nums[1][a]);
		}else printf ("Account inactive");
		
	}else printf ("The account does not exist");					
}
void Deposit(int x,double y){
	if(ifOpen(x)==1){
		x=((x%100)-1);
	    if(nums[0][x]==1){
	       nums[1][x]+=y;
	       printf ("balance is : %.2f\n",nums[1][x]);
 	    }
		else printf ("Account inactive");
	}
	else printf ("The account does not exist");
}

void attraction(int x,double y){ //משיכה מהחשבון 
	if(ifOpen(x)==1){
	 x=((x%100)-1);
	    if(nums[0][x]==1){
	       	if((nums[1][x]-y)>0){
				nums[1][x]-=y;
				printf ("balance is : %.2f\n",nums[1][x]);
			}
			else { printf ("you do not have enough money\n");}
 	    }
	    else printf ("Account inactive\n");
	}
	else printf ("The account does not exist\n");
}

void closeAccount(int x){ // סגירת חשבון
	if(ifOpen(x)==1){
		x=((x%100)-1);
	    if(nums[0][x]==1){
			nums[0][x]=0;
			nums[1][x]=0;
		}
	    else  printf ("Account inactive\n");
	}
	else printf ("The account does not exist\n");
}

void interest(double y){  // הוספת ריבית
	int i=0;
	while (i<50){
		if(nums[0][i]==1){
			nums[1][i]=(((nums[1][i]*y)/100.0)+(nums[1][i]*1.0));
		}
		i++;
	}
}

void stringBank(){  // מדפיס את החשבונות הפעילים + יתרה
	int i=0;
	while (i<50){
		if(nums[0][i]==1){
			printf ("acund: %d \n The account balance: %.2f \n",(i+901),nums[1][i]);
		}
		i++;
	}
}

void closebank(){  // סוגר את כל החשבונות 
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
	printf ("All accounts closed.\n");
}
