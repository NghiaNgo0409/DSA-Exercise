#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to reverse a string in place
void reverseString(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}

// Function to recursively reverse every string enclosed between brackets
string reverseParentheses(string s)
{
    stack<int> st; // Stack to store indices of opening brackets
    int n = s.length();

    // Find indices of opening brackets and store in stack
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            int start = st.top(); // Index of corresponding opening bracket
            st.pop();
            string temp = s.substr(start + 1, i - start - 1); // Create temporary string
            reverseString(temp);
            s.replace(start + 1, i - start - 1, temp); // Replace string between brackets with reversed string
        }
    }

    // Remove brackets from the string
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            result += s[i];
        }
    }
    return result;
}

// Main function
string parenthesesReversal(string s)
{
    return reverseParentheses(s);
}

// Test function
int main()
{
    string s = "a(bcdefghijkl(mno)p)q";
    cout << "Input string: " << s << endl;
    cout << "Output string: " << parenthesesReversal(s) << endl;
    return 0;
}
