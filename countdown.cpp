#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    for (int i = 120000; i >= 0; --i) {
        cout << i << endl;
        usleep(50000);
    }
}