#pragma once
/*
	类名称:DefineToPoland
	类功能:将正确的正规定义表达式转化为前缀(或后缀)表达式
*///
#include "CommonalityTree.h"
#include "TFactory.h"

class DefineToPoland
{
public:
	;
	;DefineToPoland(void)										//
	;DefineToPoland(TFactory* nodeF)								//根据给定的指针设定工厂
	;
public:
	;
	;~DefineToPoland(void)										//
	;
public:
	;
	;char* unPolandExp(char* define, int index)							//将中缀表达式转换成为逆波兰表达式(后缀表达式)
	;char* polandExp(char* define, int index)							//将中缀表达式转换成为波兰表达式(前缀表达式)
	;char* standardExp(char* define, int &index)							//将用户输入的正规式标准化(符合程序理解的表达式)
	;
	;
private:
	;
	;
	;int expIspForUnPoland(char operat)								//退栈优先级
	;int expIcpForUnPoland(char operat)								//进栈优先级
	;int expIspForPoland(char operat)								//退栈优先级
	;int expIcpForPoland(char operat)								//进栈优先级
	;char pop(void)											//退栈
	;char push(char operat)										//进栈
	;
	;
private:
	;
	;CommonalityTree* stack										//栈首指针
	;TFactory* nodeFactory										//工厂指针
	;
	;
};
