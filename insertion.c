#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    int n,temp,t,i;
    struct timeval t1,t2;

    sscanf(argv[1],"%d",&n);
    int j,*a=(int *)malloc(n * sizeof(int));

    printf("Enter the elements of an array");

    for(i=n;i>=0;i--)
    {
	a[i]=i;
    }	

    gettimeofday(&t1,NULL);
    for(i=0;i<n;i++)
    {
	temp=a[i];
	for(j=i+1;j<n;j++)
	{
	    if(temp>a[j])
	    {
                t=a[i];
	        a[i]=a[j];
		a[j]=t;
	    }
	}
    }
   
    gettimeofday(&t2,NULL);
    
    printf("\nsorted array is:");
    for(i=0;i<n;i++)
    {
	printf("%d\n",a[i]);
    }	

    printf("\nTime elapsed:%ld\n",(((t2.tv_sec*1000000L)+t2.tv_usec)-((t1.tv_sec*1000000L)+t1.tv_usec)));
   
}
    
