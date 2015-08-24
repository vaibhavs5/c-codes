#include<stdio.h>

int main(int argc,char* argv[])
{
    int i,n,num=1,j;

    sscanf(argv[1],"%d",&n);

    for(i=0;i<n;i++)
    {
	for(j=0;j<i+1;j++)
        {
            printf("%d",num);
    }
    return 0;
}
