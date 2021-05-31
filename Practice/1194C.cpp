    #include <iostream>
    #include <string>
    using namespace std;
    string a,b,c;
    int f[28];
    int main() {
        ios::sync_with_stdio(false);
        int t;
        cin>>t;
        // cout << 'z' - 'a';
        while(t--) {
            for (int i=0; i < 26; i++) {
                f[i] = 0;
            }
            cin>>a>>b>>c;
            
            if (a== b){
                cout << "YES\n";
                continue;
            }
            if (a.length() > b.length() || a.length() + c.length() < b.length()) {
                cout << "NO\n";
                continue;
            }
            
            for(unsigned int i = 0; i< c.length(); i ++) {
                f[c[i] - 'a']++;
            }
            bool flag = 1;unsigned int shif = 0;
            for(unsigned int i = 0; i < b.length() + 1; i++) {
                //cout << i - shif << i << endl;
                if (i - shif == a.length()) {
                    while(i < b.length()) {
                        if (!f[b[i]-'a']) {
                            flag = 0;
                            break;
                        }
                        f[b[i] - 'a']--;
                        i++;
                    }
                    break;
                }
                if (i == b.length()) {
                    if (a.length() + shif != b.length()) {
                        flag = 0;
                        
                    }
                    break;
                }
                if (a[i-shif] != b[i]) {
                    // printf("orz a[%c, b[%c\n",a[i-shif],b[i]);
                    if (!f[b[i]-'a']) {
                        flag = 0;
                        break;
                    }
                    shif++;
                    f[b[i] - 'a']--;
                }
            }
            cout << (flag ? "YES\n":"NO\n");
        }
    }