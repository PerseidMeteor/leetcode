#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxarea = 0;
        while(i < j){
            int curArea = min(height[i] , height[j]) * (j - i);
            maxarea = max(maxarea, curArea);
            height[i] < height[j] ? ++i : --j;
        }
        return maxarea;
    }
};

int main(){

    Solution x;
    vector<int> height = {2,3,4,5,18,17,6};
    cout << x.maxArea(height);

    return 0;
}
