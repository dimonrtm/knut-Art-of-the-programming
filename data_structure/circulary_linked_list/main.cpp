#include <stdio.h>

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
    CircularlyLinkedList(){
        this->Ptr = nullptr;
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
    
    }

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
