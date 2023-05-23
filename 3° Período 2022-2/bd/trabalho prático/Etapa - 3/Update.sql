-- Uptdade  Pessoa e Aluno 
UPDATE Aluno
SET Email = 'novo3email@universidade.com'
WHERE CPF IN(
  SELECT CPF
  FROM Pessoa
  WHERE CPF = '71214485219'
);
-- Teste para esse update 
SELECT * FROM Aluno
WHERE CPF = (
  SELECT CPF
  FROM Pessoa
  WHERE CPF = '71214485219'
);

-- Update Departamento
Update Departamento d 
Set d.Telefone = '22 52149635'
Where d.Nome = 'Departamento de biologia';
-- Teste 
select * FROM departamento;

-- update Curso 
UPDATE Curso c
SET c.QtdVagas = c.QtdVagas - 1
WHERE c.Codigo = '12019';
-- Teste
select * from Curso ;


-- Update Professor
UPDATE Professor p
INNER JOIN Pessoa pe ON p.CPF = Pe.CPF
SET p.Email = 'novoemail@universidade.com'
WHERE pe.CPF =  '12686571071';
-- Teste
select * from Professor ;

-- Update Pessoa
UPDATE pessoa pe
SET pe.NomeSocial = 'Maria Silva'
WHERE pe.CPF = '90097344397';
-- Teste
SELECT  pe.NomeSocial
FROM pessoa pe
WHERE pe.CPF = '90097344397';


