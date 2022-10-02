#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;

void printTime();
void timeSetUp(int &a, int &b, int &c);
void Clear();
void output(int &a, int &b, int &c);

int main(int argc, char *argv[])
{
    printTime();
}

void printTime()
{
    int hours, minutes, seconds;
    timeSetUp(hours, minutes, seconds);
    Clear();
    while (true)
    {
        if (seconds == 60){
            seconds = 0;
            minutes += 1;
        }
        if (minutes == 60){
            minutes = 0;
            hours += 1;
        }
        if (hours == 24){
            hours = 0;
        }
        output(hours, minutes, seconds);
        seconds += 1;
    }
}

void timeSetUp(int &hours, int &minutes, int &seconds)
{
    cout << "Please provide hours: ";
    cin >> hours;
    cout << "Please provide minutes: ";
    cin >> minutes;
    cout << "Please provide seconds: ";
    cin >> seconds;
}

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

void output(int &hours, int &minutes, int &seconds)
{
        cout << setfill(' ') << setw(50) << "";
        cout << setfill('0') << setw(2) << hours << " : " ;
        cout << setfill('0') << setw(2) << minutes << " : " ;
        cout << setfill('0') << setw(2)<< seconds << endl;
        Clear();
        sleep(1);
}
