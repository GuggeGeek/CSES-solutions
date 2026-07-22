#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int n = 0, m = 0; // n соискатели , m квартиры
	long long k = 0; // максимально допустимая разница в желаемом и искомом  ... a желаемый размер . b искомый размер
	cin >> n >> m >> k;
	vector <long long> L(n), R(m);

	for (int l = 0; l < n; l++) cin >> L[l];
	for (int l = 0; l < m; l++) cin >> R[l];

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int i = 0, j = 0, ch = 0;;
	while (i < n && m > j) {
		if (R[j] < L[i] - k) {
			j++;
		}
		else if (R[j] > L[i] + k) {
			i++;
		}
		else {
			ch++;
			i++;
			j++;
		}
	}
	cout << ch;
	return 0;
}