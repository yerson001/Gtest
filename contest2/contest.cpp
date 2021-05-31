#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
      double a, b;
      cin >> a >> b;
      int c = ceil( abs(a-b) / 10);
      cout << c << "\n";
    }
 
    return 0;
}