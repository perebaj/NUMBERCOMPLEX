#include <iostream>
#include <string>
//using namespace std;

class Complex
{

  public:
    int real, imag;

    Complex(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }
    /*
    Tipo de retorno tem que ser igual ao q eu estou sobrecarregando, no caso, um objeto complexo
    */

    Complex operator+(const Complex &c)
    {
        /*
        Imprimindo real e imag dentro da função, para mostrar que o objeto que esta a direita do operador sobrecaregado 
        é o objeto que esta sendo "Acessado", o da esquerda no caso, esta sendo passado por referência.
        acessado.
        EX:        
        c3 = c1 + c2 < C2 ESTA SENDO PASSADO POR REFERENCIA NESSA SINTAXE.
              ^AQUI C1 ESTA A DIREITA DO OPERADOR SOBRECARREGADO (+).
        */
        std::cout << "C1 real:" << real << std::endl;
        std::cout << "C1 imaginario:" << imag << std::endl;
        std::cout << "C4 real:" << c.real << std::endl;
        std::cout << "C4 imaginario:" << c.imag << std::endl;
        return Complex(this->real + c.real, this->imag + c.imag);
    }

    Complex operator+(int a);
    Complex operator*(const Complex &c)
    {
        return Complex(this->real * c.real, this->imag * c.imag);
    }
    friend std::ostream &operator<<(std::ostream &, Complex &);
};
/*
Sobrecarga do operador <<
*/
std::ostream &operator<<(std::ostream &output, const Complex &c)
{
    output << c.real << " + " << c.imag << "i" << std::endl; //Aqui todas as informaçõs são jogadas em output, depois no final retorna-se ele.

    return (output);
}

/*
    Sobrecarga do operador +, para somar o objeto com um numero inteiro
    */
Complex Complex::operator+(int a)
{ //{tipo de retorno} {classe referida} :: NOME DA FUNÇÃO
    return Complex(real + a, imag);
}

int main()
{

    Complex c1(2, 3), c2(3, 7), c4(4, 6), c3;


    std::cout << "RESULTADO DA SOMA: " << std::endl;
    c3 = c1 + c4; // O QUE ESTA ACONTECENDO AQUI É EQUIVALENTE À c3 = c1.operator+(c2);
    std::cout << "c3 = " << c3;
    std::cout << "<==================================>" << std::endl;
    std::cout << "RESULTADO DA SOMA COM UM INTEIRO: " << std::endl;
    c1 = c1 + 4;  //c1 = c1.operator+(4);
    std::cout << "c1 = " << c1;
    std::cout << "<==================================>" << std::endl;
    std::cout << "RESULTADO DA MULTIPLICAÇAO: " << std::endl;
    c1 = c1 * c2; //c1 = c1.operator*(c2);
    std::cout << "c1 = " << c1;
}