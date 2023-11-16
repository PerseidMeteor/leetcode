#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        //woshini
        if(m == 0)
            return n % 2 == 1 ? nums2[n/2]:(double)(nums2[n/2] + nums2[(n-1)/2])/2;
        
        if(n == 0)
            return m % 2 == 1 ? nums1[m/2]:(double)(nums1[m/2] + nums1[(m-1)/2])/2;


        int j = 0,k = 0 ;
        int mid1 = -1, mid2 = -1;

        for(int i = 0; i <= (m + n) / 2; i++){
            mid1 = mid2;
            if(j < m && (k >= n || nums1[j] <= nums2[k]))
                mid2 = nums1[j++];
            else
                mid2 = nums2[k++];
        }
        cout << mid1 << mid2 << endl;
        if((m + n) % 2)
            return mid2;
        else
            return (double)(mid1+mid2) / 2;
    }
};

int main(){
    Solution x;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    cout << x.findMedianSortedArrays(nums1, nums2) << endl;
}