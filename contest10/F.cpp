#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

signed main() {
    
    int N,io=0;
    cin>>N;
    int a[10000000];
    int b[10000000];
    for(int i=1; i<=N;i++) { cin>>a[i]>>b[i];}

    for(int i=1; i<=N; i++){
        if(a[i]==b[i]){
            io+=1;
            //cout<<io<<endl;
            if(io>=3) return cout<<"YES"<<endl,0;
        }
        else{
            io=0;
          }
    }
    cout<<"NO"<<endl;
    //cout << (io >= 3 ? "YES" : "NO") << "\n";
  return 0;
}