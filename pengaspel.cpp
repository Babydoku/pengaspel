#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int getPlayerBet(int budget){

   int bet;
  
   while(1){
      
      printf("you have %d SEK. How much would you like to bet?:", budget );
      scanf("%d", &bet);
      while(getchar()!='\n');
      
      if(bet < 0 || bet > budget){
         printf("wrong input! try again.\n");

      } else {
      return bet;
      
      }   
   }
}


char getPlayerGuess(){
   
   char input;
   

   while(1){
      printf("what do you bet on (h/t)?: ");
      scanf(" %c", &input);
      
      while(getchar() != '\n')
      ; 
      
       if(input == 'h' || input =='t'){
         return input;
  
      } else {
         printf("invalid choice, enter 'h' (heads) or 't' (tails)?\n");
      
     }
  
   }

}


char getCointoss(){

   int Cointoss = rand() % 100;

    if(Cointoss < 52) {
      return 't';

    } else {
      return 'h';
   }
}

int main(){
   srand(time(NULL)); //man kan också använda 0 om man vill. 

   int budget = 100;
   int bet;
   char guess, resultat;
   
   while(budget > 0){ 
    bet = getPlayerBet(budget);
     
      if(bet == 0){
         printf("You have left the game with %d SEK\n", budget);
          break;

      }   

   guess = getPlayerGuess();
   resultat = getCointoss();
   
   printf("Tossing the coin...\n");
   printf("It's %s.\n", (resultat == 'h') ? "heads" : "tails");

   if(guess == resultat){
      printf("You have won %d SEK!\n", bet);
      budget +=bet;
   
   } else {
      printf("Unfortunately you have lost %d SEK\n", bet);
      budget -=bet;

      if(budget == 0){
         printf("You dont have any money left!\n");
         break;
   
         }
      }         
   }
      
      return 0;     
}

   




