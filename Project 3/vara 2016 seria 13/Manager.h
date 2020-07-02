#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include <bits/stdc++.h>

class Manager
{
protected:
public:
    static Manager* instance;
    Manager();
public:
    Manager(const Manager&)=delete;
    Manager& operator=(const Manager&)=delete;
    static Manager* get_instance()
    {
        if(!instance)
            instance= new Manager;
        return instance;
    }

};


#endif // MANAGER_H_INCLUDED
