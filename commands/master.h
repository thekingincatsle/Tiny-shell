#include <bits/stdc++.h>

#include "tung.h"
using namespace std;
/*
    >> How to add a command:
    Create a function take a string as argument and return an int as an error code
        0: no error, continue to run
        1: exit shell
        2, 3, ...
    Create instruction/doc (string)
    Add to funcmap in buildCommand() below.
    See echo command (in tung.h) for example. 
*/

void buildCommand() {
    funcmap["echo"] = funcAndInstruction(echo, echoDoc);
    funcmap["help"] = funcAndInstruction(help, helpDoc);
    funcmap["exit"] = funcAndInstruction(exitShell, exitShellDoc);
    funcmap["runexe"] = funcAndInstruction(runExe, runExeDoc);
}