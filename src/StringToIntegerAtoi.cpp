/**
* Brian
* 2014.12.7
*/
#include <iostream>

using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str);
        if (str == NULL || len == 0) {
            return 0;
        }
        long long res = 0;
        int factor = 1;
        int i = 0;
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (str[i] == '+') {
            factor = 1;
            i++;
        } else if (str[i] == '-') {
            factor = -1;
            i++;
        }
        
        for (; i < strlen(str); i++) {
            if (str[i] >= '0' && str[i] <= '9'){
                res = res * 10 + str[i] - '0';
				if (res * factor > INT_MAX) {
					res = INT_MAX;
					break;
				}
				if (res * factor < INT_MIN) {
					res = -INT_MIN;
					break;
				}
			}
            else
                break;
        }
  
        return res * factor ;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.atoi("-9223372036854775809");
}