#include <iostream>

using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        int len = s.length();
        string result; 
		result.resize(len,0);
        int p = 0, j =0;
        int step = 2 * (nRows-1);
        for (int i = 0; i< nRows; i++) {
            if (i == 0 || i == nRows -1) {
                j = i;
                while(j < len){
                    result[p++] = s[j];
                    j += step;
                }
            } else {
                j = i;
				int k = step - i;
                while(j < len || k < len){
					if (j < len) 
						result[p++] = s[j];
                    if (k < len)
						result[p++] = s[k];
					 
                    j += step;
					k+=step;
                }
                 
            }
        }
        return result;
    }
};
int main(int argc, char *argv[]) {
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3);
}