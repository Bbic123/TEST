#include <bits/stdc++.h>
using namespace std; // abc251_C - Poem Online Judge

const int N = 1e5 + 5;
string arr[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str = "";
	int n, t, mx = -1;
	map<string, bool> m;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> s >> t;
		arr[i] = s;
		if(!m[s]){
			m[s] = 1;
			if(t > mx){
				mx = t;
				str = s;
			}
		}
	}
	string *it = find(arr, arr + n, str);
	cout << it - arr + 1 << '\n';
	return 0;
}
