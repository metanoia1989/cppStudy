#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <CLI/CLI.hpp>

int main(int argc, char const *argv[])
{
    CLI::App app {"An app to practice mxing unlimited arguments, but still recover the original order."};

    std::vector<int> foos;
    auto foo = app.add_option("--foo,-f", foos, "Some unlimited argument");

    std::vector<int> bars;
    auto bar = app.add_option("--bar", bars, "Some unlimited argument");

    app.add_flag("--z,--x", "Random other flags");

    try {
        app.parse(argc, argv);
    } catch(const CLI::ParseError &e) {
        return app.exit(e);
    }

    std::reverse(std::begin(foos), std::end(foos));
    std::reverse(std::begin(bars), std::end(bars));

    std::vector<std::pair<std::string, int>> keyval;
    for (const auto &option : app.parse_order()) {
        if (option == foo) {
            keyval.emplace_back("foo", foos.back());
            foos.pop_back();
        } 
        if (option == bar) {
            keyval.emplace_back("bar", bars.back());
            bars.pop_back();
        } 
    }
    for (auto &pair : keyval) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}

