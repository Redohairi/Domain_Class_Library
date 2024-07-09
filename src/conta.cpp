#include "Conta.h"
#include <stdexcept> // Biblioteca para exceções padrão
#include <cctype>    // Biblioteca para funções de caracter

/**
 * @brief Função auxiliar para validar CPF
 * @param cpf: string contendo o CPF a ser validado
 * @return true se o CPF for válido, false caso contrário
 */
bool validarCPF(const std::string& cpf) {
    int soma = 0, resto;
    if (cpf.length() != 11)
        return false;

    // Validando primeiro dígito verificador
    for (int i = 1; i <= 9; i++)
        soma += int(cpf[i - 1] - '0') * (11 - i);
    resto = (soma * 10) % 11;
    if ((resto == 10) || (resto == 11)) resto = 0;
    if (resto != int(cpf[9] - '0')) return false;

    soma = 0;
    // Validando segundo dígito verificador
    for (int i = 1; i <= 10; i++)
        soma += int(cpf[i - 1] - '0') * (12 - i);
    resto = (soma * 10) % 11;
    if ((resto == 10) || (resto == 11)) resto = 0;
    if (resto != int(cpf[10] - '0')) return false;

    return true;
}

/**
 * @brief Define o CPF do titular da conta.
 * @param cpf: string contendo o CPF do titular.
 * @throw std::invalid_argument se o CPF for inválido.
 */
void Conta::setCpf(const std::string& cpf) {
    if (!validarCPF(cpf)) {
        throw std::invalid_argument("CPF inválido");
    }
    this->cpf = cpf;
}

/**
 * @brief Retorna o CPF do titular da conta.
 * @return string com o CPF do titular.
 */
std::string Conta::getCpf() const {
    return cpf;
}

/**
 * @brief Define o nome do titular da conta.
 * @param nome: string contendo o nome do titular.
 * @throw std::invalid_argument se o nome for vazio, tiver menos de 3 caracteres, ou contiver caracteres inválidos.
 */
void Conta::setNome(const std::string& nome) {
    if (nome.empty() || nome.length() < 3) {
        throw std::invalid_argument("O nome não pode ser vazio e deve ter pelo menos 3 caracteres");
    }
    for (char c : nome) {
        if (!std::isalpha(c) && c != ' ') {
            throw std::invalid_argument("O nome deve conter apenas letras e espaços");
        }
    }
    this->nome = nome;
}

/**
 * @brief Retorna o nome do titular da conta.
 * @return string com o nome do titular.
 */
std::string Conta::getNome() const {
    return nome;
}

/**
 * @brief Função auxiliar para validar a senha.
 * @param senha: string contendo a senha a ser validada.
 * @return true se a senha for válida, false caso contrário.
 */
bool validarSenha(const std::string& senha) {
    if (senha.size() < 8) {
        return false; // Senha deve ter pelo menos 8 caracteres
    }
    bool temLetra = false, temNumero = false;
    for (char c : senha) {
        if (std::isalpha(c)) temLetra = true;
        if (std::isdigit(c)) temNumero = true;
    }
    return temLetra && temNumero;
}

/**
 * @brief Define a senha de acesso da conta.
 * @param senha: string contendo a senha.
 * @throw std::invalid_argument se a senha for inválida.
 */
void Conta::setSenha(const std::string& senha) {
    if (!validarSenha(senha)) {
        throw std::invalid_argument("Senha deve conter pelo menos 8 caracteres, incluindo letras e números");
    }
    this->senha = senha;
}

/**
 * @brief Retorna a senha de acesso da conta.
 * @return string com a senha.
 */
std::string Conta::getSenha() const {
    return senha;
}
