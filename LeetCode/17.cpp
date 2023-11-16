#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); //sort
        int n = nums.size();

        int m1 = n / 2 - 1, m2 = n / 2;
        
        while(m1 > 0 || m2 < n){
            int l = m1 - 1, r = m2 + 1;
            while(l >= 0 && r < n){
                int sum = nums[l] + nums[m1] + nums[m2] + nums[r];
                if(sum == target){
                    cout << nums[l] << " " << nums[m1] << " " << nums[m2] << " " <<
                    nums[r] << " "<< endl;
                    //ans.push_back({nums[l], nums[m1], nums[m2], nums[r]});
                    --l;
                    ++r;
                }
                else if(sum < target)
                    ++r;
                else
                    --l;
            }

            (m1 + m2) / 2 ? --m1 : ++m2;
        }

        return ans;
    }
};

int main()
{
    Solution x;
    vector<int> nums = {1, 0, -1, 0, -2, 2};//-2 -1 0 0 1 2
    x.fourSum(nums,0);
    return 0;
}

