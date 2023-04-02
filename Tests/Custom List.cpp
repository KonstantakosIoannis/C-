#include <iostream>

template<typename T>
	struct Node {
		
		
			T data;
			Node<T>* nextPtr;
		public:
			Node(const T& info) {
				data = info;
				nextPtr = nullptr;
			}
			T getData() const {
				return data;
			}
	};


template<typename T>
class List {

	
	
private:
	Node<T>* firstPtr;
	Node<T>* lastPtr;
	Node<T>* getNewNode(const T& value) {
		return new Node<T>(value);
	}


public:
	List() {
		std::cout << "Default Constructor" << std::endl;
		firstPtr = nullptr;
		lastPtr = nullptr;

	}
	
	~List() {
		std::cout << "Destructor" << std::endl;
		if (!isEmpty()) {
			std::cout << "Destroying nodes..." << std::endl;

			Node<T>* currentPtr = firstPtr;

			while (currentPtr != nullptr) {
				currentPtr = currentPtr->nextPtr;
			}
		}
	}
	/*
	List(const List& src) {
		std::cout << "Copy Constructor" << std::endl;
		this->firstPtr = src.firstPtr;
		this->lastPtr = src.lastPtr;

	}*/

	List& operator=(const List& src) {						//In order to work properly, lists should have same sizes.
															//Otherwise, the new list will be comprised of the first k elements of the other list, where k=size of our list
		if (&src == this)return *this;
		Node<T>* currentPtr = firstPtr;
		Node<T>* currentPtr_src = src.firstPtr;
		while (currentPtr != nullptr) {
			currentPtr->data = currentPtr_src->data;
			currentPtr = currentPtr->nextPtr;
			currentPtr_src = currentPtr_src->nextPtr;
		}
		
		
	}

	T operator[] (int subscript){
		if (subscript >= 0 || subscript < this->size()) {
			Node<T>* currentPtr = firstPtr;
			int i = 0;
			while (currentPtr != nullptr && i != subscript ) {
				currentPtr = currentPtr->nextPtr;
				i++;
			}
			return currentPtr->data;					//We have reached  i=subscript-1
		}
	}

	void taks() const {							//Ascending order
		
		Node<T>* currentPtr = firstPtr;
		T* temp = new T[this->size()];
		int k = 0;
		while (currentPtr != nullptr) {
			temp[k] = currentPtr->data;
			k++;
			currentPtr = currentPtr->nextPtr;
		}
		for (int i = 0; i < k-1; i++) {
			int min = i;
			for (int j = i + 1; j < k; j++) {
				if (temp[j] < temp[i]) {
					min = j;
					T t = temp[i];
					temp[i] = temp[min];
					temp[min] = t;
				}
			}
		}
		currentPtr = firstPtr;
		int j = 0;
		while (currentPtr != nullptr) {
			currentPtr->data = temp[j];
			j++;
			currentPtr = currentPtr->nextPtr;
		}
	}
				
	void flip() {								
		Node<T>* currentPtr = firstPtr;
		T* temp = new T[this->size()];
		int i = 0;
		while (currentPtr != nullptr) {
			temp[this->size()-i-1] = currentPtr->data;
			i++;
			currentPtr = currentPtr->nextPtr;
		}
		currentPtr = firstPtr;
		int j = 0;
		while (currentPtr != nullptr) {
			currentPtr->data = temp[j];
			j++;
			currentPtr=currentPtr->nextPtr;
		}

	}

