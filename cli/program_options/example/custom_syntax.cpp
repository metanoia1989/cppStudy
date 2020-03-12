#include <iostream>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

using namespace boost::program_options;
using std::pair;
using std::string;

// 自定义option语法

pair<string, string> reg_foo(const string& s)
{
    if (s.find("-f") == 0) {
        if (s.substr(2, 3) == "no-") {
            return std::make_pair(s.substr(5), string("false"));
        } else {
            return std::make_pair(s.substr(2), string("true"));
        }
    } else {
        return std::make_pair(string(), string());
    }
}

int main(int argc, char const *argv[])
{
    try {
        options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce a help message")
            ("foo", value<string>(), "just an option");

        variables_map vm;
        store(command_line_parser(argc, argv).options(desc)
            .extra_parser(reg_foo).run(), vm);

        if (vm.count("help")) {
            std::cout << desc;
            std::cout << "\n In addition -ffoo and -fno-foo syntax are recognized.\n";
        }
        if (vm.count("foo")) {
            std::cout << "foo value with the value of "
                << vm["foo"].as<string>() << "\n";
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
