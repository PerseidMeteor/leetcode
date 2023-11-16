#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        int flag = 1;//1正数，0负数

        while(str[start] == ' ')//查找起始位置
            ++start;
        
        if(str[start] == '-' || str[start] == '+'){//+ 或者 -
            flag = str[start]=='-'? -1: 1; 
            ++start;
        }

        int i = start;
        int tmp = 0;

        while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
            if(tmp > INT_MAX / 10 || tmp == INT_MAX/10 && (str[i] - '0' > 7))
                return (flag+1) ? INT_MAX : INT_MIN;
            tmp = tmp * 10 + str[i] - '0';
            ++i;
        }

        return flag * tmp;
    }
};

int main(){

    Solution x;
    cout << x.myAtoi("21474836460");

    return 0;
}

// class Solution {
// public:
//     int myAtoi(string s) {
//         int res = 0, sign = 1,i = 0, n = s.length();
//         while(s[i++]==' ');i--;                 //跳过空格
//         if(i<n && (s[i]=='+' || s[i]=='-')){    //判断符号
//             sign = s[i]=='-'? -1: 1;   
//             i++;
//         }
//         for(;i<n;++i){
//             if(s[i]>='0' && s[i]<='9'){         //处理数字
//                 if(res>INT_MAX/10 || res==INT_MAX/10 && (s[i]-'0' > 7)){ //即将溢出
//                     return (sign+1)? INT_MAX: INT_MIN;
//                 }
//                 res = res*10 + (s[i]-'0');
//             }else{                              //其他符号
//                 break;
//             }
//         }
//         return res * sign;
//     }
// };