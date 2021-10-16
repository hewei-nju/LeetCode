
/*

设计LRU(最近最少使用)缓存结构，该结构在构造时确定大小，假设大小为 k ，并有如下两个功能
1. set(key, value)：将记录(key, value)插入该结构
2. get(key)：返回key对应的value值

提示:
1.某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的，然后都会刷新缓存。
2.当缓存的大小超过k时，移除最不经常使用的记录。
3.输入一个二维数组与k，二维数组每一维有2个或者3个数字，第1个数字为opt，第2，3个数字为key，value
若opt=1，接下来两个整数key, value，表示set(key, value)
若opt=2，接下来一个整数key，表示get(key)，若key未出现过或已被移除，则返回-1
对于每个opt=2，输出一个答案
4.为了方便区分缓存里key与value，下面说明的缓存里key用""号包裹

要求：set和get操作复杂度均为 O(1)O(1)
*/

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int>>& operators, int k)
    {
        // write code here
        vector<int> res;
        for (auto op : operators) {
            if (op[0] == 1) {
                if (hsmap.find(op[1]) == hsmap.end()) {
                    if (lst.size() == k) {
                        hsmap.erase(lst.back());
                        lst.pop_back();
                    }
                    hsmap.insert({ op[1], op[2] });
                    lst.push_front(op[1]);
                } else {
                    lst.remove(op[1]);
                    lst.push_front(op[1]);
                    hsmap[op[1]] = op[2];
                }

            } else if (op[0] == 2) {
                cout << op[1] << " ";
                if (hsmap.find(op[1]) != hsmap.end()) {
                    lst.remove(op[1]);
                    lst.push_front(op[1]);
                    res.push_back(hsmap[op[1]]);
                } else
                    res.push_back(-1);
            }
        }
        return res;
    }

private:
    list<int> lst;
    unordered_map<int, int> hsmap;
};