#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); //sort
        int sum = 0, n = nums.size();

        for (int i = 0; i < n - 2; ++i){

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    //cout << nums[i] << " " << nums[l] << " " << nums[r] << " " << endl;
                    ++l;
                    --r;
                }
                else if (sum < 0)
                    ++l;
                else
                    --r;
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};

int main()
{

    Solution x;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};//-4,-1,-1,0,1,2
    x.threeSum(nums);

    return 0;
}
