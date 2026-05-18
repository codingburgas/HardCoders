#include "../include/utils.h"
#include <cctype>

using namespace std;

string toLowerStr(const string& s) {
    string result = s;
    for (char& c : result)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return result;
}

bool containsIgnoreCase(const string& str, const string& substr) {
    return toLowerStr(str).find(toLowerStr(substr)) != string::npos;
}
