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

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ;
        if(length==0)
        {
            tail=newNode;
        }//point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        if(temp==0)//if the list is empty initially
        {
            printf("You cannot delete from an empty list.\n");
            return NULL_VALUE;
        }
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0)return NULL_VALUE ;//item not found to delete
        if(length==0)//to free the tail pointer when the list gets empty by deleting one by one(Code by me)
        {
            if(tail!=0)
                delete tail;
            return NULL_VALUE;
        }
        if (temp == list) //delete the first node
        {
            list = list->next ;
            free(temp) ;
            length--;
        }
        else
        {//when the last node is deleted,previous node is assigned as the tail pointer(Code by me)
            if(temp->next==0)
            {
                tail=prev;
            }
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
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
        ListNode * temp, *temp1;
        temp = list;
        temp1=tail;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
       printf("The last item is %d\n\n",tail->item);
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
        ListNode *newNode= new ListNode();
        newNode->item=item;
        newNode->next=0;
        ListNode *temp;
        temp=list;
        //if the list is empty
        if(temp==0)
        {
            list=newNode;
            free(temp);
            tail=newNode;
            length++;
            return SUCCESS_VALUE;
        }
        //otherwise
        tail->next=newNode;
        tail=newNode;
        length++;
        return SUCCESS_VALUE;
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here
          ListNode *temp;
         temp=list;
         if(pos>length)
            return 0;
          else if(length==0)
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

    int deleteLast()
    {
        //write your codes here
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        if(temp==0)//if the list is empty initially
        {
            printf("You cannot delete from an empty list.\n");
            return NULL_VALUE;
        }
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next ; //move to next node
        }
        prev->next = temp->next ;
            delete temp;
            tail=prev;
            length--;
            return SUCCESS_VALUE;
    }
};

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert new item at the end. 5. Print. 6. exit.\n");
        printf("7.Get item at. 8.Delete last item.\n");

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
        else if(ch==4)//code by me
        {
            int item;
            scanf("%d",&item);
            ll.insertLast(item);

        }
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)//code by me
        {
            int pos;
            scanf("%d",&pos);
            ListNode *x =ll.getItemAt(pos);
            printf("The item at the position %d is : %d\n\n",pos,x->item);
        }
        else if(ch==8)
        {
            ll.deleteLast();
        }
    }



}
