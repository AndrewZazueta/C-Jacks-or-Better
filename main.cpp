#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<algorithm>

using namespace std;

int handFind(string param[]){

   string c1;
   string c2;
   string c3;
   string c4;
   string c5;
   int carray[5];
   int carray1[5] = {2, 11, 12, 13, 14};
   int carray2[5] = {2, 3, 12, 13, 14};
   int carray3[5] = {2, 3, 4, 13, 14};
   int carray4[5] = {2, 3, 4, 5, 14};
   char c1a;
   char c2a;
   char c3a;
   char c4a;
   char c5a;
   char c1b;
   char c2b;
   char c3b;
   char c4b;
   char c5b;
   int c1bn;
   int c2bn;
   int c3bn;
   int c4bn;
   int c5bn;
   int win;
   int threeNum;
   int threeCheck[5];
   int pairCheck[5];
   bool two = false;
   bool three = false;
   bool flush = false;
   bool straight = false;
   bool cont = false;

    for(int i = 0; i < 5; i++){
        if(i == 0){c1 = param[i];}
        if(i == 1){c2 = param[i];}
        if(i == 2){c3 = param[i];}
        if(i == 3){c4 = param[i];}
        if(i == 4){c5 = param[i];}
    }

    // dividing each card into a suit and number/face, a = suit, b = number/face (remember stoi())
    if(c1.length() < 3){
        c1a = c1[0];
        c1b = c1[1];
    }
    if(c1.length() == 3){
        c1a = c1[0];
        c1bn = 10;
        // for initializing purposes
        c1b = 'Z';
    }
    if(c2.length() < 3){
        c2a = c2[0];
        c2b = c2[1];
    }
    if(c2.length() == 3){
        c2a = c2[0];
        c2bn = 10;
        c2b = 'Z';
    }
    if(c3.length() < 3){
        c3a = c3[0];
        c3b = c3[1];
    }
    if(c3.length() == 3){
        c3a = c3[0];
        c3bn = 10;
        c3b = 'Z';
    }
    if(c4.length() < 3){
        c4a = c4[0];
        c4b = c4[1];
    }
    if(c4.length() == 3){
        c4a = c4[0];
        c4bn = 10;
        c4b = 'Z';
    }
    if(c5.length() < 3){
        c5a = c5[0];
        c5b = c5[1];
    }
    if(c5.length() == 3){
        c5a = c5[0];
        c5bn = 10;
        c5b = 'Z';
    }


    // converting A, K, Q, and J to numbers and char to numbers
    if(c1b == 'A' || c1b == 'K' || c1b == 'Q' ||c1b == 'J'){
        if(c1b == 'A')
        {
            c1bn = 14;
        }
        if(c1b == 'K')
        {
            c1bn = 13;
        }
        if(c1b == 'Q')
        {
            c1bn = 12;
        }
        if(c1b == 'J')
        {
            c1bn = 11;
        }
    }
    if(c1b != 'A' && c1b != 'K' && c1b != 'Q' && c1b != 'J' && c1b != 'Z'){
        c1bn = c1b - '0';
    }

    if(c2b == 'A' || c2b == 'K' || c2b == 'Q' ||c2b == 'J'){
        if(c2b == 'A')
        {
            c2bn = 14;
        }
        if(c2b == 'K')
        {
            c2bn = 13;
        }
        if(c2b == 'Q')
        {
            c2bn = 12;
        }
        if(c2b == 'J')
        {
            c2bn = 11;
        }
    }
    if(c2b != 'A' && c2b != 'K' && c2b != 'Q' && c2b != 'J' && c2b != 'Z'){
        c2bn = c2b - '0';
    }

    if(c3b == 'A' || c3b == 'K' || c3b == 'Q' ||c3b == 'J'){
        if(c3b == 'A')
        {
            c3bn = 14;
        }
        if(c3b == 'K')
        {
            c3bn = 13;
        }
        if(c3b == 'Q')
        {
            c3bn = 12;
        }
        if(c3b == 'J')
        {
            c3bn = 11;
        }
    }
    if(c3b != 'A' && c3b != 'K' && c3b != 'Q' && c3b != 'J' && c3b != 'Z'){
        c3bn = c3b - '0';
    }

    if(c4b == 'A' || c4b == 'K' || c4b == 'Q' ||c4b == 'J'){
        if(c4b == 'A')
        {
            c4bn = 14;
        }
        if(c4b == 'K')
        {
            c4bn = 13;
        }
        if(c4b == 'Q')
        {
            c4bn = 12;
        }
        if(c4b == 'J')
        {
            c4bn = 11;
        }
    }
    if(c4b != 'A' && c4b != 'K' && c4b != 'Q' && c4b != 'J' && c4b != 'Z'){
        c4bn = c4b - '0';
    }

    if(c5b == 'A' || c5b == 'K' || c5b == 'Q' ||c5b == 'J'){
        if(c5b == 'A')
        {
            c5bn = 14;
        }
        if(c5b == 'K')
        {
            c5bn = 13;
        }
        if(c5b == 'Q')
        {
            c5bn = 12;
        }
        if(c5b == 'J')
        {
            c5bn = 11;
        }
    }
    if(c5b != 'A' && c5b != 'K' && c5b != 'Q' && c5b != 'J' && c5b != 'Z'){
        c5bn = c5b - '0';
    }

    // putting cards into array
    carray[0] = c1bn;
    carray[1] = c2bn;
    carray[2] = c3bn;
    carray[3] = c4bn;
    carray[4] = c5bn;

    // sort array
    sort(carray, carray + 5);

    // check for flush and straight
    if(c1a == c2a && c1a == c3a && c1a == c4a && c1a == c5a){
        flush = true;
    }

    if(carray[4] - carray[3] == 1 && carray[3] - carray[2] == 1 && carray[2] - carray[1] == 1 && carray[1] - carray[0] == 1){
        straight = true;
        cont = true;
    }

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if(cont == false){
        for(int i = 0; i < 5; i++){
            if(carray[i] == carray1[i]){
                a++;
                if(a == 5){
                    straight = true;
                }
            }
            if(carray[i] == carray2[i]){
                b++;
                if(b == 5){
                    straight = true;
                }
            }
            if(carray[i] == carray3[i]){
                c++;
                if(c == 5){
                    straight = true;
                }
            }
            if(carray[i] == carray4[i]){
                d++;
                if(d == 5){
                    straight = true;
                }
            }
        }
    }

    // check for three of a kind
    int k = 0;
    int w = -1;
    for(int i = 0; i < 4; i++){
        if(carray[i] == carray[i+1]){
            k++;
            w++;
            threeCheck[w] = carray[i];
        }
        if(k >= 2 && threeCheck[w] == threeCheck[w-1]){
            three = true;
            threeNum = threeCheck[w];
        }
    }

    // check for royal flush
    if(c1bn >= 10 && c2bn >= 10 && c3bn >= 10 && c4bn >= 10 && c5bn >= 10 && flush){
        win = 9;
        return win;
    }

    // check for straight flush
    if(flush && straight){
        win = 8;
        return win;
    }

    // check full house
    if(three){
        for(int i = 0; i < 4; i++){
            if(carray[i] != threeNum){
                if(carray[i] == carray[i+1]){
                   win = 6;
                   return win;
                }
            }
        }
    }

    // check 4 of a kind
    int j = 0;
    for(int i = 0; i < 4; i++){
        if(carray[i] == carray[i+1])
        {
            j++;
        }
        if(j == 3){
            win = 7;
            return win;
        }
   }

    // check flush
    if(flush){
        win = 5;
        return win;
    }

    // check straight
    if(straight){
        win = 4;
        return win;
    }

    // check three of a kind
    if(three){
        win = 3;
        return win;
    }

    // check two pair
    int n = 0;
    for(int i = 0; i < 5; i++){
        if(carray[i] == carray[i+1]){
            n++;
        }
        if(n == 2){
            win = 2;
            return win;
        }
    }

    // check jacks or better
    int z = 0;
    int q = -1;
    for(int i = 0; i < 5; i++){
        if(carray[i] == carray[i+1]){
            z++;
            q++;
            pairCheck[q] = carray[i];
        }
        if(z == 1 && pairCheck[q] > 10)
        {
            win = 1;
            return win;
        }
    }

return 0;
}

