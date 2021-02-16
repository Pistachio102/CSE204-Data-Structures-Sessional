#include<iostream>
#include<stdio.h>

using namespace std;


void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Heap
{
    int size;
    int length;


public:

    int *arr;

    Heap(int l)//it will create an empty heap
    {
        size=0;
        length=l;
        arr= new int[length];
    }

    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1) ;
    }
    int right(int i)
    {
        return (2*i+2) ;
    }

    void Max_heapify( int *a, int i);

    void Build_Heap( int *a, int len);

    int Heap_Size();

    bool is_empty();

    int Find_Max();

    void Push(int i);

    int Pop();

    void Delete_Max();

    int Replace(int key);

    void Increase_key(int i, int key);

    void Decrease_key(int i, int key);

    void Delete_Node(int i);

    void Sift_Up(int l);

    void Sift_Down(int i);

    Heap* Merge(Heap *m );

    Heap* Meld(Heap *m );

    void print()
    {
        // cout<<arr[0]<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<"->";
        }
        cout<<"\n\n";


    }
};




void Heap::Max_heapify( int *a, int i)
{
    // cout<<"in max"<<endl;

    int l,r,largest;

    l=left(i);
    r=right(i);


    if(l< size && a[l]>=a[i])
        largest = l;
    else largest = i;

    if(r< size && a[r]>=a[largest])
        largest = r;

    if(largest!= i )
    {
        Swap(a[i],a[largest]);
        Max_heapify(a,largest);
        //return;
    }
    // cout<<"out max"<<endl;
    return ;

}










void Heap::Build_Heap(int *a, int len )
{
    //arr=new int[len];
    for(int x=0; x<len; x++)
    {
        arr[x]=a[x];
        //cout<<arr[x]<<"  "<<a[x]<<endl;
    }
    size=len;
    for(int i=(len-2)/2 ; i>=0 ; i--)
    {
        // cout<<i;
        Max_heapify(arr,i);

    }
    return;

}


int Heap::Heap_Size()
{
    return size;
}


bool Heap::is_empty()
{
    if(size==0)
        return true;
    else return false;
}




int Heap::Find_Max()//root node is the maximum of a max heap
{
    return arr[0];
}





void Heap::Push(int i)
{
    int *temp;
    if(size==length)
    {
        length= 2* length;
        temp = new int[length] ;
        int i;
        for( i = 0; i < size ; i++ )
        {
            temp[i] = arr[i] ; //copy all items from list to tempList
        }
        delete arr ; //free the memory allocated before
        arr = temp ;
    }

    arr[size++]=i;
    Sift_Up(size-1);
}





int Heap::Pop()
{
    if(size<=0)
        cout<<"There is no element in the heap to delete."<<endl;
    else
    {
        int x=arr[0];
        Swap(arr[0],arr[size-1]);
        size--;
        Sift_Down(0);
        return x;
    }
}







void Heap::Delete_Max()
{
    if(size<=0)
        cout<<"There is no element in the heap to delete."<<endl;
    else
    {

        Swap(arr[0],arr[size-1]);
        size--;
        Sift_Down(0);
    }
}



int Heap::Replace(int key)
{
    int x=arr[0];
    arr[0]=key;
    Sift_Down(0);
    return x;

}



void Heap::Increase_key(int i, int key)
{
    if(key<arr[i])
        cout<<"New key is smaller than current key"<<endl;

    else
    {
        arr[i]=key;
        Sift_Up(i);

    }

}




void Heap::Decrease_key(int i, int key)
{
    if(key>arr[i])
        cout<<"New key is greater than current key"<<endl;

    else
    {
        arr[i]=key;
        Sift_Down(i);

    }

}







void Heap::Delete_Node(int i)
{
    if(size<=0)
        cout<<"There is no element in the heap to delete."<<endl;

    else
    {
        Swap(arr[i],arr[size-1]);
        size--;
        Sift_Down(i);
    }
}










void Heap::Sift_Up(int l)
{
    int i=l;

    /* for(int i=(l-2)/2 ; i>=0 ; i--)
      {
          //cout<<i;
          Max_heapify(arr,i);

      }*/


    while(i!=0 && (arr[parent(i)]<arr[i]) )
    {
        Swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }







}






void Heap::Sift_Down(int i )
{
    Max_heapify(arr,i);
}


Heap* Heap::Merge(Heap *m)
{

    int x,y,z,i,j;

    x=m->Heap_Size();
    //y=n.Heap_Size();
    z=size+x;

    int *arr1= new int[z];



    for(i=0 ; i<size ; i++)
    {
        arr1[i]= arr[i];
    }

    for(j=0 ; j<x ; j++)
    {
        arr1[i]= m->arr[j];
        i++;
    }



    Heap *p=new Heap(z);
    p->Build_Heap(arr1,z);

    return p;


}


Heap* Heap::Meld(Heap *m )
{

    int x,y,z,i,j;

    x=m->Heap_Size();
    //y=n.Heap_Size();
    z=size+x;

    int *arr1= new int[z];



    for(i=0 ; i<size ; i++)
    {
        arr1[i]= arr[i];
    }

    for(j=0 ; j<x ; j++)
    {
        arr1[i]= m->arr[j];
        i++;
    }

    delete this;
    delete m;



    Heap *p=new Heap(z);
    p->Build_Heap(arr1,z);

    return p;

}




