#include "Sed.hpp"

Sed::Sed(const string& filename, const string& s1, const string& s2) : _filename(filename), _s1(s1), _s2(s2) {}

Sed::~Sed() {}

bool Sed::readFile() {
    std::ifstream file(_filename);
    if (!file.is_open()) return false;

    _text = string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return true;
}

bool Sed::checkArg() {
    if (_filename.empty() || _s1.empty() || _s2.empty())
        return false;
    return true;
}

void Sed::replace() {
    size_t pos = 0;
    while ((pos = _text.find(_s1, pos)) != string::npos) {
        _text.erase(pos, _s1.length());
        _text.insert(pos, _s2);
        pos += _s2.length();
    }
}

bool Sed::writeFile() {
    std::ofstream file(_filename + ".replace");
    if (!file.is_open()) return false;

    file << _text;
    file.close();
    return true;
}