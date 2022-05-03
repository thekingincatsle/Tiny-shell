#include <bits/stdc++.h>

#include "tung.h"
using namespace std;
/*
    >> How to add command:
    Create a function take a string as argument and return an int as error code
        0: no code, continue to run
        1: exit code
    Create instruction/doc
    Add to funcmap in buildCommand() below.
    See Hello command for example. (sth in tung.h)
*/

void buildCommand() {
    funcmap["echo"] = funcAndInstruction(echo, echoDoc);
    funcmap["help"] = funcAndInstruction(help, helpDoc);
    funcmap["exit"] = funcAndInstruction(exitShell, exitShellDoc);
    funcmap["runexe"] = funcAndInstruction(runExe, runExeDoc);
}