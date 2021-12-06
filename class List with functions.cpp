//0301 Umnova variant 3
//L1, methods: 1-12, 14
#define There_is_overload_outputting_but_maybe_using_the_printl1_is_more_convenient
#include <stdio.h>
#include <stdexcept>
#include <iostream>

//creating formular
class List
{
private:
	class Node//L-1 list
	{
	public:
		int inf;//the information part of the beginning element
		Node* next;//the pointer to the next element
		Node(int inf, Node* next = NULL) : inf(inf), next(next) {};//constructor Node's class
		Node() {};
	};
	size_t size;//size of list
	Node* head;//the pointer of the beginning
	Node* end;//the pointer of the end
	Node* getNode(size_t index)//getting pointer to the List's Node with index
	{
		if (index <= get_size() && index >= 0)
		{
			Node* node = head;
			for (int i = 0; i < (int)index; i++)
				node = node->next;
			return node;
			node = NULL;
		}
	}

public:

	List()//constructor 1; if empty
	{
		head = NULL;
		end = NULL;
		size = 0;
	}
	List(int node)//constructor 2; if consisted of one element
	{
		Node* tmp = new Node(node);
		head = tmp;
		end = tmp;
		size = 1;
	}
	
	void news_about_delete()//comment for completed action
	{
		std::cout << "The choosen element is ready to be deleted." << std::endl;
	}
	void calling_list()//same thing
	{
		std::cout << "List: " << std::endl;
	}
	
	void push_back(int node)//add to the end
	{
		Node* temp = new Node(node);
		if (isEmpty())//empty list??
		{
			head = temp;
			end = temp;
		}
		else
		{
			end->next = temp;
			end = temp;
		}
		size++;//after adding the size increases
	}

	void push_front(int node)//add to the beginning
	{
		Node* temp = new Node(node);
		if (isEmpty())//empty??
			push_back(node);
		else
		{
			temp->next = head;
			head = temp;
		}
		size++;
	}

	void pop_back()//detele the last element
	{
		if (!isEmpty())
		{
			if (head->next == NULL)//only 1 element
			{
				Node* temp = head;
				delete temp;
				head = NULL;
				size--;
				news_about_delete();
			}
			else//more than one element
			{
				Node* first_elem = head;
				Node* next_elem = head->next;
				while (next_elem->next != NULL)//not equavelent "end"
				{
					next_elem = next_elem->next;
					first_elem = first_elem->next;
				}
				first_elem->next = NULL;//the end
				delete next_elem;//the delete element
				size--;
				news_about_delete();
			}
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	void pop_front()//delete the first element
	{
		if (!isEmpty())
		{
			if (head->next == NULL)//only 1 element
			{
				Node* temp = head;
				delete temp;
				head = NULL;
				size--;
				news_about_delete();
			}
			else//more than one element
			{
				Node* first_elem = head;
				head = head->next;
				delete first_elem;//the delete element
				size--;
				news_about_delete();
			}
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	void insert(int node_with_index, size_t index_position)//add with index (before the available element's index)
	{
		if (index_position >= 0 && index_position < get_size())
		{
			if (index_position == 0)//beginning?
				push_front(node_with_index);
			else if (index_position == get_size())//end?
				push_back(node_with_index);
			else//middle?
			{
				Node* tmp_next_elem = getNode(index_position);
				Node* temp_curr = new Node(tmp_next_elem->inf, tmp_next_elem->next);
				tmp_next_elem->inf = node_with_index;
				tmp_next_elem->next = temp_curr;
				if (end == tmp_next_elem)//seems end
					end = temp_curr;
				size++;
			}
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	int at(size_t index_position)//get the element with index
	{
		if (index_position >= 0 && index_position < get_size())
		{
			return getNode(index_position)->inf;
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	void remove(size_t index_position)//delete the element with index
	{
		if (index_position >= 0 && index_position < get_size())
		{
			if (index_position == 0)//beggin
				pop_front();
			else if (index_position == get_size() - 1)//end
				pop_back();
			else//middle 
			{
				Node* previous_the_del_tmp = getNode(index_position - 1);//before the needed element
				Node* the_del_tmp = previous_the_del_tmp->next;
				previous_the_del_tmp->next = the_del_tmp->next;
				delete the_del_tmp;
				size--;
				news_about_delete();
			}
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	size_t get_size() const {
		if (size >= 0)
			return size;
		else throw std::logic_error("Index is out of range");//unexcepted
	}

	void clear()//delete all elements
	{
		Node* current = head;
		while (head)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}

	void set(size_t index_position, int node_with_index)//replacing an element by index with the transmitted element
	{
		if (index_position >= 0 && index_position < get_size())
		{
			getNode(index_position)->inf = node_with_index;
		}
		else throw std::invalid_argument("out_of_range");//unexpected
	}

	bool isEmpty()//check the emptiness
	{
		return get_size() == 0;
	}

	There_is_overload_outputting_but_maybe_using_the_printl1_is_more_convenient;
	friend std::ostream& operator << (std::ostream& out, const List& list);//overloading the output operator

	void printl1()//the outputting result
	{
		if (isEmpty())
		{
			std::cout << "List is empty at this moment. " << std::endl;
			return;
		}
		else if (!isEmpty())
		{
			calling_list();
			Node* temp = head;
			while (temp)
			{
				std::cout << temp->inf << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	}

	void insert_14(List list, size_t starting_index_position)//inserting another list into the list starting from the index
	{
		List list_1; Node *x = list_1.getNode(starting_index_position);

	
		if (starting_index_position >= 0 && starting_index_position < get_size())
		{
			if (starting_index_position == 0)//beginning?
				list.push_front(x);
			else if (starting_index_position == get_size())//end?
				list.push_back(x);
			else//middle?
			{
				Node* tmp_next_elem = getNode(starting_index_position);
				Node* temp_curr = new Node(tmp_next_elem->inf, tmp_next_elem->next);
				tmp_next_elem->inf = x;
				tmp_next_elem->next = temp_curr;
				if (end == tmp_next_elem)//seems end
					end = temp_curr;
				size++;
			}
		}
		else throw std::invalid_argument("out_of_range");//unexpected


		
	}

	~List()//destructor
	{
		clear();
	}
};