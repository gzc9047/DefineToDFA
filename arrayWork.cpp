#include "stdafx.h"
#include "arrayWork.h"



;//比较两个bool数组是否相等
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

;//比较两个int数组是否相等
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