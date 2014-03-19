///Word Jumble by Sokna Ly
//this code was compiled by Borland C++ 5.02 successfully
#include <stdlib.h>
#include <iostream>
#include <conio.h>
const int NUM=10;
const int SIZE=100;
void main(){
    char *words[NUM][SIZE]={{"hello","used as a greeting when you see or meet someone."},
        {"better","comparitive of good."},
        {"password","a secret group of letters or numbers that you must type into a computer before you can use a system or program."},
        {"guest","someone who is invited to an event or special occasion."},
        {"persuade","to make someone decide to do something, especially by giving them reasons why they should do it."},
        {"anniversary","a date on which something special or important happened in a previous year."},
        {"computer","an electronic machine that stores information and uses programs to help you."},
        {"economy","the system by which a country's money and goods are produced and used."},
        {"disable","to make someone unable to use a part of their body properly."},
        {"vulnerable","someone who is vulnerable can be easily harmed or hurt."}
    };
LOOP:
    clrscr();
    cout<<"\t\tWelcome to Word Jumple!!!(Dev::Sokna Ly)\n\n\n"<<endl;
    //choose one word randomly
    randomize();
    int choice=rand()%9;
    char chosenWord[20];
    char hint[100];
    strcpy(chosenWord,words[choice][0]);
    strcpy(hint,words[choice][1]);
    char jumble[20];
    strcpy(jumble,chosenWord);
    for(unsigned int i=0;i<strlen(jumble);++i){
        int index1=rand()%strlen(jumble);
        int index2=rand()%strlen(jumble);
        char tmp=jumble[index1];
        jumble[index1]=jumble[index2];
        jumble[index2]=tmp;
    }
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout <<"Enter 'answer' for an answer.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: "<<jumble<<endl;
AGAIN:
    cout<<"What is your answer???: ";
    char answer[15];
    cin>>answer;
    while(strcmp(answer,"quit")!=0){
        if(strcmp(answer,chosenWord)==0){
            cout<<"Awesome! You're correct."<<endl;
            char choose;
            cout<<"Do you want to play again???('y'/'n'): ";
            cin>>choose;
            if(choose=='y' || choose=='Y')
                goto LOOP;
            else
                exit(0);
            
        }else if(strcmpi(answer,"hint")==0){
            cout<<"***HINT: "<<hint<<endl;
            goto AGAIN;
        }else if(strcmpi(answer,"answer")==0){
            cout<<"The Answer is: "<<chosenWord<<endl;
            char choose;
            cout<<"Do you want to play again???('y'/'n'): ";
            cin>>choose;
            if(choose=='y' || choose=='Y')
                goto LOOP;
            else
                exit(0);
        }else{
            cout<<"Incorrect!"<<endl<<"Please try again!!!"<<endl;
            goto AGAIN;
        }
    }
    exit(0);
    getch();
}