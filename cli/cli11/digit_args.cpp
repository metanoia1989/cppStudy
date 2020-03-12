#include <iostream>
#include <CLI/CLI.hpp>

// 添加一组具有与其关联的默认值的标志

int main(int argc, char const *argv[])
{
    CLI::App app;

    int val {0};
    app.add_flag("-1{1},-2{2},-3{3},-4{4},-5{5},-6{6},-7{7},-8{8},-9{9}", val, "compression level");

    CLI11_PARSE(app, argc, argv);

    std::cout << "value = " << val << std::endl;

    return 0;
}
