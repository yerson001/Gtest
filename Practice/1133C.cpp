#include <bits/stdc++.h>

using namespace std;

const int N=20000;
int a[N];
int maxn=0;

void rpt(int m){
    if(m>maxn)
      maxn=m;
}

int resta(int i,int j){
    return a[j]-a[i];
}    

int main() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }

    sort(a+1,a+1+n);
    
    int i=1,j=i+1;

    while(i<=n-1&&j<=n){
        if(resta(j-1,j)>5){
          rpt(j-1-i);
            i=j;
            j++;
        }
        else if(resta(i,j)>5){
          rpt(j-1-i);
            i++;
            if(i==j) 
              j++;
        }
        else{
            j++;
        }
    }
    rpt(j-1-i);
    cout<<maxn+1<<endl;
    return 0;
}
