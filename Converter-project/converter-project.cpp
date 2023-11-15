#include <iostream>
#include <string>
using namespace std;

string DecimalToBinary(int decimal)
{
    string binary = "";
    while(decimal > 0)
    {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

string DecimalToOctal(int decimal)
{
    string octal = "";
    while(decimal > 0)
    {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

string DecimalToHexadecimal(int decimal)
{
    string hexadecimal = "";
    while(decimal > 0)
    {
        int remainder = decimal % 16;
        if(remainder < 10)
        {
            hexadecimal = to_string(remainder) + hexadecimal;
        } else
        {
            hexadecimal = char(remainder + 55) + hexadecimal;
        }
        decimal /= 16;
    }
    return hexadecimal;
}

int main()
{
    int decimalNumber;
    string choice;
    cout << "Enter the decimal number: ";
    cin >> decimalNumber;

    cout << "Choose the base to convert to:\n";
    cout << "1. Binary\n";
    cout << "2. Octal\n";
    cout << "3. Hexadecimal\n";
    cin >> choice;

    if(choice == "1")
    {
        cout << "The number in binary is: " << DecimalToBinary(decimalNumber) << endl;
    }
    else if(choice == "2")
    {
        cout << "The number in octal is: " << DecimalToOctal(decimalNumber) << endl;
    }
    else if(choice == "3")
    {
        cout << "The number in hexadecimal is: " << DecimalToHexadecimal(decimalNumber) << endl;
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
