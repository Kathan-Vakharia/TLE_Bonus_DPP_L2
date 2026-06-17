#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
	int r, c;
	cin >> r >> c;

	vvi A(r, vector<int>(c)), B(r, vector<int>(c));
	for (auto& row : A)
		for (auto& x : row) cin >> x;
	for (auto& row : B)
		for (auto& x : row) cin >> x;

	vvi res(r, vector<int>(c, INT_MIN));

	const int dx[] = {-1, 1, 0, 0};
	const int dy[] = {0, 0, -1, 1};

	// Recursive lambda — captures everything by reference
	auto compute = [&](auto& self, int i, int j) -> void {
		if (i < 0 || j < 0 || i >= r || j >= c || res[i][j] != INT_MIN) return;
		res[i][j] = A[i][j] + B[i][j];
		for (int d = 0; d < 4; d++) self(self, i + dx[d], j + dy[d]);
	};

	compute(compute, 0, 0);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cout << res[i][j] << " ";
		cout << "\n";
	}
}

// Solution 2
void compute(vvi& A, vvi& B, vvi& res, int i, int j) {
	if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || res[i][j] != -1e3)
		return;

	res[i][j] = A[i][j] + B[i][j];
	compute(A, B, res, i - 1, j);
	compute(A, B, res, i + 1, j);
	compute(A, B, res, i, j - 1);
	compute(A, B, res, i, j + 1);
}
int main_fn_2() {
	int r, c;
	cin >> r >> c;

	vvi A(r, vi(c)), B(r, vi(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> A[i][j];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> B[i][j];

	vvi res(r, vi(c, -1e3));
	compute(A, B, res, 0, 0);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}