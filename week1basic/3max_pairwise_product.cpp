#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) 
{
  long long result = 0;
  int n = numbers.size();
  long long x=-1;
  long long y=-1;
  int a=0;
  for (int i = 0; i < n; ++i) 
  {
    if (numbers[i]>x)
      {
        x=numbers[i];
        a=i;
      }
  }
  if (a!=0)
  {
    for (int j = 0; j < a; ++j) 
    {
      if (numbers[j]>y) 
      {
        y=numbers[j];
      }
    }
    for(int j=a+1; j<n; ++j)
    {
     if (numbers[j]>y) 
      {
        y=numbers[j];
      } 
    }
  }
  else
  { 
    for (int j=1; j<n; ++j)
    {
      if (numbers[j]>y)
      {
        y=numbers[j];
      }
    }
  }
    result=x*y;
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(vector<int>(200000,0));
    cout << result << "\n";
    return 0;
  }
