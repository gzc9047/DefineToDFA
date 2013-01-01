#include "StdAfx.h"
#include "PolandToTree.h"

;/*
	��������:
		PolandToTree

	��������:
		���캯��

	����:
		�޲�����ʼ��

	����:
		�޽���

	��������:
		���캯���޷���

	ע��:
		��
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
	��������:
		PolandToTree

	��������:
		���캯��

	����:
		nodeF(TFactory *):����ָ��

	����:
		�޽���

	��������:
		���캯���޷���

	ע��:
		��
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
	��������:
		~PolandToTree

	��������:
		��������

	����:
		��

	����:
		�޽���

	��������:
		���������޷���

	ע��:
		��
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
	��������:
		getDoubleNode

	��������:
		���ʽת���������õ��Ļ�ȡ˫�ڵ��㷨

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:˫�ڵ�ĸ��ڵ�

	ע��:
		��
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
	��������:
		expressionToTree

	��������:
		�����ʽ���ַ���ת��Ϊ��

	����:
		headNode(CommonalityTree *):��ڽڵ�

		tailNode(CommonalityTree *):���ڽڵ�

		expression(char *):��������ı��ʽ�ַ���

		index(int &):�ַ������±�

	����:
		�����ʽת��Ϊ���Ĺ���

	��������:
		CommonalityTree*:���ʽ���ĸ��ڵ�

	ע��:
		��
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
	��������:
		getRoot

	��������:
		��ñ��ʽ���ĸ��ڵ�

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:���ʽ���ĸ��ڵ�

	ע��:
		��
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
	��������:
		getRoot

	��������:
		�����Ч���ʽ�ڵ�ĸ���

	����:
		��

	����:
		�޽���

	��������:
		int:��Ч���ʽ�ڵ�ĸ���

	ע��:
		��
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
	��������:
		outTree

	��������:
		���Թ�����������ʽ

	����:
		expressionRoot(CommonalityTree *):(��ʱ)���ڵ�

	����:
		�޽���

	��������:
		int://�޽���

	ע��:
		��
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
	��������:
		expToNFA

	��������:
		�����ʽ���ַ���ת��ΪNFA,����ӿ�

	����:
		expression(char *):��������ı��ʽ�ַ���

		index(int &):�ַ������±�

	����:
		������

	��������:
		CommonalityTree*:���ʽ���ĸ��ڵ�

	ע��:
		��
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
	��������:
		getNodeList

	��������:
		��ýڵ��б�

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:�ڵ��б�ĸ��ڵ�

	ע��:
		��
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