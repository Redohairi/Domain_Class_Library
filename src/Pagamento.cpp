#include "Pagamento.h"
#include <stdexcept>
#include <regex>
#include <vector>
#include <algorithm>

/**
 * @brief Função auxiliar para validar a data.
 *
 * @param data A string contendo a data a ser validada no formato "DD/MM/AAAA".
 * @return true se a data for válida, false caso contrário.
 */
bool validarData(const std::string& data) {
    // Supondo o formato da data como "DD/MM/AAAA"
    std::regex dataRegex(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(data, dataRegex)) {
        return false;
    }

    int dia = std::stoi(data.substr(0, 2));
    int mes = std::stoi(data.substr(3, 2));
    int ano = std::stoi(data.substr(6, 4));

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2100) {
        return false;
    }

    // Verificação dos dias por mês
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }

    if (mes == 2) {
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > 29 || (dia == 29 && !bissexto)) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Define a data do pagamento.
 *
 * @param data A string contendo a data do pagamento no formato "DD/MM/AAAA".
 * @throw std::invalid_argument Se a data for inválida.
 */
void Pagamento::setData(const std::string& data) {
    if (!validarData(data)) {
        throw std::invalid_argument("Data inválida.");
    }
    this->data = data;
}

/**
 * @brief Define o valor do pagamento.
 *
 * @param valor O valor do pagamento.
 * @throw std::invalid_argument Se o valor estiver fora do intervalo permitido (0 a 1.000.000,00).
 */
void Pagamento::setValor(double valor) {
    if (valor < 0 || valor > 1000000) {
        throw std::invalid_argument("Valor do pagamento deve estar entre 0 e 1.000.000,00.");
    }
    this->valor = valor;
}

/**
 * @brief Define o estado do pagamento.
 *
 * @param estado A string contendo o estado do pagamento.
 * @throw std::invalid_argument Se o estado não for válido.
 */
void Pagamento::setEstado(const std::string& estado) {
    std::vector<std::string> estadosValidos = {"Previsto", "Liquidado", "Inadimplente"};
    if (std::find(estadosValidos.begin(), estadosValidos.end(), estado) == estadosValidos.end()) {
        throw std::invalid_argument("Estado inválido.");
    }
    this->estado = estado;
}
