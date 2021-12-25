#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>

char Grid[3][3];

void display(int,int,int);
void play_Game();
bool check_Conditions();

int main(){
    
    do{ 
        int choice;
        printf("#####################################################################################\n");
        std::cout<<"                            Tick-Tack-Toe Game                                           \n";
        printf("#####################################################################################\n\n\n");
        printf("                           1.Play Game\n\n");
        printf("                           2.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                play_Game();
                break;
            case 2:
                printf("Thanks for playing our game ^.^\n");
                return 0;
            default:
                printf("Invalid choice :(\n");
        }
    }while(1);
    play_Game();
    return 0;
}

                    //Display function to display grid.....you can call it update function too 
void display(int x,int y,int which_player){
        printf("\n\n");
        if(which_player==1)
            Grid[x][y]='X';
        else if(which_player==2)
            Grid[x][y]='O';

        for(int i=0;i<3;i++){
            printf("\t\t\t");
            for(int j=0;j<3;j++){
                printf("%c\t\t",Grid[i][j]);
            }
            printf("\n\n");
        }
        printf("\n\n");
}
                            //PlayGame function....Everything happens here
void play_Game(){
    bool isGameOpen=true;
    int x1,y1,x2,y2, player,ch;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Grid[i][j]='_';
        }
    }
    display(0,0,0);
    
    while(isGameOpen){  
        bool valid_input=false;
        while(!valid_input)
        {
            printf("\nPlayer1's Turn\nEnter the row and column : ");
            player=1;
            scanf("%d %d",&x1,&y1);
            if(Grid[x1][y1]!='O'){
                display(x1,y1,player);
                valid_input= true;
            }else{
                printf("\nInvalid index given\n");
                valid_input=false;
            }  
        }
        isGameOpen=check_Conditions();
        if(!isGameOpen)
            break;
        
        valid_input=false;
        while(!valid_input){
            printf("\n\nPlayer2's Turn\nEnter the row and column : ");
            player=2;
            scanf("%d %d",&x2,&y2);
            if(Grid[x2][y2]!='X'){
                display(x2,y2,player);
                valid_input=true;
            }
            else{
                printf("\nInvalid index given\n");
                valid_input=false;
            }
        }
            isGameOpen=check_Conditions();
    }    
    printf("\nDo you want to play again?\n %c Enter 1 if yes\n %c Enter 2 if No\n\nYour choice: ",219,219);
    scanf("%d",&ch);
    if(ch==1)
        play_Game();
    else
        return;
}

                        //Checking for different conditions 

bool check_Conditions(){
                //Checking for matching row
    for(int i=0;i<3;i++){
        if(Grid[i][0]==Grid[i][1]&& Grid[i][1]==Grid[i][2]){
            if(Grid[i][1] =='X'){
                printf("\nPlayer 1 Won!!\n");
                return false;
            }
            else if (Grid[i][1] =='O'){
                printf("\nPlayer 2 Won!!\n");
                return false;
            }    
            else if(Grid[i][1] =='_')
                return true;        
        }
        else if(Grid[0][i]==Grid[1][i]&& Grid[1][i]==Grid[2][i]){
            if(Grid[1][i] =='X'){
                printf("\nPlayer 1 Won!!\n");
                return false;
            }
            else if (Grid[1][i] =='O'){
                printf("\nPlayer 2 Won!!\n");
                return false;
            }    
            else if(Grid[1][i] =='_')
                return true; 
        }
    }
    // Checking for matching diagnols
    if((Grid[0][0]==Grid[1][1]&&Grid[1][1]==Grid[2][2])||(Grid[0][2]==Grid[1][1]&&Grid[1][1]==Grid[2][0])){
        if(Grid[1][1] =='X'){
                printf("\nPlayer 1 Won!!\n");
                return false;
            }
            else if (Grid[1][1] =='O'){
                printf("\nPlayer 2 Won!!\n");
                return false;
            }    
            else if(Grid[1][1] =='_')
                return true; 
    }
    // Checking if There is only one cell left (no possible outcome ....i.e, Draw )
    int count=0;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(Grid[i][j]=='_')
                count++;
        }
    }
    printf("%d",count);
    if(count == 1){
        printf("\nWow, Its a Draw\n");
        return false;
    }
}
