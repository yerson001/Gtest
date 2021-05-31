#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

int main() {
  int t,tem;
  ll M(0),E(0),C(0);
  cin>>t;
  vector<ll> arr(t);
  vector<ll> v(t);
  
  FORN(i,0,t){cin>>arr[i];}

  FORN(i,0,t){
    M += abs(arr[i]);
    E += pow(abs(arr[i]),2);
    v.push_back(abs(arr[i]));
    //sin arr  C = max(C,abs(nn));
   }
  
   cout<<fixed<<setprecision(15);
   cout<<M<<endl;
   cout<<sqrt(E)<<endl;
   cout<<*std::max_element(v.begin(), v.end())<<endl;


  return 0;
}
