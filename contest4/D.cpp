#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 7;

char s[MX],t[MX<<1];
int p[MX<<1];
bool manacher(int len,int m){
    int pos = 0;
    t[pos++] = '$', t[pos++] = '#';
    for(int i = 0;i < len;++i){
        t[pos++] = s[i];
        t[pos++] = '#';
    }
    int res = 0, id = 0, mx = 0;
    for(int i = 1;i < pos;++i){
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while(t[i + p[i]] == t[i - p[i]]) ++p[i];
        if(mx < i + p[i]){
            mx = i + p[i];id = i;
        }
        if((p[i] - 1) % 2 == m % 2 && p[i] - 1 >= m) return true;
        res = max(res,p[i]);
    }
    return false;
}

int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,s);
    if(manacher(n,m)) cout << "Accept";
    else cout << "Reject";
    cout << endl;
}
