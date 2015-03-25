class Item
{
private:
  char * image_;
public:
  Item(char *);
  void render();
  char * getImageLine(int);
};
