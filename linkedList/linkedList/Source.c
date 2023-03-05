#include<stdio.h>
#include<stdlib.h>
#include<string.h> // added this include for strcpy
#pragma warning(disable : 4996)

struct Student {
    char name[50];
    char gender;
    struct Student* next;
};

struct Student* insertNode(char* name, char gender, struct Student* list)
{
    struct Student* s;
    s = malloc(sizeof(struct Student));
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return list;
    }
    strcpy(s->name, name);
    s->gender = gender;
    s->next = list;
    return s; // return the new head of the list
}

void printList(struct  Student* list)
{
    while (list != NULL)
    {
        printf("%s\t%c\n", list->name, list->gender);
        list = list->next;
    }
}


//https://www.youtube.com/watch?v=pdMPvMM12G0

struct Student* sortList(struct Student* list)
{

    struct Student* end, * p, * q, * temp, * r;

    //end i nulldan ba�lat�p en b�y�k eleman� en sona yerle�tirdikten sonra end'i son yani en b�y�k elemana at�yo
    //  listenin sonuna geldikten sonra p ve q tekrar ba�tan ba�lay�p swap yap�yo. ikinci en b�y�k  say�y� bulup sona ekledikten sonra end'i bir sola kayd�r�yo
    //liste b�y�kten k���ge s�ralanana kadar bu i�lemi tekrarl�yo.

    for (end = NULL; end != list->next; end = p)
    {
        for (r = p = list; p->next != end; r = p, p = p->next)
        {
            q = p->next;
            if (p->gender == 'F' && q->gender == 'F')  //cinsiyeti kad�n olanlar� bubble sort ile alfabetik bir �ekilde s�ral�yo
            {
                if (strcmp(p->name, q->name) > 0)
                {
                    p->next = q->next;
                    q->next = p;
                    if (p != list)
                    {
                        r->next = q;
                    }
                    else
                    {
                        list = q;
                    }
                    temp = p;
                    p = q;
                    q = temp;
                }
            }
            else if (p->gender == 'M' && q->gender == 'M') //cinsiyeti erkek olanlar� bubble sort ile ters alfabetik s�ral�yo
            {
                if (strcmp(p->name, q->name) < 0)
                {
                    p->next = q->next;
                    q->next = p;
                    if (p != list)
                    {
                        r->next = q;
                    }
                    else
                    {
                        list = q;
                    }
                    temp = p;
                    p = q;
                    q = temp;
                }
            }
            else if (p->gender > q->gender) // 'M' ve 'F'nin ascii de�erlerine bak�p b�y�kl�klerini kar��la�t�r�yo. 'M' daha b�y�k oldu�u i�in �nce kad�nlar� sonra erkekleri listeliyo.
            {
                p->next = q->next;
                q->next = p;
                if (p != list)
                {
                    r->next = q;
                }
                else
                {
                    list = q;
                }
                temp = p;
                p = q;
                q = temp;

            }
        }
    }
    return list;
}

int main()
{
    struct Student* head = NULL;

    head = insertNode("Cenk", 'M', head);
    head = insertNode("Ceyda", 'F', head);
    head = insertNode("Esra", 'F', head);
    head = insertNode("Okan", 'M', head);
    head = insertNode("Tugce", 'F', head);
    head = insertNode("Mehmet", 'M', head);
    head = insertNode("Ayse", 'F', head);
    head = insertNode("Merve", 'F', head);
    head = insertNode("Sedat", 'M', head);
    head = insertNode("Ahmet", 'M', head);

    printList(head);
    printf("\n");

    head = sortList(head);

    printList(head);

    return 0;
}









