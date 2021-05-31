#include<iostream>

using namespace std;
#define ll long long
int main(){

    ll suma,aux;
        ll n;

    ll n1,n2;
    ll res=0;
    cin>>n;
    while(n--){
        suma=0;
        cin>>n1>>n2;
        suma=((n2 - n1 +1) * (n1 +n2)) / 2;
        //cout<<suma<<endl;
        res += suma;
    }

    cout<<res<<endl;
    return 0;
}