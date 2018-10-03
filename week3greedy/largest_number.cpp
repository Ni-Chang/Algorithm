#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool IsGreater(string dight, string maxDigit)
{
	 if(dight+maxDigit>maxDigit+dight)
	 	return true;
	 else
	 	return false;

}

string largest_number(vector<string> a) {
	string max;
  for(int i=0; i<a.size(); i++)
  	for(int j=i+1; j<a.size(); j++)
  		if(IsGreater(a[j],a[i])==1)
  		{
  			max=a[j];
  			a[j]=a[i];
  			a[i]=max;
  		}
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
