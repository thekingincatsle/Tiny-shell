#include <bits/stdc++.h>
using namespace std;

#pragma once

struct funcAndInstruction {
    function<int(string)> func;
    string instruction;

    funcAndInstruction() {
        func = [](string c) { return 0; };
        instruction = "default command";
    }

    funcAndInstruction(function<int(string)> funcc, string instructionn) : func(funcc), instruction(instructionn) {}
};
map<string, funcAndInstruction> funcmap;