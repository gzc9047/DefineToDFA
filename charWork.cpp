#include "stdafx.h"
#include "charWork.h"

/*
;char* joinChar(char* c1, char* c2)//两个字符串的连接操作，
{
	;char* temp
	;temp = new char[256]
	;int temp1 = 0
	;int temp2 = 0
	;while( '\0' !=c1[temp1])
	{
		;temp[temp1] = c1[temp1]
		;++temp1
	;}
	;do
	{
		;temp[temp1+temp2] = c2[temp2]
		;++temp2
	;}while('\0' != c2[temp2])
	;temp[temp1+temp2] = '\0'
	;return temp
;}

;int charToNum(char* ch)//将字符串变成数字
{
	;int index = 0
	;int temp = 0
	;while('\0' != ch[index])
	{
		;if((int)ch[index] > 47 && (int)ch[index] < 59)
		{
			;temp = temp*10 + ((int)ch[index] - 48)
			;++index
		;}else
		{
			;return -1
		;}
	;}
	;return temp
;}

;char* numToChar(int input)//将数字变成字符
{
	;int index = 0
	;int temp = input
	;char * outChar
	;while(temp/=10)
	{
		;++index
	;}
	;outChar = new char[index+2]
	;outChar[index+1] = '\0'
	;do
	{
		;outChar[index] = (char)(input%10 + 48)
		;input /= 10
		;--index
	;}while(index >= 0)
	;return outChar
;}

;int readKey(char* pW)
{
	;char input = ' '
	;int index = 0
	;while(13 != (input=getch()))
	{
		;if(8==input)
		{
			;if(index)
			{
				;index--
				;cout<<'\b'
				;cout<<' '
				;cout<<'\b'
				;pW[index]='\0'
			;}
		;}
		else
		{
			;pW[index]=input
			;cout<<"*"
			;index++
			;pW[index]='\0'
		;}
	;}
	;return 0
;}
*///

;char* getString()
{
	;unsigned int max = 1
	;unsigned int index = 0
	;char* inString
	;char* temp
	;inString = new char[max]
	;inString[0] = '\0'
	;char input = '\0'
	;while ('\n' != (input = cin.get()))
	{
		;if (8 == input)
		{
			;if (max > 1)
			{
				;if ((index-1) < max/2)
				{
					;--index
					;max = max>>1
					;temp = new char[max]
					;for (unsigned int i = 0; i <= index; i++)
					{
						;temp[i]=inString[i]
					;}
					;char* intemp=inString
					;delete[] intemp
					;inString = temp
				;}else
				{
					;index--
					;cout<<'\b'<<' '<<'\b'
				;}
			;}
		;}else
		{
			;inString[index] = input
			;if ((index+1) < max)
			{
				;++index
			;}else
			{
				;max = max<<1
				;temp = new char[max]
				;for (unsigned int i = 0; i <= index; i++)
				{
					;temp[i]=inString[i]
				;}
				;char* intemp=inString
				;delete[] intemp
				;++index
				;inString = temp
			;}
		;}
	;}
	;inString[index] = '\0'
	;//<<inString<<endl
	;return inString
;}

