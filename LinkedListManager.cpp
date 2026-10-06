#include <iostream>
using namespace std;


// ==================== Singly Linked List ====================

template <typename T>
class SinglyNode
{
private:
    T data;
    SinglyNode<T>* next;

public:
    SinglyNode(T value)
    {
        data = value;
        next = nullptr;
    }

    T getData()
    {
        return data;
    }

    SinglyNode<T>* getNext()
    {
        return next;
    }

    void setNext(SinglyNode<T>* node)
    {
        next = node;
    }
};


template <typename T>
class SinglyLinkedList
{
private:
    SinglyNode<T>* head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    ~SinglyLinkedList()
    {
        while (head != nullptr)
            deleteFromStart();
    }

    void insertAtStart(T value)
    {
        SinglyNode<T>* newNode = new SinglyNode<T>(value);

        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(T value)
    {
        SinglyNode<T>* newNode = new SinglyNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        SinglyNode<T>* current = head;

        while (current->getNext() != nullptr)
            current = current->getNext();

        current->setNext(newNode);
    }

    void insertAtPosition(T value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            insertAtStart(value);
            return;
        }

        SinglyNode<T>* current = head;

        for (int i = 1; i < position - 1 && current != nullptr; i++)
            current = current->getNext();

        if (current == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        SinglyNode<T>* newNode = new SinglyNode<T>(value);

        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        SinglyNode<T>* temp = head;

        head = head->getNext();

        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        SinglyNode<T>* current = head;

        while (current->getNext()->getNext() != nullptr)
            current = current->getNext();

        delete current->getNext();

        current->setNext(nullptr);
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            deleteFromStart();
            return;
        }

        SinglyNode<T>* current = head;

        for (int i = 1; i < position - 1 && current != nullptr; i++)
            current = current->getNext();

        if (current == nullptr || current->getNext() == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        SinglyNode<T>* temp = current->getNext();

        current->setNext(temp->getNext());

        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        SinglyNode<T>* current = head;

        while (current != nullptr)
        {
            cout << current->getData() << " ";
            current = current->getNext();
        }

        cout << "\n";
    }

    void search(T value)
    {
        SinglyNode<T>* current = head;

        int position = 1;
        bool found = false;

        while (current != nullptr)
        {
            if (current->getData() == value)
            {
                cout << "Found at position " << position << "\n";
                found = true;
            }

            current = current->getNext();
            position++;
        }

        if (!found)
            cout << "Value not found.\n";
    }
};


// ==================== Doubly Linked List ====================

template <typename T>
class DoublyNode
{
private:
    T data;
    DoublyNode<T>* next;
    DoublyNode<T>* previous;

public:
    DoublyNode(T value)
    {
        data = value;
        next = nullptr;
        previous = nullptr;
    }

    T getData()
    {
        return data;
    }

    DoublyNode<T>* getNext()
    {
        return next;
    }

    DoublyNode<T>* getPrevious()
    {
        return previous;
    }

    void setNext(DoublyNode<T>* node)
    {
        next = node;
    }

    void setPrevious(DoublyNode<T>* node)
    {
        previous = node;
    }
};


template <typename T>
class DoublyLinkedList
{
private:
    DoublyNode<T>* head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    ~DoublyLinkedList()
    {
        while (head != nullptr)
            deleteFromStart();
    }

    void insertAtStart(T value)
    {
        DoublyNode<T>* newNode = new DoublyNode<T>(value);

        newNode->setNext(head);

        if (head != nullptr)
            head->setPrevious(newNode);

        head = newNode;
    }

    void insertAtEnd(T value)
    {
        DoublyNode<T>* newNode = new DoublyNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        DoublyNode<T>* current = head;

        while (current->getNext() != nullptr)
            current = current->getNext();

        current->setNext(newNode);
        newNode->setPrevious(current);
    }

    void insertAtPosition(T value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            insertAtStart(value);
            return;
        }

        DoublyNode<T>* current = head;

        for (int i = 1; i < position - 1 && current != nullptr; i++)
            current = current->getNext();

