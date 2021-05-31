#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

const int N = 5001;
int dp[N][3];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    debug(n);
    for(int i = 0 ; i < n; i++)
    {   
        dp[i+1][0] = dp[i][0]+(s[i] == 'a');
        dp[i+1][1] = max(dp[i][0], dp[i][1])+(s[i] == 'b');
        dp[i+1][2] = max(dp[i][1], dp[i][2])+(s[i] == 'a');
        
        FORN(ii,0,10){cout<<i<<" ";;
           FORN(jj,0,20){cout<<dp[ii][jj];}cout<<endl;
        }cout<<"---------"<<endl;
    
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl; 
    return 0;
}