;/*
	使用getch()的版本,可控性更强,但C++不推荐使用,几乎是禁止使用
;char* getString()
{
	;unsigned int max = 1
	;unsigned int index = 0
	;char* inString
	;char* temp
	;inString = new char[max]
	;inString[0] = '\0'
	;char input = '\0'
	;while (13 != (input = getch()))
	{
		;if (8 == input)
		{
			;if (max > 1)
			{
				;if ((index-1) < max/2)
				{
					;--index
					;max = max>>1
					;temp = new char[max]
					;for (unsigned int i = 0; i <= index; i++)
					{
						;temp[i]=inString[i]
					;}
					;char* intemp=inString
					;delete[] intemp
					;inString = temp
				;}else
				{
					;index--
					;cout<<'\b'<<' '<<'\b'
				;}
			;}
		;}else
		{
			;inString[index] = input
			;if ((index+1) < max)
			{
				;++index
			;}else
			{
				;max = max<<1
				;temp = new char[max]
				;for (unsigned int i = 0; i <= index; i++)
				{
					;temp[i]=inString[i]
				;}
				;char* intemp=inString
				;delete[] intemp
				;++index
				;inString = temp
			;}
		;}
	;}
	;inString[index] = '\0'
	;cout<<inString<<endl
	;return inString
;}
;*/
;//switch结构,不很合理,以后利用DFA合理拆分
;char* splitString(char* &inputStringIndex)
{
	;int index = 0
	;int tempIndex = 0
	;char* tempOut=NULL
	;while (true)
	{
		;switch (inputStringIndex[tempIndex])
		{
			;case '\n' :
			;case ' ' :
			;case '.' :
			;case ',' :
			;case '!' :
			;case '?' :
			;case '(' :
			;case ')' :
			;case '[' :
			;case ']' :
			;case '{' :
			;case '}' :
			;case '\\' :
			;case '/' :
			;case '-' :
			;case '_' :
			;case '=' :
			;case '+' :
			;case '*' :
			;case '`' :
			;case '@' :
			;case '#' :
			;case '$' :
			;case '%' :
			;case '^' :
			;case '&' :
			;case '|' :
			;case '<' :
			;case '>' :
			;case ':' :
			;case ';' :
			;case '\'' :
			;case '\"' :
			;case '~' :
				;if (tempIndex)
				{
					;tempOut = new char[tempIndex+1]
					;while (index != tempIndex)
					{
						;tempOut[index] = inputStringIndex[index]
						;++index
					;}
					;tempOut[tempIndex] = '\0'
					;inputStringIndex = &inputStringIndex[tempIndex]
					;return tempOut
				;}else
				{
					;++inputStringIndex
				;}
				;break
			;case '\0' :
				;if (tempIndex)
				{
					;tempOut = new char[tempIndex+1]
					;while (index != tempIndex)
					{
						;tempOut[index] = inputStringIndex[index]
						;++index
					;}
					;tempOut[tempIndex] = '\0'
					;inputStringIndex = &inputStringIndex[tempIndex]
					;return tempOut
				;}else
				{
					;return NULL
				;}
				;break
			;default :
				;++tempIndex
				;break
		;}
	;}
	;return NULL
;}

;//从文件中读取字符保存在一个字符串中
;char* getFileString(ifstream* fin)
{
	;unsigned int max = 1
	;unsigned int index = 0
	;char* inString
	;char* temp
	;inString = new char[max]
	;inString[0] = '\0'
	;char input = '\0'
	;while (fin->get(input))
	{
		;if (8 == input)
		{
			;if (max > 1)
			{
				;if ((index-1) < max/2)
				{
					;--index
					;max = max>>1
					;temp = new char[max]
					;for (unsigned int i = 0; i <= index; i++)
					{
						;temp[i]=inString[i]
					;}
					;char* intemp=inString
					;delete[] intemp
					;inString = temp
				;}else
				{
					;index--
					;cout<<'\b'<<' '<<'\b'
				;}
			;}
		;}else
		{
			;inString[index] = input
			;if ((index+1) < max)
			{
				;++index
			;}else
			{
				;max = max<<1
				;temp = new char[max]
				;for (unsigned int i = 0; i <= index; i++)
				{
					;temp[i]=inString[i]
				;}
				;char* intemp=inString
				;delete[] intemp
				;++index
				;inString = temp
			;}
		;}
	;}
	;inString[index] = '\0'
	;//cout<<inString<<endl
	;return inString
;}

;//从文件中拆分字符串
;
;//计算字符数组长度(不含'\0')
;int charLen(char* target)
{
	;int index = 0
	;while ('\0' != target[index])
	{
		;++index
	;}
	;return index
;}

