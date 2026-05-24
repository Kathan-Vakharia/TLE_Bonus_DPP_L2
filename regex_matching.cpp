#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
	bool f(string& s, string& p, int i, int j) {
		if (j >= p.size()) return i >= s.size();

		// case when first character of s is matches
		bool c1 = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

		if (j + 1 < p.size() && p[j + 1] == '*') {
			return f(s, p, i, j + 2) || (c1 && f(s, p, i + 1, j));
		} else {
			return c1 && f(s, p, i + 1, j + 1);
		}
	}

 public:
	bool isMatch(string s, string p) { return f(s, p, 0, 0); }
};