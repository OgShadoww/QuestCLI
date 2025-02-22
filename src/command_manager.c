#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_manager.h"
#include "ui_manager.h"
#include "player.h"

void startGame(Player *player) {
    if(loadPlayer(player) == 1) {
        printPlayer(player);
    }   
    else {
        createPlayer(player);
        printPlayer(player);
    }
}

void exitGame(Player *player) {
    printSlow("Exiting the game...", 50);
    exit(0);  // Завершує всю програму
}

Command commands[] = {
    {"start()", startGame},
    {"exit()", exitGame}
};

void executeCommand(const char *input, Player *player) {
    for(int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].execute(player);
            return;
        }
    }
    
    printf(RED "Unknown command: %s\n" RESET, input);
}