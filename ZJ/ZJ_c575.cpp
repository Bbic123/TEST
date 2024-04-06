#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 5e4 + 5;

int arr[N];

inline bool chk(int m, int k, int n){
	int now = 0, kk = 0;
	while(now < n){
		++kk;
		now = upper_bound(arr + now, arr + n, arr[now] + m) - arr;
		if(kk > k) return false; 
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int L = 1, R = 1e9 + 2, MID;
	while(L < R){
		MID = (L + R) >> 1;
		if(chk(MID, k, n)) R = MID;
		else L = MID + 1;
	}
	cout << L << '\n';
	return 0;
}