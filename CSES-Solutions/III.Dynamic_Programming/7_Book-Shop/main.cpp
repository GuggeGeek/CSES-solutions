#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, x = 0;
	cin >> n >> x; // Кол-во книг. Бюджет
	vector<int> s(n, 0), h(n, 0); // кол-во страниц книги. цена книги.
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> s[i];
	
	vector<int> value(x + 1, 0);
	for (int j = 0; j < n; j++) {
		for (int i = x; i >= h[j]; i--) {
			value[i] = max(value[i], (value[i - h[j]] + s[j]));
		}
	}
	cout << *max_element(value.begin(), value.end());
	return 0;
}