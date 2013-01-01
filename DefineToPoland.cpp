#include "StdAfx.h"
#include "DefineToPoland.h"

;/*
	函数名称:
		DefineToPoland

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
	函数名称:
		~DefineToPoland

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
;DefineToPoland::
~DefineToPoland//
(
 void
)
{
	;nodeFactory->callbackCommonalityTreeRoot(stack)
;}

;/*
	函数名称:
		DefineToPoland

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
	函数名称:
		expIspForUnPoland

	函数作用:
		返回操作数退栈优先级

	参数:
		operat(char):操作数

	操作:
		无介绍

	返回类型:
		int:优先级

	注备:
		无
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
	函数名称:
		expIcpForUnPoland

	函数作用:
		返回操作数进栈优先级

	参数:
		operat(char):操作数

	操作:
		无介绍

	返回类型:
		int:优先级

	注备:
		无
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
	函数名称:
		expIcpForPoland

	函数作用:
		返回操作数进栈优先级

	参数:
		operat(char):操作数

	操作:
		无介绍

	返回类型:
		int:优先级

	注备:
		无
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
	函数名称:
		expIcpForPoland

	函数作用:
		返回操作数进栈优先级

	参数:
		operat(char):操作数

	操作:
		无介绍

	返回类型:
		int:优先级

	注备:
		无
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
	函数名称:
		pop

	函数作用:
		退栈

	参数:
		无

	操作:
		无介绍

	返回类型:
		char:退栈的操作数

	注备:
		无
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
	函数名称:
		push

	函数作用:
		进栈

	参数:
		operat(char):操作数

	操作:
		无介绍

	返回类型:
		char:进栈的操作数

	注备:
		无
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
	函数名称:
		unPolandExp

	函数作用:
		将中缀表达式转换成为逆波兰表达式(后缀表达式)

	参数:
		define(char *):表达式字符串指针

		index(int):表达式长度

	操作:
		利用栈来操作

	返回类型:
		char*:转换后的表达式字符串指针

	注备:
		无
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
	函数名称:
		polandExp

	函数作用:
		将中缀表达式转换成为波兰表达式(前缀表达式)

	参数:
		define(char *):表达式字符串指针

		index(int):表达式长度

	操作:
		利用栈来操作

	返回类型:
		char*:转换后的表达式字符串指针

	注备:
		无
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
;}//将中最表达式转换成为波兰表达式(前缀表达式)

;/*
	函数名称:
		standardExp

	函数作用:
		将用户输入的正规式标准化(符合程序理解的表达式)

	参数:
		define(char *):表达式字符串指针

		index(int &):表达式长度

	操作:
		无介绍

	返回类型:
		char*:标准化正规式(符合程序理解的表达式)指针

	注备:
		无
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