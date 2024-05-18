template<class ItemType>
Node<ItemType>::Node(){
	next = nullptr;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& newItem){
	item = newItem;
	next = nullptr;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& newItem, Node<ItemType>* newNext){
	item = newItem;
	next = newNext;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& newItem){
	item = newItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* newNext){
	next = newNext;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const{
	return next;
}
