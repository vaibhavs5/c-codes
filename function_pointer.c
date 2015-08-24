#include<stdio.h>
void swap(void* arr[],int i,int j)
{
    float* temp=(float*)arr[i];
    arr[i]=(float*)arr[j];
    arr[j]=temp;
}

void cqsort(void* arr[],int (*cmp)(void*,void*),int left,int right)
{
    if(left>=right) return;

    int last=left;
    int i;

    for(i=left+1;i<=right;i++)
        if((*cmp)(arr[i],arr[left])<0)
            swap(arr,i,++last);

    swap(arr,last,left);
    cqsort(arr,cmp,left,last-1);
    cqsort(arr,cmp,last+1,right);
}

int compareFloat(float* x,float* y)
{
    if(*x<*y)return -1;
    if(*x==*y)return 0;
    return 0;
}

int compareInt(int* x,int* y)
{
    if(*x<*y)return -1;
    if(*x==*y)return 0;
    return 0;
}
int main()
{
    int u=5,v=4,w=3,x=2,y=1,z=0;
    int* a[]={&u,&v,&w,&x,&y,&z};
    int i;

    cqsort((void**)a,(int(*)(void * , void *))compareInt,0,4);

    for(i=0;i<=4;i++)
    printf("%d\n",*a[i]);

return 0;
}

