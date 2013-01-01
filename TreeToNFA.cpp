#include "StdAfx.h"
#include "TreeToNFA.h"
#include "CommonalityTree.h"

;/*
	��������:
		TreeToNFA

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
;TreeToNFA::
TreeToNFA//
(
 void
)
{
	;NFAList = NULL
;}

;/*
	��������:
		~TreeToNFA

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
;TreeToNFA::
~TreeToNFA//
(
 void
)
{
	;delete []NFAList
;}

;/*
	��������:
		TreeDimen

	��������:
		����NFA�������NFA�б������

	����:
		NFARoot(PolandToTree *):NFA��ָ��

		expression(char *):���ʽ�ַ���ָ��

	����:
		�޽���

	��������:
		��������ָ��

	ע��:
		��
 *///
;int*
TreeToNFA::
TreeFieldWidth//
(
 PolandToTree* NFARoot,
 char* expression
)
{
	;int index = 0
	;int i = 0
	;int* widthArray
	;widthArray = new int[2]
	;widthArray[0] = NFARoot->getPublicNum()+2
	;widthArray[1] = 0
	;while ('\0' != expression[index])
	{
		;if ((int)expression[index] <= (int)'z'
		&& (int)expression[index] >= (int)'a')
		{
			;for (i = 0; i < index; ++i)
			{
				;if (expression[index] == expression[i])
				{
					;break
				;}
			;}
			;if (i == index)
			{
				;++widthArray[1]
			;}
			;
		;}
		;++index
	;}
	;return widthArray
;}

;/*
	��������:
		countCondition

	��������:
		��¼ת����������

	����:
		expression(char *):���ʽ�ַ���ָ��

	����:
		�޽���

	��������:
		��������ָ��

	ע��:
		��
 *///
;int
TreeToNFA::
countCondition//
(
 char* expression
)									//��¼ת����������
{
	;int i = 0
	;int index = 0
	;int count = 0
	;while ('\0' != expression[index])
	{
		;if (((int)expression[index] <= (int)'z' && (int)expression[index] >= (int)'a')
		|| ((int)expression[index] <= (int)'9' && (int)expression[index] >= (int)'0')
		|| ((int)expression[index] <= (int)'Z' && (int)expression[index] >= (int)'A'))
		{
			;for (i = 0; i < index; ++i)
			{
				;if (expression[index] == expression[i])
				{
					;break
				;}
			;}
			;if (i == index)
			{
				;++count
			;}
			;
		;}
		;++index
	;}
	;return count
;}

;/*
	��������:
		nodeCondition

	��������:
		����ת������

	����:
		NFARoot(PolandToTree *):NFA��ָ��

		expression(char *):���ʽ�ַ���ָ��

		i(int &):����ת�������ĸ���

	����:
		�޽���

	��������:
		����ת���������ַ���ָ��

	ע��:
		��
 *///
;char*
TreeToNFA::
nodeCondition//
(
 PolandToTree* NFARoot,
 char* expression,
 int &count
)
{
	;int i = 0
	;int index = 0
	;count = 0
	;char* temp = new char[NFARoot->getPublicNum()]
	;while ('\0' != expression[index])
	{
		;if (((int)expression[index] <= (int)'z' && (int)expression[index] >= (int)'a')
		|| ((int)expression[index] <= (int)'9' && (int)expression[index] >= (int)'0')
		|| ((int)expression[index] <= (int)'Z' && (int)expression[index] >= (int)'A'))
		{
			;for (i = 0; i < index; ++i)
			{
				;if (expression[index] == expression[i])
				{
					;break
				;}
			;}
			;if (i == index)
			{
				;temp[count] = expression[index]//
				;++count
			;}
		;}
		;++index
	;}
	;//temp[count+1] = char(0)
	;temp[count] = '\0'
	;return temp
;}

;/*
	��������:
		nodeCondition

	��������:
		����ת������

	����:
		NFARoot(PolandToTree *):NFA��ָ��

		expression(char *):���ʽ�ַ���ָ��

		conNum(int &):������¼ת��״̬��Ŀ

	����:
		�޽���

	��������:
		����ת���������ַ���ָ��

	ע��:
		��
 *///
;bool***
TreeToNFA::
makeNFAList
(
 PolandToTree* NFARoot,
 char* expression,
 int &conNum
)
{
	;int i = NFARoot->getPublicNum()+2
	;CommonalityTree* nodeList = NFARoot->getNodeList()
	;CommonalityTree** nodeListArray = new CommonalityTree*[i]
	;int tempIndex = i
	;while (tempIndex > 0)
	{
		;nodeListArray[tempIndex - 1] = nodeList->getLeft()->getParent()
		;nodeList = nodeList->getLeft()
		;--tempIndex
	;}
	;conNum = 0
	;char* condition = nodeCondition(NFARoot, expression, conNum)
	;++conNum
	;bool*** NFAList = new bool**[i]
	;for (int m = 0; m < i; ++m)
	{
		;NFAList[m] = new bool*[conNum]
		;for (int n = 0; n < conNum ; ++n)
		{
			;NFAList[m][n] = NULL
		;}
	;}
	;for (int m = 0; m < i ; ++m)
	{
		;for (int n = conNum - 1; n >= 0; --n)
		{
			;/*
			;if ('\0' == condition[n])
			{
				;cout<<(int)'\0'<<endl
			;}
			;
			;cout<<(int)condition[n]<<endl*///
			;if (nodeListArray[m]->getContent() == (int)condition[n])
			{
				;NFAList[m][conNum - n - 1] = new bool[i]
				;for (int p = 0; p < i; ++p)
				{
					;NFAList[m][conNum - n - 1][p] = false
				;}
				;if (NULL != nodeListArray[m]->getLeft())
				{
					;NFAList[m][conNum - n - 1][nodeListArray[m]->getLeft()->getPublicID()+1] = true
					;//cout<<nodeListArray[m]->getLeft()->getPublicID()+2<<'-'
				;}
				;if (NULL != nodeListArray[m]->getRight())
				{
					;NFAList[m][conNum - n - 1][nodeListArray[m]->getRight()->getPublicID()+1] = true
					;//cout<<nodeListArray[m]->getRight()->getPublicID()+2<<'-'
				;}
			;}/*else
			{
				;NFAList[m][n] = NULL
			;}*///
			;//cout<<endl
		;}
	;}
	;/*
	;cout<<endl
	;for (int m = 0; m < i ; ++m)
	{
		;for (int n = 0; n < conNum; ++n)
		{
			;if (NULL != NFAList[m][n])
			{
				;for (int j = 0; j < i ; ++j)
				{
					;cout<<NFAList[m][n][j]
				;}
			;}
			;cout<<'+'
		;}
		;cout<<'='<<endl
	;}
	;*///
	;return NFAList
;}