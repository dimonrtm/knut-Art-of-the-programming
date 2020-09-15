#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>

class QueueNode{
private:
    int data;
    QueueNode *next;
public:
    QueueNode(int data){
        this->data = data;
        this->next = nullptr;
        }
    
    void setNext(QueueNode *nextNode){
        this->next = nextNode;
        }
    
    int getData(){
        return this->data;
        }
    
    QueueNode* getNext(){
        return this->next;
        }
        
    ~QueueNode(){}
    };
    
class LinkedQueue{
private:
    QueueNode *top;
    QueueNode *rear;
public:
    LinkedQueue(){
        this->top = this->rear = nullptr;
        }
        
    void addNode(int value){
        QueueNode *newQueueNode = new QueueNode(value);
        if(this->top == nullptr){
            this->top = newQueueNode;
            this->rear = newQueueNode;
            }
        else{
            this->rear->setNext(newQueueNode);
            this->rear = newQueueNode;
            }
        }
        
    int deleteNode(){
        if(this->top == nullptr){
            throw -1;
            }
        QueueNode *deletedNode = this->top;
        this->top = deletedNode->getNext();
        if(this->top == nullptr){
            this->rear = this->top;
            }
        int value = deletedNode->getData();
        delete deletedNode;
        return value;
        }
        
    bool isEmpty(){
        return this-> top == nullptr;
        }
        
    ~LinkedQueue(){
        while(!this->isEmpty()){
            this->deleteNode();
            }
        }
    };

int main(int argc, char **argv)
{
    LinkedQueue *linkedQueue = new LinkedQueue();
    
    try{
        linkedQueue->deleteNode();
        }
    catch(int exc){
        std::cout << "Queue is empty" << std::endl;
        }
        
    linkedQueue->addNode(1);
    linkedQueue->addNode(2);
    delete linkedQueue;
    
    linkedQueue = new LinkedQueue();
    linkedQueue->addNode(1);
    linkedQueue->addNode(2);
    linkedQueue->addNode(3);
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> uid_prob(0, 1);
    int i = 4;
    
    while(!linkedQueue->isEmpty()){
        double probability = uid_prob(gen);
        
        if(probability <= 0.50){
            linkedQueue->addNode(i);
            std::cout << "Add value " << i << " into queue." << std::endl;
            i++;
            }
            
        if(probability > 0.50){
            int value = linkedQueue->deleteNode();
            std::cout << "Value " << value << " deleted from queue." << std::endl;
            }
        }
        
    delete linkedQueue;
	return 0;
}
