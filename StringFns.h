#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4267)

//uses a new Struct 'str'
typedef struct str {
	char* data;
	unsigned int len;
}str;
//functions
str* strMaker(const char* s, int l=-1);
str* strAdder(str* s1, str* s2);
void strFree(str* s);
