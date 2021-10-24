#include "MyString.h"

istream& operator>>(istream& inStr, MyString& s)
{
	char* tmp = new char[100];
	inStr >> tmp;

	s.size = strlen(tmp);

	s.str = new char[s.size + 1];

	strcpy_s(s.str, s.size + 1, tmp);


	delete[] tmp;
	tmp = NULL;

	return inStr;
}

ostream& operator<<(ostream& outStr, const MyString& s)
{
	outStr << s.str;
	return outStr;
}


char* MyString::operator +(const MyString& s2) {

	char* tmp = new char[size + s2.size + 1];

	for (int i = 0; i < strlen(str);i++)
		tmp[i] = str[i];
	for (int i = 0;i < strlen(s2.str); i++)
		tmp[strlen(str) + i] = s2.str[i];

	tmp[strlen(str) + strlen(s2.str)] = '\0';

	return tmp;
}

char* MyString::operator+(const char* s)
{
	int len = strlen(s) + this->size + 1;
	int j = this->size;
	char* temp = new char[len];

	temp = this->subString(0, this->size);

	for (int i = 0; i < strlen(s); i++) {
		temp[j++] = s[i];
	}

	temp[j] = '\0';
	return temp;
}

char* operator+(const char* s, const MyString& mystr)
{
	int len = strlen(s) + mystr.size + 1;
	int j = strlen(s);
	char* tmp = new char[len];

	strcpy_s(tmp, j + 1, s);

	for (int i = 0; i < mystr.size + 1; i++) {
		tmp[j++] = mystr.str[i];
	}
	tmp[j] = '\0';

	return tmp;
}

int MyString::length()
{
	return this->size;
}


char* MyString::subString(const int& start, const int& count)
{
	if (start < 0 || start >= size || count < 0)
		return NULL;

	int len = count + 1;
	char* tmp = new char[len];
	int sizeStr = 0;

	for (int i = start; i < start + count && i < size; i++)
		tmp[sizeStr++] = this->str[i];

	tmp[sizeStr] = '\0';

	return tmp;
}



char* MyString::insert(const int& idx, const char* s) {

	char* tmp = new char[size + strlen(s) + 1];

	if (idx < 0 || idx > size)
		return NULL;

	for (int i = 0; i < idx; i++)
		tmp[i] = str[i];

	for (int i = 0; i < strlen(s); i++)
		tmp[i + idx] = s[i];

	for (int i = idx; i <= size; i++)
		tmp[i + strlen(s)] = str[i];

	return tmp;
}

char* MyString::erase(const int& start, const int& count)
{
	if (start < 0) return NULL;

	if (start < this->size) {
		char* tmp = this->subString(0, start);

		if (start + count < this->size) {			//Check the number of elements is deleted
			int i = start + count;
			int j = start;
			for (; i < this->size; i++, j++)
				tmp[j] = this->str[i];
			tmp[j] = '\0';
		}
		return tmp;
	}
	return this->str;
}


char* MyString::replace(const int& start, const int& length, const char* s2)
{
	if (start > this->size || start < 0) return NULL;

	char* tmp = this->insert(start, s2);
	int dis = start + length;

	if (start < this->size && dis < strlen(tmp)) {			 //Check the number of elements is replaced
		int len = strlen(s2), i = start + len;

		for (int j = 0;; i++, j++) {
			if (tmp[i + length] == NULL) break;
			tmp[i] = tmp[i + length];
		}

		tmp[i] = '\0';
	}
	else if (dis >= strlen(tmp)) {
		tmp[start + strlen(s2)] = '\0';
	}

	return tmp;
}

// KMP algorithm
// Function initialize KMP table
void MyString::init_KMP(char* sub, int* KMP)
{
	int i = 0, j = -1;
	KMP[0] = -1;
	int n = strlen(sub);
	while (i < n - 1) {
		if (j == -1 || sub[i] == sub[j]) {
			i++;
			j++;
			if (sub[i] != sub[j])
				KMP[i] = j;
			else KMP[i] = KMP[j];
		}
		else j = KMP[j];
	}
}
bool MyString::find(const int& idx, const char* sub)
{
	int i = idx, j = 0;
	int* KMP = new int[size];
	init_KMP(str, KMP);
	while (i + j < size) {
		if (str[i + j] == sub[j]) {
			j++;
			if (j == strlen(sub))
				return true;
		}
		else {
			i = i + j - KMP[j];
			if (j > 0)
				j = KMP[j];
		}
	}
	delete KMP;
	KMP = NULL;

	return false;
}