#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
typedef pair<int,int> Par;
const int INF=0x3f3f3f3f,maxn=100005;
#define mod 1000000007
#define s second
#define t first
int n,m,sum[maxn];
Par a[maxn];

int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
       cin>>a[i].s>>a[i].t;
       //**************************
    sort(a+1,a+m+1);
    /*for(int i=0; i<m; i++)
        cout<<a[i].first<<a[i].second<<endl;
    */
    sum[0]=1;
    int ans=0;
    for(int i=1;i<=m;) {
        int k;
        for(k=i;k<=m&&a[k].t==a[i].t;k++) {
            int pos=lower_bound(a,a+i,Par(a[k].s,0))-a;
            int temp;
            if(pos>0)temp=(sum[i-1]-sum[pos-1]+mod)%mod;
            else temp=sum[i-1];
            sum[k]=(sum[k-1]+temp)%mod;
            if(a[k].t==n)ans=(ans+temp)%mod;
        }
        i=k;
    }
   cout<<ans<<endl;
    return 0;
}