#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string x;
	cin >> x;
	int n1 = 0, n2 = 0;
	for(int i = 0; i < x.size(); ++i){
		if(i % 2)
			n1 += x[i] - '0';
		else
			n2 += x[i] - '0';
	}
	cout << abs(n1 - n2) << '\n';
	return 0;
}
