#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<ctime>
#include<map>
#include<stack>
#include<string>
using namespace std;
 
#define sfi(i) scanf("%d",&i)
#define sfl(i) scanf("%I64d",&i)
#define pri(i) printf("%d\n",i)
#define sff(i) scanf("%lf",&i)
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define INF 0x3f3f3f3f
#define eps 1e-6
#define PI acos(-1)
#define lowbit(x) ((x)&(-x))
#define fl() printf("flag\n")
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const ll mod=1e9+7;
const int maxn=2e6+100;
 
int pre[maxn];
int n;
struct A
{
    int cap;
    int val;
}a[maxn];
 
int Find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }
 
    int i=x;
    int j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
 
void join(int x,int y)
{
    int jx=Find(x);
    int jy=Find(y);
 
    if(jx!=jy)
    {
        if(jx>jy) pre[jy]=jx;
        else pre[jx]=jy;
    }
}
 
void add(int p,int x)
{
    int r=Find(p);
    while(r<=n&&x>0)
    {
        if(a[r].cap>=a[r].val+x)
        {
            a[r].val+=x;
            x=0;
        }
        else
        {
            x-=(a[r].cap-a[r].val);
            a[r].val=a[r].cap;
            join(r,r+1);
        }
        r=Find(r);
    }
}
int main()
{
    sfi(n);
    for(int i=1;i<maxn;i++) pre[i]=i;//n的话连接n+1不行，会tle
    for(int i=1;i<=n;i++)
    {
        A tmp;
        sfi(tmp.cap);
        tmp.val=0;
        a[i]=tmp;
    }
    int m;
    sfi(m);
    while(m--)
    {
        int op;
        sfi(op);
        if(op==1)
        {
            int p;
            int x;
            sfi(p);
            sfi(x);
            add(p,x);
        }
        else
        {
            int p;
            sfi(p);
            printf("%d\n",a[p].val);
        }
    }
    return 0;
}