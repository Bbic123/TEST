#include <iostream>
#include <string>
using namespace std;

int main(){
	string x;
	cin >> x;
	int n1 = 0, n2 = 0;
	for(int i = 0; i < x.size(); ++i){
		if(i % 2) n1 += x[i] - '0';
		else n2 += x[i] - '0';
	}
	if(n1 - n2 > 0)
		cout << n1 - n2;
	else
		cout << n2 - n1;
	cout << '\n';
    return 0;
}
