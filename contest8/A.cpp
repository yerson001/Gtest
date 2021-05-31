#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

int main() {
    string S;
    cin>>S;
    debug(S.size());
    debug(S[S.size()-1]);
    if(S[S.size()-1]=='s'){
        S+="es";
        cout<<S<<endl;
    }
    else{
        S+="s";
        cout<<S<<endl;
    }

  return 0;
}
