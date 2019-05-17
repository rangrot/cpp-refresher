/**
 * @file exceptions_concepts.cpp
 * @author rangrot (rrangrot@gmail.com)
 * @brief file contains concepts of exceptions and
 * error handling
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief A function where errors can occur
 * Multiple errors can occur in this function
 * handling three types now, int, const char *, string object
 */
void might_go_wrong()
{
  // Setting these errors to true will catch that specific error.
  // Set only one error to true for now.
  bool error1 = false;
  bool error2 = false;
  bool error3 = true;
  if (error1)
  {
    // This throws an int value and is handled by an int. Could be used as error codes.
    // Works for Hex too.
    throw 0x8E;
  }

  if (error2)
  {
    // This creates a primitive c string and needs to be handled that way.
    throw("Error 2");
  }

  if (error3)
  {
    // This creates a string object and needs to be handled that way.
    throw string("Error 3");
  }
}

/**
 * @brief Test the function which throws an exception.
 * The throw will continue to be "thrown" according to the call stack
 * exceptions can be handled anywhere from the bottom most function in the stack to main
 * as shown in this example.
 */
void test_might_go_wrong()
{
  might_go_wrong();
}

/**
 * @brief Catch the exceptions thrown in might_go_wrongs
 *
 */
void catch_basic_exceptions()
{
  try
  {
    test_might_go_wrong();
  }
  catch (int e)
  {
    // Prints a hex number
    cout << "Error Code: " << hex << "0X" << e << endl;
    // Prints an int
    cout << "Error Code: " << e << endl;
  }
  catch (const char *e)
  {
    cout << "Error Str: " << e << endl;
  }
  catch (string e) // This can be caught as a reference too (string &e)
  {
    cout << "Error Str: " << e << endl;
  }
}

// global variable to catch user input
int num;

/**
 * @brief Class Will_go_wrong
 * Allocates a absurdly huge memory which should trigger a standard cpp exception from the constructor.
 */
class Will_go_wrong
{
public:

  // Standard cpp exceptions can be used to catch memory allocation and other issues in constructors etc.
  Will_go_wrong()
  {
    // The compiler won't allow me to allocate directly a huge number in the array
    // So I take the user input in num and pass it along here, the compiler doesn't know s**t what happens at run time.
    char *p_memory = new char[num];
    delete[] p_memory;
  }
};

/**
 * @brief Test will_go_wrong class
 * 
 */
void test_will_go_wrong()
{
  cout << "enter a absurdly large number to allocate memory" << endl;
  cin >> num;
  try
  {
    Will_go_wrong wrong;
  }
  catch (bad_alloc &e)
  {
    cout << "Exception caught" << e.what() << endl;
  }
}

/**
 * @brief main
 *
 * @return int
 */
int main()
{
  //catch_basic_exceptions();

  test_will_go_wrong();
  cout << "Program End!" << endl;
  return 0;
}
