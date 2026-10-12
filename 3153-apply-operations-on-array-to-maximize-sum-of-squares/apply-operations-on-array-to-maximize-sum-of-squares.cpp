class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;
        long long count[32] = {0};

        // Step 1: Count set bits
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1LL << bit)) {
                    count[bit]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k numbers
        for (int i = 0; i < k; i++) {
            long long num = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (count[bit] > 0) {
                    num |= (1LL << bit);
                    count[bit]--;
                }
            }

            // Step 3: Add square
            ans = (ans + num * num) % MOD;
        }

        return (int)ans;
    }
};