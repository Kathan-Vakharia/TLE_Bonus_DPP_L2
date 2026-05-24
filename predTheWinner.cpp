#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
	bool f(vector<int>& nums, int st, int ed, int score1, int score2, int p1) {
		if (st > ed) return score1 >= score2;

		if (p1)
			return f(nums, st + 1, ed, score1 + nums[st], score2, 0) ||
						 f(nums, st, ed - 1, score1 + nums[ed], score2, 0);
		else
			return f(nums, st + 1, ed, score1, score2 + nums[st], 1) &&
						 f(nums, st, ed - 1, score1, score2 + nums[ed], 1);
	}

 public:
	bool predictTheWinner(vector<int>& nums) {
		int score1 = 0, score2 = 0;
		int st = 0, ed = nums.size() - 1;

		return f(nums, 0, nums.size() - 1, score1, score2, 1);
		;
	}
};