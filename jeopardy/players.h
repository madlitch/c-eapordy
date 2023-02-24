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
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 512

typedef struct {
    char name[MAX_LEN];
    int score;
} player;

extern void update_score(player *players, int num_players, char *name, int score);

#endif