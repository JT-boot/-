class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;
            if (digits[i] <= 9) return digits;  //如果该位加1后没进位，返回
            digits[i] = 0;      //加一进位后改0
        }
        digits.insert(digits.begin(), 1);   //最前一位也进位，要在最前面加一位1
        return digits;
    }
};