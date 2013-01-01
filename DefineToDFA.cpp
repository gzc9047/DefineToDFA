/*
	copyright(c)2006	谷祖超
	工程名称:DefineToDFA
	程序功能:把给定的正规定义转化为DFA列表进行再匹配
	版本号:0.9
	注备:
		功能欠缺部分:
			1)超大量测试
		已经实现的功能:
			1)->用户输入的正规式
			2)->正确的正规式
			3)->波兰表达式(前缀表达式)
			4)->表达式树结构
			5)->NFA列表结构
			6)->DFA列表结构
			7)->匹配
*///

#include "stdafx.h"
#include "charWork.h"
#include "CommonalityTree.h"
#include "DefineToPoland.h"
#include "PolandToTree.h"
#include "TreeToNFA.h"
#include "NFAToDFA.h"

;int criterion_Define[7][6] = 
{
	{3, 4, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 5, 0, 0, 0, 0},
	{3, 4, 6, 1, 0, 1},
	{0, 5, 7, 3, 4, 0},
	{3, 4, 0, 1, 0, 1},
	{0, 5, 0, 3, 4, 0}
}
;int criterion_Math[7][7] =
{
	{3, 5, 4, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 7, 0, 0, 0, 0, 0},
	{3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 6, 6, 0, 1},
	{3, 5, 4, 0, 0, 0, 0},
	{0, 0, 0, 3, 3, 5, 0}
}


;int _tmain(int argc, _TCHAR* argv[])
{
	;//           ((((ga?)+l?)*(ga?)+)*((m(((ga?)+l?)*(ga?)+)*n)+l?)*(((ga?)+l?)*(ga?)+)*)*
	;//char* exp = "((((ga?)+l?)*(ga?)+)*((m(((ga?)+l?)*(ga?)+)*n)+a?l?)*(((ga?)+l?)*(ga?)+)*)*"//(((m(((ga?)+l?)*(ga?)+)*n)+l?)*(((ga?)+l?)*(ga?)+)*)* (((a?|b?)*(a?|b?)?)*)*
	;//((((ga?)+l?)*(ga?)+)*(m(((ga?)+l?)*(ga?)+)*n)+l?)*((((ga?)+l?)*(ga?)+)*)*
	;//char* exp = "(a|b)*-a-b"temp
	;char* exp = getString()
	;
	;int temp = 0
	;bool operate = false
	;while (!verdict(exp, criterion_Define, temp, false))
	{
		;temp = 0
		;delete exp
		;cout<<"You give me wrong expresstion !"<<endl
		;exp = getString()
	;}
	;int index = charLen(exp)
	;cout<<"You input expression is : "<<exp<<endl
	;TFactory* nodeFactory = new TFactory()
	;DefineToPoland* toPoland = new DefineToPoland(nodeFactory)
	;PolandToTree* NFATree = new PolandToTree(nodeFactory)
	;TreeToNFA* makeNFAList = new TreeToNFA()
	;NFAToDFA* makeDFAList = new NFAToDFA(nodeFactory)
	;CommonalityTree* NFARoot = NULL
	;bool*** NFAList = NULL
	;char* outUnPoland = toPoland->unPolandExp(exp, index)
	;cout<<"UnPoland is :"<<outUnPoland<<endl
	;char* outPoland = toPoland->polandExp(exp, index)
	;cout<<"Poland is :  "<<outPoland<<endl
	;int p = 0
	;NFARoot = NFATree->expToNFA(outPoland, p)
	;int conNum
	;NFAList = makeNFAList->makeNFAList(NFATree, outPoland, conNum)
	;int** DFAList = makeDFAList->NFAListToDFAList(NFATree->getPublicNum(), conNum, NFAList)
	;char* condition = makeNFAList->nodeCondition(NFATree, exp, conNum)
	;cout<<condition<<endl
	;temp = 0
	;while (true)
	{
		;cout<<"Input the string you want to match :"<<endl
		;
		;char* input = getString()
		;
		;int way = 1
		;int inputIndex = 0
		;int tempCha = 0
		;while (('\0' != input[inputIndex]) && (way != 0))//trans()
		{
			;tempCha = 0
			;while (tempCha < conNum)
			{
				;if (condition[tempCha] == input[inputIndex])//trans()
				{
					;++tempCha
					;break
				;}
				;++tempCha
			;}
			;way = DFAList[way - 1][tempCha - 1]
			;++inputIndex
		;}
		;
		;if ((0 != way) && (1 == DFAList[way - 1][conNum]))
		{
			;cout<<"Match !"<<endl
		;}else
		{
			;cout<<"Donn't match !"<<endl
		;}
		;/*
		;if (verdict(input, criterion, temp, operate))
		{
			;cout<<"Match !"<<endl
		;}else
		{
			;cout<<"Donn't match !"<<endl
		;}
		;*///
	;}
	;delete outUnPoland
	;delete outPoland
	;delete toPoland
	;delete NFATree
	;delete nodeFactory
	;cin.get()
	;return 0
;}

