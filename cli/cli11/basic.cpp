#include "CLI/CLI.hpp"

int main(int argc, char const *argv[])
{
    CLI::App app;

    CLI11_PARSE(app, argc, argv);

    return 0;
}
