#include "StdAfx.h"
#include "PolandToTree.h"

;/*
	函数名称:
		PolandToTree

	函数作用:
		构造函数

	参数:
		无参数初始化

	操作:
		无介绍

	返回类型:
		构造函数无返回

	注备:
		无
 *///
;PolandToTree::
PolandToTree//
(
 void
)
{
	;publicNum = 0
	;nodeFactory = NULL
	;nodeList = NULL
	;expressionRoot = NULL
;}

;/*
	函数名称:
		PolandToTree

	函数作用:
		构造函数

	参数:
		nodeF(TFactory *):工厂指针

	操作:
		无介绍

	返回类型:
		构造函数无返回

	注备:
		无
 *///
;PolandToTree::
PolandToTree//
(
 TFactory* nodeF
)
{
	;publicNum = 0
	;nodeFactory = nodeF
	;nodeList = nodeFactory->getOneCommonalityTree()
	;expressionRoot = nodeFactory->getOneCommonalityTree()
;}

;/*
	函数名称:
		~PolandToTree

	函数作用:
		析构函数

	参数:
		无

	操作:
		无介绍

	返回类型:
		析构函数无返回

	注备:
		无
 *///
;PolandToTree::
~PolandToTree//
(
 void
)
{
	;nodeFactory->callbackCommonalityTreeRoot(expressionRoot)
;}

;/*
	函数名称:
		getDoubleNode

	函数作用:
		表达式转换过程中用到的获取双节点算法

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:双节点的根节点

	注备:
		无
 *///
;CommonalityTree*
PolandToTree::
getDoubleNode//
(
 void
)
{
	;CommonalityTree* tempPoint = NULL
	;tempPoint = nodeFactory->getArrayCommonalityTree(2)
	;tempPoint->getParent()->setLeft(tempPoint)
	;return tempPoint->getParent()
;}

;/*
	函数名称:
		expressionToTree

	函数作用:
		将表达式的字符串转化为树

	参数:
		headNode(CommonalityTree *):入口节点

		tailNode(CommonalityTree *):出口节点

		expression(char *):经过处理的表达式字符串

		index(int &):字符数组下标

	操作:
		将表达式转换为树的过程

	返回类型:
		CommonalityTree*:表达式树的根节点

	注备:
		无
 *///
