#include <iostream>
#include <string.h>
#include <ctime>

// using namespace std; <---- remember you could use it to remove namespace STD:: :)
// main function 

void PrintIntroduction(int Difficulty)
{
// print the intro
    std:: cout << std::endl ;
    std:: cout << "*************************************************************************************************************************************";
    std:: cout << std::endl ;
    std:: cout << std::endl ;
    std:: cout << "You are hacking into a level " << Difficulty << " super computer to extract nucular codes to stop the distruction of the US... \n \n";
    std:: cout << "Enter the correct code to continue... \n \n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // declaring valuables 
    const int CodeA = rand() % 2 + Difficulty;
    const int CodeB = rand() % 2 + Difficulty;
    const int CodeC = rand() % 2 + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC ;
    const int CodeProduct = CodeA * CodeB * CodeC ;

 
    // print CodeSum and CodeProduct 
    std:: cout << "There is 3 numbers in the code \n \n"; 
    std:: cout << "$ The numbers add up to: " << CodeSum << std:: endl << std:: endl ;
    std:: cout << "$ The numbers multiply to: " << CodeProduct << std:: endl << std:: endl;
    
    // store plaer guess
    int GuessA, GuessB, GuessC;  

    std:: cin >> GuessA ;
    std:: cin >> GuessB ;
    std:: cin >> GuessC ; 

    std:: cout << std::endl ;


    int  GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if the player win or lose
    if(GuessProduct == CodeProduct && GuessSum == CodeSum )
    {   
        std:: cout << "you are correct ! \n ";
        return true;
    }
    else 
    {
        std:: cout << "you have entered the wrong code please try again :( \n ";
        return false;
    }

  

}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of the day
    int LevelDifficulty = 1; 
    const int MaxDifficulty = 5 ;
    while(LevelDifficulty <= MaxDifficulty) // loop the game until all the levels are done 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;

        }
    }

    std:: cout << std::endl ;
    std:: cout << "You have beaten the super computer and saved the united states" ;
    return 0;
}