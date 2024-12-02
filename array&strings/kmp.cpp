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
typedef long long ll;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
// ----------MAIN-----------

void computeLPS(string pat, vector<int> &lps)
{
    int n = pat.size();
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp(string txt, string pat)
{
    vector<int> ans;

    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m, 0);
    computeLPS(pat, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
    while ((n - i) >= (m - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            ans.emplace_back(i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < n && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if (ans.size())
        return ans;
    else
        return {-1};
}

int32_t main()
{
    fastIO;

    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABB";
    cout << "index found at: " << kmp(txt, pat).at(0) << "\n";


    string word="AAAABACAAAPAA";
    vector<int> vec(word.size(), 0);
    computeLPS(word, vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";

    return 0;
}