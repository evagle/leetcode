/**
* Brian
* 2014.12.07
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        long long i = 10, j = 10;
        while (i <= x) { i *= 10;}
        i/= 10;
       
        bool res = true;
        while ( i >= j) {
            if (x/i%10 == x/(j/10)%10) {
                i /= 10;
                j *= 10;
            } else {
                res = false;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.isPalindrome(1874994781);
}