
#ifndef EX2_ISUBJECT_H
#define EX2_ISUBJECT_H


#include "IObserver.h"

class IObserver;
/**
 * Subject interface, will contain observers and receive updates from them.
 */
class ISubject{

public:

    /*
     * Adds a new observer.
     */
    virtual void registerObserver(IObserver* observer) = 0;

    /*
     * Removes a given observer.
     */
    virtual void unregisterObserver(IObserver* observer) = 0;

    /*
     * Notifies the observers.
     */
    virtual void notifyObserver() = 0;
};

#endif //EX2_ISUBJECT_H
