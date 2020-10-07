#include <string>
#include <iostream>
#include <ClI/CLI.hpp>

int main(int argc, char const *argv[])
{
    CLI::App test {R"raw(Modify the help print so that argument values are accessible.
        Note that this will not shortcut `->required` and other similar options.)raw"};
    test.set_help_flag();

    auto help = test.add_flag("-h,--help", "Request help");

    std::string some_option;
    test.add_option("-a", some_option, "Some description");

    try {
        test.parse(argc, argv);
        if (*help) {
            throw CLI::CallForHelp();
        }
    } catch(const CLI::Error& e) {
        std::cerr << "Option -a string in help: " << some_option << '\n';
        return test.exit(e);
    }

    std::cout << "Option -a string: " << some_option << std::endl;

    return 0;
}
