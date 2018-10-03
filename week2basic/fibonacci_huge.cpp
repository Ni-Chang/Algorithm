#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    
    vector<long long>a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    int i=3;

    while (a[i-2]!=0||a[i-1]!=1)
    {
        a.push_back((a[i-2]%m+a[i-1]%m)%m);
        i++;
    }

    return a[n%(i-2)];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
