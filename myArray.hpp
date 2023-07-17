#pragma once
#include <iostream>
using namespace std;

template<class T>
class myArray {
public:
	// 有参构造
	myArray(int capacity) {
		// cout << "有参构造" << endl;
		this->my_capacity = capacity;
		this->my_size = 0;
		this->pAddress = new T[this->my_capacity];
	}
	// 拷贝构造
	myArray(const myArray& arr) {
		// cout << "拷贝构造" << endl;
		this->my_capacity = arr.my_capacity;
		this->my_size = arr.my_size;
		// this->pAddress = arr.pAddress;
		// 深拷贝
		this->pAddress = new T[arr.my_capacity];
		for (int i = 0; i < this->my_size; ++i)          // 将 arr 中的数据都拷贝过来
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	// 重载 = 防止浅拷贝问题
	myArray& operator=(myArray& arr) {
		// cout << "重载 = " << endl;
		// 先判断原来堆区是否有数据，如果有，先释放
		if (this->pAddress != nullptr) {
			delete[]this->pAddress;
			this->pAddress = nullptr;
			this->my_capacity = 0;
			this->my_size = 0;
		}
		// 深拷贝
		this->my_capacity = arr.my_capacity;
		this->my_size = arr.my_size;
		this->pAddress = new T[arr.my_capacity];
		for (int i = 0; i < this->my_size; ++i)      	// 将 arr 中的数据都拷贝过来
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	// 尾插法
	void Push_Back(const T& val) {
		if (this->my_capacity == this->my_size)
		{
			cout << "数组已满" << endl;
			return;
		}
		this->pAddress[this->my_size] = val;
		this->my_size++;
	}
	// 尾删法
	void Pop_Back() {
		if (this->my_size == 0)
		{
			cout << "数组空" << endl;
			return;
		}
		this->my_size--;
	}
	// 通过下标运算符访问数组元素（重载 [ ]）
	T& operator[](int index) {
		return this->pAddress[index];
	}
	// 返回数组容量
	int getCapacity() {
		return this->my_capacity;
	}
	// 返回数组大小
	int getSize() {
		return this->my_size;
	}
	// 析构函数
	~myArray() {
		if (this->pAddress != nullptr) {
			// cout << "析构函数" << endl;
			delete[] pAddress;
			pAddress = nullptr;
		}
	}
private:
	T* pAddress;     // 指针指向堆区开辟的真实的数组
	int my_capacity;     // 数组容量
	int my_size;     // 数组大小
};
