#include "Sed.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Error: Usage: " << argv[0] << " <filename> <find> <replace>" << endl;
        return 1;
    }
    Sed sed(argv[1], argv[2], argv[3]);
    if (!sed.checkArg()){
        cerr << "Error: Empty argument" << endl;
        return 1;
    }
    if (!sed.readFile()) {
        cerr << "Error: Could not open file: " << argv[1] << endl;
        return 1;
    }
    sed.replace();
    if (!sed.writeFile()) {
        cerr << "Error: Could not write to file: " << argv[1] << ".replace" << endl;
        return 1;
    }
    return 0;
}

