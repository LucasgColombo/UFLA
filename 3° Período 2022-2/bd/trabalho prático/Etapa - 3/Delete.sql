-- Exemplo de delete
INSERT INTO Departamento
VALUES ('Departamento de exclusão','Exemplo de exclusão','00 00000000','NL','Exemplo','Exemplo','Exemplo','00')
INSERT INTO Curso
VALUES ('Exclusão','00000','L','N','0','0','Departamento de exclusão')

-- Delete aninhado do curso 1/5

DELETE FROM Curso
WHERE NomeDept IN (select Nome from Departamento WHERE Nome = 'Departamento de exclusão');

-- Delete Testee 2/5

DELETE FROM Departamento
WHERE nome IN Departamento = 'Departamento de exclusão'

-- Delete pelo CPF 3/5
INSERT INTO Telefone
VALUES ('19 95682705','06980759000')

DELETE FROM Telefone
WHERE CPF IN Telefone = '06980759000';

-- Delete pelo Numero 4/5
INSERT INTO Telefone
VALUES ('19 95682705','06980759000')

DELETE FROM Telefone
WHERE Telefone IN Telefone = '19 95682705';

-- exclui todos elementos em Teste 
-- no MySQL, o modo "safe update" deve ser desabilitado
-- Edit --> Preferences --> SQL Editor --> desmarque "Safe Updates"
-- Só passa a valer a partir da próxima conexão
CREATE TABLE IF NOT EXISTS `mydb`.`Teste` (
  `Nome` VARCHAR(30) NOT NULL,
  `ID`   INT(2) NOT NULL,
  ON DELETE NO ACTION
  ON UPDATE NO ACTION)
ENGINE = InnoDB;

INSERT INTO Teste
VALUES ('Nome Teste 1','0')
INSERT INTO Teste
VALUES ('Nome Teste 2','1')
INSERT INTO Teste
VALUES ('Nome Teste 3','2')

DELETE FROM Teste

DROP TABLE Teste