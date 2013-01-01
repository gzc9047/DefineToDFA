#include "StdAfx.h"
#include "NFAToDFA.h"
#include "arrayWork.h"
#include "CommonalityTree.h"

;/*
	��������:
		NFAToDFA

	��������:
		�޲������캯��

	����:
		��

	����:
		�޽���

	��������:
		���캯���޷���

	ע��:
		��
 *///
;NFAToDFA::
NFAToDFA//
(
 void
)
{
	;
;}

;/*
	��������:
		NFAToDFA

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
;NFAToDFA::
NFAToDFA//
(
 TFactory* nodeF
)
{
	;nodeFactory = nodeF
;}

;/*
	��������:
		~NFAToDFA

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
;NFAToDFA::
~NFAToDFA//
(
 void
)
{
	;
;}

;/*
	��������:
		closure

	��������:
		����target��line��մ��ıհ�

	����:
		line(int):��Ӧ��

		row(int):NFAList����

		target(bool **):Ŀ�꼯��

		NFAList(bool ***):NFAList

	����:
		�޽���

	��������:
		bool*:bool��������ָ��

	ע��:
		��
 *///
;bool*
NFAToDFA::
closure
(
 int line,
 int row,
 bool* target,
 bool*** NFAList
)
{
	;bool* list = new bool[line]
	;for (int i = 0; i < line; ++i)
	{
		;list[i] = false
	;}
	;for (int i = 0; i < line; ++i)
	{
		;if (target[i])
		{
			;if (NULL != NFAList[i][row])
			{
				;for (int j = 0; j < line; ++j)
				{
					;if (NFAList[i][row][j])
					{
						;list[j] = true
						;closureE(j, line, list, NFAList)
					;}
				;}
			;}
		;}
	;}
	;/*
	;for (int i = 0; i < line; ++i)
	{
		;cout<<list[i]
	;}
	;cout<<endl
	;*///
	;return list
;}

;/*
	��������:
		closureE

	��������:
		�󼯺϶Կմ��ıհ�

	����:
		line(int):Ŀ����±�

		num(int):NFAList����

		target(bool *):Ŀ�꼯��

		NFAList(bool ***):NFAList

	����:
		�޽���

	��������:
		bool*:bool��������ָ��

	ע��:
		��
 *///
;bool*
NFAToDFA::
closureE//
(
 int line,
 int num,
 bool* target,
 bool*** NFAList
)
{
	;int index = 0
	;if (NULL != NFAList[line][0])
	{
		;for (int j = 0; j < num; ++j)
		{
			;if (NFAList[line][0][j])
			{
				;if (!target[j])
				{
					;target[j] = true
					;closureE(j, num, target, NFAList)
				;}
			;}
		;}
	;}
	;return target
;}

;/*
	��������:
		NFAListToDFAList

	��������:
		����DFA�б�

	����:
		line(int):NFAList����

		row(int):����

		NFAList(bool ***):NFAList

	����:
		�޽���

	��������:
		int**:DFA�б�

	ע��:
		��
 *///
