#include "stdio.h"
long int findth(int a, int n);
int main(){
	int a,n;
	printf("Nhap co so va so mu: ");scanf("%d%d",&a,&n);
	printf("\nResult: %ld",findth(a,n));
	return 0;
}
long int findth(int a, int n){
	if(n == 0){
		return 1; 
	}
	if(a == 0){
		return 0;
	}
	if(n % 2 == 0){
		return findth(a*a,n/2);
	}else{
		return a * findth(a*a,n/2);
	}
}
