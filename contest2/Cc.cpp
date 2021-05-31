
#include<iostream>
#include<cstdio>
using namespace std;
 
const int inf=0x3f3f3f3f;
const int N=1e5+100;
 
int a[N],n;
 
int Rpt(int val) {
	int max_ending=0,mmax=-inf;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>val)
		{
			max_ending=0;
			continue;
		}
		max_ending=max(0,max_ending+a[i]);
		mmax=max(mmax,max_ending-val);
	}
	return mmax;
}
 
int main() { 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int ans=0;
	for(int i=0;i<=30;i++)
		ans=max(ans,Rpt(i));
	printf("%d\n",ans);
 
    return 0;
}
