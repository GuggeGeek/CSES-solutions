#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;
long long factorio[1000001];

long long st(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return st(a, b - 1) * a % mod;
	long long h = st(a, b / 2);
	return h * h % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	factorio[1] = 1; factorio[0] = 1;
	for (int l = 2; l < 1000001; l++) factorio[l] = factorio[l - 1] * l % mod;

	vector<int> alf(26 , 0);
	string str;
	getline(cin, str);
	for (auto now : str) alf[now - 'a']++;

	int n = str.size();

	long long k = 1;
	for (int l = 0; l < 26; l++) {
		k = k * factorio[alf[l]] % mod; // значение выражения k1! * k2! * ... * kn!(1 , 2 , n - номер k, а не множитель)
	}

	cout << factorio[n] * st(k, mod - 2) % mod; // деление по простому модулю

	return 0;
}