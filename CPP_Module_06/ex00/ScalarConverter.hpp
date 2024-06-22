#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    static char _char;
    static int _int;
    static float _float;
    static double _double;
    enum z_type{
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        INVALID,
    };
    static void print(z_type type);
    static z_type parse(std::string const &input);
    static bool is_inf(std::string const &input);
public:
    static void convert(std::string const &input);
};

#endif //SCALARCONVERTER_HPP
