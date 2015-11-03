#include "stdafx.h"
#include "person.h"


#include<iostream>

person::person(){}
person::person(char *n, int a, char *j)
{
	strcpy_s(name, n);
	age = a;
	strcpy_s(job, j);
}

//–¼ŒŸõ
bool person::name_judge(char *n)
{
	for (int i = 0; name[i] == n[i]; i++)
	if (i + 1 == strlen(name))return true;
	return false;
}

