#include <iostream>
#include <conio.h>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque
{
private:
    Node* front;
    Node* rear;
    int count;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }

	void Push_Front(int element)
    {
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

		if ( Empty() ) {
            front = rear = tmp;
        }
		else {
            tmp->next = front;
            front->prev = tmp;
            front = tmp;
        }

        count++;
    }

	int Pop_Front()
	{
		int ret = front->data;
        Node* tmp = front;
        if ( front->next != NULL )
        {
            front = front->next;
            front->prev = NULL;
        }
        else
        {
            front = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }

	void Push_Back(int element)
	{
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

		if ( Empty() ) {
            front = rear = tmp;
        }
		else {
            rear->next = tmp;
            tmp->prev = rear;
            rear = tmp;
        }

        count++;
    }

	int Pop_Back()
	{
		int ret = rear->data;
        Node* tmp = rear;
        if ( rear->prev != NULL )
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        else
        {
            rear = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }

    int Front()
    {
        return front->data;
    }

    int Back()
    {
        return rear->data;
    }

    size_t Size() const
    {
        return count;
    }

    bool Empty()
    {
        return count == 0 ? true : false;
    }
};

int main()
{
  Deque d;
  int n, a, b;
  bool right = true;
  std::cin >> n;
  for (size_t i = 0; i < n; ++i)
  {
	std::cin >> a >> b;
	switch (a)
	{
    case 1:
	  d.Push_Front(b);
      break;
    case 2:
	  if (d.Empty())
	  {
		if (b != -1)
		{
		  right = false;
        }
      }
	  else
	  {
        int n = d.Front();
		d.Pop_Front();
		if (b != n)
		{
		  right = false;
        }
      }
      break;
    case 3:
	  d.Push_Back(b);
      break;
    case 4:
	  if (d.Empty())
	  {
		if (b != -1)
		{
		  right = false;
        }
      }
      else {
		int n = d.Back();
        d.Pop_Back();
		if (b != n)
		{
		  right = false;
        }
      }
    default:
      break;
    }
  }
  if (right)
  {
	std::cout << "YES" << std::endl;
  }
  else
  {
	std::cout << "NO" << std::endl;
  }
  getch();
  return 0;
}