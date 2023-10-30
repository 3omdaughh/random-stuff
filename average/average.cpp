#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <cstdlib>
#include <sstream>

using namespace std;

double addNumbers(const vector<double>& quantity1) 
{
    return accumulate(quantity1.begin(), quantity1.end(), 0);
}

int main()
{
    vector<double> quantity1;
    double number;
    double quantity;

    do
    {
    cout <<"How many number will you enter: ";
    cin >> quantity;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr<<"Invalid Input.";
            return 0;
        }
    }
    while (quantity <= 0);

    for (int i = 1; i <= quantity; i++)
    {
        cout <<"\nEnter the number number"<< i <<": ";
        cin >> number;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr <<"Invalid Input.";
                return 0;
            }
        
        quantity1.push_back(number); // store the number in the vector
    }

    double total = addNumbers(quantity1)/quantity;
    cout <<"\naverage is: "<< total;   
        
    return 0;
}