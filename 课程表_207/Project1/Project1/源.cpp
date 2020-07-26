#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int>intgree;//ÿ��������
    vector<vector<int>> g;//ͼ
    int n;//ͼ�нڵ����
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses, vector<int>(0));//��ʼ��ͼ
        intgree = vector<int>(numCourses, 0);
        for (auto& pre : prerequisites) {//����ͼ
            g[pre[1]].push_back(pre[0]);
            intgree[pre[0]]++;
        }
        n = numCourses;
        return topological();
    }

    bool topological() {  //��������
        int num = 0;
        deque<int> d;
        //�����Ϊ0�Ľڵ�Ž�������
        for (int i = 0; i < n;i++) {
            if (intgree[i] == 0)d.push_back(i);
        }
        while (!d.empty()) {
            int u = d.front();
            d.pop_front();
            //ɾ����u->v����ɾ��v����ȣ�
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (--intgree[v] == 0) d.push_back(v);
            }
            //�����������еĽڵ�����1
            num++;
        }
        return num == n;
    }
};