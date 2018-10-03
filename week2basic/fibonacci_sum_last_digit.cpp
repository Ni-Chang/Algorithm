#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int mod_10_cycle (){

    int previous=1;
    int current=1;
    int tmp_previous;
    int j=1;
    
    while(previous!=0||current!=1)
    {
        tmp_previous=previous;
        previous=current;
        current=(tmp_previous+current)%10;
        j++;
    }
    return j;
}

int fibonacci_sum_fast(long long n)
{
     if (n<=1)
        return n;
    int j=mod_10_cycle ();
    int previous=0;
    int current=1;

    for (int i=2; i<=(n+2)%j; i++){
        int tmp_previous=previous;
        previous=current;
        current=(tmp_previous+current)%10;
    }
    if (current==0)
        return 9;
    return (current-1);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n)<<"\n";
}
