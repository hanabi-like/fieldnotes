#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getMaxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2 * k);
        for (int i = 0; i < 2 * k; i += 2)
        {
            dp[i] = -prices[0];
        }
        for (int i = 1; i < n; ++i)
        {
            dp[0] = max(dp[0], -prices[i]);
            for (int j = 1; j < 2 * k; ++j)
            {
                if (j % 2)
                    dp[j] = max(dp[j - 1] + prices[i], dp[j]);
                else
                    dp[j] = max(dp[j - 1] - prices[i], dp[j]);
            }
        }
        return dp[2 * k - 1];
    }
};

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    Solution s;
    cout << s.getMaxProfit(2, prices) << endl;
}