;CommonalityTree*
PolandToTree::
expressionToTree//
(
 CommonalityTree* headNode,
 CommonalityTree* tailNode,
 char* expression,
 int &index
)
{
	;/*
	;CommonalityTree* tempPoint = NULL
	;CommonalityTree* tempRoot = NULL
	;expressionRoot->setLeft(getDoubleNode())
	;//expressionRoot->setRight(getDoubleNode())
	;expressionRoot->getLeft()->setParent(expressionRoot)
	;//expressionRoot->getRight()->setParent(expressionRoot)
	;while ('\0' != expression[index])
	{
		;//expressionRoot->setLeft(getDoubleNode())
		;//expressionRoot->getLeft()->setParent(expressionRoot)
		;if ('(' == expression[index])
		{
			;++index
			;expressionRoot->getLeft()->setLeft(expressionToTree(expressionRoot->getLeft()->getLeft(), expression, index))
			;
			;
			;
			;return expressionRoot
		;}else if (')' == expression[index])
		{
			;tempRoot = expressionRoot->getParent()
			;if (0 == expressionRoot->getLeft()->getContent())
			{
				;nodeFactory->callbackCommonalityTreeNode(expressionRoot->getLeft())
				;expressionRoot->setLeft(NULL)
			;}else
			{
				;
				;expressionRoot->getParent()->setRight(expressionRoot->getLeft())
				;expressionRoot->getLeft()->setParent(expressionRoot->getParent())
				;nodeFactory->callbackCommonalityTreeNode(expressionRoot)
			;}
			;++index
			;return expressionRoot//tempRoot->getRight()
		;}else if ('|' == expression[index])
		{
			;++index
			;tempPoint = nodeFactory->getOneCommonalityTree()
			;tempRoot = nodeFactory->getOneCommonalityTree()
			;tempPoint->setLeft(expressionRoot->getLeft())
			;tempPoint->setParent(expressionRoot)
			;expressionRoot->getLeft()->setParent(tempPoint)
			;expressionRoot->setLeft(tempPoint)
			;tempPoint->setContent((int)'|')
			;tempPoint->setRight(tempRoot)
			;tempRoot->setParent(tempPoint)
			;tempPoint->setRight(expressionToTree(tempRoot, expression, index))
			;return expressionRoot
			;
		;}else if ('*' == expression[index])
		{
			;tempPoint = expressionRoot->getLeft()
			;tempPoint->setContent((int)'*')
			;tempPoint->getLeft()->setLeft(tempPoint->getLeft())
			;tempRoot = tempPoint
			;while (NULL == tempRoot->getParent()->getRight())
			{
				;tempRoot = tempRoot->getParent()
			;}
			;tempPoint->getLeft()->setRight(tempRoot->getParent()->getRight())
		;}else if ('+' == expression[index])
		{
			;if (0 == expressionRoot->getLeft()->getContent())
			{
				;expressionRoot->getLeft()->setContent((int)'+')
			;}else
			{
				;
			;}
			;tempPoint = expressionRoot->getLeft()
			;tempPoint->setContent((int)'+')
			;tempPoint->getLeft()->setLeft(tempPoint->getLeft())
			;tempRoot = tempPoint
			;while (NULL == tempRoot->getParent()->getRight())
			{
				;tempRoot = tempRoot->getParent()
			;}
			;tempPoint->getLeft()->setRight(tempRoot->getParent()->getRight())
			;tempRoot->getParent()->setRight(NULL)
		;}else
		{
			;++publicNum
			;if (0 == expressionRoot->getLeft()->getContent())
			{
				;tempPoint = expressionRoot->getLeft()->getLeft()
				;tempPoint->setPublicID(publicNum)
				;tempPoint->setContent((int)expression[index])
				;/*if (')' == expression[index+1])
				{
					;nodeFactory->callbackCommonalityTreeRoot(expressionRoot->getRight())
					;++index
					;++index
					;return expressionRoot
				;}
				;if ('*' == expression[index+1])
				{
					;++index
					;tempRoot = tempPoint->getParent()
					;tempRoot->setPublicID(publicNum)
					;tempRoot->setContent((int)'*')
					;while (tempRoot == tempRoot->getParent()->getRight())
					{
						;tempRoot = tempRoot->getParent()
					;}
					;tempPoint->setLeft(tempPoint)
					;tempPoint->setRight(tempRoot->getParent()->getRight())
				;}else if ('+' == expression[index+1])
				{
					;++index
					;tempRoot = tempPoint->getParent()
					;tempRoot->setPublicID(publicNum)
					;tempRoot->setContent((int)'+')
					;while (tempRoot == tempRoot->getParent()->getRight())
					{
						;tempRoot = tempRoot->getParent()
					;}
					;tempPoint->setLeft(tempPoint)
					;tempPoint->setRight(tempRoot->getParent()->getRight())
					;tempRoot->getParent()->setRight(NULL)
				;}* ///
			;}else
			{
				;++index
				;if (0 == expressionRoot->getLeft()->getPublicID())//getContent()
				{
					;expressionRoot->setLeft(expressionRoot->getLeft()->getLeft())
					;nodeFactory->callbackCommonalityTreeNode(expressionRoot->getLeft()->getParent())
					;expressionRoot->getLeft()->setParent(expressionRoot)
				;}
				;expressionRoot->setContent((int)'-')
				;expressionRoot->setRight(nodeFactory->getOneCommonalityTree())
				;expressionRoot->getRight()->setParent(expressionRoot)
				;expressionRoot->setRight(expressionToTree(expressionRoot->getRight(), expression, index))
				;return expressionRoot
				;/*if ('\0' == expression[index+1] || ')' == expression[index+1])
				{
					;expressionRoot->setRight(getDoubleNode())
					;expressionRoot->getRight()->setParent(expressionRoot)
					;tempPoint = expressionRoot->getRight()->getLeft()
					;tempPoint->setPublicID(publicNum)
					;tempPoint->setContent((int)expression[index])
					;++index
					;++index
					;tempRoot = expressionRoot
					;while (tempRoot == tempRoot->getParent()->getRight())
					{
						;tempRoot = tempRoot->getParent()
					;}
					;tempPoint->setRight(tempRoot->getParent()->getRight())
					;return expressionRoot
				;}else
				{
					;++index
					;expressionRoot->setRight(nodeFactory->getOneCommonalityTree())
					;tempRoot = expressionRoot->getRight()
					;expressionRoot->setRight(expressionToTree(expressionRoot->getLeft()->getLeft(), expression, index))
					;return expressionRoot
				;}* ///
			;}
		;}
		;++index
	;}
	;tempRoot = expressionRoot->getParent()
	;if (0 == expressionRoot->getLeft()->getPublicID())
	{
		;expressionRoot->getParent()->setRight(expressionRoot->getLeft()->getLeft())
		;expressionRoot->getLeft()->getLeft()->setParent(expressionRoot->getParent())
		;nodeFactory->callbackCommonalityTreeNode(expressionRoot)
	;}else
	{
		;expressionRoot->getParent()->setRight(expressionRoot->getLeft())
		;expressionRoot->getLeft()->setParent(expressionRoot->getParent())
		;nodeFactory->callbackCommonalityTreeNode(expressionRoot)
	;}
	;while (NULL != tempRoot->getParent())
	{
		;tempRoot = tempRoot->getParent()
	;}
	;tempPoint->setRight(tempRoot->getRight())
	;return tempRoot->getRight()
	;*///
	;//CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()
	;//beginNode->setPublicID(publicNum)
	;CommonalityTree* endNode = tailNode
	;CommonalityTree* tempNode = NULL
	;CommonalityTree* temp = NULL
	;int i = 0
	;int j = 0
	;switch (expression[index])
	{
		;case '-':
		{
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()//
			;nodeList->setParent(beginNode)
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(endNode)
			;if (endNode == headNode->getRight())
			{
				;headNode->setRight(beginNode)
			;}else
			{
				;headNode->setLeft(beginNode)
			;}
			;++index
			;expressionToTree(headNode, beginNode, expression, index)
			;++index
			;expressionToTree(beginNode, endNode, expression, index)
			;break
		;}
		;case '+'://
		{
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()//
			;nodeList->setParent(beginNode)
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(nodeFactory->getOneCommonalityTree())//
			;nodeList->setParent(beginNode->getRight())
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->getRight()->setPublicID(publicNum)
			;beginNode->getRight()->setRight(endNode)
			;if (endNode == headNode->getRight())
			{
				;headNode->setRight(beginNode)
			;}else
			{
				;headNode->setLeft(beginNode)
			;}
			;++index
			;tempNode = expressionToTree(beginNode, beginNode->getRight(), expression, index)
			;/*tempNode->setLeft(beginNode->getRight())
			;if (beginNode->getRight() != tempNode)
			{
				;while (i < publicNum/2)
				{
					;temp = tempNode->getLeft()->getLeft()
					;if (NULL != temp)
					{
						;if (temp == temp->getLeft())
						{
							;return endNode
						;}
						;for (j = 0; j < i; ++j)
						{
							;if (0 == temp->getContent())
							{
								;temp = temp->getRight()
							;}else
							{
								;return endNode
							;}
						;}
					;}else
					{
						;return endNode
					;}
					;if (temp == tempNode)
					{
						;tempNode->setLeft(tempNode->getLeft()->getRight())
					;}
					;++i
				;}
			;}
			;
			;while (tempNode->getLeft()->getLeft() == tempNode
			&& beginNode->getRight() != tempNode)
			{
				;tempNode->setLeft(tempNode->getLeft()->getRight())
			;}
			;*///
			;break
		;}
		;case '*'://
		{
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()//
			;nodeList->setParent(beginNode)
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(nodeFactory->getOneCommonalityTree())//
			;nodeList->setParent(beginNode->getRight())
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->getRight()->setPublicID(publicNum)
			;beginNode->getRight()->setRight(endNode)
			;if (endNode == headNode->getRight())
			{
				;headNode->setRight(beginNode)
			;}else
			{
				;headNode->setLeft(beginNode)
			;}
			;++index
			;tempNode = expressionToTree(beginNode, beginNode->getRight(), expression, index)
			;tempNode->setLeft(beginNode->getRight())
			;//tempLeft = tempNode->getLeft()
			;//temp = tempNode->getLeft()->getLeft()
			;beginNode->setLeft(endNode)
			;/*if (beginNode->getRight() != tempNode)
			{
				;while (i < publicNum/2)
				{
					;temp = tempNode->getLeft()->getLeft()
					;if (NULL != temp)
					{
						;if (temp == temp->getLeft())
						{
							;return endNode
						;}
						;for (j = 0; j < i; ++j)
						{
							;if (0 == temp->getContent())
							{
								;temp = temp->getRight()
							;}else
							{
								;return endNode
							;}
						;}
					;}else
					{
						;return endNode
					;}
					;if (temp == tempNode)
					{
						;tempNode->setLeft(tempNode->getLeft()->getRight())
					;}
					;++i
				;}
			;}
			;
			;
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(endNode)
			;headNode->setRight(beginNode)
			;++index
			;headNode->setLeft(expressionToTree(headNode, beginNode, expression, index)->getRight())
			;headNode->getLeft()->setLeft(beginNode)
			;*///
			;break
		;}
		;case '?':
		{
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()//
			;nodeList->setParent(beginNode)
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(nodeFactory->getOneCommonalityTree())//
			;
			;nodeList->setParent(beginNode->getRight())
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->getRight()->setPublicID(publicNum)
			;beginNode->getRight()->setRight(endNode)
			;if (endNode == headNode->getRight())
			{
				;headNode->setRight(beginNode)
			;}else
			{
				;headNode->setLeft(beginNode)
			;}
			;++index
			;expressionToTree(beginNode, beginNode->getRight(), expression, index)
			;beginNode->setLeft(endNode)
			;/*
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;beginNode->setRight(endNode)
			;headNode->setRight(beginNode)
			;++index
			;headNode->setLeft(expressionToTree(headNode, beginNode, expression, index)->getRight())
			;*///
			;break
		;}
		;case '|':
		{
			;CommonalityTree* beginNode = nodeFactory->getOneCommonalityTree()//
			;nodeList->setParent(beginNode)
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->setPublicID(publicNum)
			;if (endNode == headNode->getRight())
			{
				;headNode->setRight(beginNode)
			;}else
			{
				;headNode->setLeft(beginNode)
			;}
			;beginNode->setRight(nodeFactory->getOneCommonalityTree())//
			;nodeList->setParent(beginNode->getRight())
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->getRight()->setPublicID(publicNum)
			;beginNode->getRight()->setRight(endNode)
			;
			;beginNode->setLeft(nodeFactory->getOneCommonalityTree())
			;nodeList->setParent(beginNode->getLeft())
			;nodeList->setRight(nodeFactory->getOneCommonalityTree())
			;nodeList->getRight()->setLeft(nodeList)
			;nodeList = nodeList->getRight()
			;
			;++publicNum
			;beginNode->getLeft()->setPublicID(publicNum)
			;beginNode->getLeft()->setLeft(endNode)
			;++index
			;expressionToTree(beginNode, beginNode->getRight(), expression, index)
			;++index
			;expressionToTree(beginNode, beginNode->getLeft(), expression, index)
			;break
		;}
		;case '\0':
		{
			;break
		;}
		;//case '':
		;//case '':
		;//case '':
		;default:
		{
			;endNode->setContent((char)expression[index])
			;break
		;}
	;}
	;return endNode
;}

