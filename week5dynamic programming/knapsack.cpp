#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int> > value(w.size()+1);
  int i, j, val;
  for(i=0; i<value.size(); i++)
    value[i].resize(W+1);
  for(i=0; i<value.size(); i++)
    value[i][0]=0;
  for(j=0; j<=W; j++)
    value[0][j]=0;
  for(i=1; i<value.size(); i++)
    for(j=1; j<=W; j++)
    {
      value[i][j]=value[i-1][j];
      if(w[i-1]<=j)
      {
        val=value[i-1][j-w[i-1]]+w[i-1];
        if(value[i][j]<val)
          value[i][j]=val;
      }
    }
    return value[w.size()][W];
/*  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;*/
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
