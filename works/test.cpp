#include<iostream>
using namespace std;

double pow(double a,int n){
    if(n==0) return 1;
    if(n==1) return a;
    double t = pow(a,n/2);
  return t*t*pow(a,n%2);
}

double pow3(double a,double n){
  double ret = 1;
  while(n){
    if(((int)n)%2==1) ret *=a;
    a *= a;n/=2;
  }
  return ret;
}
double pow2(double a, int n){
	if(n==0)return 1;
	if(n==1)return a;
	return pow(a,n) * pow(a,n%2);
}

int gcd(int a, int b){
  while(b){int r = a%b; a = b; b = r;}
  return a;
}

/*
double pow3(double a, int n){
	return pow(a,n) * (n & 1 ? a : 1);
}
*/

int main(){

  cout<<pow(2,3)<<endl;
  cout<<pow2(2,3)<<endl;
  cout<<pow3(2,3)<<endl;

 return 0;
}
