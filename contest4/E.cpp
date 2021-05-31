
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n,a[N],b[N],res,vis[N],st[40],ans,sz,k,mx;
vector<ll> prime,v[N];

inline ll check(ll k){
	ll res=0;
	for(ll i=0;i<k;i++)	if((k+1)%(i+1)==0)	res+=st[i];
	return res;
}

void dfs(ll x,ll s){
	if(x==sz){
     ans=max(ans,s);
    	return ;}
	ll cnt=check(x);
    st[x]=1;
	dfs(x+1,s+a[v[k][x]]-b[v[k][x]]*cnt);
    st[x]=0;
	dfs(x+1,s);
}

int  main(){
	cin>>n;
	for(ll i=1;i<=n;i++)
    	cin>>a[i];
	for(ll i=1;i<=n;i++)
    	cin>>b[i];
	for(ll i=2;i<=n;i++){
		if(vis[i])	
        continue;
        ll k=i;	prime.push_back(i);
		while(k<=n)
			v[i].push_back(k),vis[k]=1,k*=i;
	}
	for(ll i=0;i<prime.size();i++){
		k=prime[i]; sz=v[k].size();	ans=0;	mx=0;
		dfs(0,0);	res+=ans;
	}
	cout<<res+a[1];
	return 0;
}
