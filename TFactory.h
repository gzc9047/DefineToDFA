/*
	文件名称:TFactory.h
	类名称:TFactory
	类功能:用工厂模式创建并管理CommonalityTree对象
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
	;int makeCommonalityTree(int objectNum)							//生产商品
	;int callbackCommonalityTreeNode(CommonalityTree* callbackNode)				//回收一件产品
	;int callbackCommonalityTreeRoot(CommonalityTree* callbackRoot)				//回收一些产品
	;CommonalityTree* getOneCommonalityTree(void)						//获取一件产品
	;CommonalityTree* getArrayCommonalityTree(int len)					//获取一组商品
	;
	;
public:
	;int getLen(void)									//获取库存
	;int getCri(void)									//获取临界值
	;int getInc(void)									//获取增长值
	;
	;
private:
	;//CommonalityTree* produce								//指向出厂产品的指针
	;//CommonalityTree* CommonalityTreeArray[]
	;int length										//工厂内对象的数量
	;int critical										//工厂需要进行生产的对象数量临界值
	;int increase										//工厂每次生产个对象数量
	;CommonalityTree* storage								//库存的首节点指针
	;
;};
