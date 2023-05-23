<?php
header("Content-Type: text/html; charset=iso-8859-1",true);
?>
<html>
  <head><title>Cadastro de pessoa.</title></head>
  <body>
  <center><h3>Cadastro de pessoa</h3></center>
  <form name="form1" method="POST" action="form_incluir.php">
    <table border="0" align="center" width="100%">
    <?php
    include("./config.php");
    $con = mysqli_connect($host, $login, $senha, $bd);
    $sql = "SELECT * FROM pessoa ORDER BY NomeSocial";
    $tabela = mysqli_query($con, $sql);
    if(mysqli_num_rows($tabela)==0){
    ?>
      <tr><td align="center">Nao ha nenhum aluno cadastrado.</td></tr>
      <tr><td align="center"><input type="submit" value="Incluir aluno"></td></tr>
    <?php
    }else{
    ?>
      <tr bgcolor="grey">
        <td width="15%">NomeSocial</td>
        <td width="4%">sexo</td>
        <td width="7%">Nascimento</td>
        <td width="5%">Estado</td>
        <td width="12%">Cidade</td>
        <td width="10%">Bairro</td>
        <td width="20%">Logradouro</td>
        <td width="5%">Numero</td>
        <td width="8%">Complemento</td>
        <td width="10%"></td>
      </tr>
    <?php
      while($dados = mysqli_fetch_row($tabela)){
    ?>
      <tr>
        <td><?php echo $dados[1]; ?></td>
        <td><?php echo $dados[2]; ?></td> 
        <td><?php echo $dados[3]; ?></td>
        <td><?php echo $dados[4]; ?></td>
        <td><?php echo $dados[5]; ?></td>
        <td><?php echo $dados[6]; ?></td>
        <td><?php echo $dados[7]; ?></td>
        <td><?php echo $dados[8]; ?></td>
        <td><?php echo $dados[9]; ?></td>
        <td align="center">
          <input type="button" value="Excluir" onclick="location.href='excluir.php?CPF=<?php echo $dados[0]; ?>'">
          <input type="button" value="Editar" onclick="location.href='form_incluir.php?CPF=<?php echo $dados[0]; ?>'">
        </td>
      </tr>
    <?php
      }
    ?>
    <tr bgcolor="grey"><td colspan="10" height="5"></td></tr>
    <?php
    mysqli_close($con);
    ?>
    <tr><td colspan="10" align="center"><input type="submit" value="Incluir nova pessoa"></td></tr>
    <?php
    }
    ?>
    </table>
  </form>
  </body>
</html>