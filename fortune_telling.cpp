#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		ll x, y;
		cin >> n >> x >> y;

		vector<ll> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		ll sum = accumulate(arr.begin(), arr.end(), 0LL);

		if ((sum + x + y) % 2 == 0)
			cout << "Alice" << '\n';
		else
			cout << "Bob" << '\n';
	}
}