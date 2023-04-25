#pragma once
#include "RepoProduse.h"
#include <iostream>

using std::string;


template <typename T> class IteratorVector;


template <typename T> class ListaRepo {
	
	int lungime;
	int capacitate;
	T* elemente;

	void ensure_capacity();

public:

	ListaRepo();

	ListaRepo(const ListaRepo<T>& ot);
	
	~ListaRepo();

	ListaRepo& operator=(const ListaRepo& ot);

	int len() const noexcept;

	T& get(int poz) const;
	void set(int poz, const T& element);

	const T* cauta(const string& nume)const;
	
	void push_back(const T& element);
	void erase(int begin, int end);
	void remove(int poz);

	void modify(const string& nume, const T& other);
	void set(int poz, const T* elem);

	friend class IteratorVector<T>;
	IteratorVector<T> begin() const ;
	IteratorVector<T> end() const ;
};

template <typename T> ListaRepo<T>::ListaRepo()
{
	capacitate = 2;
	lungime = 0;
	elemente = new T[2];
}

template <typename T> ListaRepo<T>::ListaRepo(const ListaRepo<T>& ot)
{
	delete[] elemente;
	elemente = new T[ot.capacitate];
	for (int i = 0; i < ot.lungime; i++)
	{
		elemente[i] = ot.elemente[i];
	}
	capacitate = ot.capacitate;
	lungime = ot.lungime;
}

template <typename T> ListaRepo<T>::~ListaRepo()
{
	delete[] elemente;
}

template <typename T> ListaRepo<T>& ListaRepo<T>::operator=(const ListaRepo<T>& ot)
{
	if (this == &ot)
	{
		return *this;
	}
	for (int i = 0; i < ot.lungime; i++)
	{
		elemente[i] = ot.elemente[i];
	}
	capacitate = ot.capacitate;
	lungime = ot.lungime;
}

template <typename T> void ListaRepo<T>::ensure_capacity()
{
	if (lungime < capacitate)
		return;
	auto* elementeNoi = new T[capacitate * 2];
	for (int i = 0; i < lungime; i++)
	{
		elementeNoi[i] = elemente[i];
	}
	delete[] elemente;
	elemente = elementeNoi;
	capacitate *= 2;
}

template <typename T> void ListaRepo<T>::push_back(const T& element) 
{
	ensure_capacity();
	elemente[lungime++] = element;
}

template <typename T> T& ListaRepo<T>::get(int poz) const {
	return elemente[poz];
}

template <typename T> void ListaRepo<T>::set(int poz, const T& element)
{
	elemente[poz] = element;
}

template <typename T> int ListaRepo<T>::len() const noexcept{
	return lungime;
}

template <typename T> void ListaRepo<T>::erase(int begin, int end)
{
	if (begin < 0 || end > lungime || begin > end)
	{
		return;
	}
	for (int i = begin; i < end; i++)
	{
		elemente[i] = elemente[i + end - begin];
	}
	lungime -= (end - begin);
}



template <typename T> IteratorVector<T> ListaRepo<T>::begin() const
{
	return IteratorVector<T>(*this);
}

template <typename T> IteratorVector<T> ListaRepo<T>::end() const
{
	return IteratorVector<T>(*this, lungime);
}

template <typename T> class IteratorVector 
{
	const ListaRepo<T>& vector;
	int pozitie = 0;

public:
	IteratorVector(const ListaRepo<T>& vector) noexcept;
	
	IteratorVector(const ListaRepo<T>& vector, int poz) noexcept;

	bool valid() const;

	T& element() const;

	void next();

	T& operator*();

	IteratorVector& operator++();

	bool operator==(const IteratorVector<T>& other) noexcept;

	bool operator!=(const IteratorVector<T>& other) noexcept;
};

template <typename T> IteratorVector<T>::IteratorVector(const ListaRepo<T> &vector) noexcept:vector{ vector }, pozitie{ 0 }{}

template <typename T> IteratorVector<T>::IteratorVector(const ListaRepo<T> &vector, int poz) noexcept : vector{ vector }, pozitie{ poz } {}

template <typename T> bool IteratorVector<T>::valid() const {
	return pozitie < vector.lungime;
}

template <typename T> T& IteratorVector<T>::element() const {
	return vector.elemente[pozitie];
}

template <typename T> void IteratorVector<T>::next()
{
	pozitie++;
}

template <typename T> T& IteratorVector<T>::operator*()
{
	return element();
}

template <typename T> IteratorVector<T>& IteratorVector<T>::operator++()
{
	next();
	return *this;
}

template <typename T> bool IteratorVector<T>::operator==(const IteratorVector<T>& other) noexcept 
{
	return pozitie == other.pozitie;
}

template <typename T> bool IteratorVector<T>::operator!=(const IteratorVector<T>& other) noexcept
{
	return !(*this == other);
}

