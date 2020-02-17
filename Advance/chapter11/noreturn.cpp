#include <cstdlib>

[[noreturn]] void forceProgramTermination()
{
    std::exit(1);
}

bool isDongleAvailable()
{
    bool isAvailable = false;
    return isAvailable;
}

bool isFeatureLicensed(int featureId)
{
    if (!isDongleAvailable()) {
        forceProgramTermination();
    } else {
        bool isLicensed = false;
        return isLicensed;
    }
}

int main()
{
    bool isLicensed = isFeatureLicensed(42);
}