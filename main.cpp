#include "global.h"
#include "input.h"
#include "display.h"

#include "item.h"

int main()
{ 
  Input::initialize();

  Item * item;
  item = new Item("res/weapons/test.itm");
  item->render();

  Display::initialize();
  Display::render();

  Input::cleanup();
  return 0;
}
