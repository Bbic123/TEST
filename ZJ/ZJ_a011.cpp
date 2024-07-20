#include <iostream>
using namespace std;

int main(){
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