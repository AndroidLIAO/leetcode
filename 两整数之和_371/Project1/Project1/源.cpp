#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        //判断条件：当无进位时，最终结果就是无进位相加结果
        while (b) {
            auto carry=((unsigned)a & b) << 1;
            a = a ^ b;    //得到无进位相加
            b = carry;
        }
        return a;
    }
};