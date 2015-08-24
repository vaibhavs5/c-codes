#include<stdio.h>

int main()
{
	int a=9,b;
	printf("\nEnter the no.s \n");
	scanf("%d %d",&a,&b);
	printf("%d\n",~(~(a^b))+1);
}
