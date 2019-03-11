// A C/C++ program for splitting a string
// using strtok()
#include <stdio.h>
#include <string.h>

int main()
{
  char str1[] = "pmo455:$1$GC$t2R7Ly1RLRgoF/FcgmZHo0:15420::::::";
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
    char str[] = "pmo455:x:1001:1001:Phyllis Marcellino,,,:/home/pmo455:/bin/ash";

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
  printf("%s",temp);

    return 0;
    }
