// as contains only digits so used unsigned long long
class Solution {
    bool helper(string s, long long int tar) {
        if (stoul(s) == tar)
            return true;

        for (long long int i = 1; i < s.size(); ++i)
        {
            if (stoul(s.substr(0, i)) != tar)
                continue;
            if (helper(s.substr(i, s.size() - i), tar - 1))
                return true;
        }
        return false;
    }
public:
    bool splitString(string s) {
        int n = s.size();
        for (long long int i = 1; i < n; ++i) {
            //convert o to i string as number
            long long int firstNumber = stoul(s.substr(0, i));
            //target= firstnum -1 as secnum pehle wale se chota hona chahiye (given)
            if (helper(s.substr(i, n - i), firstNumber - 1))
                return true;
        }
        return false;
    }
};
//stoi or stoll will not work -> will give runtime error



/*class Solution {
public:
    bool isPossible(string &s, int index, unsigned long long targetNumber)
{
    if(index == s.length())
        return 1;
    unsigned long long currNumber = 0;
    while(index < s.length())
    {
        currNumber = currNumber*10 + s[index] - '0';
        if(currNumber == targetNumber and isPossible(s , index+1 , targetNumber-1))
            return true;
        if(currNumber > targetNumber)
            return false;
        index++;
    }
    return 0;
}
bool splitString(string s)
{
    unsigned long long firstNumber = 0;
    for(int index=0; index<s.length()-1 ; index++)
    {
        firstNumber = firstNumber*10 + (s[index] - '0');
        if(firstNumber > 1e17+1)
            return false;
        if(isPossible(s , index+1 , firstNumber-1))
            return 1;
    }
    return 0;
}
};
*/