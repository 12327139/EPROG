#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

vector<string> split(string word, char delimiter) {
    vector<string> words(0);
    string current_word = ""; 
    for (int i = 0; i < word.size(); i++) {
        if (word.at(i) != delimiter) {
            current_word += word.at(i);
        } else {
            words.push_back(current_word);
            current_word = "";
        }
    }
    words.push_back(current_word);
    return words;
}

string concat(vector<string> words) {
    string word = "";
    for (int i = 0; i < words.size() - 1; i++) {
        word += words.at(i);
        word += " ";
    }
    word += words.at(words.size() - 1);
    return word;
}

class Name {
private:
    string first_name;
    string surname;
public:
    Name() {
        first_name = "";
        surname = "";
    }
    string getFirstName();
    void setFirstName(string first_name);
    string getSurname();
    void setSurname(string surname);
    void setFullName(string full_name);
    void printName();
};

string Name::getFirstName() {
    return this->first_name;
}

void Name::setFirstName(string first_name) {
    this->first_name = first_name;
}

string Name::getSurname() {
    return this->surname;
}

void Name::setSurname(string surname) {
    this->surname = surname;
}

void Name::setFullName(string full_name) {
    vector<string> names = split(full_name, ' ');
    this->setSurname(names.at(names.size() - 1));
    names.pop_back();
    string first_name = concat(names);
    this->setFirstName(first_name);
}

void Name::printName() {
    vector<string> names = split(this->getFirstName(), ' ');
    std::cout << names.at(0) << " ";
    for (int i = 1; i < names.size(); i++) {
        std::cout << names.at(i).at(0) << ". ";
    }
    std::cout << this->surname << std::endl;
}

int main() {
    Name maxi = Name();
    maxi.setFullName("Maximilian Maxi Maximus Margarethe Perathoner");
    maxi.printName();
    return 0;
}