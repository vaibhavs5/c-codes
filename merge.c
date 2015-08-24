#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int* aux,int beg,int mid,int end);
void mergesort(int *a,int *aux,int beg,int end)
{
    if(beg>=end)return ;
    int mid=(beg+end)/2;
    mergesort(a,aux,beg,mid);
    mergesort(a,aux,mid+1,end);
    merge(a,aux,beg,mid,end);
    
}

void merge(int *a,int* aux,int beg,int mid,int end)
{
    int i=beg,k=beg,j=mid+1;
    for(k=beg;k<=end;k++)
    {
        if(i>mid) aux[k]=a[j++];
        else if(j>end) aux[k]=a[i++];
        else if(a[i]<a[j]) aux[k]=a[i++];
        else aux[k]=a[j++];
    }
    for(k=beg;k<=end;k++)
    a[k]=aux[k];
}


int main()
{
    int n,*a,i,*aux;
    struct timeval t1,t2;

    printf("Enter size\n");
    scanf("%d",&n);

    a=(int *)malloc(n*sizeof(int));
    aux=(int *)malloc(n*sizeof(int));

    printf("\nenter elements\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    gettimeofday(&t1,NULL);

    mergesort(a,aux,0,n-1);

    gettimeofday(&t2,NULL);;

    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

    printf("\nTime elapsed:%ld\n",(((t2.tv_sec*1000000L)+t2.tv_usec)-((t1.tv_sec*1000000L)+t1.tv_usec)));
}
