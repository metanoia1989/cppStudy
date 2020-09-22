#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

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
        std::string config_file;

        po::options_description generic("Generic options");
        generic.add_options()
            ("version,v", "print version string")
            ("help,h", "produce help message")
            ("config,c", po::value<std::string>(&config_file)->default_value("multiple_sources.cfg"),
                "name of a file of configuration.");

        po::options_description config("Configuration");
        config.add_options()
            ("optimization", po::value<int>(&opt)->default_value(10), "optimization level")
            ("include-path,I", po::value<std::vector<std::string>>()->composing(), "include path");

        po::options_description hidden("Hidden options");
        hidden.add_options()
            ("input-file", po::value<std::vector<std::string>>(), "intpu file");

        po::options_description cmdline_options, config_file_options, visible("Alow options");
        cmdline_options.add(generic).add(config).add(hidden);
        config_file_options.add(config).add(hidden);
        visible.add(generic).add(config);

        po::positional_options_description p;
        p.add("input-file", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
        po::notify(vm); 

        std::ifstream ifs(config_file.c_str());
        if (!ifs) {
            std::cout << "can not open config file: " << config_file << "\n";
            return 0;
        } else {
            po::store(po::parse_config_file(ifs, config_file_options), vm);
            po::notify(vm);
        }

        if (vm.count("help")) {
            std::cout << visible << "\n";
            return 0;
        }

        if (vm.count("versiont")) {
            std::cout << "Multiple sources example, version 1.0\n";
            return 0;
        }

        if (vm.count("include-path")) {
            std::cout << "Include path are: " 
                << vm["include-path"].as<std::vector<std::string>>() << "\n";
        }

        if (vm.count("input-file")) {
            std::cout << "Input file are: "
                << vm["input-file"].as<std::vector<std::string>>() << "\n";
        }

        std::cout << "Optimization level is" << opt << "\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
