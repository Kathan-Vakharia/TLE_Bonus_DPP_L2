#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
 public:
	int waysToSplit(vector<int>& nums) {
		int n = nums.size();
		int M = 1e9 + 7;
		vector<int> psum(n);
		psum[0] = nums[0];

		for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + nums[i];

		ll ans = 0;
		int l = 0, r = 0;
		// i can go up to n - 3, leaving at least 1 element for mid and 1 for right
		for (int i = 0; i < n - 2; i++) {
			l = max(l, i + 1);
			r = max(r, i + 1);
			while (l < n - 1 && psum[l] < 2 * psum[i]) l++;

			while (r < n - 1 && psum[r] <= (psum[i] + psum[n - 1]) / 2) r++;

			if (l <= r) ans = (ans + (r - l)) % M;
		}
		return ans;
	}
	int waysToSplit_BS(vector<int>& nums) {
		int n = nums.size();
		int M = 1e9 + 7;
		vector<int> psum(n);
		psum[0] = nums[0];

		for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + nums[i];

		ll ans = 0;

		// i can go up to n - 3, leaving at least 1 element for mid and 1 for
		// right
		for (int i = 0; i < n - 2; i++) {
			// Search space ends at psum.begin() + n - 1 to ensure 'right' is
			// not empty
			auto it1 =
					lower_bound(psum.begin() + i + 1, psum.begin() + n - 1, 2 * psum[i]);
			int l = it1 - psum.begin();

			// upper_bound finds the FIRST invalid 'X'
			auto it2 = upper_bound(psum.begin() + l, psum.begin() + n - 1,
														 (psum[i] + psum[n - 1]) / 2);
			int r = it2 - psum.begin();

			// If we found valid bounds, the number of valid 'mid' splits is
			// exactly r - l
			if (l < r) {
				ans = (ans + (r - l)) % M;
			}
		}
		return ans;
	}
};
