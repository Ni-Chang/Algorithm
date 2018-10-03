#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

void change(string exp, vector<int>&num, vector<char>&ops)
{
  stringstream stoi;
  int i;
  for(i=0; i<exp.size(); i++)
  {
    if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*')
    {
      stoi<<exp[i];
      int a;
      stoi>>a;
      stoi.clear();
      num.push_back(a);
    }
    else
    {
      stoi<<exp[i];
      char b;
      stoi>>b;
      stoi.clear();
      ops.push_back(b);
    }
  }
}

long long find_max(long long v, long long w, long long x, long long y, long long z)
{
  if(v>=w && v>=x && v>=y && v>=z)
    return v;
  else if(w>=x && w>=y && w>=z)
    return w;
  else if(x>=y && x>=z)
    return x;
  else if(y>=z)
    return y;
  else
    return z;
}

long long find_min(long long v, long long w, long long x, long long y, long long z)
{
  if(v<=w && v<=x && v<=y && v<=z)
    return v;
  else if(w<=x && w<=y && w<=z)
    return w;
  else if(x<=y && x<=z)
    return x;
  else if(y<=z)
    return y;
  else
    return z;
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

vector<long long> MinAndMax(int i, int j, vector<char>ops, vector<vector<long long> >m, vector<vector<long long> >M)
{
  long long a, b, c, d;
  long long max=LLONG_MIN;
  long long min=LLONG_MAX;
  vector<long long> mM(2);

  for(int k=i; k<j; k++)
  {
    a=eval(M[i][k], M[k+1][j], ops[k]);
    b=eval(M[i][k], m[k+1][j], ops[k]);
    c=eval(m[i][k], M[k+1][j], ops[k]);
    d=eval(m[i][k], m[k+1][j], ops[k]);
    min=find_min(min, a, b, c, d);
    max=find_max(max, a, b, c, d);
  }
  mM[0]=min;
  mM[1]=max;
  return mM;
}

long long get_maximum_value(const string &exp) {
  vector<vector<long long> >m((exp.size()+1)/2);
  vector<vector<long long> >M((exp.size()+1)/2);
  vector<int>num;
  vector<char>ops;
  change(exp, num, ops);
  int i, j, s;
  for(i=0; i<m.size(); i++)
  {
    m[i].resize(m.size());
    M[i].resize(M.size());
  }
  for(i=0; i<m.size(); i++)
    m[i][i]=M[i][i]=num[i];
  for(s=1; s<m.size(); s++)
    for(i=0; i<m.size()-s; i++)
    {
      j=i+s;
      m[i][j]=MinAndMax(i, j, ops, m, M)[0];
      M[i][j]=MinAndMax(i, j, ops, m, M)[1];
    }
  return M[0][M.size()-1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
