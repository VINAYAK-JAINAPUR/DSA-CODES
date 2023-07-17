#include <stdlib.h>
#include<stdio.h>
#include <string.h>
void replacefile(char word[1000], char read[100], char rep[100]);
int main()
{

   char word[1000];
   char read[100];
   char rep[100]; printf("Enter word to be replaced\n");
    scanf("%s",read);
    printf("enter the word\n");
    scanf("%s",rep);
    FILE *p;
    p = fopen("bvb.txt","r");
    fscanf(p," %[^\n]%*c",&word);
    printf("%s",word);
    replacefile(word,read,rep);
    FILE *s;
    s = fopen("replaced.txt","w");
    fprintf(s,"%s",word);
}
void replacefile(char word[1000],char read[100],char rep[100])
{
 int l1 = strlen(read);
    int l2 = strlen(rep);
    int j=0,f=0,m=0;
    for(int i=0;word[i]!=EOF ;i++)
    {
        if(word[i]==read[j])
        {
            f++;
        }
        j++;
        if(f==l1)
        {
            m=j-f;
              for(int y=m;y<l2;y++)
              {
                word[y] = rep[y];
              }
        }
    }
}

