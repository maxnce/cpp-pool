#include "ModulList.hpp"
#include "IMonitorModule.hpp"

IMonitorModule *ListModul::getModul()
{
    return (_mod);
}
ListModul *ListModul::getNext()
{
    return (_next);
}

ListModul::ListModul()
{
    _next = NULL;
    _mod = NULL;
}

ListModul::ListModul(IMonitorModule *mod)
{
    _next = NULL;
    _mod = mod;
}
ListModul::~ListModul()
{
    //   if (_mod != NULL)
    //        delete _mod;
}
void ListModul::destroy()
{
    ListModul *it = this;
    ListModul *old = NULL;

    while (it != NULL) {
        old = it;
        it = it->_next;
        delete old;
    }
    if (old != NULL)
        delete old;
}

void ListModul::addModul(IMonitorModule *mod)
{
    ListModul *it = this;

    if (it->_mod == NULL) {
        it->_mod = mod;
        return;
    }
    while (it->_next != NULL) {
        it = it->_next;
    }
    it->_next = new ListModul();
    it->_next->_mod = mod;
}
