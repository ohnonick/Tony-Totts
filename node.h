#ifndef NODE
#define NODE

template<class ItemType>
class Node{
	private:
		ItemType item;
		Node<ItemType>* next;

	public:
		Node();
		Node(const ItemType& newItem);
		Node(const ItemType& newItem, Node<ItemType>* newNext);
		void setItem(const ItemType& newItem);
		void setNext(Node<ItemType>* newNext);
		ItemType getItem() const;
		Node<ItemType>* getNext() const;
}; 

#include "node.cpp"
#endif