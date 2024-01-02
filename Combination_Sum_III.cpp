
class Solution
{
public:
    void solve(int i, int k, int n, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (i == 10)
        {
            if (n == 0 && k == 0)
            {
                ans.push_back(temp);
                return;
            }
            else
            {
                return;
            }
        }
        solve(i + 1, k, n, temp, ans);
        if (k && (n - i) >= 0)
        {
            temp.push_back(i);
            solve(i + 1, k - 1, n - i, temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, temp, ans);
        return ans;
    }
};