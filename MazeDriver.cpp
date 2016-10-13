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
bool goNorth(Maze m, Creature bob);

/** Bag Driver - use to test Bag class methods and 
 * bag functions that are independent from the Bag class.
 **********************************************************/
int main()
{
  string filename;
  cout << "Please enter the filename of the maze> ";
  getline(cin, filename);
  Maze test = Maze(filename);
  test.display();
  return 0;            //Exit program
}//main()
/*
bool goNorth(Maze m, Creature bob)
{
  bool success = false;
  if(m.isPath(x, y - 1))
  {
    if(bob.getX() == m.getExitX() && bob.getY() == m.getExitY())
    {
      success = true;
    }
  }
  
}
*/
