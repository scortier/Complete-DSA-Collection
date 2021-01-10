lic:
bool canConstruct(string s, int k) {
    map<char, int>mp;
    int n = s.size();
    if (n < k) return 0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    int od = 0, ev = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second % 2 == 1) od++;
        else ev++;
    }
    if (od > k) return 0;
    return 1;



}