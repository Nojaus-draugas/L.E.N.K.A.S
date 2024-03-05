//projektinio darbo kodas:

#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

int c=1;
int balance;
int gamelost;
int gamesPlayed=0;
void start(){
ifstream input("input.txt");
input >> balance;
}
void balanceChange(){
    ofstream output ("input.txt");
    output << balance;
}
void blackjack()

{

    cout << "Sveikas atvykes i vartykla" << endl;

    int bet, input, temp, exit, a=0, b=0, win;

    string sirdys = "sirdziu";
    string bugnai = "bugnu";
    string kryziai = "kryziu";
    string vynai = "vynu";
    int dealerSum = 0;
    int playerSum = 0;
    vector <int> korta;
    vector <int> dlrKrt;
    vector <string> dlrLgn;
    vector <string> legenda;
    srand((unsigned) time(NULL));


    while(exit!=2)

    {
        balanceChange();
        playerSum=0;
        dealerSum=0;
        input = 0;
        win =0;
        a = 0;
        b=0;
        korta.clear();
        dlrKrt.clear();
        legenda.clear();
        dlrLgn.clear();

        cout << "Kiek statai? Turi: " << balance << " pinigu" << endl;
        cin >> bet;
        if(bet > balance){
            while(bet>balance){
        cout << "Nu zinok taip neveikia. Neturi tiek pinigu. Bandyk vel" << endl;
        cout << endl;
        cin >> bet;
        }
    } else{
        balance = balance-bet;
        cout << "Tavo statymas priimtas! Dabar turi: " << balance << " pinigu" << endl;
    }
        cout << endl;
        cout << "Pradedam zaidima?" << endl;
        cout << "1 - TAIP" << endl;
        cout << "2 - NE" << endl;
        cin >> exit;
        if(exit != 1 && exit !=2){
          cout <<   "nera tokio pasirinkimo seniukai" << endl;
          while(exit!=1 && exit!=2){
            cout << "Bandyk is naujo" << endl;
            cin >> exit;
          }
        }

        cout << endl << endl << endl;

        if(exit!=2)

        {
            for(int i=0; i<2; i++)
            {
                temp = 2 + (rand() %13);
                if(temp == 12 || temp == 13 || temp == 14) temp=10;
                korta.push_back(temp);

                playerSum += temp;
                temp = 1 + (rand() %4);

                if(temp == 1){
                    legenda.push_back(sirdys);
                }

                if(temp == 2){
                    legenda.push_back(bugnai);
                }

                if(temp == 3){
                    legenda.push_back(kryziai);
                }

                if(temp == 4){
                    legenda.push_back(vynai);
                }

            }

            temp = 2 + (rand() %13);
            if(temp == 12 || temp == 13 || temp == 14) temp=10;
            dlrKrt.push_back(temp);

            dealerSum += temp;

            temp = 1 + (rand() %4);

            if(temp == 1){
                dlrLgn.push_back(sirdys);
            }

            if(temp == 2){
                dlrLgn.push_back(bugnai);
            }

            if(temp == 3){
            dlrLgn.push_back(kryziai);
            }

            if(temp == 4){
                dlrLgn.push_back(vynai);
            }

            cout << "tavo kortos: " << legenda[0] << " " << korta[0] << " ir " << legenda[1] << " " << korta[1] << endl;
            cout << "bendra suma: " << playerSum << endl << endl;
            cout << "mano kortos: " << dlrLgn[0] << " " << dlrKrt[0] << endl;
            cout << "bendra suma: " << dealerSum << endl << endl;

            while(input!=2)

            {

                cout << endl;
                cout << "Ka darom?" << endl;
                cout << "1 - verciam" << endl;
                cout << "2 - stovim" << endl;
                cin >> input;
                cout << endl;

                if(input==1)

                {

                    temp = 2 + (rand() %13);
                    if(temp == 12 || temp == 13 || temp == 14) temp=10;

                    korta.push_back(temp);
                    playerSum += temp;

                    temp = 1 + (rand() %4);

                    if(temp ==1){
                        legenda.push_back(sirdys);
                    }

                    if(temp == 2){
                        legenda.push_back(bugnai);
                    }

                    if(temp == 3){
                        legenda.push_back(kryziai);
                    }

                    if(temp == 4){
                        legenda.push_back(vynai);
                    }


                    a++;
                    for(int i=2; i<2+a; i++)
                    {
                        if(playerSum<=21 && korta[i]!=11){
                        cout << "Tavo nauja korta: " <<  legenda[i] << " " << korta[i] << " " << endl;

                        cout << "bendra suma: " << playerSum << endl;
                      } else {
                        cout << "Korta, kuri tave sudegino " <<  legenda[i] << " " << korta[i] << " " << endl;
                      }
                    }
                    for(int i=0; i<korta.size(); i++){
                        temp = korta[i];
                      if(playerSum > 21 && temp == 11){
                        playerSum = playerSum-10;
                        cout << "Kadangi tu sudegei, tavo tuzas tapo 1. Tavo bendra suma: " << playerSum << endl;
                        temp = 1;
                        korta[i] = temp;
                      }
                    }



                    if(playerSum > 21){
                        cout << "Viskas seniukai, sudegei" << endl << endl;
                        input = 2;
                        gamelost = 1;
                        playerSum = 0;
                        gamesPlayed++;

                    }






                }

                else if(input==2){
                //DEALERIO KORTOS
               if(dealerSum < playerSum && dealerSum < 21){
                while(dealerSum< playerSum && dealerSum <21){
                temp = 2 + (rand() %13);
            if(temp == 12 || temp == 13 || temp == 14) temp=10;
            dlrKrt.push_back(temp);

            dealerSum += temp;

            temp = 1 + (rand() %4);

            if(temp == 1){
                dlrLgn.push_back(sirdys);
            }

            if(temp == 2){
                dlrLgn.push_back(bugnai);
            }

            if(temp == 3){
            dlrLgn.push_back(kryziai);
            }

            if(temp == 4){
            dlrLgn.push_back(vynai);
               }

b++;

            for(int i=0; i<b; i++){

                cout << "Mano nauja korta: " << dlrLgn[i] << " " << dlrKrt[i] << endl;
                cout << "Mano bendra suma: " << dealerSum << endl;
                cout << b << " " << i << endl;
            }

                }
                } if(dealerSum > 21 && playerSum <= 21){
                    win=1;

                }

                 else if(dealerSum > playerSum){
                    cout << "AJAJ. Dealeris tave sudauze" << endl;
                } else if(dealerSum == playerSum && playerSum<=21){
                    cout << "Lygiosios!" << endl;
                    balance = balance+bet;

                }
                }
                else cout << "taigi vps nera tokio pasirinkimo, kas tau yra" << endl;
            }
        }
        else{
            continue;
        }
      if(win==1){
        cout << "Sveikinu! laimejai " << bet << " pinigu" << endl;
        balance = balance+bet*2;

      }

    }
}

