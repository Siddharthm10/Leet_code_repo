/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    void print(ListNode* head){
        struct ListNode* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<endl;
            temp = temp->next;
        }
    };

    int lengthLL(ListNode* head){
        struct ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp = temp-> next;
        }
        return count;
    }
    
    
    bool isPalindrome(ListNode* head) {
    //reverse the linked list and then compare it with the original 
    //if found not equal return false otherwise true
        struct ListNode* temp = head;
        int length = lengthLL(temp);
        if(length>0){
            char len[length];
            int i=0;
            while(temp!= NULL){
                len[i]=temp->val;
                temp = temp->next;
                i++;
            }

            for(int i=0, j=length-1; i<length; i++, j--){
                if(len[i]!=len[j])
                    return false;
            }
            return true;
        }
        else return true;
    }
};

//Logic can be updated to :
// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseLL(Node* head){
        Node* curr=head, *prev=NULL, *next=NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void print(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    Node* copyLL(Node* head){
        Node* dummy = new Node(0);
        Node* dummyHead = dummy;
        Node* temp = head;
        while(temp){
            dummy->next = new Node(temp->data);
            dummy = dummy->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *temp = head;
        Node *start = reverseLL(copyLL(head));

        while(start){
            if(temp->data!=start->data){
                return false;
            }
            // start = slow->next
            temp = temp->next;
            start = start->next;
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
