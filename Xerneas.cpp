#include <cstdlib>

int main()
{
     std::system("systemctl --user start rotom.service");
     std::system("systemctl --user start foresight.service");

}