#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char name[20];
    int level;
    int power;
} NPC;


typedef struct 
{
    char name[20];
    char detail[200];
    int level;
    int power;
} CARD;


typedef struct 
{
    char name[20];  
    int power;
} ITEM;



int calculatePower(int s1, int s2);
int playerPower, totalPowerM[20],i=0;
int main(){

    int r = 1; // Bu değişken, oyunun devam edip etmeme durumunu kontrol edecek.
    char x;

    srand(time(NULL));
    int temppw = 1 + rand() % 3; // değişecek güç miktarı (+-3)

    int level=1,power=0;
    NPC player = {"Reveck",level,power};

    if(rand() % 2==0) // güç için + mı - mi kararı.
        power += temppw;
    else if(rand() % 2 == 1)
        power -= temppw;
    
    NPC monster1 = {"Basilisk",1,0+power};
    NPC monster2 = {"Chimera",1,2+power};
    NPC monster3 = {"Pontianak",1,4+power};
    NPC monster4 = {"Dragon",1,9+power};
    CARD card1 = {""};

    NPC monsters[] = {monster1, monster2, monster3, monster4}; 

    while(r<=4){
        totalPowerM[i] = calculatePower(monsters[i].level,monsters[i].power); // monster total
        playerPower = calculatePower(player.level,player.power); // player total
        printf("Total power of the player = %d\n",playerPower);
        printf("You've encountered with %s with power of %d.\n",monsters[i].name,totalPowerM[i]);
        int monsterPower = totalPowerM[i];

        if(monsterPower>playerPower){
            printf("You lost.\tRolling a dice...\n");
            srand(time(NULL));
            int temp = 1 + rand() % 6;
            if(temp >= 5)
            {
                printf("You rolled %d\n",temp);
                printf("You've managed to escape.\n");
            }
                
            else{
                printf("You rolled %d\n",temp);
                printf("\"A bad thing\" is gonna happen to you.\n"); // Sonrasında buraya bir ceza eklenecek.
            }
            
        }
        else{
            printf("You won.\n");
            player.level++;
            printf("Do you want to draw a card?(y/n)");
            scanf("%s",&x);
            if(x=='y'){
                
            }
            else{

            }
        }
        r++;
        i++;
    }
    
    
}

int calculatePower(int s1, int s2)
{
    return s1+s2;
}
