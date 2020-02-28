// This example shows how a user-defined class can be parsed using
// specific mechanism -- not the iostream operations used by default.
//
// A new class 'magic_number' is defined and the 'validate' method is overloaded
// to validate the values of that class using Boost.Regex.
// To test, run
//   
//    regex -m 123-456
//    regex -m 123-4567
// 
// The first invocation should output:
//
//   The magic is "456"
//
// and the second invocation should issue an error message.

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/regex.hpp>

using namespace boost;
using namespace boost::program_options;

struct magic_number {
    public:
        magic_number(int n) : n(n) {}
        int n;
};

void validate(boost::any& v, 
    const std::vector<std::string>& values,
    magic_number*, int)
{
    static regex r("\\d\\d\\d-(\\d\\d\\d)");
    validators::check_first_occurrence(v);
    const std::string& s = validators::get_single_string(values);

    smatch match;
    if (regex_match(s, match, r)) {
        v = any(magic_number(lexical_cast<int>(match[1])));
    } else {
        throw validation_error(validation_error::invalid_option_value);
    }
}

int main(int argc, char const *argv[])
{
    try {
        options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce a help screen")
            ("version,v", "print the version number")
            ("magic,m", value<magic_number>(), 
                "magic value (in NNN-NNN format)");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << "Usage: regex [options]\n";
            std::cout << desc;
            return 0;
        }

        if (vm.count("version")) {
            std::cout << "Version 1.\n";
            return 0;
        }

        if (vm.count("magic")) {
            std::cout << "The magic is \""
                << vm["magic"].as<magic_number>().n << "\"\n";
        }

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
        
    return 0;
}
