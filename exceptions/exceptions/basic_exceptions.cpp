/**
 * @file basic_exceptions.cpp
 * @author rangrot (rrangrot@gmail.com)
 * @brief file contains concepts of exceptions and 
 * error handling
 * 
 */

#include <iostream>

using namespace std;

/**
 * @brief 
 * 
 */
void might_go_wrong()
{
  bool error = true;
  if (error)
  {
    throw 8;
  }
}

/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
  try
  {
    might_go_wrong();
  }
  catch (int e)
  {
    cout<<"Error Code: "<<e<<endl;
  }

  cout<<"Test Out"<<endl;
  return 0;
}