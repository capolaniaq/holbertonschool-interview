#include "holberton.h"


int wildcmp(char *s1, char *s2)
{
  int i, j;
  
  i = 0;
  j = 0;
  
  while (*(s1 + i) != '\0')
  {
    if (*(s2 + j) == '*')
    {
      j++;
      while (*(s1 + i) != s2[j])
        i++;
    }
    else if (*(s1 + i) == *(s2 + j))
    {
      i++;
      j++;
    }
    else {
      return (0);
    }
    
  }
  
  return (1);
  
}