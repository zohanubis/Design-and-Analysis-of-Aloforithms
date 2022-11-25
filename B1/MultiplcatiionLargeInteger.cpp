#include "stdio.h"
#include "math.h"
// Tích số nguyên 
int max(long a,long b);
long multiplicationLargeInteger(long a, long b);
int main(){
	int a,b;
	printf("Input A:");
	scanf("%ld",&a);
	printf("Input B:");
	scanf("%ld",&b);
	printf("Multiplication A and B is: %ld",multiplicationLargeInteger(a,b));
	return 0;
}
int max(long a,long b){
	int max;
	int count = 0;
	if(a >= b){
		max = a;
	}else{
		max = b;
	}
	while(max > 0){
		max = max / 10;
		count++;
	}
	if(count % 2 != 0){
		count++;
	}
	return count;
}
long multiplicationLargeInteger(long a, long b){
	long a0,a1,b0,b1,c0,c2,x;
	int n = max(a,b);
	if(a == 0 || b == 0){
		return 0;
	}else if(n <= 2){
		return a*b;
	}else{
		a0 =  a % (int)pow(10,n/2);
		a1 = a / pow(10,n/2);
		b0 = b % (int)pow(10,n/2);
		b1 = b / pow(10,n/2);
		c2 = multiplicationLargeInteger(a1,b1);
		c0 = multiplicationLargeInteger(a0,b0);
		x = multiplicationLargeInteger(a1+a0,b1+b0);
		return c2*pow(10,n) + (x - c2 - c0)*pow(10,n/2) + c0;
	}
}
