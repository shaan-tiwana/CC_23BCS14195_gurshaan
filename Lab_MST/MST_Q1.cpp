#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> in(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
    }

    sort(in.begin(), in.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += in[i][0];
    }

    long long left = in[0][1], right = sum, ans = sum;
    while (left <= right) {
        long long mid = (left + right) / 2;
        bool check = false;
        long long temp = mid;
        for (int i = 0; i < n; i++) {
            if (temp < in[i][1])
                check = true;

            temp -= in[i][0];
        }

        if(check)
            left = mid + 1;
        else
            right = mid;
    }
    cout << ans+1;
    return 0;
}