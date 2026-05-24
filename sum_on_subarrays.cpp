#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<ll> nums(n + 1);
		int i;

		for (i = 1; i <= n && i < k; i++) {
			nums[i] = 2;
			k -= i;
		}

		nums[i++] = (k - i) * 2 + 1;
		for (; i <= n; i++) nums[i] = -1000;

		for (int i = 1; i <= n; i++) cout << nums[i] << " ";
		cout << "\n";
	}
}