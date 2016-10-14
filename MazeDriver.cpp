/** @file BagDriver.cpp
 * Bag Driver - use to test Bag class methods and 
 *  functions that are independent from the Bag class.
 *  Bags 1 & 2 are used troughout, bag 0 is extra for testing
 *                                
 * @author  Jeff Braun             
 * @version 0.91
 * @date 8/30/16
 **********************************************************/

//-----------------------
// C++ includes
//-----------------------
#include <iostream>
#include <fstream>
#include <string>

//-----------------------
// Application includes
//-----------------------
#include "Creature.h"
#include "Maze.h"

//-----------------------
// Using statements
//-----------------------
using namespace std;

//----------------------
// Functions Prototypes
//----------------------
bool goNorth(Maze &m, Creature &bob);
bool goSouth(Maze &m, Creature &bob);
bool goEast(Maze &m, Creature &bob);
bool goWest(Maze &m, Creature &bob);

/** Bag Driver - use to test Bag class methods and 
 * bag functions that are independent from the Bag class.
 **********************************************************/
int main()
{
  string filename;
  cout << "Please enter the filename of the maze> ";
  getline(cin, filename);
  Maze m = Maze(filename);
  //m.display();
  Creature bob = Creature(m.getEnterX(), m.getEnterY());
  m.markPath(bob.getX(), bob.getY());
  bool startWin = (bob.getX() == m.getExitX() && bob.getY() == m.getExitY());
  if(!startWin)
  {
    goNorth(m, bob);
    goSouth(m, bob);
    goEast(m, bob);
    goWest(m, bob);
  }
  m.display();
  if((bob.getX() == m.getExitX() && bob.getY() == m.getExitY()) || startWin)
  {
    cout << "Maze exit found!!" << endl;
  }
  else
  {
    cout << "No solution" << endl; 
  }
}//main()

bool goNorth(Maze &m, Creature &bob)
{
  bool success;
  //bool moved = false;
  if(m.isPath(bob.getX(), bob.getY() - 1))
  {
    cout << "test " << endl;
    bob.setY(bob.getY() - 1);
    m.markPath(bob.getX(), bob.getY());
    m.display();
    if(bob.getX() == m.getExitX() && bob.getY() == m.getExitY())
    {
      success = true;
    }
    else
    {
      success = goNorth(m, bob);
      if(!success)
      {
        success = goEast(m, bob);
        if(!success)
        {
          success = goWest(m, bob);
          if(!success)
          {
            m.markVisited(bob.getX(), bob.getY());
            bob.setY(bob.getY() + 1);
          }
        }
      }
    }
  }
  else
  {
    success = false;
  }
  return success;
}

bool goSouth(Maze &m, Creature &bob)
{
      bool success;
  //bool moved = false;
  if(m.isPath(bob.getX(), bob.getY() + 1))
  {
    bob.setY(bob.getY() + 1);
    m.markPath(bob.getX(), bob.getY());
    m.display();
    if(bob.getX() == m.getExitX() && bob.getY() == m.getExitY())
    {
      success = true;
    }
    else
    {
      success = goSouth(m, bob);
      if(!success)
      {
        success = goEast(m, bob);
        if(!success)
        {
          success = goWest(m, bob);
          if(!success)
          {
            m.markVisited(bob.getX(), bob.getY());
            bob.setY(bob.getY() - 1);
          }
        }
      }
    }
  }
  else
  {
    success = false;
  }
  return success;
}
bool goEast(Maze &m, Creature &bob)
{
    bool success;
  if(m.isPath(bob.getX() + 1, bob.getY()))
  {
    bob.setX(bob.getX() + 1);
    m.markPath(bob.getX(), bob.getY());
    m.display();
    if(bob.getX() == m.getExitX() && bob.getY() == m.getExitY())
    {
      success = true;
    }
    else
    {
      success = goEast(m, bob);
      if(!success)
      {
        success = goNorth(m, bob);
        if(!success)
        {
          success = goSouth(m, bob);
          if(!success)
          {
            m.markVisited(bob.getX(), bob.getY());
            bob.setX(bob.getX() - 1);
          }
        }
      }
    }
  }
  else
  {
    success = false;
  }
  return success;
}
bool goWest(Maze &m, Creature &bob)
{ 
  bool success;
  if(m.isPath(bob.getX() - 1, bob.getY()))
  {
    bob.setX(bob.getX() - 1);
    m.markPath(bob.getX(), bob.getY());
    m.display();
    if(bob.getX() == m.getExitX() && bob.getY() == m.getExitY())
    {
      success = true;
    }
    else
    {
      success = goWest(m, bob);
      if(!success)
      {
        success = goSouth(m, bob);
        if(!success)
        {
          success = goNorth(m, bob);
          if(!success)
          {
            m.markVisited(bob.getX(), bob.getY());
            bob.setX(bob.getX() + 1);
          }
        }
      }
    }
  }
  else
  {
    success = false;
  }
  return success;
}
