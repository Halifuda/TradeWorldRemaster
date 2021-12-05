/*
    声明角色之间的关系
*/

#include "constants.h"

# ifndef RELATION_H_
# define RELATION_H_

extern bool relaFriends[CHARACTER_COUNT][CHARACTER_COUNT];
// 两人是否是朋友
extern bool relaLendFlag[CHARACTER_COUNT][LENDER_COUNT];
// 是否借债
extern double relaLended[CHARACTER_COUNT][LENDER_COUNT];
// 借债金额
extern double relaInterest[CHARACTER_COUNT][LENDER_COUNT];
// 借债利息

# endif
