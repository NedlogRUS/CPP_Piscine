#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cerr;

class Sed {
private:
    string _filename;
    string _s1;
    string _s2;
    string _text;

public:
    Sed(const string& filename, const string& s1, const string& s2);
    ~Sed();
    bool checkArg();
    bool readFile();
    void replace();
    bool writeFile();
};

#endif // SED_HPP
