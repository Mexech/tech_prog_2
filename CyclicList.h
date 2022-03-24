class CyclicList {
    public:
        CyclicList();
        ~CyclicList();
        struct Node {
            int data;
            struct Node* next;
        };
        void push(int val);
        int pop();
        void display();
        bool isEmpty();
        CyclicList copy();
        CyclicList operator++();
        CyclicList operator++(int);
        friend CyclicList operator--(CyclicList&);
        friend CyclicList operator--(CyclicList&, int);
    protected:
    private:
        Node *head, *tail;
};