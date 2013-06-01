#include <iostream>
#include <string>
using namespace std;

int main()
{
	string regular_expression = R"(\w\\\w)";
	string quoted_string = R"("Quoted string")";
	string parenthetical_string = R"*("(Parentheses)")*";
	
	cout << regular_expression << "\n"
			 << quoted_string << "\n"
			 << parenthetical_string << endl;

	return 0;
}
