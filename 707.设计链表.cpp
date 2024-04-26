/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-05 15:35:29
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-05 22:19:33
 */
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start

        
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        _size = 0;
        _dummyHead = new LinkedNode(0);
    }
    
    int get(int index) {
        if (index > _size - 1 || index < 0){
            return -1;
        }
        else{
            LinkedNode* cur = _dummyHead->next;
            while (index--){
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        LinkedNode* new_node = new LinkedNode(val);
        new_node->next = _dummyHead->next;
        _dummyHead->next = new_node;
        _size++;
    }
    
    void addAtTail(int val) {
        // 先找到尾节点
        LinkedNode* new_node = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next){
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->next = nullptr;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        // if (index == _size){
        //     this->addAtTail(val);
        //     index += 1;
        // }
        if (index <= _size && index >= 0){
            LinkedNode* new_node = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while (index--){
                cur = cur->next;
            }
            new_node->next = cur->next;
            cur->next = new_node;
            _size++;
        }
    }

    
    void deleteAtIndex(int index) {
        if (index >= 0 && index <= _size - 1){
            LinkedNode* cur = _dummyHead;
            while (index--){
                cur = cur->next;
            }
            LinkedNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            //delete命令指示释放了tmp指针原本所指的那部分内存，
            //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
            //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
            //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
            tmp=nullptr;
            _size--;
        }
        

    }
private:
    int _size;
    LinkedNode* _dummyHead;
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end