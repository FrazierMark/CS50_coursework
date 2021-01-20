#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count (using struct)
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
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

// Update vote totals given a new vote
bool vote(string name)
{
    //figure out the index corresponding to the name that's given
    int candidate_index = get_index(name);
    if (candidate_index != -1)                 //if candidate is found, increase vote counter
    {
        candidates[candidate_index].votes++;
        return true;
    }

    return false;
}


//1st Find

int get_max(void)
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

// Print the winner (or winners) of the election
void print_winner(void)
{
    //
    int max_votes = get_max();

    for (int i = 0; i < candidate_count; i++)       //iterate through one last time
    {
        if (candidates[i].votes == max_votes)       //if corresponding max_votes and candidates.votes found,
        {
            printf("%s\n", candidates[i].name);     //print name of candidate
        }
    }
    return;
}

