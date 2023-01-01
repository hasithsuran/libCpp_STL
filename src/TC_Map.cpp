#include <TC_Map.h>
#include <algorithm>
#include <iomanip>

std::ostream &operator<<(std::ostream &out, const techyB::TC_Map::MapObject &mObj)
{
    return out << &mObj;
}

namespace techyB
{
    void TC_Map::printMap(const auto &pMap)
    {
        for_each(pMap.begin(), pMap.end(), [this](const auto &entry)
                 { std::cout << std::setw(COLUMN_WIDTH) << "key : " << entry.first
                             << std::setw(COLUMN_WIDTH) << ", value : " << entry.second
                             << std::endl; });
    }

    void TC_Map::creationDemo()
    {
        std::map<int, int> intMap1;
        //** demo map value initialization
        // 1) using insertion of pairs
        intMap1.insert(std::pair<int, int>(1, 40));
        intMap1.insert(std::pair<int, int>(2, 30));
        intMap1.insert(std::pair<int, int>(3, 60));
        intMap1.insert(std::pair<int, int>(4, 20));
        intMap1.insert(std::pair<int, int>(5, 50));

        std::cout << "New int map created (intMap1) : " << std::endl;
        printMap(intMap1);

        // 2) copying existing map using iterators
        std::cout << "Copied contents to intMap2 using iterators : " << std::endl;
        std::map<int, int> intMap2(intMap1.begin(), intMap1.end());
        printMap(intMap2);

        std::cout << "Modifying elements of intMap2 : " << std::endl;
        //** demo erasing elements
        // 1) using iterator range
        std::cout << "erasing elemetns upto key 3 element from start  : " << std::endl;
        intMap2.erase(intMap2.begin(), intMap2.find(3));
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "New intMap2 map contents : " << std::endl;
        printMap(intMap2);

        // 2) using key values directly
        intMap2.erase(5); // erase all elements with key 5
        std::cout << "New intMap2 after erasing element with key 5 : " << std::endl;
        printMap(intMap2);

        std::cout << "Creating MapObject map (mapObjectMap3) : " << std::endl;
        std::map<int, MapObject> mapObjectMap3;
        mapObjectMap3.insert(std::pair<int, MapObject>(1, MapObject()));
        mapObjectMap3.insert(std::pair<int, MapObject>(2, MapObject()));
        mapObjectMap3.insert(std::pair<int, MapObject>(3, MapObject()));

        std::cout << "New MapObject map created (mapObjectMap3) : " << std::endl;
        printMap(mapObjectMap3);
        std::cout << "trying to reassign element with key 3" << std::endl;
        mapObjectMap3.insert_or_assign(3, MapObject());
    }

    void TC_Map::attributeDemo()
    {
        std::cout << "Map property demo ==============" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "size : "
                  << std::setw(COLUMN_WIDTH) << stringMap.size() << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "max size : "
                  << std::setw(COLUMN_WIDTH) << stringMap.max_size() << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "is map empty ?  : "
                  << std::setw(COLUMN_WIDTH) << std::boolalpha << stringMap.empty() << std::endl;

        std::cout << "Creating a new map ... " << std::endl;
        std::map<int, std::string> intMap1{{1, "Suran"}, {3, "Kamal"}, {2, "Namal"}};
        std::cout << "initial map contents : " << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        printMap(intMap1);

        std::cout << "After adding more items to map ... " << std::endl;
        std::cout << "Printing using iterators ... " << std::endl;
        intMap1[4] = "Ajith";
        intMap1[5] = "Nirmal";
        std::cout << std::endl;
        std::cout << std::endl;

        std::map<int, std::string>::iterator it = intMap1.begin();
        while (it != intMap1.end())
        {
            std::cout << std::setw(COLUMN_WIDTH) << "key : " << it->first
                      << std::setw(COLUMN_WIDTH) << ", value : " << it->second
                      << std::endl;
            it++;
        }

        // insert does not add a pair if the key already exists. if not it will add it
        intMap1.insert(std::pair<int, std::string>(5, "Geethmal"));
        intMap1.insert(std::pair<int, std::string>(6, "Chameera"));

        std::cout << "After adding pairs to map (with keys 5 and 6) ... " << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        printMap(intMap1);

        // but [] operator always replaces the key value pair with new value if exists
        intMap1[5] = "Geethmal";

        std::cout << "After replacing 5 key in map ... " << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        printMap(intMap1);
    }

    void TC_Map::insertOrAssign()
    {
        auto print_node = [](const auto &node)
        {
            std::cout << "[" << node.first << "] = " << node.second << '\n';
        };

        auto print_result = [&print_node](auto const &pair)
        {
            std::cout << (pair.second ? "inserted: " : "assigned: ");
            print_node(*pair.first);
        };

        std::map<std::string, std::string> myMap;

        print_result(myMap.insert_or_assign("a", "apple"));
        print_result(myMap.insert_or_assign("b", "banana"));
        print_result(myMap.insert_or_assign("c", "cherry"));
        print_result(myMap.insert_or_assign("c", "clementine"));

        for (const auto &node : myMap)
        {
            print_node(node);
        }
    }

    void TC_Map::initDemo()
    {
        auto printFunc = [](const auto &obj)
        {
            std::cout << "key : " << obj.first << ", value : " << obj.second << std::endl;
        };
        for_each(stringMap.cbegin(), stringMap.cend(), printFunc);
    }

} // namespace techyB
