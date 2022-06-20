/*
** EPITECH PROJECT, 2022
** day12
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template<typename T>
class UniquePointer {
    public:
        UniquePointer(T* ptr = nullptr) {
            this->_ptr = ptr;
        };
        ~UniquePointer() {
            delete _ptr;
        };

        UniquePointer(const UniquePointer<T> &) = delete;
        UniquePointer<T> &operator=(const UniquePointer<T> &) = delete;
        UniquePointer<T> &operator=(T *ptr)  {
            if (this->_ptr)
                delete _ptr;
            this->_ptr = ptr;
            return *this;
        };

        T *operator->() const {
            return _ptr;
        }

        void reset() {
            if (_ptr)
                delete _ptr;
            _ptr = nullptr;
        };

        T *get() {
            return _ptr;
        }

    protected:
    private:
        T *_ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
