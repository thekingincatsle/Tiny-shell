#include <bits/stdc++.h>
#include <windows.h>
//#include "bien.h"
#include "commands/master.h"
#include "utils.h"
using namespace std;

int run(string input) {
    // command parsing
    input = trim(input);

    if (input == "") return 0;
    string command, argument;
    parse(input, command, argument);

    if (funcmap.find(command) == funcmap.end()) {
        if (command.find('.') != string::npos && command.substr(command.find('.')) == ".exe")
            return runExe(input);  // No command, run file .exe
        else
            cout << command << " is not recognized as an internal or external command, operable program or batch file.\n";
        return 0;
    } else
        return funcmap[command].func(argument);
}

bool processRunResult(int res) {
    switch (res) {
        case 0:
            break;
        case 1:
            return true;
        case 2:
            cout << "Can't create process, too much process.\n";
            break;
        default:
            cout << "Error!\n";
            break;
    }
    return false;
}

int main() {
    buildCommand();
    string input;
    while (true) {
        input = "";
        //cout << filesystem::current_path().string() << ">";
        getline(cin, input);
        
        string Input = Mode(input);
        // if (mode == 0) {
        //     int num_process_run = numProcessRunning();
        //     if (input != "backgroundMode" & num_process_run != 0){
        //         cout << "dang o che do foreground; doi tien trinh ket thuc de thuc hien tiep"<<endl;
        //         input = "";
        //     }
        //     //else num_process_run++;
        // }
        
        int res = run(Input);
        if (processRunResult(res)) break;
    }
}