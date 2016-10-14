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
  
  //bool failed = false;
  for(int i = 0; i < rows; i++)             // read everything in
  {
    getline(fin, mazeArrayPtr[i]);
  }
  
  //if((mazeArrayPtr[exitY][exitX] != " ") && (exitY != 0 || exitY!= rows - 1 && exitX != 0 || exitX != cols)) failed = true;
  
  fin.close();
  }
Maze :: ~Maze()
{  
  delete[] mazeArrayPtr;
}
bool Maze :: isWall(int x, int y)
{
  return true;
}
bool Maze :: isPath(int x, int y)
{
  //cout << "testasdf" << endl;
  if(x < cols && x >= 0 && y >= 0 && y < rows)
  {
    //cout << "test" << endl;
    return mazeArrayPtr[y][x] == ' ';
  }
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
void Maze :: markVisited(int x, int y)
{
  if(x < cols && x >= 0 && y >= 0 && y < rows)
  {
      mazeArrayPtr[y][x] = '.';
  }
}
void Maze :: markPath(int x, int y)
{
  if(x < cols && x >= 0 && y >= 0 && y < rows)
  {
      mazeArrayPtr[y][x] = 'O';
  }
}

void Maze :: display()
{
  system("clear");
  
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
        cout << mazeArrayPtr[i][j] << " ";
    }
    cout << endl;
  }
  
  usleep(250000);
}