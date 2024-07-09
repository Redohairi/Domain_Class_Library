#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <string>

/**
 * @brief Classe Pagamento
 *
 * Esta classe representa um pagamento com informações detalhadas como código, CPF, data, valor, estado, nome e percentual.
 */
class Pagamento {
private:
    std::string codigo;    ///< Código do pagamento
    std::string cpf;       ///< CPF do pagador
    std::string data;      ///< Data do pagamento
    double valor;          ///< Valor do pagamento
    std::string estado;    ///< Estado do pagamento (e.g., Previsto, Liquidado, Inadimplente)
    std::string nome;      ///< Nome do pagador
    int percentual;        ///< Percentual do pagamento

public:
    /**
     * @brief Retorna o código do pagamento.
     *
     * @return std::string O código do pagamento.
     */
    std::string getCodigo() const { return codigo; }

    /**
     * @brief Retorna o CPF do pagador.
     *
     * @return std::string O CPF do pagador.
     */
    std::string getCpf() const { return cpf; }

    /**
     * @brief Retorna a data do pagamento.
     *
     * @return std::string A data do pagamento.
     */
    std::string getData() const { return data; }

    /**
     * @brief Retorna o valor do pagamento.
     *
     * @return double O valor do pagamento.
     */
    double getValor() const { return valor; }

    /**
     * @brief Retorna o estado do pagamento.
     *
     * @return std::string O estado do pagamento.
     */
    std::string getEstado() const { return estado; }

    /**
     * @brief Retorna o nome do pagador.
     *
     * @return std::string O nome do pagador.
     */
    std::string getNome() const { return nome; }

    /**
     * @brief Retorna o percentual do pagamento.
     *
     * @return int O percentual do pagamento.
     */
    int getPercentual() const { return percentual; }

    /**
     * @brief Define o código do pagamento.
     *
     * @param codigo O código do pagamento.
     */
    void setCodigo(const std::string& codigo) { this->codigo = codigo; }

    /**
     * @brief Define o CPF do pagador.
     *
     * @param cpf O CPF do pagador.
     */
    void setCpf(const std::string& cpf) { this->cpf = cpf; }

    /**
     * @brief Define a data do pagamento.
     *
     * @param data A data do pagamento no formato "DD/MM/AAAA".
     * @throw std::invalid_argument Se a data for inválida.
     */
    void setData(const std::string& data);

    /**
     * @brief Define o valor do pagamento.
     *
     * @param valor O valor do pagamento.
     * @throw std::invalid_argument Se o valor estiver fora do intervalo permitido (0 a 1.000.000,00).
     */
    void setValor(double valor);

    /**
     * @brief Define o estado do pagamento.
     *
     * @param estado O estado do pagamento.
     * @throw std::invalid_argument Se o estado não for válido.
     */
    void setEstado(const std::string& estado);

    /**
     * @brief Define o nome do pagador.
     *
     * @param nome O nome do pagador.
     */
    void setNome(const std::string& nome) { this->nome = nome; }

    /**
     * @brief Define o percentual do pagamento.
     *
     * @param percentual O percentual do pagamento.
     */
    void setPercentual(int percentual) { this->percentual = percentual; }
};

#endif // PAGAMENTO_H
