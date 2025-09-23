#ifndef dynarray_h
#define dynarray_h

# include <iostream>
# include <assert.h>

template <class T> class DynArray {
		public:
			DynArray();
			DynArray(unsigned int size);
			DynArray(const DynArray<T>& rhs); // TO DO
			~DynArray();
			
			unsigned int size() const;
			unsigned int push_back(const T& item);
			const T& operator[](unsigned int index) const;
			T& operator[](unsigned int index);
			DynArray<T>& operator=(const DynArray<T>& rhs); // TO DO
			
		private:
			unsigned int size_;
			unsigned int capacity_;
			T* elements_;
};

template <class T> DynArray<T>::DynArray()
	: size_(0), capacity_(2), elements_(new T[2]) { 
	std::cout << "DynArray::DynArray()" << std::endl;
}

template <class T> DynArray<T>::DynArray(unsigned int size) 
	: size_((size>=1) ? size : 2), capacity_(size) {
	std::cout << "DynArray::DynArray(" << size << ")" << std::endl;
	//assert( size_ >= 0); alternative au unsigned int
	elements_ = new T[capacity_];
}

template <class T> DynArray<T>::DynArray(const DynArray<T>& rhs) 
	: size_(rhs.size_), capacity_(rhs.capacity_), elements_(new T[rhs.capacity_]) {
		std::cout << "DynArray::DynArray(DynArray&) of " << size_ << std::endl;
		for (unsigned int i=0; i < size_; ++i){
			elements_[i] = rhs.elements_[i];
		}
}

template <class T> DynArray<T>::~DynArray() {
	std::cout << "DynArray::~DynArray()" << std::endl;
	delete[] elements_;
}

template <class T> unsigned int DynArray<T>::size() const {
	std::cout << "DynArray::size()" << std::endl;
	return size_;
}

template <class T> unsigned int DynArray<T>::push_back(const T& item) {
	std::cout << "DynArray::push_back()" << std::endl;
	if (size_ == capacity_) {
		std::cout << "/ Reallocation... " << std::endl;
		capacity_ *= 2;
		T* bigger_elements = new T[capacity_];
		for(unsigned int i=0; i<size_; ++i) {
			bigger_elements[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = bigger_elements;
	}
	elements_[size_] = item;
	++size_;
	return size_ - 1;
}

template <class T> const T& DynArray<T>::operator[](unsigned int index) const {
	std::cout << "DynArray::op()" << std::endl;
	//assert(index > -1);
	assert(index < size_);
	return elements_[index];
}

template <class T> T& DynArray<T>::operator[](unsigned int index) {
	std::cout << "DynArray::op()" << std::endl;
	//assert(index > -1);
	assert(index < size_);
	return elements_[index];
}

template <class T> DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs) {
	if (this != &rhs){
		delete[] elements_;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		elements_ = new T[capacity_];
		for (unsigned int i=0; i < size_; ++i){
			elements_[i] = rhs.elements_[i];
		}
	}
	return *this;
}

#endif