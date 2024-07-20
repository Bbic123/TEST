#include <iostream>
using namespace std;

int main(){
	int ans;
	string s;
	while(cin >> s){
		ans = 1;
		for(int i = 0; i < s.size(); ++i){
			for(int j = ans + 1; j <= s.size() - i; ++j){ // size of the substring
				bool ok = true;
				for(int k = 0; k < j / 2; ++k){
					if(s[i + k] != s[i + j - 1 - k]){
						ok = false;
					}
				}
				if(!ok) continue;
				ans = max(ans, j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}