#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int arr[105][105];
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];
		}
	}
	bool f = 0;
	int x, y;
	int mx, mn;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			mx = mn = arr[i][j];
			for(int k = 0; k < n; ++k){
				mn = min(mn, arr[k][j]);
				mx = max(mx, arr[i][k]);
			}
			if(mn == mx && mx == arr[i][j]){
				f = 1;
				x = i, y = j;
			}
		}
	}
	if(f) cout << x << ' ' << y << '\n';
	else cout << "NO\n";
	return 0;
}