#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class itemEntry
{
public:

    int copies;
    float unitPrice;
    char name[50], company[50];
};


class store
{
public:

    int numItem;
    itemEntry database[100];

    store()
    {
        numItem = 0;
    }

    void insertItem(char Name[], char Company[], int c, float up);
    void deleteItem(char Name[]);
    itemEntry *Search(char Name[]);
    void updateItem(char Name[], int total, float price);
};

void store::insertItem(char Name[], char Company[], int c, float up)
{
    strcpy(database[numItem].name, Name);
    strcpy(database[numItem].company, Company);
    database[numItem].copies = c;
    database[numItem].unitPrice = up;

    cout << "\n\nItem inserted successfully\n";
    numItem++;
}

void store::deleteItem(char Name[])
{
    for(int i=0; i<numItem; i++)
    {
        if(strcmp(database[i].name, Name) == 0)
        {
            database[i].copies--;
            cout << "\n\nItem deleted successfully\n";
            return;
        }
    }

    cout << "\n\nItem not found\n";
}

itemEntry *store::Search(char Name[])
{
    for(int i=0; i<numItem; i++)
    {
        if(strcmp(database[i].name, Name) == 0)
        {
            return &database[i];
        }
    }

    return NULL;
}

void store::updateItem(char Name[], int total, float price)
{
    itemEntry *item = Search(Name);

    if(item == NULL)
    {
        cout << "\n\nItem not found\n";
        return;
    }

    item->copies = item->copies + total;
    item->unitPrice = item->unitPrice + price;

    cout << "\n\nItem updated successfully\n";
}

int main()
{
    store ob1;
    char option[5], name[50], company[50], copies[100], unitPrice[15];

    do
    {
        cout << "\n\n----------> Enter your choice <----------";
        cout << "\n\ni => insert";
        cout << "\n\nd => delete";
        cout << "\n\ns => search";
        cout << "\n\nu => update";
        cout << "\n\ne => Exit\n\n";

        gets(option);

        if(option[0] == 'i')
        {
            cout << "\n\nEnter name of item, company, no. of copies and unit price : ";

            gets(name);
            gets(company);
            gets(copies);
            gets(unitPrice);

            ob1.insertItem(name, company, atoi(copies), atof(unitPrice));
        }

        else if(option[0] == 'd')
        {
            cout << "\n\nEnter name of item : ";
            gets(name);

            ob1.deleteItem(name);
        }

        else if(option[0] == 's')
        {
            cout << "\n\nEnter name of item : ";
            gets(name);

            itemEntry *ptr = ob1.Search(name);

            if(ptr != NULL)
            {
                cout << "\n\n----------> Searching result <----------";
                cout << "\n\nItem name        : " << ptr->name;
                cout << "\nCompany name     : " << ptr->company;
                cout << "\nCopies available : " << ptr->copies;
                cout << "\nUnit price       : " << ptr->unitPrice << endl;
            }
            else
            {
                cout << "\n\nItem not found";
            }
        }

        else if(option[0] == 'u')
        {
            cout << "\n\n----------> Enter details for update <----------";

            cout << "\n\nEnter name : ";
            gets(name);

            cout << "\nEnter total new Entry : ";
            gets(copies);

            cout << "\nEnter new price : ";
            gets(unitPrice);

            ob1.updateItem(name, atoi(copies), atof(unitPrice));
        }
    }

    while(option[0] != 'e');

    return 0;
}
