#include <iostream>
#include <string>
#include <CLI/CLI.hpp>

// 用户自定义参数项

int main(int argc, char const *argv[])
{
    CLI::App app("callback_passthrough");
    app.allow_extras();
    std::string argName;
    std::string val;
    app.add_option("--argname", argName, "the name of custom command line argument");
    app.callback([&app, &val, &argName](){
        if (!argName.empty()) {
            CLI::App subApp;
            subApp.add_option("--" + argName, val, "custom argument option");
            subApp.parse(app.remaining_for_passthrough());
        }
    });

    CLI11_PARSE(app, argc, argv);
    std::cout << "the value is now " << val << "\n";

    return 0;
}
