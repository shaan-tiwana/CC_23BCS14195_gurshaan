#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1, 3, 5};
    int n = A.size();
    const int MOD = 1e9 + 7;
    long long ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count_1 = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit))
                count_1++;
        }
        long long count_0 = n - count1;
        ans = (ans + (count1 * count0 * 2) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
