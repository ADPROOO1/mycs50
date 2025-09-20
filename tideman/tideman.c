#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    int match = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            match++;
        }
    }

    if (match == 0)
    {
        return false;
    }
    return true;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((j > i) && (ranks[i] != ranks[j]))
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // Loop through each candidate to get preferences value
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int ioverj = preferences[i][j];
            int joveri = preferences[j][i];
            if (i != j && ioverj > joveri)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Reverse-Bubble Sort
    // While swap_counter is > 0, then execute for-loop
    bool cycle = true;
    while (cycle)
    {
        cycle = false;
        // left_index should not reach pair_count
        for (int left_index = 0; left_index < pair_count - 1; left_index++)
        {
            // right_index = next int of left_index
            int right_index = left_index + 1;
            // right > left, then store left in pocket and put store right's winner and loser as left pair index, then save put pocket's winner and loser to now vacant right
            int left = preferences[pairs[left_index].winner][pairs[left_index].loser] - preferences[pairs[left_index].loser][pairs[left_index].winner];
            int right = preferences[pairs[right_index].winner][pairs[right_index].loser] - preferences[pairs[right_index].loser][pairs[right_index].winner];
            // if right > left
            if (right > left)
            {
                // Store left in pocket (pair_count + 1)
                pairs[pair_count + 1] = pairs[left_index];
                // Put right to left
                pairs[left_index] = pairs[right_index];
                // Get pocket by right
                pairs[right_index] = pairs[pair_count + 1];
                // Increment swap_counter
                cycle = true;
            }
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
        int diff = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        // printf("Pairs%i = %i\n", i, diff);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!is_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    typedef struct
    {
        int score;
        bool winner;
    } status;
    status winning_candidates[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        winning_candidates[i].score = 0;
    }

    // Get all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
            {
                winning_candidates[i].score++;
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
            {
                winning_candidates[j].score--;
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("WinningCand[%i] = %i\n", i, winning_candidates[i].score);
    }

    return;
}

// returns if locked pairs returns in a cycle
bool is_cycle(int start, int loser)
{
    // base case
    if (loser == start)
    {
        return true;
    }

    // Recurse
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (is_cycle(start, i))
            {
                return true;
            }
        }
    }
    // If won't result a cycle
    return false;
}
