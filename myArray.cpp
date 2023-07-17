// myArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myArray.hpp"
#include <iostream>
#include <string>
using namespace std;

void printIntArray(myArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); ++i)
	{
		cout << arr[i] << endl;
	}
}

// 测试 int
void test01() {
	myArray<int> arr1(5);
	// 利用尾插法向数组中插入元素
	for (int i = 0; i < 5; ++i)
	{
		arr1.Push_Back(i);
	}
	// 打印数组元素
	printIntArray(arr1);
	cout << "arr1的容量： " << arr1.getCapacity() << endl;
	cout << "arr1的大小： " << arr1.getSize() << endl;

	myArray<int>arr2(arr1);
	// 尾删
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "尾删后：" << endl;
	cout << "arr2的容量： " << arr2.getCapacity() << endl;
	cout << "arr2的大小： " << arr2.getSize() << endl;
	printIntArray(arr2);
}

// 测试自定义数据类型
class Person {
public:
	Person(){}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPeersonArray(myArray<Person>& p) {
	for (int i = 0; i < p.getSize(); ++i)
	{
		cout << "姓名： " << p[i].m_Name << ' ' << "年龄： " << p[i].m_Age << endl;
	}
}
void test02() {
	myArray<Person> arr3(10);
	Person p1("元芳", 28);
	Person p2("张飞", 8);
	Person p3("诸葛亮", 2);
	Person p4("关羽", 64);
	Person p5("貂蝉", 58);
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	arr3.Push_Back(p4);
	arr3.Push_Back(p5);
	printPeersonArray(arr3);
	cout << "arr3的容量： " << arr3.getCapacity() << endl;
	cout << "arr3的大小： " << arr3.getSize() << endl;

}
int main()
{
	test02();
    return 0;
}

