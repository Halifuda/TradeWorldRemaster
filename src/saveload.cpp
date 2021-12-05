/*
    saveload.h的实现
*/

#include <cities.h>
#include <saveload.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#ifdef SAVELOAD_H_

/*
    map.tdat : 存储地图信息，二进制格式
        CITY_COUNT * CITY_COUNT * sizeof(int) 字节：
        map->distance
        然后对齐到8字节

    cityname.tdat : 存储city名信息，文本格式
        第i行：city[i]->name
*/

void LoadMap(Map& map) {  // 从存储文件读map信息
    std::fstream fin("data\\map.tdat", std::ios::in | std::ios::binary);
    int temp[CITY_COUNT][CITY_COUNT];
    fin.read((char*)temp, CITY_COUNT * CITY_COUNT * sizeof(int));
    // 读map->distance
    map.LoadFrom((char*)temp);
    // Load到map中
    fin.close();
}
void LoadCityName(City* cities) {  // 从存储文件读city名字信息
    std::fstream fin("data\\cityname.tdat", std::ios::in);
    std::string tempStr;
    for (int i = 0; i < CITY_COUNT; ++i) {
        fin >> tempStr;
        cities[i].LoadFrom(tempStr, i);
    }
    fin.close();
}
void LoadCity(City* cities) {  // 从存储文件读city信息
    LoadCityName(cities);
}
void SaveMap(const Map& map) {  // 向存储文件写map信息
    std::fstream fout("data\\map.tdat", std::ios::out | std::ios::binary);
    int* temp = new int[CITY_COUNT * CITY_COUNT];
    map.SaveTo(temp);
    fout.write((char*)temp, CITY_COUNT * CITY_COUNT * sizeof(int));
    // 写map->distance
    delete[] temp;
    fout.close();
}
void SaveCityName(const City* cities) {  // 向存储文件写city名字信息
    std::fstream fout("data\\cityname.tdat", std::ios::out);
    for (int i = 0; i < CITY_COUNT; ++i) {
        fout << cities[i].getName() << std::endl;
    }
    fout.close();
}
void SaveCity(const City* cities) {  // 向存储文件写city信息
    SaveCityName(cities);
}

#endif