int main(){

    // calling random seed
    srand((unsigned) time(0));

    // variables to be used
    string cardSuits[52] = {"S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK", "SA",
                          "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "HA",
                          "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK", "DA",
                          "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "CA"};
    string card[6];
    int cardPick[4];
    int rand1;
    int rand2;
    int rand3;
    int rand4;
    int rand5;
    int randN1 = 100;
    int randN2 = 100;
    int randN3 = 100;
    int randN4 = 100;
    int randN5 = 100;
    int money;
    int bet;
    int holdNum;
    int win;
    int cont = 100;
    char answer;

    // prompting user for how much money they would like to start out with. We assume the answer is an integer.
    do{
        cout << "Welcome to Jacks or Better! How much money do you want to start out with?" << endl;
        cin >> money;

        if(money < 0){
            cout << "\nYour starting value needs to be greater than or equal to 0. Please try again." << endl << endl;
        }
    }while(money < 0);

    do{

       // Bet information
       cout << "\nWhat you will earn off certain bets:" << endl;
       cout << left << setw(12) << "Bet Amount |" << setw(9) << "J+ Pair |" << setw(8) << "2 Pair |" << setw(13) << "3 of a Kind |" << setw(10) << "Straight |" << setw(9) << "Flush   |" << setw(12) << "Full House |" << setw(16) << "Four of a Kind |" << setw(16) << "Straight Flush |" << setw(13) << "Royal Flush" << endl;
       cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
       cout << left << setw(12) << "-          |" << setw(9) << "Bet * 1 |" << setw(8) << "Bet * 2|" << setw(13) << "Bet * 3     |" << setw(10) << "Bet * 4  |" << setw(9) << "Bet * 6 |" << setw(12) << "Bet * 9    |" << setw(16) << "Bet * 25       |" << setw(16) << "Bet * 50       |" << setw(13) << "Bet * 250" << endl;
       cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
       for(int i = 1; i < 6;  i++){
        cout << left << setw(11) << i << "|" << setw(8) << i * 1 << "|" << setw(7) << i * 2 << "|" << setw(12) << i * 3 << "|" << setw(9) << i * 4 << "|" << setw(8) << i * 6 << "|" << setw(11) << i * 9 << "|" << setw(15) << i * 25 << "|" << setw(15) << i * 50 << "|" << setw(12) << i * 250 << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
       }
       for(int i = 0; i < 3;  i++){
        cout << "." << endl;
       }
       cout << "etc." << endl;

       // prompt user for how much money they wish to bet. We assume they input an integer.
       do{

        cout << "\nEnter how much you want to bet: ";
        cin >> bet;

        // warning message.
        if(bet > money || bet < 0){
            cout << "\nYour bet needs to be less than or equal to the money you have. You currently have $" << money << "." << endl;
        }
       }while(bet > money || bet < 0);

        // amount of money after bet is placed.
       money = money - bet;
       cout << "\nAfter betting, you have $" << money << "." << endl;

       // making cards section

       // finding random numbers that do not repeat (0-51)
       rand1 = (rand() % 51) + 0;

       rand2 = (rand() % 51) + 0;
       while(rand1 == rand2){
           rand2 = (rand() % 51) + 0;
       }

       rand3 = (rand() % 51) + 0;
       while(rand1 == rand3 || rand2 == rand3){
           rand3 = (rand() % 51) + 0;
       }

       rand4 = (rand() % 51) + 0;
       while(rand1 == rand4 || rand2 == rand4 || rand3 == rand4){
           rand4 = (rand() % 51) + 0;
       }

       rand5 = (rand() % 51) + 0;
       while(rand1 == rand5 || rand2 == rand5 || rand3 == rand5 || rand4 == rand5){
           rand5 = (rand() % 51) + 0;
       }

       // inputs values from cardSuits into card
       card[0] = cardSuits[rand1];
       card[1] = cardSuits[rand2];
       card[2] = cardSuits[rand3];
       card[3] = cardSuits[rand4];
       card[4] = cardSuits[rand5];

       // showing hand to user.
       cout << "\nYour cards:" << endl << endl;
       cout << left << setw(7) << "|Card 1|" << setw(7) << "|Card 2|" << setw(7) << "|Card 3|" << setw(7) << "|Card 4|" << setw(7) <<  "|Card 5|" << endl;
       cout << left << setw(7) << " ______ " << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) <<  " ______ "  << endl;
       cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
       for(int i = 0; i < 5; i++){
        cout << " | " << card[i] << "\t";
       }
       cout << endl;
       cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
       cout << left << setw(7) << " ------ " << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) <<  " ------ "  << endl;

       // prompt user for how many cards they wish to hold
       do{
        cout << "\nHow many cards do you wish to get rid of?" << endl;
        cin >> holdNum;

        if(holdNum < 0 || holdNum > 5){
            cout << "\nYou can only get rid of 0 to 5 cards." << endl;
        }
       }while(holdNum < 0 || holdNum > 5);

       // user picks which cards they want to get rid of. Assuming the picked cards will be a numeric answer in ranges 1-4 and do not repeat.
       if(holdNum != 0 && holdNum != 5){
        for(int i = 0; i < holdNum; i++){
            cout << "\nPick card number " << i + 1 << " you want to get rid of:" << endl;
            cin >> cardPick[i];
        }

        for(int i = 0; i < holdNum; i++){
          if(cardPick[i] == 1){
              randN1 = rand1;
              while(rand1 == randN1 || rand2 == randN1 || rand3 == randN1 ||
                    rand4 == randN1 || rand5 == randN1 || randN2 == randN1 ||
                    randN3 == randN1 || randN4 == randN1 || randN5 == randN1){
                randN1 = (rand() % 51) + 0;
              }
              card[0] = cardSuits[randN1];
          }
          if(cardPick[i] == 2){
              randN2 = rand2;
              while(rand1 == randN2 || rand2 == randN2 || rand3 == randN2 ||
                    rand4 == randN2 || rand5 == randN2 || randN1 == randN2 ||
                    randN3 == randN2 || randN4 == randN2 || randN5 == randN2){
                randN2 = (rand() % 51) + 0;
              }
              card[1] = cardSuits[randN2];
          }
          if(cardPick[i] == 3){
              randN3 = rand3;
              while(rand1 == randN3 || rand2 == randN3 || rand3 == randN3 ||
                    rand4 == randN3 || rand5 == randN3 || randN1 == randN3 ||
                    randN2 == randN3 || randN4 == randN3 || randN5 == randN3){
                randN3 = (rand() % 51) + 0;
              }
              card[2] = cardSuits[randN3];
          }
          if(cardPick[i] == 4){
              randN4 = rand4;
              while(rand1 == randN4 || rand2 == randN4 || rand3 == randN4 ||
                    rand4 == randN4 || rand5 == randN4 || randN1 == randN4 ||
                    randN2 == randN4 || randN3 == randN4 || randN5 == randN4){
                randN4 = (rand() % 51) + 0;
              }
              card[3] = cardSuits[randN4];
          }
          if(cardPick[i] == 5){
              randN5 = rand5;
              while(rand1 == randN5 || rand2 == randN5 || rand3 == randN5 ||
                    rand4 == randN5 || rand5 == randN5 || randN1 == randN5 ||
                    randN2 == randN5 || randN3 == randN5 || randN4 == randN5){
                randN5 = (rand() % 51) + 0;
              }
              card[4] = cardSuits[randN5];
          }
        }

        cout << "\nYour new hand of cards is:" << endl << endl;
        cout << left << setw(7) << "|Card 1|" << setw(7) << "|Card 2|" << setw(7) << "|Card 3|" << setw(7) << "|Card 4|" << setw(7) <<  "|Card 5|" << endl;
        cout << left << setw(7) << " ______ " << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) <<  " ______ "  << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        for(int i = 0; i < 5; i++){
        cout << " | " << card[i] << "\t";
        }
        cout << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        cout << left << setw(7) << " ------ " << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) <<  " ------ "  << endl;
       }

       // skips previous code and goes to this if loop if they chose to gt rid of 0 cards
       if(holdNum == 0){
        cout << "\nYour hand is still:" << endl << endl;
        cout << left << setw(7) << "|Card 1|" << setw(7) << "|Card 2|" << setw(7) << "|Card 3|" << setw(7) << "|Card 4|" << setw(7) <<  "|Card 5|" << endl;
        cout << left << setw(7) << " ______ " << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) <<  " ______ "  << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        for(int i = 0; i < 5; i++){
        cout << " | " << card[i] << "\t";
        }
        cout << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        cout << left << setw(7) << " ------ " << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) <<  " ------ "  << endl;
       }

       // if user chose to replace all cards
       if(holdNum == 5){

        randN1 = rand1;
        randN2 = rand2;
        randN3 = rand3;
        randN4 = rand4;
        randN5 = rand5;

        while(rand1 == randN5 || rand2 == randN5 || rand3 == randN5 ||
                    rand4 == randN5 || rand5 == randN5 || randN1 == randN5 ||
                    randN2 == randN5 || randN3 == randN5 || randN4 == randN5 ||
                    rand1 == randN4 || rand2 == randN4 || rand3 == randN4 ||
                    rand4 == randN4 || rand5 == randN4 || randN1 == randN4 ||
                    randN2 == randN4 || randN3 == randN4 || rand1 == randN3 || rand2 == randN3 || rand3 == randN3 ||
                    rand4 == randN3 || rand5 == randN3 || randN1 == randN3 ||
                    randN2 == randN3 || rand1 == randN2 || rand2 == randN2 || rand3 == randN2 ||
                    rand4 == randN2 || rand5 == randN2 || randN1 == randN2 ||
                    rand1 == randN1 || rand2 == randN1 || rand3 == randN1 ||
                    rand4 == randN1 || rand5 == randN1){
                randN1 = (rand() % 51) + 0;
                randN2 = (rand() % 51) + 0;
                randN3 = (rand() % 51) + 0;
                randN4 = (rand() % 51) + 0;
                randN5 = (rand() % 51) + 0;
                }

        card[0] = cardSuits[randN1];
        card[1] = cardSuits[randN2];
        card[2] = cardSuits[randN3];
        card[3] = cardSuits[randN4];
        card[4] = cardSuits[randN5];

        cout << "\nYour new hand of cards is:" << endl << endl;
        cout << left << setw(7) << "|Card 1|" << setw(7) << "|Card 2|" << setw(7) << "|Card 3|" << setw(7) << "|Card 4|" << setw(7) <<  "|Card 5|" << endl;
        cout << left << setw(7) << " ______ " << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) << " ______ "  << setw(7) <<  " ______ "  << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        for(int i = 0; i < 5; i++){
        cout << " | " << card[i] << "\t";
        }
        cout << endl;
        cout << left << setw(7) << " |    | " << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) << " |    | "  << setw(7) <<  " |    | "  << endl;
        cout << left << setw(7) << " ------ " << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) << " ------ "  << setw(7) <<  " ------ "  << endl;
       }

       // Finding out what the player got
       win = handFind(card);

       if(win == 0){
            money;
            cout << "\nSorry, you did not get anything this round." << endl;
       }

       // 1 pair
       if(win == 1){
            money = money + bet;
            cout << "\nNice! You got a Jacks or better pair." << endl;
       }

       // 2 pair
       if(win == 2){
            money = money + bet*2;
            cout << "\nNice! You got a two pair." << endl;
       }

       // 3 of a kind
       if(win == 3){
            money = money + bet*3;
            cout << "\nNice! You got a three of a kind." << endl;
       }

       // straight
       if(win == 4){
            money = money + bet*4;
            cout << "\nNice! You got a straight." << endl;
       }

       // flush
       if(win == 5){
            money = money + bet*6;
            cout << "\nNice! You got a flush." << endl;
       }

       // full house
       if(win == 6){
            money = money + bet*9;
            cout << "\nNice! You got a full house." << endl;
       }

       // 4 of a kind
       if(win == 7){
            money = money + bet*25;
            cout << "\nNice! You got a four of a kind." << endl;
       }

       // straight flush
       if(win == 8){
           money = money + bet*50;
           cout << "\nNice! You got a straight flush." << endl;
       }

       // royal flush
       if(win == 9){
            money = money + bet*250;
            cout << "\nNice! You got a royal flush." << endl;
       }

       // Show money to user
       cout << "\nYou now have $" << money << endl;

       // lost message
       if(money == 0){
        cout << "\nSorry, you lost all your money. Restart the program if you want to be able to bet on future hands!" << endl;
       }

       // prompting user if they wish to play again.
       do{
        cout << "\nWould you like to play another round? Type 'y' to continue. Type 'n' to stop program." << endl;
        cin >> answer;

        if(answer == 'Y' || answer == 'y'){
            cont = 1;
        }
        if(answer == 'N' || answer == 'n'){
            cont = 0;
        }
        if(cont != 1 && cont != 0){
            cout <<  "\nSorry, that is not a valid answer." << endl;
        }

       }while(cont != 1 && cont !=0);

    }while(cont == 1);

return 0;
}