        if (current == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        DoublyNode<T>* newNode = new DoublyNode<T>(value);
        DoublyNode<T>* nextNode = current->getNext();

        newNode->setPrevious(current);
        newNode->setNext(nextNode);

        current->setNext(newNode);

        if (nextNode != nullptr)
            nextNode->setPrevious(newNode);
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        DoublyNode<T>* temp = head;

        head = head->getNext();

        if (head != nullptr)
            head->setPrevious(nullptr);

        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        DoublyNode<T>* current = head;

        while (current->getNext() != nullptr)
            current = current->getNext();

        DoublyNode<T>* previousNode = current->getPrevious();

        previousNode->setNext(nullptr);

        delete current;
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            deleteFromStart();
            return;
        }

        DoublyNode<T>* current = head;

        for (int i = 1; i < position && current != nullptr; i++)
            current = current->getNext();

        if (current == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        DoublyNode<T>* previousNode = current->getPrevious();
        DoublyNode<T>* nextNode = current->getNext();

        previousNode->setNext(nextNode);

        if (nextNode != nullptr)
            nextNode->setPrevious(previousNode);

        delete current;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        DoublyNode<T>* current = head;

        while (current != nullptr)
        {
            cout << current->getData() << " ";
            current = current->getNext();
        }

        cout << "\n";
    }

    void search(T value)
    {
        DoublyNode<T>* current = head;

        int position = 1;
        bool found = false;

        while (current != nullptr)
        {
            if (current->getData() == value)
            {
                cout << "Found at position " << position << "\n";
                found = true;
            }

            current = current->getNext();
            position++;
        }

        if (!found)
            cout << "Value not found.\n";
    }
};


// ==================== Circular Linked List ====================

template <typename T>
class CircularNode
{
private:
    T data;
    CircularNode<T>* next;

public:
    CircularNode(T value)
    {
        data = value;
        next = nullptr;
    }

    T getData()
    {
        return data;
    }

    CircularNode<T>* getNext()
    {
        return next;
    }

    void setNext(CircularNode<T>* node)
    {
        next = node;
    }
};


template <typename T>
class CircularLinkedList
{
private:
    CircularNode<T>* head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        while (head != nullptr)
            deleteFromStart();
    }

    void insertAtStart(T value)
    {
        CircularNode<T>* newNode =
            new CircularNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->setNext(head);
            return;
        }

        CircularNode<T>* last = head;

        while (last->getNext() != head)
            last = last->getNext();

        newNode->setNext(head);
        last->setNext(newNode);

        head = newNode;
    }

    void insertAtEnd(T value)
    {
        CircularNode<T>* newNode =
            new CircularNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->setNext(head);
            return;
        }

        CircularNode<T>* last = head;

        while (last->getNext() != head)
            last = last->getNext();

        last->setNext(newNode);
        newNode->setNext(head);
    }

    void insertAtPosition(T value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            insertAtStart(value);
            return;
        }

        if (head == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        CircularNode<T>* current = head;

        for (int i = 1; i < position - 1; i++)
        {
            current = current->getNext();

            if (current == head)
            {
                cout << "Invalid position.\n";
                return;
            }
        }

        CircularNode<T>* newNode =
            new CircularNode<T>(value);

        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CircularNode<T>* last = head;

        while (last->getNext() != head)
            last = last->getNext();

        CircularNode<T>* temp = head;

        head = head->getNext();
        last->setNext(head);

        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        CircularNode<T>* current = head;

        while (current->getNext()->getNext() != head)
            current = current->getNext();

        CircularNode<T>* temp = current->getNext();

        current->setNext(head);

        delete temp;
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            deleteFromStart();
            return;
        }

        CircularNode<T>* current = head;

        for (int i = 1; i < position - 1; i++)
        {
            current = current->getNext();

            if (current == head)
            {
                cout << "Invalid position.\n";
                return;
            }
        }

        CircularNode<T>* temp = current->getNext();

        if (temp == head)
        {
            cout << "Invalid position.\n";
            return;
        }

        current->setNext(temp->getNext());

        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        CircularNode<T>* current = head;

        do
        {
            cout << current->getData() << " ";
            current = current->getNext();

        } while (current != head);

        cout << "\n";
    }

    void search(T value)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        CircularNode<T>* current = head;

        int position = 1;
        bool found = false;

        do
        {
            if (current->getData() == value)
            {
                cout << "Found at position " << position << "\n";
                found = true;
            }

            current = current->getNext();
            position++;

        } while (current != head);

        if (!found)
            cout << "Value not found.\n";
    }
};


