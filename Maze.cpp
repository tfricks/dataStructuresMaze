#include "Maze.h"
Maze :: Maze(string filename)
{  
  ifstream fin;
  fin.clear();
  fin.open(filename.c_str());
  string holder;                            // temp var
  getline(fin, holder);                     // read in maze size
  stringstream(holder) >> cols >> rows;     // store maze size
  getline(fin, holder);                     // read in exit location
  stringstream(holder) >> exitY >> exitX;   // store exit location
  getline(fin, holder);                     // read in enter location
  stringstream(holder) >> enterY >> enterX; // store enter location
  mazeArrayPtr = new string[rows];          // alloc memory for 2d maze array
  visitedArrayPtr = new bool*[rows];        // alloc memory for 2d bool array
  
  bool failed = false;
  for(int i = 0; i < rows; i++)             // read everything in
  {
    getline(fin, holder);
    visitedArrayPtr[i] = new bool[cols];
    for(int j = 0; j < cols; j++)
    {
      mazeArrayPtr[i][j] = holder[j];
      visitedArrayPtr[i][j] = false;
    }
  }
  
  if((mazeArrayPtr[exitY][exitX] != " ") && (exitY != 0 || exitY != rows - 1 && exitX != 0 || exitX != cols)) failed = true;
  
  fin.close();
  creatureX = enterX;                       // set initial pos for creature
  creatureY = enterY;
  }
Maze :: ~Maze()
{  
  delete[] mazeArrayPtr;
  for(int i = 0; i < rows; i++)
  {
    delete[] visitedArrayPtr[i];
  }
  delete[] visitedArrayPtr;
}
bool Maze :: isWall(int x, int y)
{
  return true;
}
bool Maze :: isPath(int x, int y)
{
  return false;
}
int Maze :: getEnterX()
{
  return enterX;
}
int Maze :: getEnterY()
{
  return enterY;
}
int Maze :: getExitX()
{
  return exitX;
}
int Maze :: getExitY()
{
  return exitY;
}
void Maze :: markPath(int x, int y)
{
  if(x < cols && y < rows)
  {
      visitedArrayPtr[x][y] = true;
  }
}
bool Maze :: getVisited(int x, int y)
{
  if(x < cols && y < rows)
  {
    return visitedArrayPtr[x][y];
  }
    return false;
}
void Maze :: setCreaturePos(int x, int y)
{
  if(x < cols && y < rows)
  {
    creatureX = x;
    creatureY = y;
  }
}
void Maze :: display()
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(!visitedArrayPtr[i][j])
        cout << mazeArrayPtr[i][j];
      else 
        cout << ".";
      cout << " ";
    }
    cout << endl;
    }
}