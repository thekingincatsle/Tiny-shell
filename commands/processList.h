#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const int maxprocess = 3;

STARTUPINFO si[maxprocess];
PROCESS_INFORMATION pi[maxprocess];
int num_process = 0;