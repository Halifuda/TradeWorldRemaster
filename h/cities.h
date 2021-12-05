/*
    声明地图和城市信息
*/

#include <string>
#include <vector>
#include "constants.h"

# ifndef CITIES_H_
# define CITIES_H_

class City{  // 城市
    private:
     std::string name;  // 城市名字
     int city_id;   // 城市的唯一标号
    public:
     City();
     City(const std::string&, int);
     int getID() const; // 返回城市的唯一标号
     std::string getName() const; // 返回城市名字
     void LoadFrom(const std::string&, int); // 从string和int加载名字和id

};

class Map {
    private:
    int distance[CITY_COUNT][CITY_COUNT]; // 邻接矩阵
    public:
     Map();
     std::vector<std::pair<City*, int> > TravelDst(City*); // 相邻城市和到达距离
     void LoadFrom(char *); // 从数组加载distance
     void SaveTo(int *) const; // 向数组保存distance
};

void MapInit(); // 打开游戏时加载地图和城市

extern City city[CITY_COUNT]; // 所有城市的声明
extern Map map; // 地图的声明

# endif