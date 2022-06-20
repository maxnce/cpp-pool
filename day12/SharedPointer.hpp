/*
** EPITECH PROJECT, 2022
** day12
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_
#include <map>


static std::map<void *, int> map;

template<typename T>
class SharedPointer {
    public:
        SharedPointer(T* ptr = nullptr) {
            if (ptr != nullptr) {
                if (map.count(reinterpret_cast<void *>(ptr)) == 0)
                    map[reinterpret_cast<void *>(ptr)] = 1;
                else map[reinterpret_cast<void *>(ptr)]++;
            }
            this->_ptr = ptr;
        };
        ~SharedPointer() {
            if (_ptr != nullptr) {
                if (map[reinterpret_cast<void *>(_ptr)] > 1) {
                    map[reinterpret_cast<void *>(_ptr)]--;
                    _ptr = nullptr;
                } else {
                    map.erase(reinterpret_cast<void *>(_ptr));
                    delete _ptr;
                }
            } else
            delete _ptr;
        };

        SharedPointer(const SharedPointer<T> &cpy) {
            if (_ptr != nullptr) {
                if (map[reinterpret_cast<void *>(_ptr)] > 1) {
                    map[reinterpret_cast<void *>(_ptr)]--;
                    _ptr = nullptr;
                } else {
                    map.erase(reinterpret_cast<void *>(_ptr));
                    delete _ptr;
                }
            }
            _ptr = cpy.get();
            if (_ptr != nullptr)
                map[reinterpret_cast<void *>(_ptr)]++;
        };

        SharedPointer<T> &operator=(const SharedPointer<T> &cpy) {
            if (_ptr != nullptr) {
                if (map[reinterpret_cast<void *>(_ptr)] > 1) {
                    map[reinterpret_cast<void *>(_ptr)]--;
                    _ptr = nullptr;
                } else {
                    map.erase(reinterpret_cast<void *>(_ptr));
                    delete _ptr;
                }
            }
            _ptr = cpy.get();
            if (_ptr != nullptr)
                map[reinterpret_cast<void *>(_ptr)]++;
            return *this;
        }

        SharedPointer<T> &operator=(T *ptr)  {
            if (this->_ptr) {
                if (map[reinterpret_cast<void *>(_ptr)] > 1) {
                    map[reinterpret_cast<void *>(_ptr)] -= 1;
                    _ptr = nullptr;
                } else {
                    map.erase(reinterpret_cast<void *>(ptr));
                    delete _ptr;
                }
            }
            this->_ptr = ptr;
            if (ptr != nullptr)
                map[reinterpret_cast<void *>(ptr)]++;
            return *this;
        };

        T *operator->() const {
            return _ptr;
        }

        void reset() {
            if (_ptr != nullptr) {
                if (map[reinterpret_cast<void *>(_ptr)] > 1) {
                    map[reinterpret_cast<void *>(_ptr)]--;
                    _ptr = nullptr;
                } else {
                    map.erase(reinterpret_cast<void *>(_ptr));
                    delete _ptr;
                }
            _ptr = nullptr;
            }
        };

        T *get() const {
            return _ptr;
        }

    protected:
    private:
        T *_ptr = nullptr;
};

#endif /* !SHAREDPOINTER_HPP_ */
