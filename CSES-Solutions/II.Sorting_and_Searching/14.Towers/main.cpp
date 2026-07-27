#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector <long long> array;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		auto it = upper_bound(array.begin(), array.end(), x); // первое число больше  x
		if (it == array.end()) {
			array.push_back(x); // Не нашли башню, строим новую
		}
		else {
			*it = x; // Нашли башню, кладем кубик сверху (заменяем верхушку)
		}
	}
	cout << array.size();
	return 0;
}