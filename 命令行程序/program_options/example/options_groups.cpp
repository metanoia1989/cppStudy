/** This example shows how to handle options groups.

    For a test, run:

    option_groups --help
    option_groups --num-threads 10
    option_groups --help-module backend

    The first invocation would show to option groups, and will not show the
    '--num-threads' options. The second invocation will still get the value of
    the hidden '--num-threads' option. Finally, the third invocation will show
    the options for the 'backend' module, including the '--num-threads' option.

*/

#include <iostream>
#include <fstream>
#include <exception>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>
using namespace boost;
using namespace boost::program_options;

int main(int argc, const char** argv) {
    try {
        options_description general("General options");
        general.add_options()
            ("help", "produce a help message")
            ("help-module", value<std::string>(), "produce a help for a given module")
            ("version", "output the version number");
        options_description gui("GUI options");
        gui.add_options()
            ("display", value<std::string>(), "display to use");

        options_description backend("Backend options");
        backend.add_options()
            ("num_threads", value<int>(), "the initial number of threads");

        options_description all("Allowed options"), visible("Allowed options");
        all.add(general).add(gui).add(backend);
        visible.add(general).add(gui);

        variables_map vm;
        store(parse_command_line(argc, argv, all), vm);

        if (vm.count("help")) {
            std::cout << visible;
            return 0;
        }

        if (vm.count("help-module")) {
            const std::string& s = vm["help-module"].as<std::string>();
            if (s == "gui") {
                std::cout << gui;
            } else if (s == "backend") {
                std::cout << backend;
            } else {
                std::cout << "Unknown module '" << s << "' in the --help-module options\n";
                return 1;
            }
        }

        if (vm.count("num-threads")) {
            std::cout << "The 'num-threads' options was set to " 
                << vm["num-threads"].as<int>() << "\n";
        }

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}