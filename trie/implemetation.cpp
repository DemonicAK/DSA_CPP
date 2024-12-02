/*
Problem Name:
Problem Link:
Author: Arijit Kar (DemonicAK)
*/
//----------HEADER----------
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 // 1e9+7
#define mxN 1000005
const int N = mxN;
typedef long long ll;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
// ----------MAIN-----------
struct node
{
    node *arr[26];
    bool flag = false;
    bool containskey(char x)
    {
        return arr[x - 'a'];
    }
    void set(char x, node *node)
    {
        arr[x - 'a'] = node;
    }
    void setend()
    {
        flag = true;
    }
    node *get(char x)
    {
        return arr[x - 'a'];
    }
    bool isend()
    {
        return flag;
    }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *curr = root;
        for (auto x : word)
        {
            if (!curr->containskey(x))
                curr->set(x, new node());

            curr = curr->get(x);
        }
        curr->setend();
    }

    bool search(string word)
    {
        node *curr = root;
        for (auto x : word)
        {
            if (!curr->containskey(x))
                return false;
            else
                curr = curr->get(x);
        }
        return curr->isend();
    }
    bool startsWith(string word)
    {
        node *curr = root;
        for (auto x : word)
        {
            if (!curr->containskey(x))
                return false;
            else
                curr = curr->get(x);
        }
        return true;
    }
};
int32_t main()
{
    // fastIO;
    Trie myobj;
    std::vector<std::string> words = {
        "apdicate", "apdaptation", "apdorable", "apdversity", "apdherence",
        "bachelor", "backup", "baccarat", "bacteria", "backbone",
        "hike", "hiker", "hiked", "hiking", "hikers"};

    // Displaying the vector elements
    // std::cout << "Combined vector of words:\n";
    for (const auto &word : words)
    {
        myobj.insert(word);
    }
    cout << "input the word";
    string myword = "bacteri";
    // cin>>myword;
    cout << myword << myobj.search(myword);
    return 0;
}