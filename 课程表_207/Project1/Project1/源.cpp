#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int>intgree;//每个点的入度
    vector<vector<int>> g;//图
    int n;//图中节点个数
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses, vector<int>(0));//初始化图
        intgree = vector<int>(numCourses, 0);
        for (auto& pre : prerequisites) {//构建图
            g[pre[1]].push_back(pre[0]);
            intgree[pre[0]]++;
        }
        n = numCourses;
        return topological();
    }

    bool topological() {  //拓扑排序
        int num = 0;
        deque<int> d;
        //将入度为0的节点放进队列中
        for (int i = 0; i < n;i++) {
            if (intgree[i] == 0)d.push_back(i);
        }
        while (!d.empty()) {
            int u = d.front();
            d.pop_front();
            //删除边u->v（即删除v的入度）
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (--intgree[v] == 0) d.push_back(v);
            }
            //加入拓扑序列的节点数加1
            num++;
        }
        return num == n;
    }
};