#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){

    LL n(0), k(0);
    cin>>n>>k;
    if(n == 1)
        puts("0");
    else if(n <= k){
        puts("1");
        }
    else if(n > k * (k - 1) / 2 + 1){
        puts("-1");
    } else{
        LL Linf(1), Lsup(k - 1), mid(1);
        LL subtr = 1 + k * (k - 1) / 2;
        LL test = subtr - (mid * (mid - 1))/2;
        while(Linf + 1 < Lsup){
            mid = (Linf + Lsup) / 2;
            test = subtr - (mid * (mid - 1))/2;

            if(test == n){Lsup = mid; break;}
            else if(test > n){Linf = mid;}
            else if(test < n){Lsup = mid;}
        }

        LL output(0);
        if(test < n){output = k - mid + 1;}
        else if(test >= n){output = k - mid;}

        cout<<output;
    }

    return 0;
}