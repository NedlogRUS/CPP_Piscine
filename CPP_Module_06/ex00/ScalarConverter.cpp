#include "ScalarConverter.hpp"

char		ScalarConverter::_char = 0;
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0;
double		ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
    if (this != &copy)
    {
    }
    return (*this);
}

ScalarConverter::z_type ScalarConverter::parse(std::string const &input){
    if (input.length() == 1 && !isdigit(input[0]))
    {
        _char = input[0];
        return (CHAR);
    }
    size_t i = 0;
    if (input[0] == '-')
        i++;
    for (; i < input.length(); i++)
    {
        if ((!isdigit(input[i]) && input[i] != 'f' && input[i] != '.') || (input[i] == 'f' && input[i + 1]))
            return (INVALID);
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            while (input[i] != 'f' && i < input.length())
                i++;
            if ((input[i] == 'f' && !input[i + 1]) || i == input.length())
            {
                _float = atof(input.c_str());
                return (FLOAT);
            }
        }
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            size_t j = 0;
            while (i < input.length())
            {
                i++;
                j++;
            }
            if (i == input.length() && j > 6)
            {
                _double = atof(input.c_str());
                return (DOUBLE);
            }
            else
            {
                _float = atof(input.c_str());
                return (FLOAT);
            }
        }
    }
    i = 0;
    if (input[0] == '-')
        i++;
    for (; i < input.length(); i++)
    {
        if (i == input.length() - 1)
        {
            _double = atof(input.c_str());
            if (_double > INT_MAX || _double < INT_MIN)
                return (DOUBLE);
            _int = atoi(input.c_str());
            return (INT);
        }
    }
    return (INVALID);
}

void		ScalarConverter::print(z_type type){
    if (type == CHAR)
    {
        std::cout << "char: ";
        if (_char >= 32 && _char <= 126)
            std::cout << "'" << _char << "'" << std::endl;
        else if ((_char >= 0 && _char <= 31 )|| _char == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(_char) << std::endl;
        std::cout << "float: " << static_cast<float>(_char) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(_char) << ".0" << std::endl;
    }
    else if (type == INT)
    {
        std::cout << "char: ";
        if (_int >= 32 && _int <= 126)
            std::cout << "'" << static_cast<char>(_int) << "'" << std::endl;
        else if ((_int >= 0 && _int <= 31 )|| _int == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: " << _int << std::endl;
        std::cout << "float: " << static_cast<float>(_int) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(_int) << ".0" << std::endl;
    }
    else if (type == FLOAT)
    {
        std::cout << "char: ";
        if (_float >= 32 && _float <= 126)
            std::cout << "'" << static_cast<char>(_float) << "'" << std::endl;
        else if ((_float >= 0 && _float <= 31 )|| _float == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (_float >= std::numeric_limits<int>::min() && _float <= std::numeric_limits<int>::max())
            std::cout << static_cast<int>(_float) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (_float == static_cast<int>(_float)) {
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(_float) << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << _float << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(_float) << std::endl;
        }
    }
    else if (type == DOUBLE)
    {
        std::cout << "char: ";
        if (_double >= 32 && _double <= 126)
            std::cout << "'" << static_cast<char>(_double) << "'" << std::endl;
        else if ((_double >= 0 && _double <= 31 )|| _double == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (_double >= std::numeric_limits<int>::min() && _double <= std::numeric_limits<int>::max())
            std::cout << static_cast<int>(_double) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        if (_float == static_cast<int>(_float)){
            std::cout << "float: " << static_cast<float>(_double) << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << static_cast<float>(_double) << "f" << std::endl;
            std::cout << "double: " << _double << std::endl;
        }
    }
}

bool ScalarConverter::is_inf(std::string const &input){
    if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return (true);
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (true);
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (true);
    }
    return (false);
}

void ScalarConverter::convert(std::string const &input){
    z_type type = parse(input);
    if(is_inf(input))
        return;
    if (type == INVALID)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return;
    }
    if (type == CHAR)
        print(CHAR);
    else if (type == INT)
        print(INT);
    else if (type == FLOAT)
        print(FLOAT);
    else if (type == DOUBLE)
        print(DOUBLE);
}
