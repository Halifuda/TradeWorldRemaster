# TRADEWORLD:REMASTER
# 交易神域：重制版
>version: 0
>
>版本：0（前期开发中）

>language: zh/Chinese
>
>语言：中文

> By Halifuda

## 简介 - Introduce
“交易神域：重制版”是以游戏“交易神域”为基础、以C++为代码语言编写的一款游戏。

该游戏以中世纪的中西欧主要城镇为故事场景。玩家将扮演旅行商人，在商业城市和重要市镇之间旅行、经商、赚取钱财。同时，游戏将为玩家提供一些符合背景的额外玩法，例如借还贷、魔法、神学等。

## 文件 - Files
* data/ : 保存游戏数据
  
  * cityname.tdat: 保存城市名字信息，文本格式
  * map.tdat: 保存地图全貌信息，二进制格式
  
* debug/ : 用以检查代码错误的程序代码
  
  * mapdebug.cpp: 对地图部分检查的代码
  
* h/ : 包含文件
  * character.h: 角色类的声明，包括Character,NPC,Player,Lender,Alchemist
  * cities.h: 城市和地图的声明，包括City,Map和全局变量map,city[]
  * constants.h: 编译时常量
  * relation.h: Character之间关系变量的声明
  * saveload.h: 用以保存和加载数据的方法的声明
  * utlis.h: 普遍用到的方法的声明

* initial/ : 初始化游戏数据的程序代码
  * mapinit.cpp: 初始化地图数据

* obj/ : 编译得到的可重定位目标文件

* src/ : h/包含文件的实现代码
  * cities.cpp: cities.h的实现
  * saveload.cpp: saveload.cpp的实现

* Makefile : 编译文件
* README.md : 说明文件

## 环境 - Environments
mingwx64-8.1.0

## 编译运行 - Compile & Run
详见Makefile

