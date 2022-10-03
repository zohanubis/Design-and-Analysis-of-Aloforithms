#include "stdio.h"
#include "conio.h"

struct Node
{
    int info;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
Node *createNode(int x)
{
    Node *q = new Node;
    if(q==NULL)
    {
        printf("Khong du bo nho de cap phat");
        return NULL;
    }
    q->info =x;
    q->next=NULL;
    return q;
}
void menu();
void createList(Slist &l, int n);
void printList(Slist l);
void addHeadSList(Slist &l,Node *p);
void addTailSList(Slist &l,Node *p);
void addAfterNodeSlist(Slist &l, Node *p);
void deleteHeadSlist(Slist &l);
void deleteTailSlist(Slist &l);
void interchangeSortSlistIncrease(Slist l);
void interchangeSortSlistDecrease(Slist l);
int countElementsOfSlist(Slist l);
int computeSumOfSList(Slist l);
void printEvenElementsOfSList(Slist l);
void printOddElementsOfSList(Slist l);
void printElementsInEvenIndexOfSlist(Slist l);
void printElementsInOddIndexOfSlist(Slist l);
int searchXInSlist(Slist l,int x);
int countInSlist(Slist l,int x);
Node* findMaxInSlist(Slist l);
Node* findMinInSlist(Slist l);
int findEvenMinInSList(Slist l);
int findOddMaxInSlist(Slist l);
int findEvenMaxInSList(Slist l);
int findOddMinInSlist(Slist l);
void deleteMaxInSlist(Slist &l);
void deleteMinInSlist(Slist &l);
void addXInSlist(Slist &l, Node *x);
int checkSlistIncrease(Slist l);
int checkSlistDecrease(Slist l);

int main()
{
    menu();
    return 0;
}
void menu()
{
    Slist l;
    int n;
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
	createList(l, n);
	printf("\t1. Xuat thong tin cac phan tu trong dslk.");
	printf("\n\t2. Them node vao dslk (them o dau/giua/cuoi).");
	printf("\n\t3. Xoa node trong dslk (xoa o dau/cuoi/giua).");
	printf("\n\t4. Sap xep dslk tang/giam.");
	printf("\n\t5. Dem so phan tu cua dslk.");
	printf("\n\t6. Tinh tong cac phan tu cua dslk.");
	printf("\n\t7. Xuat cac phan tu chan/le.");
	printf("\n\t8. Xuat cac phan tu o vi tri chan/le.");
	printf("\n\t9. Tim kiem x tren dslk.");
	printf("\n\t10. Dem tren dslk l co bao nhieu x.");
	printf("\n\t11. Dem so phan tu tren dslk l.");
	printf("\n\t12. Tim phan tu max/min tren dslk.");
	printf("\n\t13. Tim so chan nho nhat tren dslk.");
	printf("\n\t14. Tim so le lon nhat tren dslk. ");
	printf("\n\t15. Tim so chan lon nhat trong dslk, neu dslk khong co so chan thi tra ve -1.");
	printf("\n\t16. Tim so le nho nhat trong dslk, neu dslk khong co so le thi tra ve 0.");
	printf("\n\t17. Xoa phan tu max/min cua dslk.");
	printf("\n\t18. Them x vao dslk sao cho x la phan tu cuc dai(lon hon cac phan tu ke no).");
	printf("\n\t19. Tim day con dai dat cua dslk.");
	printf("\n\t20. Kiem tra dslk co tang dan/ giam dan khong?");

    int thaoTac;
    do
    {
        printf("\n\nNhap 0 de thoat !");
        printf("\nNhap thao tac muon thuc hien :");
        scanf("%d", &thaoTac);
        switch (thaoTac)
        {
        case 1:
        {
            printf("\n\tDanh sach lien ket la :");
            printList(l);
            break;
        }
        case 2:
        {
            int x1, x2,x3, x4;
            printf("Nhap phan tu muon them o dau : "); scanf("%d",&x1);
            Node *q1= new Node;
            Node *q2= new Node;
            Node *q3= new Node;
            Node *p= new Node;

            q1 = createNode(x1);
            addHeadSlist(l,q1);
            printf("\n\tDanh sach sau khi them o dau : ");
            printList(l);

            q2 = createNode(x2);
            addTailSList(l,q2);
            printf("\n\tDanh sach sau khi them o cuoi : ");
            printList(l);
            printf("\nNhap phan tu q va phan tu p muon them vao sau q: "); scanf("%d%d",&x3,&x4);

            q3=createNode(x3);
            p=createNode(x4);
            addAfterNodeSlist(l,q3,p);
            printf("\n\tDanh sach sau khi them %d vao sau %d : ",p->info,q3->info);
            printList(l);
            break;
        }
        case 3:
        {
            deleteHeadSlist(l);
            printf("\n\tDanh sach sau khi xoa dau : ");
            printList(l);
            deleteTailSlist(l);
            printf("\n\tDanh sach sau khi xoa cuoi : ");
            int x;
            printf("\nNhap phan tu q de xoa phan tu phia sau q : ");scanf("%d",&x);
            Node *q = new Node;
            q = createNode(x);
            deleteMidSlist(l,q);
            printf("\n\tDanh sach sau khi xoa phan tu %d : ",x);
            printList(l);
            break;
        }
        case 4:
        {
            interchangeSortSlistIncrease(l);
            printf("\n\tDanh sach sau khi sap xep tang : ");
            printList(l);
            interchangeSortSlistDecrease(l);
            printf("\n\tDanh sach sau khi sap xep giam : ");
            printList(l);
            break;
        }
        case 5:
        {
            printf("\n\tSo phan tu cua dslk : %d",countElementsOfSlist(l));
            break;
        }
        case 6:
        {
            printf("\n\tTong cac phan tu cua dslk : %d",computeSumOfSList(l));
            break;
        }
        case 7:
        {

        }
        default:
            break;
        }
    } while (thaoTac != 0);
    
}
void createList(Slist &l, int n)
{
    int x;
    Node *q = new Node;
    l.head = l.tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        printf("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        q=createNode(x);
        if (q==NULL)
        {
            printf("Khong du bo nho de cap phat ");
            getch();
            return;
        }
        if (l.head==NULL)
        {
            l.head=l.tail=q;
        }
        else
        {
            l.tail -> next = q;
            l.tail = q;
        }
    }
}
void printList(Slist l)
{
    while (l.head != NULL)          
    {
        printf("%d ", l.head->info);
        l.head = l.head->next;
    }
}
void addHeadSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head= l.tail=p;
        }
        else
        {
            p->next = l.head;
            l.head=p;
        }
    }
}
void addTailSList(Slist &l, Node *p)
{
    if(p==NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail = p;
        }
        else
        {
            l.tail-> next =p; 
            l.tail=p;
        }  
    }
}
void addAfterNodeSlist(Slist &l, Node *q, Node *p)
{
    Node *temp = new Node;
    temp = q;
    q=l.head;
    
    while (q->info != temp -> info)
    {
        q = q -> next;
    }
    if (q== NULL || p == NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail =p;
        }
        else
        {
            if ((q==l.tail))
            {
                addTailSList(l,p);
            }
            else
            {
                p->next = q->next;
                q->next=p;
            }
        }
    }
}
void deleteHeadSlist(Slist &l)
{
    if (l.head  == NULL)
    {
        return;
    }
    else
    {
        Node *temp = l.head;
        l.head= l.head->next;
        temp->next = NULL;
        delete temp;
    }
}
void deleteTailSlist(Slist &l)
{
    if (l.head == NULL)
    {
        return ;
    }
    else
    {
        Node *temp = l.head;
        Node *temp2 = l.tail;
        while (temp -> next != temp2)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        temp = l.tail;
        delete temp2;
    }
}
void deleteMidSlist(Slist &l, Node *q)
{
    Node *temp = q;
    q = l.head;
    while (q->info != temp -> info)
    {
        q=q->next;
    }
    if (l.head == NULL || q == NULL || q == l.tail)
    {
        return ;
    }
    else
    {
        if (q-> next == l.tail)
        {   
            Node *p = q -> next;
            q -> next = p ->next;
            p -> next = NULL;
            delete p;
        }
    }
}
void interchangeSortSlistIncrease(Slist l)
{
    for (Node* p = l.head; p != l.tail; p = p -> next)
    {
        for (Node* q = p -> next; q != NULL; q = q -> next)
        {
            if (p -> info < q -> info)
            {
                int temp = p -> info;
                p -> info = q -> info;
                q -> info = temp;
            }
         }
    }
}
void interchangeSortSlistDecrease(Slist l)
{
    for(Node *p = l.head; p != l.tail; p = p -> next)
    {
        for(Node *q = p->next; q != NULL ; q = q -> next)
        {
            if (p -> info > q -> info)
            {
                int temp = p -> info;
                p -> info = q -> info; 
                q -> info = temp;
            }
        }
    }
}
int countElementsOfSlist(Slist l)
{
    int count = 0;
    Node *temp = l.head;
    while (temp )   // temp == NULL
    {
        temp = temp -> next;
        count++;
    }
    return count;
}
int computeSumOfSlist(Slist l)
{
    int sum = 0;
    Node *temp= l.head;
    while (temp)    // temp == NULL
    {
        sum += temp -> info;
        temp = temp -> next;
    }
    return sum;
}
void printEvenElementsOfSlist(Slist l)
{
    if (l.head == NULL)
    {
        return ;
    }
    else
    {
        Node *temp = l.head;
        while (temp)
        {
            if(temp -> info % 2 == 0)
            {
                printf("%d ", temp -> info );
            }
            temp = temp -> next;
        }
    }
    
}





