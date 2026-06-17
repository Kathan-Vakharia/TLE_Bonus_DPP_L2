#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<pair<int, ll>> arr(n + 1);
	ll pi = 0, si = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		si += arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());

	vector<ll> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		// Get prefix[i], suffix[i]
		ll s = arr[i].first;
		pi += s;
		si -= s;

		ans[arr[i].second] = s * (2 * i - n) - pi + si + n;
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}