#include<iostream>
#include<cassert>
using namespace std;

template <typename type>

class Vector {

private:

	int size{ 0 };
	int capacity{ 0 };
	type* array{};

	void expand_capacity() {

		capacity *= 2;
		type* arr2 = new type[capacity]{};

		// copy data from old.

		for (int i = 0; i < size; i++)
			arr2[i] = array[i];

		swap(array, arr2);
		delete[] arr2;
	}
public:

	Vector() {
		capacity = size + 10;
		array = new type[capacity]{};
	}

	Vector(int size) {
		if (size < 0)
			size = 0;
		capacity = size + 10;
		array = new type[capacity]{};
	}

	~Vector() {
		delete[] array; 
		array = nullptr; 
	}

	type back() {
		return array[size - 1];
	}

	type front() {
		return array[0];
	}

	bool Empty() {
		return size == 0;
	}

	bool Full() {
		return size == capacity;
	}

	int Size() {
		return size;
	}

	void push_back(const type& value) {
		if (size == capacity)
			expand_capacity(); // at some point will be O(N) time. 
		array[size++] = value;
	}

	type pop_back() {
		assert(!Empty());
		type back = array[size - 1];
		size--;
		return back;
	}

	void insert(const type& value, int idx) { // worst case : O(N) time.

		assert(idx >= 0 && idx < size);

		if (size == capacity)
			expand_capacity();

		for (int p = size - 1; p >= idx; p--) { // shift right.
			array[p + 1] = array[p];
		}
		array[idx] = value;
		size++;
	}

	int find(const type& value) { // O(n) time, O(1) memory.
		for (int i = 0; i < size; i++) {
			if (array[i] == value)
				return i;
		}
		return -1;
	}

	type get(int idx) {
		assert(idx >= 0 && idx < size);
		return array[idx];
	}
	type set(const type& value, int idx) {
		assert(idx >= 0 && idx < size);
		array[idx] = value;
	}

	void print() {
		cout << "[";
		for (int i = 0; i < size; i++)
		{
			cout << array[i];
			if (i != size - 1)
				cout << ", ";
		}
		cout << "]\n";
	}

	type* begin() {
		return array;
	}

	type* end() {
		return array + size;
	}
};