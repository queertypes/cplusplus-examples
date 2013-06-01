#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class X>
void f(vector<X>& x)
{
	struct Less {
		bool operator() (const X& lhs, const X& rhs) {
			return lhs < rhs;
		}
	};

	sort(x.begin(), x.end(), Less());
}

int main()
{
	vector<int> x = {4,1,3,7,3,2};

	f(x);

	for (auto i : x) 
		cout << i << ",";
	cout << endl;
	
	return 0;
}
