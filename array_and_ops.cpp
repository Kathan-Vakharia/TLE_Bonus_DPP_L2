#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	ll sum = 0;
	// accumulate the elements that will be untouched
	for (int i = 0; i < n - 2 * k; i++) sum += arr[i];
	// optimally pair-up last 2k elements
	for (int i = n - 2 * k; i < n - k; i++) sum += (arr[i] / arr[i + k]);
	cout << sum << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}