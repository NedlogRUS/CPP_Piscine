#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed {
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _text;

public:
    Sed(const std::string& filename, const std::string& s1, const std::string& s2);
    ~Sed();
    bool checkarg();
    bool readFile();
    void replace();
    bool writeFile();
};

#endif // SED_HPP
