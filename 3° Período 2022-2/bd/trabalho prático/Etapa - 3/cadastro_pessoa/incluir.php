<?php
header("Content-Type: text/html; charset=iso-8859-1",true);
?>
<html>
  <head>
    <body>
      <form name="form1" method="POST" action="idex.php">
          <?php
            include("./config.php");
            $conn = new mysqli($host, $login, $senha, $bd);

            if ($conn->connect_error) {
              die("Connection failed: " . $conn->connect_error);
            }

            // Retrieve data submitted by form
            $cpf = $_POST['cpf'];
            $nomeSocial = $_POST['nomeSocial'];
            $sexo = $_POST['sexo'];
            $nascimento = $_POST['nascimento'];
            $estado = $_POST['estado'];
            $cidade = $_POST['cidade'];
            $bairro = $_POST['bairro'];
            $logradouro = $_POST['logradouro'];
            $numero = $_POST['numero'];
            $complemento = $_POST['complemento'];
            
            if(isset($_POST["CPF"])){
              $sql = "SELECT * FROM pessoa WHERE CPF=".$_POST["CPF"];
              $result = $conn->query($sql);

              if ($result->num_rows > 0) {
                $sql = "UPDATE pessoa SET NomeSocial='$nomeSocial', Sexo='$sexo', Nascimento='$nascimento', Estado='$estado', Cidade='$cidade', 
                Bairro='$bairro', Logradouro='$logradouro', Numero='$numero', Complemento='$complemento' WHERE CPF='$cpf'";
              }

            }else{             
              // Insert data into MySQL table
              $sql = "INSERT INTO pessoa (CPF, NomeSocial, Sexo, Nascimento, Estado, Cidade, Bairro, Logradouro, Numero, Complemento)
              VALUES ('$cpf', '$nomeSocial', '$sexo', '$nascimento', '$estado', '$cidade', '$bairro', '$logradouro', '$numero', '$complemento')";
            }

            if ($conn->query($sql) === TRUE) {
              echo "Data inserted successfully";
              
            } else {
              echo "Error inserting data: " . $conn->error;
            }
            
            $conn->close();
            #header("location: ./index.php")           
          ?>
        <table border="0" align="center" width="35%">
          <input type="button" value="voltar a pagina inicial" onclick="location.href='index.php'">
        </table>
      </form>
    </body>
  </head>
</html>
