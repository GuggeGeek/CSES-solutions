#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;
long long best;

void dfs(int i, int n, long long sum_all, long long sum1) {
    if (i == n) {
        long long sum2 = sum_all - sum1;
        best = min(best, llabs(sum1 - sum2));
        return;
    }
    // вариант не брать a[i] в первую группу
    dfs(i + 1, n, sum_all, sum1);
    // вариант взять a[i] в первую группу
    dfs(i + 1, n, sum_all, sum1 + a[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    a.resize(n);
    long long sum = 0;
    for (int l = 0; l < n; ++l) {
        cin >> a[l];
        sum += a[l];
    }

    best = sum; // начально максимально возможная разность
    dfs(0, n, sum, 0);
    cout << best << '\n';
    return 0;
}