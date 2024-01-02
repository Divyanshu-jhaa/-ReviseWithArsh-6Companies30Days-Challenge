class Solution
{
public:
    int cal(char a, char b)
    {
        return (a - 'a') * 10 + (b - 'a');
    }
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        vector<string> ans;
        sort(access_times.begin(), access_times.end());
        set<string> res;
        for (int j = 0; j < n; j++)
        {
            int i = j;
            int cnt = 1;
            int dur = 0;
            while (i < n - 1 && access_times[i][0] == access_times[i + 1][0])
            {
                int h1 = cal(access_times[i][1][0], access_times[i][1][1]);
                int m1 = cal(access_times[i][1][2], access_times[i][1][3]);
                int h2 = cal(access_times[i + 1][1][0], access_times[i + 1][1][1]);
                int m2 = cal(access_times[i + 1][1][2], access_times[i + 1][1][3]);
                dur += (h2 - h1) * 60 - m1 + m2;
                if (dur >= 60)
                {
                    break;
                }
                i++;
                cnt++;
            }
            if (cnt >= 3)
            {
                res.insert(access_times[j][0]);
            }
        }
        ans = vector<string>(res.begin(), res.end());

        return ans;
    }
};