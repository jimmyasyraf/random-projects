//Name: Mohamed Hazimi Asyraf Bin Mohamed Azham
//Student #: 8339639
//Program: Monty Hall Game

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//declare all functions
int prize_door(int, int, int);
int noprize_door(int[], int, int, int);
int game_mode(int, int, int);
int research_mode(int, int);
int game_count(int);
int score(int, int);

//main menu
int main()
{
  int menu = 1;
  int start = 1;
  srand(time(NULL));

  while (menu == 1)
  {
  int mode = 0;
  printf("\nMAIN MENU\n");
  printf("1 GAME MODE\n");
  printf("2 RESEARCH MODE\n");
  printf("3 EXIT\n");
  printf("\nSelect by pressing 1, 2 or 3\n");
  scanf("%d", &mode);
  if (mode == 1)
  {
    start = 1;
    int behavior = 0; //0 means it depends on user's input
    game_count(1);
    score(0, 1);
    menu = game_mode(start, mode, behavior);
  }
  else if (mode == 2)
  {
    start = 1;
    score(0, 1);
    menu = research_mode(start, mode);
  }
  else if (mode == 3)
  {
    menu = 0;
  }
  else
  {
    printf("\nInvalid input\n");
    menu = 1;
  }
  }
  return 0;
}

int game_mode(int start, int mode, int behavior)
{
  while (start == 1)
  {
  int wherePresent;
  int choice;
  int door[3];
  wherePresent = rand() % 6;
  switch (wherePresent) {
    case 0:
      door[0] = 1;
      door[1] = 2;
      door[2] = 3;
      break;

    case 1:
      door[0] = 3;
      door[1] = 2;
      door[2] = 1;
      break;

    case 2:
      door[0] = 2;
      door[1] = 1;
      door[2] = 3;
      break;

    case 3:
      door[0] = 3;
      door[1] = 1;
      door[2] = 2;
      break;

    case 4:
      door[0] = 1;
      door[1] = 3;
      door[2] = 2;
      break;

    case 5:
      door[0] = 2;
      door[1] = 3;
      door[2] = 1;
      break;

    default:
        break;
  }

  if (mode == 1)
  {
    printf("\nWelcome to Monty Hall. \n");
    printf("There are 3 doors in this hall.\n");
    printf("One of the door has a prize behind it.\n");
    printf("Choose a door (1 for Door 1, 2 for Door 2, 3 for Door 3\n");
    scanf("%d", &choice);
    if (choice == 1 || choice == 2 || choice == 3)
    {
    printf("You have chosen Door %d.\n", choice);
    }
    else
    {
      printf("\nInvalid door choice\n");
      game_mode(start, mode, behavior);
    }
  }
  else if (mode == 2)
  {
    choice = 1;
  }

  if (door[choice-1] == 1) //user chose the door with the present behind
    {
        start = prize_door(choice, mode, behavior);
    }
  else if (door[choice-1] != 1)
    {
        start = noprize_door(door,choice, mode, behavior);
    }
  }
  int again;
  if (mode == 1)
  {
    again = 1;
  }
  else if (mode == 2)
  {
    again = 0;
  }
  return again;
}

int prize_door(int choice, int mode, int behavior) //user has chosen the door with present behind
{
  int play_again=0;
  int door1 = 1 + rand() % 3;
  if (door1 == choice)
    {
      prize_door(choice, mode, behavior);
    }
    else
    {
      int choice2;
      int winning =  0;
      int won;
      if (mode == 1)
      {
        printf("\nDoor %d has no prize, would you like to switch? (1 for Yes, 2 for No)\n", door1);
        scanf("%d", &choice2);
      }
      else if (mode == 2)
      {
        choice2 = behavior;
      }
      if (choice2 == 2)
            {
              winning++;
              won = score(winning, 0);
              if (mode == 1)
              {
              printf("You chose not to switch.\n");
              printf("\nYou won the prize! You chose the right door.\n");
              printf("You won %d times out of %d games\n", won, game_count(0));
              }
            }
            else if (choice2 == 1)
            {
              won = score(0, 0);
              if (mode == 1)
              {
              printf("You chose to switch.\n");
              printf("\nYou lose. It's the wrong door.\n");
              printf("You won %d times out of %d games\n", won, game_count(0));
              }
            }
    }
  if (mode == 1)
  {
  printf("PLAY AGAIN? (1 for yes, 0 to return to main menu)\n");
  scanf("%d", &play_again);
  }
  else if (mode == 2)
  {
    play_again = 0;
  }

  return play_again;

}

int noprize_door(int door[], int choice, int mode, int behavior) //user chose the door with no present behind
{
    int door2;
    int play_again=0;
    for (door2=0;door2<3;door2++)
    {
        if ((door[door2] != door[choice-1]) && (door[door2] != 1) )
        {

            int choice2;
            int winning = 0;
            int won;
            if (mode == 1)
            {
              printf("\nDoor %d has no prize, would you like to switch? (1 for Yes, 2 for No)\n", door2+1);
              scanf("%d", &choice2);
            }
            else if (mode == 2)
            {
              choice2 = behavior;
            }
            if (choice2 == 1)
            {
              winning++;
              won = score(winning, 0);
              if (mode == 1)
              {
              printf("You chose to switch.\n");
              printf("\nYou won the prize! You chose the right door.\n");
              printf("You won %d times out of %d games\n", won, game_count(0));
              }
            }
            else if (choice2 == 2)
            {
              won = score(0, 0);
              if (mode ==1)
              {
              printf("You chose not to switch.\n");
              printf("\nYou lose. It's the wrong door.\n");
              printf("You won %d times out of %d games\n", won, game_count(0));
              }
            }
        }
    }
    if (mode ==1)
    {
    printf("PLAY AGAIN? (1 for yes, 0 to return to main menu)\n");
    scanf("%d", &play_again);
    }
    else if (mode ==2)
    {
      play_again = 0;
    }
    return play_again;

}

int research_mode(int start, int mode)
{
  int trial;
  int behavior;
  printf("Enter number of trials for the game to simulate:\n");
  scanf("%d", &trial);
  printf("Choose the behavior (1 for always switch, 2 for always stick to the same door)\n");
  scanf("%d", &behavior);
  int i;
  for(i=0; i< trial; i++)
  {
    game_mode(start, mode, behavior);
  }
  int win;
  win = score(0, 0);
  printf("You won %d times out of %d games\n", win, trial);
  float percentage;
  percentage = (float) win/trial*100;
  printf("That's %.2f %% of winning\n", percentage);
  return 1;
}

int game_count(reset_gamecount)
{
  static int gamecount;
  if (reset_gamecount == 1)
  {
    gamecount = -1;
  }
  gamecount++;
  return gamecount;
}

int score(int winning, int reset_score)
{
  static int total_win;
  if (reset_score == 1)
  {
    total_win = 0;
  }
  if (winning == 1)
  {
    total_win++;
  }
  return total_win;
}
