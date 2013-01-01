#include "StdAfx.h"
#include "TFactory.h"
;/*
	函数名称:
		TFactory

	函数作用:
		构造函数

	参数:
		无

	操作:
		初始化数据

	返回类型:
		构造函数无返回

	备注:
		无
*///
;TFactory::
TFactory//
(
 void
)
{
	;storage = NULL
	;length = 100
	;critical = 30
	;increase = 50
	;makeCommonalityTree(100)
;}

;/*
	函数名称:
		~TFactory

	函数作用:
		析构函数

	参数:
		无

	操作:
		清除库存,返回内存

	返回类型:
		构造函数无返回

	备注:
		无
*///
;TFactory::
~TFactory//
(
 void
)
{
	;CommonalityTree* tempDel = NULL
	;while (NULL != storage)
	{
		;tempDel = storage
		;storage = storage->getParent()
		;delete tempDel
	;}
;}

;/*
	函数名称:
		TFactory

	函数作用:
		构造函数

	参数:
		len(int):工厂库存

	操作:
		初始化数据

	返回类型:
		构造函数无返回

	备注:
		无
*///
;TFactory::
TFactory//
(
 int len
)
{
	;length = len
	;critical = 30
	;increase = 50
	;makeCommonalityTree(len)
;}

;/*
	函数名称:
		TFactory

	函数作用:
		构造函数

	参数:
		len(int):工厂库存

		crit(int):临界生产条件

	操作:
		初始化数据

	返回类型:
		构造函数无返回

	备注:
		无
*///
;TFactory::
TFactory//
(
 int len,
 int crit
)
{
	;length = len
	;critical = crit
	;increase = 50
	;makeCommonalityTree(len)
;}

;/*
	函数名称:
		TFactory

	函数作用:
		构造函数

	参数:
		len(int):工厂库存

		crit(int):临界生产条件

		increa(int):每次在生产的数量

	操作:
		初始化数据

	返回类型:
		构造函数无返回

	备注:
		无
*///
;TFactory::
TFactory//
(
 int len,
 int crit,
 int increa
)
{
	;length = len
	;critical = crit
	;increase = increa
	;makeCommonalityTree(len)
;}

;/*
	函数名称:
		getLength

	函数作用:
		返回工厂内对象的数量

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:对象的个数

	备注:
		无
*///
;int
TFactory::
getLen//
(
 void
)
{
	;return length
;}

;/*
	函数名称:
		getCri

	函数作用:
		获取临界值

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:获取临界值

	备注:
		无
 *///
;int
TFactory::
getCri//
(
 void
)
{
	;return critical
;}

;/*
	函数名称:
		getInc

	函数作用:
		获取增长值

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:获取增长值

	备注:
		无
 *///
;int
TFactory::
getInc//
(
 void
)
{
	;return increase
;}

;/*
	函数名称:
		makeCommonalityTree

	函数作用:
		生产一定数量的对象,并组织起来,联结成一个链表

	参数:
		objectNum(int):需要生产的数量

	操作:
		生产对象并组合起来

	返回类型:
		int:生产对象的个数

	备注:
		无
*///
;int
TFactory::
makeCommonalityTree//
(
 int objectNum
)
{
	;CommonalityTree* tempProduce = NULL
	;for (int i = 0; i < objectNum; ++i)
	{
		;tempProduce = new CommonalityTree()
		;tempProduce->setParent(storage)
		;storage = tempProduce
	;}
	;return objectNum
;}

;/*
	函数名称:
		callbackCommonalityTreeNode

	函数作用:
		回收一件产品,加入库存中

	参数:
		callbackNode(CommonalityTree *):需要回收的节点的指针

	操作:
		回收对象并组合起来

	返回类型:
		int:成功回收对象的个数

	备注:
		无
*///
;int
TFactory::
callbackCommonalityTreeNode//
(
 CommonalityTree* callbackNode
)
{
	;if (callbackNode->clear())
	{
		;callbackNode->setParent(storage)
		;storage = callbackNode
		;++length
		;return 1
	;}else
	{
		;return 0
	;}
;}

;/*
	函数名称:
		callbackCommonalityTreeRoot

	函数作用:
		回收一些产品,加入库存中

	参数:
		callbackRoot(CommonalityTree *):需要回收的根节点的指针

		len(int):用来统计回收的产品数量

	操作:
		回收对象并组合起来

	返回类型:
		int:回收对象的个数

	备注:
		无
*///
;int
TFactory::
callbackCommonalityTreeRoot//
(
 CommonalityTree* callbackRoot
)
{
	;if (NULL  !=  callbackRoot->getLeft())
	{
		;callbackCommonalityTreeRoot(callbackRoot->getLeft())
	;}
	;if (NULL  !=  callbackRoot->getRight())
	{
		;callbackCommonalityTreeRoot(callbackRoot->getRight())
	;}
	;if (NULL  !=  callbackRoot->getParent())
	{
		;callbackCommonalityTreeRoot(callbackRoot->getParent())
	;}
	;callbackCommonalityTreeNode(callbackRoot)
	;return 0
;}

;/*
	函数名称:
		getOneCommonalityTree

	函数作用:
		提取一件产品

	参数:
		无

	操作:
		提取一件产品,返回指向产品的指针

	返回类型:
		CommonalityTree*:返回指向产品的指针

	备注:
		无
*///
;CommonalityTree*
TFactory::
getOneCommonalityTree//
(
 void
)
{
	;CommonalityTree* produce = storage
	;storage = storage->getParent()
	;--length
	;if (length <= critical)
	{
		;length += makeCommonalityTree(increase)
	;}
	;produce->setParent(NULL)
	;return produce
;}

;/*
	函数名称:
		getArrayCommonalityTree

	函数作用:
		提取一组产品

	参数:
		len(int):提取产品的数量

	操作:
		提取一组产品,返回指向产品链表首的指针

	返回类型:
		CommonalityTree*:返回指向产品链表首的指针

	备注:
		无
*///
;CommonalityTree*
TFactory::
getArrayCommonalityTree//
(
 int len
)
{
	;CommonalityTree* produce = NULL
	;CommonalityTree* temp = NULL
	;if (len > length)
	{
		;while (len > length)
		{
			;for (int i = 0; i < length; ++i)
			{
				;temp = produce
				;produce = storage
				;storage = storage->getParent()
				;produce->setParent(temp)
			;}
			;len -= length
			;length = 0
			;length += makeCommonalityTree(increase)
		;}
		;for (int i = 0; i < len; ++i)
		{
			;temp = produce
			;produce = storage
			;storage = storage->getParent()
			;produce->setParent(temp)
		;}
		;length -= len
		;if (length <= critical)
		{
			;length += makeCommonalityTree(increase)
		;}
	;}else
	{
		;for (int i = 0; i < len; ++i)
		{
			;temp = produce
			;produce = storage
			;storage = storage->getParent()
			;produce->setParent(temp)
		;}
		;length -= len
		;if (length <= critical)
		{
			;length += makeCommonalityTree(increase)
		;}
	;}
	;return produce
;}