#include<bits/stdc++.h>
int main(){
  int n; std::cin>>n;
  int cont = 1,j=0;
  for(int i=1; i<n; i++){
    j+=i;
    std::cout<<(cont+j)%n<<" ";
  }

  return 0;
}