// ==================== Doubly Circular Linked List ====================

template <typename T>
class DoublyCircularNode
{
private:
    T data;
    DoublyCircularNode<T>* next;
    DoublyCircularNode<T>* previous;

public:
    DoublyCircularNode(T value)
    {
        data = value;
        next = nullptr;
        previous = nullptr;
    }

    T getData()
    {
        return data;
    }

    DoublyCircularNode<T>* getNext()
    {
        return next;
    }

    DoublyCircularNode<T>* getPrevious()
    {
        return previous;
    }

    void setNext(DoublyCircularNode<T>* node)
    {
        next = node;
    }

    void setPrevious(DoublyCircularNode<T>* node)
    {
        previous = node;
    }
};


template <typename T>
class DoublyCircularLinkedList
{
private:
    DoublyCircularNode<T>* head;

public:
    DoublyCircularLinkedList()
    {
        head = nullptr;
    }

    ~DoublyCircularLinkedList()
    {
        while (head != nullptr)
            deleteFromStart();
    }

    void insertAtStart(T value)
    {
        DoublyCircularNode<T>* newNode =
            new DoublyCircularNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;

            newNode->setNext(head);
            newNode->setPrevious(head);

            return;
        }

        DoublyCircularNode<T>* last =
            head->getPrevious();

        newNode->setNext(head);
        newNode->setPrevious(last);

        last->setNext(newNode);
        head->setPrevious(newNode);

        head = newNode;
    }

    void insertAtEnd(T value)
    {
        DoublyCircularNode<T>* newNode =
            new DoublyCircularNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;

            newNode->setNext(head);
            newNode->setPrevious(head);

            return;
        }

        DoublyCircularNode<T>* last =
            head->getPrevious();

        newNode->setNext(head);
        newNode->setPrevious(last);

        last->setNext(newNode);
        head->setPrevious(newNode);
    }

    void insertAtPosition(T value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            insertAtStart(value);
            return;
        }

        if (head == nullptr)
        {
            cout << "Invalid position.\n";
            return;
        }

        DoublyCircularNode<T>* current = head;

        for (int i = 1; i < position - 1; i++)
        {
            current = current->getNext();

            if (current == head)
            {
                cout << "Invalid position.\n";
                return;
            }
        }

        DoublyCircularNode<T>* nextNode =
            current->getNext();

        DoublyCircularNode<T>* newNode =
            new DoublyCircularNode<T>(value);

        newNode->setPrevious(current);
        newNode->setNext(nextNode);

        current->setNext(newNode);
        nextNode->setPrevious(newNode);
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        DoublyCircularNode<T>* last =
            head->getPrevious();

        DoublyCircularNode<T>* temp = head;

        head = head->getNext();

        last->setNext(head);
        head->setPrevious(last);

        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->getNext() == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        DoublyCircularNode<T>* last =
            head->getPrevious();

        DoublyCircularNode<T>* newLast =
            last->getPrevious();

        newLast->setNext(head);
        head->setPrevious(newLast);

        delete last;
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            deleteFromStart();
            return;
        }

        DoublyCircularNode<T>* current = head;

        for (int i = 1; i < position; i++)
        {
            current = current->getNext();

            if (current == head)
            {
                cout << "Invalid position.\n";
                return;
            }
        }

        DoublyCircularNode<T>* previousNode =
            current->getPrevious();

        DoublyCircularNode<T>* nextNode =
            current->getNext();

        previousNode->setNext(nextNode);
        nextNode->setPrevious(previousNode);

        delete current;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        DoublyCircularNode<T>* current = head;

        do
        {
            cout << current->getData() << " ";
            current = current->getNext();

        } while (current != head);

        cout << "\n";
    }

    void search(T value)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        DoublyCircularNode<T>* current = head;

        int position = 1;
        bool found = false;

        do
        {
            if (current->getData() == value)
            {
                cout << "Found at position " << position << "\n";
                found = true;
            }

            current = current->getNext();
            position++;

        } while (current != head);

        if (!found)
            cout << "Value not found.\n";
    }
};


