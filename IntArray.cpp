#include "IntArray.h"
#include <iostream>
#include <time.h>
using namespace std;

static void AquickSort(int *a, int l, int r)
{
	srand(time(NULL));
	int key = a[l + rand() % (r - l + 1)];
	int i = l, j = r;

	while (i <= j)
	{
		while (a[i] < key) i++;
		while (a[j] > key) j--;
		if (i <= j)
		{
			if (i < j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			i++;
			j--;
		}
	}
	if (l < j) AquickSort(a, l, j);
	if (i < r) AquickSort(a, i, r);
}

static void InsertionSort(int *a, int n)
{
	for (int j = 1; j < n; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] < key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

CIntArray::CIntArray()
{
	_length = 0;
	_m_Array = new int[_length];
}

CIntArray::CIntArray(const CIntArray &IntArray)
{
	_length = IntArray._length;
	_m_Array = new int[_length];
	for (int i = 0; i < _length; i++)
	{
		_m_Array[i] = IntArray._m_Array[i];
	}
}

CIntArray::CIntArray(int *m_Array, int length)
{
	_length = length;
	_m_Array = new int[_length];
	for (int i = 0; i < _length; i++)
	{
		_m_Array[i] = m_Array[i];
	}
}

void CIntArray::InputArray()
{
	cout << "Nhap vao so phan tu: ";
	cin >> _length;
	_m_Array = new int[_length];
	for (int i = 0; i < _length; i++)
	{
		cout << "Nhap vao a[" << i << "]: ";
		cin >> _m_Array[i];
	}
}

void CIntArray::OutputArray()
{
	for (int i = 0; i < this->_length; i++)
	{
		cout << "a[" << i << "]: " << this->_m_Array[i] << endl;
	}
}

CIntArray CIntArray::Remove()
{
	CIntArray a(_m_Array, _length);
	for (int i = 0; i < a._length - 1; i++)
	{
		for (int j = i + 1; j < a._length; j++)
		{
			if (a._m_Array[i] == a._m_Array[j])
			{
				int index = j;
				for (int k = index + 1; k < a._length; k++)
				{
					a._m_Array[k - 1] = a._m_Array[k];
				}
				a._length--;
				i--;
			}
		}
	}
	return a;
}

CIntArray CIntArray::Remove(int n)
{
	for (int i = n; i < this->_length - 1; i++)
	{
		this->_m_Array[i] = this->_m_Array[i + 1];
	}
	this->_length--;
	return *this;
}

CIntArray CIntArray::Remove(int k, int n)
{
	CIntArray c(_m_Array, _length);
	for (int i = 0; i < n;i++)
	{
		c.Remove(k);
	}
	return c;
}

CIntArray CIntArray::Replace(int old, int New)
{
	for (int i = 0; i < this->_length; i++)
	{
		if (this->_m_Array[i] == old)
		{
			this->_m_Array[i] = New;
		}
	}
	return *this;
}

CIntArray CIntArray::AddHead(int k)
{
	CIntArray temp(*this);
	this->_m_Array = new int[this->_length + 1];
	this->_length++;
	this->_m_Array[0] = k;
	for (int i = 1; i < this->_length; i++)
	{
		this->_m_Array[i] = temp._m_Array[i - 1];
	}
	return *this;
}

CIntArray CIntArray::AddTail(int k)
{
	CIntArray temp(*this);
	this->_m_Array = new int[this->_length + 1];
	this->_m_Array[_length++] = k;
	for (int i = 0; i < this->_length - 1; i++)
	{
		this->_m_Array[i] = temp._m_Array[i];
	}
	return *this;
}

CIntArray CIntArray::Insert(int k, int n)
{
	if (n == 0)
	{
		this->AddHead(k);
	}
	else if (n == _length)
	{
		this->AddTail(k);
	}
	else
	{
		CIntArray temp(*this);
		this->_m_Array = new int[this->_length + 1];
		this->_length += 1;
		for (int i = 0; i < this->_length; i++)
		{
			this->_m_Array[i] = temp._m_Array[i];
		}
		for (int i = n; i < this->_length + 1; i++)
		{
			this->_m_Array[i] = temp._m_Array[i - 1];
		}
		this->_m_Array[n] = k;
	}
	return *this;
}

int CIntArray::Max()
{
	int max = this->_m_Array[0];
	for (int i = 0; i < this->_length; i++)
	{
		if (max < this->_m_Array[i])
		{
			max = this->_m_Array[i];
		}
	}
	return max;
}

int CIntArray::Min()
{
	int min = this->_m_Array[0];
	for (int i = 0; i < this->_length; i++)
	{
		if (min > this->_m_Array[i])
		{
			min = this->_m_Array[i];
		}
	}
	return min;
}

CIntArray CIntArray::Ascending()
{
	AquickSort(this->_m_Array, 0, this->_length - 1);
	return *this;
}

CIntArray CIntArray::Descending()
{
	InsertionSort(this->_m_Array, this->_length);
	return *this;
}

bool CIntArray::IsSemmetry()
{
	int i = 0;
	int j = this->_length - 1;
	while (i <= j)
	{
		if (this->_m_Array[i] != this->_m_Array[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	return true;
}

CIntArray CIntArray::MoveForward()
{
	int tmp = this->_m_Array[0];
	for (int i = 0; i < this->_length - 1; i++) this->_m_Array[i] = this->_m_Array[i + 1];
	this->_m_Array[_length - 1] = tmp;
	return *this;
}

CIntArray CIntArray::MoveForward(int k)
{
	for (int i = k; i > 0; i--)
	{
		this->MoveForward();
	}
	return *this;
}

CIntArray CIntArray::MoveBehind()
{
	int tmp = this->_m_Array[this->_length - 1];
	for (int i = this->_length - 1; i >= 0; i--)
	{
		this->_m_Array[i] = this->_m_Array[i - 1];
	}
	this->_m_Array[0] = tmp;
	return *this;
}

CIntArray CIntArray::MoveBehind(int k)
{
	for (int i = 0; i < k; i++)
	{
		this->MoveBehind();
	}
	return *this;
}

CIntArray CIntArray::Invert()
{
	for (int i = 0; i < this->_length / 2; i++)
	{
		int temp = this->_m_Array[i];
		this->_m_Array[i] = this->_m_Array[this->_length - i - 1];
		this->_m_Array[this->_length - i - 1] = temp;
	}
	return *this;
}

int CIntArray::Appearance(int k)
{
	int count = 0;
	for (int i = 0; i < this->_length; i++)
	{
		if (this->_m_Array[i] == k)
		{
			count++;
		}
	}
	return count;
}

CIntArray::~CIntArray()
{
	delete[] _m_Array;
}