void dice()
{

    cout << "Sveikas atvykes i vps cia random bus" << endl;

    srand((unsigned) time(NULL));
    int dice1, exit;
    int dice2, diceSum;
    int guess;
    int bet;
    bool lyginis, spejimas;

    while(exit!=2){
    cout << "Pasirink, kiek nori statyti. Tavo balansas: " << balance << endl;

    cin >> bet;
    if(bet > balance){
            while(bet>balance){
        cout << "Nu zinok taip neveikia. Neturi tiek pinigu. Bandyk vel" << endl;
        cout << endl;
        cin >> bet;
        }
    } else{
        balance = balance-bet;
    }



    cout << endl << endl << "Kaip manai kauliuku suma bus lyginis ar nelyginis?" << endl;
    cout << "1 - lyginis" << endl;
    cout << "2 - nelyginis" << endl;
    cin >> guess;
    cout << endl;

    if(guess==1) {spejimas = true;}
    else if(guess == 2) {spejimas = false;}
    else {cout << "net nera tokio varianto nu" << endl; cout << endl;}

    dice1 = 1 + (rand() %6);

    dice2 = 1 + (rand() %6);

    diceSum = dice1 + dice2;

    cout << "Pirmas kauliukas iskrito: " << dice1 << " O antras kauliukas yra... " << dice2 << endl;

    if(diceSum%2==0) lyginis = true;

    else lyginis = false;

    if(spejimas==true && lyginis==true)
    {
        cout << "Sveikinu! tu Laimejai!!!" << endl;
        balance = balance + bet*2;
        cout << "Tavo balansas: " << balance << endl;
        cout << endl;
    }

    if(spejimas==false && lyginis==false){
        cout << "Sveikinu! tu Laimejai!!!" << endl;
        balance = balance + bet*2;
        cout << "Tavo balansas: " << balance << endl;
        cout << endl;
    }

    else

    {
        cout << "AJAJAJ, vieno kauliuko pritruko! Nu gal kita karta" << endl;
        cout << "Tavo, luzerio, balansas: " << balance << endl;
        cout << endl;
    }
    cout << "Ka dabar darom?" << endl;
    cout << "1 - Zaidziam dar viena" << endl;
    cout << "2 - varom kazka kita" << endl;
    cin >> exit;
    cout << endl;
    if(exit!=1 && exit !=2){
            while(exit!=1 && exit!=2){
        cout <<"nera gi tokio pasirinkimo. Rinkis kaip zmogus arba kvieciu policija" << endl;
        cin >> exit;
            }
    }

    }
}
void gameOver()

{

    cout << "Sveikinu baigus zaidima! Siandien suzaidei " << gamesPlayed << " zaidimu" << endl;
    cout << "Jusu balansas: " << balance << endl;
    balanceChange();
    c=2;
}

void decision()

{

    cout << "Pasirinkite koki zaidima norite zaisti:" << endl;
    cout << "1 - dvidesimt vienas" << endl;

    cout << "2 - kauliukai" << endl;

    cout << "3 - ISLEISKIT MANE!" << endl;

    int decision;

    cin >> decision;

    cout << endl << endl << endl;

    if(decision==1){
        blackjack();
    }
    else if(decision==2){
        dice();
    }
    else if (decision==3){
        gameOver();
    }
    else{
        cout << "Nera tokio pasirenkimo, nusileisk ant zemes, ereli" << endl;
    }

}

int main()

{
    start();
    setlocale(LC_ALL, "Lithuanian");

    cout << "Sveiki atvyke i Lietuvos Elektroniniu Nepilnameciu Kazino Asociaciju Sajunga!" << endl;

    cout << endl << endl;
    while(c!=2){
    decision();
    }

    return 0;

}
