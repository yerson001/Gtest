#include <iostream>
#include <cstring>

#define debug(a) cout<<#a<<" = "<<a<<endl;
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)

using namespace std;

int n,k;
char s[3][210];
bool vis[3][210],flag;
int step[3]={-1,0,1};// movimientos en x

void dfs(int x,int y) {
    //cout<<x<<" "<<y<<endl;
    vis[x][y] = 1;
    if(y >= n-1) {// salio del juego
        flag = true;
        return;
    }
    if(s[x][y+1]!='.')
         return;

    for(int i=0;i<3;i++) {
        int it = x+step[i]; 
        if(it >= 0 && it < 3) {
            debug(it);
            if(s[it][y+1]=='.'&&s[it][y+2]=='.'&&s[it][y+3]=='.'&&!vis[it][y+3])
                 dfs(it,y+3);
        }  
    }
}

int main() {

    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        int x,y;
        for(int i=0;i<3;i++) {
            cin>>s[i];
            for(int j=0;j<n;j++) {
                if(s[i][j]=='s') 
                  x = i,y = j; //pos inicial 
            }
            for(int j=n;j<n*2;j++)
                   s[i][j]='.';
        }
        //FOR(i,0,3) cout<<s[i]<<endl;
        flag = false;
        memset(vis,0,sizeof(vis));//incializa la matriz vis
        dfs(x,y);
        cout<<(flag ? "YES":"NO")<<endl;
    }
    return 0;
}
