#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> un_set(wordList.begin(), wordList.end());
        if (un_set.count(endWord)==0)return 0;
        //���������洢·��,���������յ�ֱ�����Ӧ·��
        unordered_set<string> begin{ beginWord };
        unordered_set<string> end{ endWord };
        vector<bool> flag(wordList.size(), 0);
        int res = 2;
        while (!begin.empty()) {
            //�洢��һ��Ԫ��
            unordered_set<string> next;
            //Ѱ����һ��Ԫ��
            for (auto word : begin) {
                for (int i = 0; i < wordList.size(); i++) {
                    int count = 0;
                    for (int j = 0; j < word.size(); j++) {
                        if (word[j] != wordList[i][j])count++;
                        if (count > 1)break;
                    }
                    if (count == 1) {
                        //����õ��ʴ����ڴӺ���������·������˵���Ѿ��ҵ���
                        if (end.count(wordList[i]) != 0)return res;
                        if (flag[i] == false)next.insert(wordList[i]);
                        flag[i] = true;
                    }
                }
            }
            res++;
            begin = next;
            //ÿ�ζ���·����̵ĳ���
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