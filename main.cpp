#include <iostream>
#include <cassert>
#include <cstring>
#include "scrabble.h"

using namespace std;

int main() {

  cout << "====================== Question 1 ======================" << endl << endl;

  cout << "Tile score for 'P' is " << tile_score('P') << endl;
  cout << "Tile score for 'i' is " << tile_score('i') << endl;
  cout << "Tile score for 'Z' is " << tile_score('Z') << endl;
  cout << "Tile score for ' ' is " << tile_score(' ') << endl;
  cout << "Tile score for '?' is " << tile_score('?') << endl;
  cout << "Tile score for '1' is " << tile_score('1') << endl;
  cout << "Tile score for 'X' is " << tile_score('X') << endl;
  cout << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  char played_tiles[80];

  bool success = can_form_word_from_tiles("LEAP", "ZLEAP?S", played_tiles);
  cout << "The word 'LEAP' " << (success ? "can" : "cannot")
       << " be made from the tiles 'ZLEAP?S'" << endl;
  if (success)
    cout << "Played tiles: " << played_tiles << endl;
  cout << endl;

  success = can_form_word_from_tiles("APPLES", "ZLEAP?S", played_tiles);
  cout << "The word 'APPLES' " << (success ? "can" : "cannot")
       << " be made from the tiles 'ZLEAP?S'" << endl;
  if (success)
    cout << "Played tiles: " << played_tiles << endl;
  cout << endl;

  success = can_form_word_from_tiles("SPATZLE", "ZLEAP?S", played_tiles);
  cout << "The word 'SPATZLE' " << (success ? "can" : "cannot")
       << " be made from the tiles 'ZLEAP?S'" << endl;
  if (success)
    cout << "Played tiles: " << played_tiles << endl;
  cout << endl;

  
  success = can_form_word_from_tiles("PIZZA", "ZLEAP?S", played_tiles);
  cout << "The word 'PIZZA' " << (success ? "can" : "cannot")
         << " be made from the tiles 'ZLEAP?S'" << endl;
  if (success)
    cout << "Played tiles: " << played_tiles << endl;
  cout << endl;

  cout << "====================== Question 3 ======================" << endl
       << endl;

  ScoreModifier sm0[]={NONE, TRIPLE_LETTER_SCORE, NONE, NONE, DOUBLE_WORD_SCORE
		       , NONE, NONE};

  int score = compute_score("LEAP", sm0); 
  cout << "LEAP scores " << score << endl;
  
  score = compute_score("LEAPS", sm0);
  cout << "LEAPS scores " << score << endl;

  score = compute_score("AP?LES", sm0);
  cout << "AP?LES scores " << score << endl;

  score = compute_score("SPA?ZLE", sm0);
  cout << "SPA?ZLE scores " << score << endl;

  cout << endl;

  cout << "====================== Question 4 ======================" << endl
       << endl;

  ScoreModifier sm1[]={NONE, NONE, DOUBLE_LETTER_SCORE, NONE, NONE, NONE, NONE};

  char word[512];
  score = highest_scoring_word_from_tiles("WBNNOER", sm1, word);
  cout << "The highest scoring word that can be made from the tiles 'WBNNOER'"
       << endl;
  cout << "  with a double letter score on the third letter is:" << endl;
  if (score < 0) 
    cout << "(no word found)" << endl;
  else
    cout << "'" << word << "' (" << score << " points)" << endl;
  cout << endl;
  
  ScoreModifier sm2[]={DOUBLE_LETTER_SCORE, NONE, NONE, NONE, NONE,
		       TRIPLE_WORD_SCORE, NONE};
  score = highest_scoring_word_from_tiles("N?ESHRH", sm2, word);
  cout << "The highest scoring word that can be made from the tiles 'N?ESHRH'"
       << endl;
  cout << "  with a double letter score on the 1st position" << endl;
  cout << "  and a triple word score on the 6th position is:" << endl;
  if (score < 0)
    cout << "(no word found)" << endl;
  else 
    cout << "'" << word << "' (" << score << " points)" << endl;
  cout << endl;

  ScoreModifier sm3[]={NONE, NONE, NONE, NONE, TRIPLE_LETTER_SCORE, NONE,
		       DOUBLE_WORD_SCORE};
  score = highest_scoring_word_from_tiles("L?IEY?A", sm3, word);
  cout << "The highest scoring word that can be made from the tiles 'L?IEY?A'"
       << endl;
  cout << "  with a triple letter score on the 5th position" << endl;
  cout << "  and a double word score on the 7th position is:" << endl;
  if (score < 0)
    cout << "(no word found)" << endl;
  else 
    cout << "'" << word << "' (" << score << " points)" << endl;
  cout << endl;
  
  cout << "========================= Fin ==========================" << endl << endl;
  
  return 0;
}
