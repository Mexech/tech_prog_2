class CyclicList {
    public:
        CyclicList();
        struct Node {
            int data;
            struct Node* next;
        };
        void push(int val);
        int pop();
        void display();
        bool isEmpty();
    protected:
    private:
        Node *head, *tail;
};