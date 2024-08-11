#include <bits/stdc++.h>
using namespace std;

/*1/So here first we will count the frequency for every particular strings in the word array.

The reason for this is that if a characters frequency is completely divided by the number of words , in the words  array that means that we can distribute that particular character to every word in the words array..
(Here by words array I am referring to the given input array of strings.)

2/ I have already given a hint about what we'll be doing in the second step that is we'll check if the character's frequency is 0 like the character is not present in the words array or the characters frequency is not divided by the number of words in the word in that case we will return false.. Means that we cannot distribute this particular character among all the word in the words array.*/

// This class represents a solution to a problem
class Solution
{
public:
    // An array to store the frequency of each character (initialized to 0)
    int freq[26] = {0};

    // A function to check if characters can be distributed equally among words
    bool makeEqual(vector<string> words)
    {
        // Number of words in the input array
        int len = words.size();

        // A flag to determine if characters can be distributed equally
        bool val = true;

        // Step 1: Count the frequency of each character in the words array
        for (auto word : words)
        {
            for (auto chars : word)
                freq[chars - 97]++; // Increment the frequency of the character
        }

        // Step 2: Check if characters can be distributed equally among words
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue; // Skip characters with frequency 0

            // If the frequency of a character is not divisible by the number of words,
            // set the flag to false and break out of the loop
            else if (freq[i] % len != 0)
            {
                val = false;
                break;
            }
        }

        // Return the final result indicating whether characters can be distributed equally
        return val;
    }
};

int main()
{

    Solution s;
    cout << s.makeEqual({"ab", "aaab", "b", "b"});
}