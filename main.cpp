#include <bits/stdc++.h>
#include "DoubleLinkedList.h"
using namespace std;

DoubleLinkedList Zuma;

const int LOSS_SIZE = 20,INITIAL = 10;

int generations = LOSS_SIZE / 5;

void print_Zuma(){
    for(int i =0 ; i < Zuma.count_nodes() ; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i =0 ; i < Zuma.count_nodes() ; i++){
        if(i>=10){
            cout << ' ';
            Zuma.print_element_idx(i);
            cout << ' ';
        }
        else{
            Zuma.print_element_idx(i);
            cout << ' ';
        }
    }
    cout<<endl;

}

void user_input(int &idx,char color){
    cout<<"Current Color : "<<color<<endl;
    do{
        cout<<"Enter the index of insertion : ";
        cin>>idx;
    }
    while(idx < 0 || idx > Zuma.count_nodes());
}

char generate_new_color(){
    int c = rand() % 4 + 1;
    switch(c){
        case 1:
            return 'B';
        case 2:
            return 'G';
        case 3:
            return 'Y';
        case 4:
            return 'R';
    }
}

void generate_Game(){
    int i = 0;
    while(i<INITIAL){
        Zuma.insert_begin(generate_new_color());
        i+=1;
    }
}

void generate_At_head(){
    if(generations != 0){
        Zuma.insert_begin(generate_new_color());
        generations-=1;
    }
}

void insert_color(int idx,char color){
    if (idx == 0)
    {
        Zuma.insert_begin(color);
    }
    else if(idx == Zuma.count_nodes())
    {
        Zuma.insert_end(color);
    }
    else
    {
        Zuma.insert_node(Zuma.get_element_idx(idx-1),color);
    }
}

void remove_duplicates(int idx){
    Zuma.delete_corresponding(idx);
}

bool check_win(){
    if(Zuma.count_nodes() == 0){
        return true;
    }
    else{
        return false;
    }
}

bool check_loss(){
    if(Zuma.count_nodes() >= LOSS_SIZE){
        return true;
    }
    else{
        return false;
    }
}

void Clear_Game(){
    if(Zuma.head != NULL){
        Zuma.deleteAllNodes();
    }
}

void Game(){
    cout<<"---------------------Welcome !!!---------------------"<<endl;
    cout<<"----------------------Zuma-Game----------------------"<<endl;
    while(true){
        print_Zuma();
        cout<<endl;
        int idx;
        char color = generate_new_color();

        user_input(idx,color);

        insert_color(idx,color);

        remove_duplicates(idx);

        if(check_win()){
            cout<<"Congrats, you have won the game!"<<endl;
            break;
        }

        if(check_loss()){
            cout<<"Ooh! That's a loss!"<<endl;
            break;
        }
        generate_At_head();
        cout<<endl;
    }
}

int main()
{
    srand (time(NULL));
    while(true){
        Clear_Game();
        generate_Game();
        Game();
        cout<<"Do you want to re-play (Y/y)-(N/n) : ";
        char choice;
        cin>>choice;
        if(choice == 'N' || choice == 'n'){
            break;
        }
    }
    return 0;
}
