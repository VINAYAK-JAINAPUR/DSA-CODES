#include<stdio.h>
void recursion(int n)
{
   if(n>0)
   {
    for(int i=1;i<n;i=i*2)
    {
        printf("%d ",n);
    }
    recursion(n-1);
}

}
void main()
{
    int n;
    printf("enter n:- ");
    scanf("%d",&n);
    recursion(n);
}
