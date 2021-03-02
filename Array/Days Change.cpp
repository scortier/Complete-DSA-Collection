vector<int> cellCompete(int* states, int days)
{
    const int SIZE = 8;
    vector<int> ans(SIZE + 2);
    ans[0] = ans[SIZE + 1] = 0;
    for (int i = 1; i <= SIZE; i++)
        ans[i] = states[i - 1];

    for (int i = 0; i < days; i++) {
        int pre = ans[0]; // must reset pre each loop
        for (int j = 1; j <= SIZE; j++) {
            int tmp = ans[j];
            ans[j] = pre ^ ans[j + 1];
            pre = tmp;
        }
    }

    return vector<int>(ans.begin() + 1, ans.end() - 1);
}