#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Pair
{
	int num;
	char let;
	int pos;
};

vector<int> partition3 (vector<Pair> &a, int l, int r)
{
	int x=a[l].num;
	int m1=l, m2=l;
	for(int i=l+1; i<=r; i++)
	{
		if(a[i].num<x)
		{
			m1++;
			m2++;
			swap(a[i],a[m2]);
			swap(a[m1],a[m2]);
		}
		else if (a[i].num==x)
		{
			m2++;
			swap(a[i],a[m2]);
		}
	}
	swap(a[l],a[m1]);
/*	int s=m1;
	int e=m2;
	for(int i=m1; i<=m2; i++)
	{
		if(a[i].let=='a')
		{
			swap(a[i],a[s]);
			s++;
		}
		else if(a[i].let=='c')
		{
			swap(a[i],a[m2]);
			e--;
		}
	}*/
	vector<int>m(2);
	m[0]=m1;
	m[1]=m2;
	return m;
}

void count_sort(vector<Pair>&a, int l, int r)
{
	int i;
	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	vector<int> b_number;
	for (i = l; i <= r; i++)
	{
		if (a[i].let == 'a')
			cnt_a++;
		if (a[i].let == 'b')
		{
			cnt_b++;
			b_number.push_back(a[i].pos);
		}
		if (a[i].let == 'c')
			cnt_c++;
	}
	i = l;
	int j = 0;
	while (cnt_a != 0)
	{
		a[i].let = 'a';
		cnt_a--;
		i++;
	}
	while (cnt_b != 0)
	{
		a[i].let = 'b';
		a[i].pos = b_number[j];
		j++;
		cnt_b--;
		i++;
	}
	while (cnt_c != 0)
	{
		a[i].let = 'c';
		cnt_c--;
		i++;
	}
}

void randomized_quick_sort (vector<Pair> &a, int l, int r) 
{
	if (l >= r)
		return;
	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	vector<int> m = partition3(a, l, r);
	randomized_quick_sort (a, l, m[0] - 1);
	randomized_quick_sort (a, m[1] + 1, r);
	count_sort (a, m[0], m[1]);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) 
{
	vector<int>cnt(points.size());
	vector<Pair> p_2s(points.size()+2*starts.size());
	for(int i=0; i<points.size();i++)
	{
		p_2s[i].let='b';
		p_2s[i].num=points[i];
		p_2s[i].pos=i;
	};
	for(int i=0; i<starts.size();i++)
	{
		p_2s[i+points.size()].let='a';    
		p_2s[i+points.size()].num=starts[i];
	}
	for(int i=0; i<starts.size();i++)
	{
		p_2s[i+points.size()+starts.size()].let='c';
		p_2s[i+points.size()+starts.size()].num=ends[i];
	}
	randomized_quick_sort(p_2s, 0, points.size()+2*starts.size()-1);
	int start_count=0;
	int end_count=0;
	for(int i=0; i<points.size()+2*starts.size(); i++)
	{
		if(p_2s[i].let=='a')
			start_count++;
		else if(p_2s[i].let=='c')
			end_count++;
		else
			cnt[p_2s[i].pos]=start_count-end_count;
	}
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		for (size_t j = 0; j < starts.size(); j++) {
			cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
		}
	}
	return cnt;
}

int main() {
	/*while(1)
	{
		int n=rand()%5+1;
		int m=rand()%5+1;
		cout << n << " "<<m<<"\n";
		vector<int> starts(n), ends(n);
		for (size_t i = 0; i < starts.size(); i++) {
			starts[i]=rand()%200000001-100000000;
			ends[i]=rand()%(100000000-starts[i]+1)+starts[i];
		}
		vector<int> points(m);
		for(size_t i = 0; i < points.size(); i++){
			points[i]=(rand()%200000001-100000000);
		}
		vector<int> res1(points.size());
		res1 = fast_count_segments(starts, ends, points);
		vector<int>res2(points.size());
		res2=naive_count_segments(starts, ends, points);
		if(res1!=res2){
			cout << "wrong answer: " ;
			for(size_t i=0;i<points.size();i++)
				cout<< res1[i] << ' ';
			cout<<"\n";
			for(size_t i=0;i<points.size();i++)
				cout<< res2[i] << ' ';
			cout<<"\n";
			break;
		}
		else{
			cout<<"OK"<<"\n";
		}
	}*/
int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  vector<int> results (points.size());
  results= fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < results.size(); i++) {
    std::cout << results[i] << ' ';
  }
}
