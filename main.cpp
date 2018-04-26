#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;
const string SHAKEFILE = "shakespeare.txt";

vector<string> getWords(string line);
string RemoveSpecials(string str);

int main() {

    ifstream shakefile;
    vector<string> lines;
    string line;

    shakefile.open(SHAKEFILE);
    if (shakefile.fail()) {
        cout << "Couldn't open: " << SHAKEFILE << endl;
        exit(1);
    }
    
    while (!shakefile.eof()) {
        getline(shakefile,line);
        lines.push_back(line);
    }
    
    string word;
    cout << "Gimme a word to find: ";
    cin >> word;
    word = RemoveSpecials(word);
    // Loop through lines
    for (int i = 0; i < lines.size(); i++) {
        line = lines.at(i);
        string tempLine = RemoveSpecials(line);
        vector<string> words = getWords(tempLine);
        for (int j = 0; j < words.size(); j++) {
            if (word == words.at(j)) {
                cout << line << endl;
                break;
            }
        }
    }
    //write code to search for matches
    return 0;
}

vector<string> getWords(string line) {
    istringstream iss(line);
    vector<string> words;
    string s;
    do {
        iss >> s;
        if (s.length() > 0 && s != " ") {
            words.push_back(s);
            //cout << s << " ";
        }
        s="";
    } while (iss);
    return words;

}

string RemoveSpecials(string str) {
    int i = 0, len = str.length();
    while (i < len) {
        char c = str[i];
        if (((c >= '0')&&(c <= '9')) || ((c >= 'A')&&(c <= 'Z')) || ((c >= 'a')&&(c <= 'z')) || c == '\'' || c == ' ') {
            if ((c >= 'A')&&(c <= 'Z')) str[i] += 32; //Assuming dictionary contains small letters only.
            ++i;
        } else {
            str.erase(i, 1);
            --len;
        }
    }
    return str;
}