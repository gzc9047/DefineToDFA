#include "StdAfx.h"
#include "TFactory.h"
;/*
	��������:
		TFactory

	��������:
		���캯��

	����:
		��

	����:
		��ʼ������

	��������:
		���캯���޷���

	��ע:
		��
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
	��������:
		~TFactory

	��������:
		��������

	����:
		��

	����:
		������,�����ڴ�

	��������:
		���캯���޷���

	��ע:
		��
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
	��������:
		TFactory

	��������:
		���캯��

	����:
		len(int):�������

	����:
		��ʼ������

	��������:
		���캯���޷���

	��ע:
		��
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
	��������:
		TFactory

	��������:
		���캯��

	����:
		len(int):�������

		crit(int):�ٽ���������

	����:
		��ʼ������

	��������:
		���캯���޷���

	��ע:
		��
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
	��������:
		TFactory

	��������:
		���캯��

	����:
		len(int):�������

		crit(int):�ٽ���������

		increa(int):ÿ��������������

	����:
		��ʼ������

	��������:
		���캯���޷���

	��ע:
		��
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
	��������:
		getLength

	��������:
		���ع����ڶ��������

	����:
		��

	����:
		�޽���

	��������:
		int:����ĸ���

	��ע:
		��
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
	��������:
		getCri

	��������:
		��ȡ�ٽ�ֵ

	����:
		��

	����:
		�޽���

	��������:
		int:��ȡ�ٽ�ֵ

	��ע:
		��
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
	��������:
		getInc

	��������:
		��ȡ����ֵ

	����:
		��

	����:
		�޽���

	��������:
		int:��ȡ����ֵ

	��ע:
		��
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
	��������:
		makeCommonalityTree

	��������:
		����һ�������Ķ���,����֯����,�����һ������

	����:
		objectNum(int):��Ҫ����������

	����:
		���������������

	��������:
		int:��������ĸ���

	��ע:
		��
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
	��������:
		callbackCommonalityTreeNode

	��������:
		����һ����Ʒ,��������

	����:
		callbackNode(CommonalityTree *):��Ҫ���յĽڵ��ָ��

	����:
		���ն����������

	��������:
		int:�ɹ����ն���ĸ���

	��ע:
		��
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
	��������:
		callbackCommonalityTreeRoot

	��������:
		����һЩ��Ʒ,��������

	����:
		callbackRoot(CommonalityTree *):��Ҫ���յĸ��ڵ��ָ��

		len(int):����ͳ�ƻ��յĲ�Ʒ����

	����:
		���ն����������

	��������:
		int:���ն���ĸ���

	��ע:
		��
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
	��������:
		getOneCommonalityTree

	��������:
		��ȡһ����Ʒ

	����:
		��

	����:
		��ȡһ����Ʒ,����ָ���Ʒ��ָ��

	��������:
		CommonalityTree*:����ָ���Ʒ��ָ��

	��ע:
		��
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
	��������:
		getArrayCommonalityTree

	��������:
		��ȡһ���Ʒ

	����:
		len(int):��ȡ��Ʒ������

	����:
		��ȡһ���Ʒ,����ָ���Ʒ�����׵�ָ��

	��������:
		CommonalityTree*:����ָ���Ʒ�����׵�ָ��

	��ע:
		��
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