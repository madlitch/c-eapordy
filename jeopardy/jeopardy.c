/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U Operating Systems
 *
 * Massimo Albanese 100616057
 * Lyba Mughees 100750490
 * Daanyaal Tahir 100746644
 * Malaika Sharif 100651617
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4
#define MAX_TOKENS 3

// Put global environment variables here
extern question questions[NUM_QUESTIONS];

extern int tokenize(char *str, char tokens[][BUFFER_LEN]) {
    const char delimiter[2] = " ";
    int tokens_count = 0;
    char *token = strtok(str, delimiter);
    while (token != NULL) {
        strcpy(tokens[tokens_count], token);
        tokens_count++;
        token = strtok(NULL, delimiter);
    }
    return tokens_count;
}

int main(int argc, char *argv[]) {
    player players[NUM_PLAYERS];
    char tokens[MAX_TOKENS][BUFFER_LEN] = {0};
    char category[MAX_LEN];
    char answer[MAX_LEN];
    char input[MAX_LEN];
    int value = 0;
    int questions_answered = 12;

    initialize_game();

    printf("Enter your names:\n");

    //     initialize each of the players in the array
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d/%d: ", i + 1, NUM_PLAYERS);
        scanf("%s", players[i].name);
        update_score(players, NUM_PLAYERS, players[i].name, 0);
    }

    while (questions_answered < NUM_QUESTIONS) {
        for (int i = 0; i < NUM_PLAYERS; i++) {
            // Call functions from the questions and players source files
            display_categories();
            start:
            printf("%s, enter a category, then the value\n", players[i].name);
            fgets(input, MAX_LEN, stdin);
            tokenize(input, tokens);

            strcpy(category, tokens[0]);
            value = atoi(tokens[1]);

//            check if question either doesn't exist or is already answered
            if (invalid_question(category, value)) {
                printf("Already answered/Doesn't exist!\n");
                goto start;
            }

            display_question(category, value);

            printf("Answer (in all lowercase, who/what is): ");
            fgets(input, MAX_LEN, stdin);
            tokenize(input, tokens);
            strcpy(answer, tokens[2]);
            answer[strcspn(answer, "\n")] = 0;

            if (valid_answer(category, value, answer)) {
                printf("That's right! You get %d points!\n", value);
                update_score(players, NUM_PLAYERS, players[i].name, players[i].score + value);
            } else {
                printf("Sorry, the answer is '%s'!\n", question_answer(category, value));
            }

            answer_question(category, value);
            questions_answered++;
        }
    }
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}

//    comparison function for sorting the player array
extern int cmpfunc(const void *a, const void *b) {
    const player *playerA = (const player *)a;
    const player *playerB = (const player *)b;

    int score = 0;
    // compare the score fields
    if (playerA->score != playerB->score) {
        score = playerA->score - playerB->score;
    } else {
        // if the scores are tied, compare the name fields
        score = strcmp(playerA->name, playerB->name);
    }

    // descending sort
    return -1 * score;
}

// displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
//    sort the player array by scores
    qsort(players, 4, sizeof(player), cmpfunc);

//    print the players and the winner
    for (int i = 0; i < num_players; i++) {
        if (i == 0)
            printf("Winner!: ");
        printf("Player: %s, Score: %d\n", players[i].name, players[i].score);
    }
}
