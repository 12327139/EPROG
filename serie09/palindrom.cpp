#include<iostream>
#include<string>

using std::string;

bool cmp_char_ci(char a, char b) {
    int diff = abs(a - b);
    return diff == 0 || diff == 32;
}

bool isPalindrome(string wort) {
    for (int i = 0; i < wort.size() / 2; i++) {
        if (!cmp_char_ci(wort.at(i), wort.at(wort.size()-1-i))) return false;
    }
    return true;
}

int main() {
    std::cout << isPalindrome("anna") << std::endl;
    return 0;
}