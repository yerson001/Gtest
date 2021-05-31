#include <iostream>
using namespace std;

int main(){

    long n; cin>>n;

    int maxp = 0;
    while(n--){
        int k, a;cin>>k>>a;
        int m(0), t(1);
        while(t < a){t *= 4; ++m;}
        if(maxp < k + m){maxp = k + m;}
        if(maxp == k){++maxp;}
    }

    cout<<maxp<<endl;

    return 0;
}