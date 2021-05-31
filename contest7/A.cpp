#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long
int A,B,f(40);
ll N,rpt; 

bool R(ll &N){
        
        FORN(A,0,f)
         FORN(B,0,f){
            rpt = pow(3,A)+pow(5,B);
            if(rpt == N) {
                cout<<A<<" "<<B<<endl;
               return 1;
            }
         }
    cout<<"-1"<<endl;     
    return 0;
 }
int main() {
  cin>>N;
  int r = R(N);
  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

int main() {
    int N,A,B;
    cin>>N>>A>>B;
    N=N-A;
    N=N+B;
    cout<<N<<endl;


  return 0;
}

*/