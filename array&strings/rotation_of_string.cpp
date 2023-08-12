// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// naive approach
bool check_rotation_naive_util(string &s1, string &s2, int indexFound,
                               int Size)
{
    for (int i = 0; i < Size; i++)
    {
        // check whether the character is equal or not
        if (s1[i] != s2[(indexFound + i) % Size])
            return false;
        // %Size keeps (indexFound+i) in bounds, since it
        // ensures it's value is always less than Size
    }

    return true;
}

bool check_rotation_naive(string &s1, string &s2)
{
    if (s1.length() != s2.length())
    {
        cout << "s2 is not a rotation on s1" << endl;
    }
    else
    {
        // store occurrences of the first character of s1
        vector<int> indexes;

        int Size = s1.length();

        char firstChar = s1[0];

        for (int i = 0; i < Size; i++)
        {
            if (s2[i] == firstChar)
            {
                indexes.push_back(i);
            }
        }

        bool isRotation = false;

        // check if the strings are rotation of each other
        // for every occurrence of firstChar in s2
        for (int idx : indexes)
        {
            isRotation = check_rotation_naive_util(s1, s2, idx, Size);

            if (isRotation)
                break;
        }

        if (isRotation)
            cout << "Strings are rotations of each other"
                 << endl;
        else
            cout
                << "Strings are not rotations of each other"
                << endl;
    }
}
// better approach

bool check_rotation_better(string s, string goal)
{
    if (s.size() != goal.size())
        return false;

    queue<char> q1;
    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
    }

    queue<char> q2;
    for (int i = 0; i < goal.size(); i++)
    {
        q2.push(goal[i]);
    }

    int k = goal.size();
    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

bool areRotations_good(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

bool areRotations_best(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++)
    {
        // check if ith character is equal to the first
        // character of str2
        if (str1[i] == str2[0])
        {
            // chheck prefix of str1 with suffix of str2
            if (str1.substr(i) == str2.substr(0, str1.length() - i))
            {
                // check suffix of str2 with prefix of str1
                if (str1.substr(0, i) == str2.substr(str1.length() - i))
                    return true;
            }
        }
    }
    // if none of the above cases satisfy then answer must
    // be false so return false
    return false;
}

int main()
{

    string s1 = "abcd";
    string s2 = "cdab";

    return 0;
}
