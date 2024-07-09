#include "TituloManager.h"
#include <algorithm>
#include <stdexcept>

/**
 * @brief Cria um novo t�tulo e adiciona ao vetor de t�tulos gerenciados.
 *
 * @param titulo O t�tulo a ser criado e adicionado.
 */
void TituloManager::criarTitulo(const Titulo& titulo) {
    titulos.push_back(titulo);
}

/**
 * @brief Busca e retorna um t�tulo pelo c�digo.
 *
 * @param codigo O c�digo do t�tulo a ser buscado.
 * @return Titulo O t�tulo correspondente ao c�digo fornecido.
 * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
 */
Titulo TituloManager::lerTitulo(const std::string& codigo) const {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        return *it;
    }
    throw std::invalid_argument("Titulo n�o encontrado.");
}

/**
 * @brief Busca e retorna todos os t�tulos associados a um CPF.
 *
 * @param cpf O CPF dos t�tulos a serem buscados.
 * @return std::vector<Titulo> Um vetor contendo todos os t�tulos associados ao CPF fornecido.
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
 * @brief Atualiza os dados de um t�tulo existente.
 *
 * @param titulo O t�tulo com os dados atualizados.
 * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
 */
void TituloManager::atualizarTitulo(const Titulo& titulo) {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == titulo.getCodigo(); });
    if (it != titulos.end()) {
        *it = titulo;
    } else {
        throw std::invalid_argument("Titulo n�o encontrado.");
    }
}

/**
 * @brief Exclui um t�tulo com base no c�digo fornecido.
 *
 * @param codigo O c�digo do t�tulo a ser exclu�do.
 * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
 */
void TituloManager::excluirTitulo(const std::string& codigo) {
    auto it = std::remove_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        titulos.erase(it, titulos.end());
    } else {
        throw std::invalid_argument("Titulo n�o encontrado.");
    }
}
