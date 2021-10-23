#include "PriorityQueue.h"


class IPriorityQueue{
public:

    virtual ~PriorityQueue() = default;
	virtual void enqueue(T dato);
	virtual T dequeue();
	virtual void eliminar(int pos)

};
#endif //MY_PROJECT_NAME_IMAQUINAVENDEDORA_H
