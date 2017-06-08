#include<assert.h>
#include<string.h>
#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

namespace qh
{
	template<class T>
	class vector {
	public:
		//ctor
		vector()
			: data_(NULL), size_(0), capacity_(0)
		{
		}

		explicit vector(size_t n, const T& value = T())
		{
			data_ = new T[n];
			size_ = n;
			capacity_ = n;
			for (size_t i = 0; i < n; i++)
			{
				data_[i] = value;
			}
		}

		vector<T>& operator=(const vector<T>& rhs)
		{
			if (this != &rhs)
			{
				delete[] data_;
				size_ = rhs.size_;
				capacity_ = rhs.capacity_;
				data_ = new T[size_];
				for (int i = 0; i < size_; i++)
				{
					data_[i] = rhs.data_[i];
				}
			}
			return *this;
			//data_ = rhs.data_;
			//size_ = rhs.size_;
		}

		//dtor
		~vector()
		{
			if (data_)
			{
				delete data_;
			}
		}

		//get
		size_t size() const
		{
			return size_;
		}

		// set & get
		T& operator[](size_t index)
		{
			if (index >= 0 && index < size_)
			{
				return data_[index];
			}
			assert(false);
		}

		// set
		void push_back(const T& element)
		{
			if (size_ == capacity_)
			{
				reserve(capacity_ == 0 ? 1 : 2 * capacity_);
			}
			data_[size_++] = element;
		}
		void pop_back()
		{
			assert(size_ > 0);
			size_--;
		}
		void resize(size_t newSize)
		{
			if (newSize > capacity_)
			{
				reserve(newSize * 2);
			}
			size_ = newSize;
		}
		void reserve(size_t newCapacity)
		{
			if (newCapacity >= size_)
			{
				T *oldData_ = data_;
				data_ = new T[newCapacity];
				for (int i = 0; i < size_; i++)
				{
					data_[i] = oldData_[i];
				}
				capacity_ = newCapacity;
				delete[] oldData_;
			}
		}
		void clear()
		{
			for (int i = 0; i < size_; i++)
			{
				memset(data_ + i, 0, sizeof(T));
			}
			size_ = 0;
		}
		bool empty()
		{
			return size_ == 0;
		}

	private:
		T*      data_;
		size_t  size_;
		size_t	capacity_;
	};
}

#endif