;//区分字母数字和正规式运算符
;int filtration(char letter)
{
	;switch (letter)
	{
		;case 'Z' :
		;case 'Y' :
		;case 'X' :
		;case 'W' :
		;case 'V' :
		;case 'U' :
		;case 'T' :
		;case 'S' :
		;case 'R' :
		;case 'Q' :
		;case 'P' :
		;case 'O' :
		;case 'N' :
		;case 'M' :
		;case 'L' :
		;case 'K' :
		;case 'J' :
		;case 'I' :
		;case 'H' :
		;case 'G' :
		;case 'F' :
		;case 'E' :
		;case 'D' :
		;case 'C' :
		;case 'B' :
		;case 'A' :
		;case 'z' :
		;case 'y' :
		;case 'x' :
		;case 'w' :
		;case 'v' :
		;case 'u' :
		;case 't' :
		;case 's' :
		;case 'r' :
		;case 'q' :
		;case 'p' :
		;case 'o' :
		;case 'n' :
		;case 'm' :
		;case 'l' :
		;case 'k' :
		;case 'j' :
		;case 'i' :
		;case 'h' :
		;case 'g' :
		;case 'f' :
		;case 'e' :
		;case 'd' :
		;case 'b' :
		;case 'c' :
		;case 'a' :
		;case '0' :
		;case '1' :
		;case '2' :
		;case '3' :
		;case '4' :
		;case '5' :
		;case '6' :
		;case '7' :
		;case '8' :
		;case '9' :
			;return 1
		;case '(' :
			;return 0
		;case ')' :
			;return 4
		;case '*' :
		;case '+' :
		;case '?' :
			;return 2
		;case '|' :
			;return 3
		;default:
			;return -1
	;}
	;return 0
;}

;//判断用户输入正规式的格式是否正确
;bool verdict(char* exp, int criterion[7][6], int &index, bool leftP)
{
	;int line = 1
	;int temp = 0
	;while ('\0' != exp[index] && (line != 0))
	{
		;temp = filtration(exp[index])
		;if (0 == temp)
		{
			;++index
			;if (!verdict(exp, criterion, index, true))
			{
				;return false
			;}
			;line = criterion[line - 1][0]
			;line = criterion[line - 1][1]
			;line = criterion[line - 1][4]
			;++index
		;}else if (4 == temp)
		{
			;if (!leftP)
			{
				;return false
			;}
			;if (1 == criterion[line - 1][5])
			{
				;return true
			;}else
			{
				;return false
			;}
		;}else
		{
			;line = criterion[line - 1][temp]
			;++index
		;}
	;}
	;if (0 == line)
	{
		;cout<<"You give me too many "<<exp[index]<<" at the "<<index+1<<" place !"<<endl
		;return false
	;}else if(1 == criterion[line - 1][5])
	{
		;return true
	;}
	;return false
;}

//转义用户输入的字符
;char trans(char letter)
{
	;switch (letter)
	{
		;case 'Z' :
		;case 'Y' :
		;case 'X' :
		;case 'W' :
		;case 'V' :
		;case 'U' :
		;case 'T' :
		;case 'S' :
		;case 'R' :
		;case 'Q' :
		;case 'P' :
		;case 'O' :
		;case 'N' :
		;case 'M' :
		;case 'L' :
		;case 'K' :
		;case 'J' :
		;case 'I' :
		;case 'H' :
		;case 'G' :
		;case 'F' :
		;case 'E' :
		;case 'D' :
		;case 'C' :
		;case 'B' :
		;case 'A' :
		;case 'z' :
		;case 'y' :
		;case 'x' :
		;case 'w' :
		;case 'v' :
		;case 'u' :
		;case 't' :
		;case 's' :
		;case 'r' :
		;case 'q' :
		;case 'p' :
		;case 'o' :
		;case 'n' :
		;case 'm' :
		;case 'l' :
		;case 'k' :
		;case 'j' :
		;case 'i' :
		;case 'h' :
		;case 'g' :
		;case 'f' :
		;case 'e' :
		;case 'd' :
		;case 'b' :
		;case 'c' :
		;case 'a' :
			;return 'g'
		;case '0' :
		;case '1' :
		;case '2' :
		;case '3' :
		;case '4' :
		;case '5' :
		;case '6' :
		;case '7' :
		;case '8' :
		;case '9' :
			;return 'g'
		;case '(' :
			;return 'm'
		;case ')' :
			;return 'n'
		;case '*' :
		;case '+' :
		;case '?' :
			;return 'a'
		;case '|' :
			;return 'l'
		;default:
			;return '\0'
	;}
	;return '\0'
;}