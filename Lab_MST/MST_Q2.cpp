#include <bits/stdc++.h>
using namespace std;

int convertmapbit(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans |= (1 << (s[i] - 'a'));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = convertmapbit(v[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if ((arr[i]&arr[j]) == 0) {
                ans = max(ans, (int)(v[i].size() * v[j].size()));
            }

        }
    }

    cout << ans << endl;
    return 0;
}