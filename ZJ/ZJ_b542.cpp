#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool f;
	int n, q, k, l;
	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	while(q--){
		cin >> k;
		f = l = 0;
		for(int r = 0; r < n; ++l){
			while(a[r] - a[l] > k) ++l;
			if(a[r] - a[l] == k){
				f = true;
				break;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
	return 0;
}