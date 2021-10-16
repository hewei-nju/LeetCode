/*
描述
用两个栈来实现一个队列，完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

数据范围：0n≤1000
要求：空间复杂度 O(n)O(n) ，时间复杂度 O(1)
*/

class Solution
{
public:
    void push(int node) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;    // 存储栈
    stack<int> stack2;    // 输出栈
    // 保证存储内容都放在stack1种，输出都在stack2进行，这样处理简单
    // 此时，如果要push时，stack2就不能又内容，要pop时stack1也不能有内容
};