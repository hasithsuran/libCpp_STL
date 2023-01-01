#pragma once
#include <map>
#include <string>
#include <iostream>

namespace techyB
{
    class TC_Map
    {
    private:
        std::map<std::string, std::string> stringMap;
        const int COLUMN_WIDTH{20};
        void printMap(const auto &pMap);

    public:
        class MapObject
        {
        public:
            MapObject(const MapObject& rhs)
            {
                std::cout << "Copy constructor" << std::endl;
            }
            MapObject &operator=(const MapObject &rhs)
            {
                std::cout << "assignment =" << std::endl;
                return *this;
            }
            MapObject()
            {
                std::cout << "Default constructor" << std::endl;
            }
            ~MapObject()
            {
                std::cout << "MapObject destructor" << std::endl;
            }
        };
        TC_Map() : stringMap{{"name", "Suran"}, {"age", "31"}} {}
        void initDemo();
        void attributeDemo();
        void insertOrAssign();
        void creationDemo();
    };

} // namespace techyB
