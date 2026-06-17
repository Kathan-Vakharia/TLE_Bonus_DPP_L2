#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int g = gcd(a, b);
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i] %= g;
	}

	sort(c.begin(), c.end());
	int ans = c[n - 1] - c[0];
	for (int i = 0; i < n - 1; i++) ans = min(ans, g + c[i] - c[i + 1]);

	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}