#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q1.size();
        size--;
        while(size--) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};




int main(int argc, char ** argv) {
    vector<int> nums {1,2,3,4,5,6,7};
    int i;
	MyStack solution;
    for(i=0;i<nums.size();i++) {
        solution.push(nums[i]);
    }
    //cout << "first elem is " << solution.peek() << endl;
    while(!solution.empty()) {
        cout << solution.pop() << endl;
    }
	return 0;
}











