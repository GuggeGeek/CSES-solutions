#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
vector<long long> st;
long long maxi = 1 << 18;

void add(int k, long long x) {
	st[k] += x;
	while (k > 1) {
		if (k % 2 == 1) st[k / 2] = max(st[k], st[k - 1]); // стоит справа 
		else st[k / 2] = max(st[k], st[k + 1]);
		k /= 2;
	}
}

int search(long long r) {
	int k = 1;
	while (k < maxi) {
		if (st[k * 2] >= r) k *= 2; // левый путь больше или равен нашему числу
		else k = k * 2 + 1; // иначе правый путь гарантировано содержит нужное число
	}
	add(k, -r);
	return k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m = 0;
	cin >> n >> m;
	st.assign(maxi * 2, 0);
	for (int l = 1; l <= n; l++) {
		long long x = 0;
		cin >> x;
		add(l + maxi - 1, x);
	}

	for (int l = 1; l <= m; l++) {
		long long r = 0;
		cin >> r;
		if (r > st[1]) cout << 0 << " ";
		else cout << (search(r) + 1 - maxi) << " ";
	}

	return 0;
}