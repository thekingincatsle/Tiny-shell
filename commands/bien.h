#include <bits/stdc++.h>

#include "../utils.h"
#include "commandList.h"
#include "processList.h"
using namespace std;


int kill(string input){
    // input = dau vao - "kill"
    // kill mot background process
    string arg1 , arg2;
    parse(input, arg1, arg2);
    //chuyen tu string sang so
    DWORD processId = stringToDWORD(arg1);
    //
    HANDLE hProc = OpenProcess(PROCESS_TERMINATE,FALSE,processId);
	TerminateProcess(hProc,1);
    return 0;
}
    
int exit(){
    // thoat khoi mot process
    return 1;
}

int foregroundMode(){
    //Shell phải đợi tiến trình kết thúc
    return 0;
}
int backgroundMode(){
    //Shell và tiến trình thực hiện song song
    return 0;
}