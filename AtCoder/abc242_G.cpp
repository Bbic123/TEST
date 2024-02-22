#include <bits/stdc++.h>
using namespace std; // abc242_G - Range Pairing Query

const int Q = 1e6 + 5;
const int N = 1e5 + 5;

int arr[N], K, ans[Q], cnt[N], ANS = 0;

struct input{
	int L, R, IDX;
}Que[Q];

bool cmp(input a, input b){
	return (a.L / K == b.L / K ? a.R < b.R : a.L / K < b.L / K);
}

inline void add(int detail){
	++cnt[detail];
	if(cnt[detail] & 1 ^ 1) ++ANS;
	return;
}

inline void sub(int detail){
	--cnt[detail];
	if(cnt[detail] & 1) --ANS;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	cin >> q;
	K = n / sqrt(q);
	if(!K) K = 1;
	for(int i = 0; i < q; ++i){
		cin >> Que[i].L >> Que[i].R;
		Que[i].IDX = i;
	}
	sort(Que, Que + q, cmp);
	int l = 1, r = 0;
	for(int i = 0; i < q; ++i){
		while(Que[i].R < r) sub(arr[r--]);
		while(Que[i].R > r) add(arr[++r]);
		while(Que[i].L < l) add(arr[--l]);
		while(Que[i].L > l) sub(arr[l++]);
		ans[Que[i].IDX] = ANS;
	}
	for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}