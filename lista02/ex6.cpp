#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

// preenche a string de tamanho 9 digitos
string preenche_zeros(string str){
    string aux;                
    //cout<< "DEBBUG STRING" << str << endl;
    int tamanho_str = str.size();           
    aux.append(str);                
    for(int i = tamanho_str; i < 9; i++){
        aux = "0"+ aux;           
    }
    //cout<< "DEBBUG STRING" << aux << endl;
    return aux;                    
}

class BigInt{
    private:
        int* _partes;   // vetor com cada uma das partes do numero
        int _npartes;   // numero de elementos do vetor partes

        // sinal do numero. Se true, o n ́umero sera positivo ou zero
        // e se false, sera negativo
        bool _positivo; 
    public:
        BigInt(string numero);
        ~BigInt(){delete[] _partes;}
        BigInt(); //Esse construtor deve criar um BigInt com o valor 0.
        BigInt(int num, bool eh_num=true);

        // Construtor de movimento
        BigInt(BigInt&& b);
        
        //Retorna true se o n ́umero for n ̃ao negativo e false caso contr ́ario
        bool positivo()const {return _positivo;}
        
        //Deve implementar o operador de atribui ̧c ̃ao, semelhante ao construtor de c ́opia
        BigInt& operator=(const BigInt& b);
        // Retorna um BigInt representando o modulo do numero
        BigInt abs();

        // Deve retornar true se a for igual a b e false caso contr ́ario: a==b
        friend bool operator==(const BigInt& a, const BigInt& b);

        // : Deve retornar true se a for maior que b e false caso contr ́ario: a > b
        friend bool operator>(const BigInt& a, const BigInt& b);
        
        // Deve retornar uma instˆancia da
        // classe BigInt que represente a soma do BigInt a com o BigInt b: a+b
        friend BigInt operator+(const BigInt& a, const BigInt& b);

        // Deve retornar uma instˆancia da
        // classe BigInt que represente a subtra ̧c ̃ao do BigInt a com o BigInt b: a-b
        friend BigInt operator-(const BigInt& a, const BigInt& b);

        //Deve retornar uma instˆancia da classe BigInt com o mesmo m ́odulo mas sinal
        //oposto: -a
        BigInt operator-();
        
        // Deve retornar uma instancia da
        // classe BigInt que represente a multiplicacao do BigInt a pelo BigInt b: a*b  
        friend BigInt operator*(const BigInt& a, const BigInt& b);
        
        // Deve retornar uma instancia da
        // classe BigInt que represente ainstancia atual elevado a b: a^b
        // b sempre sera positivo.
        friend BigInt operator^(const BigInt& a, const BigInt& b);

        //  Deve retornar uma instˆancia da classe BigInt que represente a divis ̃ao
        //  inteira do BigInt a pelo inteiro b: a/b
        BigInt operator/(int b);

        friend std::ostream& operator<<(std::ostream &out, const BigInt &a){
            string aux;
            if(!a._positivo){
                out <<"-";
            }

            int ajuda_fim=0;
            int ajuda_inicio=0;
            if(a._partes[0]!= 0){
                out << (to_string(a._partes[0]));
            }
            else{
                out << (to_string(a._partes[1]));
                ajuda_inicio=1;
                ajuda_fim=1;
            }
            int i=1;
            for( i= 1+ ajuda_inicio; i < (a._npartes+ajuda_fim); ++i){
                //cout<< "NUMERO A PRINTAR " << a._partes[i]<< endl;
                out << preenche_zeros(to_string(a._partes[i]));
                //cout<<"ENTREI EM "<< i<<endl;

            }
            
            return out;
        }
};

int main() {
    BigInt a(19204595);
    a = a / (-844326198);
    std::cout << a << std::endl;
    a = a - BigInt(2036073398);
    //cout<< "valor de AAAAAAA"<<a;
    a = a * BigInt(1103762471);
    //cout<< "CHEGUEI 2";
    //cout<< a;
    //cout<< "CHEGUEI 1";
    a = a + BigInt(731720855);
    //cout<< "CHEGUEI 2";
    a = a * BigInt(1590423911);
    a = a / (-152564981);
    std::cout << a.abs() << std::endl;
    a = a + BigInt(1187251693);
    a = a / (2144851306);
    a = a * BigInt(-921364237);
    std::cout << a.abs() << std::endl;
    a = a - BigInt(-1816749488);
    a = a ^ BigInt(23);
    a = a * BigInt(-1437087596);
    std::cout << a << std::endl;
    a = a ^ BigInt(14);
    return 0;
}

