#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

#define TAMANHO_LISTA 4601

// Letras da palavra do dia
char firstLetter, secondLetter, thirdLetter, fourthLetter, fifthLetter;

// Letras da palavra digitada
char c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

void definePalavraDoDia(int randomNumber);
void getPalavra();
bool checkPalavra();

int main()
{
  setlocale(LC_ALL, "");
  std::srand(time(nullptr));
  /*
  std::time_t time = std::time(NULL);
  std::tm* now = std::localtime(&time);

  std::srand(now->tm_yday);
  */
  
  int tentativas = 0;
  bool jogoTerminou = false, venceu = false;

  definePalavraDoDia(std::rand() % TAMANHO_LISTA);

  std::cout << firstLetter << secondLetter << thirdLetter << fourthLetter << fifthLetter << "\n";

  std::cout << "Digite uma palavra de 5 letras:\n";

  do{
    getPalavra();

    venceu = checkPalavra();
    jogoTerminou = tentativas >= 6 || venceu;
    tentativas++;

  } while (!jogoTerminou);

  if (venceu)
  {
    std::cin.ignore();
    std::cout << "Parabéns!\n";
  }
  else
  {
    std::cin.ignore();
    std::cout << "A palavra era " << firstLetter << secondLetter << thirdLetter << fourthLetter << fifthLetter << ".\n";
    std::cout << "Fim do Jogo. Aperte para finalizar.\n";
  }

  std::cin.ignore();

  return 0;
}

bool checkPalavra()
{
  /* Status de cada letra digitada pelo usuário, sendo que:
  N = Não existe na palavra.
  E = Existe, mas está na posição errada.
  C = Correta a posiçao para letra.
  */
  char lC1 = 'N';
  char lC2 = 'N';
  char lC3 = 'N';
  char lC4 = 'N';
  char lC5 = 'N';

  char firstLetterCopy = firstLetter;
  char secondLetterCopy = secondLetter;
  char thirdLetterCopy = thirdLetter;
  char fourthLetterCopy = fourthLetter;
  char fifthLetterCopy = fifthLetter;

  if (!(c1 == firstLetterCopy || c1 == secondLetterCopy || c1 == thirdLetterCopy || c1 == fourthLetterCopy || c1 == fifthLetterCopy))
    lC1 = 'N';
  else
  {
    if (c1 == firstLetterCopy)
    {
      lC1 = 'C';
      firstLetterCopy = '.';
    }
    else
    {
      lC1 = 'E';
    
      if (c1 == secondLetterCopy)
        secondLetterCopy = '.';
      else if (c1 == thirdLetterCopy)
            thirdLetterCopy = '.';
          else if (c1 == fourthLetterCopy)
                fourthLetterCopy = '.';
              else fifthLetterCopy = '.';
    }
  }

  if (!(c2 == firstLetterCopy || c2 == secondLetterCopy || c2 == thirdLetterCopy || c2 == fourthLetterCopy || c2 == fifthLetterCopy))
    lC2 = 'N';
  else
  {
    if (c2 == secondLetterCopy)
    {
      lC2 = 'C';
      secondLetterCopy = '.';
    }
    else
    {
      lC2 = 'E';

      if (c2 == firstLetterCopy)
        firstLetterCopy = '.';      
      else if (c2 == thirdLetterCopy)
            thirdLetterCopy = '.';
          else if (c2 == fourthLetterCopy)
                fourthLetterCopy = '.';
              else fifthLetterCopy = '.';
    }
  }

  if (!(c3 == firstLetterCopy || c3 == secondLetterCopy || c3 == thirdLetterCopy || c3 == fourthLetterCopy || c3 == fifthLetterCopy))
    lC3 = 'N';
  else
  {
    if (c3 == thirdLetterCopy)
    {
      lC3 = 'C';
      thirdLetterCopy = '.';
    }
    else
    {
      lC3 = 'E';

      if (c3 == firstLetterCopy)
        firstLetterCopy = '.';
      else if (c3 == secondLetterCopy)
            secondLetterCopy = '.';
          else if (c3 == fourthLetterCopy)
                fourthLetterCopy = '.';
              else fifthLetterCopy = '.';
    }
  }

  if (!(c4 == firstLetterCopy || c4 == secondLetterCopy || c4 == thirdLetterCopy || c4 == fourthLetterCopy || c4 == fifthLetterCopy))
    lC4 = 'N';
  else
  {
    if (c4 == fourthLetterCopy)
    {
      lC4 = 'C';
      fourthLetterCopy = '.';
    }
    else
    {
      lC4 = 'E';
    
      if (c4 == firstLetterCopy)
        firstLetterCopy = '.';
      else if (c4 == secondLetterCopy)
            secondLetterCopy = '.';
          else if (c4 == thirdLetterCopy)
                thirdLetterCopy = '.';
              else fifthLetterCopy = '.';
    }
  }

  if (!(c5 == firstLetterCopy || c5 == secondLetterCopy || c5 == thirdLetterCopy || c5 == fourthLetterCopy || c5 == fifthLetterCopy))
    lC5 = 'N';
  else
  {
    if (c5 == fifthLetterCopy)
    {
      lC5 = 'C';
      fifthLetterCopy = '.';
    }
    else
    {
      lC5 = 'E';
    
      if (c5 == firstLetterCopy)
        firstLetterCopy = '.';
      else if (c5 == secondLetterCopy)
            secondLetterCopy = '.';
          else if (c5 == thirdLetterCopy)
                thirdLetterCopy = '.';
              else fourthLetterCopy = '.';
    }
  }

  std::cout << lC1 << lC2 << lC3 << lC4 << lC5 << "\n\n";

  return lC1 == 'C' && lC2 == 'C' && lC3 == 'C' && lC4 == 'C' && lC5 == 'C';
}

