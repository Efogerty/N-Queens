#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <tuple>

using namespace std;
int input = 0;
bool** chessBoard;
int solutions = 0;
bool isOdd;

bool checkCell(int x, int y)
{
  int tempX=x;
  int tempY=y;

  for(int i=0;i<x;i++)
  {
    if(chessBoard[i][y])
    {
      return false;
    }
  }
  for(tempX=x-1,tempY=y-1;tempX>=0&&tempY>=0;tempX--,tempY--)
  {
    if(chessBoard[tempX][tempY])
    {
      return false;
    }
  }
  for(tempX=x-1,tempY=y+1;tempX>=0&&tempY<input;tempX--,tempY++)
  {
    if(chessBoard[tempX][tempY])
    {
      return false;
    }
  }
  return true;
}

void checkRow(int x)
{
    //add to solutions if I'm at the last row
    if(x == input && x > 0)
    {
      //check symmetry
      if(isOdd!=true)
      {
        solutions+=2;
      }
      else
      {
        solutions++;
      }
      return;
    }
    else
    {
      //check first row for setting up symmetry
      if(x==0)
      {
        for(int col=0;col<input/2+input%2;col++)
        {
          //get through all rows before the middle for odd solutions
          if(input%2!=0 && col==input/2)
          {
            isOdd=true;
          }
          //recursively check rows every cell in the first row
          if(checkCell(x,col))
          {
            chessBoard[x][col] = true;
            checkRow(x+1);
            chessBoard[x][col] = false;
          }
        }
      }
    else
    {
      //recursively check each cell in rows 1 and greater
      for(int col=0;col<input;col++)
      {
        if(checkCell(x,col))
        {
          chessBoard[x][col] = true;
          checkRow(x+1);
          chessBoard[x][col] = false;
        }
      }
    }
  }
}
int main(int argc, char* argv[])
{
  input = atoi(argv[1]);
  chessBoard= new bool*[input];
  for(int i=0;i<input;i++)
  {
    chessBoard[i]=new bool [input];
  }

  for(int j=0;j<input;j++)
  {
    for(int k=0;k<input;k++)
      {
        chessBoard[j][k]=false;
      }
  }
  checkRow(0);
  cout<<solutions<<endl;
}
