# OOP-Assignment2-M.Umer-24i5689

C++ Data Structures and Recursion Assignment
This repository contains my complete implementation of several core data structure and algorithm problems in C++. Each question demonstrates strong understanding of recursion, linked lists, queues, stacks, and object-oriented programming concepts such as inheritance, polymorphism, and operator overloading.

 Question 1: Recursion 
(a) ChangeLocation(char *Array, int b1, int b2)
•	Implemented a recursive function that swaps characters between two given indices (b1 and b2) in a character array.
•	The function continues swapping recursively until both indices meet or cross.
•	Example:
o	Input Array: { 'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R' }
o	Bounds: 3 and 7
o	Output Array: { 'C', 'O', 'E', 'P', 'U', 'T', 'M', 'R' }
Concepts used:
•	Pointer manipulation
•	Base and recursive cases
•	Array traversal through recursion
(b) PrintPattern(int &n)
•	Created a recursive function that prints a numeric pattern based on the user input.
•	The function generates repeated and decreasing numbers through recursive calls.
Example (n = 4):
4
2 2
1 3
1 1 2
1 1 1 1
Concepts used:
•	Recursive control of print sequences
•	Parameter passing by reference
•	Pattern construction logic

 
Question 2: Singly Linked List 
Designed a Singly Linked List system for managing NASA’s geospatial features such as land and water data.

 Class Structure
1.	Base Class – Feature
o	Contains a Name string attribute.
o	Declares a pure virtual function analyze() for runtime polymorphism.
2.	Derived Classes
o	LandFeature → Displays land-related analysis messages.
o	WaterFeature → Displays water-related analysis messages.
3.	SinglyLinkedList
o	insertAtEnd(int featureID, Feature* f) → Adds a feature to the end of the list.
o	deleteByID(int featureID) → Removes a node by its ID.
o	displayAll() → Traverses the list and executes each feature’s analyze() function.
o	reverseList() → Reverses the linked list iteratively.

Concepts used:
•	Inheritance and polymorphism
•	Virtual functions
•	Operator overloading
•	Dynamic memory management

Question 3: Doubly Linked List 
Implemented a Doubly Linked List to simulate a Library Management System for tracking books.

 Node Structure:
BookID (int)  Title (string)  Author (string)
 
Features Implemented:
•	Add a book:
                  At the beginning    At the end    At a specific position
•	Delete a book by BookID
•	Display all books in:
Forward order  Reverse order
Concepts used:
•	Bidirectional node links
•	Iterators and STL compatibility
•	Class encapsulation
•	Memory safety

 Question 4: Queue Implementation 
Developed a Queue system to simulate a movie theater ticket booking process.
 
Customer Structure:
•	CustomerID (int)
•	CustomerName (string)
•	TicketsRequested (int)
 
Queue Operations:
•	enqueue() → Adds a new customer to the end of the queue.
•	dequeue() → Removes the first customer once their booking is done.
•	displayQueue() → Displays all customers currently in the queue.

Concepts used:
•	FIFO (First-In, First-Out) principle
•	Dynamic memory allocation
•	Class encapsulation
•	Constructors and destructors for cleanup


Question 5: Stack & Algorithm Analysis 

Implemented two stack data structures using different approaches and analyzed their time complexity and performance.
🔹 (a) Linked List-Based Stack
•	Implemented using a singly linked list.
•	Each node stores a data element and a pointer to the next node.
•	Functions implemented:
o	push() → Inserts an element at the top.
o	pop() → Removes the top element.
o	peek() → Returns the top element without removing it.
o	isEmpty() → Checks if the stack is empty.

 (b) Array-Based Stack
•	Implemented using dynamic arrays.
•	Stack size expands when capacity is reached.
•	Functions implemented:
o	push() → Adds a new element to the top (resizes if needed).
o	pop() → Removes and returns the top element.
o	peek() → Returns the top element.
o	isFull() and isEmpty() → Stack state checks.

Algorithm Analysis

While both stack implementations carry out the same logical functions, their approaches to data management and storage differ. 

Elements are kept in a continuous block of memory in the array-based stack. Under normal circumstances, the push and pop operations take constant time, O(1); but, when the array fills up, it must resize by constructing a new array and copying all of the existing elements—a step that requires O(n) time, where n is the number of elements. Nevertheless, in the majority of situations, the average time, or amortized time, per operation is still quite near to O(1).

Each element in a linked-list-based stack is fundamentally independent (a node) and has a pointer to the one after it. Since neither push nor pop requires resizing or movement of elements, they both only modify pointer links at the top of the stack and take O(1) time. Despite having same theoretical time complexity, linked lists are actually a tiny bit slower in practice because they require dynamic memory allocation for each new node and utilize additional memory for storing pointers.

Concepts used:
•	Stack ADT principles
•	Linked list and dynamic array management
•	Algorithm efficiency comparison