BigInt::BigInt(string numero) {
    int quantidade_partes;
    int pula_sinal = 0; // nao faz leitura do sinal de menos

    if(numero[0] == '-'){
        _positivo = false;
        pula_sinal = 1; 
        quantidade_partes = (numero.size() - 1 + 8) / 9; // Calcula as partes desconsiderando o '-'
    } 
    else{
        _positivo = true;
        quantidade_partes = (numero.size() + 8) / 9;
    }

    //cout << "Quantidade de partes: " << quantidade_partes << endl;

    _partes = new int[quantidade_partes];
    _npartes = quantidade_partes;

    int verificacao_while = 0;  // verificacao para saber quando terminar o loop
    int conta_tamanho = numero.size() - 1; // diz quando nao ha nada mais a ser lido
    string aux;  // leitura da string e atoi para variavel classe 

    while(verificacao_while < quantidade_partes){ 
        aux = "";  // libera espaco para nova leitura, deixa vazio

        // faz leitura de traz pra frente, facilita quando for preencher com zeros da forma correta
        for(int i = 0; i < 9 && conta_tamanho >= pula_sinal; i++){
            aux = numero[conta_tamanho] + aux;
            conta_tamanho--;
        }

        _partes[quantidade_partes - verificacao_while -1] = stoi(aux);  // chama para inteiro a string e guarda na classe
        verificacao_while++;  // continua loop ate seu termino
    }
}



BigInt::BigInt(){

    _partes = new int;
    _partes[0]= 0;
    _npartes =1;
    _positivo= true;
    
}

/*Esse construtor deve receber na variavel num (um numero inteiro)
e converte-lo para BigInt caso eh_num seja true (valor padrao). Caso eh num seja false, num
deve ser o numero de partes a ser alocada e o valor deve ser 0.*/

BigInt::BigInt(int num, bool eh_num){
    if(eh_num){
        _partes = new int;
        _partes[0]= std::abs(num); // por alguma razao, ao colocar std funciona

        if(num>=0) _positivo = true;
        else _positivo =false;

        _npartes=1;
    }
    else{
        _partes = new int[num];
        for(int i=0; i<num;i++)
            _partes[i]= 0;

        _positivo=true;
        _npartes= std::abs(num);
    }
}

BigInt::BigInt(BigInt &&b){

    // atribuicao no outro objeto
    _npartes= b._npartes;
    _partes= b._partes;
    _positivo = b._positivo;

    // limpa objeto anterior
    b._partes= nullptr;
    b._npartes =0;
    b._positivo=true;

}

BigInt &BigInt::operator=(const BigInt &b){

    // caso ja exista um numero, operacao de igual ocorre sem que possa vazar memoria ou sobrar lixo
    delete[] _partes;

    // atribuicao no outro objeto
    _npartes= b._npartes;
    _positivo = b._positivo;

    _partes = new int[_npartes];

    /// PROCURAR ENTENDER PORQUE ATRIBUICAO DIRETA NAO FUNCIONA
    int aux=_npartes-1;
    while(aux>= 0){
        _partes[aux] = b._partes[aux];
        aux--;
    }

    return *this;
}

BigInt BigInt::abs(){
    BigInt aux;
    aux._npartes = _npartes;
    aux._positivo = true;

    aux._partes = new int[_npartes];
    // atribuicao das partes no auxiliar, similar a operator=
    int i=0;
    while(i<_npartes){
        aux._partes[i] = _partes[i];
        i++;
    }

    return aux;
}

