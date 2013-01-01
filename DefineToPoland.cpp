#include "StdAfx.h"
#include "DefineToPoland.h"

;/*
	��������:
		DefineToPoland

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
;DefineToPoland::
DefineToPoland//
(
 void
)
{
	;nodeFactory = NULL
	;stack = NULL
;}

;/*
	��������:
		~DefineToPoland

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
;DefineToPoland::
~DefineToPoland//
(
 void
)
{
	;nodeFactory->callbackCommonalityTreeRoot(stack)
;}

;/*
	��������:
		DefineToPoland

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
;DefineToPoland::
DefineToPoland//
(
 TFactory* nodeF
)
{
	;nodeFactory = nodeF
	;stack = nodeFactory->getOneCommonalityTree()
	;stack->setContent((int)'#')
;}

;/*
	��������:
		expIspForUnPoland

	��������:
		���ز�������ջ���ȼ�

	����:
		operat(char):������

	����:
		�޽���

	��������:
		int:���ȼ�

	ע��:
		��
 *///
;int
DefineToPoland::
expIspForUnPoland//
(
 char operat
)
{
	;switch (operat)
	{
		;case '#':
			;return 0
		;case '(':
			;return 1
		;case '*':
			;return 7
		;case '+':
			;return 7
		;case '?':
			;return 7
		;case '|':
			;return 5
		;case '-':
			;return 3
		;case ')':
			;return 8
		;default:
			;return -1
	;}
;}

;/*
	��������:
		expIcpForUnPoland

	��������:
		���ز�������ջ���ȼ�

	����:
		operat(char):������

	����:
		�޽���

	��������:
		int:���ȼ�

	ע��:
		��
 *///
;int
DefineToPoland::
expIcpForUnPoland//
(
 char operat
)
{
	;switch (operat)
	{
		;case '#':
			;return 0
		;case '(':
			;return 8
		;case '*':
			;return 6
		;case '+':
			;return 6
		;case '?':
			;return 6
		;case '|':
			;return 4
		;case '-':
			;return 2
		;case ')':
			;return 1
		;default:
			;return -1
	;}
;}

;/*
	��������:
		expIcpForPoland

	��������:
		���ز�������ջ���ȼ�

	����:
		operat(char):������

	����:
		�޽���

	��������:
		int:���ȼ�

	ע��:
		��
 *///
;int
DefineToPoland::
expIspForPoland//
(
 char operat
)
{
	;switch (operat)
	{
		;case '#':
			;return 0
		;case '(':
			;return 8
		;case '*':
			;return 7
		;case '+':
			;return 7
		;case '?':
			;return 7
		;case '|':
			;return 5
		;case '-':
			;return 3
		;case ')':
			;return 1
		;default:
			;return -1
	;}
;}

;/*
	��������:
		expIcpForPoland

	��������:
		���ز�������ջ���ȼ�

	����:
		operat(char):������

	����:
		�޽���

	��������:
		int:���ȼ�

	ע��:
		��
 *///
;int
DefineToPoland::
expIcpForPoland//
(
 char operat
)
{
	;switch (operat)
	{
		;case '#':
			;return 0
		;case '(':
			;return 1
		;case '*':
			;return 6
		;case '+':
			;return 6
		;case '?':
			;return 6
		;case '|':
			;return 4
		;case '-':
			;return 2
		;case ')':
			;return 8
		;default:
			;return -1
	;}
;}

;/*
	��������:
		pop

	��������:
		��ջ

	����:
		��

	����:
		�޽���

	��������:
		char:��ջ�Ĳ�����

	ע��:
		��
 *///
;char
DefineToPoland::
pop//
(
 void
)
{
	;char tempChar = (char)stack->getContent()
	;CommonalityTree* tempNode = stack->getParent()
	;nodeFactory->callbackCommonalityTreeNode(stack)
	;stack = tempNode
	;return tempChar
;}

;/*
	��������:
		push

	��������:
		��ջ

	����:
		operat(char):������

	����:
		�޽���

	��������:
		char:��ջ�Ĳ�����

	ע��:
		��
 *///
;char
DefineToPoland::
push//
(
 char operat
)
{
	;CommonalityTree* tempNode = nodeFactory->getOneCommonalityTree()
	;tempNode->setContent((int)operat)
	;tempNode->setParent(stack)
	;stack = tempNode
	;return (char)stack->getContent()
;}

;/*
	��������:
		unPolandExp

	��������:
		����׺���ʽת����Ϊ�沨�����ʽ(��׺���ʽ)

	����:
		define(char *):���ʽ�ַ���ָ��

		index(int):���ʽ����

	����:
		����ջ������

	��������:
		char*:ת����ı��ʽ�ַ���ָ��

	ע��:
		��
 *///
