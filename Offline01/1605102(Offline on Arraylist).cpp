#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

using namespace std;

int listMaxSize;
int * list;
int length;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
	int * tempList ;
	 // If the list has been cleared,it will initialize the list again.
	if(listMaxSize==0 && length==0)
    {
        initializeList();
    }
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

	list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}
int insertItemAt(int pos, int item)
{
    int * tempList ;
    // If the list has been cleared,it will initialize the list again.
    if(listMaxSize==0 && length==0)
    {
        initializeList();
    }
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}
	if ( pos >= length ) return NULL_VALUE;
	list[length]=list[pos];
	list[pos]=item;
	length++;
	return SUCCESS_VALUE;
}
//Clears the items from the list and deallocates the memory.
void clear()
{
    length=0;
    listMaxSize=0;
    free(list);
}

void deleteAll()
{
    length=0;
    if(listMaxSize>LIST_INIT_SIZE)
    listMaxSize=LIST_INIT_SIZE;
}

void shrink(){

if(listMaxSize<=LIST_INIT_SIZE)
   return;
   //printf("Can't be shrunk \n");

     if(length<=(.5*listMaxSize))
    {
        int *temp;
        listMaxSize=.5*listMaxSize;
        temp=(int*) malloc(listMaxSize*sizeof(int));
        int i;
        for(i=0;i<length;i++){
            temp[i]=list[i];
        }
        free(list);
        list=temp;
    }


}

int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position >= length ) return NULL_VALUE;
	list[position] = list[length-1] ;
	length--;
	shrink();
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;

}

int deleteLast()
{
    deleteItemAt(length-1);
    shrink();
    return SUCCESS_VALUE;
}

void printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

// Returns the current items' number of the list.
int getLength()
{
    return length;
}



/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. Insert new item at. 5. Delete the last item. 6.Delete all items.\n7.Clear the list 8. Print. 9.Get length 10. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter:\n");
            scanf("%d", &item);
            insertItem(item);
            printf("One new item has been inserted.\n");
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
            printf("One item has been deleted from the given position.\n");
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
            printf("One item has been deleted.\n");
        }
        else if(ch==4)
        {
            int pos,item;
            printf("Enter position and item\n");
            scanf("%d %d",&pos,&item);
            insertItemAt(pos,item);
            printf("One new item has been inserted at the given position.\n ");
        }
        else if(ch==5)
        {
            deleteLast();
            printf("Deleted the last item\n");
        }

        else if(ch==6)
        {
            deleteAll();
            printf("All items have been deleted\n");
        }

        else if(ch==7)
        {
            clear();
            printf("The list has been cleared\n");
        }

        else if(ch==8)
        {
            printList();
        }
        else if(ch==9)
        {
            printf("%d\n",getLength());
        }
        else if(ch==10)
        {
            break;
        }
    }

}*/

int main()
{
    initializeList();
    string s1;
    printf("Enter : \n");
    getline(cin,s1);
   // printf("outside\n");
    for(int x=0;x<s1.length();x++)
    {

        if(s1.at(x)>47 && s1.at(x)<60)
        {
            int i=s1.at(x)-48;
            insertItem(i);
           // printf("Inside the number %d\n",i);
        }
        if(s1.at(x)=='+')
        {
            int sum=list[length-1]+list[length-2]  ;
            deleteLast();
            deleteLast();
            insertItem(sum);
           //  printf("Inside the + and sum is %d\n",sum);
        }
        if(s1.at(x)=='-')
        {
            int sum=abs(list[length-1]-list[length-2]);
            deleteLast();
            deleteLast();
            insertItem(sum);
        }
        if(s1.at(x)=='*')
        {
            int sum=list[length-1]*list[length-2];
            deleteLast();
            deleteLast();
            insertItem(sum);
        }
        if(s1.at(x)=='/')
        {
            int sum=(list[length-1]/list[length-2]);
            deleteLast();
            deleteLast();
            insertItem(sum);
        }
    }

    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
        clear();


    }






