#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty) {
    cout << "\n\nHurry !! You are an agent need to access of server's room of level " << Difficulty << endl;
    cout << "Guess the correct code...\n\n";
}
bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;


    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    cout << "Hint!\n";
    cout << "*When you add you must have: " << CodeSum << endl;
    cout << "*When you multiply you must have: " << CodeProduct << endl;
    cout << "Good luck!\n\n";

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum, GuessProduct;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;


    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        cout << "\nWell Done! Keep going\n\n";
        return true;

    }
    else
    {
        cout << "\nCareful! You entered wrong code\n\n";
        return false;

    }
}
// Triple X game
int main()
{
    srand(time(NULL));  //Create a new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();    //clear any error 
        cin.ignore();   //Discard the buffer

        if (bLevelComplete)
        {
            //Increasing the level difficulty
            ++LevelDifficulty;
        }
        else
        {
            cout << "Congrats! You completed the game\n";
            exit(0);
        }
    }
    return 0;
}