#include <fstream>

class Item
{
private:
  char * image_;
public:
  Item(char *);
  char * addChar(char *, char, int);
  bool compareTag(char *, char *, int);
  void render();
  char * getImageLine(int);
};
