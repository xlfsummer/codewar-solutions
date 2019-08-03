#include <vector>
#include <string>

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        auto oneSideSpaceInFloor = [=](int floor){ return nFloors - floor; };
        auto starInFloor = [](int floor){ return floor * 2 - 1; };
        std::vector<std::string> v(nFloors);
        for(int f = 0; f < nFloors; f++){
            std::string s("");
            s.append(oneSideSpaceInFloor(f), ' ');
            s.append(starInFloor(f), '*');
            s.append(oneSideSpaceInFloor(f), ' ');
            v.push_back(s);
        }
        return v;
    }
};

int main(int argc, char const *argv[]){

}
