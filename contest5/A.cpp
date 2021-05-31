#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl

double a[100000];
vector<double> res;


int main() {
   int t;
   cin>>t;
  while(t--) 
  {
    int n,m;
    cin>>n>>m;
    double rpt(0);

    FORN(i,0,n){cin>>a[i];}
    sort(a,a+n);
    //FORN(i,0,n){debug(a[i]);}
    
    double j=1;
    FORN(i,0,n){
      double w = (double)(a[i]/(j));
      j++;
      res.push_back(w);
    }
    for(int i=0; i<n; i++) {
       double l(0),ll(0);
      for(int jj=0+i; jj<n; jj++){
        //debug(res[jj]);
           l = res[jj];
           ll+=l;
      }
      rpt+=ll;
      //debug(rpt);
    }
      if(rpt==m){
        cout<<"YES"<<endl;
      } else{
        cout<<"NO"<<endl;
      }
  }

  return 0;
}
