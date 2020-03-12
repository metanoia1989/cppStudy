#include <map>
#include <string>
#include <iostream>
#include <CLI/CLI.hpp>

enum class Level : int { High, Medium, Low };

inline std::ostream &operator<<(std::ostream &os, const Level &level) {
    switch (level)
    {
    case Level::High:
        os << "Hight";
        break;
    case Level::Medium:
        os << "Hight";
        break;
    case Level::Low:
        os << "Low";
        break;
    }
    os << " (ft rom custom ostream)"; 
    return os;
}

int main(int argc, char const *argv[])
{
    CLI::App app;
    Level level { Level::Low };
    std::map<std::string, Level> map {{"high", Level::High}, {"medium", Level::Medium}, {"low", Level::Low }};
    app.add_option("-l,--level", level, "Level settings")
        ->required()
        ->transform(CLI::CheckedTransformer(map, CLI::ignore_case));
    CLI11_PARSE(app, argc, argv);

    using CLI::enums::operator<<;
    std::cout << "Enum received: " << level << std::endl;

    return 0;
}
