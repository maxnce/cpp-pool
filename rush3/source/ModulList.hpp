
#ifndef LIST_H
#define LIST_H
#include "IMonitorModule.hpp"


class ListModul {
public:
    ListModul();
    ListModul(IMonitorModule *mod);
    ~ListModul();
    void addModul(IMonitorModule *mod);
    void destroy();
    IMonitorModule *getModul();
    ListModul *getNext();
private:
    ListModul *_next;
    IMonitorModule *_mod;
};


#endif
