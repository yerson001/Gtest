#include<bits/stdc++.h>

int sum_c(std::vector<int> a,int size){
  int result = 0;
  int inicio = 0;
  //int cnt = 0;

  for(int i=0; i<size; i++) {
      inicio = inicio + a[i];
      if(result < inicio) {
        result = inicio;
        //cnt++;
      }
      if(inicio < 0){
         inicio = 0;
      }
  }
  return result;
  //return cnt;
}

int main(){

  int t; std::cin>>t;
  std::vector<int> arr(t);
  for(int i=0; i<t; i++) {
    std::cin>>arr[i];
  }

  std::cout<<sum_c(arr,t)<<std::endl;

  return 0;
}
