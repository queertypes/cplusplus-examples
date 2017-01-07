/*
This is open source software.

Show the use of the class 'stringstream' 
of the Standard Template Library to convert
a string in to a int,float

 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
  cout<<"\033[0;33m";//changes atributes to yellow color

  cout<<"\nWrite a number: ";
  char c_style_number[10];
  cin>>c_style_number;
  cout<<"Your number has been stored as an array of chars."<<endl;

  //creates an object of the class string (STL)
  string string_number(c_style_number);

  cout<<"\nNow your number has been converted to a string STL: " <<string_number<<endl;
  //the object 'convert' will get an string and return a float
  stringstream convert;

  convert<<string_number;//get the string
  float float_number=0.0f;
  convert>>float_number;//returns a float
  cout<<"\nNow you number is converted as float by STRINGSTREAM: "<<float_number<<endl<<endl;

  cout<<"\033[0;0m";//changes to white color

  return 0;
}
