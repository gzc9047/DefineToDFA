#pragma once
/*
	������:TreeToNFA
	�๦��:��������NFA��ת��ΪNFAת���б�
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
	;bool*** makeNFAList(PolandToTree* NFARoot, char* expression, int &conNum)				//����NFA��,����Ψһ�ӿ�
	;char* nodeCondition(PolandToTree* NFARoot, char* expression, int &count)				//����ת������
	;
private:
	;
	;int* TreeFieldWidth(PolandToTree* NFARoot, char* expression)						//����NFA�������NFA�б������
	;int countCondition(char* expression)									//��¼ת����������
	;
	;
private:
	;
	;char*** NFAList											//�������ɵ�NFA��
	;
;};
