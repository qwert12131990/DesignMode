/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int elemNum = 1;
        int cnt = 0;
        Node* lastNode = root;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            Node* tmpPtr = que.front();
            if (tmpPtr == NULL){
                break;
            }
            que.push(tmpPtr->left);
            que.push(tmpPtr->right);
            
            cnt++;
            if (elemNum == cnt){       
                cnt -= elemNum;
                elemNum *= 2;
                lastNode->next = tmpPtr;
                tmpPtr->next = NULL;
            }
            else if (cnt == 1){
                lastNode = tmpPtr;
            }
            else{
                lastNode->next = tmpPtr;
                lastNode = tmpPtr;
            }
            que.pop();
        }
        return root;
    }
};