#include <TC_Vector.h>
#include <iostream>

namespace techyB
{
    
void TC_Vector::printVec() {
    auto vecIt = intVec.begin();
    while(vecIt != intVec.end()) {
        std::cout << "Vector element : " << *vecIt << std::endl;
        vecIt++;
    }
}

} // namespace techyB