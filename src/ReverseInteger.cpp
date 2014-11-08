#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int y = abs(x);
        int ans = 0;
        while(y ) {
            ans = ans * 10 + (y % 10);
            y /= 10;
        }
        if (x < 0) 
            ans = -ans;
        return ans;
    }
};
int main(int argc, char *argv[]) {
	
}