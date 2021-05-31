
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn=5e4+100;
typedef long long LL;
LL dp[maxn][700];
vector<LL>g[maxn];
LL n,k;
LL ans=0;

void dfs(LL u,LL fa){
	dp[u][0]=1;
	for(LL i=0;i<g[u].size();i++){
		LL v=g[u][i];
		if(v!=fa){
			dfs(v,u);
			for(LL j=0;j<k;j++)
             ans+=dp[u][j]*dp[v][k-j-1];
			for(LL j=0;j<k;j++)
             dp[u][j+1]+=dp[v][j];	
		}	
	}
}
int main(void)
{
  cin.tie(0);
  cin>>n>>k;
  for(LL i=1;i<n;i++){
  	LL x,y;cin>>x>>y;
  	g[x].push_back(y);
  	g[y].push_back(x);
  }
  dfs(1,0);
  cout<<ans<<endl;
return 0;
}
