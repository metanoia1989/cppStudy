#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
using namespace boost;

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

int main(int argc, char const *argv[])
{
    try {
        int opt;   
        int portnum;
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "produce help message")
            ("optimization", po::value<int>(&opt)->default_value(10), 
                "optimization level")
            ("verbose,v", po::value<int>()->implicit_value(1), 
                "enable verbosity (optionally specify level)")
            ("listen,l", po::value<int>(&portnum)->implicit_value(1001)
                ->default_value(0, "No"), "listen on a port")
            ("include-path,I", po::value<std::vector<std::string>>(),
                "include path")
            ("input-file", po::value<std::vector<std::string>>(), 
                "input file");

        po::positional_options_description p;
        p.add("input-file", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(desc)
            .positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << "Usage: options_description [options]\n";
            std::cout << desc;
            return 0;
        }

        if (vm.count("include-path")) {
            std::cout << "Include paths are: " << 
                vm["include-path"].as<std::vector<std::string>>() << "\n";
        }

        if (vm.count("input-file")) {
            std::cout << "Input files are: " << 
                vm["input-file"].as<std::vector<std::string>>() << "\n";
        }

        if (vm.count("verbose")) {
            std::cout << "Verbosity enabled. Level is" << vm["verbose"].as<int>() << "\n";
        }

        std::cout << "Optimization level is " << opt << "\n";
        std::cout << "Listen port is " << portnum << "\n";

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n"; 
        return 1;
    }

    return 0;
}
