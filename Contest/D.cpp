#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2*1e5+10;
int a[N];
map<LL,LL> cnt;
void Rpt(){
    cnt.clear();
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]%=k;
    }
    LL ans=0;
    for(int i=0;i<n;i++) {
        if(!a[i]) continue;
        cnt[a[i]]++;
        ans=max(ans,(LL)cnt[a[i]]*k-a[i]);
    }
    if(ans) ans++;
    cout<<ans<<endl;
}
int main() {
    int t;cin>>t;
    while(t--) {
        Rpt();
    }
    return 0;
}