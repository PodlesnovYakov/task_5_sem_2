#include <iostream>
#include <cmath>
using namespace std;
struct list
{
    int pw;
    int id;
    list* next;
};
void push(list*& head, int x,int x1)
{

    list* tmp = new list;
    tmp->pw = x1;
    tmp->id = x;
    tmp->next = head;
    head = tmp;

}
void push_in_end(list*& head, int x,int x1)
{
    list* tmp = head;
    if (!head)
    {
        push(head,x,x1);
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        list* ptr = new list;
        ptr->id = x;
        ptr->pw = x1;
        ptr->next = tmp->next;
        tmp->next = ptr;

    }
}
/*void prints(list* head)
{
    while (head != NULL)
    {
        cout << head->pw <<"x^" << head->id << " ";
        head = head->next;
    }
    cout << endl;
}
*/
int poisk(list*head,int k)
{
    while (head != NULL)
    {
        if(head->id == 0)
        {
            k = head->pw;
            return k;
        }
        head = head->next;
    }
}
int prov(list *head,int p)
{
    int s = 0;
    while (head != NULL)
    {
        s += pow(p,head->id)*(head->pw);
        head = head->next;
    }
    return s;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    list* head = NULL;
    int x,x1;
    x = x1 = 1;
    while((x!= 0) || (x1!=0))
    {
        cin >> x >> x1;
        if((x!= 0) || (x1!=0)) push_in_end(head,x,x1);
    }
    //prints(head);
    int k = 0;
    k = poisk(head,k);
    if(k == 0) cout << "Корень данного многочлена - 0." << endl;
    else
    {
        int aa[2*abs(k)];
        for(int i = 0; i < 2*abs(k); i++)
        {
            aa[i] = 0;
        }
        int s = -1;
        int temp = 0;
        for(int i = 1; i <= abs(k); i++)
        {
            if(abs(k) % i == 0)
            {
                aa[temp] = i;
                temp++;
                aa[temp] = -i;
                temp++;
            }
        }

        for(int i = 0; i < 2*abs(k); i++)
        {
            if(aa[i] != 0)
            {
                s = prov(head,aa[i]);
                if(s == 0) cout << "Корень этого многочлена - " << aa[i] << '.' << endl;
            }
        }
    }

    return 0;
}

