#include<bits/stdc++.h>
using namespace std;

int main(){

  string upper = "qwertyuiop";
  string middle = "asdfghjkl;";
  string lower = "zxcvbnm,./";
  
  string direccion; getline(cin,direccion);
  string entrada;   getline(cin,entrada);

  int dir = (direccion[0]=='R') ? -1:1;
  int pos = 0;
  
  for(int i=0; i<entrada.size(); i++){
    pos = upper.find(entrada[i]);
    if(pos != string::npos){printf("%c",upper[pos+dir]);}
    pos = middle.find(entrada[i]);
    if(pos != string::npos){printf("%c",middle[pos+dir]);}
    pos = lower.find(entrada[i]);
    if(pos != string::npos){printf("%c",lower[pos+dir]);}
  }

    return 0;
}
