#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main() {
    ll n,d;
    cin>>n>>d;
    ll t;
    cin>>t;
    while(t--) {
      ll x,y;
      cin>>x>>y;
      if((x+y-d>=0) && (x-y-d)<=0 && (x+y-2*n+d)<=0 && (x-y+d)>=0 )
        cout <<"YES"<<endl;
      else
         cout <<"NO"<<endl;
    }
   
    return 0;
}