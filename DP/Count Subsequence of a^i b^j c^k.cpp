int countSubsequences(string &s) {
    // write your code here
    int n = s.size();

    int a = 0, ab = 0, abc = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (s[i] == 'a')
            a = 2 * a + 1;

        else if (s[i] == 'b')
            ab = 2 * ab + a;

        else if (s[i] == 'c')
            abc = 2 * abc + ab;
    }
    return abc;
}