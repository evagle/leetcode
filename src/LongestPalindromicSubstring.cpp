#include <iostream>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int len = 0;
		int start = 0;
        int slen = s.length();
        // 处理aba的情况
        for (int i = 0; i < slen; i++){
            len = 0;
            int j = 0;
            for (j = 1; j < std::min(slen-i, i+1); j++) {
                if (s[i+j] != s[i-j]) {
                    break;
                }
            }
			j -= 1;
            if (j*2+1 > maxLen) {
                maxLen = j*2+1;
				start = i - j;
            }
        }
        // 处理abba的情况
        for (int i = 1; i < slen; i++){
            if (s[i] == s[i-1]) {
                len = 0;
                int j = 0;
                for (j = 1; j < std::min(i,slen-i); j++) {
                    if (s[i-1-j] != s[i+j]) {
                        break;
                    }
                }
				j -= 1;
                if (j*2+2 > maxLen) {
                    maxLen = j*2+2;
					start = i - 1 - j;
                }
            }
            
        }
		//cout<<start<<"  "<<maxLen<<endl;
        return s.substr(start, maxLen);
        
    }
};
int main(int argc, char *argv[]) {
	Solution s;
	cout<<s.longestPalindrome("aaaaaa");
}