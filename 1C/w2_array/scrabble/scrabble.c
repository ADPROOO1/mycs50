# include <cs50.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>

int letter_value[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4,10};

int get_score(string word);

int main(void)
{
    // Prompt user for two words.
    string player1_word = get_string("Player 1: ");
    string player2_word = get_string("Player 2: ");

    // Calculate Scores
    int player1_score = get_score(player1_word);
    int player2_score = get_score(player2_word);

    // Announce the winner
    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Define score_calculator function
int get_score(string word)
{
    int length = strlen(word);
    int score = 0;
    for (int i = 0; i < length; i++)
    {
        int letter[length];
        letter[i] = toupper(word[i]) - 65;

        if (letter[i] < 26 && letter[i] > 0)
        {
            score += letter_value[letter[i]];
        }
        else
        {
            score += 0;
        }
    }
    return score;
}
