/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void) {
    // initialize each question struct and assign it to the questions array
//    q1
    strcpy(questions[0].category, "nature");
    strcpy(questions[0].question, "How many oceans are there?");
    strcpy(questions[0].answer, "5");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "nature");
    strcpy(questions[1].question, "How many oceans are there?");
    strcpy(questions[1].answer, "5");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "nature");
    strcpy(questions[2].question, "How many oceans are there?");
    strcpy(questions[2].answer, "5");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "nature");
    strcpy(questions[3].question, "How many oceans are there?");
    strcpy(questions[3].answer, "5");
    questions[3].value = 400;
    questions[3].answered = false;

    strcpy(questions[4].category, "sports");
    strcpy(questions[4].question, "How many oceans are there?");
    strcpy(questions[4].answer, "5");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "sports");
    strcpy(questions[5].question, "How many oceans are there?");
    strcpy(questions[5].answer, "5");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "sports");
    strcpy(questions[6].question, "How many oceans are there?");
    strcpy(questions[6].answer, "5");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "sports");
    strcpy(questions[7].question, "How many oceans are there?");
    strcpy(questions[7].answer, "5");
    questions[7].value = 400;
    questions[7].answered = false;

    strcpy(questions[8].category, "food and drink");
    strcpy(questions[8].question, "How many oceans are there?");
    strcpy(questions[8].answer, "5");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "food and drink");
    strcpy(questions[9].question, "How many oceans are there?");
    strcpy(questions[9].answer, "5");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "food and drink");
    strcpy(questions[10].question, "How many oceans are there?");
    strcpy(questions[10].answer, "5");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "food and drink");
    strcpy(questions[11].question, "How many oceans are there?");
    strcpy(questions[11].answer, "5");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void) {
    // print categories and dollar values for each unanswered question in questions array
    char question_values[12][20];

    for (int i = 0; i < 12; i++) {
        if (!questions[i].answered) {
            snprintf(question_values[i], 20, "%d", questions[i].value);
        } else {
            snprintf(question_values[i], 20, "%s", "---");
        }
    }

    printf("---------------------------JEOPARDY---------------------------\n");
    printf("  %s    |  %s  |  \t%s  \n", categories[0], categories[1], categories[2]);
    printf("--------------------------------------------------------------\n");
    printf("      %s  |  \t%s  |  \t%s  \n", question_values[0], question_values[4], question_values[8]);
    printf("--------------------------------------------------------------\n");
    printf("      %s  |  \t%s  |  \t%s  \n", question_values[1], question_values[5], question_values[9]);
    printf("--------------------------------------------------------------\n");
    printf("      %s  |  \t%s  |  \t%s  \n", question_values[2], question_values[6], question_values[10]);
    printf("--------------------------------------------------------------\n");
    printf("      %s  |  \t%s  |  \t%s  \n", question_values[3], question_values[7], question_values[11]);
    printf("--------------------------------------------------------------\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value) {
    question q = questions[question_index_lookup(category, value)];
    printf("Question: %s, Value: %d\n", q.question, q.value);
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer) {
    int i = question_index_lookup(category, value);
    return (strcmp(questions[i].answer, answer) == 0);
}

// Returns true if the question has already been answered or question doesn't exist
bool invalid_question(char *category, int value) {
    int i = question_index_lookup(category, value);
    if (i < 0)
        return true;
    return questions[i].answered;
}

void answer_question(char *category, int value) {
    questions[question_index_lookup(category, value)].answered = true;
}

char* question_answer(char *category, int value) {
    return questions[question_index_lookup(category, value)].answer;
}

int question_index_lookup(char category[], int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return i;
        }
    }
    return -1;
}
