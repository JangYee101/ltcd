#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;




class MyQueue {
public:
    stack<int> stin, stout;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if(stout.empty()) {
            while(!stin.empty()) {
                stout.push(stin.top());
                stin.pop();
            }
        }
        res = stout.top();
        stout.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = pop();
        stout.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stin.empty() && stout.empty();
    }
};





int main(int argc, char ** argv) {
    vector<int> nums {1,2,3,4,5,6,7};
    int i;
	MyQueue solution;
    for(i=0;i<nums.size();i++) {
        solution.push(nums[i]);
    }
    cout << "first elem is " << solution.peek() << endl;
    while(!solution.empty()) {
        cout << solution.pop() << endl;
    }
	return 0;
}











