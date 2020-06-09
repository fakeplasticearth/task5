#include <bits/stdc++.h>
using namespace std;
typedef struct link{
    int id;
    int st;
    struct link *next;
}mylist;
mylist L;

int n1, n2;
void AddHead(mylist* &curr)
{
    int x,y;
    cin >> x >> y;
    mylist *tmp = new mylist;
    tmp->id = x;
    tmp->st = y;
    tmp->next = curr;
    curr = tmp;
    return;
}

void ShowAll (mylist *curr, bool f)
{
    if (curr!=NULL)
    {
        if (f == 1)
        {
            if (curr->st > 0)
                cout << curr->id << "x^" << curr->st;
            else
            if (curr->st == 0)
                cout << curr->id;
            else
                cout << curr->id << "x^(" << curr->st << ')';
        }
        else
        {
            if (curr->id >= 0)
                cout << "+";
            if (curr->st > 0)
                cout << curr->id << "x^" << curr->st;
            else
            if (curr->st == 0)
                cout << curr->id;
            else
                cout << curr->id << "x^(" << curr->st << ')';
        }
        ShowAll(curr->next,0);
    }
    return;
}

bool eq_st(int id, int st, mylist *curr)
{
    if (curr == NULL)
        return 0;
    if (curr->id == id && curr->st == st)
        return 1;
    return eq_st(id, st, curr->next);
}

void eq(mylist *curr1, mylist *curr2)
{
    bool f = (n1 == n2);
    while(curr1 != NULL)
    {
        if (!eq_st(curr1->id, curr1->st, curr2))
            f = 0;
        curr1 = curr1->next;
    }
    if (f)
        cout << "\nРавны";
    else
        cout << "\nNНе равны";
}


int main()
{
    setlocale(LC_ALL,"");
    mylist *mn1 = NULL;
    mylist *mn2 = NULL;
    cout << "Введите количество степеней первого многочлена\n";
    cin >> n1;
    cout << "Введите многочлен в формате *коэффициент степень*\n";
    for (int i = 0;i<n1;i++)
        AddHead(mn1);
    cout << "Введенный многочлен: ";
    ShowAll(mn1,1);
    cout << "\nВведите количество степеней второго многочлена\n";
    cin >> n2;
    cout << "Введите многочлен в формате *коэффициент степень*\n";
    for (int i = 0;i<n2;i++)
        AddHead(mn2);
    cout << "Введенный многочлен: ";
    ShowAll(mn2,1);
    eq(mn1, mn2);
    return 0;
}
