#include <iostream>
#include <fstream>
#include <string>

void replaceInString(std::string& source, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = source.find(s1, pos)) != std::string::npos) {
        source.erase(pos, s1.length());
        source.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return 1;
    }

    std::string outputFile = filename + ".replace";
    std::ofstream output(outputFile);
    if (!output.is_open()) {
        std::cerr << "Could not create file: " << outputFile << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        replaceInString(line, s1, s2);
        output << line << '\n';
    }

    inputFile.close();
    output.close();

    return 0;
}