;int**
NFAToDFA::
NFAListToDFAList//
(
 int line,
 int row,
 bool*** NFAList
)
{
	;bool* tempList = NULL
	;bool temp = true
	;CommonalityTree* tempNFAList = nodeFactory->getOneCommonalityTree()
	;CommonalityTree* tempDFAList = nodeFactory->getOneCommonalityTree()
	;CommonalityTree* tempPBool = tempNFAList
	;CommonalityTree* tempPInt = tempDFAList
	;CommonalityTree* tempUse = NULL
	;tempNFAList->setNFAList(new bool[line + 2])
	;
	;for (int i = 0; i < line + 2; ++i)
	{
		;tempNFAList->getNFAList()[i] = false
	;}
	;
	;closureE(1, line + 2, tempNFAList->getNFAList(), NFAList)
	;tempUse = tempNFAList
	;/*
	;for (int i = 0; i < line + 2; ++i)
	{
		;cout<<tempNFAList->getNFAList()[i]
	;}
	;cout<<endl
	;
	;for (int i = 0; i < line + 2; ++i)
	{
		;cout<<tempBoolList[0][i]
	;}
	;cout<<endl
	;* ///
	;/ *
	;for (int i = 0; i < line + 2; ++i)
	{
		;tempDFAList[i] = NULL
	;}
	;*///
	;tempDFAList->setDFAList(new int[row - 1])
	;for (int i = 0; i < row - 1; ++i)
	{
		;tempDFAList->getDFAList()[i] = -1
	;}
	;int index = 1
	;int wrongIndex = 0
	;int tempNum = 0
	;int tempChange = 0
	;while (tempNum < index)
	{
		;for (int j = 1; j < row; ++j)
		{
			;tempUse = tempNFAList
			;for (int i = 0; i < tempNum; ++i)
			{
				;tempUse = tempUse->getParent()
			;}
			;tempList = closure(line + 2, j, tempUse->getNFAList(), NFAList)
			;tempUse = tempNFAList
			;for (wrongIndex = 0; wrongIndex < index; ++wrongIndex)
			{
				;if (equal(tempList, tempUse->getNFAList(), line + 2))
				{
					;temp = false
					;break
				;}
				;
				;tempUse = tempUse->getParent()
			;}
			;if (temp)
			{
				;tempPBool = tempNFAList
				;tempPInt = tempDFAList
				;for (int m = 0; m < index - 1; ++m)
				{
					;tempPBool = tempPBool->getParent()
					;tempPInt = tempPInt->getParent()
				;}
				;tempPBool->setParent(nodeFactory->getOneCommonalityTree())
				;tempPBool = tempPBool->getParent()
				;tempPBool->setNFAList(tempList)
				;tempPInt->setParent(nodeFactory->getOneCommonalityTree())
				;tempPInt = tempPInt->getParent()
				;tempPInt->setDFAList(new int[row - 1])
				;for (int i = 0; i < row - 1; ++i)
				{
					;tempPInt->getDFAList()[i] = -1
				;}
				;tempUse = tempDFAList
				;for (int i = 0; i < tempChange; ++i)
				{
					;tempUse = tempUse->getParent()
				;}
				;tempUse->getDFAList()[row - j - 1] = index + 1
				;++index
			;}else
			{
				;delete []tempList
				;tempUse = tempDFAList
				;for (int i = 0; i < tempChange; ++i)
				{
					;tempUse = tempUse->getParent()
				;}
				;tempUse->getDFAList()[row - j - 1] = wrongIndex + 1
			;}
			;temp = true
		;}
		;++tempChange
		;++tempNum
	;}
	;/*
	;for (int i = 0; i < tempChange; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<tempDFAList[i][j]
		;}
		;cout<<endl
	;}* ///
	;for (int i = 0; i < tempChange; ++i)
	{
		;for (int j = 0; j < line + 2; ++j)
		{
			;cout<<tempBoolList[i][j]
		;}
		;cout<<endl
	;}
	;
	;
	;for (int i = 0; i < tempChange; ++i)//DFA�򻯹���,������������
	{
		;if (tempBoolList[i][0])
		{
			;for (int j = i + 1; j < tempChange; ++j)
			{
				;if (tempBoolList[j][0])
				{
					;int m = 0
					;for (m = 0; m < row - 1; ++m)
					{
						;if (tempDFAList[i][m] != tempDFAList[j][m])
						{
							;break
						;}
					;}
					;if ((row - 1) == m)
					{
						;for (int p = 0; p < tempChange; ++p)
						{
							;for (int q = 0; q < row - 1; ++q)
							{
								;if ((j + 1) == tempDFAList[p][q])
								{
									;tempDFAList[p][q] = (i + 1)
								;}
							;}
						;}
						;for (int n = 0; n < row - 1; ++n)
						{
							;tempDFAList[j][n] = 0
						;}
						;--tempNum
					;}
				;}
			;}
		;}else
		{
			;for (int j = i + 1; j < tempChange; ++j)
			{
				;if (!tempBoolList[j][0])
				{
					;int m = 0
					;for (m = 0; m < row - 1; ++m)
					{
						;if (tempDFAList[i][m] != tempDFAList[j][m])
						{
							;break
						;}
					;}
					;if ((row - 1) == m)
					{
						;for (int p = 0; p < tempChange; ++p)
						{
							;for (int q = 0; q < row - 1; ++q)
							{
								;if ((j + 1) == tempDFAList[p][q])
								{
									;tempDFAList[p][q] = (i + 1)
								;}
							;}
						;}
						;for (int n = 0; n < row - 1; ++n)
						{
							;tempDFAList[j][n] = 0
						;}
						;--tempNum
					;}
				;}
			;}
		;}
	;}
	;int* spaceLine = new int[tempChange]
	;spaceLine[0] = 0
	;
	;for (int i = 1; i < tempChange; ++i)
	{
		;if (0 == tempDFAList[i][0])
		{
			;spaceLine[i] = spaceLine[i - 1] + 1
		;}else
		{
			;spaceLine[i] = spaceLine[i - 1]
		;}
	;}
	;/ *
	;for (int i = 0; i < tempChange; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<tempDFAList[i][j]
		;}
		;cout<<endl
	;}
	;* ///
	;int tempLen = 0
	;int** finalDFA = new int*[tempNum]
	;
	;for (int i = 0; i < tempNum; ++i)
	{
		;finalDFA[i] = new int[row]
		;for (int j = 0; j < row; ++j)
		{
			;finalDFA[i][j] = 0
		;}
	;}
	;/ *
	;for (int i = 0; i < tempNum; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<finalDFA[i][j]
		;}
		;cout<<endl
	;}
	;* ///
	;for (int i = 0; i < tempChange; ++i)
	{
		;if (0 != tempDFAList[i][0])
		{
			;for (int j = 0; j < row - 1; ++j)
			{
				;finalDFA[tempLen][j] = tempDFAList[i][j] - spaceLine[tempDFAList[i][j] - 1]
			;}
			;if (tempBoolList[i][0])
			{
				;finalDFA[tempLen][row - 1] = 1
			;}
			;++tempLen
		;}
	;}
	;
	;for (int i = 0; i < tempNum; ++i)
	{
		;for (int j = 0; j < row; ++j)
		{
			;cout<<finalDFA[i][j]
		;}
		;cout<<endl
	;}
	;/ * * ///
	;
	;tempUse = tempNFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;for (int j = 0; j < line + 2; ++j)
		{
			;cout<<tempUse->getNFAList()[j]
		;}
		;cout<<endl
		;tempUse = tempUse->getParent()
	;}
	;*/
	;int** finalDFA = predigestDFA(tempDFAList, tempChange, row, tempNFAList)
	;delete []tempList
	;tempPBool = tempNFAList
	;tempPInt = tempDFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;delete []tempPBool->getDFAList()
		;delete []tempPInt->getNFAList()
		;tempPBool = tempPBool->getParent()
		;tempPInt = tempPInt->getParent()
	;}
	;nodeFactory->callbackCommonalityTreeRoot(tempDFAList)
	;nodeFactory->callbackCommonalityTreeRoot(tempNFAList)
	;return finalDFA
