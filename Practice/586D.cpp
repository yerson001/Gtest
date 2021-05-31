#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n,k;
char mapp[3][110];
bool vis[3][110];
bool flag;

void DFS(int x,int y) {
  cout<<x<<" , "<<y<<endl;
    vis[x][y]=1;
    if(flag)
        return;
    if(y>=n) { // si ya salimos del juego| 
        flag=true;
        return;
    }
    if(mapp[x][y+1]!='.')// salimos del juego
        return;
    if(x<2 &&!vis[x+1][y+3]) {
        if(mapp[x+1][y+1]=='.'&&mapp[x+1][y+2]=='.'&&mapp[x+1][y+3]=='.')
            DFS(x+1,y+3);
    }
    if(x>0&&!vis[x-1][y+3]) {
        if(mapp[x-1][y+1]=='.'&&mapp[x-1][y+2]=='.'&&mapp[x-1][y+3]=='.')
            DFS(x-1,y+3);
    }
    if(!vis[x][y+3]) {
        if(mapp[x][y+1]=='.'&&mapp[x][y+2]=='.'&&mapp[x][y+3]=='.')
            DFS(x,y+3);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        //Establecemos todos los valores en 0
        memset(vis,0,sizeof(vis));

        for(int i=0;i<3;i++) {
            scanf("%s",mapp[i]);
        }

        for(int i = 0;i < 3;i++)
            for(int j = n;j < n+5;j++)  
                mapp[i][j] = '.';

        //printV(n);

        flag=false;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<n;j++) {
                if(mapp[i][j]=='s') {
                    DFS(i,j);
                    break;
                }
            }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
