class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                g = findGCD(g, nums[j]);
                l = findLCM(l, nums[j]);

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
                if(product>1e12) break;
            }
        }

        return ans;
    }

private:
    // GCD Function
    long long findGCD(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // LCM Function
    long long findLCM(long long a, long long b) {
        return (a / findGCD(a, b)) * b;
    }
};