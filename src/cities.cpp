/*
    cities.h的实现
*/

#include <cities.h>
#include <saveload.h>

#include <string>
#include <vector>

#ifdef CITIES_H_

City::City() : name(""), city_id(-1) {}
City::City(const std::string& _name, int _id) : name(_name), city_id(_id) {}
Map::Map() : distance{0} {}

City city[CITY_COUNT]; // 全部城市
Map map; // 地图

int City::getID() const { return city_id; }
std::string City::getName() const { return name; }

std::vector<std::pair<City*, int> > Map::TravelDst(City* cityPtr) {
    // 对某city，返回其能到达的city列表并标明距离
    std::vector<std::pair<City*, int> > res;
    int presentID = cityPtr->getID();
    for (int i = 0; i < CITY_COUNT; ++i) {
        // 遍历邻接矩阵
        if (map.distance[presentID][i] > 0) {
            res.push_back(std::make_pair(&city[i], map.distance[presentID][i]));
        }
    }
    return res;
}

void Map::LoadFrom(char* start) {
    // 从内存加载邻接矩阵
    memcpy(distance, start, CITY_COUNT * CITY_COUNT * sizeof(int));
}
void Map::SaveTo(int* saveLoc) const {
    // 向数组存储邻接矩阵
    memcpy(saveLoc, distance, CITY_COUNT * CITY_COUNT * sizeof(int));
}
void City::LoadFrom(const std::string& nameStr, int ID) {
    // 从字符串和ID初始化
    name = nameStr;
    city_id = ID;
}

void MapInit() {
    // 加载地图数据
    LoadMap(map);
    LoadCity(city);
}

#endif