#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

class String {
    char *str;
    unsigned int sizet = 0;

public:
    // constructors
    String() {
        str = new char[1];
        str[0] = '\0'; 
    }
    String(const char *str) {
        // this->str = new char[strlen(str) + 1];
        this->str = strdup(str);
        sizet = strlen(str);
    }

    // operators
    String &operator=(const String &obj) {
        delete []str;
        sizet = obj.sizet;
        str = new char[obj.sizet + 1];
        strcpy(str, obj.str);
        return *this;
    }
    const String operator+(const String obj) const {
        String result;
        result.sizet = this->sizet + obj.sizet;
        result.str = new char[result.sizet + 1];
        strcpy(result.str, this->str);
        strcat(result.str, obj.str);
        return result;
    }
    char &operator[](const int index) const {
        return str[index];
    }
    
    // functions
    const int size() const {
        return this->sizet;
    }
    const bool empty() const {
        return this->sizet == 0;
    }
    void push_back(const char c) {
        char s[] = {c, '\0'};
        *this = *this + s;
    }
    void append(const String obj) {
        *this = *this + obj;
    }
    void clear() {
        delete []this->str;
        str = nullptr;
        *this = String();
    }
    const char back() const {
        return this->str[sizet - 1];
    }
    vector<String> split(char delimiter) const {
        vector<String> tokens;
        String token = "";
        for (int i = 0; this->str[i] != '\0'; i++) {
            if (str[i] != delimiter) {
                token.push_back(str[i]);
            } else {
                // cout  << token << endl;
                tokens.push_back(token);
                token = "";
            }
        }

        if (!token.empty()) {
            // cout << token << endl;
            tokens.push_back(token);
        }
        return tokens;
    }

    // console output
    friend ostream &operator<<(ostream &os, const String& obj) {
        os << obj.str;
        return os;
    }
};

int main() {
    // String s = "Hi my name is Kunal Khallar";
    // vector<String> v = s.split(' ');
    // for(auto i : v) {
    //     cout << i << endl;
    // }
    String s = "yoyo";
    String t = s;
    t[1] = 'w';
    cout << s;
    return 0;
}
