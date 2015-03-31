#include "display.h"
#include <sys/ioctl.h>
#include <iostream>

int Display::displayHeight_ = 0;
int Display::displayWidth_ = 0;

void Display::initialize()
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  
  setSize(w.ws_col, w.ws_row-1);
}

void Display::setSize(int displayWidth, int displayHeight)
{
  displayWidth_ = displayWidth;
  displayHeight_ = displayHeight;
}

void Display::render()
{
  std::cout << "+";
  for(int x = 1; x < displayWidth_ - 1; x++)
  {
    std::cout << "-";
  }
  std::cout << "+\r\n";

  for(int y = 1; y < displayHeight_ - 1; y++)
  {
    std::cout << "|";
    for(int x = 1; x < displayWidth_ - 1; x++)
    {
      std::cout << " ";
    }
    std::cout << "|\r\n";
  }

  std::cout << "+";
  for(int x = 1; x < displayWidth_ - 1; x++)
  {
    std::cout << "-";
  }
  std::cout << "+\r\n";  
}
