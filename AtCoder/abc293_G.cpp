#include <bits/stdc++.h>
using namespace std; // abc293_G - Triple Index

typedef long long ll;
#define C3(x) ((x) * (x - 1) * (x - 2) / 6)

const int N = 2e5 + 5;

ll ans[N], ANS, cnt[N];
int arr[N], K;

struct input{
	int L, R, IDX;
}Q[N];

bool cmp(input a, input b){
	return (a.L / K == b.L / K ? a.R < b.R : a.L / K < b.L / K);
}

inline void add(int detail){
	if(cnt[detail] >= 3) ANS -= C3(cnt[detail]);
	++cnt[detail];
	if(cnt[detail] >= 3) ANS += C3(cnt[detail]);
}

inline void sub(int detail){
	if(cnt[detail] >= 3) ANS -= C3(cnt[detail]);
	--cnt[detail];
	if(cnt[detail] >= 3) ANS += C3(cnt[detail]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	K = n / sqrt(q);
	if(!K) K = 1;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	for(int i = 0; i < q; ++i){
		cin >> Q[i].L >> Q[i].R;
		Q[i].IDX = i;
	}
	sort(Q, Q + q, cmp);
	int l = 1, r = 0;
	for(int i = 0; i < q; ++i){
		while(Q[i].R < r) sub(arr[r--]);
		while(Q[i].R > r) add(arr[++r]);
		while(Q[i].L < l) add(arr[--l]);
		while(Q[i].L > l) sub(arr[l++]);
		ans[Q[i].IDX] = ANS;
	}
	for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}
