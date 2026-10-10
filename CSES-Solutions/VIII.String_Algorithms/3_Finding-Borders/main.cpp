#include <iostream>
#include <string>

using namespace std;

int ind = 1;
const long long a = 53;
const long long b = 1e9 + 7;
long long h[1000001];
long long st[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	st[0] = 1;
	for (int l = 1; l < 1000001; l++) {
		st[l] = st[l - 1] * a % b;
	}

	string s;
	cin >> s;
	int n = s.size();
	for (auto now : s) {
		h[ind] = (h[ind - 1] * a + (now - 'a' + 1)) % b;
		ind++;
	}

	for (int l = 1; l < n; l++) {
		long long pref = h[l];
		long long suf = (h[n] - (h[n - l] * st[l]) % b + b) % b;

		if (pref == suf) cout << l << " ";
	}

	return 0;
}