/*
    声明需要用到的操作
*/

#include <string>

# ifndef OPERATIONS_H_
# define OPERATIONS_H_

// MATH FUNCTIONS
template <typename T>
T _ReLU(T);  
// f = x > 0 ? x : 0
bool random_chance(long long, long long); 
// returning true by chance t/p 以t/p的概率返回true
long long hash_create(std::string);
// hash 从字符串生成哈希值
bool hash_check(long long, std::string);
// hash check

// MS-DOS OPERATIONS
void Wait(); 
// Waiting operation 用于等待操作的函数
bool askyn(); 
// yes or no 从键盘获取选择信息
double asknum(); 
// asking number 从键盘获取数字
std::string get_string();
// asking string 从键盘获取字符串
std::string secret_get_string();
// asking string but do not show on DOS 从键盘读取字符串，但不显示在DOS上

# endif // OPERATIONS_H_