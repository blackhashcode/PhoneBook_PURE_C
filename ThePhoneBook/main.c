#include <stdio.h>
#include <string.h>

struct Data{
    char fname[50];
    char lname[50];
    char fnum[12];
    char snum[12];
    char email[50];
    char username[50];
    char password[50];
};


typedef struct Data user;

void DeleteAll();
void DeleteAll(){

    user l;

    printf("reenter username to open the file: \n");
    printf("Warning if u delete all data, the file will be deleted as well\n");
    fflush(stdin);
    gets(l.username);

    if(remove(strcat(l.username,".txt"))==0){
        printf("the file has been deleted\n");
        printf("you will be redirected to Login and registration page\n");
    }
    else{
        printf("unable to delete file\n");
    }

    boot();
}

void Search();
void Search(){
    FILE *search;
    user l;
    char fname[50];
    char lname[50];
    int op;
    char *ch[50];


    fflush(stdin);
    printf("re-enter username to open ur file:\n");
    gets(l.username);

    search = fopen(strcat(l.username,".txt"),"r");

    if(search == NULL){
        printf("file is not found returning to search function\n");
        Search();

    }
    else{
        printf("enter 1 to search by first name or 2 to search by lastname: \n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
        case 1:
            fflush(stdin);
            printf("enter first name: \n");
            gets(fname);

            while(!feof(search)){
                fscanf(search,"%s", ch);
                if(!strcmp(ch,fname)==0){
                    printf("entry found\n");

                }
                else{
                    printf("NO entry found\n");
                }
                break;
            }
                fclose(search);
                Menu();
                break;
        case 2:
            fflush(stdin);
            printf("enter surname: \n");
            gets(lname);

            while(!feof(search)){
                fscanf(search,"%s",ch);
                if(!strcmp(ch,lname)==0){
                    printf("entry found\n");
                }
                else{
                    printf("NO entry found\n");
                }
                break;
            }
                fclose(search);
                Menu();
                break;

        default:
            fclose(search);
            printf("wrong input redirecting to search function: \n");
            Search();
            break;
        }
    }
}

void ListAll();
void ListAll(){
    FILE *list;
    user l;
    char ch;


    fflush(stdin);
    printf("please re-enter username to open the file: \n");
    gets(l.username);

    list = fopen(strcat(l.username,".txt"), "r");
    if(list == NULL){
        printf("file cannot be found, redirecting to Main Menu: \n");
        Menu();
    }
    else{
        while(!feof(list)){
            ch = fgetc(list);
            printf("%c", ch);
        }
        fclose(list);
    }
    Menu();
}


void AddContact();
void AddContact(){
    FILE *add;
    user l;

    fflush(stdin);
    printf("please re-enter username to open file: \n");
    gets(l.username);

    printf("\nEnter contact first name: \n");
    scanf("%s", &l.fname);

    printf("Enter contact surname: \n");
    scanf("%s",&l.lname);

    printf("Enter First Number of contact: \n");
    scanf("%s", &l.fnum);

    printf("Enter Second Number if contacts doesnt have Enter null value: \n");
    scanf("%s", &l.snum);

    printf("Enter email of contact: \n");
    scanf("%s", &l.email);

    add = fopen(strcat(l.username,".txt"), "a");

    if(add == NULL){
        printf("file not found so redirecting back to add contact page \n");
        AddContact();
    }

    fprintf(add,"\nfirst name: %s", l.fname);
    fprintf(add,"\nsurname name: %s", l.lname);
    fprintf(add,"\nfirst num: %s", l.fnum);
    fprintf(add,"\nsecond num: %s", l.snum);
    fprintf(add,"\nemail : %s\n", l.email);

    fclose(add);

    Menu();
}


void Menu();
void Menu(){
    int op;

    printf("Enter \n1: Add contact\n2: Delete All\n3: List All\n4: Search\n5: Logout\n");
    fflush(stdin);
    scanf("%d", &op);

    switch(op){
    case 1:
        printf("redirecting to add contact: \n");
        system("CLS");
        AddContact();
        break;
    case 2:
        printf("redirecting to delete all: \n");
        system("CLS");
        DeleteAll();
        break;
    case 3:
        printf("redirecting to list all: \n");
        system("CLS");
        ListAll();
        break;
    case 4:
        printf("redirecting to Search: \n");
        system("CLS");
        Search();
        break;
    case 5:
        system("CLS");
        boot();
        break;
    default:
        Menu();
        break;
    }

}

void Registration();
void Registration(){
    user l;

    FILE *reg;

    fflush(stdin);
    printf("Enter your desired username: \n");
    gets(l.username);
    printf("Enter your desired password: \n");
    gets(l.password);
    printf("Thank you for registering: \n");

    reg = fopen(strcat(l.username,".txt"), "a");
    if(reg==NULL){
        printf("file error");
    }

    fprintf(reg,"%s \n", l.password);

    fclose(reg);

    printf("redirecting user to Main Menu \n");
    system("CLS");
    Menu();
}

void Login();
void Login(){

    user l;

    char password[50];

    FILE *login;

    fflush(stdin);

    printf("enter your username: \n");
    gets(l.username);
    printf("enter password: \n");
    gets(password);

    login = fopen(strcat(l.username,".txt"), "r");
    if(login==NULL){
        printf("User not registered \n");
        printf("Redirecting to Home Page \n");
        boot();
    }
    else{
        fscanf(login,"%s",&l.password);

    if(strcmp(l.password,password)==0){
        printf("Verified\n");
        system("CLS");
        fclose(login);
        Menu();
    }
    else{
        printf("Unverified, hence redirecting to homepage \n");
        fclose(login);
        boot();
    }
    }
}

void boot();
void boot(){
    int op;
    printf("Enter: \n1: for registration \n2: for login \n3: to exit\n");
    scanf("%d", &op);

    switch(op){
    case 1:
        system("CLS");
        Registration();
        break;
    case 2:
        system("CLS");
        Login();
        break;
    case 3:
        exit(1);
    default:
        system("CLS");
        boot();
        break;
    }
}

int main(){
    boot();
}
