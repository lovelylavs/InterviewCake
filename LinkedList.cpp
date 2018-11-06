class LinkedListNode {
public:
  int intValue_;
  LinkedListNode *next_;

  LinkedListNode(int intValue):
  intValue_(intValue),
  next_(nullptr)
  {
  }


};

LinkedListNode *a = new LinkedListNode(1);
LinkedListNode *b = new LinkedListNode(2);
LinkedListNode *c = new LinkedListNode(3);
LinkedListNode *d = new LinkedListNode(4);
LinkedListNode *e = new LinkedListNode(5);

a->next_ = b;
b->next_ = c;
c->next_ = d;
d->next_ = e;

kthToLastNode(2, a);


/* We have a stick k nodes wide. We can start at beginning of list so that left side of stick was on head
   and right side was on kth node.
   We can slide the stick down.
    */

LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head){
  LinkedListNode *leftNode = head;
  LinkedListNode *rightNode = head;

  // move right node to kthnode.
  for(size_t i=0; i < k-1; ++i) {
    rightNode = rightNode->next_;
  }

  // starting with leftNode on the head ,
  // move leftNode and rightNode down the list
  // maintaining the distance of k between them
  // until rightNode hits the end
  while(rightNode->next_){
    leftNode = leftNode->next_;
    rightNode = rightNode->next_;
  }

  //since leftNode is k nodes behind rightNode,
  // leftNode is now kth to last node. 
  return leftNode;
}
