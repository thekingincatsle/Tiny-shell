#include <iostream> 
#include <ctime> 
using namespace std; 

int date(string c) 
{  
    time_t now = time(0); 
    tm *ltm = localtime(&now); 
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    cout << day << "/" << month << "/" << year<<endl; 
    return 0;
}
string dateDoc = "Print the current date";