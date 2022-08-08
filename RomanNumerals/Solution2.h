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

        for (int i = 0; i < strSize; i++) {
            string temp1 = "";
            string temp2 = "";
            bool flag = false;
            temp1 = s[i]; temp2 = temp1 + s[i + 1]; // There's probably a better way to concatenate two characters from the input string

            for (int j = 0; j < 6; j++) {

                if (pairs[j] == temp2)
                {
                    sum = sum + subCase[pairs[j]];
                    flag = true;
                    i++;
                    break;
                }
            }
                
            if (!flag)
            {
                sum = sum + romans[temp1];
            }
        }

        cout << sum << endl; // Output the sum
        return 0;
    }
};