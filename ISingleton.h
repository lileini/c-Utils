//
// Created by EPT on 2022/1/10.
//

#ifndef EPTKANZISDK_ISINGLETON_H
#define EPTKANZISDK_ISINGLETON_H
#include <mutex>

template <class T>
class ISingleton {
public:

    static T* getInstance() {
        std::lock_guard<std::recursive_mutex> lock(_mtx);

        if (_singleton == nullptr)
            _singleton = new T();

        return _singleton;
    }

    static void destroyInstance() {
        std::lock_guard<std::recursive_mutex> lock(_mtx);

        if (_singleton != nullptr)
            delete _singleton;

        _singleton = nullptr;
    }

private:
    ISingleton() {}
    virtual ~ISingleton() {}

private:
    static std::recursive_mutex _mtx;
    static T*                   _singleton;
};

template <class T>
std::recursive_mutex ISingleton<T>::_mtx;

template <class T>
T* ISingleton<T>::_singleton = nullptr;
/**
 * \brief Macro to declare ISingleton<T>
 */
#define ISINGLETON_FRIEND_CLASS(T) friend class ISingleton<T>;
#endif //EPTKANZISDK_ISINGLETON_H
