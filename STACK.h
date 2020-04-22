#include "LINK.h"

template <class T>
class Stack : public LinkedList<T>
{
	public:
		bool Delete (T &element)
		{
			if(this->first == NULL)
				return false;
			element = this->first->data;    
			Node<T>*i = this->first;
			this->first = this->first->link;
			delete i;
			this->current_size--;
			return true;
		}
};
