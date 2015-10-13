#pragma once
class CIntArray
{
private:
	int *_m_Array;
	int _length;
public:
	CIntArray();
	CIntArray(const CIntArray &IntArray);
	CIntArray(int *m_Array, int length);
	void InputArray();
	void OutputArray();
	CIntArray Remove();
	CIntArray Remove(int n);
	CIntArray Remove(int k, int n);
	CIntArray Replace(int old, int New);
	CIntArray AddHead(int k);
	CIntArray AddTail(int k);
	CIntArray Insert(int k, int n);
	int Max();
	int Min();
	CIntArray Ascending();
	CIntArray Descending();
	bool IsSemmetry();
	CIntArray MoveForward();
	CIntArray MoveForward(int n);
	CIntArray MoveBehind();
	CIntArray MoveBehind(int n);
	CIntArray Invert();
	int Appearance(int k);
	~CIntArray();
};

