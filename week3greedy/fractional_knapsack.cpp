#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void SWAP(double &a, double &b)
{
  double temp=a;
  a=b;
  b=temp;
}

void SWAP_int(int &a, int &b)
{
  int temp=a;
  a=b;
  b=temp;
}

void Quick_sort(vector<double>&K, vector<int>&m, int s, int t)
{
  int i, j;
  if(s<t)
  {
    i=s;
    j=t+1;
    while(1){
      do i++;
      while(!(K[s]<=K[i]||i==t));
      do j--;
      while(!(K[s]>=K[j]||j==s));
      if(i<j)
        {
          SWAP (K[i], K[j]);
          SWAP_int (m[i], m[j]);
        }
      else
        break;
    }
    SWAP(K[s],K[j]);
    SWAP_int(m[s],m[j]);
    Quick_sort(K,m,s,j-1);
    Quick_sort(K,m,j+1,t);
  }
}


double get_optimal_value(int n, int capacity, vector<int> weights, vector<int> values) 
{
  double value = 0.0;
  vector<double>a(n);
  for(int i=0;i<n;i++)
    a[i]=(double)values[i]/(double)weights[i];
  vector<int>m(n);
  for(int k=0; k<n; k++)
    m[k]=k;
  Quick_sort(a, m, 0, n-1);
  int j=n-1;
  while(capacity>=weights[m[j]]&&j>=0)
  {
    value+=(double)values[m[j]];
    capacity-=weights[m[j]];
    j--;
  }
  if(j>=0)
    value+=a[j]*capacity;
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}