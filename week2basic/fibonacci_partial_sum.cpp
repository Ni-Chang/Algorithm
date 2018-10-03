#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
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

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int j=mod_10_cycle ();
    int previous_from=0;
    int current_from=1;
    int previous_to=0;
    int current_to=1;

    for (int i=2; i<=(from+1)%j; i++){
        int tmp_previous_from=previous_from;
        previous_from=current_from;
        current_from=(tmp_previous_from+current_from)%10;
    }

    for (int i=2; i<=(to+2)%j; i++){
        int tmp_previous_to=previous_to;
        previous_to=current_to;
        current_to=(tmp_previous_to+current_to)%10;
    }
return (current_to-current_from+10)%10;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
