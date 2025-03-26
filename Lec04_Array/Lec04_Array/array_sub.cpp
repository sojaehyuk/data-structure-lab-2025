#include<stdio.h>
#define MAX_SIZE	9

void sub(int x, int arr[]) {
	x = 10;
	arr[0] = 9;
}
void main()
{
	int var = 0, list[MAX_SIZE];
	list[0] = 0;
	sub(var, list);	// var?, list[0]?
	printf("var=%d, list[0]=%d\n", var, list[0]);
	
}