typedef long long ll;
class Solution
{
public:
    bool check(ll mid, ll divisor1, ll divisor2, ll uniqueCnt1, ll uniqueCnt2)
    {
        ll na = mid - mid / divisor1;
        ll nb = mid - mid / divisor2;
        ll lcm = (divisor1 * divisor2) / __gcd(divisor1, divisor2);
        ll ab = mid / lcm;
        ll nab = (na + nb) - (mid - (ab));
        ll total = na + nb - nab;
        return total >= (uniqueCnt1 + uniqueCnt2) && na >= uniqueCnt1 && nb >= uniqueCnt2;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        ll s = 1;
        ll e = 1e18;
        while (s <= e)
        {
            ll mid = (s + e) / 2;

            if (check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2))
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};