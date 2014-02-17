#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main()
{
  vector<int> myvect{1,2,3,3,7,9};

  cout<<"If we wanted to insert a new number 3 in this array keepeing the array ordered:"<<endl;
  for(int n : myvect)
    cout<<n<<" ";
  cout<<endl;

  vector<int>::iterator pl=lower_bound(myvect.begin(),myvect.end(),3);
  vector<int>::iterator pu=upper_bound(myvect.begin(),myvect.end(),3);

  size_t l_pos=distance(myvect.begin(),pl);
  size_t u_pos=distance(myvect.begin(),pu);

  cout<<"We had to insert it from the position "<<l_pos-1<<" to "<< u_pos<<" both included"<<endl;



  return 0;
}
