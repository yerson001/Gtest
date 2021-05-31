#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long
ll a[1000000]; 
ll n;

void solve() {
    cin>>n;
    for(ll i=0; i<n; i++) { cin>>a[i]; }
    ll res = 1;
    for(int i=0; i<n; i++){ if(a[i]==0) cout<<0<<endl; return;}
    for(ll i=0; i<n; i++){
        res *=(ll)a[i]; 
    }
    if(res>=pow(10,18)){
        cout<<"-1"<<endl;
    }
    else{
        cout<<res<<endl;
    }
}
int main() {
    solve();


  return 0;
}