BigInt BigInt::operator-(){
    BigInt retorno_negativo;
    retorno_negativo = *this; // igualdade ja definida, porttanto funciona
    // se o numero nao for igual a zero, mantem a mesma coisa
    if( !( _npartes == 1 && _partes[0] == 0 ) ){ /// ajustado o numero de partes em soma, agora funciona
        retorno_negativo._positivo = not(retorno_negativo._positivo);
    }
    return retorno_negativo;
}

BigInt BigInt::operator/(int b){
    BigInt aux;
    cout<< "VAZIO"<<endl;
    return aux;
}

bool operator==(const BigInt &a, const BigInt &b){

    // caso numero de partes e valor positivo sejam diferentes, nem efetua afericao do BigInt por agilidade de compilacao
    if( a._npartes != b._npartes || a._positivo!= b._positivo){return false;}

    else{ // verificar as partes
        int i=0;
        while(i<a._npartes){ // poderia ser b tb, pois sao iguais
            if(a._partes[i]!= b._partes[i]){
                return false;
            }
            i++;
        }
    }
    // caso seja igual
    return true;
}

bool operator>(const BigInt &a, const BigInt &b){
    // verificacao inicial se eh positivo ou negativo, resposta direta
    if(a.positivo()== true && b.positivo()== false){return true;}
    else if(a.positivo()== false && b.positivo()== true){return false;}

    else{ // a e b possuem mesmo sinal
        // verifica se ambos sao positivos ou negativos, caso seja negativo, a, em modulo, tem que ser menor que b
        if(a.positivo()==true){

            if(a._npartes<b._npartes){return false;} // a<b 
            else if(a._npartes>b._npartes){return true;} // a>b
            else{ // precisa ser verificado parte por parte
                //cout<< "CHEGYUEI AQ";
                int i=0;
                while(i<a._npartes){ // poderia ser b tb, pois sao iguais
                    if(a._partes[i] != b._partes[i]){ // caso seja diferente, algum dos 2 eh maior
                        if(a._partes[i]> b._partes[i]){return true;}
                        else{return false;}
                    }
                    i++;
                }
            }
        }
        else{ // a tem que ser menor em valor abs
            if(a._npartes>b._npartes){
                return false; // a<b
            }
            else if(a._npartes<b._npartes){
                return true; // a>b
            }
            else{ // precisa ser verificado parte por parte
                int i=0;
                while(i<a._npartes){ // poderia ser b tb, pois sao iguais
                    if(a._partes[i] != b._partes[i]){ // caso seja diferente, algum dos 2 eh maior
                        if(a._partes[i]< b._partes[i]){return true;}
                        else{return false;}
                    }
                    i++;
                }
            }
        }
    }

    // caso sejam iguais
    return false;
}

