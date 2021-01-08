#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include "scrabble.h"

using namespace std;

/* insert your function definitions here */

int highest_scoring_word_from_tiles(const char *tiles,
				    ScoreModifier modifiers[],char *word)
{
  char highest_score[80];
  ifstream in;
  in.open("words.txt");

  // go through all words
  for (string str; getline(in, str) ;){
    const char *line = str.c_str();
    if (can_form_word_from_tiles(line, tiles, word)){
      // compare with current highest score
      if (compute_score(line, modifiers) >
	  compute_score(highest_score, modifiers)) {
	strcpy(highest_score, line);
      }
    }
  }
  in.close();
  strcpy(word, highest_score);
  return compute_score(highest_score, modifiers);
}

bool is_a_word(const char *word) {
  cout << word << endl;
  ifstream in;
  in.open("words.txt");
  if (in.fail()){
    cout << "error opening dictionary" << endl;
    exit(1);
  }

  for (string str; getline(in, str) ;) {
    const char *line = str.c_str();
    if (!strcmp(line, word)) {
      cout << "Line is " << line << endl;
      in.close();
      return true;
    }
  }
  in.close();
  return false;
}

int compute_score(const char *word, ScoreModifier modifier[]){
  int score = 0;
  bool double_word = false;
  bool triple_word = false;
  
  int length = strlen(word);
  for (int i = 0; i < length; i++) {
    if (modifier[i] == DOUBLE_WORD_SCORE){
      double_word = true;
      score = score + tile_score(word[i]);
    }
    else if (modifier[i] == TRIPLE_WORD_SCORE){
      triple_word = true;
      score = score + tile_score(word[i]);
    }
    else if (modifier[i] == DOUBLE_LETTER_SCORE)
      score = score + tile_score(word[i]) * 2;
    else if (modifier[i] == TRIPLE_LETTER_SCORE)
      score = score + tile_score(word[i]) * 3;
    else
      score = score + tile_score(word[i]);
  }

  if (double_word == true)
    score = score * 2;
  if (triple_word == true)
    score = score * 3;

  if (length == 7)
    score = score + 50;
  return score;
}

// Function returns true if a given charater is found in given tiles
// It removes the used tile from the tiles string 
// and returns the used character 'match'
bool match_found(char ch, char tiles[], char &match){ 
  int num_tiles = strlen(tiles);
  // Search for exact match first
  for (int i = 0; i < num_tiles; i++) {
    if (tiles[i] == ch) {
      match = ch; // modify match
      for (int j = i; j < num_tiles; j++) {
	      tiles[j] = tiles[j+1]; // Move remaining characters one step back
      }
      return true;
    }
  }
  for (int i = 0; i < num_tiles; i++) {
    if (tiles[i] == '?' || tiles[i] == ' ') {
      match = tiles[i];
      for (int j = i; j < num_tiles; j++) {
	tiles[j] = tiles[j+1];
      }
      return true;
    }
  }
  return false;
}

bool can_form_word_from_tiles(const char *word, const char *tiles, char *played_tiles)
{
  char available_tiles[8];
  strcpy(available_tiles, tiles);
  int length = strlen(word);
  int index = 0;
  for (int i = 0; i < length; i++) {
    char ch;
    if(!match_found(word[i], available_tiles, ch))
       return false;
    else {
      played_tiles[index] = ch;
      index++;
    }
  }
  played_tiles[index] = '\0';
  return true;
}

int tile_score(char ch){
  if (ch == ' ' || ch == '?')
    return 0;
  if (isalpha(ch)){
    char upper_ch = toupper(ch);
    switch (upper_ch) {
    case 'A': case 'E': case 'I':
    case 'L': case 'N': case 'O':
    case 'R': case 'S': case 'T': case 'U':
      return 1; break;
    case 'D': case 'G':
      return 2; break;
    case 'B': case 'C': case 'P': case 'M':
      return 3; break;
    case 'F': case 'H': case 'V':
    case 'W': case 'Y':
      return 4; break;
    case 'K':
      return 5; break;
    case 'J': case 'X':
      return 8; break;
    case 'Q': case 'Z':
      return 10; break;
    default:
      return -1;
    }
  }
  return -1;
}

