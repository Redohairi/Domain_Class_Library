#ifndef CONTA_H
#define CONTA_H

#include <string>

/**
 * @brief Classe Conta
 *
 * Esta classe representa uma conta de usuário com operações para manipular as informações da conta.
 */
class Conta {
private:
    std::string cpf;    ///< CPF do titular da conta
    std::string nome;   ///< Nome do titular da conta
    std::string senha;  ///< Senha de acesso da conta

public:
    /**
     * @brief Define o CPF do titular da conta.
     *
     * @param cpf string contendo o CPF do titular.
     * Deve validar o CPF antes de atribuir.
     */
    void setCpf(const std::string& cpf);

    /**
     * @brief Retorna o CPF do titular da conta.
     *
     * @return string com o CPF do titular.
     */
    std::string getCpf() const;

    /**
     * @brief Define o nome do titular da conta.
     *
     * @param nome string contendo o nome do titular.
     * O nome deve ser verificado quanto a caracteres inválidos antes da atribuição.
     */
    void setNome(const std::string& nome);

    /**
     * @brief Retorna o nome do titular da conta.
     *
     * @return string com o nome do titular.
     */
    std::string getNome() const;

    /**
     * @brief Define a senha de acesso da conta.
     *
     * @param senha string contendo a senha.
     * A senha deve atender a critérios de complexidade especificados.
     */
    void setSenha(const std::string& senha);

    /**
     * @brief Retorna a senha de acesso da conta.
     *
     * @return string com a senha.
     */
    std::string getSenha() const;
};

#endif // CONTA_H
