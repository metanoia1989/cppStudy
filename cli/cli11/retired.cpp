#include <vector>
#include <utility>
#include <iostream>
#include <CLI/CLI.hpp>

int main(int argc, char const *argv[])
{
    CLI::App app {"example for retired/deprecated options"};
    std::vector<int> x;
    auto opt1 = app.add_option("--retired_option2", x);

    std::pair<int, int> y;
    auto opt2 = app.add_option("--deprecate", y);

    app.add_option("--not_deprecated", x);

    CLI::retire_option(app, "--retired_option");
    CLI::retire_option(app, opt1); 
    CLI::deprecate_option(opt2, "--not_deprecated");

    CLI11_PARSE(app, argc, argv);

    if (!x.empty()) {
        std::cout << "Retired option example: got --not_deprecated values:";
        for (auto &xval : x) {
            std::cout << xval << " "; 
        }
        std::cout << "\n"; 
    } else if(app.count_all() == 1) {
        std::cout << "Retired option example: no arguments received\n";
    }

    return 0;
}
