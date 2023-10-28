#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <sstream>

using namespace std;

double getTotal(const vector<double>& prices);

int main ()
{
    double quantity;
    double price;
    vector<double> prices;

    cout <<"How many products you have bought? : ";
    cin >> quantity;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr <<"Invalid Input.";
        return 0;
    }
    else if (quantity == 0)
    {
        cout <<"You Have Not Buy Any Thing Sir.";
        return 0;
    }

    for (int i = 1; i <= quantity; i++)
    {
        cout <<"\nHow Much product "<< i <<" cost? ";
        cin >> price;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr <<"Invalid Input.";
                return 0;
            }
        prices.push_back(price);
    }
    double total = getTotal(prices);
    cout <<"Total price is "<< total << "$" <<" sir."<<endl;

    return 0;
}

double getTotal(const vector<double>& prices)
{
    double total = 0;
    for (const auto& price : prices)
    {
        total += price;
    }
    
    return total;
}