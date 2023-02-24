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
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 512

#define BUFFER_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern int tokenize(char* str, char tokens[][BUFFER_LEN]);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

// comparison function for sorting
extern int cmpfunc(const void *a, const void *b);

#endif /* JEOPARDY_H_ */