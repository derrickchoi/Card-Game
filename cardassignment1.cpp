#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

///////declaring variables///////////
int p1decksize;
int p2decksize;
int deckSize;
int deckNum;
int deckSuit [5*52];
int p1decksuit [5*52];
int p2decksuit [5*52];
int deckValue [5*52];
int p1deckvalue [5*52];
int p2deckvalue [5*52];
string output (int value, int suit);
string input;
void shuffle();
void play(bool bValue);
void dealoutCards();
void getDeck(int d);
/////////////////////////////////////

int main() {
  srand(time(0)); //randomize
  string input; 
  bool bValue;

//prompts user to input the number of decks there are between 1 and 5
  do {
	cout << "How many decks are being used? (Between 1 and 5) ";
	cin >> deckNum; 
	if (cin.fail()) {
        cout << "Please enter an actual number\n";
	    cin.clear();
	    continue;
	}
	else if (deckNum > 5) {
	    cout << "Please enter a number between 1 and 5\n";
	    cin.clear();
	    continue;
	}
	else if (deckNum <= 0) {
	    cout << "Please enter a number between 1 and 5\n";
	    cin.clear();
	    continue;
	}
	break;
  }
  while (true);

  //prompts user to input whether they would like to watch the game
  do {
	cout << "Would you like to see the game? Yes or No ";
	cin >> input;
	if (input != "Yes" & input != "No") {
	    cout << "Please put in either Yes or No \n";
	    cin.clear();
	    continue;
	}
	break;
  }

  while (true);
  deckSize = deckNum * 52;
  if (input == "Yes") bValue = true;
  else bValue = false;

//call void functions
  getDeck(deckNum);
  shuffle();
  dealoutCards();
  play(bValue);
  string output();
  
  return 0;
} //end of int main()

///////////////////////////////////////////////////////////////////////////////////////////

//output string of numbers or suits in result
string output(int value, int suit) {
	string numbervalue = "";
	string stringSuit;

	switch (value) {
		case 0: numbervalue = "2 of";
			break;
		case 1: numbervalue = "3 of";
			break;
		case 2: numbervalue = "4 of";
			break;
		case 3: numbervalue = "5 of";
			break;
		case 4: numbervalue = "6 of";
			break;
		case 5: numbervalue = "7 of";
			break;
		case 6: numbervalue = "8 of";
			break;
		case 7: numbervalue = "9 of";
			break;
		case 8: numbervalue = "10 of";
			break;
		case 9: numbervalue = "Jack of";
			break;
		case 10: numbervalue = "Queen of";
			break;
		case 11: numbervalue = "King of";
			break;
		case 12: numbervalue = "Ace of";
			break;
	}

	switch (suit) {
		case 0:
			stringSuit = " Diamonds";
			break;
		case 1:
			stringSuit = " Clubs";
			break;
		case 2:
			stringSuit = " Spades";
			break;
		case 3:
			stringSuit = " Hearts";
			break;
	}
	return numbervalue + stringSuit;
}
 
///////////////////////////////////////////////////////////////////////////////////////////

