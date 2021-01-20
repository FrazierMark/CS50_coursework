#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


int get_index(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i].name) == 0)      //comparing string name w/ candidate name
        {
            return i;                   //if they match return i
        }
    return -1;

}

// Records all voter preferences into 2D array if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO

    int index = get_index(name);
    if (index != -1)
    {
        preferences[voter][rank] = index;
        return true;
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)    //if candidate is eliminated, loop will go to next rank
            {
                candidates[candidate_index].votes++;    //updates candidate vote counter
                break;
            }
        }
    }
    return;
}

int get_max(void)                                   //finds voter with max votes. (used to print winner)
{
//Need to find max votes for each candidate
    int max_votes = candidates[0].votes;            //make 1st candidate have "max_votes"
    for (int i = 1; i < candidate_count; i++)       //iterate through all candidates
        if (candidates[i].votes > max_votes)        //if another candidates has more votes then...
        {
            max_votes = candidates[i].votes;            //change "max_votes" to that candidate's votes
        }
    return max_votes;
}

// Print the winner of the election, if there is one, (using a function called get_max)
bool print_winner(void)
{
    //
    int max_votes = get_max();

    for (int i = 0; i < candidate_count; i++)       //iterate through candidates
    {
        {
            if (!candidates[i].eliminated)
                if (candidates[i].votes == max_votes
                    && max_votes > (.5 * (float) voter_count))       //if corresponding max_votes and candidates.votes found,
                {
                    printf("%s\n", candidates[i].name);     //print name of candidate
                    return true;
                }
        }
    }
    return false;
}


// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
//Need to find min votes for each candidate as long as candidate is not eliminated
    int min = candidates[0].votes;                  //make 1st candidate have ""
    for (int i = 0; i < candidate_count; i++)       //iterate through all candidates
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < min)          //if another candidates has less votes then...
            {
                min = candidates[i].votes;              //change "min_votes" to that candidate's votes
            }
        }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)              //if candidate is not eliminated
            if (candidates[i].votes != min)         //and if the candidate's votes are not min
            {
                return false;
            }
    }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)       //iterate through candidates
    {
        if (!candidates[i].eliminated)              //if candidate is not elliminated
        {
            if (candidates[i].votes == min)         //and if candidate's votes == minimum votes
            {
                candidates[i].eliminated = true;    //then eliminate candidate
            }
        }
    }
    return;
}
