#ifndef TITULO_H
#define TITULO_H

#include <string>

/**
 * @brief Classe Titulo
 *
 * Esta classe representa um t�tulo com informa��es detalhadas como c�digo, emissor, setor, datas de emiss�o e vencimento, valor e CPF do titular.
 */
class Titulo {
private:
    std::string codigo;         ///< C�digo do t�tulo
    std::string emissor;        ///< Nome do emissor do t�tulo
    std::string setor;          ///< Setor associado ao t�tulo
    std::string dataEmissao;    ///< Data de emiss�o do t�tulo no formato "DD/MM/AAAA"
    std::string dataVencimento; ///< Data de vencimento do t�tulo no formato "DD/MM/AAAA"
    double valor;               ///< Valor do t�tulo
    std::string cpf;            ///< CPF do titular do t�tulo

public:
    /**
     * @brief Define o CPF associado ao t�tulo.
     *
     * @param cpf O CPF do titular do t�tulo.
     */
    void setCpf(const std::string& cpf);

    /**
     * @brief Retorna o CPF associado ao t�tulo.
     *
     * @return std::string O CPF do titular do t�tulo.
     */
    std::string getCpf() const;

    /**
     * @brief Define o c�digo do t�tulo.
     *
     * @param codigo O c�digo do t�tulo.
     */
    void setCodigo(const std::string& codigo);

    /**
     * @brief Retorna o c�digo do t�tulo.
     *
     * @return std::string O c�digo do t�tulo.
     */
    std::string getCodigo() const;

    /**
     * @brief Define o emissor do t�tulo.
     *
     * @param emissor O nome do emissor do t�tulo.
     */
    void setEmissor(const std::string& emissor);

    /**
     * @brief Retorna o emissor do t�tulo.
     *
     * @return std::string O nome do emissor do t�tulo.
     */
    std::string getEmissor() const;

    /**
     * @brief Define o setor do t�tulo.
     *
     * @param setor O setor associado ao t�tulo.
     */
    void setSetor(const std::string& setor);

    /**
     * @brief Retorna o setor do t�tulo.
     *
     * @return std::string O setor associado ao t�tulo.
     */
    std::string getSetor() const;

    /**
     * @brief Define a data de emiss�o do t�tulo.
     *
     * @param dataEmissao A data de emiss�o do t�tulo no formato "DD/MM/AAAA".
     */
    void setDataEmissao(const std::string& dataEmissao);

    /**
     * @brief Retorna a data de emiss�o do t�tulo.
     *
     * @return std::string A data de emiss�o do t�tulo no formato "DD/MM/AAAA".
     */
    std::string getDataEmissao() const;

    /**
     * @brief Define a data de vencimento do t�tulo.
     *
     * @param dataVencimento A data de vencimento do t�tulo no formato "DD/MM/AAAA".
     */
    void setDataVencimento(const std::string& dataVencimento);

    /**
     * @brief Retorna a data de vencimento do t�tulo.
     *
     * @return std::string A data de vencimento do t�tulo no formato "DD/MM/AAAA".
     */
    std::string getDataVencimento() const;

    /**
     * @brief Define o valor do t�tulo.
     *
     * @param valor O valor do t�tulo.
     */
    void setValor(double valor);

    /**
     * @brief Retorna o valor do t�tulo.
     *
     * @return double O valor do t�tulo.
     */
    double getValor() const;
};

#endif // TITULO_H
