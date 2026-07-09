#include "StringFns.h"

//makes the struct for you.
str* strMaker(const char* s, int l ) {
	//heap allocaton for struct
	str* newStr = (str*)malloc(sizeof(str));
	if (newStr == NULL) { return NULL; }
	//if length not given
	if (l == -1) {
		l = strlen(s) + 1;
		//if no '\0' is there

	}
	//storing in str struct
	newStr->len = l;
	newStr->data = (char*)malloc(l * sizeof(char));
	strncpy(newStr->data, s,l);
	newStr->data[l - 1] = '\0';

	return newStr;
}

//concatination of two strings
str* strAdder(str* s1, str* s2) {
	//temporary variable
	char* temp = (char*)malloc(sizeof(char*) * (s1->len + s2->len - 1));
	if (temp == NULL) { return NULL; }
	//add
	strncpy(temp, s1->data, s1->len);
	strncpy(temp + (s1->len - 1), s2->data, s2->len);
	//create added str
	str* s = strMaker(temp, s1->len + s2->len -1);
	//free temporary variable
	free(temp);
	if (s == NULL) { return NULL; }
	return s;
}