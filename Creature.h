// @author Tyler Fricks
// Version 42

#include <string>
#ifndef CREATURE_
#define CREATURE_
class Creature
{
private:
  int posX;
  int posY;
public:
  Creature();
  Creature(int startX, int startY);
  int getX() const;
  int getY() const;
  void setX(int y);
  void setY(int x);
  
}; // end Creature
#endif