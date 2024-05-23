#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

#define TAMANHO_LISTA 4601

// Letras da palavra do dia
char primeiraLetraPalavraDia, segundaLetraPalavraDia, terceiraLetraPalavraDia, quartaLetraPalavraDia, quintaLetraPalavraDia;
// Letras da palavra digitada
char primeiraLetraPalavraDigitada = 0, segundaLetraPalavraDigitada = 0, terceiraLetraPalavraDigitada = 0, quartaLetraPalavraDigitada = 0, quintaLetraPalavraDigitada = 0;

void definePalavraDoDia(int randomNumber);
char converterParaCaixaBaixa(char caractere);
bool eValidaPalavra();
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
  int modo = 1;
  int tentativas = 0;
  bool jogoTerminou = false, venceu = false;

  std::cout<<"===================================================\n";
  std::cout<<"TERMO\n";
  std::cout<<"===================================================n\n";
  do{
    std::cout<<"Digite o número corresponde ao modo :\n";
    std::cout<<"1 - Uma palavra\n";
    std::cout<<"2 - Duas palavras\n\n";
    std::cin>>modo;
  }while(!((modo == 1) || (modo == 2)));
    std::cout<<"===================================================\n";
    std::cout<<"Legenda:\n";
    std::cout<<"N: letra não existe na palavra.\n";
    std::cout<<"E: existe na palavra, mas está na posição errada.\n";
    std::cout<<"C: letra está na posição certa.\n";
    std::cout<<"===================================================\n\n";

  if(modo == 1){
    
    definePalavraDoDia(std::rand() % TAMANHO_LISTA);
    
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
        std::cout << "A palavra era " << primeiraLetraPalavraDia << segundaLetraPalavraDia << terceiraLetraPalavraDia << quartaLetraPalavraDia << quintaLetraPalavraDia << ".\n";
        std::cout << "Fim do Jogo. Aperte para finalizar.\n";
    }
  }else{
    std::cout<<"Em desenvolvimento\n";
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
  char lC1, lC2, lC3, lC4, lC5;

  char primeiraLetraPalavraDiaCopy =  primeiraLetraPalavraDia;
  char segundaLetraPalavraDiaCopy = segundaLetraPalavraDia;
  char terceiraLetraPalavraDiaCopy = terceiraLetraPalavraDia;
  char quartaLetraPalavraDiaCopy = quartaLetraPalavraDia;
  char quintaLetraPalavraDiaCopy = quintaLetraPalavraDia;

  if (!(primeiraLetraPalavraDigitada == primeiraLetraPalavraDiaCopy || primeiraLetraPalavraDigitada == segundaLetraPalavraDiaCopy || primeiraLetraPalavraDigitada == terceiraLetraPalavraDiaCopy || primeiraLetraPalavraDigitada == quartaLetraPalavraDiaCopy || primeiraLetraPalavraDigitada == quintaLetraPalavraDiaCopy))
    lC1 = 'N';
  else{
    if (primeiraLetraPalavraDigitada == primeiraLetraPalavraDiaCopy){
      lC1 = 'C';
      primeiraLetraPalavraDiaCopy = '.';
    }
    else{
      lC1 = 'E';
    
      if (primeiraLetraPalavraDigitada == segundaLetraPalavraDiaCopy)
        segundaLetraPalavraDiaCopy = '.';
      else if (primeiraLetraPalavraDigitada == terceiraLetraPalavraDiaCopy)
            terceiraLetraPalavraDiaCopy = '.';
          else if (primeiraLetraPalavraDigitada == quartaLetraPalavraDiaCopy)
                quartaLetraPalavraDiaCopy = '.';
              else quintaLetraPalavraDiaCopy = '.';
    }
  }

  if (!(segundaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy || segundaLetraPalavraDigitada == segundaLetraPalavraDiaCopy || segundaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy || segundaLetraPalavraDigitada == quartaLetraPalavraDiaCopy || segundaLetraPalavraDigitada == quintaLetraPalavraDiaCopy))
    lC2 = 'N';
  else{
    if (segundaLetraPalavraDigitada == segundaLetraPalavraDiaCopy){
      lC2 = 'C';
      segundaLetraPalavraDiaCopy = '.';
    }
    else{
      lC2 = 'E';

      if (segundaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy)
        primeiraLetraPalavraDiaCopy = '.';      
      else if (segundaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy)
            terceiraLetraPalavraDiaCopy = '.';
          else if (segundaLetraPalavraDigitada == quartaLetraPalavraDiaCopy)
                quartaLetraPalavraDiaCopy = '.';
              else quintaLetraPalavraDiaCopy = '.';
    }
  }

  if (!(terceiraLetraPalavraDigitada == primeiraLetraPalavraDiaCopy || terceiraLetraPalavraDigitada == segundaLetraPalavraDiaCopy || terceiraLetraPalavraDigitada == terceiraLetraPalavraDiaCopy || terceiraLetraPalavraDigitada == quartaLetraPalavraDiaCopy || terceiraLetraPalavraDigitada == quintaLetraPalavraDiaCopy))
    lC3 = 'N';
  else{
    if (terceiraLetraPalavraDigitada == terceiraLetraPalavraDiaCopy){
      lC3 = 'C';
      terceiraLetraPalavraDiaCopy = '.';
    }
    else{
      lC3 = 'E';

      if (terceiraLetraPalavraDigitada == primeiraLetraPalavraDiaCopy)
        primeiraLetraPalavraDiaCopy = '.';
      else if (terceiraLetraPalavraDigitada == segundaLetraPalavraDiaCopy)
            segundaLetraPalavraDiaCopy = '.';
          else if (terceiraLetraPalavraDigitada == quartaLetraPalavraDiaCopy)
                quartaLetraPalavraDiaCopy = '.';
              else quintaLetraPalavraDiaCopy = '.';
    }
  }

  if (!(quartaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy || quartaLetraPalavraDigitada == segundaLetraPalavraDiaCopy || quartaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy || quartaLetraPalavraDigitada == quartaLetraPalavraDiaCopy || quartaLetraPalavraDigitada == quintaLetraPalavraDiaCopy))
    lC4 = 'N';
  else{
    if (quartaLetraPalavraDigitada == quartaLetraPalavraDiaCopy){
      lC4 = 'C';
      quartaLetraPalavraDiaCopy = '.';
    }
    else{
      lC4 = 'E';
    
      if (quartaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy)
        primeiraLetraPalavraDiaCopy = '.';
      else if (quartaLetraPalavraDigitada == segundaLetraPalavraDiaCopy)
            segundaLetraPalavraDiaCopy = '.';
          else if (quartaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy)
                terceiraLetraPalavraDiaCopy = '.';
              else quintaLetraPalavraDiaCopy = '.';
    }
  }

  if (!(quintaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy || quintaLetraPalavraDigitada == segundaLetraPalavraDiaCopy || quintaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy || quintaLetraPalavraDigitada == quartaLetraPalavraDiaCopy || quintaLetraPalavraDigitada == quintaLetraPalavraDiaCopy))
    lC5 = 'N';
  else{
    if (quintaLetraPalavraDigitada == quintaLetraPalavraDiaCopy){
      lC5 = 'C';
      quintaLetraPalavraDiaCopy = '.';
    }
    else{
      lC5 = 'E';
    
      if (quintaLetraPalavraDigitada == primeiraLetraPalavraDiaCopy)
        primeiraLetraPalavraDiaCopy = '.';
      else if (quintaLetraPalavraDigitada == segundaLetraPalavraDiaCopy)
            segundaLetraPalavraDiaCopy = '.';
          else if (quintaLetraPalavraDigitada == terceiraLetraPalavraDiaCopy)
                terceiraLetraPalavraDiaCopy = '.';
              else quartaLetraPalavraDiaCopy = '.';
    }
  }

  std::cout << lC1 << lC2 << lC3 << lC4 << lC5 << "\n\n";

  return lC1 == 'C' && lC2 == 'C' && lC3 == 'C' && lC4 == 'C' && lC5 == 'C';
}

void getPalavra()
{
  bool palavraValida = false;

  do{
    std::cin >> std::setw(6) >> primeiraLetraPalavraDigitada >> segundaLetraPalavraDigitada >> terceiraLetraPalavraDigitada >> quartaLetraPalavraDigitada >> quintaLetraPalavraDigitada;

    if (!(palavraValida = eValidaPalavra()))
      std::cout << "A palavra deve ter exatamente 5 caracteres alfabéticos (minúsculos).\n";

  } while (!palavraValida);
}

bool eValidaPalavra(){
    if(((primeiraLetraPalavraDigitada >= 'A' && primeiraLetraPalavraDigitada <= 'Z') || (primeiraLetraPalavraDigitada >= 'a' && primeiraLetraPalavraDigitada <= 'z')) && ((segundaLetraPalavraDigitada >= 'A' && segundaLetraPalavraDigitada <= 'Z') || (segundaLetraPalavraDigitada >= 'a' && segundaLetraPalavraDigitada <= 'z')) && ((terceiraLetraPalavraDigitada >= 'A' && terceiraLetraPalavraDigitada <= 'Z') || (terceiraLetraPalavraDigitada >= 'a' && terceiraLetraPalavraDigitada <= 'z')) && ((quartaLetraPalavraDigitada >= 'A' && quartaLetraPalavraDigitada <= 'Z') || (quartaLetraPalavraDigitada >= 'a' && quartaLetraPalavraDigitada <='z')) && ((quintaLetraPalavraDigitada >= 'A' && quintaLetraPalavraDigitada <= 'Z') || ((quintaLetraPalavraDigitada >= 'a' && quintaLetraPalavraDigitada <= 'z')))){
        primeiraLetraPalavraDigitada = converterParaCaixaBaixa(primeiraLetraPalavraDigitada);
        segundaLetraPalavraDigitada = converterParaCaixaBaixa(segundaLetraPalavraDigitada);
        terceiraLetraPalavraDigitada = converterParaCaixaBaixa(terceiraLetraPalavraDigitada);
        quartaLetraPalavraDigitada =  converterParaCaixaBaixa(quartaLetraPalavraDigitada);
        quintaLetraPalavraDigitada = converterParaCaixaBaixa(quintaLetraPalavraDigitada);
        return true;
    }
    return false;
}

char converterParaCaixaBaixa(char caractere){
    if(caractere >= 'A' && caractere <= 'Z'){
        return caractere + ('a' - 'A');
    }
    return caractere;
}

