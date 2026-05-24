#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
	int target;

	bool backtrack(vector<int>& sticks, int index, vector<int>& sides) {
		// Base case: All sticks have been placed
		if (index == sticks.size()) {
			return (sides[0] == sides[1]) && (sides[1] == sides[2]) &&
						 (sides[2] == sides[3]);
		}

		for (int j = 0; j < 4; ++j) {
			// Optimization 2: Skip if adding the stick exceeds the target length
			if (sides[j] + sticks[index] > target) continue;

			// Standard backtracking step
			sides[j] += sticks[index];
			if (backtrack(sticks, index + 1, sides)) return true;
			sides[j] -= sticks[index];
		}
		return false;
	}

 public:
	bool makesquare(vector<int>& matchsticks) {
		if (matchsticks.size() < 4) return false;

		long long total_sum =
				accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
		if (total_sum % 4 != 0) return false;

		target = total_sum / 4;

		// Optimization 1: Sort descending.
		// Placing larger sticks first fills up the "target" faster and hits
		// failures earlier.
		sort(matchsticks.begin(), matchsticks.end(), greater<int>());

		vector<int> sides(4, 0);
		return backtrack(matchsticks, 0, sides);
	}
};