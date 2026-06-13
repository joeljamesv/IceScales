#include <cstdlib>

int main()
{
     std::system("systemctl --user stop foresight.service");
     std::system("systemctl --user start rotomWash.service");
}