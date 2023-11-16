#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        std::size_t i = 0, j = 0;

        while(i < s.length() && j < p.length()){

            if(i >= s.length() || j >= p.length())
                break;

            if(s[i] == p[j] || p[j] == '.'){   //相同字母
                 ++i;
                 ++j;           //两者都 +1
            }
            else if(p[j] == '*'){//匹配到*
                while(i < s.length() && (s[i] == p[j - 1] || p[j - 1] == '.'))
                    ++i;
                ++j;             //p向后一位
            }
            else if(p[j+1] == '*'){// s"aab"  p"c*a*b"
                j += 2;
                ++i;
            }
            else
                break;
        }

        return i == s.length() && j == p.length();
    }
};

int main(){

    Solution x;
    cout << x.isMatch("aab","c*a*b");

    return 0;
}


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         vector<string> ps;
//         Tokenize(p, ps, "*");

//         int i = 0, j = 0, k = 0;//iter for s and ps

//         while(i < s.length()){

//             while(1){

//                 if(i >= s.length() || k >= ps[j].length())
//                     return false;

//                 if(s[i] == ps[j][k]){//相同字母
//                     ++k; ++i;//两者都 +1
//                 }
//                 else if(ps[j][k] == '*'){//匹配到*
//                     if(s[i] != s[i - 1])
//                         return false;    //不同返回false
//                     ++i;             //相同则+1
//                 }
//                 else
//                     return false;
//             }
//             ++j;//next p
//             k = 0;
//         }

//         return true;
//     }
    
//     void Tokenize(const string& str, vector<string>& tokens, const string& delimiters){
//         // Skip delimiters at beginning.
//         string::size_type lastPos = str.find_first_not_of(delimiters, 0);
//         // Find first "non-delimiter".
//         string::size_type pos     = str.find_first_of(delimiters, lastPos);
//         while (string::npos != pos || string::npos != lastPos){
//             // cout << pos <<"   "<< lastPos << endl;
//             // Found a token, add it to the vector.
//             // plus 1 can save the delimiter,or not save
//             tokens.push_back(str.substr(lastPos, pos - lastPos + 1));
//             // Skip delimiters.  Note the "not_of"
//             lastPos = str.find_first_not_of(delimiters, pos);
//             // Find next "non-delimiter"
//             pos = str.find_first_of(delimiters, lastPos);
//         }
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};