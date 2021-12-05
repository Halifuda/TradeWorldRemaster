/*
    检查map部分
*/

#include <cities.h>
#include <saveload.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern Map map;
extern City city[CITY_COUNT];

int main() {
    // #define __DEBUG

#ifndef __DEBUG
    LoadMap(map);
    LoadCity(city);
#endif
#ifdef __DEBUG
    LoadMap_debug(map, 0);
    LoadCity_debug(city, 0);
#endif
    int temp[CITY_COUNT][CITY_COUNT];
    map.SaveTo((int*)temp);
    for (int i = 0; i < CITY_COUNT; ++i) {
        for (int j = 0; j < CITY_COUNT; ++j) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < CITY_COUNT; ++i) {
        cout << city[i].getID() << ":" << city[i].getName() << endl;
    }

    return 0;
}