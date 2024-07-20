#include <iostream>
using namespace std;

int main(){
	string s;
	bool f = false;
	getline(cin, s);
	for(int i = 0; i <= 25; ++i){
		for(int j = 0; j < s.size(); ++j){
			if(tolower(s[j]) == 'l'){
				string chk = s.substr(j, 4);
				if(chk == "Love" || chk == "love"){
					cout << i << '\n';
					f = true;
					break;
				}
			}
			if(isalpha(s[j])){
				++s[j];
				if(!isalpha(s[j]))
					s[j] -= 26;
			}
		}
		if(f) break;
	}
	return 0;
}