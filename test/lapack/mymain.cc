#include <iostream>

extern "C" {

double
dlamch_(char *c);

} // extern "C"

int
main()
{
    char c = 'p';
    std::cout << dlamch_(&c) << std::endl;
}
