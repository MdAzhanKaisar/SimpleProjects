#include "ObjectFns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#pragma warning(push)
#pragma warning(disable : 4996) // Disables the C4996 'unsafe' warning




Object* objectMaker() {
	Object* obj = (Object*)calloc(1, sizeof(Object));
	if (obj == NULL) { return NULL; }
	obj->is_marked = false;
	return obj;
}



/*
//stuff for making objects
object* new_int(int data) {
	object* obj = new_object();
	if (obj == NULL) { return NULL; }
	(obj->data).v_int = data;
	obj->kind = INTEGER;
	return obj;
}


object* new_float(float data) {
	object* obj = new_object();
	if (obj == NULL) { return NULL; }
	(obj->data).v_float = data;
	obj->kind = FLOAT;
	return obj;
}

object* new_string(char* data) {
	object* obj = new_object();
	if (obj == NULL) { return NULL; }
	(obj->data).v_string = (char*)calloc(1, strlen(data) + 1);
	if (obj->data.v_string == NULL) { free(obj); return NULL; }
	strncpy((obj->data).v_string, data, strlen(data) + 1);
	(obj->data).v_string[strlen(data)] = '\0';
	obj->kind = STRING;
	return obj;
}

object* new_vector3(object* x, object* y, object* z) {
	if (x == NULL || y == NULL || z == NULL) { return NULL; }
	object* obj = new_object();
	if (obj == NULL) { return NULL; }
	obj->kind = VECTOR3;
	refcount_inc(x);	refcount_inc(y);	refcount_inc(z);
	obj->data.v_vector3 = (vector3){ .x = x , .y = y , .z = z };
	return obj;
}

object* new_array(size_t size) {

	object* obj = new_object();
	if (obj == NULL) { return NULL; }
	obj->kind = ARRAY;
	obj->data.v_array = (array){
		.size = size,
		.elements = (object**)calloc(size, sizeof(object*))
	};
	if (obj->data.v_array.elements == NULL) { return NULL; }
	return obj;
}

bool array_set(object* obj, size_t index, object* value) {
	if (obj == NULL || value == NULL || obj->kind != ARRAY || index >= obj->data.v_array.size || index < 0) { return false; }
	if (obj->data.v_array.elements[index] != NULL) { refcount_dec(obj->data.v_array.elements[index]); }
	obj->data.v_array.elements[index] = value;
	refcount_inc(value);
	return true;
}

object* array_get(object* obj, size_t index) {
	if (obj == NULL || obj->kind != ARRAY || index >= obj->data.v_array.size || index < 0) { return NULL; }
	return obj->data.v_array.elements[index];
}

int length(object* obj) {
	if (obj == NULL) { return -1; }
	switch (obj->kind) {
	case INTEGER:
	case FLOAT:
		return 1;
	case STRING:
		return strlen(obj->data.v_string) + 1;
	case VECTOR3:
		return 3;
	case ARRAY:
		return obj->data.v_array.size;
	default:
		return -1;
	}
}


object* add(object* A, object* B) {
	if (A == NULL || B == NULL) { return NULL; }
	objectData AD = A->data, BD = B->data;
	objectKind BK = B->kind;
	switch (A->kind) {
	case INTEGER:
		if (BK == INTEGER) { return new_int(AD.v_int + BD.v_int); }
		else if (BK == FLOAT) { return new_float((float)((float)AD.v_int + BD.v_float)); }
		else { return NULL; }
	case FLOAT:
		if (BK == INTEGER) { return new_float((float)(AD.v_float + (float)BD.v_int)); }
		else if (BK == FLOAT) { return new_float((float)(AD.v_float + BD.v_float)); }
		else { return NULL; }
	case STRING:
		if (BK == STRING) {
			char* str = (char*)calloc(strlen(AD.v_string) + strlen(AD.v_string) + 1, sizeof(char));
			if (str == NULL) { return NULL; }
			strncpy(str, AD.v_string, strlen(AD.v_string));
			strncpy(str + strlen(AD.v_string), BD.v_string, strlen(BD.v_string));
			str[strlen(AD.v_string) + strlen(AD.v_string)] = '\0';
			object* obj = new_string(str);
			free(str);
			return obj;
		}
		else { return NULL; }
	case VECTOR3:
		if (BK == VECTOR3) {
			return new_vector3(
				add(AD.v_vector3.x, BD.v_vector3.x),
				add(AD.v_vector3.y, BD.v_vector3.y),
				add(AD.v_vector3.z, BD.v_vector3.z)
			);
		}
		else { return NULL; }
	case ARRAY:
		if (BK == ARRAY) {
			object* arr = new_array(AD.v_array.size + BD.v_array.size);
			for (int i = 0;i < AD.v_array.size;i++) {
				arr->data.v_array.elements[i] = AD.v_array.elements[i];
			}
			for (int i = 0;i < BD.v_array.size;i++) {
				arr->data.v_array.elements[i + AD.v_array.size] = AD.v_array.elements[i];
			}
			return arr;
		}
		else { return NULL; }
	default: return NULL;
	}


}













*/























































#pragma warning(pop)






