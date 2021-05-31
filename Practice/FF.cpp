#include<bits/stdc++.h>
using namespace std;

#define FORN(i, a, b) for(int i = (a); i < (b); i++)
#define FORN_(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define END cout<<endl;
typedef long long LL;
const LL INF = 1e18;
const int maxn = 1001;
LL mapa[maxn][maxn], dp[maxn][maxn];
int n, m;


LL solve(LL init)
{
  for (int i = 0; i <= n; i++)
  {
     for (int j = 0; j <= m; j++)
      {
	dp[i][j] = INF;
      }
   }
	
  //memset(dp,INF,sizeof(dp);

  dp[1][1] = mapa[1][1] - init;

  for (int i = 1; i <= n; i++)
  {
     for (int j = 1; j <= m; j++)
     {
	//ya calculado omitir
	if (i == 1 && j == 1) continue;
	
	LL value = init + i + j - 2;
	
	if (mapa[i][j] < value) continue;
	//el valor que tines y a donde quieres llagar
	LL cost = mapa[i][j] - value;
	dp[i][j] = min(dp[i - 1][j] + cost, dp[i][j - 1] + cost);
     }
   }

  return dp[n][m];
}

int main()
{
   int t; cin >> t; 
	
    while (t--)
    {
	LL ans = INF;
	cin >> n >> m;
	
	FORN_(i,1,n)
	{
	    FORN_(j,1,m)
	    {
		cin >> mapa[i][j];
	    }
	}

	
	for (int i = 1; i <= n; i++)
	{
	    for (int j = 1; j <= m; j++)
	     {
		//posicion inicial
		LL init = mapa[i][j] - i - j + 2;
		//verificamos los limites
		if(init<=mapa[1][1])
		   ans = min(ans, solve(init));
		cout<<ans<<endl;
	     }
	}
	cout << ans << endl;
      }
	
    return 0;
}

/*
5
3 4
1 2 3 4
5 6 7 8
9 10 11 12
5 5
2 5 4 8 3
9 10 11 5 1
12 8 4 2 5
2 2 5 4 1
6 8 2 4 2
2 2
100 10
10 1
1 2
123456789876543 987654321234567
1 1
42
output
9
49
111
864197531358023
0
*/
