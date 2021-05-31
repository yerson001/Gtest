#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long

#ifdef sarthak
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#else
#define trace(...)
#endif

#ifndef sarthak
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fort(i,v) for(auto i:v)
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) rep(i,sizeof(ar)/sizeof(ll)) ar[i]=val
#define fill2(ar,val) rep(i,sizeof(ar)/sizeof(ar[0])) rep(j,sizeof(ar[0])/sizeof(ll)) ar[i][j]=val
#define fill0(ar) memset(ar,0,sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%d %d",&x,&y)
#define slld2(x,y) scanf("%lld %lld",&x,&y)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pd2(x,y) printf("%d %d\n",x,y)
#define plld2(x,y) printf("%lld %lld\n",x,y)
#define all(ar) ar.begin(), ar.end()
#define endl '\n'
#define sz(x) (int)x.size()
#define len(x) (int)x.length()

typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define INF 1000000000000000000
#define PI 3.14159265358979323846L

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngb(chrono::steady_clock::now().time_since_epoch().count()); // can give negative values too

const ll N = 400001;
ll s1[4*N];
ll l1[4*N];
ll s2[4*N];
ll l2[4*N];

void propagate(ll seg[], ll lazy[], ll st, ll en, ll ind)
{
    ll mid = (st+en)/2;
    lazy[2*ind] = lazy[ind];
    lazy[2*ind+1] = lazy[ind];

    seg[2*ind] = lazy[ind];
    seg[2*ind+1] = lazy[ind];

    lazy[ind] = -1;
}

void update(ll seg[], ll lazy[], ll st, ll en, ll ind, ll il, ll ir, ll diff)
{
    if(st>ir || en<il)
        return;
    if(st>=il && en<=ir)
    {
        seg[ind] = diff;
        lazy[ind] = diff;
        return;
    }

    if(lazy[ind]!=-1)
        propagate(seg,lazy,st,en,ind);
    ll mid = (st+en)/2;

    update(seg,lazy,st,mid,2*ind,il,ir,diff);
    update(seg,lazy,mid+1,en,2*ind+1,il,ir,diff);
    seg[ind] = min(seg[2*ind],seg[2*ind+1]);
}

ll query(ll seg[], ll lazy[], ll st, ll en, ll ind, ll il, ll ir)
{
    if(st>ir || en<il)
        return INF;
    if(st>=il && en<=ir)
        return seg[ind];

    if(lazy[ind]!=-1)
        propagate(seg,lazy,st,en,ind);
    ll mid = (st+en)/2;
    return min(query(seg,lazy,st,mid,2*ind,il,ir),query(seg,lazy,mid+1,en,2*ind+1,il,ir));
}

map<ll,ll> m;
ll h[300001];
ll dp[300001];

void solve()
{
    ll n;
    cin >> n;

    fr(i,1,4*n)
    {
        l1[i] = -1;
        l2[i] = -1;
    }

    fr(i,1,n)
    {
        cin >> h[i];
        m[h[i]]++;
    }

    ll now = 1;
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        it->second = now;
        now++;
    }

    fr(i,1,n)
    {
        h[i] = m[h[i]];
    }

    fr(i,1,n)
    {
        update(s1,l1,1,n,1,i,i,INF);
        update(s2,l2,1,n,1,i,i,INF);
    }

    dp[1] = 0;
    update(s1,l1,1,n,1,h[1],h[1],0);
    update(s2,l2,1,n,1,h[1],h[1],0);

    fr(i,2,n)
    {
        if(h[i]>h[i-1])
        {
            dp[i] = query(s1,l1,1,n,1,1,n)+1;
        }
        else if(h[i]<h[i-1])
        {
            dp[i] = query(s2,l2,1,n,1,1,n)+1;
        }
        else
        {
            dp[i] = dp[i-1]+1;
        }

        update(s1,l1,1,n,1,1,h[i]-1,INF);
        update(s2,l2,1,n,1,h[i]+1,n,INF);
        update(s1,l1,1,n,1,h[i],h[i],dp[i]);
        update(s2,l2,1,n,1,h[i],h[i],dp[i]);
    }

    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
    #ifdef sarthak
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    #ifdef sarthak
    cerr << "Time elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
    #endif
}