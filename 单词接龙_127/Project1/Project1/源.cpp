#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> un_set(wordList.begin(), wordList.end());
        if (un_set.count(endWord)==0)return 0;
        //设置两个存储路径,并把起点和终点分别放入对应路径
        unordered_set<string> begin{ beginWord };
        unordered_set<string> end{ endWord };
        vector<bool> flag(wordList.size(), 0);
        int res = 2;
        while (!begin.empty()) {
            //存储下一层元素
            unordered_set<string> next;
            //寻找下一层元素
            for (auto word : begin) {
                for (int i = 0; i < wordList.size(); i++) {
                    int count = 0;
                    for (int j = 0; j < word.size(); j++) {
                        if (word[j] != wordList[i][j])count++;
                        if (count > 1)break;
                    }
                    if (count == 1) {
                        //如果该单词存在于从后面搜索的路径，则说明已经找到了
                        if (end.count(wordList[i]) != 0)return res;
                        if (flag[i] == false)next.insert(wordList[i]);
                        flag[i] = true;
                    }
                }
            }
            res++;
            begin = next;
            //每次都从路径最短的出发
            if (end.size() < begin.size())swap(begin, end);
        }
        return 0;
    }
};
int main() {
    vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
    Solution s;
    int res = s.ladderLength("hit", "cog", wordList);
    return 0;
}