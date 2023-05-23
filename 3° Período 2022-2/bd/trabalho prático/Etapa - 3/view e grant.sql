-- Criação dos Usuarios do Banco de Dados

CREATE USER 'heitor'@'localhost' IDENTIFIED BY '090507';

CREATE USER 'lucas'@'localhost' IDENTIFIED BY '887213';

CREATE USER 'bryan'@'localhost'IDENTIFIED BY '1567890';

CREATE USER 'jose'@'localhost' IDENTIFIED BY '786700';

-- CONCEÇÃO DE PERMISSÕES

-- Concede permissão de update para o usuário Bryan nos atributos HrPratica e HrTeoricas na tabela Disciplina
GRANT UPDATE (HrPratica, HrTeoricas) ON mydb.disciplina TO 'bryan'@'localhost';

-- Concede permissão de select e update para o usuário Heitor em todos os atributos da tabela departamento
GRANT SELECT, UPDATE ON mydb.departamento TO 'heitor'@'localhost';

-- Concede permissão de exclusão para o usuário Heitor na tabela pessoa
GRANT DELETE ON mydb.pessoa TO 'heitor'@'localhost';

-- Concede todas as permissões em todas as tabelas do banco de dados
GRANT ALL ON mydb.* TO 'lucas'@'localhost';

-- Concede a permissão de inserir novos dados na tabela areadeinteresse para o usuário jose
GRANT INSERT ON mydb.areadeinteresse TO 'jose'@'localhost';

-- REVOGAÇÃO DAS PERMISSÕES

-- Revoga a permissão de update dos atributos HrPratica e HrTeoricas da tabela Disciplina
REVOKE UPDATE (HrPratica, HrTeoricas) ON mydb.disciplina FROM 'bryan'@'localhost';

-- Revoga a permissão de exclusão da tabela pessoa do usuário Heitor
REVOKE DELETE ON mydb.pessoa FROM 'heitor'@'localhost'; 

-- Revoga a permissão de seleção e update na tabela departamento do usuário heitor
REVOKE SELECT, UPDATE ON mydb.departamento FROM 'heitor'@'localhost';

-- Revoga a permissão de inseção de novos dados na tabela areadeinteresse do usuário jose
REVOKE INSERT ON mydb.areadeinteresse FROM 'jose'@'localhost';

-- CRIAÇÃO DAS VIEWS

-- Cria uma visão que retorna uma matéria e o nome do professor que a leciona
CREATE VIEW docenteMateria AS SELECT DISTINCT nomeDscp, NomeSocial FROM disciplina D, pessoa P, professor PE, leciona L, turma T 
WHERE P.CPF = PE.CPF AND PE.CPF = L.CPF AND L.idTurma = T.idTurma AND T.CodigoDscp = D.Codigo;

-- Cria uma visão com o departamento e  os cursos que ele possui
CREATE VIEW CursoDepartamento AS SELECT Nome, NomeCurso
FROM departamento JOIN curso ON departamento.Nome = curso.NomeDept;

-- Cria uma visão que retorna turma e disciplina e o semestre
CREATE VIEW DisciplinaTurma AS SELECT NomeDscp, idTurma, Semestre
FROM turma JOIN disciplina ON turma.CodigoDscp = disciplina.Codigo;

-- Conta todas as turmas em DisciplinaTurma
SELECT count(NomeDscp) FROM DisciplinaTurma;