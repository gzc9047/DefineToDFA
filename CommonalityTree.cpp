#include "StdAfx.h"
#include "CommonalityTree.h"


;/*
	函数名称:
		CommonalityTree

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
;CommonalityTree::
CommonalityTree//
(
 void
)
{
	;publicID = 0
	;content = 0
	;left = NULL
	;right = NULL
	;parent = NULL
	;DFAList = NULL
	;NFAList = NULL
;}

;/*
	函数名称:
		CommonalityTree

	函数作用:
		构造函数

	参数:
		pubID(int):唯一标识符

		Conte(int):节点类型

	操作:
		无介绍

	返回类型:
		构造函数无返回

	注备:
		无
 *///
;CommonalityTree::
CommonalityTree//
(
 int pubID,
 int Conte
)
{
	;publicID = pubID
	;content = Conte
	;left = NULL
	;right = NULL
	;parent = NULL
	;DFAList = NULL
	;NFAList = NULL
;}

;/*
	函数名称:
		~CommonalityTree

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
;CommonalityTree::
~CommonalityTree//
(
 void
)
{
}

;/*
	函数名称:
		clear

	函数作用:
		清空节点数据

	参数:
		无

	操作:
		无介绍

	返回类型:
		bool:是否清空成功

	注备:
		无
 *///
;bool
CommonalityTree::
clear//
(
 void
)
{
	;publicID = 0
	;content = 0
	;left = NULL
	;right = NULL
	;parent = NULL
	;DFAList = NULL
	;NFAList = NULL
	;return publicID || content || left || right || parent
;}
;/*
	函数名称:
		getPublicID

	函数作用:
		获取publicID

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:publicID

	注备:
		无
 *///
;int
CommonalityTree::
getPublicID//
(
 void
)
{
	;return publicID
;}

;/*
	函数名称:
		getContent

	函数作用:
		获取content

	参数:
		无

	操作:
		无介绍

	返回类型:
		int:content

	注备:
		无
 *///
;int
CommonalityTree::
getContent//
(
 void
)
{
	;return content
;}

;/*
	函数名称:
		getLeft

	函数作用:
		获取left

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:left

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
getLeft//
(
 void
)
{
	;return left
;}

;/*
	函数名称:
		getRight

	函数作用:
		获取right

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:right

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
getRight//
(
 void
)
{
	;return right
;}

;/*
	函数名称:
		getParent

	函数作用:
		获取parent

	参数:
		无

	操作:
		无介绍

	返回类型:
		CommonalityTree*:parent

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
getParent//
(
 void
)
{
	;return parent
;}

;/*
	函数名称:
		getDFAList

	函数作用:
		获取DFAList

	参数:
		无

	操作:
		无介绍

	返回类型:
		int*:DFAList

	注备:
		无
 *///
;int*
CommonalityTree::
getDFAList//
(
 void
)
{
	;return DFAList
;}

;/*
	函数名称:
		getNFAList

	函数作用:
		获取NFAList

	参数:
		无

	操作:
		无介绍

	返回类型:
		bool*:NFAList

	注备:
		无
 *///
;bool*
CommonalityTree::
getNFAList//
(
 void
)
{
	;return NFAList
;}//NFAList:get版

;/*
	函数名称:
		setPublicID

	函数作用:
		设置publicID

	参数:
		pubID(int):设定值

	操作:
		无介绍

	返回类型:
		int:publicID

	注备:
		无
 *///
;int
CommonalityTree::
setPublicID//
(
 int pubID
)
{
	;publicID = pubID
	;return publicID
;}

;/*
	函数名称:
		setContent

	函数作用:
		设置content

	参数:
		Conte(int):设定值

	操作:
		无介绍

	返回类型:
		int:content

	注备:
		无
 *///
;int
CommonalityTree::
setContent//
(
 int Conte
)
{
	;content = Conte
	;return content
;}

;/*
	函数名称:
		setLeft

	函数作用:
		设置left

	参数:
		Left(CommonalityTree *):设定值

	操作:
		无介绍

	返回类型:
		CommonalityTree*:left

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
setLeft//
(
 CommonalityTree* le
)
{
	;left = le
	;return left
;}

;/*
	函数名称:
		setRight

	函数作用:
		设置right

	参数:
		right(CommonalityTree *):设定值

	操作:
		无介绍

	返回类型:
		CommonalityTree*:right

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
setRight//
(
 CommonalityTree* ri
)
{
	;right = ri
	;return right
;}

;/*
	函数名称:
		setParent

	函数作用:
		设置parent

	参数:
		parent(CommonalityTree *):设定值

	操作:
		无介绍

	返回类型:
		CommonalityTree*:parent

	注备:
		无
 *///
;CommonalityTree*
CommonalityTree::
setParent//
(
 CommonalityTree* pa
)
{
	;parent = pa
	;return parent
;}

;/*
	函数名称:
		setDFAList

	函数作用:
		设置DFAList

	参数:
		DFAList(int *):设定值

	操作:
		无介绍

	返回类型:
		int*:DFAList

	注备:
		无
 *///
;int*
CommonalityTree::
setDFAList//
(
 int* list
)
{
	;DFAList = list
	;return DFAList
;}

;/*
	函数名称:
		setDFAList

	函数作用:
		设置DFAList

	参数:
		DFAList(int *):设定值

	操作:
		无介绍

	返回类型:
		int*:DFAList

	注备:
		无
 *///
;bool*
CommonalityTree::
setNFAList//
(
 bool* list
)
{
	;NFAList = list
	;return NFAList
;}