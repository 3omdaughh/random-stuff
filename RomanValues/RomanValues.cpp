#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        if(s.empty())
        {
            return 0;
        }

        map<char, int> romanvalues = {{'I', 1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i > 0 && romanvalues[s[i]] > romanvalues[s[i-1]])
            {
                total += romanvalues[s[i]] - 2*romanvalues[s[i-1]];
            }
            else
            {
                total += romanvalues[s[i]];
            }
        }
        return total; // Move the return statement to the correct position
    }
};

int main ()
{
    Solution roman;
    string romanNumbers;
    cout<<"Enter a Roman number: " << endl;
    cin >> romanNumbers;
    cout << "The corresponding integer value is: " << roman.romanToInt(romanNumbers) << endl;
}
