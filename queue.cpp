#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;

	vector<int> ages(n + 1);
	for (int i = 1; i <= n; i++) cin >> ages[i];

	vector<pair<int, int>> vec; // Stores {age, index}
	vector<int> ans(n + 1);

	for (int i = n; i >= 1; i--) {
		// Find the first element in vec such that vec.age < ages[i]
		// Since vec is strictly decreasing, we use greater<>()
		// to find the first element 'smaller' than ages[i].
		auto it = upper_bound(vec.begin(), vec.end(), make_pair(ages[i], i),
													greater<pair<int, int>>());

		if (it == vec.end())
			ans[i] = -1; // No element to the right is smaller
		else
			ans[i] = it->second - i - 1;

		// Only add to vec if this age is smaller than the current smallest
		// (vec.back()) This maintains the strictly decreasing order needed for
		// binary search.
		if (vec.empty() || ages[i] < vec.back().first) {
			vec.push_back({ages[i], i});
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "" : " ");
	cout << endl;
}