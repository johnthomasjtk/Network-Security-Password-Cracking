#include <stdio.h>
#include <string.h>
#include <crypt.h>
int main()
{
  char c[1000],*temp,d[1000];
  FILE *fptr,*fptr1,*fptr2,*fptr3;
  fptr = fopen("top250.txt", "r");
  fptr1= fopen("runall.txt","w");
  fptr3=fopen("output.txt","w");
  int cnt=0;

  while (fgets(c,1000,fptr))
{
  char str1[1000];
  strcpy (str1,c);
  // Returns first token
  char *token = strtok(str1, "\t\n");
  int i=0;
  char var[20];
  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != NULL)
  {
  if(i==3)
  {
      //printf("%s\n", token);
      strcpy (var,token);
    }
      token = strtok(NULL, "\t\n");

  i++;
  }
temp = crypt(var,"$1$GC");
//printf("%s",var);
fputs(temp,fptr1);
fputs("\n",fptr1);
fptr2= fopen("password.txt","r");
while(fgets(d,1000,fptr2))
{
  char str1[1000];
  strcpy (str1,d);
  // Returns first token
  char *token = strtok(str1, ":");
  int i=0;
  char var1[20],var2[20];
  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != NULL)
  {
  if(i==0)
  {
      //printf("%s\n", token);
      strcpy (var1,token);
    }
    if(i==1)
    {
        //printf("%s\n", token);
        strcpy (var2,token);
      }
      token = strtok(NULL, ":");

  i++;
}//printf ("%s:%s\n",var1,temp);
  if (strcmp(var2,temp)==0){
    cnt++;
    printf ("%d:%s:%s\n",cnt,var1,var);
    fputs(var1,fptr3);
    fputs(":",fptr3);
    fputs(var,fptr3);
    fputs("\n",fptr3);
  }
}
fclose (fptr2);
}

//printf("%s",temp);
    return 0;
    }
