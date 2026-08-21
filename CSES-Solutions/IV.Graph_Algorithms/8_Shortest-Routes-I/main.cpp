#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;
const long long maxi = 100001;
vector<pair<long long, int>> list[maxi];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int a = 0, b = 0;
		long long c = 0;
		cin >> a >> b >> c;
		list[a].push_back({ c, b });
	}
	priority_queue < pair<long long, int>, vector < pair<long long, int>>, greater<pair<long long, int>>> pq;
	vector<long long> ans(n + 1, INF);
	pq.push({ 0 , 1 });
	ans[1] = 0;
	while (!pq.empty()) {
		auto [c, a] = pq.top();pq.pop();
		if (c > ans[a]) continue; // если новая цена больше уже существующей то скип
		for (auto now : list[a]) {
			auto [cn, an] = now; // некст город и цена до него
			if (ans[a] + cn < ans[an]) { // если путь до города a + билет в некст город стоят меньше уже существующего пути для некст города, то
				ans[an] = ans[a] + cn;
				pq.push({ ans[an], an });
			}
		}
	}
	for (int l = 1; l <= n; l++) {
		cout << ans[l] << " ";
	}
	return 0;
}