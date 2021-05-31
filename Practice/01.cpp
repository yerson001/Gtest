#include<iostream>
using namespace std;
//using ++i  que ocupa menos espacio que i++
int main(){
  int num,ans=0,cont;
  cin>>num;
  for(int i=num-1; i>0; i--){
    if(num%(i)==0){
       ans+=i;
    }
  }
  if(ans==num){
    cout<<ans<<" es perfecto"<<endl;
  }else{
     cout<<ans<<" no es perfecto"<<endl;
  }
  
  return 0;
}
