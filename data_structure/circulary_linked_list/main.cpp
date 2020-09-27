#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>

class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode(int data){
        this->data = data;
        this->next = nullptr;
        }
        
    int getData(){
        return this->data;
        }
        
    void setNext(ListNode *next){
        this->next = next;
        }
    
    ListNode* getNext(){
        return this->next;
        }
    
    ~ListNode(){}
    };
    
class CircularyLinkedList{
private:
    ListNode *Ptr;
public:
    CircularyLinkedList(){
        this->Ptr = nullptr;
        }
        
    ListNode* getPtr(){
        return this->Ptr;
        }
        
    void insertLeft(int data){
        ListNode *newNode = new ListNode(data);
        if(this->Ptr == nullptr){
            newNode->setNext(newNode);
            this->Ptr = newNode;
            }
        else{
            newNode->setNext(this->Ptr->getNext());
            this->Ptr->setNext(newNode);
            }
        }
    
    void insertRight(int data){
        ListNode *newNode = new ListNode(data);
        if(this->Ptr == nullptr){
            newNode->setNext(newNode);
            this->Ptr = newNode;
            }
        else{
            newNode->setNext(this->Ptr->getNext());
            this->Ptr->setNext(newNode);
            this->Ptr = newNode;
            }
        }
        
    int remove(){
        if(this->Ptr == nullptr){
            throw -1;
            }
        ListNode *deletedNode = this->Ptr->getNext();
        int value = deletedNode->getData();
        this->Ptr->setNext(deletedNode->getNext());
        if(this->Ptr == deletedNode){
            this->Ptr = nullptr;
            }
        delete deletedNode;
        return value;
        }
        
    void concat(CircularyLinkedList *list){
        if(!list->isEmpty()){
            ListNode *listPtr = list->getPtr();
            if(!this->isEmpty()){
                ListNode *tmp = this->Ptr->getNext();
                this->Ptr->setNext(listPtr->getNext());
                listPtr->setNext(tmp);
                }
            }
            list = nullptr;
        }
        
    bool isEmpty(){
        return this->Ptr == nullptr;
        }
        
    ~CircularyLinkedList(){
        while(!this->isEmpty()){
            this->remove();
            }
        }
    };

int main(int argc, char **argv)
{
	CircularyLinkedList *list = new CircularyLinkedList;
    try{
        list->remove();
        }
    catch(int exc){
        std::cout << "list is empty." << std::endl;
        }
    
    list->insertLeft(1);
    list->insertLeft(2);
    list->insertLeft(3);
    delete list;
    
    CircularyLinkedList *list1 = new CircularyLinkedList;
    list1->insertLeft(1);
    list1->insertLeft(2);
    list1->insertLeft(3);
    CircularyLinkedList *list2 = new CircularyLinkedList;
    list2->insertLeft(4);
    list2->insertLeft(5);
    list2->insertLeft(6);
    list1->concat(list2);
    
    while(!list1->isEmpty()){
        int value = list1->remove();
        std::cout << value << " ";
        }
        std::cout << std::endl;
    delete list1;
    
    list = new CircularyLinkedList;
    list->insertLeft(1);
    list->insertLeft(2);
    list->insertLeft(3);
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> uid_prob(0, 1);
    int i = 4;
    while(!list->isEmpty()){
        double probability = uid_prob(gen);
        if(probability <= 0.25){
            list->insertLeft(i);
            std::cout << i << "insert left to list." << std::endl;
            i++;
            }
        if(probability > 0.25 && probability <= 0.5){
            list->insertRight(i);
            std::cout << i << "insert right to list" << std::endl;
            i++;
            }
        if(probability > 0.50){
            int value = list->remove();
            std::cout << "Value " << value << " remove from list" << std::endl;
            }
        }
	return 0;
}
