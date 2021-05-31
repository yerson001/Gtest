#include<bits/stdc++.h>
using namespace std;
int main(){

  int n,k,n1;
  cin>>n>>k>>n1;
  if((n>=10 and n<=12) and (k>=4 and k<=10) and (n1>=(n/2)and n1<=n)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

  return 0;
}
