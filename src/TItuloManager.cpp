#include "TituloManager.h"
#include <algorithm>
#include <stdexcept>

/**
 * @brief Cria um novo título e adiciona ao vetor de títulos gerenciados.
 *
 * @param titulo O título a ser criado e adicionado.
 */
void TituloManager::criarTitulo(const Titulo& titulo) {
    titulos.push_back(titulo);
}

/**
 * @brief Busca e retorna um título pelo código.
 *
 * @param codigo O código do título a ser buscado.
 * @return Titulo O título correspondente ao código fornecido.
 * @throw std::invalid_argument Se o título não for encontrado.
 */
Titulo TituloManager::lerTitulo(const std::string& codigo) const {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        return *it;
    }
    throw std::invalid_argument("Titulo não encontrado.");
}

/**
 * @brief Busca e retorna todos os títulos associados a um CPF.
 *
 * @param cpf O CPF dos títulos a serem buscados.
 * @return std::vector<Titulo> Um vetor contendo todos os títulos associados ao CPF fornecido.
 */
std::vector<Titulo> TituloManager::lerTitulos(const std::string& cpf) const {
    std::vector<Titulo> resultado;
    for (const auto& titulo : titulos) {
        if (titulo.getCpf() == cpf) {
            resultado.push_back(titulo);
        }
    }
    return resultado;
}

/**
 * @brief Atualiza os dados de um título existente.
 *
 * @param titulo O título com os dados atualizados.
 * @throw std::invalid_argument Se o título não for encontrado.
 */
void TituloManager::atualizarTitulo(const Titulo& titulo) {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == titulo.getCodigo(); });
    if (it != titulos.end()) {
        *it = titulo;
    } else {
        throw std::invalid_argument("Titulo não encontrado.");
    }
}

/**
 * @brief Exclui um título com base no código fornecido.
 *
 * @param codigo O código do título a ser excluído.
 * @throw std::invalid_argument Se o título não for encontrado.
 */
void TituloManager::excluirTitulo(const std::string& codigo) {
    auto it = std::remove_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        titulos.erase(it, titulos.end());
    } else {
        throw std::invalid_argument("Titulo não encontrado.");
    }
}
