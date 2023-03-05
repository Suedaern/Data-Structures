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

    //end i nulldan başlatıp en büyük elemanı en sona yerleştirdikten sonra end'i son yani en büyük elemana atıyo
    //  listenin sonuna geldikten sonra p ve q tekrar baştan başlayıp swap yapıyo. ikinci en büyük  sayıyı bulup sona ekledikten sonra end'i bir sola kaydırıyo
    //liste büyükten küçüge sıralanana kadar bu işlemi tekrarlıyo.

    for (end = NULL; end != list->next; end = p)
    {
        for (r = p = list; p->next != end; r = p, p = p->next)
        {
            q = p->next;
            if (p->gender == 'F' && q->gender == 'F')  //cinsiyeti kadın olanları bubble sort ile alfabetik bir şekilde sıralıyo
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
            else if (p->gender == 'M' && q->gender == 'M') //cinsiyeti erkek olanları bubble sort ile ters alfabetik sıralıyo
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
            else if (p->gender > q->gender) // 'M' ve 'F'nin ascii değerlerine bakıp büyüklüklerini karşılaştırıyo. 'M' daha büyük olduğu için önce kadınları sonra erkekleri listeliyo.
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









