<h2 align="center">Trabalho 2 – E/S e Arquivos</h2>
<h6 align="center">INE5611 - Sistemas Operacionais</h6>

<p align="center">
	<img alt="GitHub language count" src="https://img.shields.io/github/languages/count/gisabernardess/ufsc-ine5611-t2">
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/gisabernardess/ufsc-ine5611-t2">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/gisabernardess/ufsc-ine5611-t2">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/gisabernardess/ufsc-ine5611-t2">
</p>

<h2>
:rocket: Technologies
</h2>
<p>O Trabalho 2 (T2) consiste em desenvolver um programa para gerenciar uma base de dados de funcionários de uma empresa em um arquivo binário. Utilizando a linguagem de programação <a href="https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o)" rel="nofollow">C</a></p>
<h2>
:computer: Atividades
</h2>
<p>Na base de dados, cada funcionário deverá ser representado obrigatoriamente pela seguinte estrutura:</p>

		struct  funcionario {unsigned  int id; char  nome [256]; char  sexo; float  salario; }

<p>O programa deverá receber pela linha de comando o nome de um arquivo binário contendo a base de dados dos funcionários (o arquivo de dados deverá ser criado caso não exista). O programa deverá permanecer em um loop infinito aguardando operações por parte do usuário. As operações permitidas são:</p>
<ol>
<li>Inserir um funcionário: o programa deverá solicitar que o usuário digite todos os dados do funcionário a ser inserido (id, nome, sexo e salario ). O programa só deverá inserir o funcionário na base de dados se o id informado for maior do que zero e não exista nenhum funcionário já cadastrado com o mesmo id.</li>
<li>Remover um funcionário: o usuário deverá informar o id do funcionário a ser removido. A remoção consistirá em alterar o id do funcionário para o valor zero. Portanto, usuários com id=0 serão considerados como removidos da base de dados.</li>
<li>Calcular a média de salários dos funcionários por sexo: o programa deverá calcular ambas as médias e mostrá-las na tela. O programa não poderá incluir os salários dos funcionários removidos do sistema.</li>
<li>Exportar os dados dos funcionários para um arquivo em formato texto: o programa deverá solicitar o nome do arquivo de texto de saída onde serão exportados os dados. O programa não deverá exportar os funcionários removidos do sistema.</li>
<li>Compactar a base de dados: o programa deverá remover fisicamente da base de dados todos os funcionários que possuam id=0,  reduzindo assim o tamanho da base de dados.</li>
<li>Sair do programa: ao sair do programa o arquivo binário contendo a base de dados deve permanecer no disco para utilização posterior.</li>
</ol>
<hr>
<p>Made with ♥ by Gisele Silva :wave: <a href="https://www.linkedin.com/in/gisabernardess/" rel="nofollow">Get in touch!</a>
</p>
