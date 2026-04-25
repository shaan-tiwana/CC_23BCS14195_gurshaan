#include <bits/stdc++.h>

using namespace std;

int singleNumber(const vector<int>& nums) {
	int result = 0;
	for (int num : nums) {
		result ^= num;
	}
	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << singleNumber(nums) << '\n';
	return 0;
}
