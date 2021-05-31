#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define S_I(s) atoi(s.c_str()) 
#define I_S(s) to_string(s)

int main() 
{
    int t; cin>>t;
    while(t--)
    {
        string d,s;
        int cnnt(0),yes(0);
        cin>>d;
        FORN(i,1,10) {
            if(yes==0){
                s = I_S(i);
                int cnt(0);
               
                FORN(j,1,5){
                     debug(s);
                    if(s==d){
                        yes = 1;
                         debug(j);
                         cnt+=j;
                        break;
                    }else{
                            s+=I_S(i);
                            //debug(j);
                            cnt+=j;
                       }
                    }
                s.clear();
                cnnt+=cnt;
            }else{
                cout<<cnnt<<endl;
                break;
            }
        }
    }

 return 0; 
}
