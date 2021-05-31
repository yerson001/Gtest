#include<bits/stdc++.h>
using namespace std;

#define FORN(i, a, b) for(int i = (a); i < (b); i++)
#define FORN_(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define END cout<<endl;
#define ll long long

int main()
{
    int a,b,c,d,sum,res;
    cin>>a>>b>>c>>d;
    sum = min(a,b);
    res = min(c,d);
    cout<<min(sum,res);


    return 0;
}
