#include <stack>
#include <stdio.h>
#include <iostream>

using namespace std;

class MyQueue {
    public:
        stack<int>* stack1 = nullptr;
        stack<int>* stack2 = nullptr;
        MyQueue() {
            stack1 = new stack<int>();
            stack2 = new stack<int>();
        }
        ~MyQueue() {
            delete(stack1);
            stack1 = nullptr;
            delete(stack2);
            stack2 = nullptr;
        }
        
        void push(int x) {
            stack1->push(x);
        }
        
        int pop() {
            int tmp;
            if (stack2->size() == 0) {
                while (!stack1->empty()) {
                    stack2->push(stack1->top());
                    stack1->pop();
                }
            }
            tmp = stack2->top();
            stack2->pop();
            return tmp;
        }
        
        int peek() {
            if (stack2->size() == 0) {
                while (!stack1->empty()) {
                    stack2->push(stack1->top());
                    stack1->pop();
                }
            }
            return stack2->top();
        }
        
        bool empty() {
            return stack2->empty() && stack1->empty();
        }
    };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(void){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.pop();
    queue.push(3);
    queue.push(4);
    cout <<queue.pop() <<queue.pop();
    return 0;
}