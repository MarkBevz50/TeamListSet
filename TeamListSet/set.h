#pragma once
#include <iostream>
template<typename T>
class Set						// Ivan
{
private:
	template<typename T>
	struct Node
	{
		Node* next;
		T value;
		Node<T>(T val)
			: value(val), next(nullptr)
		{
		}
	};
	using List = Node<T>*;
	// List = Node*
	List head;
	unsigned size;
public:
	~Set();						// Artem

	Set<T>& operator=(const Set<T>&); 		// Ivan
	Set();						// Ivan
	Set(const Set<T>& S); 				// Artem
	Set(const T* iterable, unsigned iterableSize);	// Ivan
	explicit Set(const T& value);			// Ivan

	void Add(const T& value); 			// Mark
	Set<T>& operator+=(const Set<T>& S); 		// Mark
	bool Contains(const T& value) const 		// Mark
	Set<T>& Intersection(const Set<T>& S); 		// Mark
	Set<T>& Difference(const Set<T>& S);  		// Mark

	unsigned Size() const;				// Ivan

	void Print(std::ostream& os = std::cout) const; // Artem
};

template<typename T>
inline Set<T>::Set(const Set<T>& S)
	: head(nullptr), size(0)
{
	Set<T>::Node<T>* otherCurrent = S.head;
	while (otherCurrent != nullptr)
	{
		Add(otherCurrent->value);
		otherCurrent = otherCurrent->next;
	}
}

template<typename T>
inline Set<T>::Set(const T* iterable, unsigned iterableSize)
{
	head = new Set<T>::Node<T>(0);
	List futureHead = head;
	for (unsigned i = 0; i < iterableSize; ++i)
	{
		size = i;
		futureHead->next = new Set<T>::Node<T>(iterable[i]);
		futureHead = futureHead->next;
	}
	List victim = head;
	head = head->next;
	delete victim;
}

template<typename T>
inline Set<T>::Set(const T& value)
{
	head = new Set<T>::Node<T>(value);
	size = 1;
}

template<typename T>
inline unsigned Set<T>::Size() const
{
	return size;
}

template<typename T>
inline Set<T>::~Set()
{
	Set<T>::Node<T>* current = head;
	while (current != nullptr)
	{
		Set<T>::Node<T>* temp = current;
		current = current->next;
		delete[] temp;
	}
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>&)
{
	Set<T> result = new Set();
	Set<T>* prtToHead = head;
	while (prtToHead != nullptr)
	{

	}
}

template<typename T>
inline void Set<T>::Print(std::ostream& os) const
{
	if (size == 0)
	{
		os << "{ empty set }\n";
		return;
	}
	Set<T>::Node<T>* current = head;
	while (current != nullptr)
	{
		os << current->value << " ";
		current = current->next;
	}
	os << std::endl;
}

template<typename T>
inline Set<T>::Set()
	: size(0), head(nullptr)
{
}

template<typename T>
inline void Set<T>::Add(const T& value)
{
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (current->value == value) {
			continue;
		}
		current = current->next;
	}
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
	++size;
}

template<typename T>
inline Set<T>& Set<T>::Intersection(const Set<T>& S)
{
	Set<T> result;
	Node <T>* current = head;
	while (current != nullptr)
	{
		if (S.Contains(current->value))
		{
			result.Add(current->value);
		}
		current = current->next;
	}
	*this = result;
	return *this
}

template<typename T>
inline Set<T>& Set<T>::Difference(const Set<T>& S)
{
	Set<T> result;
	Node<T>* current = head;
	while (current != nullptr)
	{
		Node<T>* temp = S.head;
		while (temp != nullptr)
		{
			if (current->value != temp->value)
			{
				result.Add(temp->value)
			}
			temp = temp->next;
		}
		current = current->next;
	}
	*this = result;
	return *this;
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& S)
{
	if (this != &S)
	{
		this->~Set();
		Set<T>::Node<T>* prtToNewHead = new Set<T>::Node<T>(0);
		Set<T>::Node<T>* newHead = prtToNewHead;
		Set<T>::Node<T>* prtToOtherHead = S.head;
		while (prtToOtherHead != nullptr)
		{
			prtToNewHead->next = new Set<T>::Node<T>(prtToOtherHead->value);
			prtToNewHead = prtToNewHead->next;
			prtToOtherHead = prtToOtherHead->next;
		}
		head = newHead->next;
		delete newHead;
	}
	size = S.size;
	return *this;
}

template<typename T>
bool Set<T>::Contains(const T& value) const
{
	Node<T>* Current = head;
	while (current != nullptr)
	{
		if (Current->value = value)
		{
			return true;
		}
		Current = Current->next;
	}
	return false;
}
