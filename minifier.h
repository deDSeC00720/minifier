#include <fstream>
#include <vector>
using namespace std;

class minifier {
    ifstream fin;
    ofstream fout;
    vector<string> lines;
    string minified;

    public:
    minifier(string name, string ext) {
        fin.open(name + ext);
        fout.open(name + "-minified" + ext);
        while (!fin.eof()) {
            string line;
            getline(fin, line);
            lines.push_back(line);
        }
        fin.close();
        minified = "";
    }


    void minify() {
        for (int i = 0; i < lines.size(); i++) {
            lines[i] = removeWhiteSpaces(lines[i]);
            lines[i] = addNewLines(lines[i]);
        }

        for (string line : lines) {
            minified += line;
        }
        fout << minified;
    }

    string removeWhiteSpaces(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
                s = s.substr(i);
                break;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
                s = s.substr(0, i + 1);
                break;
            }
        }
        return s;
    }

    string addNewLines(string s) {
        if (s[0] == '#') {
            s = ((string) "\n").append(s).append("\n");
        }
        return s;
    }

    public:
    ~minifier() {
        fout.close();
    }
};