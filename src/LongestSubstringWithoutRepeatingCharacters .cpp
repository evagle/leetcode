#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if ( s == "" )
			return 0;
	    
	    // 记录每一个字符至今位置最后出现的位置
        int charPos[256];
        
        // 开始扫描前，每个字符出现位置为-1
		for(int i= 0 ;i<256; i++)
			charPos[i] = -1;
			
	    // 开始扫描前，最长字串为0
        int maxLen = 0; 
        // 开始扫描前，前一个字符结尾的最长字串长度为0
        int lastLen = 0; 
                
        // 从第一个开始
        for (int i = 0; i < s.length(); i++) {
            /**
             * 以s[i]结尾的最长字串长度计算方法：
             * 如果s[i-1]结尾的最长字串中包含s[i],那么len[i]=i- last_position[s[i]]
             * 否则就是s[i-1]结尾的字符串长度加1， len[i] = len[i-1] + 1
             */
            if (charPos[s[i]] >= i - lastLen) {
                lastLen = i - charPos[s[i]];
            } else {
                lastLen ++;
            }
			cout<<lastLen<<endl;
            if (maxLen < lastLen)
                maxLen = lastLen;
            charPos[s[i]] = i;
        }
        return maxLen;
    }
};
int main(int argc, char *argv[]) {
	Solution s;
	cout << s.lengthOfLongestSubstring("ruowzgiooobpple");
	
}