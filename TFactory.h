/*
	�ļ�����:TFactory.h
	������:TFactory
	�๦��:�ù���ģʽ����������CommonalityTree����
*/
#pragma once
#include "CommonalityTree.h"

;class TFactory
{
	;
public:
	;TFactory(void)
	;TFactory(int len)
	;TFactory(int len, int crit)
	;TFactory(int len, int crit, int increa)
	;
public:
	;~TFactory(void)
	;
public:
	;//int setLength(int change)
	;int makeCommonalityTree(int objectNum)							//������Ʒ
	;int callbackCommonalityTreeNode(CommonalityTree* callbackNode)				//����һ����Ʒ
	;int callbackCommonalityTreeRoot(CommonalityTree* callbackRoot)				//����һЩ��Ʒ
	;CommonalityTree* getOneCommonalityTree(void)						//��ȡһ����Ʒ
	;CommonalityTree* getArrayCommonalityTree(int len)					//��ȡһ����Ʒ
	;
	;
public:
	;int getLen(void)									//��ȡ���
	;int getCri(void)									//��ȡ�ٽ�ֵ
	;int getInc(void)									//��ȡ����ֵ
	;
	;
private:
	;//CommonalityTree* produce								//ָ�������Ʒ��ָ��
	;//CommonalityTree* CommonalityTreeArray[]
	;int length										//�����ڶ��������
	;int critical										//������Ҫ���������Ķ��������ٽ�ֵ
	;int increase										//����ÿ����������������
	;CommonalityTree* storage								//�����׽ڵ�ָ��
	;
;};
