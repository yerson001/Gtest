#include<bits/stdc++.h>

#define per(i,a,n) for (int i=n;i>=a;i--)
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define FORN_(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long
#define N 105
using namespace std;

ll t,n,m,a[N][N],dp[N][N];
ll solve(int x)
{
  memset(dp,0,sizeof dp);
  if(a[1][1] < x) return INFINITY;
  else dp[1][1] = a[1][1]-x; 
  FORN_(i,1,n)
  {
    FORN_(j,1,m)
    {
      if(i==1&&j==1) continue;
      ll h = x+(i-1)+(j-1);
      if(a[i][j] < h) continue;
      dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j]-h;
    }
  }
  return dp[n][m];
}

int main(){
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    ll ans = 0;
    FORN_(i,1,n)
    {
      FORN_(j,1,m) cin>>a[i][j];
    }
    FORN_(i,1,n)
    {
      FORN_(j,1,m)
      {
        ll h = a[i][j] - (i-1)-(j-1);
	ans = min(ans,solve(h));
      }
    }
    cout << ans << endl;
    }
  return 0;
}

