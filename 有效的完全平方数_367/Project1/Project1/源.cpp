#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*暴力解法*/
    bool isPerfectSquare1(int num) {
        int i = 1;
        int temp = 0;
        while (temp < num) {
            temp = i * i;
            i++;
            if (temp == num)return true;
        }
        return false;
    }
    
    /*二分查找*/
    bool isPerfectSquare2(int num) {
        if (num < 2)return true;
        int left = 2, right = num / 2;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (mid * mid == num)return true;
            else if (mid * mid < num)left++;
            else right--;
        }
        return false;
    }
   
    /*数学知识，一个完全平方数等于奇数之和，即x=1+3+5+7+……*/
    bool isPerfectSquare3(int num) {
        if (num < 2)return true;
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};