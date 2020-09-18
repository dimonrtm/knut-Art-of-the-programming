#include <stdio.h>
#include <iostream>

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
        
    int getCount(){
        return this->count;
        }
        
    void setCount(int count){
        this->count = count;
        }
        
    void incrementCount(){
        this->count++;
        }
        
    void decrementCount(){
        this->count--;
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
public:
    TopologySorter(int size){
        this->size = size;
        this->successors = new SuccessorList[size];
        }
    
     void addRelation(int pred, int successor){
        this->successors[successor - 1].incrementCount();
        this->successors[pred - 1].addSuccessor(successor - 1);
         }

     void topologySort(){
         int rear = -1;
         int front = -1;
         int qlink0 = -1;
         int N = this->size -1;
         
         for(int k = 0; k <= N; k++){
             if(this->successors[k].getCount() == -1){
                 if(rear == -1){
                     qlink0 = k;
                     rear = k;
                     }
                 else{
                     this->successors[rear].setCount(k);
                     rear = k;
                     }
                 }
             }
          front = qlink0;
          
          while(front != -1){
              std::cout << front + 1 << " ";
              N--;
              Node *currentSuccessorNode = this->successors[front].getTop();
              while(currentSuccessorNode != nullptr){
                  this->successors[currentSuccessorNode->getSuccessor()].decrementCount();
                  if(this->successors[currentSuccessorNode->getSuccessor()].getCount() == -1){
                      this->successors[rear].setCount(currentSuccessorNode->getSuccessor());
                      rear = currentSuccessorNode->getSuccessor();
                      }
                  currentSuccessorNode = currentSuccessorNode->getNext();
                  }
              front = this->successors[front].getCount();
              }
         if(N == -1){
             std::cout << "\nTopology Sort Complete" << std::endl;
             }
         else{
             std::cout << "\nRelationships Form Closed Loop" << std::endl;
             }
         }    
    
    ~TopologySorter(){
        delete [] this->successors;
        } 
    };

int main(int argc, char **argv)
{
	TopologySorter *topologySorter = new TopologySorter(9);
    topologySorter->addRelation(9, 2);
    topologySorter->addRelation(3, 7);
    topologySorter->addRelation(7, 5);
    topologySorter->addRelation(5, 8);
    topologySorter->addRelation(8, 6);
    topologySorter->addRelation(4, 6);
    topologySorter->addRelation(1, 3);
    topologySorter->addRelation(7, 4);
    topologySorter->addRelation(9, 5);
    topologySorter->addRelation(2, 8);
    topologySorter->topologySort();
    delete topologySorter;
	return 0;
}
