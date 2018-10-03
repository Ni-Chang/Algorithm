#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long Merge (vector<int>&X, int s, int u, int v)
{
  int i,j,q;
  i=s;
  j=u+1;
  q=0;
  long long number_of_inversions=0;
  vector<int>Z(v-s+1);
  while(i<=u&&j<=v)
    if(X[i]<=X[j])
      Z[q++]=X[i++];
    else
      {
        Z[q++]=X[j++];
        number_of_inversions+=u-s+1-i+s;
      }
  while(i<=u)
    Z[q++]=X[i++];
  while(j<=v)
    Z[q++]=X[j++];
  for(int k=0; k<v-s+1;k++)
      X[s+k]=Z[k];
    return number_of_inversions;
}

long long MergeSort(vector<int>&A, int s, int t)
{
  long long number_of_inversions=0;
  if(s<t)
  {
    int m=(t+s)/2;
    number_of_inversions+= MergeSort(A, s, m);
    number_of_inversions+=MergeSort(A, m+1, t);
    number_of_inversions+=Merge(A,s,m,t);
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << MergeSort(a, 0, a.size()-1) << '\n';
}

/*int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  MergeSort(a,0,a.size()-1);
  for(size_t i=0; i<a.size(); i++)
    std::cout << a[i] << ' ';
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right)
 {
  long long number_of_inversions=0;
  if(left==right)
    return number_of_inversions;
  size_t ave=(left+right)/2;
  vector<int>b(ave-left+1);
  vector<int>c(right-ave);
  for(int i=left; i<=ave; i++)
    b.push_back(a[i]);
  for(int i=ave+1; i<=right; i++)
    c.push_back(a[i]);
  number_of_inversions+= Merge(b, c);
  number_of_inversions+=get_number_of_inversions(a,left,ave);
  number_of_inversions+=get_number_of_inversions(a,ave,right);
  return number_of_inversions;
}

 long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  return number_of_inversions;




long long number(vector<int>a)
{long long inv=0; 
for(int i=0; i<a.size(); i++)
  for(int j=i+1; j<a.size(); j++)
    if(a[i]>a[j])
      inv++;
return inv;
}

*/
