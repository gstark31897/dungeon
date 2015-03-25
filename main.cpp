#include "global.h"
#include <cstdlib>
#include <iostream> 
#include <stdio.h>  
#include "item.h"

using namespace std;

int screenWidth = 5;
int screenHeight = 5;

void initialize()
{
  system("stty raw");
  system("stty -echo");
}

void fill_screen()
{
  system("clear");
  for(int y = 0; y < screenHeight; y++)
  {
    for(int x = 0; x < screenWidth; x++)
    {
      cout << "x";
    }
    cout << "\r\n";
  }
}

void size_screen()
{
  while(true)
  {
    switch(getchar())
    {
      case ENTER_KEY:
        return;
      case H_KEY:
        screenWidth--;
        break;
      case J_KEY:
        screenHeight++;
        break;
      case K_KEY:
        screenHeight--;
        break;
      case L_KEY:
        screenWidth++;
        break;
    }

    fill_screen();
  }
}

void cleanup()
{
  system("stty cooked");
  system("stty echo");
}

int main()
{ 
  initialize();

  Item * item;
  item = new Item("res/weapons/test.itm");
  item->render();
  //fill_screen();
  //size_screen();

  cleanup();
  return 0;
}
