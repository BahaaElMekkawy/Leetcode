class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            int temp = num;
            int digits = 0;

            // Count number of digits
            while (temp > 0) {
                digits++;
                temp /= 10;
            }

            if (digits % 2 != 0)
                continue;

            int half = digits / 2;
            temp = num;

            int sum1 = 0, sum2 = 0;
            // first loop will remove the last half of the digits and get its
            // sum
            for (int i = 0; i < half; ++i) {
                sum1 += temp % 10;
                temp /= 10;
            }
            // second loop will get the sum of the remaining digits

            for (int i = 0; i < half; ++i) {
                sum2 += temp % 10;
                temp /= 10;
            }

            if (sum1 == sum2) {
                count++;
            }
        }

        return count;
    }
};