// ==================== Menus ====================

template <typename T>
void singlyMenu()
{
    SinglyLinkedList<T> list;
    int choice;

    do
    {
        cout << "\n";
        cout << "        +--------------------------------+\n";
        cout << "        |       SINGLY LINKED LIST       |\n";
        cout << "        +--------------------------------+\n\n";

        cout << "        [1] Insert at Start\n";
        cout << "        [2] Insert at End\n";
        cout << "        [3] Insert at Position\n";
        cout << "\n";
        cout << "        [4] Delete from Start\n";
        cout << "        [5] Delete from End\n";
        cout << "        [6] Delete from Position\n";
        cout << "\n";
        cout << "        [7] Display List\n";
        cout << "        [8] Search Value\n";
        cout << "        [0] Back\n";
        cout << "\n";
        cout << "        >> Enter your choice: ";

        cin >> choice;

        T value;
        int position;

        switch (choice)
        {
        case 1:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 2:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "        Enter value: ";
            cin >> value;
            cout << "        Enter position: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "        Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 7:
            cout << "        List: ";
            list.display();
            break;

        case 8:
            cout << "        Enter value: ";
            cin >> value;
            list.search(value);
            break;

        case 0:
            break;

        default:
            cout << "        Invalid choice.\n";
        }

    } while (choice != 0);
}


template <typename T>
void doublyMenu()
{
    DoublyLinkedList<T> list;
    int choice;

    do
    {
        cout << "\n";
        cout << "        +--------------------------------+\n";
        cout << "        |        DOUBLY LINKED LIST      |\n";
        cout << "        +--------------------------------+\n\n";

        cout << "        [1] Insert at Start\n";
        cout << "        [2] Insert at End\n";
        cout << "        [3] Insert at Position\n";
        cout << "\n";
        cout << "        [4] Delete from Start\n";
        cout << "        [5] Delete from End\n";
        cout << "        [6] Delete from Position\n";
        cout << "\n";
        cout << "        [7] Display List\n";
        cout << "        [8] Search Value\n";
        cout << "        [0] Back\n";
        cout << "\n";
        cout << "        >> Enter your choice: ";

        cin >> choice;

        T value;
        int position;

        switch (choice)
        {
        case 1:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 2:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "        Enter value: ";
            cin >> value;
            cout << "        Enter position: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "        Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 7:
            cout << "        List: ";
            list.display();
            break;

        case 8:
            cout << "        Enter value: ";
            cin >> value;
            list.search(value);
            break;

        case 0:
            break;

        default:
            cout << "        Invalid choice.\n";
        }

    } while (choice != 0);
}


template <typename T>
void circularMenu()
{
    CircularLinkedList<T> list;
    int choice;

    do
    {
        cout << "\n";
        cout << "        +--------------------------------+\n";
        cout << "        |        CIRCULAR LINKED LIST    |\n";
        cout << "        +--------------------------------+\n\n";

        cout << "        [1] Insert at Start\n";
        cout << "        [2] Insert at End\n";
        cout << "        [3] Insert at Position\n";
        cout << "\n";
        cout << "        [4] Delete from Start\n";
        cout << "        [5] Delete from End\n";
        cout << "        [6] Delete from Position\n";
        cout << "\n";
        cout << "        [7] Display List\n";
        cout << "        [8] Search Value\n";
        cout << "        [0] Back\n";
        cout << "\n";
        cout << "        >> Enter your choice: ";

        cin >> choice;

        T value;
        int position;

        switch (choice)
        {
        case 1:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 2:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "        Enter value: ";
            cin >> value;
            cout << "        Enter position: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "        Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 7:
            cout << "        List: ";
            list.display();
            break;

        case 8:
            cout << "        Enter value: ";
            cin >> value;
            list.search(value);
            break;

        case 0:
            break;

        default:
            cout << "        Invalid choice.\n";
        }

    } while (choice != 0);
}


