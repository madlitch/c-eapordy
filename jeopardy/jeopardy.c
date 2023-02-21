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

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

int main(int argc, char *argv[]) {
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Enter your names:\n");

    // initialize each of the players in the array
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        update_score(players, NUM_PLAYERS, players[i].name, 0);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
        char category[MAX_LEN];
        char answer[MAX_LEN];
        int value = 0;
        int questions_answered = 0;

        while (questions_answered < NUM_QUESTIONS) {
            for (int i = 0; i < NUM_PLAYERS; i++) {
                // Call functions from the questions and players source files
                display_categories();
                start: printf("%s, enter a category, then the value\n", players[i].name);
                printf("Category (lowercase): ");
                scanf("%s", &category);
                printf("Value: ");
                scanf("%d", &value);

                if (invalid_question(category, value)) {
                    printf("Already answered/Doesn't exist!\n");
                    goto start;
                }

                display_question(category, value);

                printf("Answer (in all lowercase): ");
                scanf("%s", answer);

                if (valid_answer(category, value, answer)) {
                    printf("That's right! You get %d points!\n", value);
                    update_score(players, NUM_PLAYERS, players[i].name, players[i].score + value);
                } else {
                    printf("Sorry, the answer is '%s'!\n", question_answer(category, value));
                }

                answer_question(category, value);
                questions_answered++;
                show_results(players, NUM_PLAYERS);
            }
        }
        break;
    }
    return EXIT_SUCCESS;
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player: %s, Score: %d\n", players[i].name, players[i].score);
    }
}
