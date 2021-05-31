#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
const int maxn = 205;

int R[maxn],G[maxn],B[maxn];
ll dp[maxn][maxn][maxn];

int main() {
    
    int n1,n2,n3;scanf("%d%d%d",&n1,&n2,&n3);
    for(int i = 1;i <= n1;i++) {
        scanf("%d",&R[i]);
    }
    for(int i = 1;i <= n2;i++) {
        scanf("%d",&G[i]);
    }
    for(int i = 1;i <= n3;i++) {
        scanf("%d",&B[i]);
    }
    sort(R + 1,R + 1 + n1);
    sort(G + 1,G + 1 + n2);
    sort(B + 1,B + 1 + n3);
    
    for(int i = 0;i <= n1;i++) {
        for(int j = 0;j <= n2;j++) {
            for(int k = 0;k <= n3;k++) {
                dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k],dp[i][j][k] + R[i + 1] * G[j + 1]);
                dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1],dp[i][j][k] + R[i + 1] * B[k + 1]);
                dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1],dp[i][j][k] + G[j + 1] * B[k + 1]);
            }
        }
    }
    
    printf("%lld\n",dp[n1][n2][n3]);
    
    return 0;
}