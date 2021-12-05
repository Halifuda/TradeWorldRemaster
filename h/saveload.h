/*
    保存与加载信息的方法
*/

#ifndef SAVELOAD_H_
#define SAVELOAD_H_

struct MapHeader { // 地图文件头
    unsigned short offDistance;
};
struct CityHeader { // 城市文件头
    unsigned short offCityValue[CITY_COUNT];
};

void SaveMap(const Map&); // 保存地图
void SaveCity(const City*); // 保存城市
void LoadMap(Map&); // 加载地图
void LoadCity(City*); // 加载城市

#endif