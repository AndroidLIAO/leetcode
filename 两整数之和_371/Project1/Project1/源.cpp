#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        //�ж����������޽�λʱ�����ս�������޽�λ��ӽ��
        while (b) {
            auto carry=((unsigned)a & b) << 1;
            a = a ^ b;    //�õ��޽�λ���
            b = carry;
        }
        return a;
    }
};