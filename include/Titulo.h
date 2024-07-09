#ifndef TITULO_H
#define TITULO_H

#include <string>

/**
 * @brief Classe Titulo
 *
 * Esta classe representa um título com informações detalhadas como código, emissor, setor, datas de emissão e vencimento, valor e CPF do titular.
 */
class Titulo {
private:
    std::string codigo;         ///< Código do título
    std::string emissor;        ///< Nome do emissor do título
    std::string setor;          ///< Setor associado ao título
    std::string dataEmissao;    ///< Data de emissão do título no formato "DD/MM/AAAA"
    std::string dataVencimento; ///< Data de vencimento do título no formato "DD/MM/AAAA"
    double valor;               ///< Valor do título
    std::string cpf;            ///< CPF do titular do título

public:
    /**
     * @brief Define o CPF associado ao título.
     *
     * @param cpf O CPF do titular do título.
     */
    void setCpf(const std::string& cpf);

    /**
     * @brief Retorna o CPF associado ao título.
     *
     * @return std::string O CPF do titular do título.
     */
    std::string getCpf() const;

    /**
     * @brief Define o código do título.
     *
     * @param codigo O código do título.
     */
    void setCodigo(const std::string& codigo);

    /**
     * @brief Retorna o código do título.
     *
     * @return std::string O código do título.
     */
    std::string getCodigo() const;

    /**
     * @brief Define o emissor do título.
     *
     * @param emissor O nome do emissor do título.
     */
    void setEmissor(const std::string& emissor);

    /**
     * @brief Retorna o emissor do título.
     *
     * @return std::string O nome do emissor do título.
     */
    std::string getEmissor() const;

    /**
     * @brief Define o setor do título.
     *
     * @param setor O setor associado ao título.
     */
    void setSetor(const std::string& setor);

    /**
     * @brief Retorna o setor do título.
     *
     * @return std::string O setor associado ao título.
     */
    std::string getSetor() const;

    /**
     * @brief Define a data de emissão do título.
     *
     * @param dataEmissao A data de emissão do título no formato "DD/MM/AAAA".
     */
    void setDataEmissao(const std::string& dataEmissao);

    /**
     * @brief Retorna a data de emissão do título.
     *
     * @return std::string A data de emissão do título no formato "DD/MM/AAAA".
     */
    std::string getDataEmissao() const;

    /**
     * @brief Define a data de vencimento do título.
     *
     * @param dataVencimento A data de vencimento do título no formato "DD/MM/AAAA".
     */
    void setDataVencimento(const std::string& dataVencimento);

    /**
     * @brief Retorna a data de vencimento do título.
     *
     * @return std::string A data de vencimento do título no formato "DD/MM/AAAA".
     */
    std::string getDataVencimento() const;

    /**
     * @brief Define o valor do título.
     *
     * @param valor O valor do título.
     */
    void setValor(double valor);

    /**
     * @brief Retorna o valor do título.
     *
     * @return double O valor do título.
     */
    double getValor() const;
};

#endif // TITULO_H
