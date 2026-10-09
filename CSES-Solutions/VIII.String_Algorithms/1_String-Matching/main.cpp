#include <iostream>
#include <string>

using namespace std;
const long long b = 1e9 + 9;
const int a = 53;
long long h[1000001]; // преффиксные хеши первой строки
long long p[1000001]; // степени базы а

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, pat;
	cin >> s >> pat;
	int n = s.size(), m = pat.size();
	if (m > n) {
		cout << 0;
		return 0;
	}

	p[0] = 1;
	for (int l = 1; l < n; l++) {
		p[l] = p[l - 1] * a % b;
	}

	h[0] = (s[0] - 'a' + 1);
	for (int l = 1; l < n; l++) {
		h[l] = (h[l - 1] * a + (s[l] - 'a' + 1)) % b;
	}

	long long hesh = pat[0] - 'a' + 1; // +1 тк a - a будет 0 и при умножении даст 0
	for (int l = 1; l < m; l++) {
		hesh = (hesh * a + (pat[l]- 'a' + 1)) % b;
	} 

	long long ans = 0;
	if (hesh == h[m - 1]) ans++;
	for (int l = m; l < n; l++) {
		long long cur = (h[l] - (h[l - m] * p[m]) % b + b) % b;
		if (hesh == cur) ans++;
	}

	cout << ans;
	return 0;
}
