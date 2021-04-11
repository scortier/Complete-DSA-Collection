//TRIE SOLUTION

class TrieNode {
public:
    unordered_map<char, TrieNode*>children;
    char value;
    bool isWord = false;

    //constructor
    TrieNode() {}

    TrieNode(char v) {
        this->value = v;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    //intialization
    Trie() {
        root = new TrieNode();
    }

    //get trienode
    TrieNode* getTrieNode() {
        return root;
    }

    //Insert a word into trie
    void insert(string word)
    {
        TrieNode*temp = root;

        for (auto ch : word)
        {
            if (temp->children.find(ch) == temp->children.end())
            {
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie* pTrie = new Trie();

        for (auto s : strs) {pTrie->insert(s);}

        //Traverse the trie and find longest common prefix
        string lcp = "";
        TrieNode* curr = pTrie->getTrieNode();

        // Do till we find a leaf node or node has more than 1 children
        while (curr && !curr->isWord && (curr->children.size() == 1))
        {
            auto it = curr->children.begin();
            lcp += it->first;
            curr = it->second;
        }
        return lcp;
    }
};

/*
1.sorting
string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";

        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];

        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }

        return ans;

    }


2.greedy

string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];

        int small=INT_MAX;
        bool flag=true;
        string res;

        //finding smallest string length in string array
        for(auto s:strs) if(s.size()<small) small=s.size();

        //traversing through that smallest string and remaining strings
        while(small!=0){
            flag=true;
            for(int i=0;i<n-1;i++)
            {
                if(strs[i].substr(0,small)!=strs[i+1].substr(0,small)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return strs[0].substr(0,small);
            }
            small--;
        }
        return res;

    }


3.trie
*/