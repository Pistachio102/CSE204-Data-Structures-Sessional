#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;

        if(list==0) //inserting the first item
        {
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
        return SUCCESS_VALUE ;
    }

    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printListForward()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }

        printf("\n");
        printf("Length : %d\n",length);
        //printf("The last item is %d\n",tail->item);

    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
        ListNode *newNode= new ListNode();
        newNode->item=item;
        newNode->next=0;
        if(length==0)//when the list is empty,head and tail pointers point to the same node if a new node is added
        {
            newNode->prev=0;
            list=newNode;
            tail=newNode;
            length++;
            return SUCCESS_VALUE;
        }
        //otherwise the new node's prev points to the previous tail and the previous tail's next points to the new node.
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
        length++;
        return SUCCESS_VALUE;

    }

    int deleteLast()
    {
        //write your codes here
        if(length==0)
        {
            printf("You can't delete from an empty list.\n");
            return NULL_VALUE;
        }
        if(length==1)
        {
            free(list);

            list=0;
            free(tail);

            tail=0;
            length--;
            return SUCCESS_VALUE;
        }
        ListNode *temp;
        temp=tail;
        tail=temp->prev;
        tail->next=0;
        free(temp);
        length--;


        return SUCCESS_VALUE;
    }

    void printListBackward()
    {
        //will print the list backward starting from the tail position
         ListNode * temp;
        temp = tail;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->prev;
        }
        printf("\n");
        printf("length : %d\n",length);


    }

};

int main(void)
{
    LinkedListDoubly ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Print forward. 5. Print backward. 6. exit.\n");
        printf("7.Insert new item at the end.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertFirst(item);
        }
        else if(ch==2)
        {
            int item = ll.deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            ll.printListForward();
        }
        else if(ch==5)
        {
            ll.printListBackward();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int item;
            scanf("%d",&item);
            ll.insertLast(item);
            printf("New item inserted at the end of the list.\n");
        }
    }

}
