#include <iostream>

using namespace std;

namespace ns1 {
    int num = 42;
}

namespace ns2 {
    int num = 43;
}

using namespace ns1;
using namespace ns2;

int main(int argc, char *argv[]) 
{

    std::cout << "ns1: " << ns1::num << std::endl;
    std::cout << "ns2: " << ns2::num << std::endl;

    system("pause");
    return 0;
}