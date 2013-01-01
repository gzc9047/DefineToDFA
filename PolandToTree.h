#pragma once
/*
	类名称:PolandToTree
	类功能:将给定的前缀(或后缀)表达式转化为NFA树结构
*///
#include "CommonalityTree.h"
#include "TFactory.h"


class PolandToTree
{
public:
	;
	;PolandToTree(void)
	;PolandToTree(TFactory* nodeF)
	;
public:
	;
	;~PolandToTree(void)
	;
	;
public:
	;
	;CommonalityTree* expressionToTree(CommonalityTree* headNode, CommonalityTree* tailNode, char* expression, int &index)			//将表达式的字符串转化为树
	;CommonalityTree* expToNFA(char* expression, int &index)										//将表达式的字符串转化为NFA,对外接口
	;
	;
	;CommonalityTree* getDoubleNode(void)													//表达式转换过程中用到的双节点算法
	;int outTree(CommonalityTree* expressionRoot)												//调试过程中输出表达式
	;
public:
	;
	;CommonalityTree* getRoot(void)														//获得表达式树的根节点
	;CommonalityTree* getNodeList(void)													//获得节点列表
	;int getPublicNum(void)															//获得有效节点个数
	;
	;
private:
	;
	;CommonalityTree* expressionRoot													//表达式树的根节点指针
	;TFactory* nodeFactory															//工厂指针
	;int publicNum																//有效表达式节点的个数
	;CommonalityTree* nodeList														//节点列表
	;
;};
