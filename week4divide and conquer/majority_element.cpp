#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left + 1 == right) return a[left];
  /*int max_l=get_majority_element(a, left, (right+left)/2);
  int max_r=get_majority_element(a, (right+left)/2+1,right);*/
  if(get_majority_element(a, left, (right+left)/2)==get_majority_element(a, (right+left)/2+1,right))
    return get_majority_element(a, left, (right+left)/2);
  else
    {
      int count_a=0, count_b=0;
      for(int i=left; i<=right; i++)
      {
        if(a[i]==get_majority_element(a, left, (right+left)/2))
          count_a++;
        if(a[i]==get_majority_element(a, (right+left)/2+1,right))
          count_b++;
      }
      if(count_a>=(float)(right-left)/2+1)
        return get_majority_element(a, left, (right+left)/2);
      if(count_b>=(float)(right-left)/2+1)
        return get_majority_element(a, (right+left)/2+1,right);
    }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
