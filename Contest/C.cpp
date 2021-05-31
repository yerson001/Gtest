#include<iostream>
using namespace std;

int main(){

    long cont; cin>>cont;
    while(cont--){
        long a, b, n;
        cin>>a>>b>>n;
        long cnt(0);
        while(a <= n && b <= n){
            if(a < b){a += b;}
            else{b += a;}
            ++cnt;
        }

        cout<<cnt;
    }

    return 0;
}