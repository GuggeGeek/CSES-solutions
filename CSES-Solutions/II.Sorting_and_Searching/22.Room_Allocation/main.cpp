#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct man {
	long long in;
	long long out;
	int number;

	bool operator<(const man& other)const {
		return in < other.in;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long ans = 0;
	cin >> n;
	set <pair<long long, int>> p;
	vector <int> room(n + 1);
	vector <man> list;
	for (int l = 1; l <= n; l++) {
		long long a = 0, b = 0;
		cin >> a >> b;
		list.push_back(man(a, b, l));
	}
	sort(list.begin(), list.end());
	for (auto now : list) { 
		if (!p.empty()) {
			auto it = *p.begin();
			if (it.first >= now.in) { // номеров нет, создаём новый
				ans++;
				p.insert(pair(now.out, ans));
				room[now.number] = ans;
			}
			else {
				p.insert(pair(now.out, it.second));
				p.erase(p.begin());
				room[now.number] = it.second;
			}
		}
		else {
			ans++;
			p.insert(pair(now.out, ans));
			room[now.number] = ans;
		}
	}
	cout << ans << "\n";
	bool skip = false;
	for (auto const& now : room)
		if (skip) cout << now << " ";
		else skip = true;
	return 0;
}