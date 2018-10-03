#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_min(int x, int y, int z)
{
	if(x<=y && x<=z)
		return x;
	else if(y<=z)
		return y;
	else
		return z;
}

vector<int> optimal_sequence(int n) {
  vector<int> sequence, operation(n+1);
  int min1, min2, min3, i;
  operation[0]=-1;
  operation[1]=0;
  for(i=2; i<=n; i++)
  {
  	min1=min2=min3=i;
  	min1=operation[i-1]+1;
  	if(i%2==0)
  		min2=operation[i/2]+1;
  	if(i%3==0)
  		min3=operation[i/3]+1;
  	operation[i]=find_min(min1, min2, min3);
  }
  i=n;
  while(i!=0)
  {
  	sequence.push_back(i);
  	if(i%3==0 && operation[i/3]+1==operation[i])
  		{i=i/3;continue;}
  	else if(i%2==0 && operation[i/2]+1==operation[i])
  		{i=i/2;continue;}
  	else
  		i=i-1;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
