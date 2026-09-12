#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int base = 1 << 19;
int n = 0;
vector<int> st(2 * base);
vector<long long> first;
vector<long long> origin;

void add(int k, int type) {
	st[k] += type;
	while (k > 1) {
		if (k % 2 == 0) st[k / 2] = st[k] + st[k + 1];// стоит слева
		else st[k / 2] = st[k] + st[k - 1];
		k /= 2;
	}
}

long long range_sum(int a, int b) {
	long long s = 0;
	while (a <= b) {
		if (a % 2 == 1) s += st[a++];
		if (b % 2 == 0) s += st[b--];
		a /= 2;
		b /= 2;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	vector<tuple<bool, long long, long long>> test(q, tuple(false, 0,0)); // если ? то false , если ! то true
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		origin.push_back(x);
	}
	first = origin; // first - изначальный массив

	for (int l = 0; l < q; l++) {
		char x;
		cin >> x;
		if (x == '?') {
			long long a = 0, b = 0;
			cin >> a >> b;
			test[l] = tuple(false,a, b);
		}
		else {
			long long ch = 0;
			int k = 0;
			cin >> k >> ch;
			test[l] = tuple(true, k, ch);
			origin.push_back(ch);
		}
	}

	sort(origin.begin(), origin.end());
	origin.erase(unique(origin.begin(), origin.end()), origin.end()); // магическая строчка удаляющая все дубликаты при условиии сортировки массива

	for (int l = 0; l < first.size(); l++) {
		int k = (lower_bound(origin.begin(), origin.end(), first[l])) - origin.begin(); // находим индекс числа из массива
		add(k + base, 1);
	}

	for (auto now : test) {
		auto [type, a, b] = now;
		if (type == false) { // ?
			a = lower_bound(origin.begin(), origin.end(), a) - origin.begin(); // позиция a в дереве отрезков
			b = upper_bound(origin.begin(), origin.end(), b) - origin.begin() - 1; // позиция b в дереве отрезков
			if (a <= b) {
				cout << range_sum(a + base, b + base) << "\n";
			}
			else cout << 0 << "\n";
		}
		else { // !
			a--;
			long long old = first[a];
			
			long long olds = lower_bound(origin.begin(), origin.end(), old) - origin.begin();
			add(olds + base, -1);
			first[a] = b;

			int nov = lower_bound(origin.begin(), origin.end(), b) - origin.begin();
			add(nov + base, 1);
		}
	}

	return 0;
}