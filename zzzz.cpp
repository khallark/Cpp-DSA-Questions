#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <any>
#include <cxxabi.h>
#include <memory>
#include <queue>
using namespace std;

std::string demangle(const char* mangled_name) {
    int status = -1;
    // Demangle the name
    std::unique_ptr<char, void(*)(void*)> demangled_name(
        abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status),
        std::free);

    return (status == 0) ? demangled_name.get() : mangled_name;
}

int main() {;
    any a;
    a = vector<int>{1, 2, 3};
    a = 'h';
    // a = unordered_map<int, string>();
    // a = set<unordered_map<double, int>>();
    a = queue<unordered_map<double, int>>();
    // cout << any_cast<double>(a);
    cout << demangle(a.type().name());
    return 0;
}