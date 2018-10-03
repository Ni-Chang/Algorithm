#include <iostream>
#include <vector>

using std::vector;

int max(int x, int y, int z)
{
	if(x>=y && x>=z)
		return x;
	else if(y>=z)
		return y;
	else
		return z;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<vector<vector<int> > >com_seq(a.size()+1);
  int i, j, k;
  for(i=0; i<=a.size(); i++)
  	com_seq[i].resize(b.size()+1);
  for(i=0; i<=a.size(); i++)
  {
  	for(j=0; j<=b.size(); j++)
  		com_seq[i][j].resize(c.size()+1);
  }
  for(i=0; i<=a.size(); i++)
  	com_seq[i][0][0]=0;
  for(j=0; j<=b.size(); j++)
  	com_seq[0][j][0]=0;
  for(k=0; k<=c.size(); k++)
  	com_seq[0][0][k]=0;
  for(i=1; i<=a.size(); i++)
  	for(j=1; j<=b.size(); j++)
  		for(k=1; k<=c.size(); k++)
  		{
  			if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
  				com_seq[i][j][k]=com_seq[i-1][j-1][k-1]+1;
  			else
  				com_seq[i][j][k]=max(com_seq[i-1][j][k], com_seq[i][j-1][k], com_seq[i][j][k-1]);
  		}
  return com_seq[a.size()][b.size()][c.size()];
//  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
