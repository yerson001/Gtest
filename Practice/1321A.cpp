#include<iostream>
#include<algorithm>
//#define ll long long
//#define inf 0x3f3f3f3f
using namespace std;
int n,a[110],b[110];

int main() {
  scanf("%d",&n);
  int sumr=0,sumb=0;

  for(int i=0;i<n;i++) {
    scanf("%d",&a[i]);
    if(a[i]==1) sumr++;
  }

  for(int i=0;i<n;i++) {
    scanf("%d",&b[i]);
    if(b[i]==1) sumb++;
  }

  cout <<"suma: "<<sumr<<" sumb: "<<sumb<<endl;
//==========================
//
  int sum=0;
  for(int i=0;i<n;i++) {
    if(a[i]==1&&b[i]==1)
      sum++;
  }
  sumr = sumr - sum;
  sumb = sumb - sum;
  
  cout <<"suma: "<<sumr<<" sumb: "<<sumb<<endl;

  if(sumr==0)// no respondio ninguna pregunta
    printf("-1\n");
  else {
    if(sumr==1){
      printf("%d\n",sumb+1);
      cout<<"sumr == 1"<<endl;
    }
    else{
      // la maxima puntuacin es sumb +1 no puede aver mas puntuacion que esa
      // lo que hacemos es minimizar eso
      printf("%d\n",(sumb+1)/sumr+1);
         
  }
}
  return 0;
}
