#include "Titulo.h"

/**
 * @brief Define o c�digo do t�tulo.
 *
 * @param codigo O c�digo do t�tulo.
 */
void Titulo::setCodigo(const std::string& codigo) {
    this->codigo = codigo;
}

/**
 * @brief Define o CPF associado ao t�tulo.
 *
 * @param cpf O CPF do titular do t�tulo.
 */
void Titulo::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

/**
 * @brief Retorna o CPF associado ao t�tulo.
 *
 * @return std::string O CPF do titular do t�tulo.
 */
std::string Titulo::getCpf() const {
    return cpf;
}

/**
 * @brief Retorna o c�digo do t�tulo.
 *
 * @return std::string O c�digo do t�tulo.
 */
std::string Titulo::getCodigo() const {
    return codigo;
}

/**
 * @brief Define o emissor do t�tulo.
 *
 * @param emissor O nome do emissor do t�tulo.
 */
void Titulo::setEmissor(const std::string& emissor) {
    this->emissor = emissor;
}

/**
 * @brief Retorna o emissor do t�tulo.
 *
 * @return std::string O nome do emissor do t�tulo.
 */
std::string Titulo::getEmissor() const {
    return emissor;
}

/**
 * @brief Define o setor do t�tulo.
 *
 * @param setor O setor associado ao t�tulo.
 */
void Titulo::setSetor(const std::string& setor) {
    this->setor = setor;
}

/**
 * @brief Retorna o setor do t�tulo.
 *
 * @return std::string O setor associado ao t�tulo.
 */
std::string Titulo::getSetor() const {
    return setor;
}

/**
 * @brief Define a data de emiss�o do t�tulo.
 *
 * @param dataEmissao A data de emiss�o do t�tulo no formato "DD/MM/AAAA".
 */
void Titulo::setDataEmissao(const std::string& dataEmissao) {
    this->dataEmissao = dataEmissao;
}

/**
 * @brief Retorna a data de emiss�o do t�tulo.
 *
 * @return std::string A data de emiss�o do t�tulo no formato "DD/MM/AAAA".
 */
std::string Titulo::getDataEmissao() const {
    return dataEmissao;
}

/**
 * @brief Define a data de vencimento do t�tulo.
 *
 * @param dataVencimento A data de vencimento do t�tulo no formato "DD/MM/AAAA".
 */
void Titulo::setDataVencimento(const std::string& dataVencimento) {
    this->dataVencimento = dataVencimento;
}

/**
 * @brief Retorna a data de vencimento do t�tulo.
 *
 * @return std::string A data de vencimento do t�tulo no formato "DD/MM/AAAA".
 */
std::string Titulo::getDataVencimento() const {
    return dataVencimento;
}

/**
 * @brief Define o valor do t�tulo.
 *
 * @param valor O valor do t�tulo.
 */
void Titulo::setValor(double valor) {
    this->valor = valor;
}

/**
 * @brief Retorna o valor do t�tulo.
 *
 * @return double O valor do t�tulo.
 */
double Titulo::getValor() const {
    return valor;
}
