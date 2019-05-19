#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

typedef int Data;
struct NODE
{
Data Key;
NODE *Left, *Right;
};
typedef NODE *TREE;
TREE root;
int insertNode(TREE &T, Data x) 
{
    if (T != NULL)
    {
        if (T-> Key == x) return -1;  
        if (T-> Key > x) return insertNode(T->Left, x); 
        else if (T-> Key < x) return insertNode(T->Right, x); 
    }
    T = (NODE *) malloc(sizeof(NODE));
    if (T == NULL) return 0;
    T->Key = x;
    T->Left = T->Right = NULL;
    return 1;
}
void CreateTree(TREE &T)
{
    int x;
    while (1)
    {
        printf("Nhap Vao Node: ");
        scanf("%d", &x);
        if (x == 0) break;
        int check = insertNode(T, x);
        if (check == -1) printf("Node da ton tai!\n");
        else if (check == 0) printf("Khong du bo nho");
  
    }
}
NODE* SearchNode(TREE T, Data X)
{
if(T)
{
if(T->Key == X)
return T;
if(T->Key > X)
return SearchNode(T->Left, X);
return SearchNode(T->Right, X);
}
return NULL;
}
NODE * searchNode(TREE Root, Data x)
{
NODE *p = Root;
while (p != NULL)
{
if(x == p->Key) return p;
else
if(x < p->Key) p = p->Left;
else p = p->Right;
}
return NULL;
}
void LNR(TREE T)
{
     if(T!=NULL)
     {
      LNR(T->Left);
      printf("%d \t",T->Key);
      LNR(T->Right);
     }
}
void LRN(TREE T)
{
	if (T != NULL)
	{
		LRN(T->Left);
		LRN(T->Right);
		printf("%d \t", T->Key);
	}
}
void NLR(TREE T)
{
	if (T != NULL)
	{
		printf("%d \t", T->Key);
		NLR(T->Left);
		NLR(T->Right);
	}
}
void RemoveTree(TREE &T)
{
if(T) {
RemoveTree(T->Left);
RemoveTree(T->Right);
delete(T);
	}
}

int main()
{	
	int p;
	int q;
	int key;
	int x;
	bool Nhap = false;
	while(true){
        system("cls");
        printf("***********************************************\n");
        printf("**  CHUONG TRINH THAO TAC TREN CAY NHI PHAN  **\n");
        printf("**      1. Nhap Du Lieu Node (Nhap 0 dung)   **\n");
        printf("**      2. Xoa Node                          **\n");
        printf("**      3. Duyet Node Theo LNR               **\n");
        printf("**      4. Duyet Node Theo LRN               **\n");
        printf("**      5. Duyet Node Theo NLR               **\n");
        printf("**      6. Xoa Tree                          **\n");
        printf("**      0. Thoat                             **\n");
        printf("***********************************************\n");
        printf("**         Nhap lua chon cua ban             **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
               	printf("\nBan Da Chon Nhap Node!\n");
                CreateTree(root);	
                printf("\nBan Da Nhap Thanh Cong!\n");
                Nhap = true;
                printf("\nBam Phim Bat Ky De Tiep Tuc!\n");
                getch();
                break;
            case 2:
               	if(Nhap){
                    printf("\nBan da chon xoa node!\n");
                    printf("\nNhap nut can xoa!\n");
                }else{
                    printf("\nNhap node truoc!!!!\n");
                    CreateTree(root);
                }
                printf("\nBam phim bat ki de tiep Tuc!\n");
                getch();
                break;
            case 3:
               	if(Nhap){
                    printf("\nBan da chon Duyet Cay!\n");
                    printf("\nKet Qua:\n");
                    LNR(root);
                }else{
                    printf("\nNhap node Truoc!!!!\n");
                    CreateTree(root);
                }
                printf("\nBam Phim bat ki de tiep tuc!");
                getch();
                break;
            case 4:
               	if(Nhap){
                    printf("\nBan da chon duyet Cay!\n");
                    printf("\nKet Qua:\n");
                    LRN(root);
                }else{
                    printf("\nNhap Node truoc!!!!\n");
                    CreateTree(root);
                }
                printf("\nBam phim bat ki de tiep Tuc!");
                getch();
                break;
            case 5:
               	if(Nhap){
                    printf("\nBan da Chon duyet cay!\n");
                    printf("\nKet qua:\n");
                    NLR(root);                   
                }else{
                    printf("\nNhap node truoc!!!!\n");
                    CreateTree(root);
                }
                printf("\nBam phim bat ki de tiep tuc!");
                getch();
                break;
            case 6:
               	if(Nhap){
                    printf("\nBan da chon xoa tree!\n");
                    RemoveTree(root);
                    printf("\nXoa tree thanh cong!!!!\n");
                }else{
                    printf("\nNhap node truoc!!!!\n");
                    CreateTree(root);
                }
                printf("\nBam phim bat ki de tiep tuc!\n");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!\n");
                return 0;
            default:
            	printf("\nKhong co chuc nang nay!!!!\n");
                printf("\nBam Phim Bat Ky De Tiep Tuc!\n");
                break;
            	}           	
	}
	TREE T;
    T=NULL;
	getch();
}