;/*
	函数名称:
		getRoot

	函数作用:
		获得表达式树的根节点

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:表达式树的根节点

	注备:
		无
 *///
;CommonalityTree*
PolandToTree::
getRoot//
(
 void
)
{
	;return expressionRoot
;}

;/*
	函数名称:
		getRoot

	函数作用:
		获得有效表达式节点的个数

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:有效表达式节点的个数

	注备:
		无
 *///
;int
PolandToTree::
getPublicNum//
(
 void
)
{
	;return publicNum
;}

;/*
	函数名称:
		outTree

	函数作用:
		调试过程中输出表达式

	参数:
		expressionRoot(CommonalityTree *):(临时)根节点

	操作:
		无介绍

	返回类型:
		int://无介绍

	注备:
		无
 *///
;int
PolandToTree::
outTree//
(
 CommonalityTree* expressionRoot
)
{
	;
	;
	;
	;
	;
	;
	;
	;
	;return 0
;}

;/*
	函数名称:
		expToNFA

	函数作用:
		将表达式的字符串转化为NFA,对外接口

	参数:
		expression(char *):经过处理的表达式字符串

		index(int &):字符数组下标

	操作:
		对外借口

	返回类型:
		CommonalityTree*:表达式树的根节点

	注备:
		无
 *///
