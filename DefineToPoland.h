#pragma once
/*
	������:DefineToPoland
	�๦��:����ȷ�����涨����ʽת��Ϊǰ׺(���׺)���ʽ
*///
#include "CommonalityTree.h"
#include "TFactory.h"

class DefineToPoland
{
public:
	;
	;DefineToPoland(void)										//
	;DefineToPoland(TFactory* nodeF)								//���ݸ�����ָ���趨����
	;
public:
	;
	;~DefineToPoland(void)										//
	;
public:
	;
	;char* unPolandExp(char* define, int index)							//����׺���ʽת����Ϊ�沨�����ʽ(��׺���ʽ)
	;char* polandExp(char* define, int index)							//����׺���ʽת����Ϊ�������ʽ(ǰ׺���ʽ)
	;char* standardExp(char* define, int &index)							//���û����������ʽ��׼��(���ϳ������ı��ʽ)
	;
	;
private:
	;
	;
	;int expIspForUnPoland(char operat)								//��ջ���ȼ�
	;int expIcpForUnPoland(char operat)								//��ջ���ȼ�
	;int expIspForPoland(char operat)								//��ջ���ȼ�
	;int expIcpForPoland(char operat)								//��ջ���ȼ�
	;char pop(void)											//��ջ
	;char push(char operat)										//��ջ
	;
	;
private:
	;
	;CommonalityTree* stack										//ջ��ָ��
	;TFactory* nodeFactory										//����ָ��
	;
	;
};
