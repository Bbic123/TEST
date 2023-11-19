#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
pair<long long, int> input[N];
int arr[N], BIT[N], n;

#define lowbit(x) ((x) & (-x))

void update(int idx, int num){
    while(idx <= n){
        BIT[idx] += num;
        idx += lowbit(idx);
    }
}

int query(int idx){
    int re = 0;
    while(idx){
        re += BIT[idx];
        idx -= lowbit(idx);
    }
    return re;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n){
		for(int i = 1; i <= n; ++i){
			cin >> input[i].first;
			input[i].second = i;
		}
		sort(input + 1, input + n + 1);
		for(int i = 1; i <= n; ++i) arr[input[i].second] = i;
		for(int i = 1; i <= n; ++i){
			update(arr[i], 1);
			cout << i - query(arr[i]) + 1 << '\n';
		}
		for(int i = 1; i <= n; ++i) input[i].first = input[i].second = arr[i] = BIT[i] = 0;
	}
	return 0;
}