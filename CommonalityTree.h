#pragma once
/*
	类名称:CommonalityTree
	类功能:整个程序中的公共树节点
*///
;class CommonalityTree
{
public:
	;
	;CommonalityTree(void)
	;CommonalityTree(int pubID, int Conte)
	;
	;
public:
	;
	;~CommonalityTree(void)
	;
	;
private:
	;
	;int publicID										//处理过程中的唯一标记:自然数标记
	;int content										//运算符和操作数分类标记
	;CommonalityTree* left									//左指针
	;CommonalityTree* right									//右指针
	;CommonalityTree* parent								//双亲指针
	;int* DFAList										//记录单行DFA列表
	;bool* NFAList										//记录单行NFA列表
	;
	;
public:
	;
	;bool clear(void)									//清空节点数据
	;
	;
	;
public:
	;
	;int getPublicID(void)									//publicID:get版
	;int getContent(void)									//content:get版
	;CommonalityTree* getLeft(void)								//left:get版
	;CommonalityTree* getRight(void)							//right:get版
	;CommonalityTree* getParent(void)							//parent:get版
	;int* getDFAList(void)									//DFAList:get版
	;bool* getNFAList(void)									//NFAList:get版
	;
public:
	;
	;int setPublicID(int pubID)								//publicID:set版
	;int setContent(int Conte)								//content:set版
	;CommonalityTree* setLeft(CommonalityTree* le)						//left:set版
	;CommonalityTree* setRight(CommonalityTree* ri)						//right:set版
	;CommonalityTree* setParent(CommonalityTree* pa)					//parent:set版
	;int* setDFAList(int* list)								//DFAList:set版
	;bool* setNFAList(bool* list)								//NFAList:set版
	;

;};
