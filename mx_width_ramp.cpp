#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
class Solution_1 {
 public:
	int maxWidthRamp(vector<int>& nums) {
		vector<pii> vec;
		int ans = 0;
		int n = nums.size();
		for (int i = n - 1; i >= 0; i--) {
			auto it = lower_bound(vec.begin(), vec.end(), make_pair(nums[i], i));

			if (it == vec.end()) {
				vec.push_back(make_pair(nums[i], i));
			} else {
				ans = max(ans, it->second - i);
			}
		}
		return ans;
	}
};

class Solution2 {
 public:
	int maxWidthRamp(vector<int>& nums) {
		int n = nums.size(), ans = 0;

		// store possible left bounds in the stack
		stack<int> st;
		for (int i = 0; i < n; i++)
			if (st.empty() || nums[st.top()] > nums[i]) st.push(i);

		for (int j = n - 1; j >= 0; j--) {
			while (!st.empty() && nums[st.top()] <= nums[j]) {
				ans = max(ans, j - st.top());
				st.pop();
			}
		}

		return ans;
	}
};