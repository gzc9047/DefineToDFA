//两个字符串的连接操作
;char* joinChar(char* c1, char* c2)
//将字符串变成数字
;int charToNum(char* ch)
//将数字变成字符
;char* numToChar(int a)
//读取密码
;int readKey(char* pW)
//读取可变长度字符
;char* getString(void)
//将给定的字符串拆分成单词,单独实现为以后实现NFAToDFA提供单独的"接口"
;char* splitString(char* &inputString)
//从文件中读取字符保存在一个字符串中
;char* getFileString(ifstream* fin)
//从文件中拆分字符串
;//char* splitStringFromFile(ifstream &fin)
//计算字符数组长度(不含'\0')
;int charLen(char* target)
//区分字母数字和正规式运算符
;int filtration(char letter)
//判断用户输入正规式的格式是否正确
;bool verdict(char* exp, int criterion[7][6], int &index, bool leftP)
//转义用户输入的字符
;char trans(char letter)