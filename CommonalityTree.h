#pragma once
/*
	������:CommonalityTree
	�๦��:���������еĹ������ڵ�
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
	;int publicID										//��������е�Ψһ���:��Ȼ�����
	;int content										//������Ͳ�����������
	;CommonalityTree* left									//��ָ��
	;CommonalityTree* right									//��ָ��
	;CommonalityTree* parent								//˫��ָ��
	;int* DFAList										//��¼����DFA�б�
	;bool* NFAList										//��¼����NFA�б�
	;
	;
public:
	;
	;bool clear(void)									//��սڵ�����
	;
	;
	;
public:
	;
	;int getPublicID(void)									//publicID:get��
	;int getContent(void)									//content:get��
	;CommonalityTree* getLeft(void)								//left:get��
	;CommonalityTree* getRight(void)							//right:get��
	;CommonalityTree* getParent(void)							//parent:get��
	;int* getDFAList(void)									//DFAList:get��
	;bool* getNFAList(void)									//NFAList:get��
	;
public:
	;
	;int setPublicID(int pubID)								//publicID:set��
	;int setContent(int Conte)								//content:set��
	;CommonalityTree* setLeft(CommonalityTree* le)						//left:set��
	;CommonalityTree* setRight(CommonalityTree* ri)						//right:set��
	;CommonalityTree* setParent(CommonalityTree* pa)					//parent:set��
	;int* setDFAList(int* list)								//DFAList:set��
	;bool* setNFAList(bool* list)								//NFAList:set��
	;

;};
