#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){
  long q; cin>>q;
  while(q--){ 
    string s; cin>>s;
    cout<<endl;
    string impar,par;
    
    for(int p=0; p<s.size(); p++){
      if((s[p]-'0')%2){
        impar += s[p];
      }
      else{
        par +=s[p];
      }
    }

    long a=0,b=0;
    while(a<impar.size() || b < par.size()){
      if(a<impar.size() && b<par.size()){
         if(impar[a] < par[b]){
            cout<<impar[a];++a;
         }
      else{
        cout<<par[b];++b;
      }
    }
    else if(a < impar.size()){
        cout<<impar[a]; ++a;
    }
    else if(b < par.size()){
        cout<<par[b]; ++b;
    }
  }
    cout<<endl;
  }
  

  return 0;
}
