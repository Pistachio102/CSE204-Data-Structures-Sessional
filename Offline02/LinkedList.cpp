#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0; //initially set to NULL
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
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

    void printList()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",length);
    }

    //------------write code for the functions below-----------

    int insertLast(int item)
    {
        //write your codes here
        ListNode *temp1= new ListNode();//new node
        temp1->item=item;
        temp1->next= 0;
        ListNode *temp;
        temp= list;
        if(temp==0)
        {
            list=temp1;
            length++;
            return SUCCESS_VALUE;
        }
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=temp1;
        length++;
        return SUCCESS_VALUE;
    }

    int insertAfter(int oldItem, int newItem)
    {
        //write your codes here
        ListNode *temp=searchItem(oldItem);
        if(temp!=0)
        {
            ListNode *newNode= new ListNode();
            newNode->item=newItem;
            newNode->next=temp->next;
            temp->next=newNode;
            length++;
            return SUCCESS_VALUE;
        }
        else
        {
            printf("No such item found\n\n");
            return 0;
        }
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here
         ListNode *temp;
         temp=list;
         if(pos>length)//because it returns a pointer and a pointer can't point to a negative memory,that is why it returns zero
            return 0;
            else if(length==0)//if the list is empty.as because it returns a pointer and a pointer can't point to a negative memory,that is why it returns zero
                return 0;
         else
         {
             for(int i=1; i<pos;i++)
             {
                 temp=temp->next;

             }
             return temp;
         }

    }

    int deleteFirst()
    {
        //write your codes here
        ListNode *temp;
        if(length==0)
        {
            printf("List is empty.\n");
            return NULL_VALUE;
        }
        else
        {
            temp= list->next;
        free(list);
        list=temp;
        length--;
        printf("First item from the list is deleted.\n");
        return SUCCESS_VALUE;

        }
    }


    ~LinkedList()
    {
        //write your codes here
        length=0;
        free(list);

    }

};

int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert item after. 5. Print. 6. exit. \n");
        printf("7. Insert item at last . 8.Get item at . 9.Delete first item . \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
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
            int item,item1;
            scanf("%d %d",&item,&item1);
            ll.insertAfter(item,item1);
        }
        else if(ch==5)
        {
            ll.printList();
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
        }
        else if(ch==8)
        {
            int pos;
            scanf("%d",&pos);
            ListNode *x =ll.getItemAt(pos);
            printf("\n%d\n",x->item);
        }
        else if(ch==9)
        {
            ll.deleteFirst();
        }
    }

}
