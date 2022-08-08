#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> romans { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} };
        int sum = 0; // Int variable to store the complete number
        int stringSize = s.size(); // Int variable to store the size of the input string
        for (int i = 0; i < stringSize; i++) { // For loop iterates through the string, checking each character against subtraction constraints
            string tempC1 = ""; // String to store single character
            string tempC2 = ""; // String to store character pair

            tempC1 = s[i]; // Set C1 to string char at index i
            tempC2 = tempC1 + s[i + 1]; // Set C2 to C1 concatenated with string char at index i+1

            // Test subtraction cases
            if (tempC2 == "IV") {
                    sum = sum + 4;
                    i++; // We iterate here and in the following cases in order to skip the next character (since IV and the following are a pair)
                }
            else if (tempC2 == "IX") {
                    sum = sum + 9;
                    i++;
                }   
            else if (tempC2 == "XL") {
                    sum = sum + 40;
                    i++;
                }
            else if (tempC2 == "XC") {
                    sum = sum + 90;
                    i++;
                }
            else if (tempC2 == "CD") {
                    sum = sum + 400;
                    i++;
                }
            else if (tempC2 == "CM") {
                    sum = sum + 900;
                    i++;
                }
            else sum = sum + romans[tempC1]; // If none of the subtraction cases are true, just add the single mapped char C1 to the sum
        }
        
        cout << sum << endl; // Output the sum
        return 0;
    }
};