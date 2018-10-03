#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

void SWAP_Seg(Segment &a, Segment &b)
{
  Segment temp=a;
  a=b;
  b=temp;
}

void Quick_sort(vector<Segment>&K, int s, int t)
{
  int i, j;
  if(s<t)
  {
    i=s;
    j=t+1;
    while(1){
      do i++;
      while(!(K[s].end<=K[i].end||i==t));
      do j--;
      while(!(K[s].end>=K[j].end||j==s));
      if(i<j)
        SWAP_Seg (K[i], K[j]);
      else
        break;
    }
    SWAP_Seg(K[s],K[j]);
    Quick_sort(K, s, j-1);
    Quick_sort(K, j+1, t);
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  Quick_sort(segments, 0, segments.size()-1);
  points.push_back(segments[0].end);
  for(int i=1; i<segments.size(); i++)
    if(segments[i].start>points.back())
      points.push_back(segments[i].end);
/*  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  */
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