;char*
DefineToPoland::
unPolandExp//
(
 char* define,
 int index
)
{
	;int i = 0
	;char* unPoExp = new char[index * 2]
	;define = standardExp(define, index)
	;cout<<define<<endl
	;index = 0
	;while ('\0' != define[i])
	{
		;if ( -1 == expIspForUnPoland(define[i]))
		{
			;unPoExp[index] = define[i]
			;++i
			;++index
		;}else
		{
			;if (expIspForUnPoland((char)stack->getContent()) < expIcpForUnPoland(define[i]))
			{
				;push(define[i])
				;++i
			;}else if (expIspForUnPoland((char)stack->getContent()) > expIcpForUnPoland(define[i]))
			{
				;unPoExp[index] = pop()
				;++index
				;
			;}else
			{
				;pop()
				;++i
			;}
		;}
	;}
	;while ('#' != (char)stack->getContent())
	{
		;unPoExp[index] = pop()
		;++index
	;}
	;unPoExp[index+1] = '\0'
	;return unPoExp
;}

;/*
	��������:
		polandExp

	��������:
		����׺���ʽת����Ϊ�������ʽ(ǰ׺���ʽ)

	����:
		define(char *):���ʽ�ַ���ָ��

		index(int):���ʽ����

	����:
		����ջ������

	��������:
		char*:ת����ı��ʽ�ַ���ָ��

	ע��:
		��
 *///
;char*
DefineToPoland::
polandExp//
(
 char* define,
 int index
)
{
	;int i = 0
	;int tempIndex = 0
	;char* poExp = NULL
	;char* tempExp = new char[index * 2]
	;define = standardExp(define, index)
	;--index
	;while (0 <= index)
	{
		;if ( -1 == expIspForPoland(define[index]))
		{
			;tempExp[i] = define[index]
			;++i
			;--index
			;
			;
		;}else
		{
			;if (expIspForPoland((char)stack->getContent()) < expIcpForPoland(define[index]))
			{
				;push(define[index])
				;--index
				;
			;}else if (expIspForPoland((char)stack->getContent()) > expIcpForPoland(define[index]))
			{
				;tempExp[i] = pop()
				;++i
				;
			;}else
			{
				;pop()
				;--index
			;}
		;}
		;/*
		;if (index > 0)
		{
			;if ('|' != define[index + 1])
			{
				;if ('|' != define[index]
				&& '(' != define[index]
				&& '-' != define[index])
				{
					;if (expIspForPoland((char)stack->getContent()) < expIcpForPoland('-'))
					{
						;push('-')
					;}else if (expIspForPoland((char)stack->getContent()) > expIcpForPoland('-'))
					{
						;tempExp[i] = pop()
						;++i
					;}else
					{
						;pop()
					;}
				;}
			;}
		;}
		;*///
	;}
	;while ('#' != (char)stack->getContent())
	{
		;tempExp[i] = pop()
		;++i
	;}
	;tempExp[i] = '\0'
	;poExp = new char[i+1]
	;--i
	;while (0 <= i)
	{
		;poExp[tempIndex] = tempExp[i]
		;++tempIndex
		;--i
	;}
	;poExp[tempIndex] = '\0'
	;delete []tempExp
	;return poExp
;}//��������ʽת����Ϊ�������ʽ(ǰ׺���ʽ)

;/*
	��������:
		standardExp

	��������:
		���û����������ʽ��׼��(���ϳ������ı��ʽ)

	����:
		define(char *):���ʽ�ַ���ָ��

		index(int &):���ʽ����

	����:
		�޽���

	��������:
		char*:��׼������ʽ(���ϳ������ı��ʽ)ָ��

	ע��:
		��
 *///
;char*
DefineToPoland::
standardExp//
(
 char* define,
 int &index
)
{
	;int i = 0
	;int j = 0
	;char* tempExp = new char[index * 2]
	;while (j < index)
	{
		;tempExp[i] = define[j]
		;if ('(' != define[j]
		&& '|' != define[j]
		&& j < index - 1)
		{
			;if ('|' != define[j + 1]
			&& '*' != define[j + 1]
			&& '+' != define[j + 1]
			&& '?' != define[j + 1]
			&& ')' != define[j + 1])
			{
				;++i
				;tempExp[i] = '-'
			;}
		;}
		;++i
		;++j
	;}
	;index = i
	;char* exp = new char[i]
	;for (int m = 0; m < i; ++m)
	{
		;exp[m] = tempExp[m]
	;}
	;delete []tempExp
	;exp[i] = '\0'
	;return exp
;}