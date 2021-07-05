#include <iostream>
using namespace std;
#include "minifier.h"

pair<string, string> getFileName(string filename) {
    pair<string, string> p;
    int pos = filename.find_last_of('.');
    p.first = filename.substr(0, pos);
    p.second = filename.substr(pos);
    return p;
}

int main(int n, char **args) {
    if (n < 2) {
        cout << "file argument is missing." << endl;
        exit(1);
    }
    if (n > 2) {
        cout << "Only 1 argument is needed" << endl;
        exit(1);
    }

    pair<string, string> filename = getFileName(args[1]);
    minifier m(filename.first, filename.second);
    m.minify();
}