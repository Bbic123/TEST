#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & (-x))

const int N = 1e5 + 5;
const int M = 5e3 + 5;

int arr[N], QWQ[N], QAQ[N], K, BIT[N], n, ans[M];

struct QQQ{
	int L, R, A, IDX;
}QQ[M];

bool cmp(QQQ a, QQQ b){
	return (a.L / K == b.L / K ? a.R < b.R : a.L / K < b.L / K);
}

inline void update(int idx, int num){
	while(idx <= n){
		BIT[idx] += num;
		idx += lowbit(idx);
	}
	return;
}

inline int query(int idx){
	int re = 0;
	while(idx){
		re += BIT[idx];
		idx -= lowbit(idx);
	}
	return re;
}

inline void add(int detail){
	update(detail, 1);
	return;
}

inline void sub(int detail){
	update(detail, -1);
	return;
}

inline int find_ans(int A){
	int L = 1, R = n + 1, MID, chk;
	while(L < R){
		MID = (L + R) >> 1;
		chk = query(MID);
		if(chk >= A) R = MID;
		else L = MID + 1;
	}
	return QWQ[L];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	while(cin >> n >> m){
		K = n / sqrt(m);
		if(!K) K = 1;
		for(int i = 1; i <= n; ++i){
			cin >> arr[i];
			QWQ[i] = arr[i];
		}
		sort(QWQ + 1, QWQ + n + 1);
		int len = unique(QWQ + 1, QWQ + n + 1) - (QWQ + 1);
		for(int i = 1; i <= n; ++i) QAQ[i] = lower_bound(QWQ + 1, QWQ + len + 1, arr[i]) - QWQ;
		for(int i = 1; i <= m; ++i){
			cin >> QQ[i].L >> QQ[i].R >> QQ[i].A;
			QQ[i].IDX = i;
		} 
		sort(QQ + 1, QQ + m + 1, cmp);
		int l = 1, r = 0;
		for(int i = 1; i <= m; ++i){
			while(QQ[i].R < r) sub(QAQ[r--]);
			while(QQ[i].R > r) add(QAQ[++r]);
			while(QQ[i].L < l) add(QAQ[--l]);
			while(QQ[i].L > l) sub(QAQ[l++]);
			ans[QQ[i].IDX] = find_ans(QQ[i].A);
		}
		for(int i = 1; i <= m; ++i) cout << ans[i] << '\n';
		for(int i = 1; i <= n; ++i) BIT[i] = 0;
	}
	return 0;
}