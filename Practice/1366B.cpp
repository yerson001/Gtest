#include<iostream>
using namespace std;

int main() {
  long t; cin>>t;
  while(t--){
     long n,x,m;  cin>>n>>x>>m;
     long left(x), right(x);
     while(m--){
       long ll,rr; cin>>ll>>rr;
       if(rr < left || right < ll){
         continue;
       }
       left = (ll < left) ? ll : left;
       right = (rr > right) ? rr : right;
     }
     cout<<(right - left + 1)<<endl;
  }
  return 0;
}
