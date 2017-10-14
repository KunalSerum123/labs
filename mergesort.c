#include <stdio.h>
int arr[100];
void merge(int l,int r,int mid,int arr[])
{
    int itr=0,i=l,e=mid+1;
    int aux[100];
    while(i<=mid && e<=r)
    {
        if(arr[i]<=arr[e])
        aux[itr++]=arr[i++];
        else
        aux[itr++]=arr[e++];
    }

    while(i<=mid)
    aux[itr++]=arr[i++];
    while(e<=r)
    aux[itr++]=arr[e++];
    int j;
    for(j=0;j<itr;j++)
    arr[l+j]=aux[j];
}

void msort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        msort(arr,l,mid);
        msort(arr,mid+1,r);
        merge(l,r,mid,arr);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    msort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
    printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

