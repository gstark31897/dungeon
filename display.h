class Display
{
private:
  static int displayWidth_;
  static int displayHeight_;
public:
  static void initialize();
  static void setSize(int, int);
  static void render();
};
