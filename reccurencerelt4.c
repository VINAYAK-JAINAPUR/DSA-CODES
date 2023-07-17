#include<stdio.h>
void recursion(int n)
{
   if(n>0)
   {

    printf("%d ",n);
    recursion(n-1);
    recursion(n-1);

}
}
void main()
{
    int n;
    printf("enter n:- ");
    scanf("%d",&n);
    recursion(n);
}s
