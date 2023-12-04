#include "DataHorario.h"

#include <iostream>
#include <string>
#include <iomanip>

DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) :
dia(dia), mes(mes), ano(ano), hora(hora), minuto(minuto), segundo(segundo) {
    // Declarando as variaveis como falso para verificar uma data é válida
    bool diaValido = false;
    bool mesValido = false;
    bool anoValido = false;
    bool horaValido = false;
    bool minutoValido = false;
    bool segundoValido = false;
    bool anoBissexto = false;

    // Validar se é um ano bissexto
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        anoBissexto = true;
    // Valida ano
    if (ano >= 0)
        anoValido = true;
    // Validar mes
    if (mes >= 1 && mes <= 12)
        mesValido = true;
    // Validar dia
    if (dia >= 1) {
        // Meses que terminam com dia == 31
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || 
        mes == 8 || mes == 10 || mes == 12) {
            if (dia <= 31)
                diaValido = true;
          // Meses que terminam com dia == 30  
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 1) {
            if (dia <= 30)
                diaValido = true;
          // Mes igual a 2 e verifica se é bissexto ou nao  
        } else if (mes == 2) {
            if (anoBissexto && dia <= 29)
                diaValido = true;
            else if (!anoBissexto && dia <= 28)
                diaValido = true;
        } 
    }
    // Validar horas
    if (hora >= 0 && hora <= 24)
        horaValido = true;
    // Validar minuto
    if (minuto >= 0 && minuto <= 60)
        minutoValido = true;
    // Validar segundos
    if (segundo >= 0 && segundo <= 60)
        segundoValido = true;
    // Verificar, entao, se a data é valida
    if (diaValido && mesValido && anoValido && horaValido && minutoValido && segundoValido) {
        // Atualiza os parametros, apontando para o objeto para o qual a função de membro é chamada
        this->dia = dia; 
        this->mes = mes;
        this->ano = ano;
        this->hora = hora;
        this->minuto = minuto;
        this->segundo = segundo;
    } else { // Caso nao seja valida, atualizar para 01/01/0001 00:00:00
        dia = 1;
        mes = 1;
        ano = 1;
        hora = 0;
        minuto = 0;
        segundo = 0;
    }
}

DataHorario::~DataHorario() {}

int DataHorario::compara(const DataHorario& data) const {
    // Neste método, será retornado:
        // < 0 se a data corrente for menor que a do parametro
        // 0 se a data corrente for igual a do parametro
        // > 0 se a data corrente for maior que a do parametro
    if (this->ano != data.ano) { // --> verifica se os anos sao diferentes
        return this->ano - data.ano; // --> retorna a sua comparação
    } else if (this->mes != data.mes) { // --> verifica se os meses sao diferentes
        return this->mes - data.mes; // --> retorna a sua comparação
    } else { // --> por fim, verifica se os dias sao diferentes
        return this->dia - data.dia; // --> retorna a sua comparação
    }
}

/* <---GETTERS AND SETTERS---> */

int DataHorario::getDia() const { // Método responsável por retornar o dia da data.
    return dia;
}

void DataHorario::setDia(int dia) { // Método responsável por setar o atributo dia do objeto DataHorario
    this->dia = dia;
}

int DataHorario::getMes() const { // Método responsável por retornar o mês da data
    return mes;
}

void DataHorario::setMes(int mes) { // Método responsável por setar o mes do objeto DataHorario
    this->mes = mes;
}

int DataHorario::getAno() const { // Método responsável por retornar o ano da data
    return ano;
}

void DataHorario::setAno(int ano) { // Método responsável por setar o ano do objeto DataHorario
    this->ano = ano;
}

int DataHorario::getHora() const { // Método responsável por retornar a hora do horário.
    return hora;
}

void DataHorario::setHora(int hora) { // Método responsável por setar a hora do objeto DataHorario
    this->hora = hora;
}

int DataHorario::getMinuto() const { // Método responsável por retornar o minuto do horário
    return minuto;
}

void DataHorario::setMinuto(int minuto) { // Método responsável por setar o minuto do objeto DataHorario
    this->minuto = minuto;
}

int DataHorario::getSegundo() const { // Método responsável por retornar o segundo do horário.
    return segundo;
}

void DataHorario::setSegundo(int segundo) { // Método responsável por setar o segundo do objeto DataHorario
    this->segundo = segundo;
}

/* <---GETTERS AND SETTERS---> */

void DataHorario::imprime(bool padrao) const { // Método responsável pela impressão das informações de uma data/horário.
                                                     // AM/PM
    if (!padrao) { // Se não for PM, imprima normal (15:57:10)
        cout << setfill('0') << setw(2) << dia << "/" << setw(2) << mes << "/" << ano << " " << setw(2) << hora << ":" << setw(2) << minuto << ":" << setw(2) << segundo << endl;
    } else { // Se for PM, retirar 12 do valor padrao da hora e imprimir (3:57:10 PM)
        int meridiano = 12;
        cout << dia - meridiano << "/" << mes << "/" << ano << " " << hora << ":" << minuto << ":" << segundo << endl;
    }
}

void DataHorario::imprimePorExtenso() const{
    // Método responsável pela impressão de uma data por extenso
    string meses; 
    switch(mes) { // Utilização de switch case para selecionar o mes de acordo com o parametro
        case 1: meses = "Janeiro"; break;
        case 2: meses = "Fevereiro"; break;
        case 3: meses = "Março"; break;
        case 4: meses = "Abril"; break;
        case 5: meses = "Maio"; break;
        case 6: meses = "Junho"; break;
        case 7: meses = "Julho"; break;
        case 8: meses = "Agosto"; break;
        case 9: meses = "Setembro"; break;
        case 10: meses = "Outubro"; break;
        case 11: meses = "Novembro"; break;
        case 12: meses = "Dezembro"; break;
    }
    // Imprimir o dia, mes, ano, hora, minuto e segundo com setfill(Define o preenchimento dos caracteres) e setw(Define a largura de um campo)
    cout << setfill('0') << setw(2) << dia << " de "; 
    cout << meses << " de ";
    cout << setfill('0') << setw(4) << ano << " -- " << hora << " hora(s), " << setw(2) << minuto << " minuto(s) " << "e " << setw(2) << segundo << " segundos " << endl;
}
