#include <iostream>

using namespace std;

int Q = 0;

struct noda
{
    int data;
    noda * next;
};

void push(noda**h,int x)
{
    noda * NEW = new noda();
    NEW -> data = x;
    if (h == NULL)
    {
     Q++;
     *h = NEW;
    }
    else
    {
        NEW -> next = *h;
        *h = NEW;
        Q++;
    }
    cout << "pushed" <<endl;
};

int pop(noda ** h)
{
    int x = (*h) -> data;
    noda *t = *h;
    (*h) = (*h) -> next;
    Q--;
    return(x);
    free(t);
}

int main()
{
    noda * head = NULL;
    string s;
    int a;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> a;
            push(&head,a);
        }
        else if(s=="pop")
        {
            if (Q!=0)
            {
                cout << pop(&head) << endl;
            }
            else
            {
                cout << "empty, can pop nothing" << endl;
            }

        }
    }
    return(0);
}
