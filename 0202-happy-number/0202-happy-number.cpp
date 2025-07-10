// Approach:
// We keep replacing the number with the sum of the squares of its digits.
// To detect a cycle, we use an unordered_set to track previously seen values.
// If we reach 1 → it's a happy number.
// If we see the same number again → there's a cycle → return false.

class Solution {
public:
    bool isHappy(int n) {
        int lastDigit;
        unordered_set<int> uniqueSums;
        bool isFound = false;
        while (n != 1 && !uniqueSums.count(n)) {
            uniqueSums.insert(n);
            int sum = 0;
            while (n != 0) {
                lastDigit = n % 10;
                n /= 10;
                sum += lastDigit * lastDigit;
            }
            n = sum;
        }
        if (n == 1)
            return true;
        return false;
    }
};