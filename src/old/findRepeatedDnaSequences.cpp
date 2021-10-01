#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
/** time out!
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<string, int> hash_map;
        int i = 0, j = i + 10;
        int len = s.size();
        while (i <= len - 10) {
            string str = s.substr(i, i + 10);
            auto search = hash_map.find(str);
            if (search != hash_map.end())
                search->second += 1;
            else
                hash_map.insert({str, 1});
        }
        for (auto item: hash_map) 
            if (item.second >= 2)
                ret.push_back(item.first);
        return ret;
    }
    */

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_set<string> hash_set;
        unordered_set<string> ans_set;
        for(int i = 0, n = s.size(); i<= n - 10; ++i){
            string str = s.substr(i, 10);
            std::cout << str << std::endl;
            if(hash_set.count(str) > 0)
                ans_set.insert(str);
            else 
                hash_set.insert(str);
        }
        for(auto item : ans_set)
            ret.push_back(item);
        return ret;
    }

};

int main()
{
    Solution s;
    auto ret = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto item: ret) {
        std::cout << item << std::endl;
    }
}


