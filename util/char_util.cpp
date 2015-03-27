#include "char_util.h"
#include <cstdlib>
#include <cstring>

bool CharUtil::compare(char * a, char * b, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(a[i] != b[i])
      return false;
  }

  return true;
}

char * CharUtil::add(char * target, char c, int size)
{
  char * newArray = new char[size + 1];
  if(size > 0) {
    memcpy(newArray, target, size + 1);
  }
  newArray[size] = c;
  return newArray;
}
