#include "Titulo.h"

/**
 * @brief Define o código do título.
 *
 * @param codigo O código do título.
 */
void Titulo::setCodigo(const std::string& codigo) {
    this->codigo = codigo;
}

/**
 * @brief Define o CPF associado ao título.
 *
 * @param cpf O CPF do titular do título.
 */
void Titulo::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

/**
 * @brief Retorna o CPF associado ao título.
 *
 * @return std::string O CPF do titular do título.
 */
std::string Titulo::getCpf() const {
    return cpf;
}

/**
 * @brief Retorna o código do título.
 *
 * @return std::string O código do título.
 */
std::string Titulo::getCodigo() const {
    return codigo;
}

/**
 * @brief Define o emissor do título.
 *
 * @param emissor O nome do emissor do título.
 */
void Titulo::setEmissor(const std::string& emissor) {
    this->emissor = emissor;
}

/**
 * @brief Retorna o emissor do título.
 *
 * @return std::string O nome do emissor do título.
 */
std::string Titulo::getEmissor() const {
    return emissor;
}

/**
 * @brief Define o setor do título.
 *
 * @param setor O setor associado ao título.
 */
void Titulo::setSetor(const std::string& setor) {
    this->setor = setor;
}

/**
 * @brief Retorna o setor do título.
 *
 * @return std::string O setor associado ao título.
 */
std::string Titulo::getSetor() const {
    return setor;
}

/**
 * @brief Define a data de emissão do título.
 *
 * @param dataEmissao A data de emissão do título no formato "DD/MM/AAAA".
 */
void Titulo::setDataEmissao(const std::string& dataEmissao) {
    this->dataEmissao = dataEmissao;
}

/**
 * @brief Retorna a data de emissão do título.
 *
 * @return std::string A data de emissão do título no formato "DD/MM/AAAA".
 */
std::string Titulo::getDataEmissao() const {
    return dataEmissao;
}

/**
 * @brief Define a data de vencimento do título.
 *
 * @param dataVencimento A data de vencimento do título no formato "DD/MM/AAAA".
 */
void Titulo::setDataVencimento(const std::string& dataVencimento) {
    this->dataVencimento = dataVencimento;
}

/**
 * @brief Retorna a data de vencimento do título.
 *
 * @return std::string A data de vencimento do título no formato "DD/MM/AAAA".
 */
std::string Titulo::getDataVencimento() const {
    return dataVencimento;
}

/**
 * @brief Define o valor do título.
 *
 * @param valor O valor do título.
 */
void Titulo::setValor(double valor) {
    this->valor = valor;
}

/**
 * @brief Retorna o valor do título.
 *
 * @return double O valor do título.
 */
double Titulo::getValor() const {
    return valor;
}
