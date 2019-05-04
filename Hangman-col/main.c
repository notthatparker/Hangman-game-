#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define red   "\033[0;31m"
#define none   "\033[0m" 
#define green "\033[0;32m"
#define cyan  "\033[1;36m"
//A standart function of MOS remade for this game
char* strlwr(char* str)
{char* t = str;
    for(;*t;++t) 
    {*t = tolower((unsigned char) *t);}return str;}
int strleno(char* s){int Siz=0;// the size of a string variable
    while(s[Siz] != '\0')/* works until the end of the string which is symbolized by \0  */
    { Siz++;/*while the loop works add one to the size (length ) of the string */
    } return Siz;// returns the size(length) 
}

void cor(){

  printf("\n\n ██████╗ ██████╗ ██████╗ ██████╗ ███████╗ ██████╗████████╗\n");
  printf("██╔════╝██╔═══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝\n");
  printf("██║     ██║   ██║██████╔╝██████╔╝█████╗  ██║        ██║   \n");
  printf("██║     ██║   ██║██╔══██╗██╔══██╗██╔══╝  ██║        ██║   \n");
  printf("╚██████╗╚██████╔╝██║  ██║██║  ██║███████╗╚██████╗   ██║   \n");
  printf(" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ ╚═════╝   ╚═╝   \n");
  
}


void title(){
    
    printf(none"-------------------------------------------------------------------\n");
    printf(red" ||  || |||||| ||\\    || |||||||| |||||||||| |||||| ||\\    ||\n");
    printf(" ||  || ||  || || \\   || ||    || ||  ||  || ||  || || \\   ||\n");
    printf(" |||||| |||||| ||  \\  || ||    __ ||  ||  || |||||| ||  \\  ||\n");
    printf(" ||  || ||  || ||   \\ || ||    || ||      || ||  || ||   \\ ||\n");
    printf(" ||  || ||  || ||    \\|| |||||||| ||      || ||  || ||    \\||\n"none);
    printf("-------------------------------------------------------------------\n\n");
}

void wow(){printf("\n             >>>>>Wow you won<<<<<                      \n\n");
    
    printf("  w          w          w  ooooooooo   w           w          w  \n");
    printf("   w        w w        w   o       o    w         w w        w   \n");
    printf("    w      w   w      w    o       o     w       w   w      w    \n");
    printf("     w    w     w    w     o       o      w     w     w    w     \n");
    printf("      w  w       w  w      o       o        w  w       w  w      \n");
    printf("       ww         ww       ooooooooo         ww         ww       \n");
}

