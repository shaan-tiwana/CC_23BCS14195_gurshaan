#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n <= 2) return n;
        
        int ans = 2;
        
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n ; j++){
                int temp = 2;
                for(int k = j + 1 ; k < n ; k++ ){                   
                    int x = (points[j][1] - points[i][1]) * (points[k][0] - points[i][0]);
                    int y = (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]);
                    
                    if(x == y){
                        temp++;
                    }
                }
                
                ans = max(ans, temp);
            }
        }   
        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    
    int result = obj.maxPoints(points);
    
    cout << "Output: " << result << endl;

    return 0;
}
