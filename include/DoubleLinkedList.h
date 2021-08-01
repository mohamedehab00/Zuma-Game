#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <bits/stdc++.h>
using namespace std;

class DoubleLinkedList
{
public:
    struct node
    {
        char data;
        node* prev;
        node* next;
    };

    node* head;
    node* tail;

    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_begin(char new_data)
    {
        // allocate new node and put it's data
        node* new_node = new node();
        new_node->data = new_data;
        // check if the linked list is empty
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        // otherwise insert the new node in the begin of the linked list
        else
        {
            // set next of the new node to be the head and vice versa
            new_node->next = head;
            head->prev = new_node;
            // set the new node as a head
            head = new_node;
        }
    }

    // This function inserts a node at the end of the linked list
    void insert_end(char new_data)
    {
        // allocate new node and put it's data
        node* new_node = new node();
        new_node->data = new_data;
        // check if the linked list is empty
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        // otherwise reach the end of the linked list
        else
        {
            // set the next of the last node to be the new node and vice versa
            tail->next = new_node;
            new_node->prev = tail;
            // set the new node as a tail
            tail = new_node;
        }
    }

    // This function require a node to add the new node after it in the linked list
    void insert_node(node* prev_node, char new_data)
    {
        // check if the given prev node is NULL
        if (prev_node == NULL)
            return;
        // allocate new node and put it's data
        node* new_node = new node();
        new_node->data = new_data;
        // set the next of the new node to be the next of the prev node and vice versa
        new_node->next = prev_node->next;
        // check if the prev node is not the last node in the linked list
        if (prev_node->next != NULL)
            prev_node->next->prev = new_node;
        // move the next of the prev node to be the new node and vice versa
        prev_node->next = new_node;
        new_node->prev = prev_node;
    }

    // This function deletes the first node in the linked list
    void delete_begin()
    {
        // check if the linked list is empty
        if (head == NULL)
            return;
        // get the node which it will be deleted
        node* temp_node = head;
        // check if the linked list has only one node
        if (head == tail)
        {
            // delete the temp node
            delete(temp_node);
            head = NULL;
            tail = NULL;
        }
        // otherwise the linked list has nodes more than one
        else
        {
            // shift the head to be the next node
            head = head->next;
            head->prev = NULL;
            // delete the temp node
            delete(temp_node);
        }
    }

    // This function deletes the last node in the linked list
    void delete_end()
    {
        // check if the linked list is empty
        if (head == NULL)
            return;
        // get the node which it will be deleted
        node* temp_node = tail;
        // check if the linked list has only one node
        if (head == tail)
        {
            // delete the temp node
            delete(temp_node);
            head = NULL;
            tail = NULL;
        }
        // otherwise the linked list has nodes more than one
        else
        {
            // jump the deleted node
            tail = tail->prev;
            tail->next = NULL;
            // delete the node which selected
            delete(temp_node);
        }
    }

    // This function require a node to delete the node after it in the linked list
    void deleteNode( node* del)
    {
        /* base case */
        if (head == NULL || del == NULL)
            return;

        /* If node to be deleted is head node */
        if (head == del)
            head = del->next;

        /* Change next only if node to be
        deleted is NOT the last node */
        if (del->next != NULL)
            del->next->prev = del->prev;

        /* Change prev only if node to be
        deleted is NOT the first node */
        if (del->prev != NULL)
            del->prev->next = del->next;

        /* Finally, free the memory occupied by del*/
        free(del);
        return;
    }

    // This function searches for a node in the linked list
    bool search_node(int key)
    {
        // iterate on the nodes till reach the last node in the linked list
        node* curr = head;
        while (curr != NULL)
        {
            // check if the given key exists in the linked list
            if (curr->data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // This function prints the contents of the linked list
    void print_linked_list()
    {
        // print the data nodes starting from head till reach the last node
        node* curr = head;
        while (curr != NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
    }

    // This function prints the contents of the linked list
    void print_linked_list_reverse()
    {
        // print the data nodes starting from tail till reach the first node
        node* curr = tail;
        while (curr != NULL)
        {
            cout << curr->data << ' ';
            curr = curr->prev;
        }
    }

    //Count number of nodes in list by iterative/recursive way
    int count_nodes()
    {
        if(head == NULL)
        {
            return 0;
        }

        node* curr = head;

        int nodes = 0;

        while(curr != NULL)
        {
            curr = curr->next;
            nodes++;
        }
        return nodes;
    }
    void print_element_idx(int idx)
    {
        if(head == NULL)
        {
            cout<< "Empty List!!!"<<endl;
        }
        else
        {
            if(idx == 0)
            {
                cout<<head->data;
            }
            else
            {
                node* curr = head;
                int i = 0;
                while(i<idx)
                {
                    curr = curr->next;
                    i+=1;
                }
                cout<<curr->data;
            }
        }
    }
    void deleteAllNodes()
    {
        node* temp_node = tail;
        if (head == tail)
        {
            delete_begin();
        }
        else
        {

            while(count_nodes() != 0)
            {

                delete_end();
            }


        }

    }
    node* get_element_idx(int idx)
    {
        if(head == NULL)
        {
            return NULL;
        }

        if(idx == 0)
        {
            return head;
        }
        else
        {
            node* curr = head;
            int i = 0;
            while(i < idx)
            {
                curr = curr->next;
                i+=1;
            }
            return curr;
        }
    }
    void delete_corresponding(int idx)
    {
        int cell_equal;
        int temp_idx = idx;


        if(idx == 0)
        {
            cell_equal = 0;
            node* curr = head;
            char new_data = curr->data;
            while(curr != NULL && curr->data == new_data )
            {
                cell_equal+=1;
                curr = curr->next;
            }
        }
        else if(idx == count_nodes()-1)
        {

            cell_equal = 0;
            node* curr = tail;
            char new_data = curr->data;
            while(curr != NULL && curr->data == new_data)
            {
                cell_equal+=1;
                if(curr->prev->data == new_data){
                    temp_idx -= 1;
                }
                curr = curr->prev;
            }

        }
        else
        {
            cell_equal = 0;
            node* curr = get_element_idx(idx);
            char new_data = curr->data;
            while(curr != NULL && curr->data == new_data )
            {
                cell_equal+=1;
                curr = curr->next;
            }


            curr = get_element_idx(idx);
            while(curr != NULL && curr->data == new_data)
            {

                if(curr->prev->data == new_data){
                    cell_equal+=1;
                    temp_idx -= 1;
                }
                curr = curr->prev;
            }

        }

        if(cell_equal >= 3)
        {
            if(temp_idx == 0)
            {
                while(cell_equal>0)
                {
                    delete_begin();
                    cell_equal-=1;
                }
            }
            else
            {

                node* curr = get_element_idx(temp_idx);
                char col = curr->data;
                while(cell_equal>0)
                {
                    if(curr->next == NULL)
                    {
                        delete_end();
                    }
                    else
                    {
                        node* temp = curr;
                        curr = curr->next;
                        deleteNode(temp);
                    }
                    cell_equal-=1;
                }
            }

        }

    }
};

#endif // DOUBLELINKEDLIST_H
