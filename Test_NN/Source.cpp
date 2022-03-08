#include<iostream>


template<class T>
class Buff {
	int len;
	int write;
	T* buf;
	
public:
	Buff(int len):len { len }{
		buf = new T[len];
		write = 0;
	}

	void Write(const T& smth) {
		buf[write] = smth;
		write++;
		if (write == len)
			write = 0;
	
	}

	T operator[](int n) {
		if (n >= len||n<0)
			throw;// ������� ��� ����� ����������� 
		return buf[n];
	}

};


template<class T>
struct Elem {
	Elem* next;
	T me;
};

template<class T>
class ListBuff{
	Elem<T>* first;// ����� ������� ��������� �� ��������� �������, ��� ����� ���� ��� ���������� ������
	Elem<T>* cur;
	Elem<T>* Get;
	int size;
public:
	ListBuff(int size) :size{ size } {
		cur = new Elem<T>;
		Get = cur;
		first = cur;
		Elem<T>* tmp = first;
		for (int i = 1; i < size; i++) {
			tmp->next = new Elem<T>;
			tmp = tmp->next;
		}
		tmp->next = first;
	}

	void add_mem(int count) {
		Elem<T>* tmp = first;
		for (int i = 1; i < size + count; i++) {
			if(i>=size)
				tmp->next = new Elem<T>;
			if (i == size)
				cur = tmp;//�������� ������ �� ������ ����������� �������
			tmp = tmp->next;
		}
		tmp->next = first;
	}

	void write(const T& smth) {
		cur->me = smth;// ����� ����������� ���������� ���� ��� �� ��� ��������� (� ������� �� �������� ����� ��� � �� ������)
		cur = cur->next;
	}

	T get() {
		T gg = Get->me;
		Get = Get->next;
		return gg;
	}
};

int main() {


	
	return 0;
}