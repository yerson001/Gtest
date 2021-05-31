#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
 
int main() 
{
    int t; cin>>t;
    while(t--)
    {
       int l,r,i=1; cin>>l>>r;
        for( ; i<l+r; i++)
        {
            int res = (l%i)+(i/2)+(r%i)+(i/2);
            if(res>=2*i)//l*2>r
            {
               cout<<"YES\n";
               break;
            }
        }
        //debug(i);
        //debug(l+r);
        if(i==l+r){
            cout<<"NO\n";  
        }

    }
       return 0; 
}
