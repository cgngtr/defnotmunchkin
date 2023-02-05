#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char name[16];
    int level;
    int power;
} NPC;


typedef struct 
{
    char name[16];
    int level;
    int power;
} CARD;


typedef struct 
{
    char name[16];  
    int power;
} ITEM;



int calculatePower(int s1, int s2);
int pickACard(int s1);
int curse(int s1);
int playerPower, totalPowerM[16],i=0;
int main(){

    int r = 1; // Bu değişken, oyunun devam edip etmeme durumunu kontrol edecek.
    char x;

    srand(time(NULL));
    int temppw = 1 + rand() % 3; // değişecek güç miktarı (+-3)

    int level=1,power=5;
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
            printf("You lost.\t");
            if(r==4)
                break;
            printf("Rolling a dice...\n");
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
                player.level = player.level + curse(player.level);
            }
            
        }
        else{
            printf("You won.\n");
            player.level++;
            printf("Do you want to draw a card?(y/n)");
            scanf("%s",&x);
            if(x=='y'){
                player.level = player.level + pickACard(player.level);


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

int pickACard(int s1){
    int random = 1 + rand() % 6;
    s1 = 0;
    switch(random){
        case 1:
            printf("You broke your leg. -1dmg.\n");
            s1 -= 1;
            return s1;
            break;
        case 2:
            printf("You don't feel very well. -2dmg.\n");
            s1 -= 2;
            return s1;
            break;
        case 3:
            printf("Your holy sword is broken. -3dmg.\n");
            s1 -= 3;
            return s1;
            break;
        case 4:
            printf("Natural stones that your girlfriend bought you are working, I guess. +2dmg.\n");
            s1 += 2;
            return s1;
            break;
        case 5:
            printf("Your amulet had a spark. +4dmg.\n");
            s1 += 4;
            return s1;
            break;
        case 6:
            printf("They hurt your sister. +7dmg.\n");
            s1 += 7;
            return s1;
            break;
        default:
            printf("**\n");
    }
}

int curse(int s1){
    int random = 1 + rand() % 3;
    s1 = 0;
    switch(random){
        case 1:
            printf("You broke your leg. -1dmg.\n");
            s1 -= 1;
            return s1;
            break;
        case 2:
            printf("You don't feel very well. -2dmg.\n");
            s1 -= 2;
            return s1;
            break;
        case 3:
            printf("Your holy sword is broken. -3dmg.\n");
            s1 -= 3;
            return s1;
            break;
        default:
            printf("**\n");
    }
}
