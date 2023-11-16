#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        int q = num / 1000;
        num %= 1000;
        while(q--)
            ans += 'M';

        int b = num / 100;
        num %= 100;

        if(b == 9)
            ans += "CM";
        else if(b == 4)
            ans += "CD";
        else {
            if(b >= 5){
                ans += 'D';
                b -= 5;
            }
            while(b--)
                ans += 'C';
        }

        int s = num / 10;
        num %= 10;

        if(s == 9)
            ans += "XC";
        else if(s == 4)
            ans += "XL";
        else {
            if(s >= 5){
                ans += 'L';
                s -= 5;
            }
            while(s--)
                ans += 'X';
        }

        if(num == 9)
            ans += "IX";
        else if(num == 4)
            ans += "IV";
        else {
            if(num >= 5){
                ans += 'V';
                num -= 5;
            }
            while(num--)
                ans += 'I';
        }

        return ans;
    }
};

int main(){

    Solution x;
    cout << x.intToRoman(1994) << endl;

    return 0;
}
