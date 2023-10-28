#include<bits/stdc++.h>
using namespace std;

#define cal first
#define t second

const int N = 1e5 + 5;
pair<int, int> arr[N];

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.t < b.t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	long long ans = 0;
	priority_queue<int, vector<int>, greater<>> pq;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i].cal >> arr[i].t;
	cin >> k;
	sort(arr, arr + n, cmp);
	for(int i = 0; i < n; ++i){
		if(pq.size() < arr[i].t && pq.size() < k){
			ans += arr[i].cal;
			pq.push(arr[i].cal);
		}
		else if(pq.top() < arr[i].cal){
			ans -= pq.top();
			pq.pop();
			pq.push(arr[i].cal);
			ans += arr[i].cal;
		}
	}
	if(k > pq.size()) ans -= (k - pq.size());
	cout << ans << '\n';
	return 0;
}
