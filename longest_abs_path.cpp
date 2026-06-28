#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
	int lengthLongestPath(string input) {
		stringstream ss(input);
		string line;
		map<int, int> lengths;
		int ans = 0;

		while (getline(ss, line, '\n')) {
			// Now "line" is just a single chunk like "\t\tfile1.ext"

			// Get the size of component: directory/file
			int d = line.find_first_not_of('\t');
			int comp_size = line.substr(d).size();

			// this is a file
			if (line.find('.') != string::npos) {
				if (d == 0)
					ans = max(ans, comp_size);
				else
					ans = max(ans, lengths[d - 1] + 1 + comp_size);
			} else { // this is a directory; update lengths

				if (d == 0)
					lengths[d] = comp_size;
				else
					lengths[d] = 1 + comp_size + lengths[d - 1];
			}
		}

		return ans;
	}
}; // T: O(n*log(k)), S:O(n)