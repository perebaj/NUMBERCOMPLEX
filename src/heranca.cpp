#include <iostream>
using namespace std;
class Funcionario{
    private:
        string nome;
        int codigo;
        double salario;
        static int num_Func; //Numero de funcionários ativos
    public:
        int get_codigo()const{return codigo;}
        double get_salario()const{return salario;}
        string get_nome()const{return nome;}
        int get_NUMFUNC()const{return num_Func;}

        void set_remuneracao(double salario){
            if(salario > 0){
                this->salario = salario;
            }
            else 
                salario = 0;
        }
        void set_codigo(int codigo){
            if(codigo > 0) {
                this->codigo = codigo;
            }
            else
                this->codigo = 0;
        }

        Funcionario(int codigo, double salario, string nome){
            set_codigo(codigo);
            set_remuneracao(salario);
            this -> nome = nome;
            num_Func++;
        }
};

int Funcionario::num_Func = 0;

class Gerente : public Funcionario{
    
    private:
        int p_sup = 0; //quantidade de pessoas supervisionadas;
    public:

        void set_sup(){
            p_sup = get_NUMFUNC();
        }
        int get_PSUP() const {return p_sup;}
        double get_remuneracao() const{
            return (get_salario() + get_PSUP()*0.001);
        }
    Gerente(int codigo, double salario, string nome): Funcionario(codigo, salario, nome){}
    void print() const{
        cout << "NUMERO DE FUNCIONARIOS SUPERVISIONADOS: " << get_PSUP() << endl;
        cout << "REMUNERAÇÃO: " << get_remuneracao() << endl;
        cout << "CODIGO: " << get_codigo() << endl;
        
    }

};

int main(){
    Funcionario f1(001, 1000.0, "José");
    Gerente g1(002, 20.0, "JONATHAN");
    g1.print();
    cout <<f1.get_NUMFUNC();
    cout << g1.get_PSUP();
}