	T begin() const {
		return this->firstPtr->data;
	}
	T end()const {
		return this->lastPtr->data;
	}
	int size() const {
		int size = 0;
		if (isEmpty()) {
			return 0;
		}
		else {
			Node<T>* currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				size++;
				currentPtr = currentPtr->nextPtr;
			}
		}
		return size;
	}

	bool find(const T& value) {
		if (isEmpty()) {
			std::cout << "The list is empty" << std::endl;
			return false;
		}
		else {
			
			Node<T>* currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				
				if (currentPtr->data == value) {
					return true;
				}
				currentPtr = currentPtr->nextPtr;			
			}
			
		}
		//return false;
	}

	void replace(int pos, const T& value){
		if (pos < 0) {
			std::cout << "Position index should be greater than 0." << std::endl;
			
		}
		else if (pos > this->size()) {
			std::cout << "Position index exceeds the list's bounds" << std::endl;
			
		}
		else {
			Node<T>* currentPtr = firstPtr;
			int i = 0;
			while (currentPtr != nullptr && i != pos - 1) {
				currentPtr = currentPtr->nextPtr;
				i++;
			}
			currentPtr->data = value;				//because i=pos-1 we can replace the data at this index
		}
		

	}


	void insert_front(const T& value) {
		Node<T>* newPtr = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	void insert_back(const T& value) {
		Node<T>* newPtr = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}
	void remove_front() {
		if (isEmpty()) {
			std::cout << "The list is empty, so i can't remove anything" << std::endl;
		}
		else {
			

			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				firstPtr = firstPtr->nextPtr;
			}
		}
	}

	void remove_back() {
		if (isEmpty()) {
			std::cout << "The list is empty, so i can't remove anything" << std::endl;
		}
		else {
			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				Node<T>* currentPtr = firstPtr;
				while (currentPtr->nextPtr != lastPtr) {
					currentPtr = currentPtr->nextPtr;						
				}
				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
			}
		}
	}

	

	bool isEmpty() const {
		return firstPtr == nullptr;
	}

	void print() const {
		if (isEmpty()) {
			std::cout << "The list is empty" << std::endl;

		}
		Node<T>* currentPtr = firstPtr;
		while (currentPtr != nullptr) {
			std::cout << currentPtr->data << std::endl;
			currentPtr = currentPtr->nextPtr;
		}
	}





};












int main()
{
	std::cout << "Test 1 : " << std::endl << std::endl;

	List <int> y; 


	y.insert_back(20); 
	y.insert_back(30);
	y.insert_back(40);
	y.insert_back(50);
	y.insert_back(60);
	y.insert_back(70);
	y.insert_back(80);

	y.print();

	y.insert_front(10);
	std::cout << "---------" << std::endl;
	y.print();
	y.remove_back(); 

	y.remove_front();

	List <int> y2;
	y2.insert_back(200);
	y2.insert_back(300);
	
	//y = y + y2; // operator + (can't happen because list size is fixed. When going to add the first item of the new list, the old list points to null)
	//std::cout<<"OPERATOR+" << std::endl;
	y.print();
	List <int> y3 = y2; // copy constructor
	y3 = y;  // operator =

	std::cout << "y3 print" << std::endl;
	y3.print();

	
	

	y.flip(); 
	std::cout<<"Flip"<<std::endl;

	y.print(); 



	std::cout << "TAKS" << std::endl;
	y.taks();
	y.print();

	
	

//////////////////////////////  TEST  2  //////////////////////////

	std::cout << std::endl << "Test 2 :" << std::endl << std::endl;

	if (y.isEmpty())std::cout << "I am empty " << std::endl;  
	else
	{
		std::cout << "My size is : " << y.size() << " elements" << std::endl;  
		

		

		std::cout << "My first element is : " << y.begin() 
			<< " and my last one is : " << y.end() << std::endl; 
	}

	std::cout << "Do you have a '30' in your elements ?          ";
	if (y.find(30))std::cout << "Yes i Do!!" << std::endl;  
	else std::cout << "Sorry but NO" << std::endl;

	std::cout << "My third element is : " << y[2] << std::endl;  
	y.print();
	y.replace(3, 45);
	
	std::cout << "---------" << std::endl;
	y.print();
	if (y.isEmpty())std::cout << "I am empty " << std::endl;


}