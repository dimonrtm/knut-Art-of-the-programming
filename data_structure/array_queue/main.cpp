#include <stdio.h>

class ArrayQueue{
private:
    int size;
    int *array;
    int front;
    int rear;
public:
    ArrayQueue(int size){
        this->size = size;
        this->array = new int[size];
        this->front = this->rear = 0;
    }
    
    void Add(int value){
        if(this->rear == this->size - 1){
            this->rear = 0;
        }
        else{
            this->rear++;
            if(this->rear == this->front){
               throw -1;
            }
            this->array[this->rear] = value;
            }
        }
        
    ~ArrayQueue(){
        delete [] this->array;
        }
    };
int main(int argc, char **argv)
{
	return 0;
}
