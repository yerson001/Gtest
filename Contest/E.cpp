#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        std::set<long> arr;
        for(long p = 0; p < n; p++){
            long x;
             scanf("%ld", &x);arr.insert(x);
        }
        printf("%ld\n", arr.size());
    }

    return 0;
}