int main()
{
    while(1)
    {

        Heap *h1, *h2, *h3, *h4;

        int choice;
        cout << "1.Create an empty heap.  2.Create new heap.  3.Size.\n\n";
        cout << "4.Push.  5.Pop.  6.Maximum node.\n\n";
        cout << "7.Delete maximum node.  8.Replace root.  9.Check empty or not.\n\n";
        cout << "10.Increase key.  11.Decrease key.  12.Delete a node.\n\n";
        cout << "13.Merge two heaps.  14.Meld two heaps.  15.Free the current heap.\n\n16.Print  17.Exit. \n\n";
        cout << "Your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                int x;
                cout<<"Enter the length of the array: ";
                cin>>x;
                h1=new Heap(x);
                cout<<"\n";
                cout<<"******  An empty heap created.  ****** \n\n"<<endl;
                break;
            }
        case 2:
            {
                int x;
                cout<<" Enter the number of the nodes: ";
                cin>>x;
                int *A=new int[x];
                cout<<"Enter the nodes: "<<endl;
                for(int i=0;i<x;i++)
                {
                    cin>>A[i];
                }
                h1=new Heap(x);
                h1->Build_Heap(A,x);
                cout<<"******  New heap created.  ****** \n\n"<<endl;
                break;

            }
        case 3:
            {
                cout<<"Current size if the heap: "<<h1->Heap_Size()<<endl;
                cout<<endl;
                break;
            }
        case 4:
            {
                int x;
                cout<<"Insert a new node: ";
                cin>>x;
                h1->Push(x);
                cout<<"******  New node added  ******\n\n"<<endl;
                break;
            }
        case 5:
            {
                cout<<"Popping up the root node: "<<h1->Pop()<<"\n\n"<<endl;
                break;
            }
        case 6:
            {
                cout<<"The maximum node: "<<h1->Find_Max()<<endl;
                break;
            }
        case 7:
            {
                h1->Delete_Max();
                cout<<"******  Maximum node is deleted. ******\n\n"<<endl;
                break;
            }
        case 8:
            {
                int x;
                cout<<"Replace the root node with: ";
                cin>>x;
                h1->Replace(x);
                cout<<"******  Replaced  ******\n\n"<<endl;
                break;
            }
        case 9:
            {
                if(h1->is_empty())
                    cout<<"The heap is empty.\n"<<endl;
                else cout<<"The heap is not empty.\n"<<endl;
                break;
            }
        case 10:
            {
                int x,y;
                cout<<"Enter the position: ";
                cin>>x;
                cout<<"Enter the new key: ";
                cin>>y;
                h1->Increase_key(x,y);
                break;
            }
        case 11:
            {
                int x,y;
                cout<<"Enter the position: ";
                cin>>x;
                cout<<"Enter the new key: ";
                cin>>y;
                h1->Decrease_key(x,y);
                break;

            }
        case 12:
            {
                int x;
                cout<<"Enter the position of the node to delete: ";
                cin>>x;
                h1->Delete_Node(x);
                break;

            }
        case 13:
            {
                int x;
                cout<<" Enter the number of the nodes of the 1st heap: ";
                cin>>x;
                int *B=new int[x];
                cout<<"Enter the nodes: "<<endl;
                for(int i=0;i<x;i++)
                {
                    cin>>B[i];
                }
                h2=new Heap(x);
                h2->Build_Heap(B,x);


                int y;
                cout<<" Enter the number of the nodes of the 2nd heap: ";
                cin>>y;
                int *C=new int[y];
                cout<<"Enter the nodes: "<<endl;
                for(int i=0;i<y;i++)
                {
                    cin>>C[i];
                }
                h3=new Heap(y);
                h3->Build_Heap(C,y);

                h1=h2->Merge(h3);
                cout<<"******  Merged  ******\n\n"<<endl;
                break;


            }
        case 14:
            {
                 int x;
                cout<<" Enter the number of the nodes of the 1st heap: ";
                cin>>x;
                int *B=new int[x];
                cout<<"Enter the nodes: "<<endl;
                for(int i=0;i<x;i++)
                {
                    cin>>B[i];
                }
                h2=new Heap(x);
                h2->Build_Heap(B,x);


                int y;
                cout<<" Enter the number of the nodes of the 2nd heap: ";
                cin>>y;
                int *C=new int[y];
                cout<<"Enter the nodes: "<<endl;
                for(int i=0;i<y;i++)
                {
                    cin>>C[i];
                }
                h3=new Heap(y);
                h3->Build_Heap(C,y);

                h1=h2->Meld(h3);

                cout<<"******  Melded  ******\n\n"<<endl;
                break;

            }
        case 15:
            {
                delete h1;
                break;

            }
        case 16:
            {
                h1->print();
                cout<<"\n\n\n";
                break;

            }


        }
        if(choice==17)
        {
            break;
        }

}


    return 0;
}


























