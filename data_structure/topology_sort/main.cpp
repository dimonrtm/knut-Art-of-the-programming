#include <stdio.h>

class Node{
private:
    int successor;
    Node *next;
public:
    Node(int successor){
        this->successor = successor;
        this->next = nullptr;
        }
        
    int getSuccessor(){
        return this->successor;
        }
        
    Node* getNext(){
        return this->next;
        }
    
    void setNext(Node *nextNode){
        this->next = nextNode;
        }
        
    ~Node(){}
    };
    
class SuccessorList{
private:
    int count;
    Node *top;
public:
    SuccessorList(){
        this->count = -1;
        this->top = nullptr;
        }
        
    void addSuccessor(int successor){
        Node *successorNode = new Node(successor);
        successorNode->setNext(this->top);
        this->top = successorNode;
        }
        
    void getCount(){
        return this->count;
        }
        
    int setCount(int count){
        this->count = count;
        }
        
    void incrementCount(){
        this->count++;
        }
        
    Node* getTop(){
        return this->top;
        }
        
    ~SuccessorList(){
        Node *currentNode = this->top;
        while(currentNode != nullptr){
            Node *deletedNode = currentNode;
            currentNode = currentNode->getNext();
            delete deletedNode;
            }
        }
    };
    
class TopologySorter{
private:
    SuccessorList *successors;
    int size; 
    };

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
