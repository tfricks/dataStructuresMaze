// @author Tyler Fricks
// Version 42

#ifndef MAZE_
#define MAZE_
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "unistd.h"
using namespace std;
class Maze
{
private:
  int cols;
  int rows;
  int enterX;
  int enterY;
  int exitX;
  int exitY;
  string* mazeArrayPtr;
  
public:
  Maze(std::string filename);
  virtual ~Maze();
  bool isWall(int x, int y);
  bool isPath(int x, int y);
  int getEnterX();
  int getEnterY();
  int getExitX();
  int getExitY();
  void markPath(int x, int y);
  void markVisited(int x, int y);
  bool getVisited(int x, int y);
  void display();
}; // end Maze
#endif