;CommonalityTree*
PolandToTree::
expToNFA//
(
 char* expression,
 int &index
)
{
	;
	;CommonalityTree* tailNode = nodeFactory->getOneCommonalityTree()//
	;nodeList->setParent(tailNode)
	;nodeList->setRight(nodeFactory->getOneCommonalityTree())
	;nodeList->getRight()->setLeft(nodeList)
	;nodeList = nodeList->getRight()
	;
	;CommonalityTree* headNode = nodeFactory->getOneCommonalityTree()//
	;nodeList->setParent(headNode)
	;nodeList->setRight(nodeFactory->getOneCommonalityTree())
	;nodeList->getRight()->setLeft(nodeList)
	;nodeList = nodeList->getRight()
	;
	;CommonalityTree* temp = nodeFactory->getOneCommonalityTree()//
	;nodeList->setParent(temp)
	;nodeList->setRight(nodeFactory->getOneCommonalityTree())
	;nodeList->getRight()->setLeft(nodeList)
	;nodeList = nodeList->getRight()
	;
	;headNode->setContent(0)
	;headNode->setPublicID(-1)
	;tailNode->setContent(-1)
	;tailNode->setPublicID(-1)
	;++publicNum
	;temp->setPublicID(publicNum)
	;headNode->setRight(temp)
	;temp->setRight(tailNode)
	;expressionToTree(headNode, temp, expression, index)
	;return headNode
;}

;/*
	函数名称:
		getNodeList

	函数作用:
		获得节点列表

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:节点列表的根节点

	注备:
		无
 *///
;CommonalityTree*
PolandToTree::
getNodeList//
(
 void
)
{
	;return nodeList
;}