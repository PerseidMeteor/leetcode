#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int len = s.size();
        int startleft = 0;//最长回文子串的左开始位置
        int startright = 0;//最长回文子串的右开始位置
        int maxhalflen = 0;//延展长度

        for(int i = 0;i < len; ++i){

            int left = 0,right = 0;

            if(s[i] == s[i + 1]){//无中心
                int k = i + 1;
                while(s[k] == s[i]){
                    ++k;
                }

                left = (k + i) / 2;
                right = (k + i + 1) / 2;
            }
            else//不对称
                continue;

            for(int j = 0;j <= i && j < len - i;++j){

                if(s[left - j] == s[right + j]){
                    if((j + right - left) > maxhalflen){
                        startleft = i;
                        startright = startleft + right - left;
                        maxhalflen = j;
                    }
                }
                else break;
            }

        }
        
        cout << startleft <<"**"<<startright<< "**" << maxhalflen << "**" << endl;
        return s.substr(startleft - maxhalflen, 2*maxhalflen+startright-startleft+1);
    }

};

int main(){
    Solution x;
    cout << x.longestPalindrome("aaaaa") << endl;

    return 0;
}