BigInt operator+(const BigInt &a, const BigInt &b){
    int resultado_soma=0; // espaco para portar ate  2.147.483.647, ou seja, no pior caso suporta 999.999.999 x2
    int carry=0; // numero que sera trasnferido para proxima parte
    BigInt retorno_bigint;
    if((a.positivo() == true && b.positivo() == true) || (a.positivo() == false && b.positivo() == false)){ // ambos numeros recebidos são negativos ou positivos
        if(a._npartes > b._npartes){ // saber qual o parametro do while /// se tiver errado fazer direto
            retorno_bigint._partes = new int[a._npartes + 1]; // desloca número de partes necessárias para soma (+1 pois pode-se ter um carry para uma nova parte)
            
            // indice que inicia no fim do vetor para bom funcionamento do codigo
            int a_index;
            int b_index;

            // Soma a partir do último dígito para facilitar a execucao do codiugo
            for(int i = 0; i < a._npartes; i++){
                a_index = a._npartes - 1 - i; 
                b_index = b._npartes - 1 - i; 

                // nao precisa ser considerado a soma de b pois ela nao existe
                if(i >= b._npartes){ resultado_soma = a._partes[a_index] + carry; }  /// talvez nao tenha o igual aq
                else{ resultado_soma = a._partes[a_index] + b._partes[b_index] + carry; }

                carry = resultado_soma / 1000000000; // como carry eh int, aproxima para o valor de baixo
                retorno_bigint._partes[a_index+1] = resultado_soma % 1000000000;  
                

                retorno_bigint._npartes++; // após inserção, aumenta número de partes do retorno
            }

            // Caso em que o carry tem que ser inserido em um novo _parte
            if(carry){
                retorno_bigint._partes[0] = carry; /// talvez tenha q fazer -1
                retorno_bigint._npartes= a._npartes+1;
            }
            else{
                retorno_bigint._partes[0] = carry; /// talvez tenha q fazer -1
                retorno_bigint._npartes = a._npartes;
            }
        }
        else{
            retorno_bigint._partes = new int[b._npartes +1]; // desloca numero de partes necessarias para soma (+1 pois pode-se ter um carry para uma nova parte)
            // indice que inicia no fim do vetor para bom funcionamento do codigo
            int a_index;
            int b_index;
            int i;
            // Soma a partir do último digito
            for(i = 0; i < b._npartes; i++){
                a_index = a._npartes - 1 - i; 
                b_index = b._npartes - 1 - i; 

                if(i >= a._npartes){ resultado_soma = b._partes[b_index] + carry; } /// talvze nao tenha o igual aq
                // Caso contrário, soma as partes de a e b com o carry
                else{ resultado_soma = a._partes[a_index] + b._partes[b_index] + carry; }

                carry = resultado_soma / 1000000000; // como carry eh int, aproxima para o valor de baixo

                retorno_bigint._partes[b_index+1] = resultado_soma % 1000000000;
                //cout<< "DEBBUG"<< "a+b com eles tamanho =< " <<retorno_bigint._partes[b_index+1]<<endl;
                //cout<<"FUI INSERIDO EM " << (b_index+1) << endl;
            }

            // Caso em que o carry tem que ser inserido em um novo _parte
            if(carry){
                retorno_bigint._partes[0] = carry;
                retorno_bigint._npartes = b._npartes+1;
                //cout<< retorno_bigint._npartes;
            }
            else{
                retorno_bigint._partes[0] = carry;
                retorno_bigint._npartes = b._npartes; /// talvez esteja errado
            }
        }

        retorno_bigint._positivo = a.positivo(); // pode ser b também
    }
    else{ // realiza subtracao 
        if(a.positivo() == false){ // b-a
            if( b._npartes > a._npartes){ /// talvez esteja errado
                retorno_bigint._partes = new int[b._npartes + 1]; // desloca número de partes necessárias para soma (+1 pois pode-se ter um carry para uma nova parte)
            
                // indice que inicia no fim do vetor para bom funcionamento do codigo
                int a_index;
                int b_index;

                // Subtrai a partir do último dígito para facilitar a execucao do codigo
                for(int i = 0; i < b._npartes; i++){
                    a_index = a._npartes - 1 - i; 
                    b_index = b._npartes - 1 - i; 

                    //cout<< "B: "<< b._partes[b_index]<< " ";
                    //cout<< "A: "<< a._partes[a_index]<< " ";
                    // nao precisa ser considerado a subtracai de a pois ela nao existe
                    if(i >= a._npartes){ resultado_soma = b._partes[b_index] + carry; }  /// talvez nao tenha o igual aq
                    else{ resultado_soma = - ( a._partes[a_index] ) + b._partes[b_index] + carry; }

                    /// pensar em como fazer carry da subtracao
                    if(resultado_soma <0){ // carry tem que carregar valor negativo e tem-se que subtrair do valor que o carry vai retirar
                        resultado_soma = 1000000000 + resultado_soma; // subtrai do valor que sera retirado do proximo _partes 
                        carry = -1; // carry subtrai na proxima operacao
                    }
                    else{
                        carry = 0;
                    }

                    retorno_bigint._partes[b_index+1] = resultado_soma;
                }
                retorno_bigint._npartes= b._npartes;
                retorno_bigint._positivo = true;
                
            }
            else{ // quando a >= b
            //cout<< "CHEGUEI AQ AO MENOS";
                retorno_bigint._partes = new int[a._npartes + 1]; // desloca número de partes necessárias para soma (+1 pois pode-se ter um carry para uma nova parte)
            
                // indice que inicia no fim do vetor para bom funcionamento do codigo
                int a_index;
                int b_index;

                // Subtrai a partir do último dígito para facilitar a execucao do codigo
                for(int i = 0; i < a._npartes; i++){
                    a_index = a._npartes - 1 - i; 
                    b_index = b._npartes - 1 - i; 

                    //cout<< "B: "<< b._partes[b_index]<< " ";
                    //cout<< "A: "<< a._partes[a_index]<< " ";
                    // nao precisa ser considerado a subtracai de a pois ela nao existe
                    if(i >= b._npartes){ resultado_soma = b._partes[b_index] + carry; }  /// talvez nao tenha o igual aq
                    else{ resultado_soma = - ( a._partes[a_index] ) + b._partes[b_index] + carry; }

                    /// pensar em como fazer carry da subtracao
                    if(resultado_soma <0){ // carry tem que carregar valor negativo e tem-se que subtrair do valor que o carry vai retirar
                        resultado_soma = 1000000000 + resultado_soma; // subtrai do valor que sera retirado do proximo _partes 
                        carry = -1; // carry subtrai na proxima operacao
                    }
                    else{
                        carry = 0;
                    }

                    retorno_bigint._partes[b_index+1] = resultado_soma;
                }
                retorno_bigint._npartes= b._npartes;
                
                BigInt aux;
                aux = b;
                aux = aux.abs();

                if(aux > a){
                    //cout<< "PORRA";
                    retorno_bigint._positivo= true;
                }
                else{ 
                    //cout<< "CARALHGO";
                    retorno_bigint._positivo = false;}
            }
        }  
        else{  // a - b
            if( b._npartes >= a._npartes){ /// talvez esteja errado
                retorno_bigint._partes = new int[b._npartes + 1]; // desloca número de partes necessárias para soma (+1 pois pode-se ter um carry para uma nova parte)
            
                // indice que inicia no fim do vetor para bom funcionamento do codigo
                int a_index;
                int b_index;

                // Subtrai a partir do último dígito para facilitar a execucao do codigo
                for(int i = 0; i < b._npartes; i++){
                    a_index = a._npartes - 1 - i; 
                    b_index = b._npartes - 1 - i; 

                    //cout<< "B: "<< b._partes[b_index]<< " ";
                    //cout<< "A: "<< a._partes[a_index]<< " ";
                    // nao precisa ser considerado a subtracai de a pois ela nao existe
                    if(i >= a._npartes){ resultado_soma = b._partes[b_index] + carry; }  /// talvez nao tenha o igual aq
                    else{ resultado_soma = - ( a._partes[a_index] ) + b._partes[b_index] + carry; }

                    /// pensar em como fazer carry da subtracao
                    if(resultado_soma <0){ // carry tem que carregar valor negativo e tem-se que subtrair do valor que o carry vai retirar
                        resultado_soma = 1000000000 + resultado_soma; // subtrai do valor que sera retirado do proximo _partes 
                        carry = -1; // carry subtrai na proxima operacao
                    }
                    else{
                        carry = 0;
                    }

                    retorno_bigint._partes[b_index+1] = resultado_soma;
                }
                retorno_bigint._npartes= b._npartes;
                
                BigInt aux;
                aux = b;
                aux = aux.abs();

                if(aux > a){
                    //cout<< "PORRA";
                    retorno_bigint._positivo= false;
                }
                else{ 
                    //cout<< "CARALHGO";
                    retorno_bigint._positivo = true;}
            }
            else{ // quando a > b
                retorno_bigint._partes = new int[a._npartes + 1]; // desloca número de partes necessárias para soma (+1 pois pode-se ter um carry para uma nova parte)
            
                // indice que inicia no fim do vetor para bom funcionamento do codigo
                int a_index;
                int b_index;

                // Subtrai a partir do último dígito para facilitar a execucao do codigo
                for(int i = 0; i < a._npartes; i++){
                    a_index = a._npartes - 1 - i; 
                    b_index = b._npartes - 1 - i; 

                    // nao precisa ser considerado a subtracai de b pois ela nao existe
                    if(i >= b._npartes){ resultado_soma = ( a._partes[a_index]) + carry; }  /// talvez nao tenha o igual aq
                    else{ resultado_soma = ( a._partes[a_index] ) - ( b._partes[b_index] ) + carry; }

                    /// pensar em como fazer carry da subtracao
                    if(resultado_soma <0){ // carry tem que carregar valor negativo e tem-se que subtrair do valor que o carry vai retirar
                        resultado_soma = 1000000000 + resultado_soma; // subtrai do valor que sera retirado do proximo _partes 
                        carry = -1; // carry subtrai na proxima operacao
                    }
                    else{
                        carry=0;
                    }
                    
                    //cout<<"DEBBUG a - b:" << preenche_zeros(to_string(resultado_soma))<< endl;
                    retorno_bigint._partes[ a_index+1] = resultado_soma;
                    
                }
                retorno_bigint._npartes= a._npartes;
                retorno_bigint._positivo = true;
            }
        }
    }

    return retorno_bigint;
}

