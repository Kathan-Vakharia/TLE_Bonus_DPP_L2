#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
	string robotWithString(string s) {
		int n = s.size();
		// frequency map
		vector<int> cnt(26, 0);
		for (char c : s) {
			cnt[c - 'a']++;
		}

		string res = "";
		res.reserve(n); // preallocate memory

		stack<char> t;
		char minC = 'a';

		for (char ch : s) {
			t.push(ch);
			cnt[ch - 'a']--;

			// Update the minimum available character
			while (minC < 'z' && cnt[minC - 'a'] == 0) {
				minC++;
			}

			// Pop characters that are smaller than or equal to the smallest
			// remaining character
			while (!t.empty() && t.top() <= minC) {
				res.push_back(t.top());
				t.pop();
			}
		}

		return res;
	}
};