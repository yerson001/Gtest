#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

int main() {
  int n,s(0); cin>>n;
  set<ll> a;

  for(ll i=1; i*i<=n; i++) {
    if (n % i == 0){
      a.insert(n/i);
      a.insert(i);
      s += i;
    }
  }
  for(ll j:a){
    cout<<j<<endl;
  }


  return 0;
}
