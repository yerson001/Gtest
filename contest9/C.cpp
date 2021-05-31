#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FORN(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define ll long long

vector<int> adj[100005];
vector<int> vis(100005,false);

void dfs(int i){
    if(!vis[i]){
        vis[i] = true;
        for(auto v:adj[i]){
            dfs(v);
        }
    }
}

void solve(){
    int total=0;
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int comp=0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            comp++;
            dfs(i);
        }
    }
    cout<<comp-1;
}

int main() {
    solve();

  return 0;
}
