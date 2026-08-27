class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.length();
        map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        string l = "", r = "";
        string rem = "";
        for (auto it : mp)
        {
            int cha = it.first;
            if (it.second % 2)
                rem += cha;
            int freq = (it.second) / 2;
            for (int i = 0; i < freq; i++)
                l += cha;
            for (int j = 0; j < freq; j++)
                r += cha;
        }
        reverse(r.begin(), r.end());
        l += rem;
        l += r;
        return l;
    }
};