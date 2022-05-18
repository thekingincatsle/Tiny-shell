#include <bits/stdc++.h>

#include "../utils.h"
#include "processList.h"

using namespace std;
#pragma once

int kill(string c) {
    // input = dau vao - "kill"
    // kill mot background process

    string arg1, arg2;
    parse(c, arg1, arg2);
    // chuyen tu string sang so
    DWORD processId = stringToDWORD(arg1);
    HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
    if (hProc == NULL) {
        cout << "khong co tien trinh" << endl;
        return 0;
    }

    BOOL a = TerminateProcess(hProc, 0);
    CloseHandle(hProc);
    // num_process_run --;
    cout << "dang thuc hien tien trinh" << endl;
    return 0;
}
string killDoc = "kill.";

int foregroundMode(string c) {
    // Shell phải đợi tiến trình kết thúc
    if (mode = 1) {
        for (int i = 0; i < maxprocess; i++) {
            DWORD id = pi[i].dwProcessId;
            HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, id);
            TerminateProcess(hProc, 0);
        }
    }
    mode = 0;
    return 0;
}
string foregroundModeDoc = "foregroundMode.";

int backgroundMode(string c) {
    // Shell và tiến trình thực hiện song song
    mode = 1;
    return 0;
}
string backgroundModeDoc = "backgroundMode.";

DWORD isProcessRunning(HANDLE hProcess) {
    DWORD dwExitCode = 0;
    GetExitCodeProcess(hProcess, &dwExitCode);
    return dwExitCode;
}

int numProcessRunning() {
    int num = 0;
    for (int i = 0; i < maxprocess; i++) {
        HANDLE hProc = pi[i].hProcess;
        DWORD a = isProcessRunning(hProc);
        if (a == 259) {
            num++;
        }
    }
    return num;
}

string Mode(string c) {
    string input = c;
    if (mode == 0) {
        int num_process_run = numProcessRunning();
        if (input != "backgroundMode" & num_process_run != 0) {
            cout << "dang o che do foreground; doi tien trinh ket thuc de thuc hien tiep" << endl;
            input = "";
        }
    }
    return input;
}