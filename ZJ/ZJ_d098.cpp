#include <bits/stdc++.h>
using namespace std;

int main(){
	string ss;
	stringstream s;
	while(getline(cin, ss)){
		s << ss;
		int ans = 0, cnt;
		while(s >> ss){
			cnt = 0;
			for(int i = 0; i < ss.size() && isdigit(ss[i]); ++i){
				++cnt;
			}
			if(cnt == ss.size()) ans += stoi(ss);
		}
		cout << ans << '\n';
		s.clear();
	}
	return 0;
}