;}

;/*
	��������:
		predigestDFA

	��������:
		��DFA�б�

	����:
		tempDFAList(CommonalityTree *):���ɵ���ʱDFA

		line(int):NFAList����

		row(int):����

		tempBoolList(CommonalityTree *):���ɵ���ʱbool�ṹ��

	����:
		�޽���

	��������:
		int**:DFA�б�

	ע��:
		��
 *///
;int**
NFAToDFA::
predigestDFA//
(
 CommonalityTree* tempDFAList,
 int line,
 int row,
 CommonalityTree* tempNFAList
)
{
	;int tempNum = line
	;int tempChange = line
	;CommonalityTree* tempPBool = tempNFAList
	;CommonalityTree* tempPInt = tempDFAList
	;CommonalityTree* tempUse = tempNFAList
	;CommonalityTree* tempUse2 = tempNFAList
	;CommonalityTree* tempUse3 = tempDFAList
	;CommonalityTree* tempUse4 = tempDFAList
	;CommonalityTree* tempUse5 = tempDFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;if (tempUse->getNFAList()[0])
		{
			;tempUse2 = tempUse->getParent()
			;tempUse4 = tempUse3->getParent()
			;for (int j = i + 1; j < tempChange; ++j)
			{
				;
				;if (tempUse2->getNFAList()[0])
				{
					;int m = 0
					;for (m = 0; m < row - 1; ++m)
					{
						;
						;if (tempUse3->getDFAList()[m] != tempUse4->getDFAList()[m])
						{
							;break
						;}
					;}
					;if ((row - 1) == m)
					{
						;tempUse5 = tempDFAList
						;for (int p = 0; p < tempChange; ++p)
						{
							;for (int q = 0; q < row - 1; ++q)
							{
								;if ((j + 1) == tempUse5->getDFAList()[q])
								{
									;tempUse5->getDFAList()[q] = (i + 1)
								;}
							;}
							;tempUse5 = tempUse5->getParent()
						;}
						;for (int n = 0; n < row - 1; ++n)
						{
							;tempUse4->getDFAList()[n] = 0
						;}
					;}
				;}
				;tempUse2 = tempUse2->getParent()
				;tempUse4 = tempUse4->getParent()
			;}
		;}else
		{
			;tempUse2 = tempUse->getParent()
			;tempUse4 = tempUse3->getParent()
			;for (int j = i + 1; j < tempChange; ++j)
			{
				;if (!tempUse2->getNFAList()[0])
				{
					;int m = 0
					;for (m = 0; m < row - 1; ++m)
					{
						;if (tempUse3->getDFAList()[m] != tempUse4->getDFAList()[m])
						{
							;break
						;}
					;}
					;if ((row - 1) == m)
					{
						;tempUse5 = tempDFAList
						;for (int p = 0; p < tempChange; ++p)
						{
							;for (int q = 0; q < row - 1; ++q)
							{
								;if ((j + 1) == tempUse5->getDFAList()[q])
								{
									;tempUse5->getDFAList()[q] = (i + 1)
								;}
							;}
							;tempUse5 = tempUse5->getParent()
						;}
						;for (int n = 0; n < row - 1; ++n)
						{
							;tempUse4->getDFAList()[n] = 0
						;}
					;}
				;}
				;tempUse2 = tempUse2->getParent()
				;tempUse4 = tempUse4->getParent()
			;}
		;}
		;tempUse = tempUse->getParent()
		;tempUse3 = tempUse3->getParent()
	;}
	;int* spaceLine = new int[tempChange]
	;spaceLine[0] = 0
	;tempUse = tempDFAList->getParent()
	;for (int i = 1; i < tempChange; ++i)
	{
		;if (0 == tempUse->getDFAList()[0])
		{
			;spaceLine[i] = spaceLine[i - 1] + 1
		;}else
		{
			;spaceLine[i] = spaceLine[i - 1]
		;}
		;tempUse = tempUse->getParent()
	;}
	;/*
	;tempUse = tempDFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<tempUse->getDFAList()[j]
		;}
		;cout<<endl
		;tempUse = tempUse->getParent()
	;}
	;*///
	;int tempLen = 0
	;tempNum = tempChange
	;tempUse = tempDFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;if (0 == tempUse->getDFAList()[0])
		{
			;--tempNum
		;}
		;tempUse = tempUse->getParent()
	;}
	;int** finalDFA = new int*[tempNum]
	;
	;for (int i = 0; i < tempNum; ++i)
	{
		;finalDFA[i] = new int[row]
		;for (int j = 0; j < row; ++j)
		{
			;finalDFA[i][j] = 0
		;}
	;}
	;/*
	;for (int i = 0; i < tempNum; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<finalDFA[i][j]
		;}
		;cout<<endl
	;}
	;*///
	;tempUse = tempDFAList
	;tempUse2 = tempNFAList
	;for (int i = 0; i < tempChange; ++i)
	{
		;if (0 != tempUse->getDFAList()[0])
		{
			;for (int j = 0; j < row - 1; ++j)
			{
				;finalDFA[tempLen][j] = tempUse->getDFAList()[j] - spaceLine[tempUse->getDFAList()[j] - 1]
			;}
			;if (tempUse2->getNFAList()[0])
			{
				;finalDFA[tempLen][row - 1] = 1
			;}
			;++tempLen
		;}
		;tempUse = tempUse->getParent()
		;tempUse2 = tempUse2->getParent()
	;}
	;for (int i = 0; i < tempNum; ++i)
	{
		;if (0 == finalDFA[i][row - 1])
		{
			;int j = 0
			;for (j = 0; j < row - 1; ++j)
			{
				;if (i != (finalDFA[i][j] - 1))
				{
					;break
				;}
			;}
			;if ((row - 1) == j)
			{
				;for (int m = 0; m < tempNum; ++m)
				{
					;for (int n = 0; n < row - 1; ++n)
					{
						;if (i == (finalDFA[m][n] - 1))
						{
							;finalDFA[m][n] = 0
						;}
					;}
				;}
				;break
			;}
		;}
	;}
	;for (int i = 0; i < tempNum; ++i)
	{
		;for (int j = 0; j < row - 1; ++j)
		{
			;cout<<finalDFA[i][j]<<'+'
		;}
		;cout<<'-'<<finalDFA[i][row - 1]
		;cout<<endl
	;}
	;/**///
	;return finalDFA
;}//��DFA����