#include <bits/stdc++.h>

#include "../utils.h"
#include "commandList.h"
#include "processList.h"
using namespace std;

// example
int echo(string c){
    cout<<c<<endl;
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

int runExe(string input) {
    // What if just exist process 99?
    // if (num_process == maxprocess) return 2;
    // string file, argument;
    // parse(input, file, argument);
    // ZeroMemory(&si[num_process], sizeof(si[num_process]));
    // si[num_process].cb = sizeof(si[num_process]);
    // CreateProcess(file.c_str(), NULL, NULL, NULL, FALSE,
    //               CREATE_NEW_CONSOLE, NULL, NULL, &si[num_process], &pi[num_process]);
    // ++num_process;
    return 0;
}
string runExeDoc = "Run a .exe file, can omit 'runexe'.";