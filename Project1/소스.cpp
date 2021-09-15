#include <iostream>

using namespace std;

void call_by_value(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void call_by_address(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void call_by_reference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	call_by_value(a, b);
	cout << "<call by value>" << endl;
	cout << "a : " << a << ", b : " << b << endl << endl;

	a = 10;
	b = 20;

	call_by_address(&a, &b);
	cout << "<call by address>" << endl;
	cout << "a : " << a << ", b : " << b << endl << endl;

	a = 10;
	b = 20;

	call_by_reference(a, b);
	cout << "<call by reference>" << endl;
	cout << "a : " << a << ", b : " << b << endl << endl;
}