void hang(int i){
    switch (i) {
        case 5:
        {  printf(cyan"\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("____________\n\n"none);break;}
        
        case 4:{
            printf(cyan"  _______\n");
            printf("  |/\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n"none); break;//outputs the hanging animation for lives ==4
        }
        case 3:{
            printf(cyan"  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n"none);//outputs the hanging animation for lives ==3
        
            
            break;
        }
        case 2:{ printf(cyan"  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n"none);//outputs the hanging animation for lives ==2
            
            break;
        }
        case 1:{  printf(cyan"  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("  |\n");
            printf("__|_________\n\n"none);//outputs the hanging animation for lives ==1
            
            break;
        }
          
case 0:{  printf(cyan" _________   \n");
    printf("            | \n");
    printf("|  X     X  |  \n");
    printf("|    /      |  \n");
    printf("|   ____    |\n");
    printf("|      U    | \n");
    printf("  _____\n"none);//outputs the hanging animation for lives ==0
            break;
        }
            
    
    }}
    
    

void inst(){printf("The Hangman\n");
    printf("------------\n");
    printf("welcome to the game where we hang ya , if you cant guess the word\n,well we shall give ya six pardons for the wrong letter but and \nthats all after that youre dead boi!\nif you want to end the game quit or any none character");
    printf("--------------------------------------------------------------\n");}
//need to make the rand-numb sub function to take out from the main, also

int randi(){srand(time(NULL));//calling srand to make the normal rand even more random
 int rando=rand();//variable rando is equal to the rand()
  return rando;
}
int main(){
    title();
    inst();
  
    /* initilaizes the two dimensional array for the guesses words */ char *guess[16]={
        "green","blue","tree","pizza","glow","folly" };//words to guess
    /* initilaizes the two dimensional array for the hints of guesses words , its a parralel array to the guess */ char *hint[16]={"its a color of the hills","color of the sky","something that branches","food of gods","bulb","crazy"};//hints for the words
    int randik= randi() %6;/*the rand function to choose the guessng word that uses the modulo to see which
                          number to choose from 0-XX  so the formula should be something like random_number % the size of
                          array plus+1, so we can get  reminders that would match the addresses in the arrays  */
    int lives=6,correct=0,oldcors=0,quit=0,loop=0;//varaibles for the the game such as correct guesses and etc
    int length=strleno(guess[randik]);//int for the length of the size of a random string
    int guessed[16]={0};//declares and assaigns zero to all values in all 16 addreses of the arrays
    char guess1[16]; char lettr;
    char letw;
    
    printf("word to guess:%s   random:%d  length:%d\n",guess[randik],randik,length);//for now prints the correct answer and length for the developer to see if everything is correct
    printf("--------------------------------------------------------------\n");
    printf("the length of the word :%d",length);
    printf(green"\nHint: %s\n"none,hint[randik]);//prints the hint for the word
    printf("--------------------------------------------------------------\n\n\n");
    //the main game loop
    while(correct<length){//while the amount of guessed letters is less than the length of word the game shall continue
        printf("word:");
        for(loop=0;loop<length;loop++){if(guessed[loop]==1){
                printf("%c",guess[randik][loop]);}/*if the value at address loop in the array guessed is  1
                                                   ,printf the letter stored in the same address in the array guess_word   */
            else if(guessed[loop]!=1)/*else if the  value at address isnt one than , printf underscore "_"*/
            {printf("_");}}
        printf("\n");
        
        printf("\n\nenter the letter:");
        fgets(guess1,16,stdin);/*gets the input , using fgets
                                a more secure version of gets*/
                                
                           if(((guess1[0]>='A')&&(guess1[0]<='Z'))||((guess1[0]>='a')&&(guess1[0]<='z'))){    
                           strlwr(guess1);}
                           else if(guess1[0]=' '){continue;}
                          
                         
   
        if(strncmp(guess1,"quit",4)==0){quit=1;puts("\nGame Over");printf("\nif user wants to know word was: %s \n",guess[randik]);return 0;}/*if user inputs word "quit" the
                                                                           game terminates its self*/
        lettr=guess1[0];printf("\nEntered: %c\n",lettr);/*      */
        letw=lettr;
        oldcors=correct;/*  we use the oldcors variable to see if the correct letter was already entered it continues in for loop and just writes that its wrong after the second enter     */
        for(loop=0;loop<length;loop++){/*just a for loop that goes thru the whole string and sees if the
                                        entered letter matchest ones stored in the word the user should guess */
            
            
            
            if(guessed[loop] == 1){continue;}/*   if the for loop sees that the value stored in the address loop
                                            has already been guessed and assigned value of one it shall continue working     */
            if(lettr==guess[randik][loop]){/* if the loop encounters a new letter that matches the entered
                                            letter it assignes the value of one to the "guessed" array
                                            , and on next run of the first for loop the letters that are stored in the corosponding addresses
                                            where members of array guessed are equal to one shall be outputed and than  adds one to the
                                            varaible correct on which teh whole game almost functions ,because game shall quit when the
                                            correct is gonna be more than the size*/
                guessed[loop]=1;
                correct++;}}
        
        if(oldcors==correct){lives--;printf(red"WRONG\n");printf(none"lives=%d\n \n",lives); //if the amount of correct doesnt change the input is wrong so the lives decreese
    
            {hang(lives);
                
                if (lives==0){break;}
                
                
                
            
                
               }//if the amount of lives reaches the zero game terminates its self
        }else{ cor(); 
        printf("\n\n\nCorrect:%d\n\n",correct);}}
        //if its not zero the game continues and prints the amount correct characters
    
    //over part
    if(quit==1){puts("Game Over");}//if quit was entered or the
    else if(lives==0){printf("You were Hanged,but if the dead man,\nwants to know word was: %s \n",guess[randik]);}// if game ended in failer the code outputs the correct word to the user
    else{
        wow();
    }//if the user won it outputs the congrats text
    return 0;}