//starts to play the card war game
void play(bool bValue) {
  int p1win = 0;
  int p2win = 0;
  int p1winswar = 0;
  int p2winswar = 0;
  int wars = 0;
  int handsPlayed = 1; 
  bool cardgame = false;
  int size = 0; 

  while (p1decksize > 0 && p2decksize > 0) {
	//comparing the cards
	int p1card = p1deckvalue [0];
	int p1suit = p1decksuit [0];
	int p2card = p2deckvalue [0];
	int p2suit = p2decksuit [0];
	//number of cards
	int handSuit [5*52]; //max 5 decks of 52 cards
	int handValue [5*52];
	//cards added
	handValue[size] = p1card;
	handValue[size+1] = p2card;
	handSuit[size] = p1suit;
	handSuit[size+1] = p2suit;
	size += 2; 

	if(bValue) {
	    cout << endl; 
	    cout << endl;
	    if (!cardgame) {  //if not equal to the cardgame
		cout << "--------------------------\n";
		cout << endl;
		cout << "Hand #" << handsPlayed << endl;
	    }
	    cout << "Player 1: " << output(p1card, p1suit) << endl;
	    cout << "Player 2: " << output(p2card, p2suit) << endl;
	}

	for (int i = 1; i < p1decksize; i++) //shifts the index up
	{
	    p1deckvalue[i-1] = p1deckvalue[i];
	    p1decksuit[i-1] = p1deckvalue[i];
	}
	for (int i = 1; i < p2decksize; i++)
	{
	    p2deckvalue[i-1] = p2deckvalue[i];
	    p2decksuit[i-1] = p2decksuit[i];
	}
	p1decksize --;
	p2decksize --;

///extra code for the card game to try and solve current problem/////
//	if (p1deckvalue [0] > p2deckvalue [0]) {
//	p1deckvalue[p1-count] = p2deckvalue[0];
//	p1decksize ++;
//	p1deckvalue[p1decksize] = p1deckvalue[0];
//	p2decksize --;
//
//	for (int i = 1, i <= p1decksize; i++) {
//		p1deckvalue [i-1] = p1deckvalue [i];
//	}
//
//	for (int i = 1, i <= p2decksize; i++) {
//		p2deckvalue [i-1] = p2deckvalue [i];
//	}
//}
//else if (p2deckvalue [0] > p2deckvalue [0]) {
//	p2deckvalue[p2decksize] = p1deckvalue[0];
//	p2decksize ++;
//	p2deckvalue[p2decksize] = p2deckvalue[0];
//	p1decksize --;
//
//	for (int i = 1, i <= p2decksize, i++) {
//		p2deckvalue [i-1] = p2deckvalue [i];
//	}
//
//	for (int i = 1, i <= p1decksize; i++) {
//		p1deckvalue [i-1] = p1deckvalue[i];
//	}
//}
///////////////////////////////////////////////////////////////////////

	if (p1card>p2card) {
	    if (bValue) cout << "Player 1 wins. "; //output player 1 wins
	    p1win ++;
	    if (cardgame) {
		p1winswar ++; //counts how many of war hands player 1 has won
		cardgame = false;
	    }

	    for (int i=0; i<size; i++) {
	   		p1deckvalue[p1decksize + i] = handValue[i];
	    	p1decksuit[p1decksize + i] = handSuit[i];
	    }
	    p1decksize += size;
	    size = 0;
  	}

	else if (p1card<p2card) {
	    if (bValue) cout << "Player 2 wins. "; //output player 2 wins
	    p2win++;
	    if (cardgame) { 
			p2winswar ++; //counts number of war hands player 2 has won
			cardgame = false;
	    }

	    for (int i=0; i<size; i++) {
	    	p2deckvalue[p2decksize + i] = handValue[i];
	    	p2deckvalue[p2decksize + i] = handSuit[i];
	    }
	    p2decksize += size;
	    size = 0;
	}

	else { //when war happens
	    if (bValue) {
		cout << "\n";
		cout << "War! \n";
		cout << "\n";
		cout << "Player 1 places 3 cards down." << endl;
		cout << "Player 2 places 3 cards down." << endl;
	    }
	    if (p1decksize <= 0) {
			cout << "Player 1 does not have 3 cards to place down.";
			cout << "\n\n";
			cout << "Player 2 wins.";
		}
	    if (p2decksize <= 0) {
			cout << "Player 2 does not have 3 cards to place down.";
			cout << "\n\n";
			cout << "Player 1 wins.";
		}	
	    if (!cardgame) {
			wars ++; //counts the number of wars played
			cardgame = true;
	    }

	    //regains the cards that were put down
		for (int i=1; i<3; i++) {
		handValue [i+size] = p1deckvalue[i];
		handSuit [i+size] = p1decksuit[i];
		handValue [i+3+size] = p2deckvalue[i];
		handSuit [i+3+size] = p2decksuit[i];
	    }
	    size += 6;

	    //each player puts down 3 cards
	    for (int i=0; i<p1decksize-3; i++) {
			p1deckvalue[i] = p1deckvalue[i+3];
			p1decksuit[i] = p1decksuit[i+3];
	    }
	    p1decksize -= 3;

	    for (int i=0; i<p2decksize-3; i++) {
			p2deckvalue[i] = p2deckvalue[i+3];
			p2decksuit[i] = p2decksuit[i+3];
	    }
	    p2decksize -= 3;
		
	    continue;
	  
	}

	handsPlayed ++; //increments the number of hands played in card game

	if (bValue) {
	    cout << "\n";
	    cout << "\n";
	    cout << "Player 1 now has " << p1decksize << " cards." << endl;
	    cout << "Player 2 now has " << p2decksize <<" cards.";
	}
  }
  
  cout << endl << endl << endl;  
  cout << "--------------------------\n";
  
  if (p2decksize <=0) { //valid when player 2 has 0 cards left
	cout << "\n";
	cout << "Player 1 WINS the game!\n";
	cout << "\n";
	if (cardgame) p1winswar ++;
  }
  if (p1decksize <=0) { //valid when player 1 has 0 cards left
	cout << "\n";
	cout << "Player 2 WINS the game!\n";
	cout << "\n";
	if (cardgame) p2winswar ++;
  }

  float p1winningrate = (float) p1win/handsPlayed; //float for decimal points
  float p2winningrate = (float) p2win/handsPlayed;
  float warhands = (float) wars/handsPlayed;
  float p1warwinningrate = (float) p1winswar/wars; 
  float p2warwinningrate = (float) p2winswar/wars;

  cout << "--------------------------\n\n";
  cout << "Statistics\n\n";  
  cout << "Number of Hands: " << handsPlayed << endl;
  cout << "Number of Hands Player 1 Won: " <<p1win<<" ("<<setprecision(3)<<p1winningrate*100<<"%)"<<endl;
  cout << "Number of Hands Player 2 Won: " <<p2win<<" ("<<setprecision(3)<<p2winningrate*100<<"%)"<<endl;
  cout << "Number of War Hands: " <<wars<<" ("<<setprecision(3)<<warhands*100<<"%)"<<endl;
  cout << "Number of War Hands Player 1 Won: "<<p1winswar<<" ("<<setprecision(4)<<p1warwinningrate*100<<"%)"<<endl;
  cout << "Number of War Hands Player 2 Won: "<<p2winswar<<" ("<<setprecision(3)<<p2warwinningrate*100<<"%)"<< endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

//shuffles the deck of cards
void shuffle () {
	int temp; 
	int temp2; //for suits
	for (int i = 0; i < 1000; i++) { //shuffle
		int indexone = rand() % 52;
		int indextwo = rand() % 52;

		temp = p1deckvalue[indexone];
		temp2 = p1decksuit[indextwo];
		p1deckvalue [indexone] = p1deckvalue [indextwo];
		p1deckvalue [indextwo] = temp;
		temp2 = p1decksuit[indextwo];
		p1decksuit[indextwo] = p1decksuit [indexone];
		p1decksuit [indexone] = temp2;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////

//fills deck with card and suit values
void getDeck(int d) 
{
  d = deckNum*52;
  for (int i=0; i<d; i++) {
	deckValue[i] = i % 13;
  }
  for (int i=0; i<d; i++) {
	deckSuit[i] = i % 4;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////

//deals out the deck(s) of cards
void dealoutCards() {
  for (int i=0; i<deckSize/2; i++) {
	p1deckvalue[i] = deckValue[i + deckSize/2];
	p1decksuit[i] = deckSuit[i + deckSize/2];
	p1decksize = deckSize/2;
  }
  for (int i=0; i<deckSize/2; i++) {
	p2deckvalue[i] = deckValue[i + deckSize/2];
	p2deckvalue[i] = deckSuit[i + deckSize/2];
	p2decksize = deckSize/2;
  }
}
