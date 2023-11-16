#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> button = {
        {"a", "b", "c" },{"d", "e", "f" },{"g", "h", "i" },{"j", "k", "l" },
        {"m", "n", "o" },{"p", "q", "r", "s"},{"t", "u", "v" },{"w", "x", "y", "z"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size() == 0)
            return ans;
        
        if(digits.size() == 1)
            return button[digits[0] - '2'];
            
        ans = button[digits[0] - '2'];
        for(std::size_t i = 1;i < digits.size(); ++i)
            ans = Mymultiple(ans, button[digits[i] - '2']);
        
        return ans;
    }
    vector<string> Mymultiple(vector<string> op1,vector<string> op2){
        vector<string>* ans = new vector<string>(op1.size() * op2.size());
        for(std::size_t i = 0;i < op1.size();++i){
            for(std::size_t j = 0;j < op2.size();++j){
                ans -> at(i * op2.size() + j) += op1[i];
                ans -> at(i * op2.size() + j) += op2[j];
            }
        }
        return *ans;
    }
};
int main()
{
    // Solution x;
    // x.letterCombinations("234");
    int64_t a = 50000 * 50000;
    cout << a;
    return 0;
}
