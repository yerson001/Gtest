#include<bits/stdc++.h>
using namespace std;

#define FORN(i, a, b) for(int i = (a); i < (b); i++)
#define FORN_(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define END cout<<endl;
#define MAX 100005
#define INF 0x3f3f3f3f

int n,c[MAX],x,y,d[MAX],ans;
vector<int> G[MAX];
bool vis[MAX];
void dfs1(int v){
    vis[v] = true;
    d[v] = c[v];
    bool f = false;
    for(int i = 0;i < G[v].size();++i){
        int t = G[v][i];
        if(!vis[t]){
            dfs1(t);
            f = true;
            if(d[v] != d[t]) d[v] = -1;
        }
    }
    vis[v] = false;
}

bool dfs2(int v,int pre){
    vis[v] = true;
    if(d[v] == -1){
        int counter = 0,u = -1;
        for(int i = 0;i < G[v].size();++i){
            int t = G[v][i];
            if(vis[t]) continue;
            if(d[t] == -1) counter++,u = t;
        }
        if(counter >= 2) return false;
        //c <= 1
        if(counter == 0) {ans = v;return true;}
        else{ // c = 1
            if(d[pre] != c[v]) return false;
            for(int i = 0;i < G[v].size();++i){
                int t = G[v][i];
                if(vis[t] || t == u) continue;
                if(d[t] != c[v]) return false;
            }
            d[v] = c[v];
            return dfs2(u,v);
        }
    }
    ans = v;
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1;i < n;++i){
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1;i <= n;++i){
        scanf("%d",&c[i]);
    }
    dfs1(1);
    d[0] = c[1];
    ans = -1;
    if(dfs2(1,0)) cout << "YES" << endl << ans << endl;
    else cout << "NO" << endl;
    return 0;
}
