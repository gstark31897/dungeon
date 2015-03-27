#include "global.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>
#include "util/char_util.h"

using namespace std;

Item::Item(char * filePath)
{
  image_ = new char[ITEM_IMAGE_HEIGHT * ITEM_IMAGE_WIDTH];

  ifstream myfile (filePath);  
  fstream fin(filePath, fstream::in);

  while(true)
  {
    char * tag = "";
    int size = 0;
    char ch;
    while(fin >> noskipws >> ch)
    {
      if(ch == ':')
      {
        break;
      }
      else
      {
        tag = CharUtil::add(tag, ch, size);
        size++;
      }
    }
    cout << "TAG:" << tag << "\r\n";
    if(CharUtil::compare("image", tag, size))
    {
      for(int i = 0; i < ITEM_IMAGE_HEIGHT * ITEM_IMAGE_WIDTH; i++)
      {
        fin >> noskipws >> ch;
        if(ch == '\n')
          i--;
        else
          image_[i] = ch;
      }
      fin >> noskipws >> ch;
    }
    else if(CharUtil::compare("end", tag, size))
    {
      break;
    }
  }
  myfile.close();
}
/*
bool Item::compareTag(char * target, char * input, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(target[i] != input[i])
      return false;
  }

  return true;
}

char * Item::addChar(char * target, char c, int size)
{
  char * newArray = new char[size + 1];
  if(size > 0) {
    memcpy(newArray, target, size + 1);
  }
  newArray[size] = c;
  return newArray;
}
*/
char * Item::getImageLine(int n)
{
  char * line = new char[ITEM_IMAGE_WIDTH];
  for(int x = 0; x < ITEM_IMAGE_WIDTH; x++)
  {
    line[x] = image_[n*ITEM_IMAGE_WIDTH + x];
  }

  return line;
}

void Item::render()
{
  for(int y = 0; y < ITEM_IMAGE_HEIGHT; y++)
  {
    cout << getImageLine(y) << "\r\n";
  }
}