BigInt operator-(const BigInt &a, const BigInt &b){
    BigInt aux;
    aux = b; // copia ja definifa

    aux._positivo = ! (aux._positivo);

    return a + aux; // realiza adicao ja definida
}

// para essa funcao foi feita a soma em partes dos numeros, assim como feita na vida real manualmente
BigInt operator*(const BigInt &a, const BigInt &b){
    // fonte: https://learn.microsoft.com/pt-br/cpp/cpp/data-type-ranges?view=msvc-170
    unsigned long long resultado_mult=0; // pior caso 10e9 * 10e9, dando 10e18, unsiigned tem 1,8 10e19 // fazer pelo menos 3 inspecoes de carry?
    unsigned long long carry=0;
    unsigned long long res_a, res_b=0; // utilizado pois ao se multiplicar, valores sao perdidos
    BigInt retorno_bigint;

    retorno_bigint._npartes = a._npartes + b._npartes; // considera o pior caso
    
    // guarda as multiplicacoes feitas em partes
    BigInt *partes_soma = new BigInt[retorno_bigint._npartes];

    // comecar a multiplicacao

    int a_index=0;
    int b_index=0;
    
    string numero_string, string_final;

    // carry primeiro considerando ordem do numero
    // carry terceiro define a posicao atual de insercao
    //int carry_primeiro, carry_segundo, carry_terceiro =0; // responsaveis por guardar em partes o valor de 10e19 ( carry primeiro eh o do meio )
    int aux;
    int numero_ciclos=0;
    int varredura_a=0;
    int varredura_b=0;
    //cout<< "################ COMECOU A MULTIPLICACAO"<< endl;;
    if(a._npartes>=b._npartes){
        //numero_ciclos= a._npartes;
        while(varredura_b< b._npartes){

            // escreve os zeros no final da string decorrente dp valor do b
            
            aux=0;
            while(aux!=varredura_b){
                //cout<< "VERIFICA ERRO"<<endl;
                string_final= string_final + "000000000";
                //cout<< string_final<<endl;
                aux++;
            }
            while(varredura_a< a._npartes){
                
                // comecam do ultimo valor
                a_index = a._npartes - 1 - varredura_a; 
                b_index = b._npartes - 1 - varredura_b; 

                res_a= a._partes[a_index];
                res_b= b._partes[b_index];

                //cout<< "NUMERO A "<< res_a << " NUMERO B "<< res_b << endl;
                resultado_mult = (res_a * res_b) + carry;
                //cout<< "RESULTADO MUL "<< resultado_mult<< endl;

                carry = resultado_mult/1000000000; // como ele eh int, nao aproxima para cima e guarda valor correto casa exista carry
                //cout<< "CARRY DA DIV " << carry << endl;
                numero_string = to_string( resultado_mult%1000000000 );

                if(a_index!=0){ // caso nao seja o numero mais significativo, preenche com zeros
                    numero_string = preenche_zeros(numero_string);
                } 
                
                string_final = numero_string + string_final; // contatena numero obtido
                //cout<< "DEBBBUF "<<string_final<<endl;
                varredura_a++;
            }

            if(carry!=0){ // ainda tem numero para ser inserido
            //cout<< "CARRY"<< carry<< endl;
                numero_string = to_string(carry);
                string_final = numero_string + string_final; // contatena numero obtido
            }
            
            varredura_b++;
            varredura_a=0;

            // cria valor de bigint com string resultante
            //cout<<string_final<<" Armazenado em "<< b_index<<endl;
            partes_soma[b_index] = BigInt(string_final);
            string_final.clear(); // limpa buffer da string
            //cout<< "termina um numero aq"<< endl;
        }
        
        BigInt aux;
        // passa a limpo as partes da soma obtida
        aux = partes_soma[0];
        retorno_bigint = aux;
        //cout<< "Retorno BIG INT  "<< retorno_bigint;
        //cout<< "VALOR VERDADEIRO " << partes_soma[0];

        for(int i=1; i < b._npartes; i++){ 
            aux = retorno_bigint + partes_soma[i];
            retorno_bigint = aux;
            //cout<< "Retorno Big INt  " <<retorno_bigint;
            //cout<< "VALOR soma       " << (partes_soma[i]) <<" " << i;
        }    // ja altera o valor de _npartes    
    }
    else{ // a<b
        //numero_ciclos= a._npartes;
        while(varredura_a< a._npartes){

            // escreve os zeros no final da string decorrente dp valor do b
            int aux=0;
            while(aux!=varredura_a){
                string_final+= to_string( 000000000 );
                aux++;
            }

            while(varredura_b< b._npartes){
                
                // comecam do ultimo valor
                a_index = a._npartes - 1 - varredura_a; 
                b_index = b._npartes - 1 - varredura_b; 

                res_a= a._partes[a_index];
                res_b= b._partes[b_index];

                //cout<< "NUMERO A "<< res_a << " NUMERO B "<< res_b << endl;
                resultado_mult = (res_a * res_b) + carry;
                //cout<< "RESULTADO MUL "<< resultado_mult<< endl;

                carry = resultado_mult/1000000000; // como ele eh int, nao aproxima para cima e guarda valor correto casa exista carry
                numero_string = to_string( resultado_mult%1000000000 );

                if(b_index!=0){ // caso nao seja o numero mais significativo, preenche com zeros
                    numero_string = preenche_zeros(numero_string);
                } 
                
                string_final = numero_string + string_final; // contatena numero obtido
                //cout<< "DEBBBUF"<<string_final<<endl;
                varredura_b++;
            }

            if(carry!=0){ // ainda tem numero para ser inserido
            //cout<< "CARRY"<< carry<< endl;
                numero_string = to_string(carry);
                string_final = numero_string + string_final; // contatena numero obtido
            }
            
            varredura_a++;
            varredura_b=0;

            // cria valor de bigint com string resultante
            //cout<<string_final<<" Armazenado em "<< a_index<<endl;
            partes_soma[a_index] = BigInt(string_final);
            string_final.clear(); // limpa buffer da string
        }

        BigInt aux;
        // passa a limpo as partes da soma obtida
        aux = partes_soma[0];
        retorno_bigint = aux;
        //cout<< retorno_bigint;
        //cout<< partes_soma[0];
        for(int i=1; i < a._npartes; i++){ 
            aux = retorno_bigint + partes_soma[i];
            retorno_bigint = aux;
            //cout<< retorno_bigint;
            //cout<< partes_soma[i];
            
        } // ja altera o valor de _npartes
            
    }

    if(a._positivo!=b._positivo){ // caso +/- e -/+
        retorno_bigint._positivo= false;
    }
    else{
        retorno_bigint._positivo = true;
    }

    return retorno_bigint;
}

BigInt operator^(const BigInt &a, const BigInt &b){

    // se a base for zero, ja retorna 1
    // inicializa o valor que sera retornado
    BigInt resultado("1");
    if(b == BigInt("0")){ return BigInt("1"); } 
    else{
        // Variaveis auxiliares
        BigInt expoente;
        BigInt base;
        base = a;
        expoente = b;

        for(int i = 0; i < expoente._npartes; i++){
            for(int j=0; j < expoente._partes[j] ; j++){
                resultado= resultado* base;
            }    
        }
    }

    return resultado;
}
