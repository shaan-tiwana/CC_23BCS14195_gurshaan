#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    for (int i = 0; i < n - 1; i++) {
        string a = words[i];
        string b = words[i + 1];

        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                indegree[b[j] - 'a']++;
                found = true;
                break;
            }
        }

        // Check invalid prefix case
        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // Topological sort (Kahn's algorithm)
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result += char(u + 'a');

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
