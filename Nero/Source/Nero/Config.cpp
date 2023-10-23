
// ______________________________________________________________________

#include <Nero/Config.hpp>

// ______________________________________________________________________

namespace Nero
{
    bool Info(const std::string &p_Text)
    {
        std::cout << "\033[1;32m";
        std::cout << "[Info] " << p_Text;
        std::cout << "\033[0m" << std::endl;

        return true;
    }

    bool Warn(const std::string &p_Text)
    {
        std::cout << "\033[1;33m";
        std::cout << "[Warn] " << p_Text;
        std::cout << "\033[0m" << std::endl;

        return true;
    }

    bool Error(const std::string &p_Text)
    {
        std::cout << "\033[1;31m";
        std::cout << "[Error] "     << p_Text;
        std::cout << "\033[1;0m"    << std::endl;

        return false;
    }

    bool Fatal(const std::string &p_Text)
    {
        std::cout << "\033[1;31m";
        std::cout << "[Fatal] "     << p_Text;
        std::cout << "\033[1;0m"    << std::endl;

        return false;
    }
}

// ______________________________________________________________________
