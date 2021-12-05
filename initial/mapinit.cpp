/*
    首次运行程序之前初始化地图和城市信息
*/

#include <cities.h>
#include <saveload.h>

#include <iostream>
#include <string>

extern Map map;
extern City city[CITY_COUNT];
int tempdis[CITY_COUNT][CITY_COUNT];

int main() {
    city[0].LoadFrom("吕贝克", 0);
    city[1].LoadFrom("不伦瑞克", 1);
    city[2].LoadFrom("科隆", 2);
    city[3].LoadFrom("但泽", 3);
    city[4].LoadFrom("威尼斯", 4);
    city[5].LoadFrom("米兰", 5);
    city[6].LoadFrom("那不勒斯", 6);
    city[7].LoadFrom("巴黎", 7);
    city[8].LoadFrom("佛罗伦萨", 8);
    city[9].LoadFrom("维也纳", 9);
    city[10].LoadFrom("奥格斯堡", 10);
    city[11].LoadFrom("安特卫普", 11);
    city[12].LoadFrom("伦敦", 12);
    city[13].LoadFrom("热那亚", 13);
    city[14].LoadFrom("布拉格", 14);
    city[15].LoadFrom("不来梅", 15);
    city[16].LoadFrom("日内瓦", 16);
    city[17].LoadFrom("里昂", 17);
    city[18].LoadFrom("斯特拉斯堡", 18);
    city[19].LoadFrom("尼斯", 19);

    tempdis[0][1] = tempdis[1][0] = 1;
    tempdis[0][2] = tempdis[2][0] = 3;
    tempdis[0][3] = tempdis[3][0] = 10;
    tempdis[0][10] = tempdis[10][0] = 5;
    tempdis[0][11] = tempdis[11][0] = 8;
    tempdis[0][12] = tempdis[12][0] = 10;
    tempdis[0][15] = tempdis[15][0] = 1;

    tempdis[1][2] = tempdis[2][1] = 2;
    tempdis[1][3] = tempdis[3][1] = 15;
    tempdis[1][10] = tempdis[10][1] = 4;
    tempdis[1][14] = tempdis[14][1] = 6;
    tempdis[1][15] = tempdis[15][1] = 3;

    tempdis[2][7] = tempdis[7][2] = 5;
    tempdis[2][10] = tempdis[10][2] = 4;
    tempdis[2][15] = tempdis[15][2] = 2;
    tempdis[2][18] = tempdis[18][2] = 4;

    tempdis[3][14] = tempdis[14][3] = 13;

    tempdis[4][8] = tempdis[8][4] = 1;
    tempdis[4][9] = tempdis[9][4] = 3;

    tempdis[5][8] = tempdis[8][5] = 1;
    tempdis[5][13] = tempdis[13][5] = 1;
    tempdis[5][16] = tempdis[16][5] = 3;
    tempdis[5][19] = tempdis[19][5] = 1;

    tempdis[6][8] = tempdis[8][6] = 8;

    tempdis[7][11] = tempdis[11][7] = 3;
    tempdis[7][18] = tempdis[18][7] = 3;

    tempdis[9][14] = tempdis[14][9] = 2;

    tempdis[10][16] = tempdis[16][10] = 3;
    tempdis[10][18] = tempdis[18][10] = 1;

    tempdis[11][12] = tempdis[12][11] = 5;
    tempdis[11][15] = tempdis[15][11] = 1;

    tempdis[13][19] = tempdis[19][13] = 1;

    tempdis[16][18] = tempdis[18][16] = 3;

    tempdis[17][18] = tempdis[18][17] = 4;
    tempdis[17][19] = tempdis[19][17] = 2;

    map.LoadFrom((char*)tempdis);

// #define __DEBUG

#ifdef __DEBUG
    SaveMap_debug(map, 0);
    SaveCity_debug(city, 0);
#endif
#ifndef __DEBUG
    SaveMap(map);
    SaveCity(city);
#endif
    return 0;
}