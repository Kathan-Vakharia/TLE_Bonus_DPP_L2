#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Safer get_sum that prevents intermediate overflow
ll get_sum(ll s, ll e) {
	if (s > e) return 0;

	ll n = e - s + 1;

	// Divide by 2 before multiplying to keep numbers small
	if (n % 2 == 0) {
		return (n / 2) * (s + e);
	} else {
		return n * ((s + e) / 2);
	}
}

void solve() {
	ll n, k;
	cin >> n >> k;

	ll lo = 0, hi = n - 1;
	ll ans = LLONG_MAX;

	while (lo <= hi) {
		ll m = lo + (hi - lo) / 2;

		ll mval = get_sum(k, k + m) - get_sum(k + m + 1, k + n - 1);

		// Always track the minimum absolute difference
		ans = min(ans, abs(mval));

		if (mval == 0) {
			// Perfect match found, no need to search further
			break;
		} else if (mval < 0) {
			lo = m + 1;
		} else {
			hi = m - 1;
		}
	}

	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}