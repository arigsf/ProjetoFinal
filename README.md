# CineAluguel

## Introdução
Nos dias atuais, com a presença em massa dos serviços de streaming online, é difícil lembrar que existiu uma época em que a escolha do que assistir para entretenimento não era uma tarefa tão simples como navegar por uma gama de filmes e séries disponíveis nesses streamings. Nesse contexto, surge a ideia do projeto, que objetiva implementar um sistema de controle para a vídeo-locadora CineAluguel.
As vídeo-locadoras eram ambientes frequentados por amantes do cinema, que exploravam as prateleiras repletas de filmes em DVDs e fitas. A experiência de organizar os filmes no estoque, gerenciar os clientes, controlar as locações e lidar com prazos de devolução fazia parte da rotina desses estabelecimentos, tal como na CineAluguel.
Este projeto resgata essa cultura de antigamente, como também instiga os desenvolvedores a aplicar os conceitos e técnicas da Programação Orientada a Objetos aprendidos ao longo do curso Programação e Desenvolvimento de Software II. A modelagem, implementação, testes e documentação ajudam a criar uma solução confiável, reutilizável e de fácil manutenção. Dessa maneira, busca-se desenvolver um programa funcional, que garanta a confiabilidade e a flexibilidade.

## Visão Geral da Solução

### Estrutura do Programa
O sistema é dividido em classes que representam as entidades essenciais na gestão da vídeo-locadora, como `Filme`, que tem como subclasses `DVD` e `FITA`, `Estoque`, `Cliente`, `CadastroCliente` e `Locacao`. Cada classe tem responsabilidades específicas para garantir uma estrutura modular.

### Funcionamento do Programa
- **Filmes:** Os filmes são representados pelas classes `DVD` e `FITA`, que herdam da classe base `Filme`. Cada filme tem um identificador único, título, quantidade em estoque, tipo (DVD ou FITA), e características específicas, como categoria para DVDs e estado de rebobinamento para fitas.

- **Estoque:** A classe `Estoque` é responsável pelo gerenciamento do inventário de filmes. Ela permite a leitura de um arquivo de dados, inserção de novos filmes, remoção de filmes, pesquisa por código ou título, listagem ordenada, e salvamento de dados em arquivo.

- **Clientes:** A classe `Cliente` representa os clientes da vídeo-locadora, contendo informações como CPF, nome, data de nascimento e idade.

- **CadastroCliente:** A classe `CadastroCliente` é responsável pelo gerenciamento de clientes do sistema. Ela permite a leitura de um arquivo de dados, inserção de novos clientes, remoção de clientes, listar clientes e salvamento dos dados em um arquivo.

- **Locação:** O controle de locações é gerenciado pela classe `Locacao`. Ela rastreia as locações pendentes, verifica a disponibilidade de filmes, realiza aluguéis, processa devoluções (calculando multas se necessário) e gera relatórios.

## Conclusão
O projeto proporcionou uma oportunidade para aplicar os conhecimentos adquiridos em PDSII na prática, enfrentando desafios típicos do desenvolvimento de software, desde a utilização da ferramenta GitHub em sua totalidade, passando por questões típicas da programação em termos de lógica e sintaxe, até questões de organização, como limitação do que cada um realizaria. Apesar disso, o trabalho em equipe e a ajuda mútua proporcoinaram uma ótima experiência nesse trabalho prático. Por fim, o resultado final deste projeto é um sistema de controle de vídeo-locadora para a CineAluguel, que é totalmente funcional e segue as melhores práticas de desenvolvimento de software.
