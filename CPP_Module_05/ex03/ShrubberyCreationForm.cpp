#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const string target) : AForm("ShrubberyCreationForm", 145, 137) {
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &obj) {
    AForm::operator=(obj);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    AForm::execute(executor);
    std::ofstream file;
    file.open(getTarget() + "_shrubbery");
    file << "                     ; ; ;\n"
            "                   ;        ;  ;     ;;    ;\n"
            "                ;                 ;         ;  ;\n"
            "                                ;\n"
            "                               ;                ;;\n"
            "               ;          ;            ;              ;\n"
            "               ;            ';,        ;               ;\n"
            "               ;              'b      *\n"
            "                ;              '$    ;;                ;;\n"
            "               ;    ;           $:   ;:               ;\n"
            "             ;;      ;  ;;      *;  @):        ;   ; ;\n"
            "                          ;     :@42):   ,;**:'   ;\n"
            "              ;      ;,         :@@*: ;;**'      ;   ;\n"
            "                       ';o;    ;:(@';@*\"'  ;\n"
            "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n"
            "                          ,p$q8,:@)'  ;p*'      ;\n"
            "                   ;     '  ; '@@42@@*'    ;  ;\n"
            "                    ;  ; ;;    42'.'     ;  ;\n"
            "                              :@):.\n"
            "                             .:@:'.'\n"
            "                           .::(@:.      \n";
    file.close();
}

AForm *ShrubberyCreationForm::clone(const string &target) const {
    return new ShrubberyCreationForm(target);
}