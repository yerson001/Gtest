#include<cstdio>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
const int N = 500007;
const ll INF = 1e14;

int n, m;
ll a[N];

int main(){
    scanf("%d", &n);
    for(int i =  1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll ans = INF ;
    int t = pow(INF, 1.0 / n);
    sort(a +  1, a + 1 + n);
    for(int c = 1; c <= t; ++ c){
        ll sum = 0, tmp = 1;
        for(int i = 1; i <= n; ++ i){
            sum += abs(a[i] - tmp);
            tmp *= c;
        }
        ans = min(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}