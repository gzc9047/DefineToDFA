#pragma once
/*
	������:PolandToTree
	�๦��:��������ǰ׺(���׺)���ʽת��ΪNFA���ṹ
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
	;CommonalityTree* expressionToTree(CommonalityTree* headNode, CommonalityTree* tailNode, char* expression, int &index)			//�����ʽ���ַ���ת��Ϊ��
	;CommonalityTree* expToNFA(char* expression, int &index)										//�����ʽ���ַ���ת��ΪNFA,����ӿ�
	;
	;
	;CommonalityTree* getDoubleNode(void)													//���ʽת���������õ���˫�ڵ��㷨
	;int outTree(CommonalityTree* expressionRoot)												//���Թ�����������ʽ
	;
public:
	;
	;CommonalityTree* getRoot(void)														//��ñ��ʽ���ĸ��ڵ�
	;CommonalityTree* getNodeList(void)													//��ýڵ��б�
	;int getPublicNum(void)															//�����Ч�ڵ����
	;
	;
private:
	;
	;CommonalityTree* expressionRoot													//���ʽ���ĸ��ڵ�ָ��
	;TFactory* nodeFactory															//����ָ��
	;int publicNum																//��Ч���ʽ�ڵ�ĸ���
	;CommonalityTree* nodeList														//�ڵ��б�
	;
;};
