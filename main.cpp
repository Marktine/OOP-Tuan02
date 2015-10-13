#include "IntArray.h"
#include <iostream>
using namespace std;
int main()
{
	CIntArray arr;
	arr.InputArray();
	arr.OutputArray();
	int k, n;
	//cout << "\nMang sau khi xoa cac phan tu giong nhau: \n";
	//arr.Remove().OutputArray();
	//int n;
	//cout << "\nNhap vao vi tri cua phan tu muon xoa: ";
	//cin >> n;
	//arr.Remove(n).OutputArray();
	cout << "\nNhap vao k: ";
	cin >> k;
	//cout << "\nNhap vao n: ";
	//cin >> n;
	cout << "\n-------------------------------------------------\n";
	/*arr.Descending().OutputArray();*/
	//if (arr.IsSemmetry() == true)
	//{
	//	cout << "\nMang doi xung.!";
	//}
	//else
	//{
	//	cout << "\nMang khong doi xung.!";
	//}
	//arr.MoveBehind(k).OutputArray();
	//arr.Invert().OutputArray();
	cout << "So lan xuat hien cua " << k << " trong mang la: " << arr.Appearance(k) << " lan.!";
	return 0;
}