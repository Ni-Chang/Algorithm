#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void SWAP_int(int &a, int &b){
  int temp=a;
  a=b;
  b=temp;
}

void Quick_sort(vector<int>&K, int s, int t)
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
          SWAP_int (K[i], K[j]);
      else
        break;
    }
    SWAP_int(K[s],K[j]);
    Quick_sort(K,s,j-1);
    Quick_sort(K,j+1,t);
  }
}

long long max_dot_product(vector<int> a, vector<int> b) {
  Quick_sort(a,0,a.size()-1);
  Quick_sort(b,0,b.size()-1);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
