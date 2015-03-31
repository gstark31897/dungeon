#include "input.h"

void Input::initialize()
{
  system("stty raw");
  system("stty -echo");
}

void Input::cleanup()
{
  system("stty cooked");
  system("stty echo");
}
