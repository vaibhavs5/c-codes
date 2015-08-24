#include<stdio.h>
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void cqsort(int arr[],int left,int right)
{
    if(left>=right) return;

    int last=left;
    int i;

    for(i=left+1;i<=right;i++)
        if(arr[i]<arr[left])
            swap(arr,i,++last);

    swap(arr,last,left);
    cqsort(arr,left,last-1);
    cqsort(arr,last+1,right);
}
int main()
{
    int a[]={5,4,3,2,1};
    int i;

    cqsort(a,0,4);

    for(i=0;i<=4;i++)
    printf("%d",a[i]);

return 0;
}

