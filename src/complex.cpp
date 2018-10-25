#include <iostream>
#include <string>
//using namespace std;

class Complex
{
  private:
    int real, imag;

  public:
    //Constrututor
    Complex(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }

    const Complex operator+(const Complex &c) const;
    const Complex operator+(int a) const;
    const Complex operator*(const Complex &c) const;
    const Complex operator++(int);
    const bool operator==(const Complex &c)const ;

    
    //Funçoes Friends :

    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend const Complex operator+(int a, const Complex &c);
};
/*
    VERIFICANDO SE OS OBJETOS SÃO IGUAIS, COMPARANDO SUAS VARIÁVEIS IMAGINÁROAS E REAIS
*/
const bool Complex::operator==(const Complex &c) const {
    if(this->real == c.real && this->imag == c.imag)
        return true;
    else 
        return false;
}

const Complex Complex::operator++(int)
{
    Complex c1(*this);
    real++;
    return c1;
}
const Complex operator+(int a, const Complex &c)
{
    return Complex(a + c.real, c.imag);
}
/*
    Tipo de retorno tem que ser igual ao q eu estou sobrecarregando, no caso, um objeto complexo
   
    Imprimindo real e imag dentro da função, para mostrar que o objeto que esta a direita do operador sobrecaregado 
    é o objeto que esta sendo "Acessado", o da esquerda no caso, esta sendo passado por referência.
    acessado.
    EX:        
    c3 = c1 + c2 < C2 ESTA SENDO PASSADO POR REFERENCIA NESSA SINTAXE
              ^AQUI C1 ESTA A DIREITA DO OPERADOR SOBRECARREGADO (+).
        */
const Complex Complex::operator+(const Complex &c) const
{
    return Complex(this->real + c.real, this->imag + c.imag);
}

/*
    Sobrecarga do operador +, para somar o objeto com um numero inteiro
    */
const Complex Complex::operator+(int a) const
{ //{tipo de retorno} {classe referida} :: NOME DA FUNÇÃO
    return Complex(real + a, imag);
}
/*
    Sobrecarga do operador (*) para multiplicar dois objetos
*/
const Complex Complex::operator*(const Complex &c) const
{
    return Complex(this->real * c.real, this->imag * c.imag);
    //return Complex(this->real *, this-> imag = 3)
}

/*
Sobrecarga do operador <<
*/
std::ostream &operator<<(std::ostream &output, const Complex &c)
{
    output << c.real << " + " << c.imag << "i" << std::endl;
    return output;
}

int main()
{
    int  a = 10;
    Complex c1(2, 3), c2(3, 7), c4(4, 6), c3,c7,c8;

    std::cout << "RESULTADO DA SOMA: " << std::endl;
    c3 = c1 + c4; // O QUE ESTA ACONTECENDO AQUI É EQUIVALENTE À c3 = c1.operator+(c2);
    std::cout << "c3 = " << c3;
    std::cout << "<==================================>" << std::endl;
    std::cout << "RESULTADO DA SOMA COM UM INTEIRO: " << std::endl;
    c1 = c1 + 4; //c1 = c1.operator+(4);
    std::cout << "c1 = " << c1;
    std::cout << "<==================================>" << std::endl;
    std::cout << "RESULTADO DA MULTIPLICAÇAO: " << std::endl;
    c1 = c1 * c2; //c1 = c1.operator*(c2);
    std::cout << "c1 = " << c1;
    std::cout << "SOMA COM O TIPO INT À ESQUERDA DO OPERADOR: " << std::endl;
    c1 = 4 + c1;
    std::cout << c1;
    std::cout << "<==================================>" << std::endl;
    std::cout << "OPERADOR++ POS FIXADO: " << std::endl;
    c3++;
    std::cout << c3 << std::endl;
    std::cout << "<==================================>" << std::endl;
    std::cout << "VERIFICANDO SE DOIS OBJETOS SÃO IGUAIS: " << std::endl;
    if(c7.operator==(c8))
        std::cout << "IGUAIS: " << std::endl;
    else
        std::cout << "N IGUAIS: " << std::endl;
    
    
}