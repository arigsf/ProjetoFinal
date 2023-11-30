# CineAluguel

## Introdução
Nos dias atuais, com a presença em massa dos serviços online de streaming, é difícil lembrar que existiu uma época em que a escolha do que assistir para entretenimento não era uma tarefa tão simples como navegar por uma gama infinita de filmes e séries disponíveis nessas plataformas. Antigamente, as empresas que realizavam esses serviços eram chamadas de videolocadoras e as pessoas precisavam ir fisicamente para navegar no mundo dos DVDs e das fitas. Nesse contexto, surge a ideia do projeto, que tem como objetivo implementar um sistema de controle para a locadora de vídeo CineAluguel. As videolocadoras eram ambientes frequentados por amantes do cinema, que exploravam as prateleiras repletas de obras audiovisuais. A experiência frustrante de organizar os filmes no estoque, gerenciar os clientes, controlar as locações, lidar com prazos de devolução e cuidar do financeiro fazia parte da rotina desses estabelecimentos, que também é um problema da CineAluguel. Este projeto resgata esse ambiente e serve para que os desenvolvedores apliquem os conceitos e técnicas da Programação Orientada a Objetos aprendidos ao longo do curso de Programação e Desenvolvimento de Software II. A modelagem, a implementação, os testes e a documentação ajudam a criar uma solução confiável, reutilizável e de fácil manutenção. Dessa maneira, busca-se desenvolver um programa funcional, que garanta confiabilidade e flexibilidade.

## Visão Geral da Solução

### Estrutura do Programa
O sistema é dividido em classes que representam as entidades essenciais na gestão de uma videolocadora, como `Filme`, que tem como subclasses `DVD` e `FITA`, `Estoque`, `Cliente`, `CadastroCliente`, `Locacao`, `Financeiro` e `Sistema`. Cada classe tem responsabilidades específicas para garantir uma estrutura modular.

### Funcionamento do Programa
- **Filmes:** Os filmes são representados pelas classes `DVD` e `FITA`, que herdam da classe base `Filme`. Cada filme tem um identificador único, título, quantidade em estoque, tipo (DVD ou FITA), e características específicas, como categoria para DVDs e estado de rebobinamento para fitas.

- **Estoque:** A classe `Estoque` é responsável pelo gerenciamento do inventário de filmes. Ela permite a leitura de um arquivo de dados, inserção de novos filmes, remoção de filmes, pesquisa por código ou título, listagem ordenada, e salvamento de dados em arquivo.

- **Clientes:** A classe `Cliente` representa os clientes da vídeo-locadora, contendo informações como CPF, nome, data de nascimento e idade.

- **CadastroCliente:** A classe `CadastroCliente` é responsável pelo gerenciamento de clientes do sistema. Ela permite a leitura de um arquivo de dados, inserção de novos clientes, remoção de clientes, listar clientes e salvamento dos dados em um arquivo.

- **Locação:** O controle de locações é gerenciado pela classe `Locacao`. Ela rastreia as locações pendentes, verifica a disponibilidade de filmes, realiza aluguéis, processa devoluções (calculando multas se necessário) e gera relatórios.

- **Financeiro:** A classe `Financeiro` é responsável por cuidar do caixa da empresa. Ela permite sacar, depositar, visualizar o saldo e ver o histórico de transações.

- **Sistema:** A classe `Sistema` gerencia todas as aplicações que o usuário desejar fazer.

## Conclusão
O projeto proporcionou uma oportunidade para aplicar os conhecimentos adquiridos em PDSII na prática, enfrentando desafios típicos do desenvolvimento de software, desde a utilização da ferramenta GitHub em sua totalidade, passando por questões típicas da programação em termos de lógica e sintaxe, até questões de organização, como limitação do que cada um realizaria. Apesar disso, o trabalho em equipe e a ajuda mútua proporcoinaram uma ótima experiência nesse trabalho prático. Por fim, o resultado final deste projeto é um sistema de controle de videolocadora da CineAluguel, que é funcional e segue boas práticas de desenvolvimento de software.
