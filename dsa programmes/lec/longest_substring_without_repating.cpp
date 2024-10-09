#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Read input string from user
    string s;
    cin >> s;

    // Initialize variables
    int start_index = -1; // Index of start of current substring without repeating characters
    int max_len = 0;      // Length of longest substring without repeating characters

    // Initialize vector to store index of last occurrence of each character
    vector<int> last_occurrence(26, -1);

    // Iterate through string
    for (int stop_index = 0; stop_index < s.length(); stop_index++)
    {

        // Check if current character has occurred before in current substring
        if (last_occurrence[s[stop_index] - 'a'] > start_index)
        {

            // If so, update index of start of current substring without repeating characters
            start_index = last_occurrence[s[stop_index] - 'a'];
        }

        // Update index of last occurrence of current character
        last_occurrence[s[stop_index] - 'a'] = stop_index;

        // Update length of longest substring without repeating characters
        max_len = max(max_len, stop_index - start_index);
    }

    // Output length of longest substring without repeating characters
    cout << max_len << endl;

    return 0;
}

/*
Certainly! This code finds the length of the longest substring of a given string that does not contain any repeating characters. It works by iterating through the string and keeping track of the last index at which each character appeared. If the current character has appeared before in the current substring, the code updates the start index of the current substring to the index immediately following the last occurrence of that character. The code then updates the index of the last occurrence of the current character and checks whether the length of the current substring is greater than the maximum length found so far. Once the iteration is complete, the code outputs the length of the longest substring without repeating characters.

For example, if the input string is "abcabcbb", the code would find the longest substring without repeating characters to be "abc", and it would output a value of 3. If the input string is "bbbbb", the code would find that there are no substrings without repeating characters, and it would output a value of 0.

*/