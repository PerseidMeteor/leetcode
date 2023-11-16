#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) 
            return false;

        int rev = 0;

        while (x && x > rev){
            rev = (x % 10) + rev * 10;
            x /= 10;
        }

        cout << x << "   " << rev << endl;
        return (x == rev || x == rev / 10) ? true : false;
    }
};


int main(){

    Solution x;
    cout << x.isPalindrome(10);

    return 0;
}
