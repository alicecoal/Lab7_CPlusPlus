#ifndef STACK_H
#define STACK_H

class Stack
{

    struct Node{
		AnsiString data;
        int key;
        Node* next = 0;
        Node* prev = 0;

		Node( AnsiString data, int key){
            this->data = data;
            this->key = key;
        }
    };

    Node* head = 0;
    Node* tail = 0;

public:
    Stack(){

    }

	void push_back(AnsiString data,int key)
	{
		if(head == 0)
		{
			Node* node = new Node(data,key);
			head = node;
            tail = node;
            return;
        }
        Node* node = new Node(data,key);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

	void pop_back(int key)
	{
        if(head == 0)
			return;
        Node* current = head;
        while(current != 0){
            if(current->key == key){
                if(current == head){
                    if(current->next != 0){
                        delete head;
                        head = current->next;
                        head->prev = 0;
                        return;
                    }
                    delete head;
                    if(tail != 0)
                        delete tail;
                    head = 0;
                    tail = 0;
                    return;
                }
                if(current == tail){
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = 0;
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete(current);
            }
            current = current->next;
        }
    }

    int size(){
        Node* current = head;
        int ans = 0;
        while(current != 0){
            ans++;
            current = current->next;
        }
        return ans;
    }

    void clear(){
        if(head == 0)
            return;
        Node* current = head;
        while(current->next != 0){
            current = current->next;
            delete current->prev;
        }
        delete current;
        head = 0;
        tail = 0;
    }

	AnsiString print()
	{
        if(head == 0){
			return ("");
		}
		Node* current = head;
		AnsiString result = "";
		while(current != 0)
		{
			result += current->data + "(" + current->key + ")";
            current = current->next;
        }
		return result;
	}

	 AnsiString find(int key){
		if(head == 0){
			return "none";
		}
		Node* current = head;
		AnsiString result = "";
		while(current != 0){
			if(current->key == key){
				result += "Founded: " + current->data + "\n";

			}
			current = current->next;
		}
		return result;
	}

	 int findmin()
	 {
		int min = 2000000000;

		if(head == 0){
			return (min);
		}

		Node* current = head;
		while(current != 0)
		{
			if(current->key < min)
			{
				min = current->key;
			}
			current = current->next;
		}
		return min;
	}
};

#endif // STACK_H
