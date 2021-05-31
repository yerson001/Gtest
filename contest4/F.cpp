#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,ln=0,lm=0,tmp,ans=0;
	cin>>n>>m;
	tmp=n-1;
	while(tmp>0)
	{
		ln+=tmp;
		tmp-=2;
	}
	tmp=m-1;
	while(tmp>0)
	{
		lm+=tmp;
		tmp-=2;
	}
	ans=ln*(m+1)+lm*(n+1);
	ans+=2*lm*ln;
	cout<<ans;
    return 0;
}