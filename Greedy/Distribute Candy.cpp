//tc:O(n)
//Buyhatke m pucha tha
int Solution::candy(vector<int> &a) {
    int n = a.size();
    vector<int>l(n, 1), r(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            l[i] = l[i - 1] + 1;

    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            r[i] = 1 + r[i + 1];
        // l[i]=max(l[i],1+l[i+1]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(l[i], r[i]);
        // sum+=l[i];

    }
    return sum;
}
