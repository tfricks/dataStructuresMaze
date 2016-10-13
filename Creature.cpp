#include "Creature.h"
Creature :: Creature()
{
  
}
Creature :: Creature(int startX, int startY)
{
  posX = startX;
  posY = startY;
}
int Creature :: getX() const
{
  return posX;
}
int Creature :: getY() const
{
  return posY;
}
void Creature :: setX(int x)
{
  posX = x;
}
void Creature :: setY(int y)
{
  posY = y;
}