#pragma once
/*
	类名称:TreeToNFA
	类功能:将给定的NFA树转化为NFA转换列表
*///
#include "PolandToTree.h"

class TreeToNFA
{
public:
	;
	;TreeToNFA(void)
	;
public:
	;
	;~TreeToNFA(void)
	;
public:
	;
	;bool*** makeNFAList(PolandToTree* NFARoot, char* expression, int &conNum)				//生成NFA表,对外唯一接口
	;char* nodeCondition(PolandToTree* NFARoot, char* expression, int &count)				//储存转换条件
	;
private:
	;
	;int* TreeFieldWidth(PolandToTree* NFARoot, char* expression)						//计算NFA树代表的NFA列表的域宽度
	;int countCondition(char* expression)									//记录转换条件个数
	;
	;
private:
	;
	;char*** NFAList											//最终生成的NFA表
	;
;};
