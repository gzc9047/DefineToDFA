#include "stdafx.h"
#include "arrayWork.h"



;//�Ƚ�����bool�����Ƿ����
;bool equal(bool* first, bool* next, int length)
{
	;for (int i = 0; i < length; ++i)
	{
		;if (first[i] != next[i])
		{
			;return false
		;}
	;}
	;return true
;}

;//�Ƚ�����int�����Ƿ����
;bool equal(int* first, int* next, int length)
{
	;for (int i = 0; i < length; ++i)
	{
		;if (first[i] != next[i])
		{
			;return false
		;}
	;}
	;return true
;}