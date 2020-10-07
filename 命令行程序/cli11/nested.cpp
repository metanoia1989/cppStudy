#include <string>
#include <CLI/CLI.hpp>

int main(int argc, char const *argv[])
{
    CLI::App app {"Vision Application"};
    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_flag("--version", "Get version");

    CLI::App *cameraApp = app.add_subcommand("camera", "Configure the app camera");
    cameraApp->require_subcommand(0, 1); // 0 (default) or 1 camera

    std::string mvcamera_config_flie = "mvcamera_config.json";
    CLI::App *mvcameraApp = cameraApp->add_subcommand("mvcamera", "MatrixVision Camera Configuration");
    mvcameraApp->add_option("-c,--config", mvcamera_config_flie, "Config filename", true)->check(CLI::ExistingFile);

    std::string mock_camera_path;
    CLI::App *mockcameraApp = cameraApp->add_subcommand("mock", "Mock Camera Configuration");
    mockcameraApp->add_option("-p,--path", mock_camera_path, "Path")->required()->check(CLI::ExistingPath);

    CLI11_PARSE(app, argc, argv);

    return 0;
}
