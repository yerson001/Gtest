#include <cstring>
#include <iostream>

using namespace std;

int main(){
  
  char str[] = "hola";
  memset(str,'h',sizeof(str)-1);
  cout<<str<<endl;

  return 0;
}
