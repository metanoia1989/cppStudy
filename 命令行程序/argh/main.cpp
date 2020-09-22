#include <iostream>
#include "argh.h"

int main(int argc, char const *argv[])
{
    argh::parser cmd1;
    cmd1.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

    if (cmd1["-v"]) {
        std::cout << "Verbose, I am." << std::endl;        
    }

    std::cout << "Positional args:\n";
    for (auto& pos_arg : cmd1) {
        std::cout << "\t" << pos_arg << std::endl;
    }

    std::cout << "Positional args:\n";
    for (auto& pos_arg : cmd1.pos_args()) {
        std::cout << "\t" << pos_arg << std::endl;
    }

    std::cout << "\nFlags:\n";
    for (auto& flag : cmd1.flags()) {
        std::cout << "\t" << flag << std::endl;
    }

    std::cout << "\nParameters:\n";
    for (auto& param : cmd1.params()) {
        std::cout << "\t" << param.first << " : " << param.second << std::endl;
    }

    return EXIT_SUCCESS;
}
