#pragma once

//List of values of different data types

typedef enum DataType {
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	STRING
} DataType;

typedef struct List {
	void* data;
	DataType* type;
	int len;
} List;

//FUNCTIONS
List* listMaker(int len);


