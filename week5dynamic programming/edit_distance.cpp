#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_min(int w, int x, int y, int z)
{
	if(w<=x && w<=y && w<=z)
		return w;
	else if(x<=y && x<=z)
		return x;
	else if(y<=z)
		return y;
	else
		return z;
}

int edit_distance(const string &str1, const string &str2) {
  vector<vector<int> >distance(str2.size()+1);
  int i, j, insertion, deletion, match, dismatch;
  for(i=0; i<=str2.size(); i++)
  {
  	distance[i].resize(str1.size()+1);
  }
  for(i=0; i<=str2.size(); i++)
  	distance[i][0]=i;
  for(j=0; j<=str1.size(); j++)
  	distance[0][j]=j;
  for(j=1; j<=str1.size(); j++)
  	for(i=1; i<=str2.size(); i++)
  	{
  		insertion=deletion=match=dismatch=max(str1.size(),str2.size());
  		insertion=distance[i][j-1]+1;
  		deletion=distance[i-1][j]+1;
  		if(str1[j-1]==str2[i-1])
  			match=distance[i-1][j-1];
  		else
  			dismatch=distance[i-1][j-1]+1;
  		distance[i][j]=find_min(insertion, deletion, match, dismatch);
  	}
  return distance[str2.size()][str1.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
