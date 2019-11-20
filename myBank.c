#include <stdio.h>


double nums[2][50]={0};


void newofen(double x){      // פותח חשבון חדש
int i=0;
while (i<50&&nums[0][i]!=0){ // לולה שבודקת עם יש מקום לפתוח חשבון 
	i++;}
	if(i==50)
	  printf("is full");
	else {
	nums[0][i]=1;
	nums[1][i]=x;}
	printf("new acund %d",(901+i));
}

int ifofen(int x){   // מקבל מספר חשבון ובודק עם הוא קיים 
	int index=x-901;
	if(index>-1&&index<50)
	   return (1);
		else 
	   return(0);}
		
void Inquiry(int a){   // מקבל חשבון בנק ומתפיס את האיתרה 
    if(ifofen(a)==1){  // בודק עם החשבון קיים
	a=((a%10)-1);
	if(nums[0][a]==1) // בודק עם החשבון פעיל 
	printf ("The account balance,%f",nums[1][a]);
    	else 
        printf ("Account inactive");
	}
     else printf ("The account does not exist");					
}
void Deposit(int x,double y){
	if(ifofen(x)==1){
	 x=((x%10)-1);
	    if(nums[0][x]==1){
	       nums[1][x]+=y;
	       printf ("balance is : %f",nums[1][x]);
 	    }
	    else	 printf ("Account inactive");}
	else printf ("The account does not exist");
}

void attraction(int x,double y){
	if(ifofen(x)==1){
	 x=((x%10)-1);
	    if(nums[0][x]==1){
	       	if((nums[1][x]-y)>0){
		nums[1][x]-=y;
	       	printf ("balance is : %f",nums[1][x]);
		}
		else { printf ("you do not have enough money");}
 	    }
	    else	 printf ("Account inactive");
	}
	else printf ("The account does not exist");
	}
void close(int x){
	if(ifofen(x)==1){
	   x=((x%10)-1);
	    if(nums[0][x]==1){
		nums[0][x]=0;
		nums[1][x]=0;
		}
	    else  printf ("Account inactive");

	}
	 else printf ("The account does not exist");
}
void interest (double y){
	int i=0;
	while (i<50){
	 if(nums[0][i]==1)
	 nums[0][i]=(nums[0][i]*y+nums[0][i]);
	i++;}
}
void toStreng(){
	int i=0;
	while (i<50){
	 if(nums[0][i]==1)
	printf ("acund: %d /n The account balance: %f",(i+901),nums[1][i]);
	i++;}
}
void closbak(){
	int i=0;
	while (i<50){
	  if(ifofen(i+901)==1){
	    close (i);
	  }
	 i++;
	}
}

