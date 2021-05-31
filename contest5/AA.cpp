#include <bits/stdc++.h>
 
int main() {
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            m -= a;
        }
        std::cout << (m == 0 ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
/*
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m, sum = 0;
        cin >> n >> m;
 
        vector<int> a(n);
 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
 
        cout << (sum == m ? "YES\n" : "NO\n");
    }
}
*/