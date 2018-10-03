#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int x=0;
  int y=0;
  int a=0;
  int n = numbers.size();
  x=numbers[0];
  y=numbers[0];
  for (int i = 0; i < n; ++i) 
  {
    if (numbers[i]>x)
      {
        x=numbers[i];
        a=i;
      }
  }
  for (int j = 0; j < a||(j>a&&j<n); ++j) {
    if (numbers[j]>y) 
    {
        y=numbers[j];
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

    int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
  }
