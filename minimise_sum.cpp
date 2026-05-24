#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define nl '\n'
#define sp ' '

void solve() {
	int n;
	cin >> n;

	vector<ll> arr(n);
	ll total_sum = 0;
	vi ids(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total_sum += arr[i];
		ids[i] = i; // Store indices to filter
	}

	// Greedy bit-masking from MSB to LSB
	for (int i = 29; i >= 0; i--) {
		vi survivors;
		for (int idx : ids) {
			if ((arr[idx] >> i) & 1) {
				survivors.push_back(idx);
			}
		}

		// If at least two numbers have the i-th bit set,
		// we restrict our search space to only those numbers.
		if (survivors.size() >= 2) {
			ids = std::move(survivors);
		}
	}

	// Any two remaining numbers in 'ids' will have the same maximum bitwise AND
	// ll max_and = arr[ids[0]] & arr[ids[1]];

	// cout << total_sum - (2 * max_and) << nl;
	cout << total_sum - (arr[ids[0]] + arr[ids[1]]) + (arr[ids[0]] ^ arr[ids[1]])
			 << nl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();
}