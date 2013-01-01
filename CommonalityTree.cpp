#include "StdAfx.h"
#include "CommonalityTree.h"


;/*
	��������:
		CommonalityTree

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
	��������:
		CommonalityTree

	��������:
		���캯��

	����:
		pubID(int):Ψһ��ʶ��

		Conte(int):�ڵ�����

	����:
		�޽���

	��������:
		���캯���޷���

	ע��:
		��
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
	��������:
		~CommonalityTree

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
;CommonalityTree::
~CommonalityTree//
(
 void
)
{
}

;/*
	��������:
		clear

	��������:
		��սڵ�����

	����:
		��

	����:
		�޽���

	��������:
		bool:�Ƿ���ճɹ�

	ע��:
		��
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
	��������:
		getPublicID

	��������:
		��ȡpublicID

	����:
		��

	����:
		�޽���

	��������:
		int:publicID

	ע��:
		��
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
	��������:
		getContent

	��������:
		��ȡcontent

	����:
		��

	����:
		�޽���

	��������:
		int:content

	ע��:
		��
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
	��������:
		getLeft

	��������:
		��ȡleft

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:left

	ע��:
		��
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
	��������:
		getRight

	��������:
		��ȡright

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:right

	ע��:
		��
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
	��������:
		getParent

	��������:
		��ȡparent

	����:
		��

	����:
		�޽���

	��������:
		CommonalityTree*:parent

	ע��:
		��
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
	��������:
		getDFAList

	��������:
		��ȡDFAList

	����:
		��

	����:
		�޽���

	��������:
		int*:DFAList

	ע��:
		��
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
	��������:
		getNFAList

	��������:
		��ȡNFAList

	����:
		��

	����:
		�޽���

	��������:
		bool*:NFAList

	ע��:
		��
 *///
;bool*
CommonalityTree::
getNFAList//
(
 void
)
{
	;return NFAList
;}//NFAList:get��

;/*
	��������:
		setPublicID

	��������:
		����publicID

	����:
		pubID(int):�趨ֵ

	����:
		�޽���

	��������:
		int:publicID

	ע��:
		��
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
	��������:
		setContent

	��������:
		����content

	����:
		Conte(int):�趨ֵ

	����:
		�޽���

	��������:
		int:content

	ע��:
		��
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
	��������:
		setLeft

	��������:
		����left

	����:
		Left(CommonalityTree *):�趨ֵ

	����:
		�޽���

	��������:
		CommonalityTree*:left

	ע��:
		��
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
	��������:
		setRight

	��������:
		����right

	����:
		right(CommonalityTree *):�趨ֵ

	����:
		�޽���

	��������:
		CommonalityTree*:right

	ע��:
		��
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
	��������:
		setParent

	��������:
		����parent

	����:
		parent(CommonalityTree *):�趨ֵ

	����:
		�޽���

	��������:
		CommonalityTree*:parent

	ע��:
		��
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
	��������:
		setDFAList

	��������:
		����DFAList

	����:
		DFAList(int *):�趨ֵ

	����:
		�޽���

	��������:
		int*:DFAList

	ע��:
		��
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
	��������:
		setDFAList

	��������:
		����DFAList

	����:
		DFAList(int *):�趨ֵ

	����:
		�޽���

	��������:
		int*:DFAList

	ע��:
		��
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