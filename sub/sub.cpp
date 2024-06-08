#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert HH:MM:SS,MMM to total milliseconds
long long convertToMilliseconds(int hours, int minutes, int seconds, int milliseconds) 
{
    return (((hours * 60 + minutes) * 60 + seconds) * 1000 + milliseconds);
}

// Function to convert total milliseconds back to HH:MM:SS,MMM
string convertToTimestamp(long long totalMilliseconds) 
{
    int hours = totalMilliseconds / 3600000;
    totalMilliseconds %= 3600000;
    int minutes = totalMilliseconds / 60000;
    totalMilliseconds %= 60000;
    int seconds = totalMilliseconds / 1000;
    int milliseconds = totalMilliseconds % 1000;

    ostringstream oss;
    oss << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << ","
        << setw(3) << setfill('0') << milliseconds;

    return oss.str();
}

// Function to adjust the timestamp by -6200 milliseconds (6.2 seconds)
string adjustTimestamp(const string& timestamp, long long adjustment) 
{
    int hours, minutes, seconds, milliseconds;
    char dummy; // to consume the colon and comma separators
    istringstream iss(timestamp);
    iss >> hours >> dummy >> minutes >> dummy >> seconds >> dummy >> milliseconds;

    long long totalMilliseconds = convertToMilliseconds(hours, minutes, seconds, milliseconds);
    totalMilliseconds += adjustment;

    // Ensure we do not get a negative timestamp
    if (totalMilliseconds < 0) totalMilliseconds = 0;

    return convertToTimestamp(totalMilliseconds);
}

int main() 
{
    ifstream inputFile("Silicon-Valley-S04E02.srt");
    ofstream outputFile("output.srt");
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (getline(inputFile, line)) 
    {
        if (line.find("-->") != string::npos) 
        {
            string startTimestamp = line.substr(0, 12);
            string endTimestamp = line.substr(17, 12);

            string adjustedStart = adjustTimestamp(startTimestamp, - 6200);
            string adjustedEnd = adjustTimestamp(endTimestamp, - 6200);

            outputFile << adjustedStart << " --> " << adjustedEnd << endl;
        } 
        else 
            outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Subtitle timings adjusted successfully!" << endl;

    return 0;
}