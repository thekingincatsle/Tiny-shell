#include <bits/stdc++.h>
#include <tlhelp32.h>

#include <cstdlib>

#include "../utils.h"
#include "commandList.h"
#include "processList.h"
using namespace std;

// example
int echo(string c) {
    cout << c << endl;
    return 0;
}
string echoDoc = "Just print the argument.";

int exitShell(string c) {
    // Need to kill all process
    return 1;
}
string exitShellDoc = "Exit shell.";

int help(string c) {
    cout << "Command list: \n";
    for (auto i = funcmap.begin(); i != funcmap.end(); ++i) {
        string command = i->first;
        string space = command.size() < 8 ? "\t\t" : "\t";
        cout << command << space << i->second.instruction << "\n";
    }
    return 0;
}
string helpDoc = "List all available command.";

int date(string input) {
    time_t t = time(0);  // get time now
    tm* now = localtime(&t);
    cout << now->tm_mday << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900) << '\n';
    return 0;
}
string dateDoc = "Display today date.";

int timee(string input) {
    time_t t = time(0);  // get time now
    tm* now = localtime(&t);
    cout << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << '\n';
    return 0;
}
string timeDoc = "Display current time.";

int datetime(string input) {
    time_t t = time(0);  // get time now
    tm* now = localtime(&t);
    cout << now->tm_mday << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900) << "  ";
    cout << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "\n";
    return 0;
}
string datetimeDoc = "Display current date and time.";

int runExe(string input) {
    // What if just exist process 99?
    if (num_process == maxprocess) return 2;
    string file, argument;
    parse(input, file, argument);
    ZeroMemory(&si[num_process], sizeof(si[num_process]));
    si[num_process].cb = sizeof(si[num_process]);
    CreateProcess(file.c_str(), NULL, NULL, NULL, FALSE,
                  CREATE_NEW_CONSOLE, NULL, NULL, &si[num_process], &pi[num_process]);
    ++num_process;
    return 0;
}
string runExeDoc = "Run a .exe file, can omit 'runexe'.";

// int stop(string input) {
//     string whatever;
//     parse(input, input, whatever);
//     input = trim(input);
//     stringstream ss(input);
//     unsigned __LONG32 processId = 0;
//     ss >> processId;

//     HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
//     THREADENTRY32 threadEntry;
//     threadEntry.dwSize = sizeof(THREADENTRY32);
//     Thread32First(hThreadSnapshot, &threadEntry);
//     do {
//         if (threadEntry.th32OwnerProcessID == processId) {
//             HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, threadEntry.th32ThreadID);
//             SuspendThread(hThread);
//             CloseHandle(hThread);
//         }
//     } while (Thread32Next(hThreadSnapshot, &threadEntry));

//     CloseHandle(hThreadSnapshot);
//     return 0;
// }
// string stopDoc = "Stop a background process.";

// int listt(string input) {
//     for (int i = 0; i < num_process; ++i) {
//         cout << pi[i].dwProcessId <<" "<< pi[i].dwThreadId<<endl;
//     }
//     return 0;
// }
// string listDoc = "All running process information.";

int resume(string input) {
    string whatever;
    parse(input, input, whatever);
    input = trim(input);
    stringstream ss(input);
    unsigned __LONG32 processId = 0;
    ss >> processId;
    cout << processId << endl;

    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);
    Thread32First(hThreadSnapshot, &threadEntry);
    do {
        if (threadEntry.th32OwnerProcessID == processId) {
            HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, threadEntry.th32ThreadID);
            ResumeThread(hThread);
            CloseHandle(hThread);
        }
    } while (Thread32Next(hThreadSnapshot, &threadEntry));

    CloseHandle(hThreadSnapshot);
    return 0;
}
string resumeDoc = "Resume a stopped background process.";