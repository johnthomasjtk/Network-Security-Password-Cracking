#include <stdio.h>
#include <stdlib.h>
#include <string.h>// For exit() function
int main()
{
    char c[1000],c1[1000];
    FILE *fptr,*fptr1,*fptr3;

  fptr = fopen("training-shadow.txt", "r");
  fptr1 = fopen("training-passwd.txt", "r");
  fptr3= fopen("password.txt","w");
int y = 8196;
while (y)
{

    // reads text until newline
    //fscanf(fptr,"%[^\n]", c);
    fgets(c,1000,fptr);
      char str1[1000];// = "pmo455:$1$GC$t2R7Ly1RLRgoF/FcgmZHo0:15420::::::";
      strcpy (str1,c);
      // Returns first token
      char *token = strtok(str1, ":");
      int i=0;
      char var[20];
      // Keep printing tokens while one of the
      // delimiters present in str[].
      while (token != NULL)
      {
      if(i==1)
      {
          //printf("%s\n", token);
          strcpy (var,token);
        }
          token = strtok(NULL, ":");

      i++;
      }

    // reads text until newline
    //fscanf(fptr1,"%[^\n]", c1);
    fgets(c1,1000,fptr1);
    char str[1000];// = "pmo455:x:1001:1001:Phyllis Marcellino,,,:/home/pmo455:/bin/ash";
    strcpy (str,c1);
    // Returns first token
    char *token1 = strtok(str, ":");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    char temp[1000];
    strcpy (temp,"");
    while (token1 != NULL)
    {
      if (strcmp (token1,"x")!=0)
      {
      //printf("%s\n", token1);
      strcat(temp,token1);
      strcat(temp,":");
      }
      else
      {
        //printf("%s", var);
        strcat(temp,var);
        strcat(temp,":");
      }

        token1 = strtok(NULL, ":");

    }
  printf("%s \n",temp);
  fputs(temp,fptr3);
  y--;
}

    fclose(fptr);
    return 0;
}
