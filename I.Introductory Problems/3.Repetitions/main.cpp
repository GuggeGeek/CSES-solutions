#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string DNK;
	cin >> DNK;
	int max = 0 , n = 0;
	char ch_last = ' ';
	for (auto now : DNK) {
		if (ch_last == now) n++;
		else n = 1;
		if (n > max) max = n;
		ch_last = now;
	}
	cout << max;
}