#pragma once
#include "TFactory.h"
/*
	类名称:NFAToDFA
	类功能:将给定的NFA列表转化为DFA列表,并进行简化
*///

class NFAToDFA
{
public:
	;
	;NFAToDFA(void)
	;NFAToDFA(TFactory* nodeF)
	;
public:
	;~NFAToDFA(void)
	;
	;
public:
	;int** NFAListToDFAList(int line, int row, bool*** NFAList)						//生成DFA列表
	;int** predigestDFA(CommonalityTree* tempDFAList, int line, int row, CommonalityTree* tempNFAList)	//将DFA化简
	;
public:
	;
	;bool* closure(int line, int row, bool* target, bool*** NFAList)					//集合target对line求空串的闭包
	;bool* closureE(int line, int num, bool* target, bool*** NFAList)					//求集合对空串的闭包
	;
	;
private:
	;
	;int** DFAList												//最终生成的DFA列表
	;TFactory* nodeFactory											//工厂指针
	;
;};
