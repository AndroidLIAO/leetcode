#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*�����ⷨ*/
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
    
    /*���ֲ���*/
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
   
    /*��ѧ֪ʶ��һ����ȫƽ������������֮�ͣ���x=1+3+5+7+����*/
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