#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

template <class T>
class Container {
private:
    T* info;
    int sz;
    int cap;
public:
    Container();
    Container(unsigned int, T);
    Container(const Container&);
    ~Container();

    class iterator{
    private:
        T* p;
    public:
        iterator();
        iterator(T*);

        iterator operator++(int);
        iterator& operator++();

        iterator operator--(int);
        iterator& operator--();

        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;

        T& operator*() const;
        T* operator->() const;
    };

    class const_iterator{
        private:
            iterator iter;
        public:
            const_iterator();
            const_iterator(const iterator&);
            const_iterator(T*);

            const_iterator operator++(int);
            const_iterator& operator++();

            const_iterator operator--(int);
            const_iterator& operator--();

            bool operator==(const const_iterator&) const;
            bool operator!=(const const_iterator&) const;

            const T& operator*() const;
            const T* operator->() const;
        };

    unsigned int size() const;
    unsigned int capacity() const;

    Container<T>& operator=(const Container<T>&);

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend() const;

    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;

    void push_back(const T&);
    void pop_back();
    void erase(int);
    void erase(iterator, iterator);
    void clear();
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& c){
    for(typename Container<T>::const_iterator cit = c.begin(); cit != c.end(); cit++){
        os << *cit << std::endl;
    }
    return os;
}


/* Implementation */


template <class T>
Container<T>::Container(): info(new T[1]), cap(1), sz(0) {}

template <class T>
Container<T>::Container(unsigned int elemN, T t): info(new T[cap]), sz(elemN), cap(elemN)  {
    for(int i = 0; i<cap; i++){
        info[i] = t;
    }
}

template <class T>
Container<T>::Container(const Container& c): info(new T[cap]), sz(c.sz), cap(c.cap)  {
    for(unsigned int i = 0; i<sz; i++){
        info[i] = c.info[i];
    }
}

template <class T>
Container<T>::~Container<T>() {
    delete info;
}

template <class T>
Container<T>& Container<T>::operator=(const Container<T>& c){
    if(this!=&c){
        delete[] info;
        cap = c.cap;
        info = new T[cap];
        for(int i=0; i<sz; i++)
            info[i] = c.info[i];
    }
    return *this;
}

template <class T>
Container<T>::iterator::iterator(): p(nullptr) {}

template <class T>
Container<T>::iterator::iterator(T* t): p(t) {}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int){
    Container<T>::iterator it = *this;
    p++;
    return it;
}

template <class T>
typename Container<T>::iterator& Container<T>::iterator::operator++(){
    ++p;
    return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator--(int){
    Container<T>::iterator it = *this;
    p--;
    return it;
}

template <class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    --p;
    return *this;
}

template <class T>
bool Container<T>::iterator::operator==(const Container<T>::iterator& it) const {
    return p == it.p;
}

template <class T>
bool Container<T>::iterator::operator!=(const Container<T>::iterator& it) const {
    return p != it.p;
}

template <class T>
T& Container<T>::iterator::operator*() const {
    return *p;
}

template <class T>
T* Container<T>::iterator::operator->() const {
    return p;
}

//CONST_ITERATOR
//costruttore di default
template <class T>
Container<T>::const_iterator::const_iterator(): iter(nullptr, false) {}

//costruttore di copia
template <class T>
Container<T>::const_iterator::const_iterator(const iterator& it): iter(it) {}


template <class T>
Container<T>::const_iterator::const_iterator(T* t): iter(t) {}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int){
    Container<T>::const_iterator it = *this;
    iter++;
    return it;
}

template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++(){
    ++iter;
    return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator--(int){
    Container<T>::const_iterator it = *this;
    iter--;
    return it;
}

template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator--(){
    --iter;
    return *this;
}

template <class T>
bool Container<T>::const_iterator::operator==(const Container<T>::const_iterator& it) const {
    return iter == it.iter;
}

template <class T>
bool Container<T>::const_iterator::operator!=(const Container<T>::const_iterator& it) const {
    return iter != it.iter;
}

template <class T>
const T& Container<T>::const_iterator::operator*() const {
    return iter.operator *();
}

template <class T>
const T* Container<T>::const_iterator::operator->() const {
    return iter.operator ->();
}

template <class T>
unsigned int Container<T>::size() const { return sz; }

template <class T>
unsigned int Container<T>::capacity() const { return cap; }

template <class T>
typename Container<T>::iterator Container<T>::begin() { return info; }

template<class T>
typename Container<T>::iterator Container<T>::end() { return info+sz; }

template <class T>
typename Container<T>::const_iterator Container<T>::cbegin() const { return info; }

template<class T>
typename Container<T>::const_iterator Container<T>::cend() const { return info+sz; }

template<class T>
T& Container<T>::operator[](unsigned int i){ return info[i]; }

template<class T>
const T& Container<T>::operator[](unsigned int i) const{ return info[i]; }


template<class T>
void Container<T>::push_back(const T& t){
    if(sz==cap){
        cap*=2;
        T* aux = new T[sz];
        for(int i=0;i<sz; i++)
            aux[i]= info[i];
        delete[] info;
        info = new T[cap];
        for(int i=0;i<sz; i++)
            info[i]=aux[i];
    }
    info[sz] = t;
    sz++;
}

template<class T>
void Container<T>::pop_back(){
    if(sz>0){
        sz--;
        T* aux = new T[sz];
        for(int i=0;i<sz; i++)
            aux[i]= info[i];
        delete[] info;
        info = new T[cap];
        for(int i=0;i<sz; i++)
            info[i]=aux[i];
    }
}

template<class T>
void Container<T>::erase(int i){
    if(i==sz-1)
        pop_back();
    else if(0<=i && i<sz-1){
        for(int j=i; j<sz-1; j++)
            info[j]=info[j+1];
        pop_back();
    }
    else
        throw "index out of range";
}

template<class T>
void Container<T>::clear(){
    sz=0;
}

#endif // CONTAINER_H
