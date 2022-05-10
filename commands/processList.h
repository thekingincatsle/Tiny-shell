#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const int maxprocess = 3;

STARTUPINFO si[maxprocess];
PROCESS_INFORMATION pi[maxprocess];

int num_process = 0;

int mode = 0 ;    // mode = 0 <=> mode = foregroundMode ; mode = 1 <=> mode = backgroundMode
bool pi_run[maxprocess];