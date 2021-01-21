/*
For Example : 2 2 4 5
here curr=2 curr->next=2 curr->next->next=4
we have to delete curr->next
*/

Node *removeDuplicates(Node *head)
{
// your code goes here
//  set<node*>s;
//  Node* temp=head
//  while(temp!=NULL)
//  {
//      s.insert(temp);
//      temp=temp->next;
    Node* curr = head;
    Node* next_of_delete;
    if (curr == NULL) return 0;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_of_delete = curr->next->next;
            free(curr->next);
            curr->next = next_of_delete;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;

}