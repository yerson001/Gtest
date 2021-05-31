#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> a(n); for(int i=0;i<n;i++)cin >> a[i];
        //======================================

		int z=0;
		for(int i=0;i<n;i++){
			if(a[i]==0)
				z++;
		}
		if((n/2)%2==0){
			cout << n/2 << endl;
			for(int i=0;i<n/2;i++)
				cout << (z*2<n) << ' ';
			cout << endl;
		}
		else{
			if(z==0){
				cout << n/2+1 << endl;
				for(int i=0;i<n/2+1;i++)
					cout << 1 << ' ';
				cout << endl;
			}else{
				int k=0;
				cout << n/2 << endl;
				if(z*2<n){
					for(int i=0;i<n;i++){
						if(a[i]==0){
							break;
						}else if(k<n/2-1){
							k++;
						}
					}
                    for(int i=0;i<(k/2)*2;i++)
						cout << 1 << ' ';
					cout << 0 << ' ';
                    for(int i=0;i<n/2-1-(k/2)*2;i++)
						cout << 1 << ' ';
				}
				else{
					for(int i=0;i<n/2;i++)
						cout << 0 << ' ';
				}
				cout << endl;
			}
		}
	}
	return 0;
}
