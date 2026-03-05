#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    unordered_map<string, int> freq;
    int lines;
    cin >> lines;
    
    for(int i = 0; i<lines; i++){
        string inn;
        cin >> inn;
        freq[inn]++;
    }
    int max_val = -1;
    string max_str;
    for (const auto& [str, count] : freq) {
        if (count > max_val) {
            max_val = count;
            max_str = str;
        }
    }
    cout<<max_str;
    return 0;
}
