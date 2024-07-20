#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin, s)){
		int ans = 0;
		s = '0' + s;
		for(int i = 1; i < s.size(); ++i){
			if(isalpha(s[i])){
				if(!isalpha(s[i - 1])) ++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}