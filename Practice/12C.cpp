#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n,m; cin>>n>>m;
  //std::cout<<n<<"  "<<m<<std::endl;
  vector<int> precio;
  vector<string> frutas;
  int nn = 0; int mm=0;

  while(cin>>precio[nn++] && nn < n){}
  
   string s; 
    for(int i = 0; i<=n; i++) { 
        getline(cin, s); 
        frutas.push_back(s); 
    } 
    for(int i = 0; i<frutas.size(); i++) { 
        cout<<frutas[i]<<endl;
    } 

  return 0;
}
