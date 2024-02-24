#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

struct Node
{
    Node*   prev;
    Node*   next;    
    string  data;
};

struct linked_list
{
    Node* head;
    Node* end;
};

void insert_node(linked_list* list, Node* node)
{
    if (nullptr == list->head)
    {        
        list->head = node;
    }
    
    if (list->end)
    {
        list->end->next = node;        
    }
    
    node->prev = list->end;            
    list->end  = node;
}

void calculate_node(linked_list* llist, Node* node)
{
    long long prev = 0;
    long long next = 0;
    long long ret = 0;

    prev = std::atoll(node->prev->data.c_str());
    next = std::atoll(node->next->data.c_str());
    
    if (node->data == "*")
    {
        ret = prev * next;
    }
    else if (node->data == "+")
    {
        ret = prev + next;
    }
    else
    {
        ret = prev - next;
    }
    
    node->data = std::to_string(ret);
    
    Node* prevTemp = node->prev;
    Node* nextTemp = node->next;
    
    if (node->prev->prev)
    {
        node->prev->prev->next = node;
        node->prev = node->prev->prev;
    }
    if (node->next->next)
    {
        node->next->next->prev = node;
        node->next = node->next->next;
    }
    
    if (llist->head == prevTemp)
    {        
        llist->head = node;
        node->prev = nullptr;
    }
    if (llist->end == nextTemp)
    {
        llist->end = node;
        node->next = nullptr;
    }
    
    //delete prevTemp;
    //delete nextTemp;
}

void create_llist(linked_list* llist, string expression)
{
    for (int i = 0; i < expression.size(); ++i)
    {        
        string temp = "";
        while (i < expression.size())
        {            
            if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
            {
                break;
            }
            temp += expression[i];
            ++i;
        }
        if (!temp.empty())
        {
            Node* node = new Node{nullptr, nullptr, temp};
            insert_node(llist, node);            
        }
        
        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
        {                        
            Node* node = new Node{nullptr, nullptr, string(1, expression[i])};
            insert_node(llist, node);
        }
    }
}

void calculate_priority(linked_list* llist, string opers)
{            
    for (char oper : opers)
    {
        Node* node = llist->head;
        while (node)
        {
            if (node->data[0] == oper)
            {
                calculate_node(llist, node);     
            }
            node = node->next;
        }
    }
}

void delete_list(linked_list* llist)
{
    Node* node = llist->head;
    while (node)
    {
        Node* temp = node;
        node = node->next;
        delete temp;
    }    
}

long long solution(string expression) {
    long long answer = 0;    
    const char* prioritys[6] = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};
    
    for (int i = 0; i < 6; ++i)
    {
        linked_list llist = {};
        create_llist(&llist, expression);        
        calculate_priority(&llist, prioritys[i]);
        long long temp = std::atoll(llist.head->data.c_str());
        temp = abs(temp);
        if (answer < temp)
        {
            answer = temp;
        }
        //delete_list(&llist);
    }    

    return answer;
}