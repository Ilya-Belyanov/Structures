# Structures
***

Structures Line Adapter:
=====================
1. *List* - doubly linked list, have pointers to back and front position.
2. *Vector* - dinamic linear massive of elements.

Line Structures:
=====================
1. *Queue* - based on any line adapter. Type *LILO* (Last In - Last Out).
	*Examples*:
	**Queue<int> q** - default, based on **List**;
	**Queue<int, Vector> q** - based on **Vector**;
	
2. *Stack* - based on any line adapter. Type *LIFO* (Last In - First Out).
	*Examples*:
	**Stack<int> s** - default, based on **List**;
	**Stack<int, Vector> s** - based on **Vector**;

		