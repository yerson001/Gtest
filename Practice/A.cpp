#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define debug(a) cout<<#a<<" = "<<a<<endl;

int main() {
      long n; cin>>n;
        vector<long > a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        vector<long> b(n);
        for(int j=0; j<n; j++){
            cin>>b[j];
        }

    bool flag = 1;
    for(int i = 0; i < n; i ++){
        if(a[i] != b[i]){
            flag = 0;
            break;
        }
    }

    if(flag){
        cout << "-1" << '\n';
        return 0;
    }

    int sum = 0; debug(sum);
    int res = 0; debug(res);

    for(int i = 0;i < n;i ++){
         if(a[i]!=0  && b[i] == 0)
            sum ++;// nuestros puntos
         if(a[i] ==0 && b[i] != 0)
            res += b[i];// respuestas de B
    }
    if(sum == 0){
        printf("-1\n");
        return 0;
    }

    int ans = 0;
    if(sum > res){
        ans = 1;
    }
    else if(sum <= res){
         ans = res/sum + 1;
    }
    cout << ans << '\n';
    
    return 0;
}
