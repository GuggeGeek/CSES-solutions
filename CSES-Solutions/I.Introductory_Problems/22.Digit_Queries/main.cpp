#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	while (n--) {
		unsigned long long ch;
		cin >> ch;
		unsigned long long len = 1 , cnt = 9 , start = 1; // длина числа(разрядов),  количество чисел , начальное число

		while ( ch > len * cnt) {
			ch -= len * cnt;
			len++;
			cnt *= 10;
			start *= 10;
		}

		long long num = start + (ch - 1) / len;
		int pos = (ch - 1) % len;

		string s = to_string(num);
		cout << s[pos] << "\n";
	}

	return 0;
}