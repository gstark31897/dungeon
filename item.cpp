#include "global.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Item::Item(char * filePath)
{
  image_ = new char[ITEM_IMAGE_HEIGHT * ITEM_IMAGE_WIDTH];
  char * line;
  ifstream myfile (filePath);
  
  char ch;
  fstream fin(filePath, fstream::in);
  while(fin >> noskipws >> ch)
  {
    line << ch;
    if(ch == ':')
      break;
  }
  cout << line;

  for(int i = 0; i < ITEM_IMAGE_HEIGHT * ITEM_IMAGE_WIDTH; i++)
  {
    fin >> noskipws >> ch;
    if(ch == '\n')
      i--;
    else
      image_[i] = ch;
  }
  myfile.close();
}

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
