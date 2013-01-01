#pragma once
#include "TFactory.h"
/*
	������:NFAToDFA
	�๦��:��������NFA�б�ת��ΪDFA�б�,�����м�
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
	;int** NFAListToDFAList(int line, int row, bool*** NFAList)						//����DFA�б�
	;int** predigestDFA(CommonalityTree* tempDFAList, int line, int row, CommonalityTree* tempNFAList)	//��DFA����
	;
public:
	;
	;bool* closure(int line, int row, bool* target, bool*** NFAList)					//����target��line��մ��ıհ�
	;bool* closureE(int line, int num, bool* target, bool*** NFAList)					//�󼯺϶Կմ��ıհ�
	;
	;
private:
	;
	;int** DFAList												//�������ɵ�DFA�б�
	;TFactory* nodeFactory											//����ָ��
	;
;};
