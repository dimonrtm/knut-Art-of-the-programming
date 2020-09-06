#include <stdio.h>
#include <iostream>
class NodeCard{
private:
    short tag;
    short suite;
    short rank;
    char *title;
    NodeCard *next;
public:
    NodeCard(short suite, short rank){
        this->tag = 0;
        if(suite < 1 || suite > 4){
            throw -1;
            }
        if (rank < 1 || rank > 13){
            throw -1;
            }
        this->suite = suite;
        this->rank = rank;
        char suite_char;
        if(suite == 1){
            suite_char ='C';
            }
        else if(suite == 2){
            suite_char = 'D';
            }
        else if(suite == 3){
            suite_char = 'H';
            }
        else if(suite == 4){
            suite_char = 'S';
            }
        this->title = new char[5];
        if(rank / 10 > 0)
        {
           sprintf(this->title, " %d %с", rank, suite_char); 
            }
        else{
            sprintf(this->title, "  %d %c", rank, suite_char);
            }
        this->next = nullptr;
        }
    };
    
    void testConstructorInvalidValue(short suite, short rank){
        try{
           NodeCard *node = new NodeCard(suite,rank);
           }
        catch(int exc){
           std::cout << "Invalid value" << std::endl;
           }
        }

int main(int argc, char **argv)
{
	NodeCard *node = new NodeCard(2,2);
    testConstructorInvalidValue(0, 1);
    testConstructorInvalidValue(1, 0);
    testConstructorInvalidValue(5, 1);
    testConstructorInvalidValue(1, 14);
	return 0;
}
