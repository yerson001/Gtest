#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

int main() {
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    //if(max(A,C)<=min(B,D)){
    if(A>C){
        swap(A,C);
        swap(B,D);
        //cout<<"YES"<<endl;
    }
    if(C<=B){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

  return 0;
}
