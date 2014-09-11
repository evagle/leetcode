/**
* Brian
* 2014.9.11
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::map<int, vector<int>> smap ;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            if (smap.find(numbers.at(i)) != smap.end()) {
                smap[numbers.at(i)].push_back( i + 1);
            } else {
                vector<int> tmp ;
                tmp.push_back(i + 1);
                smap[numbers.at(i)] = tmp;
            }
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            int v = numbers.at(i);
            
            if (smap.find(target - v) != smap.end()) {
                vector<int> matched = smap[target - v];
                for (int k = 0; k < matched.size(); k++) {
                    if (matched.at(k) > i+1) {
                        result.push_back(i+1);
                        result.push_back(matched.at(k));       
                        break;
                    }
                } 
            }
            if (result.size() > 0)
                break;
        }
        return result;   
    }
};

int main()
{
   
   Solution s;
   vector<int> numbers;
   numbers.push_back(0);
   numbers.push_back(2);
   numbers.push_back(4);
   numbers.push_back(0);
   
   vector<int> a = s.twoSum(numbers , 0);
   if (a.at(0) > a.at(1)) {
       swap(a[0], a[1]);
   }
   for (int i = 0; i < a.size(); i++) {
       cout<< a.at(i) << endl;
   }
   return 0;
}