void definePalavraDoDia(int randomNumber)
{
  switch (randomNumber)
  {
    /* agimo */
  case 0:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* agira */
  case 1:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* agita */
  case 2:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* agite */
  case 3:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* agito */
  case 4:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* agora */
  case 5:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* aguai */
  case 6:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* aguam */
  case 7:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* aguar */
  case 8:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* aguas */
  case 9:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* aguce */
  case 10:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* aguda */
  case 11:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* agudo */
  case 12:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* aguei */
  case 13:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* aguem */
  case 14:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* agues */
  case 15:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* aguou */
  case 16:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ainda */
  case 17:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* aires */
  case 18:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ajais */
  case 19:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ajamo */
  case 20:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ajuda */
  case 21:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* ajude */
  case 22:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* ajudo */
  case 23:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* alado */
  case 24:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* alago */
  case 25:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* alcei */
  case 26:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* alcem */
  case 27:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* alces */
  case 28:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* alega */
  case 29:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* alego */
  case 30:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* algas */
  case 31:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* algoz */
  case 32:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'z';
    break;

  /* algum */
  case 33:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'm';
    break;

  /* alhos */
  case 34:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* aliai */
  case 35:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* aliam */
  case 36:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* aliar */
  case 37:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* alias */
  case 38:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* aliei */
  case 39:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* aliem */
  case 40:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* alies */
  case 41:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* alija */
  case 42:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* alije */
  case 43:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* alijo */
  case 44:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* aliou */
  case 45:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* alisa */
  case 46:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* alise */
  case 47:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* aliso */
  case 48:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* almas */
  case 49:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* aloca */
  case 50:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* aloco */
  case 51:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* aloja */
  case 52:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* aloje */
  case 53:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* alojo */
  case 54:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* altar */
  case 55:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* altas */
  case 56:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* altos */
  case 57:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* aluda */
  case 58:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* alude */
  case 59:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* aludi */
  case 60:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* aludo */
  case 61:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* aluga */
  case 62:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* alugo */
  case 63:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* aluna */
  case 64:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* aluno */
  case 65:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* alvas */
  case 66:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* alves */
  case 67:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* alvor */
  case 68:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* alvos */
  case 69:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* amado */
  case 70:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* amais */
  case 71:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* amamo */
  case 72:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* amaro */
  case 73:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ambas */
  case 74:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ambos */
  case 75:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ameba */
  case 76:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* ameia */
  case 77:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ameis */
  case 78:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* amemo */
  case 79:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* amena */
  case 80:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* ameno */
  case 81:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* amido */
  case 82:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* amiga */
  case 83:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* amigo */
  case 84:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* amima */
  case 85:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* amime */
  case 86:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* amimo */
  case 87:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* amola */
  case 88:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* amole */
  case 89:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* amolo */
  case 90:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* amora */
  case 91:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ampla */
  case 92:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* amplo */
  case 93:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* anais */
  case 94:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ancas */
  case 95:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* andai */
  case 96:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* andam */
  case 97:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* andar */
  case 98:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* andas */
  case 99:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* andei */
  case 100:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* andem */
  case 101:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* andes */
  case 102:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* andor */
  case 103:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* andou */
  case 104:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* anela */
  case 105:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* anele */
  case 106:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* anelo */
  case 107:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* anexa */
  case 108:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* anexe */
  case 109:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* anexo */
  case 110:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* anglo */
  case 111:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* angra */
  case 112:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* anima */
  case 113:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* anime */
  case 114:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* animo */
  case 115:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* anjos */
  case 116:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* anota */
  case 117:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* anote */
  case 118:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* anoto */
  case 119:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* antas */
  case 120:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* antes */
  case 121:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* antro */
  case 122:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* anual */
  case 123:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* anuam */
  case 124:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* anuas */
  case 125:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* anuem */
  case 126:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* anuir */
  case 127:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* anuis */
  case 128:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* anuiu */
  case 129:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* anula */
  case 130:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* anule */
  case 131:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* anulo */
  case 132:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* anzol */
  case 133:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* aonde */
  case 134:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* aorta */
  case 135:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* apago */
  case 136:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* apare */
  case 137:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* aparo */
  case 138:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* apeai */
  case 139:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* apear */
  case 140:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* apeei */
  case 141:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* apega */
  case 142:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* apego */
  case 143:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* apeia */
  case 144:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* apeie */
  case 145:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* apeio */
  case 146:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* apela */
  case 147:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* apele */
  case 148:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* apelo */
  case 149:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* apena */
  case 150:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* apene */
  case 151:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* apeno */
  case 152:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* apeou */
  case 153:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* apita */
  case 154:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* apite */
  case 155:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* apito */
  case 156:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* apoio */
  case 157:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* apolo */
  case 158:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* aptas */
  case 159:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* aptos */
  case 160:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* apura */
  case 161:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* apure */
  case 162:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* apuro */
  case 163:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* arado */
  case 164:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* arais */
  case 165:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* arame */
  case 166:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* aramo */
  case 167:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* arcai */
  case 168:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* arcam */
  case 169:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* arcar */
  case 170:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* arcas */
  case 171:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* arcos */
  case 172:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* arcou */
  case 173:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ardam */
  case 174:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ardas */
  case 175:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ardei */
  case 176:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ardem */
  case 177:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* arder */
  case 178:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* ardes */
  case 179:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ardeu */
  case 180:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* ardia */
  case 181:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ardil */
  case 182:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* ardis */
  case 183:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ardor */
  case 184:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* areal */
  case 185:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* areia */
  case 186:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* areis */
  case 187:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* areja */
  case 188:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* areje */
  case 189:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* arejo */
  case 190:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* aremo */
  case 191:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* arena */
  case 192:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* arfai */
  case 193:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* arfam */
  case 194:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* arfar */
  case 195:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* arfas */
  case 196:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* arfei */
  case 197:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* arfem */
  case 198:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* arfes */
  case 199:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* arfou */
  case 200:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* argua */
  case 201:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* argui */
  case 202:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* arguo */
  case 203:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* armai */
  case 204:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* armam */
  case 205:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* armar */
  case 206:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* armas */
  case 207:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* armei */
  case 208:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* armem */
  case 209:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* armes */
  case 210:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* armou */
  case 211:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* aroma */
  case 212:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* arpoa */
  case 213:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* arpoe */
  case 214:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* arque */
  case 215:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* arria */
  case 216:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* arrie */
  case 217:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* arrio */
  case 218:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* arroz */
  case 219:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'z';
    break;

  /* artes */
  case 220:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* artur */
  case 221:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'r';
    break;

  /* asila */
  case 222:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* asile */
  case 223:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* asilo */
  case 224:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* asnos */
  case 225:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* aspas */
  case 226:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* assai */
  case 227:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* assam */
  case 228:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* assar */
  case 229:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* assas */
  case 230:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* assaz */
  case 231:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* assei */
  case 232:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* assem */
  case 233:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* asses */
  case 234:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* assim */
  case 235:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* assis */
  case 236:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* assoa */
  case 237:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* assoe */
  case 238:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* assou */
  case 239:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* astro */
  case 240:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ataco */
  case 241:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* atado */
  case 242:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* atais */
  case 243:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* atamo */
  case 244:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ateai */
  case 245:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* atear */
  case 246:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ateei */
  case 247:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ateia */
  case 248:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ateie */
  case 249:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* ateio */
  case 250:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* ateis */
  case 251:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* atemo */
  case 252:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ateou */
  case 253:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ateus */
  case 254:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* ateve */
  case 255:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* atice */
  case 256:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* atido */
  case 257:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* atina */
  case 258:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* atine */
  case 259:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* atino */
  case 260:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* atira */
  case 261:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* atire */
  case 262:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* atiro */
  case 263:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ativa */
  case 264:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* ative */
  case 265:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* ativo */
  case 266:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* atlas */
  case 267:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* atola */
  case 268:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* atole */
  case 269:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* atolo */
  case 270:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* atrai */
  case 271:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* atriz */
  case 272:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* atuai */
  case 273:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* atual */
  case 274:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* atuam */
  case 275:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* atuar */
  case 276:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* atuas */
  case 277:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* atuei */
  case 278:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* atuem */
  case 279:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* atues */
  case 280:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* atuns */
  case 281:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 's';
    break;

  /* atuou */
  case 282:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* atura */
  case 283:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ature */
  case 284:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* aturo */
  case 285:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* audaz */
  case 286:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* aulas */
  case 287:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* auras */
  case 288:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* autor */
  case 289:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* autos */
  case 290:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* autua */
  case 291:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* autue */
  case 292:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* autuo */
  case 293:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* avais */
  case 294:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* avaro */
  case 295:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* aveia */
  case 296:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* aveio */
  case 297:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* aviai */
  case 298:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* aviam */
  case 299:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* aviar */
  case 300:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* avias */
  case 301:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* aviei */
  case 302:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* aviem */
  case 303:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* avier */
  case 304:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* avies */
  case 305:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* avimo */
  case 306:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* aviou */
  case 307:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* avisa */
  case 308:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* avise */
  case 309:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* aviso */
  case 310:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* aviva */
  case 311:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* avive */
  case 312:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* avivo */
  case 313:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* axial */
  case 314:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* axila */
  case 315:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* azare */
  case 316:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* azaro */
  case 317:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* azeda */
  case 318:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* azede */
  case 319:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* azedo */
  case 320:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* azias */
  case 321:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* azoto */
  case 322:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* azuis */
  case 323:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* azula */
  case 324:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* azule */
  case 325:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* azulo */
  case 326:
    primeiraLetraPalavraDia = 'a';
    segundaLetraPalavraDia = 'z';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* babai */
  case 327:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* babam */
  case 328:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* babar */
  case 329:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* babas */
  case 330:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* babei */
  case 331:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* babem */
  case 332:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* babes */
  case 333:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* babou */
  case 334:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* bacia */
  case 335:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* bafos */
  case 336:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bagas */
  case 337:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bagos */
  case 338:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bahia */
  case 339:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* baias */
  case 340:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* baila */
  case 341:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* baile */
  case 342:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* bailo */
  case 343:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* baita */
  case 344:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* baixa */
  case 345:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* baixe */
  case 346:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* baixo */
  case 347:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* balam */
  case 348:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* balas */
  case 349:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* balde */
  case 350:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* balem */
  case 351:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* bales */
  case 352:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* balia */
  case 353:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* balir */
  case 354:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* balis */
  case 355:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* baliu */
  case 356:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* balsa */
  case 357:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* bamba */
  case 358:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* bambo */
  case 359:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* bambu */
  case 360:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'u';
    break;

  /* banal */
  case 361:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* banca */
  case 362:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* banco */
  case 363:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* banda */
  case 364:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* bando */
  case 365:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* banem */
  case 366:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* banes */
  case 367:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* banha */
  case 368:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* banhe */
  case 369:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* banho */
  case 370:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* bania */
  case 371:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* banir */
  case 372:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* banis */
  case 373:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* baniu */
  case 374:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* banjo */
  case 375:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* baque */
  case 376:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* barba */
  case 377:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* barca */
  case 378:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* barco */
  case 379:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* bardo */
  case 380:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* bares */
  case 381:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* barra */
  case 382:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* barre */
  case 383:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* barro */
  case 384:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* bases */
  case 385:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* basta */
  case 386:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* baste */
  case 387:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* basto */
  case 388:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* batam */
  case 389:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* batas */
  case 390:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* batei */
  case 391:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* batel */
  case 392:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* batem */
  case 393:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* bater */
  case 394:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* bates */
  case 395:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* bateu */
  case 396:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* batia */
  case 397:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* batom */
  case 398:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'm';
    break;

  /* bauru */
  case 399:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'u';
    break;

  /* bazar */
  case 400:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* beata */
  case 401:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* beato */
  case 402:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* bebam */
  case 403:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* bebas */
  case 404:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bebei */
  case 405:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* bebem */
  case 406:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* beber */
  case 407:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* bebes */
  case 408:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* bebeu */
  case 409:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* bebia */
  case 410:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* becas */
  case 411:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* becos */
  case 412:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* beija */
  case 413:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* beije */
  case 414:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* beijo */
  case 415:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* beira */
  case 416:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* beire */
  case 417:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* beiro */
  case 418:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* belas */
  case 419:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* belga */
  case 420:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* belos */
  case 421:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bemol */
  case 422:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* benta */
  case 423:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* bento */
  case 424:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* benza */
  case 425:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* benze */
  case 426:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* benzi */
  case 427:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'i';
    break;

  /* benzo */
  case 428:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* beque */
  case 429:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* berna */
  case 430:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* berra */
  case 431:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* berre */
  case 432:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* berro */
  case 433:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* besta */
  case 434:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* bicai */
  case 435:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* bicam */
  case 436:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* bicar */
  case 437:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* bicas */
  case 438:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bicha */
  case 439:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* bicho */
  case 440:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* bicos */
  case 441:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bicou */
  case 442:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* biela */
  case 443:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* bigas */
  case 444:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bingo */
  case 445:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* bique */
  case 446:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* birra */
  case 447:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* bispo */
  case 448:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* blefa */
  case 449:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* blefe */
  case 450:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* blefo */
  case 451:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* bloco */
  case 452:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* blusa */
  case 453:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* boate */
  case 454:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* boato */
  case 455:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* bobas */
  case 456:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bobos */
  case 457:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bocal */
  case 458:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* bocas */
  case 459:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bocha */
  case 460:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* bodas */
  case 461:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bodes */
  case 462:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* boiai */
  case 463:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* boiar */
  case 464:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* boiei */
  case 465:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* boina */
  case 466:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* boiou */
  case 467:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* bolai */
  case 468:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* bolam */
  case 469:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* bolar */
  case 470:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* bolas */
  case 471:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* boldo */
  case 472:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* bolei */
  case 473:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* bolem */
  case 474:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* boles */
  case 475:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* bolha */
  case 476:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* bolos */
  case 477:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* bolou */
  case 478:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* bolsa */
  case 479:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* bolso */
  case 480:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* bomba */
  case 481:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* bonde */
  case 482:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* borda */
  case 483:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* borde */
  case 484:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* bordo */
  case 485:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* borra */
  case 486:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* borre */
  case 487:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* borro */
  case 488:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* bossa */
  case 489:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* bosta */
  case 490:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* botai */
  case 491:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* botam */
  case 492:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* botar */
  case 493:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* botas */
  case 494:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* botei */
  case 495:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* botem */
  case 496:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* botes */
  case 497:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* botou */
  case 498:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* braba */
  case 499:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* brabo */
  case 500:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* brada */
  case 501:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* brade */
  case 502:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* brado */
  case 503:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* braga */
  case 504:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* brama */
  case 505:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* brame */
  case 506:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* brami */
  case 507:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* bramo */
  case 508:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* brasa */
  case 509:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* brava */
  case 510:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* bravo */
  case 511:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* breca */
  case 512:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* breco */
  case 513:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* brejo */
  case 514:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* breve */
  case 515:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* brida */
  case 516:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* briga */
  case 517:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* brigo */
  case 518:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* brins */
  case 519:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 's';
    break;

  /* brios */
  case 520:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* brisa */
  case 521:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* brita */
  case 522:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* brito */
  case 523:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* broas */
  case 524:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* broca */
  case 525:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* broco */
  case 526:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* bromo */
  case 527:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* brota */
  case 528:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* brote */
  case 529:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* broto */
  case 530:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* bruma */
  case 531:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* bruta */
  case 532:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* bruto */
  case 533:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* bruxa */
  case 534:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* bruxo */
  case 535:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* bucal */
  case 536:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* bucha */
  case 537:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* bucho */
  case 538:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* bueno */
  case 539:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* bufai */
  case 540:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* bufam */
  case 541:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* bufar */
  case 542:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* bufas */
  case 543:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bufei */
  case 544:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* bufem */
  case 545:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* bufes */
  case 546:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* bufou */
  case 547:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* bulam */
  case 548:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* bulas */
  case 549:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* bulbo */
  case 550:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* bules */
  case 551:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* bulia */
  case 552:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* bulir */
  case 553:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* bulis */
  case 554:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* buliu */
  case 555:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* bumbo */
  case 556:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* bunda */
  case 557:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* bunde */
  case 558:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* bundo */
  case 559:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* burgo */
  case 560:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* burla */
  case 561:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* burle */
  case 562:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* burlo */
  case 563:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* burra */
  case 564:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* burro */
  case 565:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* busca */
  case 566:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* busco */
  case 567:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* busto */
  case 568:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* buxos */
  case 569:
    primeiraLetraPalavraDia = 'b';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cabei */
  case 570:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cabem */
  case 571:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* caber */
  case 572:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* cabes */
  case 573:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cabia */
  case 574:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* cabos */
  case 575:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cabra */
  case 576:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cacas */
  case 577:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cacei */
  case 578:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cacem */
  case 579:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* caces */
  case 580:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cacho */
  case 581:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* cacos */
  case 582:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cacto */
  case 583:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cagai */
  case 584:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* cagam */
  case 585:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cagar */
  case 586:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* cagas */
  case 587:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cagou */
  case 588:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* cague */
  case 589:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* caiai */
  case 590:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* caiam */
  case 591:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* caiar */
  case 592:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* caias */
  case 593:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* caiba */
  case 594:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* caibo */
  case 595:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* caido */
  case 596:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* caiei */
  case 597:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* caiem */
  case 598:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* caies */
  case 599:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* caiou */
  case 600:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* cairo */
  case 601:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* caixa */
  case 602:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* calai */
  case 603:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* calam */
  case 604:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* calar */
  case 605:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* calas */
  case 606:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* calca */
  case 607:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* calce */
  case 608:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* calco */
  case 609:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* calda */
  case 610:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* caldo */
  case 611:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* calei */
  case 612:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* calem */
  case 613:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cales */
  case 614:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* calha */
  case 615:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* calhe */
  case 616:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* calho */
  case 617:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* calma */
  case 618:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* calmo */
  case 619:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* calor */
  case 620:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* calos */
  case 621:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* calou */
  case 622:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* calva */
  case 623:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* calvo */
  case 624:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* camas */
  case 625:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* campo */
  case 626:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* canal */
  case 627:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* canas */
  case 628:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* canga */
  case 629:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* canja */
  case 630:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* canoa */
  case 631:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* canos */
  case 632:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cansa */
  case 633:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* canse */
  case 634:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* canso */
  case 635:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* canta */
  case 636:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cante */
  case 637:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* canto */
  case 638:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* capai */
  case 639:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* capam */
  case 640:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* capar */
  case 641:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* capas */
  case 642:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* capaz */
  case 643:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* capei */
  case 644:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* capem */
  case 645:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* capes */
  case 646:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* capim */
  case 647:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* capou */
  case 648:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* capta */
  case 649:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* capte */
  case 650:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* capto */
  case 651:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* caput */
  case 652:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 't';
    break;

  /* capuz */
  case 653:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'z';
    break;

  /* caras */
  case 654:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cardo */
  case 655:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* carga */
  case 656:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* cargo */
  case 657:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* carmo */
  case 658:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* carne */
  case 659:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* caros */
  case 660:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* carpa */
  case 661:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* carpe */
  case 662:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* carpi */
  case 663:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'i';
    break;

  /* carro */
  case 664:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* carta */
  case 665:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* casai */
  case 666:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* casal */
  case 667:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* casam */
  case 668:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* casar */
  case 669:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* casas */
  case 670:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* casca */
  case 671:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* casco */
  case 672:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* casei */
  case 673:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* casem */
  case 674:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cases */
  case 675:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* casos */
  case 676:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* casou */
  case 677:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* caspa */
  case 678:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* cassa */
  case 679:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* casse */
  case 680:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* casso */
  case 681:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* casta */
  case 682:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* casto */
  case 683:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* catai */
  case 684:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* catam */
  case 685:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* catar */
  case 686:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* catas */
  case 687:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* catei */
  case 688:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* catem */
  case 689:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cates */
  case 690:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* catou */
  case 691:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* catre */
  case 692:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* cauda */
  case 693:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* caule */
  case 694:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* causa */
  case 695:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* cause */
  case 696:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* causo */
  case 697:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* cauta */
  case 698:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cauto */
  case 699:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cavai */
  case 700:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* cavam */
  case 701:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cavar */
  case 702:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* cavas */
  case 703:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cavei */
  case 704:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cavem */
  case 705:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* caves */
  case 706:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cavia */
  case 707:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* cavie */
  case 708:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* cavio */
  case 709:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* cavou */
  case 710:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ceado */
  case 711:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* ceais */
  case 712:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ceamo */
  case 713:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ceara */
  case 714:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ceava */
  case 715:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* cedam */
  case 716:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cedas */
  case 717:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cedei */
  case 718:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cedem */
  case 719:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ceder */
  case 720:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* cedes */
  case 721:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cedeu */
  case 722:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* cedia */
  case 723:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* cedro */
  case 724:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ceeis */
  case 725:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ceemo */
  case 726:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* cegai */
  case 727:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* cegam */
  case 728:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cegar */
  case 729:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* cegas */
  case 730:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cegos */
  case 731:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cegou */
  case 732:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* cegue */
  case 733:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* ceiam */
  case 734:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ceias */
  case 735:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ceiem */
  case 736:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ceies */
  case 737:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ceifa */
  case 738:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* ceife */
  case 739:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* ceifo */
  case 740:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* celas */
  case 741:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* celta */
  case 742:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cenas */
  case 743:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* censo */
  case 744:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* cento */
  case 745:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ceras */
  case 746:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cerca */
  case 747:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* cerco */
  case 748:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* cerda */
  case 749:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* cerne */
  case 750:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* cerni */
  case 751:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'i';
    break;

  /* cerol */
  case 752:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* cerra */
  case 753:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cerre */
  case 754:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* cerro */
  case 755:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* certa */
  case 756:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* certo */
  case 757:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cervo */
  case 758:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* cessa */
  case 759:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* cesse */
  case 760:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* cesso */
  case 761:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* cesta */
  case 762:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cesto */
  case 763:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cetim */
  case 764:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* cetro */
  case 765:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* chaga */
  case 766:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* chago */
  case 767:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* chale */
  case 768:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* chama */
  case 769:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* chame */
  case 770:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* chamo */
  case 771:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* chapa */
  case 772:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* chata */
  case 773:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* chato */
  case 774:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* chave */
  case 775:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* checa */
  case 776:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* checo */
  case 777:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* chefa */
  case 778:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* chefe */
  case 779:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* chega */
  case 780:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* chego */
  case 781:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* cheia */
  case 782:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* cheio */
  case 783:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* chiai */
  case 784:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* chiam */
  case 785:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* chiar */
  case 786:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* chias */
  case 787:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* chica */
  case 788:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* chico */
  case 789:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* chiei */
  case 790:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* chiem */
  case 791:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* chies */
  case 792:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* china */
  case 793:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* chiou */
  case 794:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* choca */
  case 795:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* choco */
  case 796:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* chora */
  case 797:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* chore */
  case 798:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* choro */
  case 799:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* chova */
  case 800:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* chove */
  case 801:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* chovi */
  case 802:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* chovo */
  case 803:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* chupa */
  case 804:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* chupe */
  case 805:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* chupo */
  case 806:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* chuta */
  case 807:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* chute */
  case 808:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* chuto */
  case 809:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* chuva */
  case 810:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* ciclo */
  case 811:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* cidra */
  case 812:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cifra */
  case 813:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cifre */
  case 814:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* cifro */
  case 815:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* cinco */
  case 816:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* cinda */
  case 817:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* cinde */
  case 818:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* cindi */
  case 819:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* cindo */
  case 820:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* cinge */
  case 821:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* cingi */
  case 822:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* cinja */
  case 823:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* cinjo */
  case 824:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* cinta */
  case 825:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cinto */
  case 826:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cinza */
  case 827:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* ciosa */
  case 828:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* cioso */
  case 829:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* circo */
  case 830:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* cisca */
  case 831:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* cisco */
  case 832:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* cisma */
  case 833:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* cisme */
  case 834:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* cismo */
  case 835:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* cisne */
  case 836:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* citai */
  case 837:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* citam */
  case 838:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* citar */
  case 839:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* citas */
  case 840:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* citei */
  case 841:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* citem */
  case 842:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cites */
  case 843:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* citou */
  case 844:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* civil */
  case 845:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* civis */
  case 846:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* clama */
  case 847:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* clame */
  case 848:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* clamo */
  case 849:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* clara */
  case 850:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* claro */
  case 851:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* clava */
  case 852:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* clero */
  case 853:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* clima */
  case 854:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* clips */
  case 855:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 's';
    break;

  /* clone */
  case 856:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* cloro */
  case 857:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* clube */
  case 858:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* coada */
  case 859:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* coado */
  case 860:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* coagi */
  case 861:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* coais */
  case 862:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* coaja */
  case 863:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* coajo */
  case 864:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* coamo */
  case 865:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* coara */
  case 866:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* coava */
  case 867:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* coaxa */
  case 868:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* coaxe */
  case 869:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* coaxo */
  case 870:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* cobra */
  case 871:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cobre */
  case 872:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* cobri */
  case 873:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* cobro */
  case 874:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* cocal */
  case 875:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* cocei */
  case 876:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cocem */
  case 877:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* coces */
  case 878:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cocho */
  case 879:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* cocos */
  case 880:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* coege */
  case 881:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* coeis */
  case 882:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* coemo */
  case 883:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* coesa */
  case 884:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* coeso */
  case 885:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* coeva */
  case 886:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* coevo */
  case 887:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* cofre */
  case 888:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* coibi */
  case 889:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'i';
    break;

  /* coice */
  case 890:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* coifa */
  case 891:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* coisa */
  case 892:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* coito */
  case 893:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* colai */
  case 894:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* colam */
  case 895:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* colar */
  case 896:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* colas */
  case 897:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* colei */
  case 898:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* colem */
  case 899:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* coles */
  case 900:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* colha */
  case 901:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* colhe */
  case 902:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* colhi */
  case 903:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'i';
    break;

  /* colho */
  case 904:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* colou */
  case 905:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* comam */
  case 906:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* comas */
  case 907:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* comei */
  case 908:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* comem */
  case 909:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* comer */
  case 910:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* comes */
  case 911:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* comeu */
  case 912:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* comia */
  case 913:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* comum */
  case 914:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'm';
    break;

  /* conde */
  case 915:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* cones */
  case 916:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* conta */
  case 917:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* conte */
  case 918:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* conto */
  case 919:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* copas */
  case 920:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* copia */
  case 921:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* copie */
  case 922:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* copio */
  case 923:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* copos */
  case 924:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* corai */
  case 925:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* coral */
  case 926:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* coram */
  case 927:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* corar */
  case 928:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* coras */
  case 929:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* corda */
  case 930:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* corei */
  case 931:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* corem */
  case 932:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cores */
  case 933:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* corja */
  case 934:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* corno */
  case 935:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* coroa */
  case 936:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* coroe */
  case 937:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* coros */
  case 938:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* corou */
  case 939:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* corpo */
  case 940:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* corra */
  case 941:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* corre */
  case 942:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* corri */
  case 943:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* corro */
  case 944:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* corta */
  case 945:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* corte */
  case 946:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* corto */
  case 947:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* corvo */
  case 948:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* cosam */
  case 949:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cosas */
  case 950:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cosei */
  case 951:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cosem */
  case 952:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* coser */
  case 953:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* coses */
  case 954:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* coseu */
  case 955:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* cosia */
  case 956:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* cosmo */
  case 957:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* cospe */
  case 958:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* costa */
  case 959:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* cotai */
  case 960:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* cotam */
  case 961:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cotar */
  case 962:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* cotas */
  case 963:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cotei */
  case 964:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cotem */
  case 965:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cotes */
  case 966:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cotou */
  case 967:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* coube */
  case 968:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* couro */
  case 969:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* couto */
  case 970:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* couve */
  case 971:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* covas */
  case 972:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* coxas */
  case 973:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* coxim */
  case 974:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* coxos */
  case 975:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cozam */
  case 976:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* cozas */
  case 977:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cozei */
  case 978:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* cozem */
  case 979:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cozer */
  case 980:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* cozes */
  case 981:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cozeu */
  case 982:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* cozia */
  case 983:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* crava */
  case 984:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* crave */
  case 985:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* cravo */
  case 986:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* crede */
  case 987:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* credo */
  case 988:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* creia */
  case 989:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* creio */
  case 990:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* crema */
  case 991:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* creme */
  case 992:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* cremo */
  case 993:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* crera */
  case 994:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* criai */
  case 995:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* criam */
  case 996:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* criar */
  case 997:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* crias */
  case 998:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* crido */
  case 999:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* criei */
  case 1000:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* criem */
  case 1001:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cries */
  case 1002:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* crime */
  case 1003:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* crina */
  case 1004:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* criou */
  case 1005:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* crise */
  case 1006:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* criva */
  case 1007:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* crive */
  case 1008:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* crivo */
  case 1009:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* croma */
  case 1010:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* crome */
  case 1011:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* cromo */
  case 1012:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* cruas */
  case 1013:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cruel */
  case 1014:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* cruza */
  case 1015:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* cruze */
  case 1016:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* cruzo */
  case 1017:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* cubas */
  case 1018:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cubos */
  case 1019:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cubra */
  case 1020:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* cubro */
  case 1021:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* cucas */
  case 1022:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cucos */
  case 1023:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cueca */
  case 1024:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* cuias */
  case 1025:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cuida */
  case 1026:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* cuide */
  case 1027:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* cuido */
  case 1028:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* cujas */
  case 1029:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* cujos */
  case 1030:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* cujus */
  case 1031:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* culpa */
  case 1032:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* culpe */
  case 1033:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* culpo */
  case 1034:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* culta */
  case 1035:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* culto */
  case 1036:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* cumes */
  case 1037:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* cunha */
  case 1038:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* cunhe */
  case 1039:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* cunho */
  case 1040:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* cupim */
  case 1041:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* cupom */
  case 1042:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'm';
    break;

  /* curai */
  case 1043:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* curam */
  case 1044:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* curar */
  case 1045:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* curas */
  case 1046:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* curei */
  case 1047:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* curem */
  case 1048:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* cures */
  case 1049:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* curou */
  case 1050:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* cursa */
  case 1051:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* curse */
  case 1052:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* curso */
  case 1053:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* curta */
  case 1054:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* curte */
  case 1055:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* curti */
  case 1056:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* curto */
  case 1057:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* curva */
  case 1058:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* curve */
  case 1059:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* curvo */
  case 1060:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* cuspa */
  case 1061:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* cuspi */
  case 1062:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'i';
    break;

  /* cuspo */
  case 1063:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* custa */
  case 1064:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* custe */
  case 1065:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* custo */
  case 1066:
    primeiraLetraPalavraDia = 'c';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* dadas */
  case 1067:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dados */
  case 1068:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* damas */
  case 1069:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* damos */
  case 1070:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* danai */
  case 1071:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* danam */
  case 1072:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* danar */
  case 1073:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* danas */
  case 1074:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dance */
  case 1075:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* dando */
  case 1076:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* danei */
  case 1077:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* danem */
  case 1078:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* danes */
  case 1079:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* danos */
  case 1080:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* danou */
  case 1081:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* dante */
  case 1082:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* daqui */
  case 1083:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* dardo */
  case 1084:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* darei */
  case 1085:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* darem */
  case 1086:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dares */
  case 1087:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* daria */
  case 1088:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* datai */
  case 1089:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* datam */
  case 1090:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* datar */
  case 1091:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* datas */
  case 1092:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* datei */
  case 1093:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* datem */
  case 1094:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dates */
  case 1095:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* datou */
  case 1096:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* davam */
  case 1097:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* davas */
  case 1098:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* decai */
  case 1099:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* dedal */
  case 1100:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* dedos */
  case 1101:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* deduz */
  case 1102:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'z';
    break;

  /* deita */
  case 1103:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* deite */
  case 1104:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* deito */
  case 1105:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* deixa */
  case 1106:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* deixe */
  case 1107:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* deixo */
  case 1108:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* delas */
  case 1109:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* deles */
  case 1110:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* delta */
  case 1111:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* demos */
  case 1112:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* densa */
  case 1113:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* denso */
  case 1114:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* dente */
  case 1115:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* depor */
  case 1116:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* depus */
  case 1117:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* deram */
  case 1118:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* deras */
  case 1119:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* derem */
  case 1120:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* deres */
  case 1121:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dermo */
  case 1122:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* desce */
  case 1123:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* desci */
  case 1124:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'i';
    break;

  /* desde */
  case 1125:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* despe */
  case 1126:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* despi */
  case 1127:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'i';
    break;

  /* dessa */
  case 1128:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* desse */
  case 1129:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* desta */
  case 1130:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* deste */
  case 1131:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* deter */
  case 1132:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* deusa */
  case 1133:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* devam */
  case 1134:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* devas */
  case 1135:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* devei */
  case 1136:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* devem */
  case 1137:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dever */
  case 1138:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* deves */
  case 1139:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* deveu */
  case 1140:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* devia */
  case 1141:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* diabo */
  case 1142:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* dicas */
  case 1143:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dieta */
  case 1144:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* digam */
  case 1145:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* digas */
  case 1146:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* digna */
  case 1147:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* digne */
  case 1148:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* digno */
  case 1149:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* dilua */
  case 1150:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* dilui */
  case 1151:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* diluo */
  case 1152:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* diodo */
  case 1153:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* dique */
  case 1154:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* direi */
  case 1155:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* diria */
  case 1156:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* disca */
  case 1157:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* disco */
  case 1158:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* disse */
  case 1159:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* disso */
  case 1160:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* dista */
  case 1161:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* diste */
  case 1162:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* disto */
  case 1163:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ditai */
  case 1164:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ditam */
  case 1165:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ditar */
  case 1166:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ditas */
  case 1167:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ditei */
  case 1168:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ditem */
  case 1169:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dites */
  case 1170:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ditos */
  case 1171:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ditou */
  case 1172:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* divas */
  case 1173:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dizei */
  case 1174:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* dizem */
  case 1175:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dizer */
  case 1176:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* dizes */
  case 1177:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dizia */
  case 1178:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* doada */
  case 1179:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* doado */
  case 1180:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* doais */
  case 1181:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* doamo */
  case 1182:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* doara */
  case 1183:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* doava */
  case 1184:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* dobra */
  case 1185:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* dobre */
  case 1186:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* dobro */
  case 1187:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* docas */
  case 1188:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* doeis */
  case 1189:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* doemo */
  case 1190:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* doera */
  case 1191:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* dogma */
  case 1192:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* doida */
  case 1193:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* doido */
  case 1194:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* domai */
  case 1195:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* domam */
  case 1196:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* domar */
  case 1197:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* domas */
  case 1198:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* domei */
  case 1199:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* domem */
  case 1200:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* domes */
  case 1201:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* domou */
  case 1202:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* donas */
  case 1203:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* donde */
  case 1204:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* donos */
  case 1205:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* dopai */
  case 1206:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* dopam */
  case 1207:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* dopar */
  case 1208:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* dopas */
  case 1209:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dopei */
  case 1210:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* dopem */
  case 1211:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dopes */
  case 1212:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dopou */
  case 1213:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* dores */
  case 1214:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dorme */
  case 1215:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* dormi */
  case 1216:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* dorso */
  case 1217:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* dosai */
  case 1218:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* dosam */
  case 1219:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* dosar */
  case 1220:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* dosas */
  case 1221:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dosei */
  case 1222:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* dosem */
  case 1223:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* doses */
  case 1224:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dosou */
  case 1225:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* dotai */
  case 1226:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* dotam */
  case 1227:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* dotar */
  case 1228:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* dotas */
  case 1229:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dotei */
  case 1230:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* dotem */
  case 1231:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dotes */
  case 1232:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* dotou */
  case 1233:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* doura */
  case 1234:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* doure */
  case 1235:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* douro */
  case 1236:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* douta */
  case 1237:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* douto */
  case 1238:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* draga */
  case 1239:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* drago */
  case 1240:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* drama */
  case 1241:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* drena */
  case 1242:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* drene */
  case 1243:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* dreno */
  case 1244:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* droga */
  case 1245:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* drogo */
  case 1246:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* duais */
  case 1247:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* dubla */
  case 1248:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* duble */
  case 1249:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* dublo */
  case 1250:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* ducha */
  case 1251:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* duela */
  case 1252:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* duele */
  case 1253:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* duelo */
  case 1254:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* dueto */
  case 1255:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* dumas */
  case 1256:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dunas */
  case 1257:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* dunga */
  case 1258:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* dupla */
  case 1259:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* duplo */
  case 1260:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* duque */
  case 1261:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* durai */
  case 1262:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* duram */
  case 1263:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* durar */
  case 1264:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* duras */
  case 1265:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* durei */
  case 1266:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* durem */
  case 1267:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* dures */
  case 1268:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* durma */
  case 1269:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* durmo */
  case 1270:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* duros */
  case 1271:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* durou */
  case 1272:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* dutos */
  case 1273:
    primeiraLetraPalavraDia = 'd';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ecoai */
  case 1274:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ecoam */
  case 1275:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ecoar */
  case 1276:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ecoas */
  case 1277:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ecoei */
  case 1278:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ecoem */
  case 1279:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ecoes */
  case 1280:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ecoou */
  case 1281:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* edema */
  case 1282:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* edita */
  case 1283:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* edite */
  case 1284:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* edito */
  case 1285:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* educa */
  case 1286:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* educo */
  case 1287:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* egito */
  case 1288:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* eiras */
  case 1289:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* eixos */
  case 1290:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ejeta */
  case 1291:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* ejeto */
  case 1292:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'j';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* elegi */
  case 1293:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* eleja */
  case 1294:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* elejo */
  case 1295:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* eleva */
  case 1296:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* elevo */
  case 1297:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* elite */
  case 1298:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* elixa */
  case 1299:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* elixe */
  case 1300:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* elixi */
  case 1301:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'i';
    break;

  /* elixo */
  case 1302:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* elmos */
  case 1303:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* emana */
  case 1304:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* emane */
  case 1305:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* emano */
  case 1306:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* emita */
  case 1307:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* emite */
  case 1308:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* emiti */
  case 1309:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* emito */
  case 1310:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* emula */
  case 1311:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* emule */
  case 1312:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* emulo */
  case 1313:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* encha */
  case 1314:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* enche */
  case 1315:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* enchi */
  case 1316:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'i';
    break;

  /* encho */
  case 1317:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* enfia */
  case 1318:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* enfie */
  case 1319:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* enfim */
  case 1320:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* enfio */
  case 1321:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* enjoa */
  case 1322:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* enjoe */
  case 1323:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* enoja */
  case 1324:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* enoje */
  case 1325:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* enojo */
  case 1326:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* entes */
  case 1327:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* entoa */
  case 1328:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* entoe */
  case 1329:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* entra */
  case 1330:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* entre */
  case 1331:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* entro */
  case 1332:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* envia */
  case 1333:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* envie */
  case 1334:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* envio */
  case 1335:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* ereta */
  case 1336:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* ereto */
  case 1337:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ergam */
  case 1338:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ergas */
  case 1339:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ergue */
  case 1340:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* ergui */
  case 1341:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* erice */
  case 1342:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* erigi */
  case 1343:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* erija */
  case 1344:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* erijo */
  case 1345:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* ermos */
  case 1346:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* eroda */
  case 1347:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* erode */
  case 1348:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* erodi */
  case 1349:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* erodo */
  case 1350:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* errai */
  case 1351:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* erram */
  case 1352:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* errar */
  case 1353:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* erras */
  case 1354:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* errei */
  case 1355:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* errem */
  case 1356:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* erres */
  case 1357:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* erros */
  case 1358:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* errou */
  case 1359:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ervas */
  case 1360:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* escoa */
  case 1361:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* escoe */
  case 1362:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* escol */
  case 1363:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* espia */
  case 1364:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* espie */
  case 1365:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* espio */
  case 1366:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* esqui */
  case 1367:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* essas */
  case 1368:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* esses */
  case 1369:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* estai */
  case 1370:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* estar */
  case 1371:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* estas */
  case 1372:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* estes */
  case 1373:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* estio */
  case 1374:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* estou */
  case 1375:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* esvai */
  case 1376:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* etano */
  case 1377:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* etapa */
  case 1378:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* eteno */
  case 1379:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* etilo */
  case 1380:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* etnia */
  case 1381:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* evada */
  case 1382:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* evade */
  case 1383:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* evadi */
  case 1384:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* evado */
  case 1385:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* evita */
  case 1386:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* evite */
  case 1387:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* evito */
  case 1388:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* evoca */
  case 1389:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* evoco */
  case 1390:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* exala */
  case 1391:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* exale */
  case 1392:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* exalo */
  case 1393:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* exame */
  case 1394:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* exara */
  case 1395:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* exare */
  case 1396:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* exaro */
  case 1397:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* exata */
  case 1398:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* exato */
  case 1399:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* exiba */
  case 1400:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* exibe */
  case 1401:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* exibi */
  case 1402:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'i';
    break;

  /* exibo */
  case 1403:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* exige */
  case 1404:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* exigi */
  case 1405:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* exija */
  case 1406:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* exijo */
  case 1407:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* exila */
  case 1408:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* exile */
  case 1409:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* exilo */
  case 1410:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* exima */
  case 1411:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* exime */
  case 1412:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* eximi */
  case 1413:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* eximo */
  case 1414:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* expia */
  case 1415:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* expie */
  case 1416:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* expio */
  case 1417:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* expor */
  case 1418:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* expus */
  case 1419:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* extra */
  case 1420:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* exuma */
  case 1421:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* exume */
  case 1422:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* exumo */
  case 1423:
    primeiraLetraPalavraDia = 'e';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* facas */
  case 1424:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* faces */
  case 1425:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* facho */
  case 1426:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* fadas */
  case 1427:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fados */
  case 1428:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* faina */
  case 1429:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* faixa */
  case 1430:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* falai */
  case 1431:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* falam */
  case 1432:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* falar */
  case 1433:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* falas */
  case 1434:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* falda */
  case 1435:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* falei */
  case 1436:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* falem */
  case 1437:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fales */
  case 1438:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* falha */
  case 1439:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* falhe */
  case 1440:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* falho */
  case 1441:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* falia */
  case 1442:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* falir */
  case 1443:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* falis */
  case 1444:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* faliu */
  case 1445:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* falou */
  case 1446:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* falsa */
  case 1447:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* falso */
  case 1448:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* falta */
  case 1449:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* falte */
  case 1450:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* falto */
  case 1451:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* famas */
  case 1452:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* farda */
  case 1453:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* fardo */
  case 1454:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* farei */
  case 1455:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* faria */
  case 1456:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* farol */
  case 1457:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* faros */
  case 1458:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* farpa */
  case 1459:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* farra */
  case 1460:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* farsa */
  case 1461:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* farta */
  case 1462:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* farte */
  case 1463:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* farto */
  case 1464:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* fases */
  case 1465:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fatal */
  case 1466:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* fatia */
  case 1467:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* fatie */
  case 1468:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* fatio */
  case 1469:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* fator */
  case 1470:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* fatos */
  case 1471:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fauna */
  case 1472:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* fauno */
  case 1473:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* favas */
  case 1474:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* favor */
  case 1475:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* favos */
  case 1476:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fazei */
  case 1477:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fazem */
  case 1478:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fazer */
  case 1479:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* fazes */
  case 1480:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fazia */
  case 1481:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* febre */
  case 1482:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* fecal */
  case 1483:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* fecha */
  case 1484:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* feche */
  case 1485:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* fecho */
  case 1486:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* fedam */
  case 1487:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fedas */
  case 1488:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fedei */
  case 1489:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fedem */
  case 1490:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* feder */
  case 1491:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* fedes */
  case 1492:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fedeu */
  case 1493:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* fedia */
  case 1494:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* fedor */
  case 1495:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* feias */
  case 1496:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* feios */
  case 1497:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* feira */
  case 1498:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* feita */
  case 1499:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* feito */
  case 1500:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* feixe */
  case 1501:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* feliz */
  case 1502:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* fenda */
  case 1503:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* fende */
  case 1504:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* fendi */
  case 1505:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* fendo */
  case 1506:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* feras */
  case 1507:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* feraz */
  case 1508:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* ferem */
  case 1509:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* feres */
  case 1510:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* feria */
  case 1511:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ferir */
  case 1512:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* feris */
  case 1513:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* feriu */
  case 1514:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* feroz */
  case 1515:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'z';
    break;

  /* ferra */
  case 1516:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ferre */
  case 1517:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* ferro */
  case 1518:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ferva */
  case 1519:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* ferve */
  case 1520:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* fervi */
  case 1521:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* fervo */
  case 1522:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* festa */
  case 1523:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* fetal */
  case 1524:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* fetos */
  case 1525:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* feudo */
  case 1526:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* fezes */
  case 1527:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fiado */
  case 1528:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* fiais */
  case 1529:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fiamo */
  case 1530:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* fiapo */
  case 1531:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* fiara */
  case 1532:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* fiava */
  case 1533:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* fibra */
  case 1534:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ficai */
  case 1535:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ficam */
  case 1536:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ficar */
  case 1537:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ficas */
  case 1538:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ficha */
  case 1539:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* fiche */
  case 1540:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* ficho */
  case 1541:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* ficou */
  case 1542:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* fieis */
  case 1543:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fiemo */
  case 1544:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* figas */
  case 1545:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* figos */
  case 1546:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* filai */
  case 1547:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* filam */
  case 1548:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* filar */
  case 1549:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* filas */
  case 1550:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* filei */
  case 1551:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* filem */
  case 1552:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* files */
  case 1553:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* filha */
  case 1554:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* filho */
  case 1555:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* filia */
  case 1556:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* filie */
  case 1557:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* filio */
  case 1558:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* filma */
  case 1559:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* filme */
  case 1560:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* filmo */
  case 1561:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* filou */
  case 1562:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* final */
  case 1563:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* finas */
  case 1564:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* finca */
  case 1565:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* finco */
  case 1566:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* finda */
  case 1567:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* finde */
  case 1568:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* findo */
  case 1569:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* finge */
  case 1570:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* fingi */
  case 1571:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* finja */
  case 1572:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* finjo */
  case 1573:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* finos */
  case 1574:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* finta */
  case 1575:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* finte */
  case 1576:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* finto */
  case 1577:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* fique */
  case 1578:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* firam */
  case 1579:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* firas */
  case 1580:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* firma */
  case 1581:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* firme */
  case 1582:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* firmo */
  case 1583:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* fisco */
  case 1584:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* fisga */
  case 1585:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* fisgo */
  case 1586:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* fitai */
  case 1587:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* fitam */
  case 1588:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fitar */
  case 1589:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* fitas */
  case 1590:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fitei */
  case 1591:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fitem */
  case 1592:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fites */
  case 1593:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fitou */
  case 1594:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* fixai */
  case 1595:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* fixam */
  case 1596:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fixar */
  case 1597:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* fixas */
  case 1598:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fixei */
  case 1599:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fixem */
  case 1600:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fixes */
  case 1601:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fixos */
  case 1602:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fixou */
  case 1603:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* fizer */
  case 1604:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* flavo */
  case 1605:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* floco */
  case 1606:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* flora */
  case 1607:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* flori */
  case 1608:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* fluam */
  case 1609:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fluas */
  case 1610:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fluem */
  case 1611:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fluir */
  case 1612:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* fluis */
  case 1613:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fluiu */
  case 1614:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* fluxo */
  case 1615:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* fobia */
  case 1616:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* focai */
  case 1617:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* focam */
  case 1618:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* focar */
  case 1619:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* focas */
  case 1620:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* focos */
  case 1621:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* focou */
  case 1622:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* fofas */
  case 1623:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fofos */
  case 1624:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fogem */
  case 1625:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* foges */
  case 1626:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fogos */
  case 1627:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* foice */
  case 1628:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* foles */
  case 1629:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* folga */
  case 1630:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* folgo */
  case 1631:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* folha */
  case 1632:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* folia */
  case 1633:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* fomes */
  case 1634:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fomos */
  case 1635:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fones */
  case 1636:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fonte */
  case 1637:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* foque */
  case 1638:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* foram */
  case 1639:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* foras */
  case 1640:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* forca */
  case 1641:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* force */
  case 1642:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* forem */
  case 1643:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fores */
  case 1644:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* forja */
  case 1645:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* forje */
  case 1646:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* forjo */
  case 1647:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* forma */
  case 1648:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* forme */
  case 1649:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* formo */
  case 1650:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* forno */
  case 1651:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* foros */
  case 1652:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* forra */
  case 1653:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* forre */
  case 1654:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* forro */
  case 1655:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* forte */
  case 1656:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* fosca */
  case 1657:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* fosco */
  case 1658:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* fossa */
  case 1659:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* fosse */
  case 1660:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* fosso */
  case 1661:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* foste */
  case 1662:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* fotos */
  case 1663:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fraca */
  case 1664:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* fraco */
  case 1665:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* frade */
  case 1666:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* fraga */
  case 1667:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* frase */
  case 1668:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* freai */
  case 1669:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* frear */
  case 1670:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* freei */
  case 1671:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* freia */
  case 1672:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* freie */
  case 1673:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* freio */
  case 1674:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* freme */
  case 1675:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* fremi */
  case 1676:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* freou */
  case 1677:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* fresa */
  case 1678:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* frese */
  case 1679:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* freso */
  case 1680:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* freta */
  case 1681:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* frete */
  case 1682:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* freto */
  case 1683:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* frevo */
  case 1684:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* frias */
  case 1685:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* frigi */
  case 1686:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* frija */
  case 1687:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* frijo */
  case 1688:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* frios */
  case 1689:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* frisa */
  case 1690:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* frise */
  case 1691:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* friso */
  case 1692:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* frita */
  case 1693:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* frite */
  case 1694:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* frito */
  case 1695:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* frota */
  case 1696:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* fruam */
  case 1697:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fruas */
  case 1698:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fruem */
  case 1699:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fruir */
  case 1700:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* fruis */
  case 1701:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fruiu */
  case 1702:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* fruta */
  case 1703:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* fruto */
  case 1704:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* fucei */
  case 1705:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fucem */
  case 1706:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fuces */
  case 1707:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fugas */
  case 1708:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fugaz */
  case 1709:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* fugia */
  case 1710:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* fugir */
  case 1711:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* fugis */
  case 1712:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fugiu */
  case 1713:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* fujam */
  case 1714:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fujas */
  case 1715:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fujem */
  case 1716:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fujes */
  case 1717:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fujia */
  case 1718:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* fujir */
  case 1719:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* fujis */
  case 1720:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* fujiu */
  case 1721:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* fulge */
  case 1722:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* fulgi */
  case 1723:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* fumai */
  case 1724:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* fumam */
  case 1725:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* fumar */
  case 1726:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* fumas */
  case 1727:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* fumei */
  case 1728:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* fumem */
  case 1729:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fumes */
  case 1730:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* fumou */
  case 1731:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* funda */
  case 1732:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* funde */
  case 1733:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* fundi */
  case 1734:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* fundo */
  case 1735:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* funga */
  case 1736:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* fungo */
  case 1737:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* funil */
  case 1738:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* funis */
  case 1739:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* furai */
  case 1740:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* furam */
  case 1741:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* furar */
  case 1742:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* furas */
  case 1743:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* furei */
  case 1744:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* furem */
  case 1745:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* fures */
  case 1746:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* furna */
  case 1747:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* furor */
  case 1748:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* furos */
  case 1749:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* furou */
  case 1750:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* furta */
  case 1751:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* furte */
  case 1752:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* furto */
  case 1753:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* fusco */
  case 1754:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* fusos */
  case 1755:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* fuzil */
  case 1756:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* fuzis */
  case 1757:
    primeiraLetraPalavraDia = 'f';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* gabai */
  case 1758:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* gabam */
  case 1759:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gabar */
  case 1760:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* gabas */
  case 1761:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gabei */
  case 1762:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gabem */
  case 1763:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* gabes */
  case 1764:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gabou */
  case 1765:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* gados */
  case 1766:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gagas */
  case 1767:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gagos */
  case 1768:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gaita */
  case 1769:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* gajas */
  case 1770:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gajos */
  case 1771:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* galas */
  case 1772:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* galga */
  case 1773:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* galgo */
  case 1774:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* galho */
  case 1775:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* galos */
  case 1776:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gamos */
  case 1777:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ganem */
  case 1778:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ganes */
  case 1779:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ganha */
  case 1780:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* ganhe */
  case 1781:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* ganho */
  case 1782:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* gania */
  case 1783:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ganir */
  case 1784:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* ganis */
  case 1785:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ganiu */
  case 1786:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* ganso */
  case 1787:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* garbo */
  case 1788:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* garfa */
  case 1789:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* garfe */
  case 1790:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* garfo */
  case 1791:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* garis */
  case 1792:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* garoa */
  case 1793:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* garoe */
  case 1794:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* garra */
  case 1795:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* gases */
  case 1796:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gasta */
  case 1797:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* gaste */
  case 1798:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* gasto */
  case 1799:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* gatas */
  case 1800:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gatos */
  case 1801:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gazua */
  case 1802:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* geada */
  case 1803:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* geado */
  case 1804:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* geais */
  case 1805:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* geamo */
  case 1806:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* geara */
  case 1807:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* geava */
  case 1808:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* geeis */
  case 1809:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* geemo */
  case 1810:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* geiam */
  case 1811:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* geias */
  case 1812:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* geiem */
  case 1813:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* geies */
  case 1814:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gelai */
  case 1815:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* gelam */
  case 1816:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gelar */
  case 1817:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* gelas */
  case 1818:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gelei */
  case 1819:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gelem */
  case 1820:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* geles */
  case 1821:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gelos */
  case 1822:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gelou */
  case 1823:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* gemam */
  case 1824:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gemas */
  case 1825:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gemei */
  case 1826:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gemem */
  case 1827:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* gemer */
  case 1828:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* gemes */
  case 1829:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gemeu */
  case 1830:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* gemia */
  case 1831:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* genes */
  case 1832:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* genro */
  case 1833:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* gente */
  case 1834:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* gerai */
  case 1835:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* geral */
  case 1836:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* geram */
  case 1837:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gerar */
  case 1838:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* geras */
  case 1839:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gerei */
  case 1840:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gerem */
  case 1841:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* geres */
  case 1842:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* geria */
  case 1843:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* gerir */
  case 1844:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* geris */
  case 1845:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* geriu */
  case 1846:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* germe */
  case 1847:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* gerou */
  case 1848:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* gesso */
  case 1849:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* gesta */
  case 1850:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* gesto */
  case 1851:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ginga */
  case 1852:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* gingo */
  case 1853:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* girai */
  case 1854:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* giram */
  case 1855:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* girar */
  case 1856:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* giras */
  case 1857:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* girei */
  case 1858:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* girem */
  case 1859:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* gires */
  case 1860:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* giros */
  case 1861:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* girou */
  case 1862:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* gleba */
  case 1863:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* globo */
  case 1864:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* glosa */
  case 1865:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* glose */
  case 1866:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* gloso */
  case 1867:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* gnomo */
  case 1868:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* goela */
  case 1869:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* golas */
  case 1870:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* goles */
  case 1871:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* golfo */
  case 1872:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* golpe */
  case 1873:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* gomas */
  case 1874:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gomes */
  case 1875:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gomos */
  case 1876:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gongo */
  case 1877:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* gonzo */
  case 1878:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* gorai */
  case 1879:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* goram */
  case 1880:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gorar */
  case 1881:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* goras */
  case 1882:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gorda */
  case 1883:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* gordo */
  case 1884:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* gorei */
  case 1885:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gorem */
  case 1886:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* gores */
  case 1887:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gorou */
  case 1888:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* gorro */
  case 1889:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* gosma */
  case 1890:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* gosta */
  case 1891:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* goste */
  case 1892:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* gosto */
  case 1893:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* gotas */
  case 1894:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gozai */
  case 1895:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* gozam */
  case 1896:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* gozar */
  case 1897:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* gozas */
  case 1898:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* gozei */
  case 1899:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* gozem */
  case 1900:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* gozes */
  case 1901:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* gozos */
  case 1902:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* gozou */
  case 1903:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* grade */
  case 1904:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* grafa */
  case 1905:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* grafe */
  case 1906:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* grafo */
  case 1907:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* grama */
  case 1908:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* grana */
  case 1909:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* grata */
  case 1910:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* grato */
  case 1911:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* graus */
  case 1912:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* grava */
  case 1913:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* grave */
  case 1914:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* gravo */
  case 1915:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* graxa */
  case 1916:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'a';
    break;

  /* graxo */
  case 1917:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* grega */
  case 1918:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* grego */
  case 1919:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* greve */
  case 1920:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* grifa */
  case 1921:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* grife */
  case 1922:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'e';
    break;

  /* grifo */
  case 1923:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'o';
    break;

  /* grila */
  case 1924:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* grile */
  case 1925:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* grilo */
  case 1926:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* gripe */
  case 1927:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* grita */
  case 1928:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* grite */
  case 1929:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* grito */
  case 1930:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* gruda */
  case 1931:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* grude */
  case 1932:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* grudo */
  case 1933:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* grupo */
  case 1934:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* gruta */
  case 1935:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* gueto */
  case 1936:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* guiai */
  case 1937:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* guiam */
  case 1938:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* guiar */
  case 1939:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* guias */
  case 1940:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* guiei */
  case 1941:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* guiem */
  case 1942:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* guies */
  case 1943:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* guiou */
  case 1944:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* guisa */
  case 1945:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* guizo */
  case 1946:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* gumes */
  case 1947:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* guria */
  case 1948:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* guris */
  case 1949:
    primeiraLetraPalavraDia = 'g';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* hajam */
  case 1950:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* hajas */
  case 1951:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* halos */
  case 1952:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* haras */
  case 1953:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* harpa */
  case 1954:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* haste */
  case 1955:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* haure */
  case 1956:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* hauri */
  case 1957:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* havei */
  case 1958:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* haver */
  case 1959:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* havia */
  case 1960:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* heras */
  case 1961:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* herda */
  case 1962:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* herde */
  case 1963:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* herdo */
  case 1964:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* hiato */
  case 1965:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* hiena */
  case 1966:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* hindu */
  case 1967:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'u';
    break;

  /* hinos */
  case 1968:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* homem */
  case 1969:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* honra */
  case 1970:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* honre */
  case 1971:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* honro */
  case 1972:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* horas */
  case 1973:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* horda */
  case 1974:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* horta */
  case 1975:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* horto */
  case 1976:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* hotel */
  case 1977:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* houve */
  case 1978:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* hulha */
  case 1979:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* humor */
  case 1980:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* hunos */
  case 1981:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* hurra */
  case 1982:
    primeiraLetraPalavraDia = 'h';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* iates */
  case 1983:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ibero */
  case 1984:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* iceis */
  case 1985:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* icemo */
  case 1986:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* idade */
  case 1987:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* ideal */
  case 1988:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* idosa */
  case 1989:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* idoso */
  case 1990:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* ienes */
  case 1991:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* igual */
  case 1992:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* ilesa */
  case 1993:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* ileso */
  case 1994:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* ilhai */
  case 1995:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ilham */
  case 1996:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ilhar */
  case 1997:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ilhas */
  case 1998:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ilhei */
  case 1999:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ilhem */
  case 2000:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ilhes */
  case 2001:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ilhou */
  case 2002:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* iluda */
  case 2003:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* ilude */
  case 2004:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* iludi */
  case 2005:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* iludo */
  case 2006:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* imita */
  case 2007:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* imite */
  case 2008:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* imito */
  case 2009:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* imola */
  case 2010:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* imole */
  case 2011:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* imolo */
  case 2012:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* impor */
  case 2013:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* impus */
  case 2014:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* imune */
  case 2015:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* inala */
  case 2016:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* inale */
  case 2017:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* inalo */
  case 2018:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* inata */
  case 2019:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* inato */
  case 2020:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* incas */
  case 2021:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* incha */
  case 2022:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* inche */
  case 2023:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* incho */
  case 2024:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* incoa */
  case 2025:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* incoe */
  case 2026:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* induz */
  case 2027:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'z';
    break;

  /* infla */
  case 2028:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* infle */
  case 2029:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* inflo */
  case 2030:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* infra */
  case 2031:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* iniba */
  case 2032:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* inibe */
  case 2033:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* inibo */
  case 2034:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* inova */
  case 2035:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* inove */
  case 2036:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* inovo */
  case 2037:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* insta */
  case 2038:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* inste */
  case 2039:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* insto */
  case 2040:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* inter */
  case 2041:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* intua */
  case 2042:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* intui */
  case 2043:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* intuo */
  case 2044:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* irada */
  case 2045:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* irado */
  case 2046:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* irdes */
  case 2047:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ireis */
  case 2048:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* iremo */
  case 2049:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* iriam */
  case 2050:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* irias */
  case 2051:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* irmos */
  case 2052:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* iscas */
  case 2053:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* isola */
  case 2054:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* isole */
  case 2055:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* isolo */
  case 2056:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* istmo */
  case 2057:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* itera */
  case 2058:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* itere */
  case 2059:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* itero */
  case 2060:
    primeiraLetraPalavraDia = 'i';
    segundaLetraPalavraDia = 't';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* jacas */
  case 2061:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* janta */
  case 2062:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* jante */
  case 2063:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* janto */
  case 2064:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* jarda */
  case 2065:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* jarra */
  case 2066:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* jarro */
  case 2067:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* jatos */
  case 2068:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* jaula */
  case 2069:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* jazam */
  case 2070:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* jazas */
  case 2071:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* jazei */
  case 2072:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* jazem */
  case 2073:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* jazer */
  case 2074:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* jazes */
  case 2075:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* jazeu */
  case 2076:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* jazia */
  case 2077:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* jecas */
  case 2078:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* jegue */
  case 2079:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* jeito */
  case 2080:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* jejua */
  case 2081:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* jejue */
  case 2082:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* jejum */
  case 2083:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'm';
    break;

  /* jejuo */
  case 2084:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* jesus */
  case 2085:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* jinga */
  case 2086:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* joana */
  case 2087:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* jogai */
  case 2088:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* jogam */
  case 2089:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* jogar */
  case 2090:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* jogas */
  case 2091:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* jogos */
  case 2092:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* jogou */
  case 2093:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* jogue */
  case 2094:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* jorge */
  case 2095:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* jorra */
  case 2096:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* jorre */
  case 2097:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* jorro */
  case 2098:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* jovem */
  case 2099:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* jubas */
  case 2100:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* judas */
  case 2101:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* judeu */
  case 2102:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* judia */
  case 2103:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* judie */
  case 2104:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* judio */
  case 2105:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* julga */
  case 2106:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* julgo */
  case 2107:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* julho */
  case 2108:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* junco */
  case 2109:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* junho */
  case 2110:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* junta */
  case 2111:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* junte */
  case 2112:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* junto */
  case 2113:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* jurai */
  case 2114:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* juram */
  case 2115:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* jurar */
  case 2116:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* juras */
  case 2117:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* jurei */
  case 2118:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* jurem */
  case 2119:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* jures */
  case 2120:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* juros */
  case 2121:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* jurou */
  case 2122:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* justa */
  case 2123:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* justo */
  case 2124:
    primeiraLetraPalavraDia = 'j';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* labor */
  case 2125:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* lacei */
  case 2126:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lacem */
  case 2127:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* laces */
  case 2128:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lacra */
  case 2129:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* lacre */
  case 2130:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* lacro */
  case 2131:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lados */
  case 2132:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ladra */
  case 2133:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ladre */
  case 2134:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* ladro */
  case 2135:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lagar */
  case 2136:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lagoa */
  case 2137:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* lagos */
  case 2138:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* laica */
  case 2139:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* laico */
  case 2140:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* lajes */
  case 2141:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lamba */
  case 2142:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* lambe */
  case 2143:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* lambi */
  case 2144:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'i';
    break;

  /* lambo */
  case 2145:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* lance */
  case 2146:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* lapso */
  case 2147:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* lares */
  case 2148:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* larga */
  case 2149:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* largo */
  case 2150:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* larva */
  case 2151:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* lasca */
  case 2152:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* lasco */
  case 2153:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* laser */
  case 2154:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* latas */
  case 2155:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* latem */
  case 2156:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* lates */
  case 2157:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* latia */
  case 2158:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* latim */
  case 2159:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* latir */
  case 2160:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* latis */
  case 2161:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* latiu */
  case 2162:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* lauda */
  case 2163:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* laudo */
  case 2164:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* lavai */
  case 2165:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lavam */
  case 2166:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lavar */
  case 2167:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lavas */
  case 2168:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lavei */
  case 2169:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lavem */
  case 2170:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* laves */
  case 2171:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lavou */
  case 2172:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* lavra */
  case 2173:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* lavre */
  case 2174:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* lavro */
  case 2175:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lazer */
  case 2176:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* leais */
  case 2177:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* lebre */
  case 2178:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* ledes */
  case 2179:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* legai */
  case 2180:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* legal */
  case 2181:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* legam */
  case 2182:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* legar */
  case 2183:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* legas */
  case 2184:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* legou */
  case 2185:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* legue */
  case 2186:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* leiam */
  case 2187:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* leias */
  case 2188:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* leiga */
  case 2189:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* leigo */
  case 2190:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* leite */
  case 2191:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* leito */
  case 2192:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* lemas */
  case 2193:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lemes */
  case 2194:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lemos */
  case 2195:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* lenda */
  case 2196:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* lendo */
  case 2197:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* lenga */
  case 2198:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* lenha */
  case 2199:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* lenho */
  case 2200:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* lenta */
  case 2201:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* lente */
  case 2202:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* lento */
  case 2203:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* leoas */
  case 2204:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lepra */
  case 2205:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* leque */
  case 2206:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* leram */
  case 2207:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* leras */
  case 2208:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lerda */
  case 2209:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* lerdo */
  case 2210:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* lerei */
  case 2211:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lerem */
  case 2212:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* leres */
  case 2213:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* leria */
  case 2214:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* lermo */
  case 2215:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* lesai */
  case 2216:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lesam */
  case 2217:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lesar */
  case 2218:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lesas */
  case 2219:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lesei */
  case 2220:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lesem */
  case 2221:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* leses */
  case 2222:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lesma */
  case 2223:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* lesou */
  case 2224:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* lesse */
  case 2225:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* leste */
  case 2226:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* letra */
  case 2227:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* levai */
  case 2228:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* levam */
  case 2229:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* levar */
  case 2230:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* levas */
  case 2231:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* levei */
  case 2232:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* levem */
  case 2233:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* leves */
  case 2234:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* levou */
  case 2235:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* lhama */
  case 2236:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'h';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* liame */
  case 2237:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* libra */
  case 2238:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* liceu */
  case 2239:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* licor */
  case 2240:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* lidai */
  case 2241:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lidam */
  case 2242:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lidar */
  case 2243:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lidas */
  case 2244:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lidei */
  case 2245:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lidem */
  case 2246:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* lides */
  case 2247:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lidos */
  case 2248:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* lidou */
  case 2249:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ligai */
  case 2250:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ligam */
  case 2251:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ligar */
  case 2252:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ligas */
  case 2253:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ligou */
  case 2254:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ligue */
  case 2255:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* limai */
  case 2256:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* limam */
  case 2257:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* limar */
  case 2258:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* limas */
  case 2259:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* limbo */
  case 2260:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* limei */
  case 2261:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* limem */
  case 2262:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* limes */
  case 2263:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* limou */
  case 2264:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* limpa */
  case 2265:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* limpe */
  case 2266:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* limpo */
  case 2267:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* lince */
  case 2268:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* linda */
  case 2269:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* lindo */
  case 2270:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* linfa */
  case 2271:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* linha */
  case 2272:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* linho */
  case 2273:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* liras */
  case 2274:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lisas */
  case 2275:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lisos */
  case 2276:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* lista */
  case 2277:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* liste */
  case 2278:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* listo */
  case 2279:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* litro */
  case 2280:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* livra */
  case 2281:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* livre */
  case 2282:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* livro */
  case 2283:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lixai */
  case 2284:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lixam */
  case 2285:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lixar */
  case 2286:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lixas */
  case 2287:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lixei */
  case 2288:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lixem */
  case 2289:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* lixes */
  case 2290:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lixou */
  case 2291:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* lobas */
  case 2292:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lobos */
  case 2293:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* locai */
  case 2294:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* local */
  case 2295:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* locam */
  case 2296:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* locar */
  case 2297:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* locas */
  case 2298:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* locou */
  case 2299:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* logra */
  case 2300:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* logre */
  case 2301:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* logro */
  case 2302:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* loira */
  case 2303:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* loiro */
  case 2304:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lojas */
  case 2305:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lombo */
  case 2306:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* lonas */
  case 2307:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* longa */
  case 2308:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* longe */
  case 2309:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* longo */
  case 2310:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* lopes */
  case 2311:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* loque */
  case 2312:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* lorde */
  case 2313:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* lotai */
  case 2314:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lotam */
  case 2315:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lotar */
  case 2316:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lotas */
  case 2317:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lotei */
  case 2318:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lotem */
  case 2319:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* lotes */
  case 2320:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lotou */
  case 2321:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* louca */
  case 2322:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* louco */
  case 2323:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* loura */
  case 2324:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* louro */
  case 2325:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lousa */
  case 2326:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* louva */
  case 2327:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* louve */
  case 2328:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* louvo */
  case 2329:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* lucas */
  case 2330:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lucra */
  case 2331:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* lucre */
  case 2332:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* lucro */
  case 2333:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* lugar */
  case 2334:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lulas */
  case 2335:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lunar */
  case 2336:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lupas */
  case 2337:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lusas */
  case 2338:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lusos */
  case 2339:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* lutai */
  case 2340:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* lutam */
  case 2341:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* lutar */
  case 2342:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* lutas */
  case 2343:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* lutei */
  case 2344:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* lutem */
  case 2345:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* lutes */
  case 2346:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* lutou */
  case 2347:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* luvas */
  case 2348:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* luxos */
  case 2349:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* luzam */
  case 2350:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* luzas */
  case 2351:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* luzem */
  case 2352:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* luzes */
  case 2353:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* luzia */
  case 2354:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* luzir */
  case 2355:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* luzis */
  case 2356:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* luziu */
  case 2357:
    primeiraLetraPalavraDia = 'l';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* macas */
  case 2358:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* macho */
  case 2359:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* macia */
  case 2360:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* macio */
  case 2361:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* macro */
  case 2362:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* magia */
  case 2363:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* magma */
  case 2364:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* magna */
  case 2365:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* magno */
  case 2366:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* magoa */
  case 2367:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* magoe */
  case 2368:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* magos */
  case 2369:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* magra */
  case 2370:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* magro */
  case 2371:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* maias */
  case 2372:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* maior */
  case 2373:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* major */
  case 2374:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* malas */
  case 2375:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* males */
  case 2376:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* malha */
  case 2377:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* malhe */
  case 2378:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* malho */
  case 2379:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* malta */
  case 2380:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* mamai */
  case 2381:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mamam */
  case 2382:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mamar */
  case 2383:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* mamas */
  case 2384:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mamei */
  case 2385:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mamem */
  case 2386:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mames */
  case 2387:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mamou */
  case 2388:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* manas */
  case 2389:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* manca */
  case 2390:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* manco */
  case 2391:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* manda */
  case 2392:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* mande */
  case 2393:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* mando */
  case 2394:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* manga */
  case 2395:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* manha */
  case 2396:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* mania */
  case 2397:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* manja */
  case 2398:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* manje */
  case 2399:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* manjo */
  case 2400:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* manos */
  case 2401:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mansa */
  case 2402:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* manso */
  case 2403:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* manta */
  case 2404:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* manto */
  case 2405:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* mapas */
  case 2406:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* marca */
  case 2407:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* marco */
  case 2408:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* mares */
  case 2409:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* maria */
  case 2410:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* marra */
  case 2411:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* marta */
  case 2412:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* masca */
  case 2413:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* masco */
  case 2414:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* massa */
  case 2415:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* matai */
  case 2416:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* matam */
  case 2417:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* matar */
  case 2418:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* matas */
  case 2419:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* matei */
  case 2420:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* matem */
  case 2421:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mates */
  case 2422:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* matiz */
  case 2423:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* matos */
  case 2424:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* matou */
  case 2425:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* meada */
  case 2426:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* mecha */
  case 2427:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* medem */
  case 2428:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* medes */
  case 2429:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* media */
  case 2430:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* medir */
  case 2431:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* medis */
  case 2432:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* mediu */
  case 2433:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* medos */
  case 2434:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* medra */
  case 2435:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* medre */
  case 2436:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* medro */
  case 2437:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* meias */
  case 2438:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* meiga */
  case 2439:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* meigo */
  case 2440:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* meios */
  case 2441:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* melai */
  case 2442:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* melam */
  case 2443:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* melar */
  case 2444:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* melas */
  case 2445:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* melei */
  case 2446:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* melem */
  case 2447:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* meles */
  case 2448:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* melou */
  case 2449:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* melro */
  case 2450:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* menir */
  case 2451:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* menor */
  case 2452:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* menos */
  case 2453:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* menta */
  case 2454:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* mente */
  case 2455:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* menti */
  case 2456:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* menus */
  case 2457:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* meras */
  case 2458:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* merda */
  case 2459:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* meros */
  case 2460:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mesas */
  case 2461:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* meses */
  case 2462:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mesma */
  case 2463:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* mesmo */
  case 2464:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* metal */
  case 2465:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* metam */
  case 2466:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* metas */
  case 2467:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* metei */
  case 2468:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* metem */
  case 2469:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* meter */
  case 2470:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* metes */
  case 2471:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* meteu */
  case 2472:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* metia */
  case 2473:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* metro */
  case 2474:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* mexam */
  case 2475:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mexas */
  case 2476:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mexei */
  case 2477:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mexem */
  case 2478:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mexer */
  case 2479:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* mexes */
  case 2480:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mexeu */
  case 2481:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* mexia */
  case 2482:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* miado */
  case 2483:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* miais */
  case 2484:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* miamo */
  case 2485:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* miara */
  case 2486:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* miava */
  case 2487:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* micos */
  case 2488:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* micro */
  case 2489:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* mieis */
  case 2490:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* miemo */
  case 2491:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* migra */
  case 2492:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* migre */
  case 2493:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* migro */
  case 2494:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* mijai */
  case 2495:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mijam */
  case 2496:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mijar */
  case 2497:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* mijas */
  case 2498:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mijei */
  case 2499:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mijem */
  case 2500:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mijes */
  case 2501:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mijou */
  case 2502:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* milha */
  case 2503:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* milho */
  case 2504:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* mimai */
  case 2505:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mimam */
  case 2506:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mimar */
  case 2507:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* mimas */
  case 2508:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mimei */
  case 2509:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mimem */
  case 2510:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mimes */
  case 2511:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mimos */
  case 2512:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mimou */
  case 2513:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* minai */
  case 2514:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* minam */
  case 2515:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* minar */
  case 2516:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* minas */
  case 2517:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* minei */
  case 2518:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* minem */
  case 2519:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mines */
  case 2520:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* minha */
  case 2521:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* minis */
  case 2522:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* minou */
  case 2523:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* minta */
  case 2524:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* minto */
  case 2525:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* miolo */
  case 2526:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* mirai */
  case 2527:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* miram */
  case 2528:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mirar */
  case 2529:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* miras */
  case 2530:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mirei */
  case 2531:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mirem */
  case 2532:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mires */
  case 2533:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mirou */
  case 2534:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* mirra */
  case 2535:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* missa */
  case 2536:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* mista */
  case 2537:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* misto */
  case 2538:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* mitos */
  case 2539:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mitra */
  case 2540:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* mixos */
  case 2541:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mixto */
  case 2542:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* moais */
  case 2543:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* moamo */
  case 2544:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* modas */
  case 2545:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* modem */
  case 2546:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* modos */
  case 2547:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* moeda */
  case 2548:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* moeis */
  case 2549:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* moela */
  case 2550:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* moemo */
  case 2551:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* moera */
  case 2552:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* mofai */
  case 2553:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mofam */
  case 2554:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mofar */
  case 2555:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* mofas */
  case 2556:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mofei */
  case 2557:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mofem */
  case 2558:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mofes */
  case 2559:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mofou */
  case 2560:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* mogem */
  case 2561:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* moges */
  case 2562:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mogno */
  case 2563:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* mogol */
  case 2564:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'l';
    break;

  /* moita */
  case 2565:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* molar */
  case 2566:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* molas */
  case 2567:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* molda */
  case 2568:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* molde */
  case 2569:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* moldo */
  case 2570:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* moles */
  case 2571:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* molha */
  case 2572:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* molhe */
  case 2573:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* molho */
  case 2574:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* momos */
  case 2575:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* monge */
  case 2576:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* monja */
  case 2577:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* monta */
  case 2578:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* monte */
  case 2579:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* monto */
  case 2580:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* morai */
  case 2581:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* moral */
  case 2582:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* moram */
  case 2583:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* morar */
  case 2584:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* moras */
  case 2585:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* morda */
  case 2586:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* morde */
  case 2587:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* mordi */
  case 2588:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* mordo */
  case 2589:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* morei */
  case 2590:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* morem */
  case 2591:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mores */
  case 2592:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* morna */
  case 2593:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* morno */
  case 2594:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* morou */
  case 2595:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* morra */
  case 2596:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* morre */
  case 2597:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* morri */
  case 2598:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* morro */
  case 2599:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* morsa */
  case 2600:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* morse */
  case 2601:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* morta */
  case 2602:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* morte */
  case 2603:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* morto */
  case 2604:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* mosca */
  case 2605:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* motel */
  case 2606:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* motor */
  case 2607:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* motos */
  case 2608:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* moura */
  case 2609:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* mouro */
  case 2610:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* movam */
  case 2611:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* movas */
  case 2612:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* movei */
  case 2613:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* movem */
  case 2614:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mover */
  case 2615:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* moves */
  case 2616:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* moveu */
  case 2617:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* movia */
  case 2618:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* mucos */
  case 2619:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mudai */
  case 2620:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mudam */
  case 2621:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mudar */
  case 2622:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* mudas */
  case 2623:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mudei */
  case 2624:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* mudem */
  case 2625:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mudes */
  case 2626:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* mudez */
  case 2627:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'z';
    break;

  /* mudos */
  case 2628:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* mudou */
  case 2629:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* mugia */
  case 2630:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* mugir */
  case 2631:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* mugis */
  case 2632:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* mugiu */
  case 2633:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* muita */
  case 2634:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* muito */
  case 2635:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* mujam */
  case 2636:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* mujas */
  case 2637:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* mulas */
  case 2638:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* multa */
  case 2639:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* multe */
  case 2640:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* multi */
  case 2641:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* multo */
  case 2642:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* mundo */
  case 2643:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* munem */
  case 2644:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* munes */
  case 2645:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* munia */
  case 2646:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* munir */
  case 2647:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* munis */
  case 2648:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* muniu */
  case 2649:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* murai */
  case 2650:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* mural */
  case 2651:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* muram */
  case 2652:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* murar */
  case 2653:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* muras */
  case 2654:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* murei */
  case 2655:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* murem */
  case 2656:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* mures */
  case 2657:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* muros */
  case 2658:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* murou */
  case 2659:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* murro */
  case 2660:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* musas */
  case 2661:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* musca */
  case 2662:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* musco */
  case 2663:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* museu */
  case 2664:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* musgo */
  case 2665:
    primeiraLetraPalavraDia = 'm';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* nabla */
  case 2666:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* nabos */
  case 2667:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nacos */
  case 2668:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nadai */
  case 2669:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* nadam */
  case 2670:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* nadar */
  case 2671:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* nadas */
  case 2672:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* nadei */
  case 2673:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* nadem */
  case 2674:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* nades */
  case 2675:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nadou */
  case 2676:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* nafta */
  case 2677:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* naipe */
  case 2678:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* nanai */
  case 2679:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* nanam */
  case 2680:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* nanar */
  case 2681:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* nanas */
  case 2682:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* nanei */
  case 2683:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* nanem */
  case 2684:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* nanes */
  case 2685:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nanou */
  case 2686:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* nardo */
  case 2687:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* nariz */
  case 2688:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* narra */
  case 2689:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* narre */
  case 2690:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* narro */
  case 2691:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* nasal */
  case 2692:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* nasce */
  case 2693:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* nasci */
  case 2694:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'i';
    break;

  /* natal */
  case 2695:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* natas */
  case 2696:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* natos */
  case 2697:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nauta */
  case 2698:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* naval */
  case 2699:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* naves */
  case 2700:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* navio */
  case 2701:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* negai */
  case 2702:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* negam */
  case 2703:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* negar */
  case 2704:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* negas */
  case 2705:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* negou */
  case 2706:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* negra */
  case 2707:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* negro */
  case 2708:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* negue */
  case 2709:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* nelas */
  case 2710:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* neles */
  case 2711:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nervo */
  case 2712:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* nesga */
  case 2713:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* nessa */
  case 2714:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* nesse */
  case 2715:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* nesta */
  case 2716:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* neste */
  case 2717:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* netas */
  case 2718:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* netos */
  case 2719:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nevai */
  case 2720:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* nevam */
  case 2721:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* nevar */
  case 2722:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* nevas */
  case 2723:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* nevei */
  case 2724:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* nevem */
  case 2725:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* neves */
  case 2726:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nevou */
  case 2727:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* nexos */
  case 2728:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nicho */
  case 2729:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* ninai */
  case 2730:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ninam */
  case 2731:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ninar */
  case 2732:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ninas */
  case 2733:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ninei */
  case 2734:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ninem */
  case 2735:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* nines */
  case 2736:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ninfa */
  case 2737:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* ninho */
  case 2738:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* ninou */
  case 2739:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* nisso */
  case 2740:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* nisto */
  case 2741:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* nitro */
  case 2742:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* nobre */
  case 2743:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* nodal */
  case 2744:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* noite */
  case 2745:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* noiva */
  case 2746:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* noive */
  case 2747:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* noivo */
  case 2748:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* nomes */
  case 2749:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* noras */
  case 2750:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* norma */
  case 2751:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* norte */
  case 2752:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* nossa */
  case 2753:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* nosso */
  case 2754:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* notai */
  case 2755:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* notam */
  case 2756:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* notar */
  case 2757:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* notas */
  case 2758:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* notei */
  case 2759:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* notem */
  case 2760:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* notes */
  case 2761:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* notou */
  case 2762:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* novas */
  case 2763:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* novos */
  case 2764:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* nozes */
  case 2765:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nudez */
  case 2766:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'z';
    break;

  /* nulas */
  case 2767:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* nulos */
  case 2768:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* numas */
  case 2769:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* nunca */
  case 2770:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* nunes */
  case 2771:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* nutra */
  case 2772:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* nutre */
  case 2773:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* nutri */
  case 2774:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* nutro */
  case 2775:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* nuvem */
  case 2776:
    primeiraLetraPalavraDia = 'n';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* obesa */
  case 2777:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* obeso */
  case 2778:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* obras */
  case 2779:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* obsta */
  case 2780:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* obste */
  case 2781:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* obsto */
  case 2782:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* obter */
  case 2783:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* obvia */
  case 2784:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* obvie */
  case 2785:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* obvio */
  case 2786:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'b';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* ocaso */
  case 2787:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* ocupa */
  case 2788:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* ocupe */
  case 2789:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* ocupo */
  case 2790:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'c';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* odeia */
  case 2791:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* odeie */
  case 2792:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* odeio */
  case 2793:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* odiai */
  case 2794:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* odiar */
  case 2795:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* odiei */
  case 2796:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* odiou */
  case 2797:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'd';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* oeste */
  case 2798:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* ogiva */
  case 2799:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'g';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* olhai */
  case 2800:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* olham */
  case 2801:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* olhar */
  case 2802:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* olhas */
  case 2803:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* olhei */
  case 2804:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* olhem */
  case 2805:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* olhes */
  case 2806:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* olhos */
  case 2807:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* olhou */
  case 2808:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* oliva */
  case 2809:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* ombro */
  case 2810:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* omega */
  case 2811:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* omita */
  case 2812:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* omite */
  case 2813:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* omiti */
  case 2814:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* omito */
  case 2815:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'm';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ondas */
  case 2816:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* onera */
  case 2817:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* onere */
  case 2818:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* onero */
  case 2819:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ontem */
  case 2820:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* opaca */
  case 2821:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* opaco */
  case 2822:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* opala */
  case 2823:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* opera */
  case 2824:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* opere */
  case 2825:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* opero */
  case 2826:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* opina */
  case 2827:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* opine */
  case 2828:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* opino */
  case 2829:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* optai */
  case 2830:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* optam */
  case 2831:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* optar */
  case 2832:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* optas */
  case 2833:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* optei */
  case 2834:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* optem */
  case 2835:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* optes */
  case 2836:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* optou */
  case 2837:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'p';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* orado */
  case 2838:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* orais */
  case 2839:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* oramo */
  case 2840:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* orara */
  case 2841:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* orava */
  case 2842:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* orcas */
  case 2843:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* orcei */
  case 2844:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* orcem */
  case 2845:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* orces */
  case 2846:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ordem */
  case 2847:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* oreis */
  case 2848:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* oremo */
  case 2849:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* orgem */
  case 2850:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* orges */
  case 2851:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* orgia */
  case 2852:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* orlai */
  case 2853:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* orlam */
  case 2854:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* orlar */
  case 2855:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* orlas */
  case 2856:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* orlei */
  case 2857:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* orlem */
  case 2858:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* orles */
  case 2859:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* orlou */
  case 2860:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ornai */
  case 2861:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ornam */
  case 2862:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ornar */
  case 2863:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ornas */
  case 2864:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ornei */
  case 2865:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ornem */
  case 2866:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ornes */
  case 2867:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ornou */
  case 2868:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ossos */
  case 2869:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ostra */
  case 2870:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ouros */
  case 2871:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ousai */
  case 2872:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ousam */
  case 2873:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ousar */
  case 2874:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ousas */
  case 2875:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ousei */
  case 2876:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ousem */
  case 2877:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ouses */
  case 2878:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ousou */
  case 2879:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* outra */
  case 2880:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* outro */
  case 2881:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* ouvem */
  case 2882:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* ouves */
  case 2883:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ouvia */
  case 2884:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ouvir */
  case 2885:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* ouvis */
  case 2886:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ouviu */
  case 2887:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* ovais */
  case 2888:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ovino */
  case 2889:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'v';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* oxida */
  case 2890:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* oxide */
  case 2891:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* oxido */
  case 2892:
    primeiraLetraPalavraDia = 'o';
    segundaLetraPalavraDia = 'x';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* pacto */
  case 2893:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* padre */
  case 2894:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* pagai */
  case 2895:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pagam */
  case 2896:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pagar */
  case 2897:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pagas */
  case 2898:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pagem */
  case 2899:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pagos */
  case 2900:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pagou */
  case 2901:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pague */
  case 2902:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* paira */
  case 2903:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* paire */
  case 2904:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* pairo */
  case 2905:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* palco */
  case 2906:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* palha */
  case 2907:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* palma */
  case 2908:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* palmo */
  case 2909:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* pampa */
  case 2910:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* panca */
  case 2911:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* panda */
  case 2912:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* panos */
  case 2913:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* papai */
  case 2914:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* papam */
  case 2915:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* papar */
  case 2916:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* papas */
  case 2917:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* papei */
  case 2918:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* papel */
  case 2919:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* papem */
  case 2920:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* papes */
  case 2921:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* papos */
  case 2922:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* papou */
  case 2923:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* parai */
  case 2924:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* param */
  case 2925:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* parar */
  case 2926:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* paras */
  case 2927:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* parca */
  case 2928:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* parco */
  case 2929:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* parda */
  case 2930:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* pardo */
  case 2931:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* parei */
  case 2932:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* parem */
  case 2933:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pares */
  case 2934:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* paria */
  case 2935:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* parir */
  case 2936:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* paris */
  case 2937:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* pariu */
  case 2938:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* parou */
  case 2939:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* parta */
  case 2940:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* parte */
  case 2941:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* parti */
  case 2942:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* parto */
  case 2943:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* parvo */
  case 2944:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* pasma */
  case 2945:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* pasme */
  case 2946:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* pasmo */
  case 2947:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* passa */
  case 2948:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* passe */
  case 2949:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* passo */
  case 2950:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* pasta */
  case 2951:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* paste */
  case 2952:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* pasto */
  case 2953:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* patas */
  case 2954:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* patim */
  case 2955:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* patos */
  case 2956:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* paula */
  case 2957:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* paulo */
  case 2958:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* pausa */
  case 2959:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* pauta */
  case 2960:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* paute */
  case 2961:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* pauto */
  case 2962:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* pavio */
  case 2963:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* pavor */
  case 2964:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* pazes */
  case 2965:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pecai */
  case 2966:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pecam */
  case 2967:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pecar */
  case 2968:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pecas */
  case 2969:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pecou */
  case 2970:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pedal */
  case 2971:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* pedem */
  case 2972:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pedes */
  case 2973:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pedia */
  case 2974:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* pedir */
  case 2975:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* pedis */
  case 2976:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* pediu */
  case 2977:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* pedra */
  case 2978:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* pedro */
  case 2979:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* pegai */
  case 2980:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pegam */
  case 2981:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pegar */
  case 2982:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pegas */
  case 2983:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pegou */
  case 2984:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pegue */
  case 2985:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* peida */
  case 2986:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* peide */
  case 2987:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* peido */
  case 2988:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* peita */
  case 2989:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* peite */
  case 2990:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* peito */
  case 2991:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* peixe */
  case 2992:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* pelai */
  case 2993:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pelam */
  case 2994:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pelar */
  case 2995:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pelas */
  case 2996:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pelei */
  case 2997:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* pelem */
  case 2998:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* peles */
  case 2999:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pelos */
  case 3000:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pelou */
  case 3001:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* penai */
  case 3002:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* penal */
  case 3003:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* penam */
  case 3004:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* penar */
  case 3005:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* penas */
  case 3006:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* penca */
  case 3007:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* penda */
  case 3008:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* pende */
  case 3009:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* pendi */
  case 3010:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* pendo */
  case 3011:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* penei */
  case 3012:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* penem */
  case 3013:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* penes */
  case 3014:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* penou */
  case 3015:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pensa */
  case 3016:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* pense */
  case 3017:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* penso */
  case 3018:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* pente */
  case 3019:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* peque */
  case 3020:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* peras */
  case 3021:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* perca */
  case 3022:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* perco */
  case 3023:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* perda */
  case 3024:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* perde */
  case 3025:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* perdi */
  case 3026:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* perna */
  case 3027:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* persa */
  case 3028:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* perto */
  case 3029:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* perua */
  case 3030:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* perus */
  case 3031:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* pesai */
  case 3032:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pesam */
  case 3033:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pesar */
  case 3034:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pesas */
  case 3035:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pesca */
  case 3036:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* pesco */
  case 3037:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* pesei */
  case 3038:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* pesem */
  case 3039:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* peses */
  case 3040:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pesos */
  case 3041:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pesou */
  case 3042:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* peste */
  case 3043:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* petiz */
  case 3044:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* piada */
  case 3045:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* piado */
  case 3046:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* piais */
  case 3047:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* piamo */
  case 3048:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* piano */
  case 3049:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* piara */
  case 3050:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* piava */
  case 3051:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* picai */
  case 3052:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* picam */
  case 3053:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* picar */
  case 3054:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* picas */
  case 3055:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* picha */
  case 3056:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* piche */
  case 3057:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* picho */
  case 3058:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* picos */
  case 3059:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* picou */
  case 3060:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pieis */
  case 3061:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* piemo */
  case 3062:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* pifai */
  case 3063:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pifam */
  case 3064:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pifar */
  case 3065:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pifas */
  case 3066:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pifei */
  case 3067:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* pifem */
  case 3068:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pifes */
  case 3069:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pifou */
  case 3070:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pilar */
  case 3071:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pilha */
  case 3072:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* pilhe */
  case 3073:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* pilho */
  case 3074:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* pince */
  case 3075:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* pinga */
  case 3076:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* pingo */
  case 3077:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* pinha */
  case 3078:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* pinho */
  case 3079:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* pinos */
  case 3080:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pinta */
  case 3081:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* pinte */
  case 3082:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* pinto */
  case 3083:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* piora */
  case 3084:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* piore */
  case 3085:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* pioro */
  case 3086:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* pipas */
  case 3087:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pique */
  case 3088:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* pires */
  case 3089:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pisai */
  case 3090:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pisam */
  case 3091:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pisar */
  case 3092:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pisas */
  case 3093:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pisca */
  case 3094:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* pisco */
  case 3095:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* pisei */
  case 3096:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* pisem */
  case 3097:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pises */
  case 3098:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pisou */
  case 3099:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pista */
  case 3100:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* pixel */
  case 3101:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* pizza */
  case 3102:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* placa */
  case 3103:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* plana */
  case 3104:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* plane */
  case 3105:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* plano */
  case 3106:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* plebe */
  case 3107:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* plena */
  case 3108:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* pleno */
  case 3109:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* plota */
  case 3110:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* plote */
  case 3111:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* ploto */
  case 3112:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* pluga */
  case 3113:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* plugo */
  case 3114:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* pluma */
  case 3115:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* pneus */
  case 3116:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* pobre */
  case 3117:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* podai */
  case 3118:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* podam */
  case 3119:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* podar */
  case 3120:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* podas */
  case 3121:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* podei */
  case 3122:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* podem */
  case 3123:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* poder */
  case 3124:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* podes */
  case 3125:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* podia */
  case 3126:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* podou */
  case 3127:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* poema */
  case 3128:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* poeta */
  case 3129:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* polar */
  case 3130:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* polca */
  case 3131:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* polia */
  case 3132:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* polir */
  case 3133:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* polis */
  case 3134:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* poliu */
  case 3135:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* polpa */
  case 3136:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* polvo */
  case 3137:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* pomar */
  case 3138:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pomba */
  case 3139:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* pombo */
  case 3140:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* pomos */
  case 3141:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pompa */
  case 3142:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* ponde */
  case 3143:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* pondo */
  case 3144:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* ponha */
  case 3145:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* ponho */
  case 3146:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* ponta */
  case 3147:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* ponte */
  case 3148:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* ponto */
  case 3149:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* porca */
  case 3150:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* porco */
  case 3151:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* porei */
  case 3152:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* porem */
  case 3153:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pores */
  case 3154:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* poria */
  case 3155:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* poros */
  case 3156:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* porra */
  case 3157:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* porre */
  case 3158:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* porta */
  case 3159:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* porte */
  case 3160:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* porto */
  case 3161:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* posai */
  case 3162:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* posam */
  case 3163:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* posar */
  case 3164:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* posas */
  case 3165:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* posei */
  case 3166:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* posem */
  case 3167:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* poses */
  case 3168:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* posou */
  case 3169:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* possa */
  case 3170:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* posse */
  case 3171:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* posso */
  case 3172:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* posta */
  case 3173:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* poste */
  case 3174:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* posto */
  case 3175:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* potes */
  case 3176:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* potro */
  case 3177:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* pouca */
  case 3178:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* pouco */
  case 3179:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* poupa */
  case 3180:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* poupe */
  case 3181:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* poupo */
  case 3182:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* pousa */
  case 3183:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* pouse */
  case 3184:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* pouso */
  case 3185:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* povoa */
  case 3186:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* povoe */
  case 3187:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* povos */
  case 3188:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* prado */
  case 3189:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* praga */
  case 3190:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* praia */
  case 3191:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* prata */
  case 3192:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* prato */
  case 3193:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* praxe */
  case 3194:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'e';
    break;

  /* prazo */
  case 3195:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* prece */
  case 3196:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* prega */
  case 3197:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* prego */
  case 3198:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* prelo */
  case 3199:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* prema */
  case 3200:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* preme */
  case 3201:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* premi */
  case 3202:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* premo */
  case 3203:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* presa */
  case 3204:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* preso */
  case 3205:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* preta */
  case 3206:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* preto */
  case 3207:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* previ */
  case 3208:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* preza */
  case 3209:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* preze */
  case 3210:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* prezo */
  case 3211:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* prima */
  case 3212:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* prime */
  case 3213:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* primo */
  case 3214:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* priva */
  case 3215:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* prive */
  case 3216:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* privo */
  case 3217:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* proas */
  case 3218:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* prole */
  case 3219:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* prosa */
  case 3220:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* prova */
  case 3221:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* prove */
  case 3222:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* provi */
  case 3223:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* provo */
  case 3224:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* prumo */
  case 3225:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* puder */
  case 3226:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* pudim */
  case 3227:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* pudor */
  case 3228:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* pulai */
  case 3229:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* pulam */
  case 3230:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* pular */
  case 3231:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* pulas */
  case 3232:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* pulei */
  case 3233:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* pulem */
  case 3234:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* pules */
  case 3235:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* pulga */
  case 3236:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* pulos */
  case 3237:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* pulou */
  case 3238:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* pulsa */
  case 3239:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* pulse */
  case 3240:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* pulso */
  case 3241:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* pumas */
  case 3242:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* punam */
  case 3243:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* punas */
  case 3244:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* punem */
  case 3245:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* punes */
  case 3246:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* punha */
  case 3247:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* punho */
  case 3248:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* punia */
  case 3249:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* punir */
  case 3250:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* punis */
  case 3251:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* puniu */
  case 3252:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* puras */
  case 3253:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* purga */
  case 3254:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* purgo */
  case 3255:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* puros */
  case 3256:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* puser */
  case 3257:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* putas */
  case 3258:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* putos */
  case 3259:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* puxai */
  case 3260:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* puxam */
  case 3261:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* puxar */
  case 3262:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* puxas */
  case 3263:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* puxei */
  case 3264:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* puxem */
  case 3265:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* puxes */
  case 3266:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* puxou */
  case 3267:
    primeiraLetraPalavraDia = 'p';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* quais */
  case 3268:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* quase */
  case 3269:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* queda */
  case 3270:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* quede */
  case 3271:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* quedo */
  case 3272:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* quepe */
  case 3273:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* quero */
  case 3274:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* quilo */
  case 3275:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* quina */
  case 3276:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* quita */
  case 3277:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* quite */
  case 3278:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* quito */
  case 3279:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* quota */
  case 3280:
    primeiraLetraPalavraDia = 'q';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* rabos */
  case 3281:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* racha */
  case 3282:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* rache */
  case 3283:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* racho */
  case 3284:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* radar */
  case 3285:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* radia */
  case 3286:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* radie */
  case 3287:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* radio */
  case 3288:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* raiai */
  case 3289:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* raiam */
  case 3290:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* raiar */
  case 3291:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* raias */
  case 3292:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* raiei */
  case 3293:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* raiem */
  case 3294:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* raies */
  case 3295:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* raios */
  case 3296:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* raiou */
  case 3297:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* raiva */
  case 3298:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* rajai */
  case 3299:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rajam */
  case 3300:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rajar */
  case 3301:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rajas */
  case 3302:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rajei */
  case 3303:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rajem */
  case 3304:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rajes */
  case 3305:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rajou */
  case 3306:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ralai */
  case 3307:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* ralam */
  case 3308:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ralar */
  case 3309:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* ralas */
  case 3310:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ralei */
  case 3311:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* ralem */
  case 3312:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rales */
  case 3313:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ralha */
  case 3314:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* ralhe */
  case 3315:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* ralho */
  case 3316:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* ralos */
  case 3317:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* ralou */
  case 3318:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ramos */
  case 3319:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rampa */
  case 3320:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* range */
  case 3321:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* rangi */
  case 3322:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* ranja */
  case 3323:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* ranjo */
  case 3324:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* rapai */
  case 3325:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rapam */
  case 3326:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rapar */
  case 3327:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rapas */
  case 3328:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rapaz */
  case 3329:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* rapei */
  case 3330:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rapem */
  case 3331:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rapes */
  case 3332:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rapou */
  case 3333:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rapta */
  case 3334:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* rapte */
  case 3335:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* rapto */
  case 3336:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* raras */
  case 3337:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* raros */
  case 3338:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rasas */
  case 3339:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rasga */
  case 3340:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* rasgo */
  case 3341:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* rasos */
  case 3342:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* raspa */
  case 3343:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* raspe */
  case 3344:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* raspo */
  case 3345:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* rasto */
  case 3346:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* ratas */
  case 3347:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ratos */
  case 3348:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* reagi */
  case 3349:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* reais */
  case 3350:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* reaja */
  case 3351:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* reajo */
  case 3352:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* reata */
  case 3353:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* reate */
  case 3354:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* reato */
  case 3355:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* reboa */
  case 3356:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* reboe */
  case 3357:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* recai */
  case 3358:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* recua */
  case 3359:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* recue */
  case 3360:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* recuo */
  case 3361:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* redes */
  case 3362:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* redil */
  case 3363:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* redor */
  case 3364:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* reduz */
  case 3365:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'z';
    break;

  /* refaz */
  case 3366:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* refez */
  case 3367:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'z';
    break;

  /* refiz */
  case 3368:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'z';
    break;

  /* regai */
  case 3369:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* regam */
  case 3370:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* regar */
  case 3371:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* regas */
  case 3372:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* regei */
  case 3373:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* regem */
  case 3374:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* reger */
  case 3375:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* reges */
  case 3376:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* regeu */
  case 3377:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* regia */
  case 3378:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* regou */
  case 3379:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* regra */
  case 3380:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* regre */
  case 3381:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* regro */
  case 3382:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* regue */
  case 3383:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* reina */
  case 3384:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* reine */
  case 3385:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* reino */
  case 3386:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* rejam */
  case 3387:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rejas */
  case 3388:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* reler */
  case 3389:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* reles */
  case 3390:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* releu */
  case 3391:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* relia */
  case 3392:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* relva */
  case 3393:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* remai */
  case 3394:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* remam */
  case 3395:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* remar */
  case 3396:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* remas */
  case 3397:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* remei */
  case 3398:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* remem */
  case 3399:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* remes */
  case 3400:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* remia */
  case 3401:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* remir */
  case 3402:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* remis */
  case 3403:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* remiu */
  case 3404:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* remoa */
  case 3405:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'a';
    break;

  /* remoe */
  case 3406:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'e';
    break;

  /* remos */
  case 3407:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* remou */
  case 3408:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* renal */
  case 3409:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* renas */
  case 3410:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* renda */
  case 3411:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* rende */
  case 3412:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* rendi */
  case 3413:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* rendo */
  case 3414:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* rente */
  case 3415:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* repor */
  case 3416:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* repus */
  case 3417:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* reses */
  case 3418:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* resma */
  case 3419:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* resta */
  case 3420:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* reste */
  case 3421:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* resto */
  case 3422:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* retas */
  case 3423:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* reter */
  case 3424:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* retos */
  case 3425:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* reuni */
  case 3426:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'i';
    break;

  /* rever */
  case 3427:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* revia */
  case 3428:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* revir */
  case 3429:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* reviu */
  case 3430:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* rezai */
  case 3431:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rezam */
  case 3432:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rezar */
  case 3433:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rezas */
  case 3434:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rezei */
  case 3435:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rezem */
  case 3436:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rezes */
  case 3437:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rezou */
  case 3438:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* riais */
  case 3439:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* riamo */
  case 3440:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ribas */
  case 3441:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ricas */
  case 3442:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ricos */
  case 3443:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rides */
  case 3444:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rifai */
  case 3445:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rifam */
  case 3446:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rifar */
  case 3447:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rifas */
  case 3448:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rifei */
  case 3449:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rifem */
  case 3450:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rifes */
  case 3451:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rifle */
  case 3452:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* rifou */
  case 3453:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rigor */
  case 3454:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* rijas */
  case 3455:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rijos */
  case 3456:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rimai */
  case 3457:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rimam */
  case 3458:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rimar */
  case 3459:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rimas */
  case 3460:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rimei */
  case 3461:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rimem */
  case 3462:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rimes */
  case 3463:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rimos */
  case 3464:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rimou */
  case 3465:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rindo */
  case 3466:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* ripas */
  case 3467:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* riram */
  case 3468:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* riras */
  case 3469:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rirei */
  case 3470:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rirem */
  case 3471:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rires */
  case 3472:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* riria */
  case 3473:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* rirmo */
  case 3474:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* risca */
  case 3475:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* risco */
  case 3476:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* risos */
  case 3477:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* risse */
  case 3478:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* riste */
  case 3479:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* ritmo */
  case 3480:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ritos */
  case 3481:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rival */
  case 3482:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* rixas */
  case 3483:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* roais */
  case 3484:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* roamo */
  case 3485:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* rocas */
  case 3486:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rocei */
  case 3487:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rocem */
  case 3488:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* roces */
  case 3489:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rocha */
  case 3490:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* rodai */
  case 3491:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rodam */
  case 3492:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rodar */
  case 3493:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rodas */
  case 3494:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rodei */
  case 3495:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rodem */
  case 3496:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rodes */
  case 3497:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rodos */
  case 3498:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rodou */
  case 3499:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* roeis */
  case 3500:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* roemo */
  case 3501:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* roera */
  case 3502:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* rogai */
  case 3503:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rogam */
  case 3504:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rogar */
  case 3505:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rogas */
  case 3506:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rogem */
  case 3507:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* roges */
  case 3508:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rogos */
  case 3509:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rogou */
  case 3510:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rogue */
  case 3511:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* rolai */
  case 3512:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rolam */
  case 3513:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rolar */
  case 3514:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rolas */
  case 3515:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rolei */
  case 3516:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rolem */
  case 3517:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* roles */
  case 3518:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rolha */
  case 3519:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* rolos */
  case 3520:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rolou */
  case 3521:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rombo */
  case 3522:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* rompa */
  case 3523:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* rompe */
  case 3524:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* rompi */
  case 3525:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'i';
    break;

  /* rompo */
  case 3526:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* ronca */
  case 3527:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* ronco */
  case 3528:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* ronda */
  case 3529:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* ronde */
  case 3530:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* rondo */
  case 3531:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* roque */
  case 3532:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* rosas */
  case 3533:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rosca */
  case 3534:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* rosna */
  case 3535:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* rosne */
  case 3536:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* rosno */
  case 3537:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* rosto */
  case 3538:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* rotas */
  case 3539:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rotos */
  case 3540:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rouba */
  case 3541:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* roube */
  case 3542:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* roubo */
  case 3543:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* rouca */
  case 3544:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* rouco */
  case 3545:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* roupa */
  case 3546:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* roxas */
  case 3547:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* roxos */
  case 3548:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rubis */
  case 3549:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* rublo */
  case 3550:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* rubra */
  case 3551:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* rubro */
  case 3552:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* rudes */
  case 3553:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ruela */
  case 3554:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* rufai */
  case 3555:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rufam */
  case 3556:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rufar */
  case 3557:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rufas */
  case 3558:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rufei */
  case 3559:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rufem */
  case 3560:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rufes */
  case 3561:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rufou */
  case 3562:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rugai */
  case 3563:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rugam */
  case 3564:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rugar */
  case 3565:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rugas */
  case 3566:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rugia */
  case 3567:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* rugir */
  case 3568:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* rugis */
  case 3569:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* rugiu */
  case 3570:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* rugou */
  case 3571:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rugue */
  case 3572:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* ruiam */
  case 3573:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* ruias */
  case 3574:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ruido */
  case 3575:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* ruimo */
  case 3576:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ruins */
  case 3577:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 's';
    break;

  /* ruira */
  case 3578:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ruiva */
  case 3579:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* ruivo */
  case 3580:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* rujam */
  case 3581:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rujas */
  case 3582:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rumai */
  case 3583:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* rumam */
  case 3584:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* rumar */
  case 3585:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* rumas */
  case 3586:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* rumei */
  case 3587:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* rumem */
  case 3588:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* rumes */
  case 3589:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* rumor */
  case 3590:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* rumos */
  case 3591:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* rumou */
  case 3592:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* rural */
  case 3593:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* rusga */
  case 3594:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* russa */
  case 3595:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* russo */
  case 3596:
    primeiraLetraPalavraDia = 'r';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* sabei */
  case 3597:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* sabem */
  case 3598:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* saber */
  case 3599:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* sabes */
  case 3600:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sabia */
  case 3601:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sabor */
  case 3602:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* sabre */
  case 3603:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* sacai */
  case 3604:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* sacam */
  case 3605:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sacar */
  case 3606:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* sacas */
  case 3607:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sacia */
  case 3608:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sacie */
  case 3609:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* sacio */
  case 3610:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* sacis */
  case 3611:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* sacos */
  case 3612:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sacou */
  case 3613:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sacra */
  case 3614:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sacro */
  case 3615:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* sadia */
  case 3616:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sadio */
  case 3617:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* safai */
  case 3618:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* safam */
  case 3619:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* safar */
  case 3620:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* safas */
  case 3621:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* safei */
  case 3622:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* safem */
  case 3623:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* safes */
  case 3624:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* safou */
  case 3625:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* safra */
  case 3626:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sagas */
  case 3627:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sagaz */
  case 3628:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* sagra */
  case 3629:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sagre */
  case 3630:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* sagro */
  case 3631:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* saiam */
  case 3632:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* saias */
  case 3633:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* saiba */
  case 3634:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* saido */
  case 3635:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* salas */
  case 3636:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* salda */
  case 3637:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* salde */
  case 3638:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* saldo */
  case 3639:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* sales */
  case 3640:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* salga */
  case 3641:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* salgo */
  case 3642:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* salmo */
  case 3643:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* salsa */
  case 3644:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* salta */
  case 3645:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* salte */
  case 3646:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* salto */
  case 3647:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* salva */
  case 3648:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* salve */
  case 3649:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* salvo */
  case 3650:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* samba */
  case 3651:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* sambe */
  case 3652:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* sambo */
  case 3653:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* sanai */
  case 3654:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* sanam */
  case 3655:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sanar */
  case 3656:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* sanas */
  case 3657:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sanei */
  case 3658:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* sanem */
  case 3659:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* sanes */
  case 3660:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sanha */
  case 3661:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* sanou */
  case 3662:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* santa */
  case 3663:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* santo */
  case 3664:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* sapos */
  case 3665:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* saque */
  case 3666:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* sarai */
  case 3667:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* saram */
  case 3668:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sarar */
  case 3669:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* saras */
  case 3670:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sarda */
  case 3671:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* sarei */
  case 3672:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* sarem */
  case 3673:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* sares */
  case 3674:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sarna */
  case 3675:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* sarou */
  case 3676:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sauna */
  case 3677:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* seara */
  case 3678:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sebes */
  case 3679:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sebos */
  case 3680:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* secai */
  case 3681:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* secam */
  case 3682:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* secar */
  case 3683:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* secas */
  case 3684:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* secos */
  case 3685:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* secou */
  case 3686:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sedas */
  case 3687:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sedes */
  case 3688:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sedia */
  case 3689:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sedie */
  case 3690:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* sedio */
  case 3691:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* seduz */
  case 3692:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'z';
    break;

  /* segue */
  case 3693:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* segui */
  case 3694:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'i';
    break;

  /* seios */
  case 3695:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* seita */
  case 3696:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* seiva */
  case 3697:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* seixo */
  case 3698:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'x';
    quintaLetraPalavraDia = 'o';
    break;

  /* sejam */
  case 3699:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sejas */
  case 3700:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* selai */
  case 3701:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* selam */
  case 3702:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* selar */
  case 3703:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* selas */
  case 3704:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* selei */
  case 3705:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* selem */
  case 3706:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* seles */
  case 3707:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* selim */
  case 3708:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* selos */
  case 3709:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* selou */
  case 3710:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* selva */
  case 3711:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* senda */
  case 3712:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* sendo */
  case 3713:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* senha */
  case 3714:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* senos */
  case 3715:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* senso */
  case 3716:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* senta */
  case 3717:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* sente */
  case 3718:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* senti */
  case 3719:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* sento */
  case 3720:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* seque */
  case 3721:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* serei */
  case 3722:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* serem */
  case 3723:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* seres */
  case 3724:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* seria */
  case 3725:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* serie */
  case 3726:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* serio */
  case 3727:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* serra */
  case 3728:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* serre */
  case 3729:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* serro */
  case 3730:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* serva */
  case 3731:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* serve */
  case 3732:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* servi */
  case 3733:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* servo */
  case 3734:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* serze */
  case 3735:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* serzi */
  case 3736:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'i';
    break;

  /* sesta */
  case 3737:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* setas */
  case 3738:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* setor */
  case 3739:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* sexos */
  case 3740:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sexta */
  case 3741:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* sexto */
  case 3742:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* sigam */
  case 3743:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sigas */
  case 3744:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sigla */
  case 3745:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* sigma */
  case 3746:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* signo */
  case 3747:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* silos */
  case 3748:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* silva */
  case 3749:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* silve */
  case 3750:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* silvo */
  case 3751:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* sinal */
  case 3752:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* sinas */
  case 3753:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sinos */
  case 3754:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sinta */
  case 3755:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* sinto */
  case 3756:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* siris */
  case 3757:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* sirva */
  case 3758:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* sirvo */
  case 3759:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* sirza */
  case 3760:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* sirzo */
  case 3761:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* sisma */
  case 3762:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* sisme */
  case 3763:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* sismo */
  case 3764:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* sitas */
  case 3765:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sitia */
  case 3766:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sitie */
  case 3767:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* sitio */
  case 3768:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* sitos */
  case 3769:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* situa */
  case 3770:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* situe */
  case 3771:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* situo */
  case 3772:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* soado */
  case 3773:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* soais */
  case 3774:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* soamo */
  case 3775:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* soara */
  case 3776:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* soava */
  case 3777:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* sobem */
  case 3778:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* sobes */
  case 3779:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sobra */
  case 3780:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sobre */
  case 3781:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* sobro */
  case 3782:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* socai */
  case 3783:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* socam */
  case 3784:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* socar */
  case 3785:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* socas */
  case 3786:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* socos */
  case 3787:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* socou */
  case 3788:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* soeis */
  case 3789:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* soemo */
  case 3790:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* sofra */
  case 3791:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sofre */
  case 3792:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* sofri */
  case 3793:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* sofro */
  case 3794:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'f';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* sogra */
  case 3795:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sogro */
  case 3796:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* solai */
  case 3797:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* solam */
  case 3798:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* solar */
  case 3799:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* solas */
  case 3800:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* solda */
  case 3801:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* solde */
  case 3802:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* soldo */
  case 3803:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* solei */
  case 3804:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* solem */
  case 3805:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* soles */
  case 3806:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* solos */
  case 3807:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* solou */
  case 3808:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* solta */
  case 3809:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* solte */
  case 3810:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* solto */
  case 3811:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* somai */
  case 3812:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* somam */
  case 3813:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* somar */
  case 3814:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* somas */
  case 3815:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* somei */
  case 3816:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* somem */
  case 3817:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* somes */
  case 3818:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* somos */
  case 3819:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* somou */
  case 3820:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sonda */
  case 3821:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* sonde */
  case 3822:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* sondo */
  case 3823:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* sonha */
  case 3824:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* sonhe */
  case 3825:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* sonho */
  case 3826:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* sonos */
  case 3827:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sonsa */
  case 3828:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* sonso */
  case 3829:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* sopas */
  case 3830:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sopra */
  case 3831:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* sopre */
  case 3832:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* sopro */
  case 3833:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* soque */
  case 3834:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* soros */
  case 3835:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sorri */
  case 3836:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* sorta */
  case 3837:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* sorte */
  case 3838:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* sorti */
  case 3839:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* sorva */
  case 3840:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* sorve */
  case 3841:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* sorvi */
  case 3842:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* sorvo */
  case 3843:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* soube */
  case 3844:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* sousa */
  case 3845:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* souza */
  case 3846:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* sovai */
  case 3847:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* sovam */
  case 3848:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sovar */
  case 3849:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* sovas */
  case 3850:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sovei */
  case 3851:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* sovem */
  case 3852:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* soves */
  case 3853:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sovou */
  case 3854:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* suada */
  case 3855:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* suado */
  case 3856:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* suais */
  case 3857:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* suamo */
  case 3858:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* suara */
  case 3859:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* suava */
  case 3860:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* suave */
  case 3861:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* subam */
  case 3862:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* subas */
  case 3863:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* subia */
  case 3864:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* subir */
  case 3865:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* subis */
  case 3866:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* subiu */
  case 3867:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* sucos */
  case 3868:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sueca */
  case 3869:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* sueco */
  case 3870:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* sueis */
  case 3871:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* suemo */
  case 3872:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* sugai */
  case 3873:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* sugam */
  case 3874:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sugar */
  case 3875:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* sugas */
  case 3876:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sugou */
  case 3877:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sugue */
  case 3878:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* sujai */
  case 3879:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* sujam */
  case 3880:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sujar */
  case 3881:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* sujas */
  case 3882:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sujei */
  case 3883:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* sujem */
  case 3884:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* sujes */
  case 3885:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* sujos */
  case 3886:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* sujou */
  case 3887:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* sulca */
  case 3888:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* sulco */
  case 3889:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* sulfa */
  case 3890:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* sumam */
  case 3891:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* sumas */
  case 3892:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* sumia */
  case 3893:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* sumir */
  case 3894:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* sumis */
  case 3895:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* sumiu */
  case 3896:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* sunga */
  case 3897:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* super */
  case 3898:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* supor */
  case 3899:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* supra */
  case 3900:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* supre */
  case 3901:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* supri */
  case 3902:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* supro */
  case 3903:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* supus */
  case 3904:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* surda */
  case 3905:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* surdo */
  case 3906:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* surge */
  case 3907:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* surgi */
  case 3908:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* surja */
  case 3909:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* surjo */
  case 3910:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* surra */
  case 3911:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* surre */
  case 3912:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* surro */
  case 3913:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* surta */
  case 3914:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* surte */
  case 3915:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* surto */
  case 3916:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* susta */
  case 3917:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* suste */
  case 3918:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* susti */
  case 3919:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* susto */
  case 3920:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* sutil */
  case 3921:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* sutis */
  case 3922:
    primeiraLetraPalavraDia = 's';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* tabas */
  case 3923:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tacai */
  case 3924:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tacam */
  case 3925:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tacar */
  case 3926:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tacas */
  case 3927:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tacha */
  case 3928:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* tache */
  case 3929:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* tacho */
  case 3930:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* tacos */
  case 3931:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tacou */
  case 3932:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* taipa */
  case 3933:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* talas */
  case 3934:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* talco */
  case 3935:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* talha */
  case 3936:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* talhe */
  case 3937:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* talho */
  case 3938:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* talos */
  case 3939:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tampa */
  case 3940:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* tampe */
  case 3941:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* tampo */
  case 3942:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* tanga */
  case 3943:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* tange */
  case 3944:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'e';
    break;

  /* tangi */
  case 3945:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* tango */
  case 3946:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* tanja */
  case 3947:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* tanjo */
  case 3948:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* tanta */
  case 3949:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* tanto */
  case 3950:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* tapai */
  case 3951:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tapam */
  case 3952:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tapar */
  case 3953:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tapas */
  case 3954:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tapei */
  case 3955:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* tapem */
  case 3956:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* tapes */
  case 3957:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tapou */
  case 3958:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* taque */
  case 3959:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* taras */
  case 3960:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tarda */
  case 3961:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* tarde */
  case 3962:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* tardo */
  case 3963:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* tarja */
  case 3964:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* tatua */
  case 3965:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'a';
    break;

  /* tatue */
  case 3966:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* tatuo */
  case 3967:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'o';
    break;

  /* tatus */
  case 3968:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 's';
    break;

  /* taxai */
  case 3969:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* taxam */
  case 3970:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* taxar */
  case 3971:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* taxas */
  case 3972:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* taxei */
  case 3973:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* taxem */
  case 3974:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* taxes */
  case 3975:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* taxou */
  case 3976:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* tecei */
  case 3977:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* tecem */
  case 3978:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* tecer */
  case 3979:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* teces */
  case 3980:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* teceu */
  case 3981:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* tecia */
  case 3982:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* tecla */
  case 3983:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* tecle */
  case 3984:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* teclo */
  case 3985:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* teias */
  case 3986:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* teima */
  case 3987:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* teime */
  case 3988:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* teimo */
  case 3989:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* telas */
  case 3990:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* teles */
  case 3991:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* telha */
  case 3992:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* temam */
  case 3993:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* temas */
  case 3994:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* temei */
  case 3995:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* temem */
  case 3996:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* temer */
  case 3997:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* temes */
  case 3998:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* temeu */
  case 3999:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* temia */
  case 4000:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* temor */
  case 4001:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* temos */
  case 4002:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tempo */
  case 4003:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* tenaz */
  case 4004:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* tenda */
  case 4005:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* tende */
  case 4006:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* tendi */
  case 4007:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* tendo */
  case 4008:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* tenha */
  case 4009:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* tenho */
  case 4010:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* tenor */
  case 4011:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* tenra */
  case 4012:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* tenro */
  case 4013:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* tensa */
  case 4014:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* tenso */
  case 4015:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* tenta */
  case 4016:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* tente */
  case 4017:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* tento */
  case 4018:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* terei */
  case 4019:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* terem */
  case 4020:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* teres */
  case 4021:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* teria */
  case 4022:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* termo */
  case 4023:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* terna */
  case 4024:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* terno */
  case 4025:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* terra */
  case 4026:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* tesas */
  case 4027:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* teses */
  case 4028:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tesos */
  case 4029:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* testa */
  case 4030:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* teste */
  case 4031:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* testo */
  case 4032:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* tetas */
  case 4033:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tetos */
  case 4034:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* texto */
  case 4035:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* tiara */
  case 4036:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* tidas */
  case 4037:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tidos */
  case 4038:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tigre */
  case 4039:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* times */
  case 4040:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tinam */
  case 4041:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tinas */
  case 4042:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tinem */
  case 4043:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* tines */
  case 4044:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tingi */
  case 4045:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'i';
    break;

  /* tinha */
  case 4046:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* tinia */
  case 4047:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* tinir */
  case 4048:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* tinis */
  case 4049:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* tiniu */
  case 4050:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* tinja */
  case 4051:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* tinjo */
  case 4052:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* tinta */
  case 4053:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* tinto */
  case 4054:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* tipos */
  case 4055:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tirai */
  case 4056:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tiram */
  case 4057:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tirar */
  case 4058:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tiras */
  case 4059:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tirei */
  case 4060:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* tirem */
  case 4061:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* tires */
  case 4062:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tiros */
  case 4063:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tirou */
  case 4064:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* titia */
  case 4065:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* titio */
  case 4066:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* tiver */
  case 4067:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* toada */
  case 4068:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* tocai */
  case 4069:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tocam */
  case 4070:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tocar */
  case 4071:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tocas */
  case 4072:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tocha */
  case 4073:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* tocou */
  case 4074:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* todas */
  case 4075:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* todos */
  case 4076:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* togas */
  case 4077:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tolas */
  case 4078:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* toldo */
  case 4079:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* tolha */
  case 4080:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* tolhe */
  case 4081:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'e';
    break;

  /* tolhi */
  case 4082:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'i';
    break;

  /* tolho */
  case 4083:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* tolos */
  case 4084:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tomai */
  case 4085:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tomam */
  case 4086:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tomar */
  case 4087:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tomas */
  case 4088:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tomba */
  case 4089:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* tombe */
  case 4090:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* tombo */
  case 4091:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* tomei */
  case 4092:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* tomem */
  case 4093:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* tomes */
  case 4094:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tomou */
  case 4095:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* tonel */
  case 4096:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'l';
    break;

  /* tonta */
  case 4097:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* tonto */
  case 4098:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* topai */
  case 4099:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* topam */
  case 4100:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* topar */
  case 4101:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* topas */
  case 4102:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* topei */
  case 4103:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* topem */
  case 4104:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* topes */
  case 4105:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* topos */
  case 4106:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* topou */
  case 4107:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* toque */
  case 4108:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* toras */
  case 4109:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* torce */
  case 4110:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* torci */
  case 4111:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'i';
    break;

  /* torna */
  case 4112:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* torne */
  case 4113:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* torno */
  case 4114:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* toros */
  case 4115:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* torpe */
  case 4116:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* torra */
  case 4117:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* torre */
  case 4118:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* torro */
  case 4119:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* torta */
  case 4120:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* torto */
  case 4121:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* tosai */
  case 4122:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* tosam */
  case 4123:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* tosar */
  case 4124:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* tosas */
  case 4125:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* tosca */
  case 4126:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* tosco */
  case 4127:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* tosei */
  case 4128:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* tosem */
  case 4129:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* toses */
  case 4130:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* tosou */
  case 4131:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* tosse */
  case 4132:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* tossi */
  case 4133:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'i';
    break;

  /* tosta */
  case 4134:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* toste */
  case 4135:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* tosto */
  case 4136:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* total */
  case 4137:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* totem */
  case 4138:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* touca */
  case 4139:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* touro */
  case 4140:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* trace */
  case 4141:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* traem */
  case 4142:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* traga */
  case 4143:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* trago */
  case 4144:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* traia */
  case 4145:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* traio */
  case 4146:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* trair */
  case 4147:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* trais */
  case 4148:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* traiu */
  case 4149:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* traja */
  case 4150:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* traje */
  case 4151:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* trajo */
  case 4152:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* trama */
  case 4153:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* trapo */
  case 4154:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* trata */
  case 4155:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* trate */
  case 4156:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* trato */
  case 4157:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* trava */
  case 4158:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* trave */
  case 4159:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* travo */
  case 4160:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* traze */
  case 4161:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* treco */
  case 4162:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* trema */
  case 4163:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* treme */
  case 4164:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* tremi */
  case 4165:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'i';
    break;

  /* tremo */
  case 4166:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* trena */
  case 4167:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* trens */
  case 4168:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 's';
    break;

  /* trepa */
  case 4169:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* trepe */
  case 4170:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* trepo */
  case 4171:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* treta */
  case 4172:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* treva */
  case 4173:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* trevo */
  case 4174:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* treze */
  case 4175:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* tribo */
  case 4176:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* trigo */
  case 4177:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* trina */
  case 4178:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* trino */
  case 4179:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* trios */
  case 4180:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tripa */
  case 4181:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* troca */
  case 4182:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* troce */
  case 4183:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* troco */
  case 4184:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* trono */
  case 4185:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* tropa */
  case 4186:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* trota */
  case 4187:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* trote */
  case 4188:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* troto */
  case 4189:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* trova */
  case 4190:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* truco */
  case 4191:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* trufa */
  case 4192:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'f';
    quintaLetraPalavraDia = 'a';
    break;

  /* truta */
  case 4193:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* tubos */
  case 4194:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* tumba */
  case 4195:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* tumor */
  case 4196:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* tupis */
  case 4197:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* turba */
  case 4198:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* turbe */
  case 4199:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* turbo */
  case 4200:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* turca */
  case 4201:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* turco */
  case 4202:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* turma */
  case 4203:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'a';
    break;

  /* turno */
  case 4204:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* turva */
  case 4205:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* turve */
  case 4206:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* turvo */
  case 4207:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* tussa */
  case 4208:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* tusso */
  case 4209:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* tutor */
  case 4210:
    primeiraLetraPalavraDia = 't';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* ufana */
  case 4211:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'f';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* ufane */
  case 4212:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'f';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* ufano */
  case 4213:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'f';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* uivai */
  case 4214:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* uivam */
  case 4215:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* uivar */
  case 4216:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* uivas */
  case 4217:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* uivei */
  case 4218:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* uivem */
  case 4219:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* uives */
  case 4220:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* uivos */
  case 4221:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* uivou */
  case 4222:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ultra */
  case 4223:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* ulula */
  case 4224:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* ulule */
  case 4225:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* ululo */
  case 4226:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'l';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* unais */
  case 4227:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* unemo */
  case 4228:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* ungem */
  case 4229:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* unges */
  case 4230:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* ungia */
  case 4231:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* ungir */
  case 4232:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* ungis */
  case 4233:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* ungiu */
  case 4234:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* unhas */
  case 4235:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'h';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* uniam */
  case 4236:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* unias */
  case 4237:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* unida */
  case 4238:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* unido */
  case 4239:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* unimo */
  case 4240:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* unira */
  case 4241:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* untai */
  case 4242:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* untam */
  case 4243:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* untar */
  case 4244:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* untas */
  case 4245:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* untei */
  case 4246:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* untem */
  case 4247:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* untes */
  case 4248:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* untou */
  case 4249:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'n';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* urano */
  case 4250:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* urdam */
  case 4251:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* urdas */
  case 4252:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* urdem */
  case 4253:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* urdes */
  case 4254:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* urdia */
  case 4255:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* urdir */
  case 4256:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* urdis */
  case 4257:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* urdiu */
  case 4258:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* urgia */
  case 4259:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* urgir */
  case 4260:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* urgis */
  case 4261:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* urgiu */
  case 4262:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* urina */
  case 4263:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* urine */
  case 4264:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'e';
    break;

  /* urino */
  case 4265:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'o';
    break;

  /* urjam */
  case 4266:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* urjas */
  case 4267:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* urnas */
  case 4268:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* urrai */
  case 4269:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* urram */
  case 4270:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* urrar */
  case 4271:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* urras */
  case 4272:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* urrei */
  case 4273:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* urrem */
  case 4274:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* urres */
  case 4275:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* urros */
  case 4276:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* urrou */
  case 4277:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* ursas */
  case 4278:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* ursos */
  case 4279:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 'r';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* usada */
  case 4280:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* usado */
  case 4281:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* usais */
  case 4282:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* usamo */
  case 4283:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* usara */
  case 4284:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* usava */
  case 4285:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* useis */
  case 4286:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* usemo */
  case 4287:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* usina */
  case 4288:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* usual */
  case 4289:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* usura */
  case 4290:
    primeiraLetraPalavraDia = 'u';
    segundaLetraPalavraDia = 's';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* vacas */
  case 4291:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vades */
  case 4292:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vadia */
  case 4293:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vadie */
  case 4294:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* vadio */
  case 4295:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* vagai */
  case 4296:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vagam */
  case 4297:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vagar */
  case 4298:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vagas */
  case 4299:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vagem */
  case 4300:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vagia */
  case 4301:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vagir */
  case 4302:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* vagis */
  case 4303:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* vagiu */
  case 4304:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* vagos */
  case 4305:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* vagou */
  case 4306:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* vague */
  case 4307:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* vaiai */
  case 4308:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vaiam */
  case 4309:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vaiar */
  case 4310:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vaias */
  case 4311:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vaiei */
  case 4312:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vaiem */
  case 4313:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vaies */
  case 4314:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vaiou */
  case 4315:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* valas */
  case 4316:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* valei */
  case 4317:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* valem */
  case 4318:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* valer */
  case 4319:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* vales */
  case 4320:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* valeu */
  case 4321:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* valha */
  case 4322:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* valho */
  case 4323:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* valia */
  case 4324:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* valor */
  case 4325:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* valos */
  case 4326:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* valsa */
  case 4327:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* vamos */
  case 4328:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* vapor */
  case 4329:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'p';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* varai */
  case 4330:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* varam */
  case 4331:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* varar */
  case 4332:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* varas */
  case 4333:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* varei */
  case 4334:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* varem */
  case 4335:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vares */
  case 4336:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* varia */
  case 4337:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* varie */
  case 4338:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* vario */
  case 4339:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* varou */
  case 4340:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* varra */
  case 4341:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* varre */
  case 4342:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* varri */
  case 4343:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'i';
    break;

  /* varro */
  case 4344:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* vasos */
  case 4345:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* vasta */
  case 4346:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* vasto */
  case 4347:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* vazai */
  case 4348:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vazam */
  case 4349:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vazar */
  case 4350:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vazas */
  case 4351:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vazei */
  case 4352:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vazem */
  case 4353:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vazes */
  case 4354:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vazia */
  case 4355:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vazio */
  case 4356:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* vazou */
  case 4357:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* veado */
  case 4358:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* vedai */
  case 4359:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vedam */
  case 4360:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vedar */
  case 4361:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vedas */
  case 4362:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vedei */
  case 4363:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vedem */
  case 4364:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vedes */
  case 4365:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vedou */
  case 4366:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* veias */
  case 4367:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vejai */
  case 4368:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vejam */
  case 4369:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vejas */
  case 4370:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'j';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* velai */
  case 4371:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* velam */
  case 4372:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* velar */
  case 4373:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* velas */
  case 4374:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* velei */
  case 4375:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* velem */
  case 4376:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* veles */
  case 4377:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* velha */
  case 4378:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* velho */
  case 4379:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* velou */
  case 4380:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* veloz */
  case 4381:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'z';
    break;

  /* vemos */
  case 4382:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* venal */
  case 4383:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* vence */
  case 4384:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'e';
    break;

  /* venci */
  case 4385:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'i';
    break;

  /* venda */
  case 4386:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* vende */
  case 4387:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* vendi */
  case 4388:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'i';
    break;

  /* vendo */
  case 4389:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* venha */
  case 4390:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* venho */
  case 4391:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* venta */
  case 4392:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* vente */
  case 4393:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* vento */
  case 4394:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* verba */
  case 4395:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* verbo */
  case 4396:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* verde */
  case 4397:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* verei */
  case 4398:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* verem */
  case 4399:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* veres */
  case 4400:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* verga */
  case 4401:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* veria */
  case 4402:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* verme */
  case 4403:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'e';
    break;

  /* versa */
  case 4404:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* verse */
  case 4405:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* verso */
  case 4406:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* verta */
  case 4407:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* verte */
  case 4408:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* verti */
  case 4409:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* verto */
  case 4410:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* vesga */
  case 4411:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* vesgo */
  case 4412:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* vespa */
  case 4413:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* veste */
  case 4414:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* vesti */
  case 4415:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'i';
    break;

  /* vetai */
  case 4416:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vetam */
  case 4417:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vetar */
  case 4418:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vetas */
  case 4419:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vetei */
  case 4420:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vetem */
  case 4421:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vetes */
  case 4422:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vetor */
  case 4423:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* vetou */
  case 4424:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* vexai */
  case 4425:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* vexam */
  case 4426:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vexar */
  case 4427:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* vexas */
  case 4428:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vexei */
  case 4429:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vexem */
  case 4430:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vexes */
  case 4431:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vexou */
  case 4432:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'x';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* vezes */
  case 4433:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* viaja */
  case 4434:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'a';
    break;

  /* viaje */
  case 4435:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'e';
    break;

  /* viajo */
  case 4436:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'j';
    quintaLetraPalavraDia = 'o';
    break;

  /* viana */
  case 4437:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* vibra */
  case 4438:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* vibre */
  case 4439:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* vibro */
  case 4440:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* vicia */
  case 4441:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vicie */
  case 4442:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* vicio */
  case 4443:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* vidas */
  case 4444:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vidra */
  case 4445:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* vidre */
  case 4446:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* vidro */
  case 4447:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* viela */
  case 4448:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* viena */
  case 4449:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'n';
    quintaLetraPalavraDia = 'a';
    break;

  /* viera */
  case 4450:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* vieza */
  case 4451:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* vigas */
  case 4452:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vigia */
  case 4453:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vigie */
  case 4454:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'e';
    break;

  /* vigio */
  case 4455:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'o';
    break;

  /* vigor */
  case 4456:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'r';
    break;

  /* vilas */
  case 4457:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vimos */
  case 4458:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* vinca */
  case 4459:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* vinco */
  case 4460:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* vinda */
  case 4461:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'a';
    break;

  /* vinde */
  case 4462:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'e';
    break;

  /* vindo */
  case 4463:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* vinga */
  case 4464:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* vingo */
  case 4465:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* vinha */
  case 4466:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'a';
    break;

  /* vinho */
  case 4467:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'h';
    quintaLetraPalavraDia = 'o';
    break;

  /* vinte */
  case 4468:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* viola */
  case 4469:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'a';
    break;

  /* viole */
  case 4470:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'e';
    break;

  /* violo */
  case 4471:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'o';
    quartaLetraPalavraDia = 'l';
    quintaLetraPalavraDia = 'o';
    break;

  /* virai */
  case 4472:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* viram */
  case 4473:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* virar */
  case 4474:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* viras */
  case 4475:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* virei */
  case 4476:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* virem */
  case 4477:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vires */
  case 4478:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* viria */
  case 4479:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* viril */
  case 4480:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'l';
    break;

  /* viris */
  case 4481:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* virmo */
  case 4482:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* virou */
  case 4483:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* visai */
  case 4484:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* visam */
  case 4485:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* visar */
  case 4486:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* visas */
  case 4487:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* visei */
  case 4488:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* visem */
  case 4489:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* vises */
  case 4490:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* visou */
  case 4491:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* visse */
  case 4492:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'e';
    break;

  /* vista */
  case 4493:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* viste */
  case 4494:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* visto */
  case 4495:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* vital */
  case 4496:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* viuva */
  case 4497:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* viuve */
  case 4498:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* viuvo */
  case 4499:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'u';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* vivam */
  case 4500:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* vivas */
  case 4501:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* vivaz */
  case 4502:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* vivei */
  case 4503:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* vivem */
  case 4504:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* viver */
  case 4505:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'r';
    break;

  /* vives */
  case 4506:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* viveu */
  case 4507:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'u';
    break;

  /* vivia */
  case 4508:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* vivos */
  case 4509:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'v';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* voado */
  case 4510:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'd';
    quintaLetraPalavraDia = 'o';
    break;

  /* voais */
  case 4511:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* voamo */
  case 4512:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* voara */
  case 4513:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* voava */
  case 4514:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'a';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* vodca */
  case 4515:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'd';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'a';
    break;

  /* voeis */
  case 4516:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* voemo */
  case 4517:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'e';
    quartaLetraPalavraDia = 'm';
    quintaLetraPalavraDia = 'o';
    break;

  /* vogal */
  case 4518:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'l';
    break;

  /* volta */
  case 4519:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* volte */
  case 4520:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'e';
    break;

  /* volto */
  case 4521:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* volva */
  case 4522:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* volve */
  case 4523:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'e';
    break;

  /* volvi */
  case 4524:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'i';
    break;

  /* volvo */
  case 4525:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'o';
    break;

  /* voraz */
  case 4526:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'z';
    break;

  /* vossa */
  case 4527:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'a';
    break;

  /* vosso */
  case 4528:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 's';
    quintaLetraPalavraDia = 'o';
    break;

  /* votai */
  case 4529:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* votam */
  case 4530:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* votar */
  case 4531:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* votas */
  case 4532:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* votei */
  case 4533:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* votem */
  case 4534:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* votes */
  case 4535:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* votos */
  case 4536:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* votou */
  case 4537:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 't';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* vozes */
  case 4538:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'z';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* vulgo */
  case 4539:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* vulto */
  case 4540:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* vulva */
  case 4541:
    primeiraLetraPalavraDia = 'v';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'v';
    quintaLetraPalavraDia = 'a';
    break;

  /* xales */
  case 4542:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* xelim */
  case 4543:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'm';
    break;

  /* xeque */
  case 4544:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'q';
    quartaLetraPalavraDia = 'u';
    quintaLetraPalavraDia = 'e';
    break;

  /* xerox */
  case 4545:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'x';
    break;

  /* xiita */
  case 4546:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'i';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'a';
    break;

  /* xinga */
  case 4547:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* xingo */
  case 4548:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* xisto */
  case 4549:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 's';
    quartaLetraPalavraDia = 't';
    quintaLetraPalavraDia = 'o';
    break;

  /* xucra */
  case 4550:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* xucro */
  case 4551:
    primeiraLetraPalavraDia = 'x';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'c';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;

  /* zagas */
  case 4552:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'g';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* zanga */
  case 4553:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'a';
    break;

  /* zango */
  case 4554:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'g';
    quintaLetraPalavraDia = 'o';
    break;

  /* zanza */
  case 4555:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* zanze */
  case 4556:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'e';
    break;

  /* zanzo */
  case 4557:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* zarpa */
  case 4558:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'a';
    break;

  /* zarpe */
  case 4559:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'e';
    break;

  /* zarpo */
  case 4560:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'a';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'p';
    quintaLetraPalavraDia = 'o';
    break;

  /* zebra */
  case 4561:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'b';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* zelai */
  case 4562:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* zelam */
  case 4563:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* zelar */
  case 4564:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* zelas */
  case 4565:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* zelei */
  case 4566:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* zelem */
  case 4567:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* zeles */
  case 4568:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* zelou */
  case 4569:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'l';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* zerai */
  case 4570:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'i';
    break;

  /* zeram */
  case 4571:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* zerar */
  case 4572:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'r';
    break;

  /* zeras */
  case 4573:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* zerei */
  case 4574:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'i';
    break;

  /* zerem */
  case 4575:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* zeres */
  case 4576:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* zeros */
  case 4577:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 's';
    break;

  /* zerou */
  case 4578:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'e';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'o';
    quintaLetraPalavraDia = 'u';
    break;

  /* zinco */
  case 4579:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'i';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'c';
    quintaLetraPalavraDia = 'o';
    break;

  /* zomba */
  case 4580:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* zombe */
  case 4581:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* zombo */
  case 4582:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* zonas */
  case 4583:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* zonza */
  case 4584:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'a';
    break;

  /* zonzo */
  case 4585:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'o';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'z';
    quintaLetraPalavraDia = 'o';
    break;

  /* zumba */
  case 4586:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'a';
    break;

  /* zumbe */
  case 4587:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'e';
    break;

  /* zumbi */
  case 4588:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'i';
    break;

  /* zumbo */
  case 4589:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'm';
    quartaLetraPalavraDia = 'b';
    quintaLetraPalavraDia = 'o';
    break;

  /* zunam */
  case 4590:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 'm';
    break;

  /* zunas */
  case 4591:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'a';
    quintaLetraPalavraDia = 's';
    break;

  /* zunem */
  case 4592:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 'm';
    break;

  /* zunes */
  case 4593:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'e';
    quintaLetraPalavraDia = 's';
    break;

  /* zunia */
  case 4594:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'a';
    break;

  /* zunir */
  case 4595:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'r';
    break;

  /* zunis */
  case 4596:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 's';
    break;

  /* zuniu */
  case 4597:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'n';
    quartaLetraPalavraDia = 'i';
    quintaLetraPalavraDia = 'u';
    break;

  /* zurra */
  case 4598:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'a';
    break;

  /* zurre */
  case 4599:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'e';
    break;

  /* zurro */
  case 4600:
    primeiraLetraPalavraDia = 'z';
    segundaLetraPalavraDia = 'u';
    terceiraLetraPalavraDia = 'r';
    quartaLetraPalavraDia = 'r';
    quintaLetraPalavraDia = 'o';
    break;
  }
}