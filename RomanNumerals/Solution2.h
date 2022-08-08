#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Key
        map<string, int> romans { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} };
        
        // Table of subtraction instances
        map<string, int> subCase { {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900} };

        string pairs[6] = {"IV", "IX", "XL", "XC", "CD", "CM"};

        int sum = 0; // Sum in integer symbols
        int strSize = s.size(); // integer that stores the number of characters in the input string

        for (int i = 0; i < strSize; i++) { // Overall for loop that iterates through each character in the input string
            
            bool flag = false; // flag to determine if the string contains a sub pair at index [i] and [i + 1]

            // These strings contain the character at [i] and the pair at [i, i + 1]
            string temp1 = "";
            string temp2 = "";
            temp1 = s[i]; temp2 = temp1 + s[i + 1]; // There's probably a better way to concatenate two characters from the input string

            for (int j = 0; j < 6; j++) { // This loop iterates through the 6 possible subtraction pairs and checks them against the temp strings

                if (pairs[j] == temp2) // If the pair at [j] is the same as our pair at [i]...
                {
                    sum = sum + subCase[pairs[j]]; // ...Sum the pair value stored in the subCase map
                    flag = true; // ...and set the flag to true
                    i++; // ...and iterate the overall loop to move to the next character after the pair
                    break; // ...and break out of the case loop so we don't make anymore unnecessary checks
                }
            }
                
            if (!flag) // Otherwise if the flag is still false...
            {
                sum = sum + romans[temp1]; // ...add the character value stored in the romans map to the sum
            }
        }

        cout << sum << endl; // Output the sum
        return 0;
    }
};