template <typename T>
void doublyCircularMenu()
{
    DoublyCircularLinkedList<T> list;
    int choice;

    do
    {
        cout << "\n";
        cout << "        +--------------------------------+\n";
        cout << "        |     DOUBLY CIRCULAR LIST       |\n";
        cout << "        +--------------------------------+\n\n";

        cout << "        [1] Insert at Start\n";
        cout << "        [2] Insert at End\n";
        cout << "        [3] Insert at Position\n";
        cout << "\n";
        cout << "        [4] Delete from Start\n";
        cout << "        [5] Delete from End\n";
        cout << "        [6] Delete from Position\n";
        cout << "\n";
        cout << "        [7] Display List\n";
        cout << "        [8] Search Value\n";
        cout << "        [0] Back\n";
        cout << "\n";
        cout << "        >> Enter your choice: ";

        cin >> choice;

        T value;
        int position;

        switch (choice)
        {
        case 1:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 2:
            cout << "        Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "        Enter value: ";
            cin >> value;
            cout << "        Enter position: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 4:
            list.deleteFromStart();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "        Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 7:
            cout << "        List: ";
            list.display();
            break;

        case 8:
            cout << "        Enter value: ";
            cin >> value;
            list.search(value);
            break;

        case 0:
            break;

        default:
            cout << "        Invalid choice.\n";
        }

    } while (choice != 0);
}


// ==================== Data Type Selection ====================

void selectDataType(int listType)
{
    int type;

    cout << "\n";
    cout << "        +--------------------------------+\n";
    cout << "        |         SELECT DATA TYPE       |\n";
    cout << "        +--------------------------------+\n\n";

    cout << "        [0] Integer\n";
    cout << "        [1] Float\n";
    cout << "        [2] Character\n";
    cout << "        [3] Long Integer\n";

    cout << "\n";
    cout << "        >> Enter your choice: ";

    cin >> type;

    switch (type)
    {
    case 0:
        if (listType == 1)
            singlyMenu<int>();
        else if (listType == 2)
            doublyMenu<int>();
        else if (listType == 3)
            circularMenu<int>();
        else
            doublyCircularMenu<int>();
        break;

    case 1:
        if (listType == 1)
            singlyMenu<float>();
        else if (listType == 2)
            doublyMenu<float>();
        else if (listType == 3)
            circularMenu<float>();
        else
            doublyCircularMenu<float>();
        break;

    case 2:
        if (listType == 1)
            singlyMenu<char>();
        else if (listType == 2)
            doublyMenu<char>();
        else if (listType == 3)
            circularMenu<char>();
        else
            doublyCircularMenu<char>();
        break;

    case 3:
        if (listType == 1)
            singlyMenu<long>();
        else if (listType == 2)
            doublyMenu<long>();
        else if (listType == 3)
            circularMenu<long>();
        else
            doublyCircularMenu<long>();
        break;

    default:
        cout << "        Invalid data type.\n";
    }
}


int main()
{
    int listType;

    cout << "\n";
    cout << "        +--------------------------------+\n";
    cout << "        |       LINKED LIST MANAGER      |\n";
    cout << "        +--------------------------------+\n\n";

    cout << "        Select Linked List Type\n\n";

    cout << "        [1] Singly Linked List\n";
    cout << "        [2] Doubly Linked List\n";
    cout << "        [3] Circular Linked List\n";
    cout << "        [4] Doubly Circular Linked List\n";
    cout << "        [0] Exit\n";

    cout << "\n";
    cout << "        >> Enter your choice: ";

    cin >> listType;

    if (listType == 0)
    {
        cout << "\n        Program closed.\n";
        return 0;
    }

    if (listType < 1 || listType > 4)
    {
        cout << "\n        Invalid linked list type.\n";
        return 0;
    }

    selectDataType(listType);

    cout << "\n        Program finished.\n";

    return 0;
}
