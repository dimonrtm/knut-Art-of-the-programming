#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>

class DequeNode{
private:
    int data;
    DequeNode *next;
public:
    DequeNode(int data){
        this->data = data;
        this->next = nullptr;
        }
    
    void setNext(DequeNode *nextNode){
        this->next = nextNode;
        }
    
    int getData(){
        return this->data;
        }
    
    DequeNode* getNext(){
        return this->next;
        }
        
    ~DequeNode(){}
    };
    
class LinkedDeque{
private:
    DequeNode *top;
    DequeNode *rear;
public:
    LinkedDeque(){
        this->top = this->rear = nullptr;
        }
        
    void addNodeTail(int value){
        DequeNode *newDequeNode = new DequeNode(value);
        if(this->top == nullptr){
            this->top = newDequeNode;
            this->rear = newDequeNode;
            }
        else{
            this->rear->setNext(newDequeNode);
            this->rear = newDequeNode;
            }
        }
        
    int deleteNodeTop(){
        if(this->top == nullptr){
            throw -1;
            }
        DequeNode *deletedNode = this->top;
        this->top = deletedNode->getNext();
        if(this->top == nullptr){
            this->rear = this->top;
            }
        int value = deletedNode->getData();
        delete deletedNode;
        return value;
        }
        
    void addNodeTop(int value){
        DequeNode *newDequeNode = new DequeNode(value);
        if(this->top == nullptr){
            this->top = newDequeNode;
            this->rear = newDequeNode;
            }
        else{
            newDequeNode->setNext(this->top);
            this->top = newDequeNode;
            }
        }
    
    int deleteNodeTail(){
        if(this->top == nullptr){
            throw -1;
            }
        DequeNode *currentNode = this->top;
        if(currentNode->getNext() == nullptr){
            int value = currentNode->getData();
            delete currentNode;
            this->top = this->rear = nullptr;
            return value;
        }
        while(currentNode->getNext() != this->rear){
            currentNode = currentNode->getNext();
            }
        int value = this->rear->getData();
        delete this->rear;
        this->rear = currentNode;
        currentNode->setNext(nullptr);
        return value;
        }
        
    bool isEmpty(){
        return this-> top == nullptr;
        }
        
    ~LinkedDeque(){
        while(!this->isEmpty()){
            this->deleteNodeTop();
            }
        }
    };

int main(int argc, char **argv)
{
    LinkedDeque *linkedDeque = new LinkedDeque();
    
    try{
        linkedDeque->deleteNodeTop();
        }
    catch(int exc){
        std::cout << "Queue is empty" << std::endl;
        }
        
    try{
        linkedDeque->deleteNodeTail();
        }
    catch(int exc){
        std::cout << "Queue is empty" << std::endl;
        }
        
    linkedDeque->addNodeTail(1);
    linkedDeque->addNodeTail(2);
    delete linkedDeque;
    
    linkedDeque = new LinkedDeque();
    linkedDeque->addNodeTail(1);
    linkedDeque->addNodeTail(2);
    linkedDeque->addNodeTail(3);
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> uid_prob(0, 1);
    int i = 4;
    
    while(!linkedDeque->isEmpty()){
        double probability = uid_prob(gen);
        
        if(probability <= 0.25){
            linkedDeque->addNodeTail(i);
            std::cout << "Add value " << i << " into tail queue." << std::endl;
            i++;
            }
            
        if(probability > 0.25 && probability <= 0.5){
            int value = linkedDeque->deleteNodeTop();
            std::cout << "Value " << value << " deleted from top queue." << std::endl;
            }
            
        if(probability > 0.5 && probability <= 0.75){
            linkedDeque->addNodeTop(i);
            std::cout << "Add value " << i << " into top queue." << std::endl;
            i++;
            }
            
         if(probability > 0.75){
            int value = linkedDeque->deleteNodeTail();
            std::cout << "Value " << value << " deleted from tail queue." << std::endl;
            }
        }
        
    delete linkedDeque;
	return 0;
}
