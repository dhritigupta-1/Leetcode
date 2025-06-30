class MyLinkedList {
    private:
        ListNode* head;
        int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size || head == NULL)
            return -1;
        ListNode* current = head;
        for(int i=0; i<index; i++)
            current = current->next;
        return current->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == NULL)
            head = newNode;
        else
        {
            ListNode* current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode = new ListNode(val);
        if(index < 0 || index > size)
            return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        else
        {
            ListNode* current = head;
            for(int i=0; i<index-1; i++)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        if(index == 0)
            head = head->next;
        else
        {
            ListNode* current = head;
            for(int i=0; i<index-1; i++)
                current = current->next;
            current->next = current->next->next;
        }
        size--;
    }
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