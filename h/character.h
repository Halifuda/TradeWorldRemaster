/*
    角色有关的信息声明在此
*/

#include <string>
#include "constants.h"
#include "cities.h"

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character { // 角色类
   private:
    std::string name;          // 角色名字
    int id;                    // 角色唯一标号
    double cash;               // 角色所持现金
    double goods[GOOD_KINDS];  // 角色现持的货物数量
    double price[GOOD_KINDS];  // 角色对各种货物的预期价位
    City* present_city;        // 角色所在城市

   public:
    Character();
    Character(const Character&); 
    std::string Name(); // 返回角色名字
};

class Player : public Character { // 玩家
   private:
    long long passkey; // 密码的哈希值
    std::string playerID, password; // 账户和密码

   public:
    Player();
    Player(std::string, std::string);
};

class NPC : public Character {}; // 普通NPC,无特殊之处

class Lender : public Character { // 债主
   private:
    double interest_wish;  // wished interest 债主借债时的期望利息
   public:
    Lender();
    Lender(const Lender&);
    Lender(double);
};

# endif