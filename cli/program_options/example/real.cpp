#include <iostream>
#include <boost/program_options.hpp>
using namespace boost::program_options;

// 辅助函数，检测输入验证

void conflicting_options(const variables_map& vm,
    const char* opt1, const char* opt2)
{
    if (vm.count(opt1) && !vm[opt1].defaulted() &&
        vm.count(opt2) && !vm[opt2].defaulted()) {
        throw std::logic_error(std::string("Conflictign options '")
            + opt1 + "' and '" + opt2 + "'.");
    }
}

void option_dependency(const variables_map& vm,
    const char* for_what, const char* required_option) 
{
    if (vm.count(for_what) && !vm[for_what].defaulted()){
        if (vm.count(required_option) == 0 || vm[required_option].defaulted()) {

            throw std::logic_error(std::string("Option '") + for_what 
                + "' requires option '" + required_option + "'.");
        }
    }
}

int main(int argc, char const *argv[])
{
    try {
        std::string ofile;
        std::string macrofile, libmakfile;
        bool t_given = false;
        bool b_given = false;
        std::string mainpackage;
        std::string depends = "deps_file";
        std::string sources = "str_file";
        std::string root = ".";

        options_description desc("Allowed options");
        desc.add_options()        
            ("help,h", "print usage message")
            ("output,o", value(&ofile), "pathanme for output")
            ("macrofile,m", value(&macrofile), "full apthname of macro.h")
            ("two,t", bool_switch(&t_given), "preprocess both header and boy")
            ("body,b", bool_switch(&b_given), "preprocess body in the header")
            ("libmakfile,l", value(&libmakfile), "write include makefile for library")
            ("depends,d", value(&depends), "write dependencies to <pathname>")
            ("sources,s", value(&sources), "write source package list to <pathname>")
            ("root,r", value(&root), "treat <dirname> as project root directory");

        variables_map vm;     
        store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 0;
        }

        conflicting_options(vm, "output", "two");
        conflicting_options(vm, "output", "body");
        conflicting_options(vm, "output", "mainpackage");
        conflicting_options(vm, "two", "mainpackage");
        conflicting_options(vm, "body", "mainpackage");

        conflicting_options(vm, "two", "body");
        conflicting_options(vm, "libmakfile", "mainpackage");
        conflicting_options(vm, "libmakfile", "mainpackage");

        option_dependency(vm, "depends", "mainpackage");
        option_dependency(vm, "sources", "mainpackage");
        option_dependency(vm, "root", "mainpackage");

        std::cout << "two = " << vm["two"].as<bool>() << "\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