void getPalavra()
{
  bool palavraValida = false;

  do{
    std::cin >> std::setw(6) >> c1 >> c2 >> c3 >> c4 >> c5;

    if (!(palavraValida = (c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z') && (c3 >= 'a' && c3 <= 'z') && (c4 >= 'a' && c4 <= 'z') && (c5 >= 'a' && c5 <= 'z' && c5)))
      std::cout << "A palavra deve ter exatamente 5 caracteres alfabéticos (minúsculos).\n";

  } while (!palavraValida);
}

void definePalavraDoDia(int randomNumber)
{
  switch (randomNumber)
  {
    /* agimo */
  case 0:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* agira */
  case 1:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* agita */
  case 2:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* agite */
  case 3:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* agito */
  case 4:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* agora */
  case 5:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* aguai */
  case 6:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* aguam */
  case 7:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* aguar */
  case 8:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* aguas */
  case 9:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* aguce */
  case 10:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* aguda */
  case 11:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* agudo */
  case 12:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* aguei */
  case 13:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* aguem */
  case 14:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* agues */
  case 15:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* aguou */
  case 16:
    firstLetter = 'a';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ainda */
  case 17:
    firstLetter = 'a';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* aires */
  case 18:
    firstLetter = 'a';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ajais */
  case 19:
    firstLetter = 'a';
    secondLetter = 'j';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ajamo */
  case 20:
    firstLetter = 'a';
    secondLetter = 'j';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ajuda */
  case 21:
    firstLetter = 'a';
    secondLetter = 'j';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* ajude */
  case 22:
    firstLetter = 'a';
    secondLetter = 'j';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* ajudo */
  case 23:
    firstLetter = 'a';
    secondLetter = 'j';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* alado */
  case 24:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* alago */
  case 25:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* alcei */
  case 26:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* alcem */
  case 27:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* alces */
  case 28:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* alega */
  case 29:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* alego */
  case 30:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* algas */
  case 31:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* algoz */
  case 32:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'z';
    break;

  /* algum */
  case 33:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'm';
    break;

  /* alhos */
  case 34:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* aliai */
  case 35:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* aliam */
  case 36:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* aliar */
  case 37:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* alias */
  case 38:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* aliei */
  case 39:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* aliem */
  case 40:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* alies */
  case 41:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* alija */
  case 42:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* alije */
  case 43:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* alijo */
  case 44:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* aliou */
  case 45:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* alisa */
  case 46:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* alise */
  case 47:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* aliso */
  case 48:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* almas */
  case 49:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* aloca */
  case 50:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* aloco */
  case 51:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* aloja */
  case 52:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* aloje */
  case 53:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* alojo */
  case 54:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* altar */
  case 55:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* altas */
  case 56:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* altos */
  case 57:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* aluda */
  case 58:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* alude */
  case 59:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* aludi */
  case 60:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* aludo */
  case 61:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* aluga */
  case 62:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* alugo */
  case 63:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* aluna */
  case 64:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* aluno */
  case 65:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* alvas */
  case 66:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* alves */
  case 67:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* alvor */
  case 68:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* alvos */
  case 69:
    firstLetter = 'a';
    secondLetter = 'l';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* amado */
  case 70:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* amais */
  case 71:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* amamo */
  case 72:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* amaro */
  case 73:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ambas */
  case 74:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ambos */
  case 75:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ameba */
  case 76:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* ameia */
  case 77:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ameis */
  case 78:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* amemo */
  case 79:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* amena */
  case 80:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* ameno */
  case 81:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* amido */
  case 82:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* amiga */
  case 83:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* amigo */
  case 84:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* amima */
  case 85:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* amime */
  case 86:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* amimo */
  case 87:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* amola */
  case 88:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* amole */
  case 89:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* amolo */
  case 90:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* amora */
  case 91:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ampla */
  case 92:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'p';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* amplo */
  case 93:
    firstLetter = 'a';
    secondLetter = 'm';
    thirdLetter = 'p';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* anais */
  case 94:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ancas */
  case 95:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* andai */
  case 96:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* andam */
  case 97:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* andar */
  case 98:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* andas */
  case 99:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* andei */
  case 100:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* andem */
  case 101:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* andes */
  case 102:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* andor */
  case 103:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* andou */
  case 104:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* anela */
  case 105:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* anele */
  case 106:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* anelo */
  case 107:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* anexa */
  case 108:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* anexe */
  case 109:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* anexo */
  case 110:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* anglo */
  case 111:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* angra */
  case 112:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* anima */
  case 113:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* anime */
  case 114:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* animo */
  case 115:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* anjos */
  case 116:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* anota */
  case 117:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* anote */
  case 118:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* anoto */
  case 119:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* antas */
  case 120:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* antes */
  case 121:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* antro */
  case 122:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* anual */
  case 123:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* anuam */
  case 124:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* anuas */
  case 125:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* anuem */
  case 126:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* anuir */
  case 127:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* anuis */
  case 128:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* anuiu */
  case 129:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* anula */
  case 130:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* anule */
  case 131:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* anulo */
  case 132:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* anzol */
  case 133:
    firstLetter = 'a';
    secondLetter = 'n';
    thirdLetter = 'z';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* aonde */
  case 134:
    firstLetter = 'a';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* aorta */
  case 135:
    firstLetter = 'a';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* apago */
  case 136:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* apare */
  case 137:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* aparo */
  case 138:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* apeai */
  case 139:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* apear */
  case 140:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* apeei */
  case 141:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* apega */
  case 142:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* apego */
  case 143:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* apeia */
  case 144:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* apeie */
  case 145:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* apeio */
  case 146:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* apela */
  case 147:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* apele */
  case 148:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* apelo */
  case 149:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* apena */
  case 150:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* apene */
  case 151:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* apeno */
  case 152:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* apeou */
  case 153:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* apita */
  case 154:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* apite */
  case 155:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* apito */
  case 156:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* apoio */
  case 157:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'o';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* apolo */
  case 158:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* aptas */
  case 159:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* aptos */
  case 160:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* apura */
  case 161:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* apure */
  case 162:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* apuro */
  case 163:
    firstLetter = 'a';
    secondLetter = 'p';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* arado */
  case 164:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* arais */
  case 165:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* arame */
  case 166:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* aramo */
  case 167:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* arcai */
  case 168:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* arcam */
  case 169:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* arcar */
  case 170:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* arcas */
  case 171:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* arcos */
  case 172:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* arcou */
  case 173:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ardam */
  case 174:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ardas */
  case 175:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ardei */
  case 176:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ardem */
  case 177:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* arder */
  case 178:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* ardes */
  case 179:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ardeu */
  case 180:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* ardia */
  case 181:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ardil */
  case 182:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* ardis */
  case 183:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ardor */
  case 184:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* areal */
  case 185:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* areia */
  case 186:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* areis */
  case 187:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* areja */
  case 188:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* areje */
  case 189:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* arejo */
  case 190:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* aremo */
  case 191:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* arena */
  case 192:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* arfai */
  case 193:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* arfam */
  case 194:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* arfar */
  case 195:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* arfas */
  case 196:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* arfei */
  case 197:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* arfem */
  case 198:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* arfes */
  case 199:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* arfou */
  case 200:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* argua */
  case 201:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* argui */
  case 202:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* arguo */
  case 203:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* armai */
  case 204:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* armam */
  case 205:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* armar */
  case 206:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* armas */
  case 207:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* armei */
  case 208:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* armem */
  case 209:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* armes */
  case 210:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* armou */
  case 211:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* aroma */
  case 212:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* arpoa */
  case 213:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* arpoe */
  case 214:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* arque */
  case 215:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* arria */
  case 216:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* arrie */
  case 217:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* arrio */
  case 218:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* arroz */
  case 219:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'z';
    break;

  /* artes */
  case 220:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* artur */
  case 221:
    firstLetter = 'a';
    secondLetter = 'r';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'r';
    break;

  /* asila */
  case 222:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* asile */
  case 223:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* asilo */
  case 224:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* asnos */
  case 225:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* aspas */
  case 226:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* assai */
  case 227:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* assam */
  case 228:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* assar */
  case 229:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* assas */
  case 230:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* assaz */
  case 231:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* assei */
  case 232:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* assem */
  case 233:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* asses */
  case 234:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* assim */
  case 235:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* assis */
  case 236:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* assoa */
  case 237:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* assoe */
  case 238:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* assou */
  case 239:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* astro */
  case 240:
    firstLetter = 'a';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ataco */
  case 241:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* atado */
  case 242:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* atais */
  case 243:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* atamo */
  case 244:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ateai */
  case 245:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* atear */
  case 246:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ateei */
  case 247:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ateia */
  case 248:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ateie */
  case 249:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* ateio */
  case 250:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* ateis */
  case 251:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* atemo */
  case 252:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ateou */
  case 253:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ateus */
  case 254:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* ateve */
  case 255:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* atice */
  case 256:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* atido */
  case 257:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* atina */
  case 258:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* atine */
  case 259:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* atino */
  case 260:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* atira */
  case 261:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* atire */
  case 262:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* atiro */
  case 263:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ativa */
  case 264:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* ative */
  case 265:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* ativo */
  case 266:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* atlas */
  case 267:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* atola */
  case 268:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* atole */
  case 269:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* atolo */
  case 270:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* atrai */
  case 271:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* atriz */
  case 272:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* atuai */
  case 273:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* atual */
  case 274:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* atuam */
  case 275:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* atuar */
  case 276:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* atuas */
  case 277:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* atuei */
  case 278:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* atuem */
  case 279:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* atues */
  case 280:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* atuns */
  case 281:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 's';
    break;

  /* atuou */
  case 282:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* atura */
  case 283:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ature */
  case 284:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* aturo */
  case 285:
    firstLetter = 'a';
    secondLetter = 't';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* audaz */
  case 286:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* aulas */
  case 287:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* auras */
  case 288:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* autor */
  case 289:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* autos */
  case 290:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* autua */
  case 291:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* autue */
  case 292:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* autuo */
  case 293:
    firstLetter = 'a';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* avais */
  case 294:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* avaro */
  case 295:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* aveia */
  case 296:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* aveio */
  case 297:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* aviai */
  case 298:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* aviam */
  case 299:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* aviar */
  case 300:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* avias */
  case 301:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* aviei */
  case 302:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* aviem */
  case 303:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* avier */
  case 304:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* avies */
  case 305:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* avimo */
  case 306:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* aviou */
  case 307:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* avisa */
  case 308:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* avise */
  case 309:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* aviso */
  case 310:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* aviva */
  case 311:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* avive */
  case 312:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* avivo */
  case 313:
    firstLetter = 'a';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* axial */
  case 314:
    firstLetter = 'a';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* axila */
  case 315:
    firstLetter = 'a';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* azare */
  case 316:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* azaro */
  case 317:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* azeda */
  case 318:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* azede */
  case 319:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* azedo */
  case 320:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* azias */
  case 321:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* azoto */
  case 322:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* azuis */
  case 323:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* azula */
  case 324:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* azule */
  case 325:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* azulo */
  case 326:
    firstLetter = 'a';
    secondLetter = 'z';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* babai */
  case 327:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* babam */
  case 328:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* babar */
  case 329:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* babas */
  case 330:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* babei */
  case 331:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* babem */
  case 332:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* babes */
  case 333:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* babou */
  case 334:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* bacia */
  case 335:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* bafos */
  case 336:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bagas */
  case 337:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bagos */
  case 338:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bahia */
  case 339:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'h';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* baias */
  case 340:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* baila */
  case 341:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* baile */
  case 342:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* bailo */
  case 343:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* baita */
  case 344:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* baixa */
  case 345:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* baixe */
  case 346:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* baixo */
  case 347:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* balam */
  case 348:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* balas */
  case 349:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* balde */
  case 350:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* balem */
  case 351:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* bales */
  case 352:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* balia */
  case 353:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* balir */
  case 354:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* balis */
  case 355:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* baliu */
  case 356:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* balsa */
  case 357:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* bamba */
  case 358:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* bambo */
  case 359:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* bambu */
  case 360:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'u';
    break;

  /* banal */
  case 361:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* banca */
  case 362:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* banco */
  case 363:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* banda */
  case 364:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* bando */
  case 365:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* banem */
  case 366:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* banes */
  case 367:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* banha */
  case 368:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* banhe */
  case 369:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* banho */
  case 370:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* bania */
  case 371:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* banir */
  case 372:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* banis */
  case 373:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* baniu */
  case 374:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* banjo */
  case 375:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* baque */
  case 376:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* barba */
  case 377:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* barca */
  case 378:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* barco */
  case 379:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* bardo */
  case 380:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* bares */
  case 381:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* barra */
  case 382:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* barre */
  case 383:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* barro */
  case 384:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* bases */
  case 385:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* basta */
  case 386:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* baste */
  case 387:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* basto */
  case 388:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* batam */
  case 389:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* batas */
  case 390:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* batei */
  case 391:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* batel */
  case 392:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* batem */
  case 393:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* bater */
  case 394:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* bates */
  case 395:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* bateu */
  case 396:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* batia */
  case 397:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* batom */
  case 398:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'm';
    break;

  /* bauru */
  case 399:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'u';
    break;

  /* bazar */
  case 400:
    firstLetter = 'b';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* beata */
  case 401:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* beato */
  case 402:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* bebam */
  case 403:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* bebas */
  case 404:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bebei */
  case 405:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* bebem */
  case 406:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* beber */
  case 407:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* bebes */
  case 408:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* bebeu */
  case 409:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* bebia */
  case 410:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* becas */
  case 411:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* becos */
  case 412:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* beija */
  case 413:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* beije */
  case 414:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* beijo */
  case 415:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* beira */
  case 416:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* beire */
  case 417:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* beiro */
  case 418:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* belas */
  case 419:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* belga */
  case 420:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* belos */
  case 421:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bemol */
  case 422:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* benta */
  case 423:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* bento */
  case 424:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* benza */
  case 425:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* benze */
  case 426:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* benzi */
  case 427:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'i';
    break;

  /* benzo */
  case 428:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* beque */
  case 429:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* berna */
  case 430:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* berra */
  case 431:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* berre */
  case 432:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* berro */
  case 433:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* besta */
  case 434:
    firstLetter = 'b';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* bicai */
  case 435:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* bicam */
  case 436:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* bicar */
  case 437:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* bicas */
  case 438:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bicha */
  case 439:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* bicho */
  case 440:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* bicos */
  case 441:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bicou */
  case 442:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* biela */
  case 443:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* bigas */
  case 444:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bingo */
  case 445:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* bique */
  case 446:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* birra */
  case 447:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* bispo */
  case 448:
    firstLetter = 'b';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* blefa */
  case 449:
    firstLetter = 'b';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* blefe */
  case 450:
    firstLetter = 'b';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* blefo */
  case 451:
    firstLetter = 'b';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* bloco */
  case 452:
    firstLetter = 'b';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* blusa */
  case 453:
    firstLetter = 'b';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* boate */
  case 454:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* boato */
  case 455:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* bobas */
  case 456:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bobos */
  case 457:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bocal */
  case 458:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* bocas */
  case 459:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bocha */
  case 460:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* bodas */
  case 461:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bodes */
  case 462:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* boiai */
  case 463:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* boiar */
  case 464:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* boiei */
  case 465:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* boina */
  case 466:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* boiou */
  case 467:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* bolai */
  case 468:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* bolam */
  case 469:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* bolar */
  case 470:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* bolas */
  case 471:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* boldo */
  case 472:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* bolei */
  case 473:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* bolem */
  case 474:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* boles */
  case 475:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* bolha */
  case 476:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* bolos */
  case 477:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* bolou */
  case 478:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* bolsa */
  case 479:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* bolso */
  case 480:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* bomba */
  case 481:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* bonde */
  case 482:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* borda */
  case 483:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* borde */
  case 484:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* bordo */
  case 485:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* borra */
  case 486:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* borre */
  case 487:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* borro */
  case 488:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* bossa */
  case 489:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* bosta */
  case 490:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* botai */
  case 491:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* botam */
  case 492:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* botar */
  case 493:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* botas */
  case 494:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* botei */
  case 495:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* botem */
  case 496:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* botes */
  case 497:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* botou */
  case 498:
    firstLetter = 'b';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* braba */
  case 499:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* brabo */
  case 500:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* brada */
  case 501:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* brade */
  case 502:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* brado */
  case 503:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* braga */
  case 504:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* brama */
  case 505:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* brame */
  case 506:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* brami */
  case 507:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* bramo */
  case 508:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* brasa */
  case 509:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* brava */
  case 510:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* bravo */
  case 511:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* breca */
  case 512:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* breco */
  case 513:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* brejo */
  case 514:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* breve */
  case 515:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* brida */
  case 516:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* briga */
  case 517:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* brigo */
  case 518:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* brins */
  case 519:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 's';
    break;

  /* brios */
  case 520:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* brisa */
  case 521:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* brita */
  case 522:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* brito */
  case 523:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* broas */
  case 524:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* broca */
  case 525:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* broco */
  case 526:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* bromo */
  case 527:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* brota */
  case 528:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* brote */
  case 529:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* broto */
  case 530:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* bruma */
  case 531:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* bruta */
  case 532:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* bruto */
  case 533:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* bruxa */
  case 534:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* bruxo */
  case 535:
    firstLetter = 'b';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* bucal */
  case 536:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* bucha */
  case 537:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* bucho */
  case 538:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* bueno */
  case 539:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* bufai */
  case 540:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* bufam */
  case 541:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* bufar */
  case 542:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* bufas */
  case 543:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bufei */
  case 544:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* bufem */
  case 545:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* bufes */
  case 546:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* bufou */
  case 547:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* bulam */
  case 548:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* bulas */
  case 549:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* bulbo */
  case 550:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* bules */
  case 551:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* bulia */
  case 552:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* bulir */
  case 553:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* bulis */
  case 554:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* buliu */
  case 555:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* bumbo */
  case 556:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* bunda */
  case 557:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* bunde */
  case 558:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* bundo */
  case 559:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* burgo */
  case 560:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* burla */
  case 561:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* burle */
  case 562:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* burlo */
  case 563:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* burra */
  case 564:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* burro */
  case 565:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* busca */
  case 566:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* busco */
  case 567:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* busto */
  case 568:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* buxos */
  case 569:
    firstLetter = 'b';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cabei */
  case 570:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cabem */
  case 571:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* caber */
  case 572:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* cabes */
  case 573:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cabia */
  case 574:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* cabos */
  case 575:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cabra */
  case 576:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cacas */
  case 577:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cacei */
  case 578:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cacem */
  case 579:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* caces */
  case 580:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cacho */
  case 581:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* cacos */
  case 582:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cacto */
  case 583:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cagai */
  case 584:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* cagam */
  case 585:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cagar */
  case 586:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* cagas */
  case 587:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cagou */
  case 588:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* cague */
  case 589:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* caiai */
  case 590:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* caiam */
  case 591:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* caiar */
  case 592:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* caias */
  case 593:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* caiba */
  case 594:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* caibo */
  case 595:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* caido */
  case 596:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* caiei */
  case 597:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* caiem */
  case 598:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* caies */
  case 599:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* caiou */
  case 600:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* cairo */
  case 601:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* caixa */
  case 602:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* calai */
  case 603:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* calam */
  case 604:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* calar */
  case 605:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* calas */
  case 606:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* calca */
  case 607:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* calce */
  case 608:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* calco */
  case 609:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* calda */
  case 610:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* caldo */
  case 611:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* calei */
  case 612:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* calem */
  case 613:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cales */
  case 614:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* calha */
  case 615:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* calhe */
  case 616:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* calho */
  case 617:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* calma */
  case 618:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* calmo */
  case 619:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* calor */
  case 620:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* calos */
  case 621:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* calou */
  case 622:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* calva */
  case 623:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* calvo */
  case 624:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* camas */
  case 625:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* campo */
  case 626:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* canal */
  case 627:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* canas */
  case 628:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* canga */
  case 629:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* canja */
  case 630:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* canoa */
  case 631:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* canos */
  case 632:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cansa */
  case 633:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* canse */
  case 634:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* canso */
  case 635:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* canta */
  case 636:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cante */
  case 637:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* canto */
  case 638:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* capai */
  case 639:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* capam */
  case 640:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* capar */
  case 641:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* capas */
  case 642:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* capaz */
  case 643:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* capei */
  case 644:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* capem */
  case 645:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* capes */
  case 646:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* capim */
  case 647:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* capou */
  case 648:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* capta */
  case 649:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* capte */
  case 650:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* capto */
  case 651:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* caput */
  case 652:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 't';
    break;

  /* capuz */
  case 653:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 'z';
    break;

  /* caras */
  case 654:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cardo */
  case 655:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* carga */
  case 656:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* cargo */
  case 657:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* carmo */
  case 658:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* carne */
  case 659:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* caros */
  case 660:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* carpa */
  case 661:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* carpe */
  case 662:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* carpi */
  case 663:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'i';
    break;

  /* carro */
  case 664:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* carta */
  case 665:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* casai */
  case 666:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* casal */
  case 667:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* casam */
  case 668:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* casar */
  case 669:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* casas */
  case 670:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* casca */
  case 671:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* casco */
  case 672:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* casei */
  case 673:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* casem */
  case 674:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cases */
  case 675:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* casos */
  case 676:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* casou */
  case 677:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* caspa */
  case 678:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* cassa */
  case 679:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* casse */
  case 680:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* casso */
  case 681:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* casta */
  case 682:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* casto */
  case 683:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* catai */
  case 684:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* catam */
  case 685:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* catar */
  case 686:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* catas */
  case 687:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* catei */
  case 688:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* catem */
  case 689:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cates */
  case 690:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* catou */
  case 691:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* catre */
  case 692:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* cauda */
  case 693:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* caule */
  case 694:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* causa */
  case 695:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* cause */
  case 696:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* causo */
  case 697:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* cauta */
  case 698:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cauto */
  case 699:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cavai */
  case 700:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* cavam */
  case 701:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cavar */
  case 702:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* cavas */
  case 703:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cavei */
  case 704:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cavem */
  case 705:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* caves */
  case 706:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cavia */
  case 707:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* cavie */
  case 708:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* cavio */
  case 709:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* cavou */
  case 710:
    firstLetter = 'c';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ceado */
  case 711:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* ceais */
  case 712:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ceamo */
  case 713:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ceara */
  case 714:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ceava */
  case 715:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* cedam */
  case 716:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cedas */
  case 717:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cedei */
  case 718:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cedem */
  case 719:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ceder */
  case 720:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* cedes */
  case 721:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cedeu */
  case 722:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* cedia */
  case 723:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* cedro */
  case 724:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ceeis */
  case 725:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ceemo */
  case 726:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* cegai */
  case 727:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* cegam */
  case 728:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cegar */
  case 729:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* cegas */
  case 730:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cegos */
  case 731:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cegou */
  case 732:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* cegue */
  case 733:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* ceiam */
  case 734:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ceias */
  case 735:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ceiem */
  case 736:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ceies */
  case 737:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ceifa */
  case 738:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* ceife */
  case 739:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* ceifo */
  case 740:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* celas */
  case 741:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* celta */
  case 742:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cenas */
  case 743:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* censo */
  case 744:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* cento */
  case 745:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ceras */
  case 746:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cerca */
  case 747:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* cerco */
  case 748:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* cerda */
  case 749:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* cerne */
  case 750:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* cerni */
  case 751:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'i';
    break;

  /* cerol */
  case 752:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* cerra */
  case 753:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cerre */
  case 754:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* cerro */
  case 755:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* certa */
  case 756:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* certo */
  case 757:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cervo */
  case 758:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* cessa */
  case 759:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* cesse */
  case 760:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* cesso */
  case 761:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* cesta */
  case 762:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cesto */
  case 763:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cetim */
  case 764:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* cetro */
  case 765:
    firstLetter = 'c';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* chaga */
  case 766:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* chago */
  case 767:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* chale */
  case 768:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* chama */
  case 769:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* chame */
  case 770:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* chamo */
  case 771:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* chapa */
  case 772:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* chata */
  case 773:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* chato */
  case 774:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* chave */
  case 775:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* checa */
  case 776:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* checo */
  case 777:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* chefa */
  case 778:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* chefe */
  case 779:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* chega */
  case 780:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* chego */
  case 781:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* cheia */
  case 782:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* cheio */
  case 783:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* chiai */
  case 784:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* chiam */
  case 785:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* chiar */
  case 786:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* chias */
  case 787:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* chica */
  case 788:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* chico */
  case 789:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* chiei */
  case 790:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* chiem */
  case 791:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* chies */
  case 792:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* china */
  case 793:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* chiou */
  case 794:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* choca */
  case 795:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* choco */
  case 796:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* chora */
  case 797:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* chore */
  case 798:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* choro */
  case 799:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* chova */
  case 800:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* chove */
  case 801:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* chovi */
  case 802:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* chovo */
  case 803:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* chupa */
  case 804:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* chupe */
  case 805:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* chupo */
  case 806:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* chuta */
  case 807:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* chute */
  case 808:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* chuto */
  case 809:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* chuva */
  case 810:
    firstLetter = 'c';
    secondLetter = 'h';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* ciclo */
  case 811:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* cidra */
  case 812:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cifra */
  case 813:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cifre */
  case 814:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* cifro */
  case 815:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* cinco */
  case 816:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* cinda */
  case 817:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* cinde */
  case 818:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* cindi */
  case 819:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* cindo */
  case 820:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* cinge */
  case 821:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* cingi */
  case 822:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* cinja */
  case 823:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* cinjo */
  case 824:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* cinta */
  case 825:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cinto */
  case 826:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cinza */
  case 827:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* ciosa */
  case 828:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* cioso */
  case 829:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* circo */
  case 830:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* cisca */
  case 831:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* cisco */
  case 832:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* cisma */
  case 833:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* cisme */
  case 834:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* cismo */
  case 835:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* cisne */
  case 836:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* citai */
  case 837:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* citam */
  case 838:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* citar */
  case 839:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* citas */
  case 840:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* citei */
  case 841:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* citem */
  case 842:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cites */
  case 843:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* citou */
  case 844:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* civil */
  case 845:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* civis */
  case 846:
    firstLetter = 'c';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* clama */
  case 847:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* clame */
  case 848:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* clamo */
  case 849:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* clara */
  case 850:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* claro */
  case 851:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* clava */
  case 852:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* clero */
  case 853:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* clima */
  case 854:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* clips */
  case 855:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'p';
    fifthLetter = 's';
    break;

  /* clone */
  case 856:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* cloro */
  case 857:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* clube */
  case 858:
    firstLetter = 'c';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* coada */
  case 859:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* coado */
  case 860:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* coagi */
  case 861:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* coais */
  case 862:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* coaja */
  case 863:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* coajo */
  case 864:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* coamo */
  case 865:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* coara */
  case 866:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* coava */
  case 867:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* coaxa */
  case 868:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* coaxe */
  case 869:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* coaxo */
  case 870:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* cobra */
  case 871:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cobre */
  case 872:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* cobri */
  case 873:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* cobro */
  case 874:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* cocal */
  case 875:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* cocei */
  case 876:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cocem */
  case 877:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* coces */
  case 878:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cocho */
  case 879:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* cocos */
  case 880:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* coege */
  case 881:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* coeis */
  case 882:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* coemo */
  case 883:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* coesa */
  case 884:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* coeso */
  case 885:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* coeva */
  case 886:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* coevo */
  case 887:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* cofre */
  case 888:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* coibi */
  case 889:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'i';
    break;

  /* coice */
  case 890:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* coifa */
  case 891:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* coisa */
  case 892:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* coito */
  case 893:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* colai */
  case 894:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* colam */
  case 895:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* colar */
  case 896:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* colas */
  case 897:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* colei */
  case 898:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* colem */
  case 899:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* coles */
  case 900:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* colha */
  case 901:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* colhe */
  case 902:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* colhi */
  case 903:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'i';
    break;

  /* colho */
  case 904:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* colou */
  case 905:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* comam */
  case 906:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* comas */
  case 907:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* comei */
  case 908:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* comem */
  case 909:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* comer */
  case 910:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* comes */
  case 911:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* comeu */
  case 912:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* comia */
  case 913:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* comum */
  case 914:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'u';
    fifthLetter = 'm';
    break;

  /* conde */
  case 915:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* cones */
  case 916:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* conta */
  case 917:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* conte */
  case 918:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* conto */
  case 919:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* copas */
  case 920:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* copia */
  case 921:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* copie */
  case 922:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* copio */
  case 923:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* copos */
  case 924:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* corai */
  case 925:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* coral */
  case 926:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* coram */
  case 927:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* corar */
  case 928:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* coras */
  case 929:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* corda */
  case 930:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* corei */
  case 931:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* corem */
  case 932:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cores */
  case 933:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* corja */
  case 934:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* corno */
  case 935:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* coroa */
  case 936:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* coroe */
  case 937:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* coros */
  case 938:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* corou */
  case 939:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* corpo */
  case 940:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* corra */
  case 941:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* corre */
  case 942:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* corri */
  case 943:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* corro */
  case 944:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* corta */
  case 945:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* corte */
  case 946:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* corto */
  case 947:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* corvo */
  case 948:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* cosam */
  case 949:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cosas */
  case 950:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cosei */
  case 951:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cosem */
  case 952:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* coser */
  case 953:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* coses */
  case 954:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* coseu */
  case 955:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* cosia */
  case 956:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* cosmo */
  case 957:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* cospe */
  case 958:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* costa */
  case 959:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* cotai */
  case 960:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* cotam */
  case 961:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cotar */
  case 962:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* cotas */
  case 963:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cotei */
  case 964:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cotem */
  case 965:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cotes */
  case 966:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cotou */
  case 967:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* coube */
  case 968:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* couro */
  case 969:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* couto */
  case 970:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* couve */
  case 971:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* covas */
  case 972:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* coxas */
  case 973:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* coxim */
  case 974:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'x';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* coxos */
  case 975:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cozam */
  case 976:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* cozas */
  case 977:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cozei */
  case 978:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* cozem */
  case 979:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cozer */
  case 980:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* cozes */
  case 981:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cozeu */
  case 982:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* cozia */
  case 983:
    firstLetter = 'c';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* crava */
  case 984:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* crave */
  case 985:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* cravo */
  case 986:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* crede */
  case 987:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* credo */
  case 988:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* creia */
  case 989:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* creio */
  case 990:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* crema */
  case 991:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* creme */
  case 992:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* cremo */
  case 993:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* crera */
  case 994:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* criai */
  case 995:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* criam */
  case 996:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* criar */
  case 997:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* crias */
  case 998:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* crido */
  case 999:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* criei */
  case 1000:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* criem */
  case 1001:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cries */
  case 1002:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* crime */
  case 1003:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* crina */
  case 1004:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* criou */
  case 1005:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* crise */
  case 1006:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* criva */
  case 1007:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* crive */
  case 1008:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* crivo */
  case 1009:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* croma */
  case 1010:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* crome */
  case 1011:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* cromo */
  case 1012:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* cruas */
  case 1013:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cruel */
  case 1014:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* cruza */
  case 1015:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* cruze */
  case 1016:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* cruzo */
  case 1017:
    firstLetter = 'c';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* cubas */
  case 1018:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cubos */
  case 1019:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cubra */
  case 1020:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* cubro */
  case 1021:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* cucas */
  case 1022:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cucos */
  case 1023:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cueca */
  case 1024:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* cuias */
  case 1025:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cuida */
  case 1026:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* cuide */
  case 1027:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* cuido */
  case 1028:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* cujas */
  case 1029:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* cujos */
  case 1030:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* cujus */
  case 1031:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* culpa */
  case 1032:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* culpe */
  case 1033:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* culpo */
  case 1034:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* culta */
  case 1035:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* culto */
  case 1036:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* cumes */
  case 1037:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* cunha */
  case 1038:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* cunhe */
  case 1039:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* cunho */
  case 1040:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* cupim */
  case 1041:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* cupom */
  case 1042:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'm';
    break;

  /* curai */
  case 1043:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* curam */
  case 1044:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* curar */
  case 1045:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* curas */
  case 1046:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* curei */
  case 1047:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* curem */
  case 1048:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* cures */
  case 1049:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* curou */
  case 1050:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* cursa */
  case 1051:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* curse */
  case 1052:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* curso */
  case 1053:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* curta */
  case 1054:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* curte */
  case 1055:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* curti */
  case 1056:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* curto */
  case 1057:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* curva */
  case 1058:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* curve */
  case 1059:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* curvo */
  case 1060:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* cuspa */
  case 1061:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* cuspi */
  case 1062:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'i';
    break;

  /* cuspo */
  case 1063:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* custa */
  case 1064:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* custe */
  case 1065:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* custo */
  case 1066:
    firstLetter = 'c';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* dadas */
  case 1067:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dados */
  case 1068:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* damas */
  case 1069:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* damos */
  case 1070:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* danai */
  case 1071:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* danam */
  case 1072:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* danar */
  case 1073:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* danas */
  case 1074:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dance */
  case 1075:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* dando */
  case 1076:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* danei */
  case 1077:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* danem */
  case 1078:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* danes */
  case 1079:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* danos */
  case 1080:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* danou */
  case 1081:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* dante */
  case 1082:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* daqui */
  case 1083:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* dardo */
  case 1084:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* darei */
  case 1085:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* darem */
  case 1086:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dares */
  case 1087:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* daria */
  case 1088:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* datai */
  case 1089:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* datam */
  case 1090:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* datar */
  case 1091:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* datas */
  case 1092:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* datei */
  case 1093:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* datem */
  case 1094:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dates */
  case 1095:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* datou */
  case 1096:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* davam */
  case 1097:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* davas */
  case 1098:
    firstLetter = 'd';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* decai */
  case 1099:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* dedal */
  case 1100:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* dedos */
  case 1101:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* deduz */
  case 1102:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'u';
    fifthLetter = 'z';
    break;

  /* deita */
  case 1103:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* deite */
  case 1104:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* deito */
  case 1105:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* deixa */
  case 1106:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* deixe */
  case 1107:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* deixo */
  case 1108:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* delas */
  case 1109:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* deles */
  case 1110:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* delta */
  case 1111:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* demos */
  case 1112:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* densa */
  case 1113:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* denso */
  case 1114:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* dente */
  case 1115:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* depor */
  case 1116:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* depus */
  case 1117:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* deram */
  case 1118:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* deras */
  case 1119:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* derem */
  case 1120:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* deres */
  case 1121:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dermo */
  case 1122:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* desce */
  case 1123:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* desci */
  case 1124:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'i';
    break;

  /* desde */
  case 1125:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* despe */
  case 1126:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* despi */
  case 1127:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'i';
    break;

  /* dessa */
  case 1128:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* desse */
  case 1129:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* desta */
  case 1130:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* deste */
  case 1131:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* deter */
  case 1132:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* deusa */
  case 1133:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* devam */
  case 1134:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* devas */
  case 1135:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* devei */
  case 1136:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* devem */
  case 1137:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dever */
  case 1138:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* deves */
  case 1139:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* deveu */
  case 1140:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* devia */
  case 1141:
    firstLetter = 'd';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* diabo */
  case 1142:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* dicas */
  case 1143:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dieta */
  case 1144:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* digam */
  case 1145:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* digas */
  case 1146:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* digna */
  case 1147:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* digne */
  case 1148:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* digno */
  case 1149:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* dilua */
  case 1150:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* dilui */
  case 1151:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* diluo */
  case 1152:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* diodo */
  case 1153:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* dique */
  case 1154:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* direi */
  case 1155:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* diria */
  case 1156:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* disca */
  case 1157:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* disco */
  case 1158:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* disse */
  case 1159:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* disso */
  case 1160:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* dista */
  case 1161:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* diste */
  case 1162:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* disto */
  case 1163:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ditai */
  case 1164:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ditam */
  case 1165:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ditar */
  case 1166:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ditas */
  case 1167:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ditei */
  case 1168:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ditem */
  case 1169:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dites */
  case 1170:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ditos */
  case 1171:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ditou */
  case 1172:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* divas */
  case 1173:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dizei */
  case 1174:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* dizem */
  case 1175:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dizer */
  case 1176:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* dizes */
  case 1177:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dizia */
  case 1178:
    firstLetter = 'd';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* doada */
  case 1179:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* doado */
  case 1180:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* doais */
  case 1181:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* doamo */
  case 1182:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* doara */
  case 1183:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* doava */
  case 1184:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* dobra */
  case 1185:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* dobre */
  case 1186:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* dobro */
  case 1187:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* docas */
  case 1188:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* doeis */
  case 1189:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* doemo */
  case 1190:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* doera */
  case 1191:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* dogma */
  case 1192:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* doida */
  case 1193:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* doido */
  case 1194:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* domai */
  case 1195:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* domam */
  case 1196:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* domar */
  case 1197:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* domas */
  case 1198:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* domei */
  case 1199:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* domem */
  case 1200:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* domes */
  case 1201:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* domou */
  case 1202:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* donas */
  case 1203:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* donde */
  case 1204:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* donos */
  case 1205:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* dopai */
  case 1206:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* dopam */
  case 1207:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* dopar */
  case 1208:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* dopas */
  case 1209:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dopei */
  case 1210:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* dopem */
  case 1211:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dopes */
  case 1212:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dopou */
  case 1213:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* dores */
  case 1214:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dorme */
  case 1215:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* dormi */
  case 1216:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* dorso */
  case 1217:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* dosai */
  case 1218:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* dosam */
  case 1219:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* dosar */
  case 1220:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* dosas */
  case 1221:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dosei */
  case 1222:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* dosem */
  case 1223:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* doses */
  case 1224:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dosou */
  case 1225:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* dotai */
  case 1226:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* dotam */
  case 1227:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* dotar */
  case 1228:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* dotas */
  case 1229:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dotei */
  case 1230:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* dotem */
  case 1231:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dotes */
  case 1232:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* dotou */
  case 1233:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* doura */
  case 1234:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* doure */
  case 1235:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* douro */
  case 1236:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* douta */
  case 1237:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* douto */
  case 1238:
    firstLetter = 'd';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* draga */
  case 1239:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* drago */
  case 1240:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* drama */
  case 1241:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* drena */
  case 1242:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* drene */
  case 1243:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* dreno */
  case 1244:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* droga */
  case 1245:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* drogo */
  case 1246:
    firstLetter = 'd';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* duais */
  case 1247:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* dubla */
  case 1248:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* duble */
  case 1249:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* dublo */
  case 1250:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* ducha */
  case 1251:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* duela */
  case 1252:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* duele */
  case 1253:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* duelo */
  case 1254:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* dueto */
  case 1255:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* dumas */
  case 1256:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dunas */
  case 1257:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* dunga */
  case 1258:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* dupla */
  case 1259:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* duplo */
  case 1260:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* duque */
  case 1261:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* durai */
  case 1262:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* duram */
  case 1263:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* durar */
  case 1264:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* duras */
  case 1265:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* durei */
  case 1266:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* durem */
  case 1267:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* dures */
  case 1268:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* durma */
  case 1269:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* durmo */
  case 1270:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* duros */
  case 1271:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* durou */
  case 1272:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* dutos */
  case 1273:
    firstLetter = 'd';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ecoai */
  case 1274:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ecoam */
  case 1275:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ecoar */
  case 1276:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ecoas */
  case 1277:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ecoei */
  case 1278:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ecoem */
  case 1279:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ecoes */
  case 1280:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ecoou */
  case 1281:
    firstLetter = 'e';
    secondLetter = 'c';
    thirdLetter = 'o';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* edema */
  case 1282:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* edita */
  case 1283:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* edite */
  case 1284:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* edito */
  case 1285:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* educa */
  case 1286:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* educo */
  case 1287:
    firstLetter = 'e';
    secondLetter = 'd';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* egito */
  case 1288:
    firstLetter = 'e';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* eiras */
  case 1289:
    firstLetter = 'e';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* eixos */
  case 1290:
    firstLetter = 'e';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ejeta */
  case 1291:
    firstLetter = 'e';
    secondLetter = 'j';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* ejeto */
  case 1292:
    firstLetter = 'e';
    secondLetter = 'j';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* elegi */
  case 1293:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* eleja */
  case 1294:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* elejo */
  case 1295:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* eleva */
  case 1296:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* elevo */
  case 1297:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* elite */
  case 1298:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* elixa */
  case 1299:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* elixe */
  case 1300:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* elixi */
  case 1301:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'i';
    break;

  /* elixo */
  case 1302:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* elmos */
  case 1303:
    firstLetter = 'e';
    secondLetter = 'l';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* emana */
  case 1304:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* emane */
  case 1305:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* emano */
  case 1306:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* emita */
  case 1307:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* emite */
  case 1308:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* emiti */
  case 1309:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* emito */
  case 1310:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* emula */
  case 1311:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* emule */
  case 1312:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* emulo */
  case 1313:
    firstLetter = 'e';
    secondLetter = 'm';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* encha */
  case 1314:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* enche */
  case 1315:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* enchi */
  case 1316:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'i';
    break;

  /* encho */
  case 1317:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* enfia */
  case 1318:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* enfie */
  case 1319:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* enfim */
  case 1320:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* enfio */
  case 1321:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* enjoa */
  case 1322:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* enjoe */
  case 1323:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* enoja */
  case 1324:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* enoje */
  case 1325:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* enojo */
  case 1326:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* entes */
  case 1327:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* entoa */
  case 1328:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* entoe */
  case 1329:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* entra */
  case 1330:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* entre */
  case 1331:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* entro */
  case 1332:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* envia */
  case 1333:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* envie */
  case 1334:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* envio */
  case 1335:
    firstLetter = 'e';
    secondLetter = 'n';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* ereta */
  case 1336:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* ereto */
  case 1337:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ergam */
  case 1338:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ergas */
  case 1339:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ergue */
  case 1340:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* ergui */
  case 1341:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* erice */
  case 1342:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* erigi */
  case 1343:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* erija */
  case 1344:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* erijo */
  case 1345:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* ermos */
  case 1346:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* eroda */
  case 1347:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* erode */
  case 1348:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* erodi */
  case 1349:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* erodo */
  case 1350:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* errai */
  case 1351:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* erram */
  case 1352:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* errar */
  case 1353:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* erras */
  case 1354:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* errei */
  case 1355:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* errem */
  case 1356:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* erres */
  case 1357:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* erros */
  case 1358:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* errou */
  case 1359:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ervas */
  case 1360:
    firstLetter = 'e';
    secondLetter = 'r';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* escoa */
  case 1361:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* escoe */
  case 1362:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* escol */
  case 1363:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* espia */
  case 1364:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* espie */
  case 1365:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* espio */
  case 1366:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* esqui */
  case 1367:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* essas */
  case 1368:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* esses */
  case 1369:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* estai */
  case 1370:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* estar */
  case 1371:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* estas */
  case 1372:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* estes */
  case 1373:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* estio */
  case 1374:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* estou */
  case 1375:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* esvai */
  case 1376:
    firstLetter = 'e';
    secondLetter = 's';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* etano */
  case 1377:
    firstLetter = 'e';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* etapa */
  case 1378:
    firstLetter = 'e';
    secondLetter = 't';
    thirdLetter = 'a';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* eteno */
  case 1379:
    firstLetter = 'e';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* etilo */
  case 1380:
    firstLetter = 'e';
    secondLetter = 't';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* etnia */
  case 1381:
    firstLetter = 'e';
    secondLetter = 't';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* evada */
  case 1382:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* evade */
  case 1383:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* evadi */
  case 1384:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* evado */
  case 1385:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* evita */
  case 1386:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* evite */
  case 1387:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* evito */
  case 1388:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* evoca */
  case 1389:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* evoco */
  case 1390:
    firstLetter = 'e';
    secondLetter = 'v';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* exala */
  case 1391:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* exale */
  case 1392:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* exalo */
  case 1393:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* exame */
  case 1394:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* exara */
  case 1395:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* exare */
  case 1396:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* exaro */
  case 1397:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* exata */
  case 1398:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* exato */
  case 1399:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* exiba */
  case 1400:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* exibe */
  case 1401:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* exibi */
  case 1402:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'i';
    break;

  /* exibo */
  case 1403:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* exige */
  case 1404:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* exigi */
  case 1405:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* exija */
  case 1406:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* exijo */
  case 1407:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* exila */
  case 1408:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* exile */
  case 1409:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* exilo */
  case 1410:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* exima */
  case 1411:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* exime */
  case 1412:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* eximi */
  case 1413:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* eximo */
  case 1414:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* expia */
  case 1415:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* expie */
  case 1416:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* expio */
  case 1417:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* expor */
  case 1418:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* expus */
  case 1419:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* extra */
  case 1420:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* exuma */
  case 1421:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* exume */
  case 1422:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* exumo */
  case 1423:
    firstLetter = 'e';
    secondLetter = 'x';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* facas */
  case 1424:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* faces */
  case 1425:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* facho */
  case 1426:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* fadas */
  case 1427:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fados */
  case 1428:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* faina */
  case 1429:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* faixa */
  case 1430:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* falai */
  case 1431:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* falam */
  case 1432:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* falar */
  case 1433:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* falas */
  case 1434:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* falda */
  case 1435:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* falei */
  case 1436:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* falem */
  case 1437:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fales */
  case 1438:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* falha */
  case 1439:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* falhe */
  case 1440:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* falho */
  case 1441:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* falia */
  case 1442:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* falir */
  case 1443:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* falis */
  case 1444:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* faliu */
  case 1445:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* falou */
  case 1446:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* falsa */
  case 1447:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* falso */
  case 1448:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* falta */
  case 1449:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* falte */
  case 1450:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* falto */
  case 1451:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* famas */
  case 1452:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* farda */
  case 1453:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* fardo */
  case 1454:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* farei */
  case 1455:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* faria */
  case 1456:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* farol */
  case 1457:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* faros */
  case 1458:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* farpa */
  case 1459:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* farra */
  case 1460:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* farsa */
  case 1461:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* farta */
  case 1462:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* farte */
  case 1463:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* farto */
  case 1464:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* fases */
  case 1465:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fatal */
  case 1466:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* fatia */
  case 1467:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* fatie */
  case 1468:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* fatio */
  case 1469:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* fator */
  case 1470:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* fatos */
  case 1471:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fauna */
  case 1472:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* fauno */
  case 1473:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* favas */
  case 1474:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* favor */
  case 1475:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* favos */
  case 1476:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fazei */
  case 1477:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fazem */
  case 1478:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fazer */
  case 1479:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* fazes */
  case 1480:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fazia */
  case 1481:
    firstLetter = 'f';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* febre */
  case 1482:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* fecal */
  case 1483:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* fecha */
  case 1484:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* feche */
  case 1485:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* fecho */
  case 1486:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* fedam */
  case 1487:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fedas */
  case 1488:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fedei */
  case 1489:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fedem */
  case 1490:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* feder */
  case 1491:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* fedes */
  case 1492:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fedeu */
  case 1493:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* fedia */
  case 1494:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* fedor */
  case 1495:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* feias */
  case 1496:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* feios */
  case 1497:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* feira */
  case 1498:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* feita */
  case 1499:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* feito */
  case 1500:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* feixe */
  case 1501:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* feliz */
  case 1502:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* fenda */
  case 1503:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* fende */
  case 1504:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* fendi */
  case 1505:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* fendo */
  case 1506:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* feras */
  case 1507:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* feraz */
  case 1508:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* ferem */
  case 1509:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* feres */
  case 1510:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* feria */
  case 1511:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ferir */
  case 1512:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* feris */
  case 1513:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* feriu */
  case 1514:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* feroz */
  case 1515:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'z';
    break;

  /* ferra */
  case 1516:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ferre */
  case 1517:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* ferro */
  case 1518:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ferva */
  case 1519:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* ferve */
  case 1520:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* fervi */
  case 1521:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* fervo */
  case 1522:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* festa */
  case 1523:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* fetal */
  case 1524:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* fetos */
  case 1525:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* feudo */
  case 1526:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* fezes */
  case 1527:
    firstLetter = 'f';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fiado */
  case 1528:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* fiais */
  case 1529:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fiamo */
  case 1530:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* fiapo */
  case 1531:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* fiara */
  case 1532:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* fiava */
  case 1533:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* fibra */
  case 1534:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ficai */
  case 1535:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ficam */
  case 1536:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ficar */
  case 1537:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ficas */
  case 1538:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ficha */
  case 1539:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* fiche */
  case 1540:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* ficho */
  case 1541:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* ficou */
  case 1542:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* fieis */
  case 1543:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fiemo */
  case 1544:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* figas */
  case 1545:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* figos */
  case 1546:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* filai */
  case 1547:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* filam */
  case 1548:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* filar */
  case 1549:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* filas */
  case 1550:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* filei */
  case 1551:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* filem */
  case 1552:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* files */
  case 1553:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* filha */
  case 1554:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* filho */
  case 1555:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* filia */
  case 1556:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* filie */
  case 1557:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* filio */
  case 1558:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* filma */
  case 1559:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* filme */
  case 1560:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* filmo */
  case 1561:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* filou */
  case 1562:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* final */
  case 1563:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* finas */
  case 1564:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* finca */
  case 1565:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* finco */
  case 1566:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* finda */
  case 1567:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* finde */
  case 1568:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* findo */
  case 1569:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* finge */
  case 1570:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* fingi */
  case 1571:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* finja */
  case 1572:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* finjo */
  case 1573:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* finos */
  case 1574:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* finta */
  case 1575:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* finte */
  case 1576:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* finto */
  case 1577:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* fique */
  case 1578:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* firam */
  case 1579:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* firas */
  case 1580:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* firma */
  case 1581:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* firme */
  case 1582:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* firmo */
  case 1583:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* fisco */
  case 1584:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* fisga */
  case 1585:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* fisgo */
  case 1586:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* fitai */
  case 1587:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* fitam */
  case 1588:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fitar */
  case 1589:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* fitas */
  case 1590:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fitei */
  case 1591:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fitem */
  case 1592:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fites */
  case 1593:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fitou */
  case 1594:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* fixai */
  case 1595:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* fixam */
  case 1596:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fixar */
  case 1597:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* fixas */
  case 1598:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fixei */
  case 1599:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fixem */
  case 1600:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fixes */
  case 1601:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fixos */
  case 1602:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fixou */
  case 1603:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* fizer */
  case 1604:
    firstLetter = 'f';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* flavo */
  case 1605:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* floco */
  case 1606:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* flora */
  case 1607:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* flori */
  case 1608:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* fluam */
  case 1609:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fluas */
  case 1610:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fluem */
  case 1611:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fluir */
  case 1612:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* fluis */
  case 1613:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fluiu */
  case 1614:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* fluxo */
  case 1615:
    firstLetter = 'f';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* fobia */
  case 1616:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* focai */
  case 1617:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* focam */
  case 1618:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* focar */
  case 1619:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* focas */
  case 1620:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* focos */
  case 1621:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* focou */
  case 1622:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* fofas */
  case 1623:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fofos */
  case 1624:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fogem */
  case 1625:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* foges */
  case 1626:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fogos */
  case 1627:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* foice */
  case 1628:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* foles */
  case 1629:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* folga */
  case 1630:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* folgo */
  case 1631:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* folha */
  case 1632:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* folia */
  case 1633:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* fomes */
  case 1634:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fomos */
  case 1635:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fones */
  case 1636:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fonte */
  case 1637:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* foque */
  case 1638:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* foram */
  case 1639:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* foras */
  case 1640:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* forca */
  case 1641:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* force */
  case 1642:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* forem */
  case 1643:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fores */
  case 1644:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* forja */
  case 1645:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* forje */
  case 1646:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* forjo */
  case 1647:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* forma */
  case 1648:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* forme */
  case 1649:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* formo */
  case 1650:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* forno */
  case 1651:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* foros */
  case 1652:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* forra */
  case 1653:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* forre */
  case 1654:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* forro */
  case 1655:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* forte */
  case 1656:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* fosca */
  case 1657:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* fosco */
  case 1658:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* fossa */
  case 1659:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* fosse */
  case 1660:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* fosso */
  case 1661:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* foste */
  case 1662:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* fotos */
  case 1663:
    firstLetter = 'f';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fraca */
  case 1664:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* fraco */
  case 1665:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* frade */
  case 1666:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* fraga */
  case 1667:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* frase */
  case 1668:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* freai */
  case 1669:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* frear */
  case 1670:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* freei */
  case 1671:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* freia */
  case 1672:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* freie */
  case 1673:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* freio */
  case 1674:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* freme */
  case 1675:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* fremi */
  case 1676:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* freou */
  case 1677:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* fresa */
  case 1678:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* frese */
  case 1679:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* freso */
  case 1680:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* freta */
  case 1681:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* frete */
  case 1682:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* freto */
  case 1683:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* frevo */
  case 1684:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* frias */
  case 1685:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* frigi */
  case 1686:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* frija */
  case 1687:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* frijo */
  case 1688:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* frios */
  case 1689:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* frisa */
  case 1690:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* frise */
  case 1691:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* friso */
  case 1692:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* frita */
  case 1693:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* frite */
  case 1694:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* frito */
  case 1695:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* frota */
  case 1696:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* fruam */
  case 1697:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fruas */
  case 1698:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fruem */
  case 1699:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fruir */
  case 1700:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* fruis */
  case 1701:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fruiu */
  case 1702:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* fruta */
  case 1703:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* fruto */
  case 1704:
    firstLetter = 'f';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* fucei */
  case 1705:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fucem */
  case 1706:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fuces */
  case 1707:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fugas */
  case 1708:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fugaz */
  case 1709:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* fugia */
  case 1710:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* fugir */
  case 1711:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* fugis */
  case 1712:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fugiu */
  case 1713:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* fujam */
  case 1714:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fujas */
  case 1715:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fujem */
  case 1716:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fujes */
  case 1717:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fujia */
  case 1718:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* fujir */
  case 1719:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* fujis */
  case 1720:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* fujiu */
  case 1721:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* fulge */
  case 1722:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* fulgi */
  case 1723:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* fumai */
  case 1724:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* fumam */
  case 1725:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* fumar */
  case 1726:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* fumas */
  case 1727:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* fumei */
  case 1728:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* fumem */
  case 1729:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fumes */
  case 1730:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* fumou */
  case 1731:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* funda */
  case 1732:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* funde */
  case 1733:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* fundi */
  case 1734:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* fundo */
  case 1735:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* funga */
  case 1736:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* fungo */
  case 1737:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* funil */
  case 1738:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* funis */
  case 1739:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* furai */
  case 1740:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* furam */
  case 1741:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* furar */
  case 1742:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* furas */
  case 1743:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* furei */
  case 1744:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* furem */
  case 1745:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* fures */
  case 1746:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* furna */
  case 1747:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* furor */
  case 1748:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* furos */
  case 1749:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* furou */
  case 1750:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* furta */
  case 1751:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* furte */
  case 1752:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* furto */
  case 1753:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* fusco */
  case 1754:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* fusos */
  case 1755:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* fuzil */
  case 1756:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* fuzis */
  case 1757:
    firstLetter = 'f';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* gabai */
  case 1758:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* gabam */
  case 1759:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gabar */
  case 1760:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* gabas */
  case 1761:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gabei */
  case 1762:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gabem */
  case 1763:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* gabes */
  case 1764:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gabou */
  case 1765:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* gados */
  case 1766:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gagas */
  case 1767:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gagos */
  case 1768:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gaita */
  case 1769:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* gajas */
  case 1770:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gajos */
  case 1771:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* galas */
  case 1772:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* galga */
  case 1773:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* galgo */
  case 1774:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* galho */
  case 1775:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* galos */
  case 1776:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gamos */
  case 1777:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ganem */
  case 1778:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ganes */
  case 1779:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ganha */
  case 1780:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* ganhe */
  case 1781:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* ganho */
  case 1782:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* gania */
  case 1783:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ganir */
  case 1784:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* ganis */
  case 1785:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ganiu */
  case 1786:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* ganso */
  case 1787:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* garbo */
  case 1788:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* garfa */
  case 1789:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* garfe */
  case 1790:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* garfo */
  case 1791:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* garis */
  case 1792:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* garoa */
  case 1793:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* garoe */
  case 1794:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* garra */
  case 1795:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* gases */
  case 1796:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gasta */
  case 1797:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* gaste */
  case 1798:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* gasto */
  case 1799:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* gatas */
  case 1800:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gatos */
  case 1801:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gazua */
  case 1802:
    firstLetter = 'g';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* geada */
  case 1803:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* geado */
  case 1804:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* geais */
  case 1805:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* geamo */
  case 1806:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* geara */
  case 1807:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* geava */
  case 1808:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* geeis */
  case 1809:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* geemo */
  case 1810:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* geiam */
  case 1811:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* geias */
  case 1812:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* geiem */
  case 1813:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* geies */
  case 1814:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gelai */
  case 1815:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* gelam */
  case 1816:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gelar */
  case 1817:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* gelas */
  case 1818:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gelei */
  case 1819:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gelem */
  case 1820:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* geles */
  case 1821:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gelos */
  case 1822:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gelou */
  case 1823:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* gemam */
  case 1824:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gemas */
  case 1825:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gemei */
  case 1826:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gemem */
  case 1827:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* gemer */
  case 1828:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* gemes */
  case 1829:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gemeu */
  case 1830:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* gemia */
  case 1831:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* genes */
  case 1832:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* genro */
  case 1833:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* gente */
  case 1834:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* gerai */
  case 1835:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* geral */
  case 1836:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* geram */
  case 1837:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gerar */
  case 1838:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* geras */
  case 1839:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gerei */
  case 1840:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gerem */
  case 1841:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* geres */
  case 1842:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* geria */
  case 1843:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* gerir */
  case 1844:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* geris */
  case 1845:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* geriu */
  case 1846:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* germe */
  case 1847:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* gerou */
  case 1848:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* gesso */
  case 1849:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* gesta */
  case 1850:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* gesto */
  case 1851:
    firstLetter = 'g';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ginga */
  case 1852:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* gingo */
  case 1853:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* girai */
  case 1854:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* giram */
  case 1855:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* girar */
  case 1856:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* giras */
  case 1857:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* girei */
  case 1858:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* girem */
  case 1859:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* gires */
  case 1860:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* giros */
  case 1861:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* girou */
  case 1862:
    firstLetter = 'g';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* gleba */
  case 1863:
    firstLetter = 'g';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* globo */
  case 1864:
    firstLetter = 'g';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* glosa */
  case 1865:
    firstLetter = 'g';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* glose */
  case 1866:
    firstLetter = 'g';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* gloso */
  case 1867:
    firstLetter = 'g';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* gnomo */
  case 1868:
    firstLetter = 'g';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* goela */
  case 1869:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* golas */
  case 1870:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* goles */
  case 1871:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* golfo */
  case 1872:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* golpe */
  case 1873:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* gomas */
  case 1874:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gomes */
  case 1875:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gomos */
  case 1876:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gongo */
  case 1877:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* gonzo */
  case 1878:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* gorai */
  case 1879:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* goram */
  case 1880:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gorar */
  case 1881:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* goras */
  case 1882:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gorda */
  case 1883:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* gordo */
  case 1884:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* gorei */
  case 1885:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gorem */
  case 1886:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* gores */
  case 1887:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gorou */
  case 1888:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* gorro */
  case 1889:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* gosma */
  case 1890:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* gosta */
  case 1891:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* goste */
  case 1892:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* gosto */
  case 1893:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* gotas */
  case 1894:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gozai */
  case 1895:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* gozam */
  case 1896:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* gozar */
  case 1897:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* gozas */
  case 1898:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* gozei */
  case 1899:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* gozem */
  case 1900:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* gozes */
  case 1901:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* gozos */
  case 1902:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* gozou */
  case 1903:
    firstLetter = 'g';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* grade */
  case 1904:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* grafa */
  case 1905:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* grafe */
  case 1906:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* grafo */
  case 1907:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* grama */
  case 1908:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* grana */
  case 1909:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* grata */
  case 1910:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* grato */
  case 1911:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* graus */
  case 1912:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* grava */
  case 1913:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* grave */
  case 1914:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* gravo */
  case 1915:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* graxa */
  case 1916:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'a';
    break;

  /* graxo */
  case 1917:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* grega */
  case 1918:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* grego */
  case 1919:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* greve */
  case 1920:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* grifa */
  case 1921:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* grife */
  case 1922:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'e';
    break;

  /* grifo */
  case 1923:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'f';
    fifthLetter = 'o';
    break;

  /* grila */
  case 1924:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* grile */
  case 1925:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* grilo */
  case 1926:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* gripe */
  case 1927:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* grita */
  case 1928:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* grite */
  case 1929:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* grito */
  case 1930:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* gruda */
  case 1931:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* grude */
  case 1932:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* grudo */
  case 1933:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* grupo */
  case 1934:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* gruta */
  case 1935:
    firstLetter = 'g';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* gueto */
  case 1936:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* guiai */
  case 1937:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* guiam */
  case 1938:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* guiar */
  case 1939:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* guias */
  case 1940:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* guiei */
  case 1941:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* guiem */
  case 1942:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* guies */
  case 1943:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* guiou */
  case 1944:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* guisa */
  case 1945:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* guizo */
  case 1946:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* gumes */
  case 1947:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* guria */
  case 1948:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* guris */
  case 1949:
    firstLetter = 'g';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* hajam */
  case 1950:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* hajas */
  case 1951:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* halos */
  case 1952:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* haras */
  case 1953:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* harpa */
  case 1954:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* haste */
  case 1955:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* haure */
  case 1956:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* hauri */
  case 1957:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* havei */
  case 1958:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* haver */
  case 1959:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* havia */
  case 1960:
    firstLetter = 'h';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* heras */
  case 1961:
    firstLetter = 'h';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* herda */
  case 1962:
    firstLetter = 'h';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* herde */
  case 1963:
    firstLetter = 'h';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* herdo */
  case 1964:
    firstLetter = 'h';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* hiato */
  case 1965:
    firstLetter = 'h';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* hiena */
  case 1966:
    firstLetter = 'h';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* hindu */
  case 1967:
    firstLetter = 'h';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'u';
    break;

  /* hinos */
  case 1968:
    firstLetter = 'h';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* homem */
  case 1969:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* honra */
  case 1970:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* honre */
  case 1971:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* honro */
  case 1972:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* horas */
  case 1973:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* horda */
  case 1974:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* horta */
  case 1975:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* horto */
  case 1976:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* hotel */
  case 1977:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* houve */
  case 1978:
    firstLetter = 'h';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* hulha */
  case 1979:
    firstLetter = 'h';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* humor */
  case 1980:
    firstLetter = 'h';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* hunos */
  case 1981:
    firstLetter = 'h';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* hurra */
  case 1982:
    firstLetter = 'h';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* iates */
  case 1983:
    firstLetter = 'i';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ibero */
  case 1984:
    firstLetter = 'i';
    secondLetter = 'b';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* iceis */
  case 1985:
    firstLetter = 'i';
    secondLetter = 'c';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* icemo */
  case 1986:
    firstLetter = 'i';
    secondLetter = 'c';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* idade */
  case 1987:
    firstLetter = 'i';
    secondLetter = 'd';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* ideal */
  case 1988:
    firstLetter = 'i';
    secondLetter = 'd';
    thirdLetter = 'e';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* idosa */
  case 1989:
    firstLetter = 'i';
    secondLetter = 'd';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* idoso */
  case 1990:
    firstLetter = 'i';
    secondLetter = 'd';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* ienes */
  case 1991:
    firstLetter = 'i';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* igual */
  case 1992:
    firstLetter = 'i';
    secondLetter = 'g';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* ilesa */
  case 1993:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* ileso */
  case 1994:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* ilhai */
  case 1995:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ilham */
  case 1996:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ilhar */
  case 1997:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ilhas */
  case 1998:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ilhei */
  case 1999:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ilhem */
  case 2000:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ilhes */
  case 2001:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ilhou */
  case 2002:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* iluda */
  case 2003:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* ilude */
  case 2004:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* iludi */
  case 2005:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* iludo */
  case 2006:
    firstLetter = 'i';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* imita */
  case 2007:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* imite */
  case 2008:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* imito */
  case 2009:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* imola */
  case 2010:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* imole */
  case 2011:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* imolo */
  case 2012:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* impor */
  case 2013:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* impus */
  case 2014:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* imune */
  case 2015:
    firstLetter = 'i';
    secondLetter = 'm';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* inala */
  case 2016:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* inale */
  case 2017:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* inalo */
  case 2018:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* inata */
  case 2019:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* inato */
  case 2020:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* incas */
  case 2021:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* incha */
  case 2022:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* inche */
  case 2023:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* incho */
  case 2024:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* incoa */
  case 2025:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* incoe */
  case 2026:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* induz */
  case 2027:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'u';
    fifthLetter = 'z';
    break;

  /* infla */
  case 2028:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* infle */
  case 2029:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* inflo */
  case 2030:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* infra */
  case 2031:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* iniba */
  case 2032:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* inibe */
  case 2033:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* inibo */
  case 2034:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* inova */
  case 2035:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* inove */
  case 2036:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* inovo */
  case 2037:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* insta */
  case 2038:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* inste */
  case 2039:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* insto */
  case 2040:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* inter */
  case 2041:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* intua */
  case 2042:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* intui */
  case 2043:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* intuo */
  case 2044:
    firstLetter = 'i';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* irada */
  case 2045:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* irado */
  case 2046:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* irdes */
  case 2047:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ireis */
  case 2048:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* iremo */
  case 2049:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* iriam */
  case 2050:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* irias */
  case 2051:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* irmos */
  case 2052:
    firstLetter = 'i';
    secondLetter = 'r';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* iscas */
  case 2053:
    firstLetter = 'i';
    secondLetter = 's';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* isola */
  case 2054:
    firstLetter = 'i';
    secondLetter = 's';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* isole */
  case 2055:
    firstLetter = 'i';
    secondLetter = 's';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* isolo */
  case 2056:
    firstLetter = 'i';
    secondLetter = 's';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* istmo */
  case 2057:
    firstLetter = 'i';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* itera */
  case 2058:
    firstLetter = 'i';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* itere */
  case 2059:
    firstLetter = 'i';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* itero */
  case 2060:
    firstLetter = 'i';
    secondLetter = 't';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* jacas */
  case 2061:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* janta */
  case 2062:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* jante */
  case 2063:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* janto */
  case 2064:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* jarda */
  case 2065:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* jarra */
  case 2066:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* jarro */
  case 2067:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* jatos */
  case 2068:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* jaula */
  case 2069:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* jazam */
  case 2070:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* jazas */
  case 2071:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* jazei */
  case 2072:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* jazem */
  case 2073:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* jazer */
  case 2074:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* jazes */
  case 2075:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* jazeu */
  case 2076:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* jazia */
  case 2077:
    firstLetter = 'j';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* jecas */
  case 2078:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* jegue */
  case 2079:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* jeito */
  case 2080:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* jejua */
  case 2081:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* jejue */
  case 2082:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* jejum */
  case 2083:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'u';
    fifthLetter = 'm';
    break;

  /* jejuo */
  case 2084:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* jesus */
  case 2085:
    firstLetter = 'j';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* jinga */
  case 2086:
    firstLetter = 'j';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* joana */
  case 2087:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* jogai */
  case 2088:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* jogam */
  case 2089:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* jogar */
  case 2090:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* jogas */
  case 2091:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* jogos */
  case 2092:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* jogou */
  case 2093:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* jogue */
  case 2094:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* jorge */
  case 2095:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* jorra */
  case 2096:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* jorre */
  case 2097:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* jorro */
  case 2098:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* jovem */
  case 2099:
    firstLetter = 'j';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* jubas */
  case 2100:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* judas */
  case 2101:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* judeu */
  case 2102:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* judia */
  case 2103:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* judie */
  case 2104:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* judio */
  case 2105:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* julga */
  case 2106:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* julgo */
  case 2107:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* julho */
  case 2108:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* junco */
  case 2109:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* junho */
  case 2110:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* junta */
  case 2111:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* junte */
  case 2112:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* junto */
  case 2113:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* jurai */
  case 2114:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* juram */
  case 2115:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* jurar */
  case 2116:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* juras */
  case 2117:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* jurei */
  case 2118:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* jurem */
  case 2119:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* jures */
  case 2120:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* juros */
  case 2121:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* jurou */
  case 2122:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* justa */
  case 2123:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* justo */
  case 2124:
    firstLetter = 'j';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* labor */
  case 2125:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* lacei */
  case 2126:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lacem */
  case 2127:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* laces */
  case 2128:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lacra */
  case 2129:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* lacre */
  case 2130:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* lacro */
  case 2131:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lados */
  case 2132:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ladra */
  case 2133:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ladre */
  case 2134:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* ladro */
  case 2135:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lagar */
  case 2136:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lagoa */
  case 2137:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* lagos */
  case 2138:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* laica */
  case 2139:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* laico */
  case 2140:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* lajes */
  case 2141:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lamba */
  case 2142:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* lambe */
  case 2143:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* lambi */
  case 2144:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'i';
    break;

  /* lambo */
  case 2145:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* lance */
  case 2146:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* lapso */
  case 2147:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* lares */
  case 2148:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* larga */
  case 2149:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* largo */
  case 2150:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* larva */
  case 2151:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* lasca */
  case 2152:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* lasco */
  case 2153:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* laser */
  case 2154:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* latas */
  case 2155:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* latem */
  case 2156:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* lates */
  case 2157:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* latia */
  case 2158:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* latim */
  case 2159:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* latir */
  case 2160:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* latis */
  case 2161:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* latiu */
  case 2162:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* lauda */
  case 2163:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* laudo */
  case 2164:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* lavai */
  case 2165:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lavam */
  case 2166:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lavar */
  case 2167:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lavas */
  case 2168:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lavei */
  case 2169:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lavem */
  case 2170:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* laves */
  case 2171:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lavou */
  case 2172:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* lavra */
  case 2173:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* lavre */
  case 2174:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* lavro */
  case 2175:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lazer */
  case 2176:
    firstLetter = 'l';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* leais */
  case 2177:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* lebre */
  case 2178:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* ledes */
  case 2179:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* legai */
  case 2180:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* legal */
  case 2181:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* legam */
  case 2182:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* legar */
  case 2183:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* legas */
  case 2184:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* legou */
  case 2185:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* legue */
  case 2186:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* leiam */
  case 2187:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* leias */
  case 2188:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* leiga */
  case 2189:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* leigo */
  case 2190:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* leite */
  case 2191:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* leito */
  case 2192:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* lemas */
  case 2193:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lemes */
  case 2194:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lemos */
  case 2195:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* lenda */
  case 2196:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* lendo */
  case 2197:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* lenga */
  case 2198:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* lenha */
  case 2199:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* lenho */
  case 2200:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* lenta */
  case 2201:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* lente */
  case 2202:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* lento */
  case 2203:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* leoas */
  case 2204:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lepra */
  case 2205:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* leque */
  case 2206:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* leram */
  case 2207:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* leras */
  case 2208:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lerda */
  case 2209:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* lerdo */
  case 2210:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* lerei */
  case 2211:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lerem */
  case 2212:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* leres */
  case 2213:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* leria */
  case 2214:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* lermo */
  case 2215:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* lesai */
  case 2216:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lesam */
  case 2217:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lesar */
  case 2218:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lesas */
  case 2219:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lesei */
  case 2220:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lesem */
  case 2221:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* leses */
  case 2222:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lesma */
  case 2223:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* lesou */
  case 2224:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* lesse */
  case 2225:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* leste */
  case 2226:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* letra */
  case 2227:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* levai */
  case 2228:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* levam */
  case 2229:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* levar */
  case 2230:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* levas */
  case 2231:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* levei */
  case 2232:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* levem */
  case 2233:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* leves */
  case 2234:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* levou */
  case 2235:
    firstLetter = 'l';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* lhama */
  case 2236:
    firstLetter = 'l';
    secondLetter = 'h';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* liame */
  case 2237:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* libra */
  case 2238:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* liceu */
  case 2239:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* licor */
  case 2240:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* lidai */
  case 2241:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lidam */
  case 2242:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lidar */
  case 2243:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lidas */
  case 2244:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lidei */
  case 2245:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lidem */
  case 2246:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* lides */
  case 2247:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lidos */
  case 2248:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* lidou */
  case 2249:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ligai */
  case 2250:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ligam */
  case 2251:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ligar */
  case 2252:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ligas */
  case 2253:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ligou */
  case 2254:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ligue */
  case 2255:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* limai */
  case 2256:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* limam */
  case 2257:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* limar */
  case 2258:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* limas */
  case 2259:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* limbo */
  case 2260:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* limei */
  case 2261:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* limem */
  case 2262:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* limes */
  case 2263:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* limou */
  case 2264:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* limpa */
  case 2265:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* limpe */
  case 2266:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* limpo */
  case 2267:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* lince */
  case 2268:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* linda */
  case 2269:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* lindo */
  case 2270:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* linfa */
  case 2271:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* linha */
  case 2272:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* linho */
  case 2273:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* liras */
  case 2274:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lisas */
  case 2275:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lisos */
  case 2276:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* lista */
  case 2277:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* liste */
  case 2278:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* listo */
  case 2279:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* litro */
  case 2280:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* livra */
  case 2281:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* livre */
  case 2282:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* livro */
  case 2283:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lixai */
  case 2284:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lixam */
  case 2285:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lixar */
  case 2286:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lixas */
  case 2287:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lixei */
  case 2288:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lixem */
  case 2289:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* lixes */
  case 2290:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lixou */
  case 2291:
    firstLetter = 'l';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* lobas */
  case 2292:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lobos */
  case 2293:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* locai */
  case 2294:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* local */
  case 2295:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* locam */
  case 2296:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* locar */
  case 2297:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* locas */
  case 2298:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* locou */
  case 2299:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* logra */
  case 2300:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* logre */
  case 2301:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* logro */
  case 2302:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* loira */
  case 2303:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* loiro */
  case 2304:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lojas */
  case 2305:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lombo */
  case 2306:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* lonas */
  case 2307:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* longa */
  case 2308:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* longe */
  case 2309:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* longo */
  case 2310:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* lopes */
  case 2311:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* loque */
  case 2312:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* lorde */
  case 2313:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* lotai */
  case 2314:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lotam */
  case 2315:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lotar */
  case 2316:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lotas */
  case 2317:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lotei */
  case 2318:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lotem */
  case 2319:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* lotes */
  case 2320:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lotou */
  case 2321:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* louca */
  case 2322:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* louco */
  case 2323:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* loura */
  case 2324:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* louro */
  case 2325:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lousa */
  case 2326:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* louva */
  case 2327:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* louve */
  case 2328:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* louvo */
  case 2329:
    firstLetter = 'l';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* lucas */
  case 2330:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lucra */
  case 2331:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* lucre */
  case 2332:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* lucro */
  case 2333:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* lugar */
  case 2334:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lulas */
  case 2335:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lunar */
  case 2336:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lupas */
  case 2337:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lusas */
  case 2338:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lusos */
  case 2339:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* lutai */
  case 2340:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* lutam */
  case 2341:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* lutar */
  case 2342:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* lutas */
  case 2343:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* lutei */
  case 2344:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* lutem */
  case 2345:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* lutes */
  case 2346:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* lutou */
  case 2347:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* luvas */
  case 2348:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* luxos */
  case 2349:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* luzam */
  case 2350:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* luzas */
  case 2351:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* luzem */
  case 2352:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* luzes */
  case 2353:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* luzia */
  case 2354:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* luzir */
  case 2355:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* luzis */
  case 2356:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* luziu */
  case 2357:
    firstLetter = 'l';
    secondLetter = 'u';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* macas */
  case 2358:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* macho */
  case 2359:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* macia */
  case 2360:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* macio */
  case 2361:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* macro */
  case 2362:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* magia */
  case 2363:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* magma */
  case 2364:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* magna */
  case 2365:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* magno */
  case 2366:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* magoa */
  case 2367:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* magoe */
  case 2368:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* magos */
  case 2369:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* magra */
  case 2370:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* magro */
  case 2371:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* maias */
  case 2372:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* maior */
  case 2373:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* major */
  case 2374:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* malas */
  case 2375:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* males */
  case 2376:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* malha */
  case 2377:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* malhe */
  case 2378:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* malho */
  case 2379:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* malta */
  case 2380:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* mamai */
  case 2381:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mamam */
  case 2382:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mamar */
  case 2383:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* mamas */
  case 2384:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mamei */
  case 2385:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mamem */
  case 2386:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mames */
  case 2387:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mamou */
  case 2388:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* manas */
  case 2389:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* manca */
  case 2390:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* manco */
  case 2391:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* manda */
  case 2392:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* mande */
  case 2393:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* mando */
  case 2394:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* manga */
  case 2395:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* manha */
  case 2396:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* mania */
  case 2397:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* manja */
  case 2398:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* manje */
  case 2399:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* manjo */
  case 2400:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* manos */
  case 2401:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mansa */
  case 2402:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* manso */
  case 2403:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* manta */
  case 2404:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* manto */
  case 2405:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* mapas */
  case 2406:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* marca */
  case 2407:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* marco */
  case 2408:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* mares */
  case 2409:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* maria */
  case 2410:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* marra */
  case 2411:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* marta */
  case 2412:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* masca */
  case 2413:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* masco */
  case 2414:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* massa */
  case 2415:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* matai */
  case 2416:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* matam */
  case 2417:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* matar */
  case 2418:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* matas */
  case 2419:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* matei */
  case 2420:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* matem */
  case 2421:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mates */
  case 2422:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* matiz */
  case 2423:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* matos */
  case 2424:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* matou */
  case 2425:
    firstLetter = 'm';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* meada */
  case 2426:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* mecha */
  case 2427:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* medem */
  case 2428:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* medes */
  case 2429:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* media */
  case 2430:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* medir */
  case 2431:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* medis */
  case 2432:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* mediu */
  case 2433:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* medos */
  case 2434:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* medra */
  case 2435:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* medre */
  case 2436:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* medro */
  case 2437:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* meias */
  case 2438:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* meiga */
  case 2439:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* meigo */
  case 2440:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* meios */
  case 2441:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* melai */
  case 2442:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* melam */
  case 2443:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* melar */
  case 2444:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* melas */
  case 2445:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* melei */
  case 2446:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* melem */
  case 2447:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* meles */
  case 2448:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* melou */
  case 2449:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* melro */
  case 2450:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* menir */
  case 2451:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* menor */
  case 2452:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* menos */
  case 2453:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* menta */
  case 2454:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* mente */
  case 2455:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* menti */
  case 2456:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* menus */
  case 2457:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* meras */
  case 2458:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* merda */
  case 2459:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* meros */
  case 2460:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mesas */
  case 2461:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* meses */
  case 2462:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mesma */
  case 2463:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* mesmo */
  case 2464:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* metal */
  case 2465:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* metam */
  case 2466:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* metas */
  case 2467:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* metei */
  case 2468:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* metem */
  case 2469:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* meter */
  case 2470:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* metes */
  case 2471:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* meteu */
  case 2472:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* metia */
  case 2473:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* metro */
  case 2474:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* mexam */
  case 2475:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mexas */
  case 2476:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mexei */
  case 2477:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mexem */
  case 2478:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mexer */
  case 2479:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* mexes */
  case 2480:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mexeu */
  case 2481:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* mexia */
  case 2482:
    firstLetter = 'm';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* miado */
  case 2483:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* miais */
  case 2484:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* miamo */
  case 2485:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* miara */
  case 2486:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* miava */
  case 2487:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* micos */
  case 2488:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* micro */
  case 2489:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* mieis */
  case 2490:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* miemo */
  case 2491:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* migra */
  case 2492:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* migre */
  case 2493:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* migro */
  case 2494:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* mijai */
  case 2495:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mijam */
  case 2496:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mijar */
  case 2497:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* mijas */
  case 2498:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mijei */
  case 2499:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mijem */
  case 2500:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mijes */
  case 2501:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mijou */
  case 2502:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* milha */
  case 2503:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* milho */
  case 2504:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* mimai */
  case 2505:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mimam */
  case 2506:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mimar */
  case 2507:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* mimas */
  case 2508:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mimei */
  case 2509:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mimem */
  case 2510:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mimes */
  case 2511:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mimos */
  case 2512:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mimou */
  case 2513:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* minai */
  case 2514:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* minam */
  case 2515:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* minar */
  case 2516:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* minas */
  case 2517:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* minei */
  case 2518:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* minem */
  case 2519:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mines */
  case 2520:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* minha */
  case 2521:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* minis */
  case 2522:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* minou */
  case 2523:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* minta */
  case 2524:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* minto */
  case 2525:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* miolo */
  case 2526:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* mirai */
  case 2527:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* miram */
  case 2528:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mirar */
  case 2529:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* miras */
  case 2530:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mirei */
  case 2531:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mirem */
  case 2532:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mires */
  case 2533:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mirou */
  case 2534:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* mirra */
  case 2535:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* missa */
  case 2536:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* mista */
  case 2537:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* misto */
  case 2538:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* mitos */
  case 2539:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mitra */
  case 2540:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* mixos */
  case 2541:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mixto */
  case 2542:
    firstLetter = 'm';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* moais */
  case 2543:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* moamo */
  case 2544:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* modas */
  case 2545:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* modem */
  case 2546:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* modos */
  case 2547:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* moeda */
  case 2548:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* moeis */
  case 2549:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* moela */
  case 2550:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* moemo */
  case 2551:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* moera */
  case 2552:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* mofai */
  case 2553:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mofam */
  case 2554:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mofar */
  case 2555:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* mofas */
  case 2556:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mofei */
  case 2557:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mofem */
  case 2558:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mofes */
  case 2559:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mofou */
  case 2560:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* mogem */
  case 2561:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* moges */
  case 2562:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mogno */
  case 2563:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* mogol */
  case 2564:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'l';
    break;

  /* moita */
  case 2565:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* molar */
  case 2566:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* molas */
  case 2567:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* molda */
  case 2568:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* molde */
  case 2569:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* moldo */
  case 2570:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* moles */
  case 2571:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* molha */
  case 2572:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* molhe */
  case 2573:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* molho */
  case 2574:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* momos */
  case 2575:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* monge */
  case 2576:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* monja */
  case 2577:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* monta */
  case 2578:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* monte */
  case 2579:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* monto */
  case 2580:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* morai */
  case 2581:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* moral */
  case 2582:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* moram */
  case 2583:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* morar */
  case 2584:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* moras */
  case 2585:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* morda */
  case 2586:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* morde */
  case 2587:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* mordi */
  case 2588:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* mordo */
  case 2589:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* morei */
  case 2590:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* morem */
  case 2591:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mores */
  case 2592:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* morna */
  case 2593:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* morno */
  case 2594:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* morou */
  case 2595:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* morra */
  case 2596:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* morre */
  case 2597:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* morri */
  case 2598:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* morro */
  case 2599:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* morsa */
  case 2600:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* morse */
  case 2601:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* morta */
  case 2602:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* morte */
  case 2603:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* morto */
  case 2604:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* mosca */
  case 2605:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* motel */
  case 2606:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* motor */
  case 2607:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* motos */
  case 2608:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* moura */
  case 2609:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* mouro */
  case 2610:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* movam */
  case 2611:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* movas */
  case 2612:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* movei */
  case 2613:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* movem */
  case 2614:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mover */
  case 2615:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* moves */
  case 2616:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* moveu */
  case 2617:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* movia */
  case 2618:
    firstLetter = 'm';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* mucos */
  case 2619:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mudai */
  case 2620:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mudam */
  case 2621:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mudar */
  case 2622:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* mudas */
  case 2623:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mudei */
  case 2624:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* mudem */
  case 2625:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mudes */
  case 2626:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* mudez */
  case 2627:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'z';
    break;

  /* mudos */
  case 2628:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* mudou */
  case 2629:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* mugia */
  case 2630:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* mugir */
  case 2631:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* mugis */
  case 2632:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* mugiu */
  case 2633:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* muita */
  case 2634:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* muito */
  case 2635:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* mujam */
  case 2636:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* mujas */
  case 2637:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* mulas */
  case 2638:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* multa */
  case 2639:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* multe */
  case 2640:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* multi */
  case 2641:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* multo */
  case 2642:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* mundo */
  case 2643:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* munem */
  case 2644:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* munes */
  case 2645:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* munia */
  case 2646:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* munir */
  case 2647:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* munis */
  case 2648:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* muniu */
  case 2649:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* murai */
  case 2650:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* mural */
  case 2651:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* muram */
  case 2652:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* murar */
  case 2653:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* muras */
  case 2654:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* murei */
  case 2655:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* murem */
  case 2656:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* mures */
  case 2657:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* muros */
  case 2658:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* murou */
  case 2659:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* murro */
  case 2660:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* musas */
  case 2661:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* musca */
  case 2662:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* musco */
  case 2663:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* museu */
  case 2664:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* musgo */
  case 2665:
    firstLetter = 'm';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* nabla */
  case 2666:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* nabos */
  case 2667:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nacos */
  case 2668:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nadai */
  case 2669:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* nadam */
  case 2670:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* nadar */
  case 2671:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* nadas */
  case 2672:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* nadei */
  case 2673:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* nadem */
  case 2674:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* nades */
  case 2675:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nadou */
  case 2676:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* nafta */
  case 2677:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* naipe */
  case 2678:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* nanai */
  case 2679:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* nanam */
  case 2680:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* nanar */
  case 2681:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* nanas */
  case 2682:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* nanei */
  case 2683:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* nanem */
  case 2684:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* nanes */
  case 2685:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nanou */
  case 2686:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* nardo */
  case 2687:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* nariz */
  case 2688:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* narra */
  case 2689:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* narre */
  case 2690:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* narro */
  case 2691:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* nasal */
  case 2692:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* nasce */
  case 2693:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* nasci */
  case 2694:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'i';
    break;

  /* natal */
  case 2695:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* natas */
  case 2696:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* natos */
  case 2697:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nauta */
  case 2698:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* naval */
  case 2699:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* naves */
  case 2700:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* navio */
  case 2701:
    firstLetter = 'n';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* negai */
  case 2702:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* negam */
  case 2703:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* negar */
  case 2704:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* negas */
  case 2705:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* negou */
  case 2706:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* negra */
  case 2707:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* negro */
  case 2708:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* negue */
  case 2709:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* nelas */
  case 2710:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* neles */
  case 2711:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nervo */
  case 2712:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* nesga */
  case 2713:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* nessa */
  case 2714:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* nesse */
  case 2715:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* nesta */
  case 2716:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* neste */
  case 2717:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* netas */
  case 2718:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* netos */
  case 2719:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nevai */
  case 2720:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* nevam */
  case 2721:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* nevar */
  case 2722:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* nevas */
  case 2723:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* nevei */
  case 2724:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* nevem */
  case 2725:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* neves */
  case 2726:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nevou */
  case 2727:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* nexos */
  case 2728:
    firstLetter = 'n';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nicho */
  case 2729:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* ninai */
  case 2730:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ninam */
  case 2731:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ninar */
  case 2732:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ninas */
  case 2733:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ninei */
  case 2734:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ninem */
  case 2735:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* nines */
  case 2736:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ninfa */
  case 2737:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* ninho */
  case 2738:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* ninou */
  case 2739:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* nisso */
  case 2740:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* nisto */
  case 2741:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* nitro */
  case 2742:
    firstLetter = 'n';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* nobre */
  case 2743:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* nodal */
  case 2744:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* noite */
  case 2745:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* noiva */
  case 2746:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* noive */
  case 2747:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* noivo */
  case 2748:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* nomes */
  case 2749:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* noras */
  case 2750:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* norma */
  case 2751:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* norte */
  case 2752:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* nossa */
  case 2753:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* nosso */
  case 2754:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* notai */
  case 2755:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* notam */
  case 2756:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* notar */
  case 2757:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* notas */
  case 2758:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* notei */
  case 2759:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* notem */
  case 2760:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* notes */
  case 2761:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* notou */
  case 2762:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* novas */
  case 2763:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* novos */
  case 2764:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* nozes */
  case 2765:
    firstLetter = 'n';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nudez */
  case 2766:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'z';
    break;

  /* nulas */
  case 2767:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* nulos */
  case 2768:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* numas */
  case 2769:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* nunca */
  case 2770:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* nunes */
  case 2771:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* nutra */
  case 2772:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* nutre */
  case 2773:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* nutri */
  case 2774:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* nutro */
  case 2775:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* nuvem */
  case 2776:
    firstLetter = 'n';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* obesa */
  case 2777:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* obeso */
  case 2778:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* obras */
  case 2779:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* obsta */
  case 2780:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* obste */
  case 2781:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* obsto */
  case 2782:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* obter */
  case 2783:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* obvia */
  case 2784:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* obvie */
  case 2785:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* obvio */
  case 2786:
    firstLetter = 'o';
    secondLetter = 'b';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* ocaso */
  case 2787:
    firstLetter = 'o';
    secondLetter = 'c';
    thirdLetter = 'a';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* ocupa */
  case 2788:
    firstLetter = 'o';
    secondLetter = 'c';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* ocupe */
  case 2789:
    firstLetter = 'o';
    secondLetter = 'c';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* ocupo */
  case 2790:
    firstLetter = 'o';
    secondLetter = 'c';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* odeia */
  case 2791:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* odeie */
  case 2792:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* odeio */
  case 2793:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* odiai */
  case 2794:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* odiar */
  case 2795:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* odiei */
  case 2796:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* odiou */
  case 2797:
    firstLetter = 'o';
    secondLetter = 'd';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* oeste */
  case 2798:
    firstLetter = 'o';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* ogiva */
  case 2799:
    firstLetter = 'o';
    secondLetter = 'g';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* olhai */
  case 2800:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* olham */
  case 2801:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* olhar */
  case 2802:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* olhas */
  case 2803:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* olhei */
  case 2804:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* olhem */
  case 2805:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* olhes */
  case 2806:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* olhos */
  case 2807:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* olhou */
  case 2808:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'h';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* oliva */
  case 2809:
    firstLetter = 'o';
    secondLetter = 'l';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* ombro */
  case 2810:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* omega */
  case 2811:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* omita */
  case 2812:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* omite */
  case 2813:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* omiti */
  case 2814:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* omito */
  case 2815:
    firstLetter = 'o';
    secondLetter = 'm';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ondas */
  case 2816:
    firstLetter = 'o';
    secondLetter = 'n';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* onera */
  case 2817:
    firstLetter = 'o';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* onere */
  case 2818:
    firstLetter = 'o';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* onero */
  case 2819:
    firstLetter = 'o';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ontem */
  case 2820:
    firstLetter = 'o';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* opaca */
  case 2821:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* opaco */
  case 2822:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* opala */
  case 2823:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'a';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* opera */
  case 2824:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* opere */
  case 2825:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* opero */
  case 2826:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* opina */
  case 2827:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* opine */
  case 2828:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* opino */
  case 2829:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* optai */
  case 2830:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* optam */
  case 2831:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* optar */
  case 2832:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* optas */
  case 2833:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* optei */
  case 2834:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* optem */
  case 2835:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* optes */
  case 2836:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* optou */
  case 2837:
    firstLetter = 'o';
    secondLetter = 'p';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* orado */
  case 2838:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* orais */
  case 2839:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* oramo */
  case 2840:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* orara */
  case 2841:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* orava */
  case 2842:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* orcas */
  case 2843:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* orcei */
  case 2844:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* orcem */
  case 2845:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* orces */
  case 2846:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ordem */
  case 2847:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* oreis */
  case 2848:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* oremo */
  case 2849:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* orgem */
  case 2850:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* orges */
  case 2851:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* orgia */
  case 2852:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* orlai */
  case 2853:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* orlam */
  case 2854:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* orlar */
  case 2855:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* orlas */
  case 2856:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* orlei */
  case 2857:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* orlem */
  case 2858:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* orles */
  case 2859:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* orlou */
  case 2860:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ornai */
  case 2861:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ornam */
  case 2862:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ornar */
  case 2863:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ornas */
  case 2864:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ornei */
  case 2865:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ornem */
  case 2866:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ornes */
  case 2867:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ornou */
  case 2868:
    firstLetter = 'o';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ossos */
  case 2869:
    firstLetter = 'o';
    secondLetter = 's';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ostra */
  case 2870:
    firstLetter = 'o';
    secondLetter = 's';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ouros */
  case 2871:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ousai */
  case 2872:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ousam */
  case 2873:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ousar */
  case 2874:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ousas */
  case 2875:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ousei */
  case 2876:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ousem */
  case 2877:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ouses */
  case 2878:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ousou */
  case 2879:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* outra */
  case 2880:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* outro */
  case 2881:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* ouvem */
  case 2882:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* ouves */
  case 2883:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ouvia */
  case 2884:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ouvir */
  case 2885:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* ouvis */
  case 2886:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ouviu */
  case 2887:
    firstLetter = 'o';
    secondLetter = 'u';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* ovais */
  case 2888:
    firstLetter = 'o';
    secondLetter = 'v';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ovino */
  case 2889:
    firstLetter = 'o';
    secondLetter = 'v';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* oxida */
  case 2890:
    firstLetter = 'o';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* oxide */
  case 2891:
    firstLetter = 'o';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* oxido */
  case 2892:
    firstLetter = 'o';
    secondLetter = 'x';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* pacto */
  case 2893:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* padre */
  case 2894:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* pagai */
  case 2895:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pagam */
  case 2896:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pagar */
  case 2897:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pagas */
  case 2898:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pagem */
  case 2899:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pagos */
  case 2900:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pagou */
  case 2901:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pague */
  case 2902:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* paira */
  case 2903:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* paire */
  case 2904:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* pairo */
  case 2905:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* palco */
  case 2906:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* palha */
  case 2907:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* palma */
  case 2908:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* palmo */
  case 2909:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* pampa */
  case 2910:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* panca */
  case 2911:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* panda */
  case 2912:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* panos */
  case 2913:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* papai */
  case 2914:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* papam */
  case 2915:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* papar */
  case 2916:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* papas */
  case 2917:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* papei */
  case 2918:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* papel */
  case 2919:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* papem */
  case 2920:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* papes */
  case 2921:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* papos */
  case 2922:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* papou */
  case 2923:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* parai */
  case 2924:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* param */
  case 2925:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* parar */
  case 2926:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* paras */
  case 2927:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* parca */
  case 2928:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* parco */
  case 2929:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* parda */
  case 2930:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* pardo */
  case 2931:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* parei */
  case 2932:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* parem */
  case 2933:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pares */
  case 2934:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* paria */
  case 2935:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* parir */
  case 2936:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* paris */
  case 2937:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* pariu */
  case 2938:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* parou */
  case 2939:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* parta */
  case 2940:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* parte */
  case 2941:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* parti */
  case 2942:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* parto */
  case 2943:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* parvo */
  case 2944:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* pasma */
  case 2945:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* pasme */
  case 2946:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* pasmo */
  case 2947:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* passa */
  case 2948:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* passe */
  case 2949:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* passo */
  case 2950:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* pasta */
  case 2951:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* paste */
  case 2952:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* pasto */
  case 2953:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* patas */
  case 2954:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* patim */
  case 2955:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* patos */
  case 2956:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* paula */
  case 2957:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* paulo */
  case 2958:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* pausa */
  case 2959:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* pauta */
  case 2960:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* paute */
  case 2961:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* pauto */
  case 2962:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* pavio */
  case 2963:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* pavor */
  case 2964:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* pazes */
  case 2965:
    firstLetter = 'p';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pecai */
  case 2966:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pecam */
  case 2967:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pecar */
  case 2968:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pecas */
  case 2969:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pecou */
  case 2970:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pedal */
  case 2971:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* pedem */
  case 2972:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pedes */
  case 2973:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pedia */
  case 2974:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* pedir */
  case 2975:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* pedis */
  case 2976:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* pediu */
  case 2977:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* pedra */
  case 2978:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* pedro */
  case 2979:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* pegai */
  case 2980:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pegam */
  case 2981:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pegar */
  case 2982:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pegas */
  case 2983:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pegou */
  case 2984:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pegue */
  case 2985:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* peida */
  case 2986:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* peide */
  case 2987:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* peido */
  case 2988:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* peita */
  case 2989:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* peite */
  case 2990:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* peito */
  case 2991:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* peixe */
  case 2992:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* pelai */
  case 2993:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pelam */
  case 2994:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pelar */
  case 2995:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pelas */
  case 2996:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pelei */
  case 2997:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* pelem */
  case 2998:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* peles */
  case 2999:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pelos */
  case 3000:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pelou */
  case 3001:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* penai */
  case 3002:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* penal */
  case 3003:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* penam */
  case 3004:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* penar */
  case 3005:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* penas */
  case 3006:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* penca */
  case 3007:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* penda */
  case 3008:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* pende */
  case 3009:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* pendi */
  case 3010:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* pendo */
  case 3011:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* penei */
  case 3012:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* penem */
  case 3013:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* penes */
  case 3014:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* penou */
  case 3015:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pensa */
  case 3016:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* pense */
  case 3017:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* penso */
  case 3018:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* pente */
  case 3019:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* peque */
  case 3020:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* peras */
  case 3021:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* perca */
  case 3022:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* perco */
  case 3023:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* perda */
  case 3024:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* perde */
  case 3025:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* perdi */
  case 3026:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* perna */
  case 3027:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* persa */
  case 3028:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* perto */
  case 3029:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* perua */
  case 3030:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* perus */
  case 3031:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* pesai */
  case 3032:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pesam */
  case 3033:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pesar */
  case 3034:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pesas */
  case 3035:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pesca */
  case 3036:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* pesco */
  case 3037:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* pesei */
  case 3038:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* pesem */
  case 3039:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* peses */
  case 3040:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pesos */
  case 3041:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pesou */
  case 3042:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* peste */
  case 3043:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* petiz */
  case 3044:
    firstLetter = 'p';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* piada */
  case 3045:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* piado */
  case 3046:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* piais */
  case 3047:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* piamo */
  case 3048:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* piano */
  case 3049:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* piara */
  case 3050:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* piava */
  case 3051:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* picai */
  case 3052:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* picam */
  case 3053:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* picar */
  case 3054:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* picas */
  case 3055:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* picha */
  case 3056:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* piche */
  case 3057:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* picho */
  case 3058:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* picos */
  case 3059:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* picou */
  case 3060:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pieis */
  case 3061:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* piemo */
  case 3062:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* pifai */
  case 3063:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pifam */
  case 3064:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pifar */
  case 3065:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pifas */
  case 3066:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pifei */
  case 3067:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* pifem */
  case 3068:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pifes */
  case 3069:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pifou */
  case 3070:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pilar */
  case 3071:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pilha */
  case 3072:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* pilhe */
  case 3073:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* pilho */
  case 3074:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* pince */
  case 3075:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* pinga */
  case 3076:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* pingo */
  case 3077:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* pinha */
  case 3078:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* pinho */
  case 3079:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* pinos */
  case 3080:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pinta */
  case 3081:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* pinte */
  case 3082:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* pinto */
  case 3083:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* piora */
  case 3084:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* piore */
  case 3085:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* pioro */
  case 3086:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* pipas */
  case 3087:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pique */
  case 3088:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* pires */
  case 3089:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pisai */
  case 3090:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pisam */
  case 3091:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pisar */
  case 3092:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pisas */
  case 3093:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pisca */
  case 3094:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* pisco */
  case 3095:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* pisei */
  case 3096:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* pisem */
  case 3097:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pises */
  case 3098:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pisou */
  case 3099:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pista */
  case 3100:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* pixel */
  case 3101:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* pizza */
  case 3102:
    firstLetter = 'p';
    secondLetter = 'i';
    thirdLetter = 'z';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* placa */
  case 3103:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* plana */
  case 3104:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* plane */
  case 3105:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* plano */
  case 3106:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* plebe */
  case 3107:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* plena */
  case 3108:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* pleno */
  case 3109:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* plota */
  case 3110:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* plote */
  case 3111:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* ploto */
  case 3112:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* pluga */
  case 3113:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* plugo */
  case 3114:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* pluma */
  case 3115:
    firstLetter = 'p';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* pneus */
  case 3116:
    firstLetter = 'p';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* pobre */
  case 3117:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* podai */
  case 3118:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* podam */
  case 3119:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* podar */
  case 3120:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* podas */
  case 3121:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* podei */
  case 3122:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* podem */
  case 3123:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* poder */
  case 3124:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* podes */
  case 3125:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* podia */
  case 3126:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* podou */
  case 3127:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* poema */
  case 3128:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* poeta */
  case 3129:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* polar */
  case 3130:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* polca */
  case 3131:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* polia */
  case 3132:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* polir */
  case 3133:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* polis */
  case 3134:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* poliu */
  case 3135:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* polpa */
  case 3136:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* polvo */
  case 3137:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* pomar */
  case 3138:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pomba */
  case 3139:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* pombo */
  case 3140:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* pomos */
  case 3141:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pompa */
  case 3142:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* ponde */
  case 3143:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* pondo */
  case 3144:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* ponha */
  case 3145:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* ponho */
  case 3146:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* ponta */
  case 3147:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* ponte */
  case 3148:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* ponto */
  case 3149:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* porca */
  case 3150:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* porco */
  case 3151:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* porei */
  case 3152:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* porem */
  case 3153:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pores */
  case 3154:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* poria */
  case 3155:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* poros */
  case 3156:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* porra */
  case 3157:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* porre */
  case 3158:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* porta */
  case 3159:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* porte */
  case 3160:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* porto */
  case 3161:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* posai */
  case 3162:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* posam */
  case 3163:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* posar */
  case 3164:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* posas */
  case 3165:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* posei */
  case 3166:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* posem */
  case 3167:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* poses */
  case 3168:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* posou */
  case 3169:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* possa */
  case 3170:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* posse */
  case 3171:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* posso */
  case 3172:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* posta */
  case 3173:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* poste */
  case 3174:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* posto */
  case 3175:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* potes */
  case 3176:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* potro */
  case 3177:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* pouca */
  case 3178:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* pouco */
  case 3179:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* poupa */
  case 3180:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* poupe */
  case 3181:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* poupo */
  case 3182:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* pousa */
  case 3183:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* pouse */
  case 3184:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* pouso */
  case 3185:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* povoa */
  case 3186:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* povoe */
  case 3187:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* povos */
  case 3188:
    firstLetter = 'p';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* prado */
  case 3189:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* praga */
  case 3190:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* praia */
  case 3191:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* prata */
  case 3192:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* prato */
  case 3193:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* praxe */
  case 3194:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'x';
    fifthLetter = 'e';
    break;

  /* prazo */
  case 3195:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* prece */
  case 3196:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* prega */
  case 3197:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* prego */
  case 3198:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* prelo */
  case 3199:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* prema */
  case 3200:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* preme */
  case 3201:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* premi */
  case 3202:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* premo */
  case 3203:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* presa */
  case 3204:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* preso */
  case 3205:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* preta */
  case 3206:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* preto */
  case 3207:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* previ */
  case 3208:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* preza */
  case 3209:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* preze */
  case 3210:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* prezo */
  case 3211:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* prima */
  case 3212:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* prime */
  case 3213:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* primo */
  case 3214:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* priva */
  case 3215:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* prive */
  case 3216:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* privo */
  case 3217:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* proas */
  case 3218:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* prole */
  case 3219:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* prosa */
  case 3220:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* prova */
  case 3221:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* prove */
  case 3222:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* provi */
  case 3223:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* provo */
  case 3224:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* prumo */
  case 3225:
    firstLetter = 'p';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* puder */
  case 3226:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* pudim */
  case 3227:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* pudor */
  case 3228:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* pulai */
  case 3229:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* pulam */
  case 3230:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* pular */
  case 3231:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* pulas */
  case 3232:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* pulei */
  case 3233:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* pulem */
  case 3234:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* pules */
  case 3235:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* pulga */
  case 3236:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* pulos */
  case 3237:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* pulou */
  case 3238:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* pulsa */
  case 3239:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* pulse */
  case 3240:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* pulso */
  case 3241:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* pumas */
  case 3242:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* punam */
  case 3243:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* punas */
  case 3244:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* punem */
  case 3245:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* punes */
  case 3246:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* punha */
  case 3247:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* punho */
  case 3248:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* punia */
  case 3249:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* punir */
  case 3250:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* punis */
  case 3251:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* puniu */
  case 3252:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* puras */
  case 3253:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* purga */
  case 3254:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* purgo */
  case 3255:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* puros */
  case 3256:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* puser */
  case 3257:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* putas */
  case 3258:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* putos */
  case 3259:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* puxai */
  case 3260:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* puxam */
  case 3261:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* puxar */
  case 3262:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* puxas */
  case 3263:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* puxei */
  case 3264:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* puxem */
  case 3265:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* puxes */
  case 3266:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* puxou */
  case 3267:
    firstLetter = 'p';
    secondLetter = 'u';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* quais */
  case 3268:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* quase */
  case 3269:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* queda */
  case 3270:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* quede */
  case 3271:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* quedo */
  case 3272:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* quepe */
  case 3273:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* quero */
  case 3274:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* quilo */
  case 3275:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* quina */
  case 3276:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* quita */
  case 3277:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* quite */
  case 3278:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* quito */
  case 3279:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* quota */
  case 3280:
    firstLetter = 'q';
    secondLetter = 'u';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* rabos */
  case 3281:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* racha */
  case 3282:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* rache */
  case 3283:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* racho */
  case 3284:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* radar */
  case 3285:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* radia */
  case 3286:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* radie */
  case 3287:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* radio */
  case 3288:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* raiai */
  case 3289:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* raiam */
  case 3290:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* raiar */
  case 3291:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* raias */
  case 3292:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* raiei */
  case 3293:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* raiem */
  case 3294:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* raies */
  case 3295:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* raios */
  case 3296:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* raiou */
  case 3297:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* raiva */
  case 3298:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* rajai */
  case 3299:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rajam */
  case 3300:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rajar */
  case 3301:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rajas */
  case 3302:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rajei */
  case 3303:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rajem */
  case 3304:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rajes */
  case 3305:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rajou */
  case 3306:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ralai */
  case 3307:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* ralam */
  case 3308:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ralar */
  case 3309:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* ralas */
  case 3310:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ralei */
  case 3311:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* ralem */
  case 3312:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rales */
  case 3313:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ralha */
  case 3314:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* ralhe */
  case 3315:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* ralho */
  case 3316:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* ralos */
  case 3317:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* ralou */
  case 3318:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ramos */
  case 3319:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rampa */
  case 3320:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* range */
  case 3321:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* rangi */
  case 3322:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* ranja */
  case 3323:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* ranjo */
  case 3324:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* rapai */
  case 3325:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rapam */
  case 3326:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rapar */
  case 3327:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rapas */
  case 3328:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rapaz */
  case 3329:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* rapei */
  case 3330:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rapem */
  case 3331:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rapes */
  case 3332:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rapou */
  case 3333:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rapta */
  case 3334:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* rapte */
  case 3335:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* rapto */
  case 3336:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* raras */
  case 3337:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* raros */
  case 3338:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rasas */
  case 3339:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rasga */
  case 3340:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* rasgo */
  case 3341:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* rasos */
  case 3342:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* raspa */
  case 3343:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* raspe */
  case 3344:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* raspo */
  case 3345:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* rasto */
  case 3346:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* ratas */
  case 3347:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ratos */
  case 3348:
    firstLetter = 'r';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* reagi */
  case 3349:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* reais */
  case 3350:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* reaja */
  case 3351:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* reajo */
  case 3352:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* reata */
  case 3353:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* reate */
  case 3354:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* reato */
  case 3355:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* reboa */
  case 3356:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* reboe */
  case 3357:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* recai */
  case 3358:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* recua */
  case 3359:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* recue */
  case 3360:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* recuo */
  case 3361:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* redes */
  case 3362:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* redil */
  case 3363:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* redor */
  case 3364:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* reduz */
  case 3365:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'u';
    fifthLetter = 'z';
    break;

  /* refaz */
  case 3366:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* refez */
  case 3367:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'z';
    break;

  /* refiz */
  case 3368:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'f';
    fourthLetter = 'i';
    fifthLetter = 'z';
    break;

  /* regai */
  case 3369:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* regam */
  case 3370:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* regar */
  case 3371:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* regas */
  case 3372:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* regei */
  case 3373:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* regem */
  case 3374:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* reger */
  case 3375:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* reges */
  case 3376:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* regeu */
  case 3377:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* regia */
  case 3378:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* regou */
  case 3379:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* regra */
  case 3380:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* regre */
  case 3381:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* regro */
  case 3382:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* regue */
  case 3383:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* reina */
  case 3384:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* reine */
  case 3385:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* reino */
  case 3386:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* rejam */
  case 3387:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rejas */
  case 3388:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* reler */
  case 3389:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* reles */
  case 3390:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* releu */
  case 3391:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* relia */
  case 3392:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* relva */
  case 3393:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* remai */
  case 3394:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* remam */
  case 3395:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* remar */
  case 3396:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* remas */
  case 3397:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* remei */
  case 3398:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* remem */
  case 3399:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* remes */
  case 3400:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* remia */
  case 3401:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* remir */
  case 3402:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* remis */
  case 3403:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* remiu */
  case 3404:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* remoa */
  case 3405:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'a';
    break;

  /* remoe */
  case 3406:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'e';
    break;

  /* remos */
  case 3407:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* remou */
  case 3408:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* renal */
  case 3409:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* renas */
  case 3410:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* renda */
  case 3411:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* rende */
  case 3412:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* rendi */
  case 3413:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* rendo */
  case 3414:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* rente */
  case 3415:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* repor */
  case 3416:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* repus */
  case 3417:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* reses */
  case 3418:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* resma */
  case 3419:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* resta */
  case 3420:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* reste */
  case 3421:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* resto */
  case 3422:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* retas */
  case 3423:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* reter */
  case 3424:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* retos */
  case 3425:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* reuni */
  case 3426:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'i';
    break;

  /* rever */
  case 3427:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* revia */
  case 3428:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* revir */
  case 3429:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* reviu */
  case 3430:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* rezai */
  case 3431:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rezam */
  case 3432:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rezar */
  case 3433:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rezas */
  case 3434:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rezei */
  case 3435:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rezem */
  case 3436:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rezes */
  case 3437:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rezou */
  case 3438:
    firstLetter = 'r';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* riais */
  case 3439:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* riamo */
  case 3440:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ribas */
  case 3441:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ricas */
  case 3442:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ricos */
  case 3443:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rides */
  case 3444:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rifai */
  case 3445:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rifam */
  case 3446:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rifar */
  case 3447:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rifas */
  case 3448:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rifei */
  case 3449:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rifem */
  case 3450:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rifes */
  case 3451:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rifle */
  case 3452:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* rifou */
  case 3453:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rigor */
  case 3454:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* rijas */
  case 3455:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rijos */
  case 3456:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rimai */
  case 3457:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rimam */
  case 3458:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rimar */
  case 3459:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rimas */
  case 3460:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rimei */
  case 3461:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rimem */
  case 3462:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rimes */
  case 3463:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rimos */
  case 3464:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rimou */
  case 3465:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rindo */
  case 3466:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* ripas */
  case 3467:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* riram */
  case 3468:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* riras */
  case 3469:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rirei */
  case 3470:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rirem */
  case 3471:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rires */
  case 3472:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* riria */
  case 3473:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* rirmo */
  case 3474:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* risca */
  case 3475:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* risco */
  case 3476:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* risos */
  case 3477:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* risse */
  case 3478:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* riste */
  case 3479:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* ritmo */
  case 3480:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ritos */
  case 3481:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rival */
  case 3482:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* rixas */
  case 3483:
    firstLetter = 'r';
    secondLetter = 'i';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* roais */
  case 3484:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* roamo */
  case 3485:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* rocas */
  case 3486:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rocei */
  case 3487:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rocem */
  case 3488:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* roces */
  case 3489:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rocha */
  case 3490:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* rodai */
  case 3491:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rodam */
  case 3492:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rodar */
  case 3493:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rodas */
  case 3494:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rodei */
  case 3495:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rodem */
  case 3496:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rodes */
  case 3497:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rodos */
  case 3498:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rodou */
  case 3499:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* roeis */
  case 3500:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* roemo */
  case 3501:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* roera */
  case 3502:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* rogai */
  case 3503:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rogam */
  case 3504:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rogar */
  case 3505:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rogas */
  case 3506:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rogem */
  case 3507:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* roges */
  case 3508:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rogos */
  case 3509:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rogou */
  case 3510:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rogue */
  case 3511:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* rolai */
  case 3512:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rolam */
  case 3513:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rolar */
  case 3514:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rolas */
  case 3515:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rolei */
  case 3516:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rolem */
  case 3517:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* roles */
  case 3518:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rolha */
  case 3519:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* rolos */
  case 3520:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rolou */
  case 3521:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rombo */
  case 3522:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* rompa */
  case 3523:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* rompe */
  case 3524:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* rompi */
  case 3525:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'i';
    break;

  /* rompo */
  case 3526:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* ronca */
  case 3527:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* ronco */
  case 3528:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* ronda */
  case 3529:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* ronde */
  case 3530:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* rondo */
  case 3531:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* roque */
  case 3532:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* rosas */
  case 3533:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rosca */
  case 3534:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* rosna */
  case 3535:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* rosne */
  case 3536:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* rosno */
  case 3537:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* rosto */
  case 3538:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* rotas */
  case 3539:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rotos */
  case 3540:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rouba */
  case 3541:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* roube */
  case 3542:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* roubo */
  case 3543:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* rouca */
  case 3544:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* rouco */
  case 3545:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* roupa */
  case 3546:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* roxas */
  case 3547:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* roxos */
  case 3548:
    firstLetter = 'r';
    secondLetter = 'o';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rubis */
  case 3549:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* rublo */
  case 3550:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* rubra */
  case 3551:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* rubro */
  case 3552:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* rudes */
  case 3553:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ruela */
  case 3554:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* rufai */
  case 3555:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rufam */
  case 3556:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rufar */
  case 3557:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rufas */
  case 3558:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rufei */
  case 3559:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rufem */
  case 3560:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rufes */
  case 3561:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rufou */
  case 3562:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rugai */
  case 3563:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rugam */
  case 3564:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rugar */
  case 3565:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rugas */
  case 3566:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rugia */
  case 3567:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* rugir */
  case 3568:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* rugis */
  case 3569:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* rugiu */
  case 3570:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* rugou */
  case 3571:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rugue */
  case 3572:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* ruiam */
  case 3573:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* ruias */
  case 3574:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ruido */
  case 3575:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* ruimo */
  case 3576:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ruins */
  case 3577:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 's';
    break;

  /* ruira */
  case 3578:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ruiva */
  case 3579:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* ruivo */
  case 3580:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* rujam */
  case 3581:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rujas */
  case 3582:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rumai */
  case 3583:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* rumam */
  case 3584:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* rumar */
  case 3585:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* rumas */
  case 3586:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* rumei */
  case 3587:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* rumem */
  case 3588:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* rumes */
  case 3589:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* rumor */
  case 3590:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* rumos */
  case 3591:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* rumou */
  case 3592:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* rural */
  case 3593:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* rusga */
  case 3594:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* russa */
  case 3595:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* russo */
  case 3596:
    firstLetter = 'r';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* sabei */
  case 3597:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* sabem */
  case 3598:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* saber */
  case 3599:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* sabes */
  case 3600:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sabia */
  case 3601:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sabor */
  case 3602:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* sabre */
  case 3603:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* sacai */
  case 3604:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* sacam */
  case 3605:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sacar */
  case 3606:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* sacas */
  case 3607:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sacia */
  case 3608:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sacie */
  case 3609:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* sacio */
  case 3610:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* sacis */
  case 3611:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* sacos */
  case 3612:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sacou */
  case 3613:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sacra */
  case 3614:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sacro */
  case 3615:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* sadia */
  case 3616:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sadio */
  case 3617:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* safai */
  case 3618:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* safam */
  case 3619:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* safar */
  case 3620:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* safas */
  case 3621:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* safei */
  case 3622:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* safem */
  case 3623:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* safes */
  case 3624:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* safou */
  case 3625:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* safra */
  case 3626:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sagas */
  case 3627:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sagaz */
  case 3628:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* sagra */
  case 3629:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sagre */
  case 3630:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* sagro */
  case 3631:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* saiam */
  case 3632:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* saias */
  case 3633:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* saiba */
  case 3634:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* saido */
  case 3635:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* salas */
  case 3636:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* salda */
  case 3637:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* salde */
  case 3638:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* saldo */
  case 3639:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* sales */
  case 3640:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* salga */
  case 3641:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* salgo */
  case 3642:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* salmo */
  case 3643:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* salsa */
  case 3644:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* salta */
  case 3645:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* salte */
  case 3646:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* salto */
  case 3647:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* salva */
  case 3648:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* salve */
  case 3649:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* salvo */
  case 3650:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* samba */
  case 3651:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* sambe */
  case 3652:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* sambo */
  case 3653:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* sanai */
  case 3654:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* sanam */
  case 3655:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sanar */
  case 3656:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* sanas */
  case 3657:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sanei */
  case 3658:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* sanem */
  case 3659:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* sanes */
  case 3660:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sanha */
  case 3661:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* sanou */
  case 3662:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* santa */
  case 3663:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* santo */
  case 3664:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* sapos */
  case 3665:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* saque */
  case 3666:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* sarai */
  case 3667:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* saram */
  case 3668:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sarar */
  case 3669:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* saras */
  case 3670:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sarda */
  case 3671:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* sarei */
  case 3672:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* sarem */
  case 3673:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* sares */
  case 3674:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sarna */
  case 3675:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* sarou */
  case 3676:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sauna */
  case 3677:
    firstLetter = 's';
    secondLetter = 'a';
    thirdLetter = 'u';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* seara */
  case 3678:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sebes */
  case 3679:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sebos */
  case 3680:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* secai */
  case 3681:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* secam */
  case 3682:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* secar */
  case 3683:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* secas */
  case 3684:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* secos */
  case 3685:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* secou */
  case 3686:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sedas */
  case 3687:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sedes */
  case 3688:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sedia */
  case 3689:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sedie */
  case 3690:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* sedio */
  case 3691:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* seduz */
  case 3692:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'u';
    fifthLetter = 'z';
    break;

  /* segue */
  case 3693:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* segui */
  case 3694:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'i';
    break;

  /* seios */
  case 3695:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* seita */
  case 3696:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* seiva */
  case 3697:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* seixo */
  case 3698:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'x';
    fifthLetter = 'o';
    break;

  /* sejam */
  case 3699:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sejas */
  case 3700:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* selai */
  case 3701:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* selam */
  case 3702:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* selar */
  case 3703:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* selas */
  case 3704:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* selei */
  case 3705:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* selem */
  case 3706:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* seles */
  case 3707:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* selim */
  case 3708:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* selos */
  case 3709:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* selou */
  case 3710:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* selva */
  case 3711:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* senda */
  case 3712:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* sendo */
  case 3713:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* senha */
  case 3714:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* senos */
  case 3715:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* senso */
  case 3716:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* senta */
  case 3717:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* sente */
  case 3718:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* senti */
  case 3719:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* sento */
  case 3720:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* seque */
  case 3721:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* serei */
  case 3722:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* serem */
  case 3723:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* seres */
  case 3724:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* seria */
  case 3725:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* serie */
  case 3726:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* serio */
  case 3727:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* serra */
  case 3728:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* serre */
  case 3729:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* serro */
  case 3730:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* serva */
  case 3731:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* serve */
  case 3732:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* servi */
  case 3733:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* servo */
  case 3734:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* serze */
  case 3735:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* serzi */
  case 3736:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'z';
    fifthLetter = 'i';
    break;

  /* sesta */
  case 3737:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* setas */
  case 3738:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* setor */
  case 3739:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* sexos */
  case 3740:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sexta */
  case 3741:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* sexto */
  case 3742:
    firstLetter = 's';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* sigam */
  case 3743:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sigas */
  case 3744:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sigla */
  case 3745:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* sigma */
  case 3746:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* signo */
  case 3747:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* silos */
  case 3748:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* silva */
  case 3749:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* silve */
  case 3750:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* silvo */
  case 3751:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* sinal */
  case 3752:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* sinas */
  case 3753:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sinos */
  case 3754:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sinta */
  case 3755:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* sinto */
  case 3756:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* siris */
  case 3757:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* sirva */
  case 3758:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* sirvo */
  case 3759:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* sirza */
  case 3760:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* sirzo */
  case 3761:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* sisma */
  case 3762:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* sisme */
  case 3763:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* sismo */
  case 3764:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* sitas */
  case 3765:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sitia */
  case 3766:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sitie */
  case 3767:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* sitio */
  case 3768:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* sitos */
  case 3769:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* situa */
  case 3770:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* situe */
  case 3771:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* situo */
  case 3772:
    firstLetter = 's';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* soado */
  case 3773:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* soais */
  case 3774:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* soamo */
  case 3775:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* soara */
  case 3776:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* soava */
  case 3777:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* sobem */
  case 3778:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* sobes */
  case 3779:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sobra */
  case 3780:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sobre */
  case 3781:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* sobro */
  case 3782:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* socai */
  case 3783:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* socam */
  case 3784:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* socar */
  case 3785:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* socas */
  case 3786:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* socos */
  case 3787:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* socou */
  case 3788:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* soeis */
  case 3789:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* soemo */
  case 3790:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* sofra */
  case 3791:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sofre */
  case 3792:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* sofri */
  case 3793:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* sofro */
  case 3794:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'f';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* sogra */
  case 3795:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sogro */
  case 3796:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* solai */
  case 3797:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* solam */
  case 3798:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* solar */
  case 3799:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* solas */
  case 3800:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* solda */
  case 3801:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* solde */
  case 3802:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* soldo */
  case 3803:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* solei */
  case 3804:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* solem */
  case 3805:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* soles */
  case 3806:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* solos */
  case 3807:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* solou */
  case 3808:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* solta */
  case 3809:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* solte */
  case 3810:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* solto */
  case 3811:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* somai */
  case 3812:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* somam */
  case 3813:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* somar */
  case 3814:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* somas */
  case 3815:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* somei */
  case 3816:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* somem */
  case 3817:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* somes */
  case 3818:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* somos */
  case 3819:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* somou */
  case 3820:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sonda */
  case 3821:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* sonde */
  case 3822:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* sondo */
  case 3823:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* sonha */
  case 3824:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* sonhe */
  case 3825:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* sonho */
  case 3826:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* sonos */
  case 3827:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sonsa */
  case 3828:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* sonso */
  case 3829:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* sopas */
  case 3830:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sopra */
  case 3831:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* sopre */
  case 3832:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* sopro */
  case 3833:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* soque */
  case 3834:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* soros */
  case 3835:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sorri */
  case 3836:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* sorta */
  case 3837:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* sorte */
  case 3838:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* sorti */
  case 3839:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* sorva */
  case 3840:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* sorve */
  case 3841:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* sorvi */
  case 3842:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* sorvo */
  case 3843:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* soube */
  case 3844:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* sousa */
  case 3845:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* souza */
  case 3846:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* sovai */
  case 3847:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* sovam */
  case 3848:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sovar */
  case 3849:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* sovas */
  case 3850:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sovei */
  case 3851:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* sovem */
  case 3852:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* soves */
  case 3853:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sovou */
  case 3854:
    firstLetter = 's';
    secondLetter = 'o';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* suada */
  case 3855:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* suado */
  case 3856:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* suais */
  case 3857:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* suamo */
  case 3858:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* suara */
  case 3859:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* suava */
  case 3860:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* suave */
  case 3861:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* subam */
  case 3862:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* subas */
  case 3863:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* subia */
  case 3864:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* subir */
  case 3865:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* subis */
  case 3866:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* subiu */
  case 3867:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* sucos */
  case 3868:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sueca */
  case 3869:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* sueco */
  case 3870:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* sueis */
  case 3871:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* suemo */
  case 3872:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* sugai */
  case 3873:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* sugam */
  case 3874:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sugar */
  case 3875:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* sugas */
  case 3876:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sugou */
  case 3877:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sugue */
  case 3878:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* sujai */
  case 3879:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* sujam */
  case 3880:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sujar */
  case 3881:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* sujas */
  case 3882:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sujei */
  case 3883:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* sujem */
  case 3884:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* sujes */
  case 3885:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* sujos */
  case 3886:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* sujou */
  case 3887:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'j';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* sulca */
  case 3888:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* sulco */
  case 3889:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* sulfa */
  case 3890:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* sumam */
  case 3891:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* sumas */
  case 3892:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* sumia */
  case 3893:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* sumir */
  case 3894:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* sumis */
  case 3895:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* sumiu */
  case 3896:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* sunga */
  case 3897:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* super */
  case 3898:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* supor */
  case 3899:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* supra */
  case 3900:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* supre */
  case 3901:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* supri */
  case 3902:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* supro */
  case 3903:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* supus */
  case 3904:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* surda */
  case 3905:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* surdo */
  case 3906:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* surge */
  case 3907:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* surgi */
  case 3908:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* surja */
  case 3909:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* surjo */
  case 3910:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* surra */
  case 3911:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* surre */
  case 3912:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* surro */
  case 3913:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* surta */
  case 3914:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* surte */
  case 3915:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* surto */
  case 3916:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* susta */
  case 3917:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* suste */
  case 3918:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* susti */
  case 3919:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* susto */
  case 3920:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* sutil */
  case 3921:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* sutis */
  case 3922:
    firstLetter = 's';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* tabas */
  case 3923:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'b';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tacai */
  case 3924:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tacam */
  case 3925:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tacar */
  case 3926:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tacas */
  case 3927:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tacha */
  case 3928:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* tache */
  case 3929:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* tacho */
  case 3930:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* tacos */
  case 3931:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tacou */
  case 3932:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* taipa */
  case 3933:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* talas */
  case 3934:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* talco */
  case 3935:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* talha */
  case 3936:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* talhe */
  case 3937:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* talho */
  case 3938:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* talos */
  case 3939:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tampa */
  case 3940:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* tampe */
  case 3941:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* tampo */
  case 3942:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* tanga */
  case 3943:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* tange */
  case 3944:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'e';
    break;

  /* tangi */
  case 3945:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* tango */
  case 3946:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* tanja */
  case 3947:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* tanjo */
  case 3948:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* tanta */
  case 3949:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* tanto */
  case 3950:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* tapai */
  case 3951:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tapam */
  case 3952:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tapar */
  case 3953:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tapas */
  case 3954:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tapei */
  case 3955:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* tapem */
  case 3956:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* tapes */
  case 3957:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tapou */
  case 3958:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* taque */
  case 3959:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* taras */
  case 3960:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tarda */
  case 3961:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* tarde */
  case 3962:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* tardo */
  case 3963:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* tarja */
  case 3964:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* tatua */
  case 3965:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'a';
    break;

  /* tatue */
  case 3966:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* tatuo */
  case 3967:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 'o';
    break;

  /* tatus */
  case 3968:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 't';
    fourthLetter = 'u';
    fifthLetter = 's';
    break;

  /* taxai */
  case 3969:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* taxam */
  case 3970:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* taxar */
  case 3971:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* taxas */
  case 3972:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* taxei */
  case 3973:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* taxem */
  case 3974:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* taxes */
  case 3975:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* taxou */
  case 3976:
    firstLetter = 't';
    secondLetter = 'a';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* tecei */
  case 3977:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* tecem */
  case 3978:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* tecer */
  case 3979:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* teces */
  case 3980:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* teceu */
  case 3981:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* tecia */
  case 3982:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* tecla */
  case 3983:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* tecle */
  case 3984:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* teclo */
  case 3985:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'c';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* teias */
  case 3986:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* teima */
  case 3987:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* teime */
  case 3988:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* teimo */
  case 3989:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* telas */
  case 3990:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* teles */
  case 3991:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* telha */
  case 3992:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* temam */
  case 3993:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* temas */
  case 3994:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* temei */
  case 3995:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* temem */
  case 3996:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* temer */
  case 3997:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* temes */
  case 3998:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* temeu */
  case 3999:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* temia */
  case 4000:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* temor */
  case 4001:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* temos */
  case 4002:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tempo */
  case 4003:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* tenaz */
  case 4004:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* tenda */
  case 4005:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* tende */
  case 4006:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* tendi */
  case 4007:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* tendo */
  case 4008:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* tenha */
  case 4009:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* tenho */
  case 4010:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* tenor */
  case 4011:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* tenra */
  case 4012:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* tenro */
  case 4013:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* tensa */
  case 4014:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* tenso */
  case 4015:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* tenta */
  case 4016:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* tente */
  case 4017:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* tento */
  case 4018:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* terei */
  case 4019:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* terem */
  case 4020:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* teres */
  case 4021:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* teria */
  case 4022:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* termo */
  case 4023:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* terna */
  case 4024:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* terno */
  case 4025:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* terra */
  case 4026:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* tesas */
  case 4027:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* teses */
  case 4028:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tesos */
  case 4029:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* testa */
  case 4030:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* teste */
  case 4031:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* testo */
  case 4032:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* tetas */
  case 4033:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tetos */
  case 4034:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* texto */
  case 4035:
    firstLetter = 't';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* tiara */
  case 4036:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* tidas */
  case 4037:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tidos */
  case 4038:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tigre */
  case 4039:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* times */
  case 4040:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tinam */
  case 4041:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tinas */
  case 4042:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tinem */
  case 4043:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* tines */
  case 4044:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tingi */
  case 4045:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'i';
    break;

  /* tinha */
  case 4046:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* tinia */
  case 4047:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* tinir */
  case 4048:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* tinis */
  case 4049:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* tiniu */
  case 4050:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* tinja */
  case 4051:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* tinjo */
  case 4052:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* tinta */
  case 4053:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* tinto */
  case 4054:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* tipos */
  case 4055:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tirai */
  case 4056:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tiram */
  case 4057:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tirar */
  case 4058:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tiras */
  case 4059:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tirei */
  case 4060:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* tirem */
  case 4061:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* tires */
  case 4062:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tiros */
  case 4063:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tirou */
  case 4064:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* titia */
  case 4065:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* titio */
  case 4066:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* tiver */
  case 4067:
    firstLetter = 't';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* toada */
  case 4068:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* tocai */
  case 4069:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tocam */
  case 4070:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tocar */
  case 4071:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tocas */
  case 4072:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tocha */
  case 4073:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* tocou */
  case 4074:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'c';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* todas */
  case 4075:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* todos */
  case 4076:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* togas */
  case 4077:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tolas */
  case 4078:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* toldo */
  case 4079:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* tolha */
  case 4080:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* tolhe */
  case 4081:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'e';
    break;

  /* tolhi */
  case 4082:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'i';
    break;

  /* tolho */
  case 4083:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* tolos */
  case 4084:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tomai */
  case 4085:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tomam */
  case 4086:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tomar */
  case 4087:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tomas */
  case 4088:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tomba */
  case 4089:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* tombe */
  case 4090:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* tombo */
  case 4091:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* tomei */
  case 4092:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* tomem */
  case 4093:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* tomes */
  case 4094:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tomou */
  case 4095:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* tonel */
  case 4096:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'l';
    break;

  /* tonta */
  case 4097:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* tonto */
  case 4098:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* topai */
  case 4099:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* topam */
  case 4100:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* topar */
  case 4101:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* topas */
  case 4102:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* topei */
  case 4103:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* topem */
  case 4104:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* topes */
  case 4105:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* topos */
  case 4106:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* topou */
  case 4107:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* toque */
  case 4108:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* toras */
  case 4109:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* torce */
  case 4110:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* torci */
  case 4111:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'i';
    break;

  /* torna */
  case 4112:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* torne */
  case 4113:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* torno */
  case 4114:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* toros */
  case 4115:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* torpe */
  case 4116:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* torra */
  case 4117:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* torre */
  case 4118:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* torro */
  case 4119:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* torta */
  case 4120:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* torto */
  case 4121:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* tosai */
  case 4122:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* tosam */
  case 4123:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* tosar */
  case 4124:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* tosas */
  case 4125:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* tosca */
  case 4126:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* tosco */
  case 4127:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* tosei */
  case 4128:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* tosem */
  case 4129:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* toses */
  case 4130:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* tosou */
  case 4131:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* tosse */
  case 4132:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* tossi */
  case 4133:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'i';
    break;

  /* tosta */
  case 4134:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* toste */
  case 4135:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* tosto */
  case 4136:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* total */
  case 4137:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* totem */
  case 4138:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* touca */
  case 4139:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* touro */
  case 4140:
    firstLetter = 't';
    secondLetter = 'o';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* trace */
  case 4141:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* traem */
  case 4142:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* traga */
  case 4143:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* trago */
  case 4144:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* traia */
  case 4145:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* traio */
  case 4146:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* trair */
  case 4147:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* trais */
  case 4148:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* traiu */
  case 4149:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* traja */
  case 4150:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* traje */
  case 4151:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* trajo */
  case 4152:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* trama */
  case 4153:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* trapo */
  case 4154:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* trata */
  case 4155:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* trate */
  case 4156:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* trato */
  case 4157:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* trava */
  case 4158:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* trave */
  case 4159:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* travo */
  case 4160:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* traze */
  case 4161:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* treco */
  case 4162:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* trema */
  case 4163:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* treme */
  case 4164:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* tremi */
  case 4165:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'i';
    break;

  /* tremo */
  case 4166:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* trena */
  case 4167:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* trens */
  case 4168:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 's';
    break;

  /* trepa */
  case 4169:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* trepe */
  case 4170:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* trepo */
  case 4171:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* treta */
  case 4172:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* treva */
  case 4173:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* trevo */
  case 4174:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* treze */
  case 4175:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'e';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* tribo */
  case 4176:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* trigo */
  case 4177:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* trina */
  case 4178:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* trino */
  case 4179:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* trios */
  case 4180:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tripa */
  case 4181:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* troca */
  case 4182:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* troce */
  case 4183:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* troco */
  case 4184:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* trono */
  case 4185:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* tropa */
  case 4186:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* trota */
  case 4187:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* trote */
  case 4188:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* troto */
  case 4189:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* trova */
  case 4190:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'o';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* truco */
  case 4191:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* trufa */
  case 4192:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 'f';
    fifthLetter = 'a';
    break;

  /* truta */
  case 4193:
    firstLetter = 't';
    secondLetter = 'r';
    thirdLetter = 'u';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* tubos */
  case 4194:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'b';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* tumba */
  case 4195:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* tumor */
  case 4196:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* tupis */
  case 4197:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'p';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* turba */
  case 4198:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* turbe */
  case 4199:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* turbo */
  case 4200:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* turca */
  case 4201:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* turco */
  case 4202:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* turma */
  case 4203:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'a';
    break;

  /* turno */
  case 4204:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* turva */
  case 4205:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* turve */
  case 4206:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* turvo */
  case 4207:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* tussa */
  case 4208:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* tusso */
  case 4209:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* tutor */
  case 4210:
    firstLetter = 't';
    secondLetter = 'u';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* ufana */
  case 4211:
    firstLetter = 'u';
    secondLetter = 'f';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* ufane */
  case 4212:
    firstLetter = 'u';
    secondLetter = 'f';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* ufano */
  case 4213:
    firstLetter = 'u';
    secondLetter = 'f';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* uivai */
  case 4214:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* uivam */
  case 4215:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* uivar */
  case 4216:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* uivas */
  case 4217:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* uivei */
  case 4218:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* uivem */
  case 4219:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* uives */
  case 4220:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* uivos */
  case 4221:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* uivou */
  case 4222:
    firstLetter = 'u';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ultra */
  case 4223:
    firstLetter = 'u';
    secondLetter = 'l';
    thirdLetter = 't';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* ulula */
  case 4224:
    firstLetter = 'u';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* ulule */
  case 4225:
    firstLetter = 'u';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* ululo */
  case 4226:
    firstLetter = 'u';
    secondLetter = 'l';
    thirdLetter = 'u';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* unais */
  case 4227:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* unemo */
  case 4228:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* ungem */
  case 4229:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* unges */
  case 4230:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* ungia */
  case 4231:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* ungir */
  case 4232:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* ungis */
  case 4233:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* ungiu */
  case 4234:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* unhas */
  case 4235:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'h';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* uniam */
  case 4236:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* unias */
  case 4237:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* unida */
  case 4238:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* unido */
  case 4239:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* unimo */
  case 4240:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* unira */
  case 4241:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 'i';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* untai */
  case 4242:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* untam */
  case 4243:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* untar */
  case 4244:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* untas */
  case 4245:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* untei */
  case 4246:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* untem */
  case 4247:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* untes */
  case 4248:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* untou */
  case 4249:
    firstLetter = 'u';
    secondLetter = 'n';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* urano */
  case 4250:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* urdam */
  case 4251:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* urdas */
  case 4252:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* urdem */
  case 4253:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* urdes */
  case 4254:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* urdia */
  case 4255:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* urdir */
  case 4256:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* urdis */
  case 4257:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* urdiu */
  case 4258:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* urgia */
  case 4259:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* urgir */
  case 4260:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* urgis */
  case 4261:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* urgiu */
  case 4262:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* urina */
  case 4263:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* urine */
  case 4264:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'e';
    break;

  /* urino */
  case 4265:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'o';
    break;

  /* urjam */
  case 4266:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* urjas */
  case 4267:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* urnas */
  case 4268:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* urrai */
  case 4269:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* urram */
  case 4270:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* urrar */
  case 4271:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* urras */
  case 4272:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* urrei */
  case 4273:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* urrem */
  case 4274:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* urres */
  case 4275:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* urros */
  case 4276:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* urrou */
  case 4277:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* ursas */
  case 4278:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* ursos */
  case 4279:
    firstLetter = 'u';
    secondLetter = 'r';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* usada */
  case 4280:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* usado */
  case 4281:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* usais */
  case 4282:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* usamo */
  case 4283:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* usara */
  case 4284:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* usava */
  case 4285:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* useis */
  case 4286:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* usemo */
  case 4287:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* usina */
  case 4288:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'i';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* usual */
  case 4289:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'u';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* usura */
  case 4290:
    firstLetter = 'u';
    secondLetter = 's';
    thirdLetter = 'u';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* vacas */
  case 4291:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'c';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vades */
  case 4292:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vadia */
  case 4293:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vadie */
  case 4294:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* vadio */
  case 4295:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'd';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* vagai */
  case 4296:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vagam */
  case 4297:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vagar */
  case 4298:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vagas */
  case 4299:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vagem */
  case 4300:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vagia */
  case 4301:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vagir */
  case 4302:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* vagis */
  case 4303:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* vagiu */
  case 4304:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* vagos */
  case 4305:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* vagou */
  case 4306:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* vague */
  case 4307:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* vaiai */
  case 4308:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vaiam */
  case 4309:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vaiar */
  case 4310:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vaias */
  case 4311:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vaiei */
  case 4312:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vaiem */
  case 4313:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vaies */
  case 4314:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vaiou */
  case 4315:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'i';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* valas */
  case 4316:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* valei */
  case 4317:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* valem */
  case 4318:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* valer */
  case 4319:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* vales */
  case 4320:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* valeu */
  case 4321:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* valha */
  case 4322:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* valho */
  case 4323:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* valia */
  case 4324:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* valor */
  case 4325:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* valos */
  case 4326:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* valsa */
  case 4327:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* vamos */
  case 4328:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* vapor */
  case 4329:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'p';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* varai */
  case 4330:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* varam */
  case 4331:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* varar */
  case 4332:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* varas */
  case 4333:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* varei */
  case 4334:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* varem */
  case 4335:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vares */
  case 4336:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* varia */
  case 4337:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* varie */
  case 4338:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* vario */
  case 4339:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* varou */
  case 4340:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* varra */
  case 4341:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* varre */
  case 4342:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* varri */
  case 4343:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'i';
    break;

  /* varro */
  case 4344:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* vasos */
  case 4345:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* vasta */
  case 4346:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* vasto */
  case 4347:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* vazai */
  case 4348:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vazam */
  case 4349:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vazar */
  case 4350:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vazas */
  case 4351:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vazei */
  case 4352:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vazem */
  case 4353:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vazes */
  case 4354:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vazia */
  case 4355:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vazio */
  case 4356:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* vazou */
  case 4357:
    firstLetter = 'v';
    secondLetter = 'a';
    thirdLetter = 'z';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* veado */
  case 4358:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* vedai */
  case 4359:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vedam */
  case 4360:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vedar */
  case 4361:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vedas */
  case 4362:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vedei */
  case 4363:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vedem */
  case 4364:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vedes */
  case 4365:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vedou */
  case 4366:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'd';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* veias */
  case 4367:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'i';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vejai */
  case 4368:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vejam */
  case 4369:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vejas */
  case 4370:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'j';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* velai */
  case 4371:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* velam */
  case 4372:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* velar */
  case 4373:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* velas */
  case 4374:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* velei */
  case 4375:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* velem */
  case 4376:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* veles */
  case 4377:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* velha */
  case 4378:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* velho */
  case 4379:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* velou */
  case 4380:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* veloz */
  case 4381:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'z';
    break;

  /* vemos */
  case 4382:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* venal */
  case 4383:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* vence */
  case 4384:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'e';
    break;

  /* venci */
  case 4385:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'i';
    break;

  /* venda */
  case 4386:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* vende */
  case 4387:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* vendi */
  case 4388:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'i';
    break;

  /* vendo */
  case 4389:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* venha */
  case 4390:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* venho */
  case 4391:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* venta */
  case 4392:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* vente */
  case 4393:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* vento */
  case 4394:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* verba */
  case 4395:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* verbo */
  case 4396:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* verde */
  case 4397:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* verei */
  case 4398:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* verem */
  case 4399:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* veres */
  case 4400:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* verga */
  case 4401:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* veria */
  case 4402:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* verme */
  case 4403:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'e';
    break;

  /* versa */
  case 4404:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* verse */
  case 4405:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* verso */
  case 4406:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* verta */
  case 4407:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* verte */
  case 4408:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* verti */
  case 4409:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* verto */
  case 4410:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* vesga */
  case 4411:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* vesgo */
  case 4412:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* vespa */
  case 4413:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* veste */
  case 4414:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* vesti */
  case 4415:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'i';
    break;

  /* vetai */
  case 4416:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vetam */
  case 4417:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vetar */
  case 4418:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vetas */
  case 4419:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vetei */
  case 4420:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vetem */
  case 4421:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vetes */
  case 4422:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vetor */
  case 4423:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* vetou */
  case 4424:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* vexai */
  case 4425:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* vexam */
  case 4426:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vexar */
  case 4427:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* vexas */
  case 4428:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vexei */
  case 4429:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vexem */
  case 4430:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vexes */
  case 4431:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vexou */
  case 4432:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'x';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* vezes */
  case 4433:
    firstLetter = 'v';
    secondLetter = 'e';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* viaja */
  case 4434:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'a';
    break;

  /* viaje */
  case 4435:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'e';
    break;

  /* viajo */
  case 4436:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'j';
    fifthLetter = 'o';
    break;

  /* viana */
  case 4437:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'a';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* vibra */
  case 4438:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* vibre */
  case 4439:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* vibro */
  case 4440:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* vicia */
  case 4441:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vicie */
  case 4442:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* vicio */
  case 4443:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'c';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* vidas */
  case 4444:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vidra */
  case 4445:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* vidre */
  case 4446:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* vidro */
  case 4447:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'd';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* viela */
  case 4448:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* viena */
  case 4449:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'n';
    fifthLetter = 'a';
    break;

  /* viera */
  case 4450:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* vieza */
  case 4451:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'e';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* vigas */
  case 4452:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vigia */
  case 4453:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vigie */
  case 4454:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'e';
    break;

  /* vigio */
  case 4455:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'i';
    fifthLetter = 'o';
    break;

  /* vigor */
  case 4456:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'g';
    fourthLetter = 'o';
    fifthLetter = 'r';
    break;

  /* vilas */
  case 4457:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vimos */
  case 4458:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'm';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* vinca */
  case 4459:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* vinco */
  case 4460:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* vinda */
  case 4461:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'a';
    break;

  /* vinde */
  case 4462:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'e';
    break;

  /* vindo */
  case 4463:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* vinga */
  case 4464:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* vingo */
  case 4465:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* vinha */
  case 4466:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'a';
    break;

  /* vinho */
  case 4467:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'h';
    fifthLetter = 'o';
    break;

  /* vinte */
  case 4468:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* viola */
  case 4469:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'a';
    break;

  /* viole */
  case 4470:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'e';
    break;

  /* violo */
  case 4471:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'o';
    fourthLetter = 'l';
    fifthLetter = 'o';
    break;

  /* virai */
  case 4472:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* viram */
  case 4473:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* virar */
  case 4474:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* viras */
  case 4475:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* virei */
  case 4476:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* virem */
  case 4477:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vires */
  case 4478:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* viria */
  case 4479:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* viril */
  case 4480:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 'l';
    break;

  /* viris */
  case 4481:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* virmo */
  case 4482:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* virou */
  case 4483:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* visai */
  case 4484:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* visam */
  case 4485:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* visar */
  case 4486:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* visas */
  case 4487:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* visei */
  case 4488:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* visem */
  case 4489:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* vises */
  case 4490:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* visou */
  case 4491:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* visse */
  case 4492:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'e';
    break;

  /* vista */
  case 4493:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* viste */
  case 4494:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* visto */
  case 4495:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* vital */
  case 4496:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* viuva */
  case 4497:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* viuve */
  case 4498:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* viuvo */
  case 4499:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'u';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* vivam */
  case 4500:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* vivas */
  case 4501:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* vivaz */
  case 4502:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* vivei */
  case 4503:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* vivem */
  case 4504:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* viver */
  case 4505:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'r';
    break;

  /* vives */
  case 4506:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* viveu */
  case 4507:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'e';
    fifthLetter = 'u';
    break;

  /* vivia */
  case 4508:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* vivos */
  case 4509:
    firstLetter = 'v';
    secondLetter = 'i';
    thirdLetter = 'v';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* voado */
  case 4510:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'd';
    fifthLetter = 'o';
    break;

  /* voais */
  case 4511:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* voamo */
  case 4512:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* voara */
  case 4513:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* voava */
  case 4514:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'a';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* vodca */
  case 4515:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'd';
    fourthLetter = 'c';
    fifthLetter = 'a';
    break;

  /* voeis */
  case 4516:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* voemo */
  case 4517:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'e';
    fourthLetter = 'm';
    fifthLetter = 'o';
    break;

  /* vogal */
  case 4518:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 'l';
    break;

  /* volta */
  case 4519:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* volte */
  case 4520:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'e';
    break;

  /* volto */
  case 4521:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* volva */
  case 4522:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* volve */
  case 4523:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'e';
    break;

  /* volvi */
  case 4524:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'i';
    break;

  /* volvo */
  case 4525:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'o';
    break;

  /* voraz */
  case 4526:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'z';
    break;

  /* vossa */
  case 4527:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'a';
    break;

  /* vosso */
  case 4528:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 's';
    fourthLetter = 's';
    fifthLetter = 'o';
    break;

  /* votai */
  case 4529:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* votam */
  case 4530:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* votar */
  case 4531:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* votas */
  case 4532:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* votei */
  case 4533:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* votem */
  case 4534:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* votes */
  case 4535:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* votos */
  case 4536:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* votou */
  case 4537:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 't';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* vozes */
  case 4538:
    firstLetter = 'v';
    secondLetter = 'o';
    thirdLetter = 'z';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* vulgo */
  case 4539:
    firstLetter = 'v';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* vulto */
  case 4540:
    firstLetter = 'v';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* vulva */
  case 4541:
    firstLetter = 'v';
    secondLetter = 'u';
    thirdLetter = 'l';
    fourthLetter = 'v';
    fifthLetter = 'a';
    break;

  /* xales */
  case 4542:
    firstLetter = 'x';
    secondLetter = 'a';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* xelim */
  case 4543:
    firstLetter = 'x';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'i';
    fifthLetter = 'm';
    break;

  /* xeque */
  case 4544:
    firstLetter = 'x';
    secondLetter = 'e';
    thirdLetter = 'q';
    fourthLetter = 'u';
    fifthLetter = 'e';
    break;

  /* xerox */
  case 4545:
    firstLetter = 'x';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'x';
    break;

  /* xiita */
  case 4546:
    firstLetter = 'x';
    secondLetter = 'i';
    thirdLetter = 'i';
    fourthLetter = 't';
    fifthLetter = 'a';
    break;

  /* xinga */
  case 4547:
    firstLetter = 'x';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* xingo */
  case 4548:
    firstLetter = 'x';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* xisto */
  case 4549:
    firstLetter = 'x';
    secondLetter = 'i';
    thirdLetter = 's';
    fourthLetter = 't';
    fifthLetter = 'o';
    break;

  /* xucra */
  case 4550:
    firstLetter = 'x';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* xucro */
  case 4551:
    firstLetter = 'x';
    secondLetter = 'u';
    thirdLetter = 'c';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;

  /* zagas */
  case 4552:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'g';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* zanga */
  case 4553:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'a';
    break;

  /* zango */
  case 4554:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'g';
    fifthLetter = 'o';
    break;

  /* zanza */
  case 4555:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* zanze */
  case 4556:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'e';
    break;

  /* zanzo */
  case 4557:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* zarpa */
  case 4558:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'a';
    break;

  /* zarpe */
  case 4559:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'e';
    break;

  /* zarpo */
  case 4560:
    firstLetter = 'z';
    secondLetter = 'a';
    thirdLetter = 'r';
    fourthLetter = 'p';
    fifthLetter = 'o';
    break;

  /* zebra */
  case 4561:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'b';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* zelai */
  case 4562:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* zelam */
  case 4563:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* zelar */
  case 4564:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* zelas */
  case 4565:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* zelei */
  case 4566:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* zelem */
  case 4567:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* zeles */
  case 4568:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* zelou */
  case 4569:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'l';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* zerai */
  case 4570:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'i';
    break;

  /* zeram */
  case 4571:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* zerar */
  case 4572:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 'r';
    break;

  /* zeras */
  case 4573:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* zerei */
  case 4574:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'i';
    break;

  /* zerem */
  case 4575:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* zeres */
  case 4576:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* zeros */
  case 4577:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 's';
    break;

  /* zerou */
  case 4578:
    firstLetter = 'z';
    secondLetter = 'e';
    thirdLetter = 'r';
    fourthLetter = 'o';
    fifthLetter = 'u';
    break;

  /* zinco */
  case 4579:
    firstLetter = 'z';
    secondLetter = 'i';
    thirdLetter = 'n';
    fourthLetter = 'c';
    fifthLetter = 'o';
    break;

  /* zomba */
  case 4580:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* zombe */
  case 4581:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* zombo */
  case 4582:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* zonas */
  case 4583:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* zonza */
  case 4584:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'a';
    break;

  /* zonzo */
  case 4585:
    firstLetter = 'z';
    secondLetter = 'o';
    thirdLetter = 'n';
    fourthLetter = 'z';
    fifthLetter = 'o';
    break;

  /* zumba */
  case 4586:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'a';
    break;

  /* zumbe */
  case 4587:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'e';
    break;

  /* zumbi */
  case 4588:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'i';
    break;

  /* zumbo */
  case 4589:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'm';
    fourthLetter = 'b';
    fifthLetter = 'o';
    break;

  /* zunam */
  case 4590:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 'm';
    break;

  /* zunas */
  case 4591:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'a';
    fifthLetter = 's';
    break;

  /* zunem */
  case 4592:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 'm';
    break;

  /* zunes */
  case 4593:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'e';
    fifthLetter = 's';
    break;

  /* zunia */
  case 4594:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'a';
    break;

  /* zunir */
  case 4595:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'r';
    break;

  /* zunis */
  case 4596:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 's';
    break;

  /* zuniu */
  case 4597:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'n';
    fourthLetter = 'i';
    fifthLetter = 'u';
    break;

  /* zurra */
  case 4598:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'a';
    break;

  /* zurre */
  case 4599:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'e';
    break;

  /* zurro */
  case 4600:
    firstLetter = 'z';
    secondLetter = 'u';
    thirdLetter = 'r';
    fourthLetter = 'r';
    fifthLetter = 'o';
    break;
  }
}